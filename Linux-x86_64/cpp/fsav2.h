/**
 * @file fsav2.h
 * @author Huigang Wang (huigang39@outlook.com)
 * @brief
 * @version 0.1
 * @date 2025-03-11
 *
 * @copyright Copyright (c) 2025 Huigang Wang
 *
 */

#ifndef FSAV2_H
#define FSAV2_H

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

/* ---------------------------- SDK Version Check --------------------------- */
#define SDK_RUNTIME_VER (0x02000002)

static inline void
lib_ver_check()
{
        extern const uint32_t SDK_BUILD_VER;
        if (SDK_RUNTIME_VER != SDK_BUILD_VER) {
                fprintf(stderr,
                        "\033[31m======== VERSION MISMATCH ========\n"
                        "RUNTIME\tVER: 0x%x\n"
                        "BUILD\tVER: 0x%x\n"
                        "======== VERSION MISMATCH ========\033[0m\n",
                        SDK_RUNTIME_VER,
                        SDK_BUILD_VER);
                exit(-1);
        }
}
/* ---------------------------- SDK Version Check --------------------------- */

/* 前置声明 */
struct net_manager;
struct net_channel;

namespace AC2
{
/* --------------------------------- SDK 配置 --------------------------------- */
struct sdk_config_t {
        char MIN_ESP32_VER[16]; // 最低 ESP32 固件版本
        char MIN_STM32_VER[16]; // 最低 STM32 固件版本

        int MAX_TIMEOUT_MS; // 最大超时时间
        int MAX_RETRY;      // 最大重试次数

        int      DEFAULT_TIMEOUT_MS; // 用户默认超时时间, 单位毫秒
        uint32_t DEFAULT_MAX_RETRY;  // 用户默认最大重试次数
};
static constexpr sdk_config_t SDK_CONFIG = {"0.3.12.30", "0.2.10.20", 1000, 10, 5, 0};
/* --------------------------------- SDK 配置 --------------------------------- */

class FSA
{
        /* -------------------------------------------------------------------------- */
        /*                                    类型定义                                */
        /* -------------------------------------------------------------------------- */
      public:
        enum class ret_e : int {
                SUCCESS = 0, // 操作成功

                /**
                 * @brief 执行器版本不匹配
                 * @note 执行器固件版本过低
                 */
                SDK_VER_NOT_MATCH = -101,

                /**
                 * @brief 执行器获取配置参数错误
                 * @note 型号和版本号未获取成功
                 */
                CTRL_PARAM_ERR = -102,

                /**
                 * @brief 执行器对象未初始化
                 * @note 可能未执行 init 函数
                 */
                INTERFACE_HANDLE_ERR = -201,

                /**
                 * @brief 接口参数非法
                 * @note 传入接口的参数不符合要求
                 */
                ARG_ERR = -202,

                /**
                 * @brief 网络错误
                 * @note 可能对应 IP 的 FSA 网络已断开
                 */
                NET_ERR = -301,

                /**
                 * @brief 网络接收超时
                 * @note 接收执行器返回数据等待时间超过指定超时时间
                 */
                TIMEOUT = -302,

                /**
                 * @brief 网络接收缓冲区数据与发送指令不匹配
                 * @note 可能接收到系统 socket 输入缓冲区前几帧数据导致指令不匹配
                 */
                NET_RXBUF_DATA_ERR = -303,
        };

        enum class net_recv_mode_e : int {
                NONE = 0,

                /**
                 * @brief 等待时让出 CPU
                 * @warning 实际超时返回时间可能会大于指定超时时间(取决于系统调度和负载)
                 */
                YIELD_WAIT = 1,

                /**
                 * @brief 等待时 while 自旋, 不让出 CPU
                 * @warning 可能会造成 CPU 满载
                 */
                SPIN_WAIT = 2,
        };

        enum class ctrl_word_e : uint32_t {
                CALIBRATE_ENCODER = 0x02,   // 编码器校准
                SERVO_OFF         = 0X06,   // 失能
                SERVO_ON          = 0X0F,   // 使能
                CLEAR_FAULT       = 0X86,   // 清除错误
                RETURN_ZERO       = 0X103F, // 回零
                FRICTION_IDENTIFY = 0X104F, // 摩擦辨识
        };

        enum class ctrl_mode_e : uint32_t {
                NONE          = 0x00, // 无模式
                POSITION_MODE = 0x01, // 位置模式
                VELOCITY_MODE = 0x03, // 速度模式
                TORQUE_MODE   = 0x04, // 力矩模式
                PD_MODE       = 0x07, // PD 模式
        };

        /* ---------------------------------- 实时控制 ---------------------------------- */
        struct pvctte_t {
                double pos;
                double vel;
                double cur;
                double tor;
                double tor_e;
        };

        struct temp_vbus_t {
                double mos;
                double coil;
                double vbus;
        };

        struct pid_param_t {
                double pos_kp;
                double vel_kp;
                double vel_ki;
        };

        struct pd_param_t {
                double pd_kp;
                double pd_kd;
        };

        struct err_code_t {
                std::array<uint32_t, 8> arr;
        };

        struct setpvc_timeout_protect_config_t {
                uint32_t    enable;               // 使能
                uint32_t    timeout_ms;           // 超时时间
                ctrl_mode_e protect_control_mode; // 设置进入保护状态时的控制模式
                uint32_t is_close_back_last_control_mode; // 如果关闭该功能时正在保护状态，是否恢复到进入保护状态前的操作模式
                uint32_t is_ignore_set_control_mode; // 进入保护模式后是否禁止修改控制模式
        };

        /* 订阅模式 */
        struct subs_config_t {
                uint32_t enable;
                uint32_t pos;
                uint32_t vel;
                uint32_t cur;
                uint32_t tor;
                uint32_t error;
                uint32_t error_ext2;
                uint32_t error_ext3;
                uint32_t error_ext4;
                uint32_t error_ext5;
                uint32_t error_ext6;
                uint32_t error_ext7;
                uint32_t error_ext8;
        };

        struct subs_data_t {
                struct {
                        double pos, vel, cur, tor;
                } pvct;
                uint32_t                cnt;
                std::array<uint32_t, 8> error;
        };
        /* ---------------------------------- 实时控制 ---------------------------------- */

      private:
        /* ---------------------------------- 执行器配置 --------------------------------- */
        constexpr static uint32_t MAX_STR_BUF_SIZE = 32;
        struct ctrl_config_t {
                char     actuator_type[MAX_STR_BUF_SIZE];
                char     sub_version[MAX_STR_BUF_SIZE];
                uint32_t motor_type;
                uint32_t motor_hardware_type;
                uint32_t actuator_comm_hardware_type;
                int32_t  actuator_direction;
                float    actuator_reduction_ratio;
                uint32_t motor_vbus;
                int32_t  motor_direction;
                float    motor_max_speed;
                float    motor_max_acceleration;
                float    motor_max_current;
        };

        struct root_t {
                char     type[MAX_STR_BUF_SIZE];
                char     model[MAX_STR_BUF_SIZE];
                char     name[MAX_STR_BUF_SIZE];
                char     uid[MAX_STR_BUF_SIZE];
                char     sn[MAX_STR_BUF_SIZE];
                char     driver_version[MAX_STR_BUF_SIZE];
                char     firmware_version[MAX_STR_BUF_SIZE];
                char     connect_mode[MAX_STR_BUF_SIZE];
                char     mac_address[MAX_STR_BUF_SIZE];
                char     ip_address[MAX_STR_BUF_SIZE];
                char     IP[MAX_STR_BUF_SIZE];
                uint32_t DHCP_enable;
                char     SSID[MAX_STR_BUF_SIZE];
                char     password[MAX_STR_BUF_SIZE];
                char     static_IP[MAX_STR_BUF_SIZE];
                char     gateway[MAX_STR_BUF_SIZE];
                char     subnet_mask[MAX_STR_BUF_SIZE];
                char     dns_1[MAX_STR_BUF_SIZE];
                char     dns_2[MAX_STR_BUF_SIZE];
                char     OTAstatus[MAX_STR_BUF_SIZE];
                char     OTADriverstatus[MAX_STR_BUF_SIZE];
        };
        /* ---------------------------------- 执行器配置 --------------------------------- */

        /* --------------------------------- 执行器错误码 --------------------------------- */
        enum class error_e {
                ERR_ADC_CAL_FAULT           = 1 << 0,  // ADC 校准错误
                ERR_CAN_COM_TIMEOUT         = 1 << 1,  // CAN 通信超时
                ERR_OVER_CURRENT            = 1 << 2,  // 过流
                ERR_OVER_VBUS               = 1 << 3,  // 过压
                ERR_UNDER_VBUS              = 1 << 4,  // 欠压
                ERR_OVER_TEMP_TRIP          = 1 << 5,  // 芯片过温
                ERR_OVER_TEMP_MOS           = 1 << 6,  // MOS 过温
                ERR_OVER_PHASE_A_CURRENT    = 1 << 7,  // A 相过流
                ERR_OVER_PHASE_B_CURRENT    = 1 << 8,  // B 相过流
                ERR_OVER_PHASE_C_CURRENT    = 1 << 9,  // C 相过流
                ERR_OVER_HARD_PHASE_CURRENT = 1 << 10, // 硬件过流
                ERR_OPD_FAULT               = 1 << 11, // 缺相
                ERR_ENCODER_NOT_CALI        = 1 << 12, // 电角度磁编码未校准
                ERR_ENCODER_LOSS            = 1 << 13, // 电角度磁编码丢失
                ERR_FLASH_ERR               = 1 << 14, // Flash 错误
                ERR_MOTOR_STALL             = 1 << 15, // 转速异常
                ERR_POSITION_ERR            = 1 << 16, // 位置保护错误
                ERR_ENCODER_REVERSAL        = 1 << 17, // 编码器反转
                ERR_MOTOR_TYPE_NULL         = 1 << 18, // 电机类型为空
                ERR_HARDWARE_TYPE_NULL      = 1 << 19, // 硬件类型为空
                ERR_ENCODER_OTHERS          = 1 << 20, // 其它编码器错误
                ERR_OVER_TEMP_COIL          = 1 << 21, // 绕组过温
                ERR_ADC_DMA_INIT            = 1 << 22, // ADC DMA 初始化错误
                ERR_DOUBLE_ENCODER          = 1 << 23, // 双编码器错误
                ERR_LINERHALL_NOT_CALI      = 1 << 24, // 线性霍尔未校准
                ERR_LINERHALL_REVERSAL      = 1 << 25, // 线性霍尔反转
                ERR_LINERHALL_LOSS          = 1 << 26, // 线性霍尔丢失
                ERR_LINERHALL_WAVEFORM      = 1 << 27, // 线性霍尔波形错误
                ERR_U_PHASE_LOSS            = 1 << 28, // U 相丢失
                ERR_V_PHASE_LOSS            = 1 << 29, // V 相丢失
                ERR_W_PHASE_LOSS            = 1 << 30, // W 相丢失
                ERR_ETH_COM_TIMEOUT         = 1 << 31, // 以太网通信超时
        };

        /**
         * @brief   传感器错误码前两位表示传感器类型
         *          0x01 表示磁编码器
         *          0x02 表示线性霍尔
         */
        enum class ext2_magent_e {
                EXT2_MAGENET_NOT_CALI      = 1 << 3,  // 磁编码器未校准
                EXT2_MAGENET_CALIBRATION   = 1 << 4,  // 磁编码器校准错误
                EXT2_MAGENET_COMMUNICATION = 1 << 5,  // 磁编码器通信错误
                EXT2_MAGENET_PORT_NULL     = 1 << 6,  // 磁编码器空指针错误
                EXT2_MAGENET_AMPLITUDE     = 1 << 7,  // 磁编码器幅值错误
                EXT2_MAGENET_ANGLE_FULL    = 1 << 8,  // 磁编码器最大值错误
                EXT2_MAGENET_REVERSAL      = 1 << 9,  // 磁编码器反转错误
                EXT2_MAGENET_OVER_MAX      = 1 << 10, // 磁编码器配置极对数超上限
                EXT2_MAGENET_ECCENTRIC     = 1 << 11, // 磁编码器偏心校准数据异常

                EXT2_DPT_INNER_ROTOR_NEAR = 1 << 12, // 金刚编码器内圈转子过近
                EXT2_DPT_INNER_ROTOR_FAR  = 1 << 13, // 金刚编码器内圈转子过远
                EXT2_DPT_OUTER_ROTOR_NEAR = 1 << 14, // 金刚编码器外圈转子过近
                EXT2_DPT_OUTER_ROTOR_FAR  = 1 << 15, // 金刚编码器外圈转子过远
        };

        enum class ext2_linerhall_e {
                EXT2_LINERHALL_NOT_CALI          = 1 << 3,  // 线性霍尔未校准
                EXT2_LINERHALL_AMP               = 1 << 4,  // 线性霍尔最终校准值幅值错误
                EXT2_LINERHALL_MED               = 1 << 5,  // 线性霍尔中值错误
                EXT2_LINERHALL_MIN               = 1 << 6,  // 线性霍尔最小值错误
                EXT2_LINERHALL_MAX               = 1 << 7,  // 线性霍尔最大值错误
                EXT2_LINERHALL_ANGLE_OFFSET      = 1 << 8,  // 线性霍尔电角度偏置错误
                EXT2_LINERHALL_REVERSAL          = 1 << 9,  // 线性霍尔反转错误
                EXT2_LINERHALL_PORT_NULL         = 1 << 10, // 线性霍尔空指针错误
                EXT2_LINERHALL_AMP_ARRAY         = 1 << 11, // 线性霍尔某一个电周期幅值错误
                EXT2_LINERHALL_ANGLE_OFFSET_AVEG = 1 << 12, // 线性霍尔校准值与平均校准值偏差过大
                EXT2_LINERHALL_MED_AVEG          = 1 << 13, // 线性霍尔中值与平均中值偏差过大
                EXT2_LINERHALL_PHASE_DELTA       = 1 << 14, // 线性霍尔相位差错误
        };

        enum class ext3_e {
                EXT3_OVERLOAD_TEMP = 1 << 0, // 绕组过温
        };

        enum class ext8_e {
                EXT8_SETPVC_TIMEOUT_PROTECT = 1 << 0, // SETPVC 超时保护
        };
        /* --------------------------------- 执行器错误码 --------------------------------- */

        /* -------------------------------------------------------------------------- */
        /*                                    函数接口                                */
        /* -------------------------------------------------------------------------- */
      public:
        /* ---------------------------------- Power --------------------------------- */

        /**
         * @brief                   开启继电器
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e OpenRelay(int      timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                        uint32_t max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY) const;

        /**
         * @brief                   关闭继电器
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e CloseRelay(int      timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                         uint32_t max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY) const;

        /**
         * @brief                   重启执行器
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e Reboot(int timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS, uint32_t max_retry = SDK_CONFIG.DEFAULT_MAX_RETRY) const;
        /* ---------------------------------- Power --------------------------------- */

        /* --------------------------------- Control -------------------------------- */

        /**
         * @brief                   切换控制模式
         * @param ctrl_mode         控制模式
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e EnableControl(ctrl_mode_e ctrl_mode,
                            int         timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                            uint32_t    max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY);

        /**
         * @brief                   失能执行器
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e DisableControl(int timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS, uint32_t max_retry = SDK_CONFIG.DEFAULT_MAX_RETRY);

        /**
         * @brief                   发送目标位置指令、前馈速度指令、前馈力矩指令, 执行器不回复
         * @param tx_pos            目标位置
         * @param tx_vel_ff         前馈速度
         * @param tx_tor_ff         前馈力矩
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e SetPositionNoAck(double   tx_pos,
                               double   tx_vel_ff,
                               double   tx_tor_ff,
                               uint32_t max_retry = SDK_CONFIG.DEFAULT_MAX_RETRY) const;

        /**
         * @brief                   发送目标位置指令、前馈速度指令、前馈力矩指令, 执行器回复状态
         * @param tx_pos            目标位置
         * @param tx_vel_ff         前馈速度
         * @param tx_tor_ff         前馈力矩
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e SetPosition(double   tx_pos,
                          double   tx_vel_ff,
                          double   tx_tor_ff,
                          int      timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                          uint32_t max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY);

        /**
         * @brief                   发送目标速度指令、前馈力矩指令, 执行器不回复
         * @param tx_vel            目标速度
         * @param tx_tor_ff         前馈力矩
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e SetVelocityNoAck(double tx_vel, double tx_tor_ff, uint32_t max_retry = SDK_CONFIG.DEFAULT_MAX_RETRY) const;

        /**
         * @brief                   发送目标速度指令、前馈力矩指令, 执行器回复状态
         * @param tx_vel            目标速度
         * @param tx_tor_ff         前馈力矩
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e SetVelocity(double   tx_vel,
                          double   tx_tor_ff,
                          int      timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                          uint32_t max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY);

        /**
         * @brief                   发送目标电流指令, 执行器不回复
         * @param tx_tor            目标力矩
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e SetTorqueNoAck(double tx_tor, uint32_t max_retry = SDK_CONFIG.DEFAULT_MAX_RETRY) const;

        /**
         * @brief                   发送目标电流指令, 执行器回复状态
         * @param tx_tor            目标力矩
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e SetTorque(double   tx_tor,
                        int      timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                        uint32_t max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY);

        /**
         * @brief                   发送目标位置指令、前馈速度指令、前馈力矩指令, 执行器不回复
         * @param tx_pos            目标位置
         * @param tx_vel            目标速度
         * @param tx_tor_ff         前馈力矩
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e SetPDPositionVelocityNoAck(double   tx_pos,
                                         double   tx_vel,
                                         double   tx_tor_ff,
                                         uint32_t max_retry = SDK_CONFIG.DEFAULT_MAX_RETRY) const;

        /**
         * @brief                   发送目标位置指令、前馈速度指令、前馈力矩指令, 执行器回复状态
         * @param tx_pos            目标位置
         * @param tx_vel            目标速度
         * @param tx_tor_ff         前馈力矩
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e SetPDPositionVelocity(double   tx_pos,
                                    double   tx_vel,
                                    double   tx_tor_ff,
                                    int      timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                                    uint32_t max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY);
        /* --------------------------------- Control -------------------------------- */

        /* ---------------------------------- State --------------------------------- */

        /**
         * @brief                   获取反馈的执行器位置、速度、电流、负载转矩和电磁转矩
         * @param rx_pvctte         存放获取反馈的位置、速度、电流、负载转矩和电磁转矩
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e GetPVCTTe(pvctte_t &rx_pvctte,
                        int       timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                        uint32_t  max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY) const;

        /**
         * @brief                   配置订阅模式
         * @param tx_subs_config    订阅模式配置
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e EnableSubscribe(subs_config_t tx_subs_config,
                              int           timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                              uint32_t      max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY);

        /**
         * @brief                   获取执行器温度和母线电压
         * @param rx_temp_vbus      存放获取的温度和母线电压
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e GetTempVbus(temp_vbus_t &rx_temp_vbus,
                          int          timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                          uint32_t     max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY) const;

        /**
         * @brief                   获取执行器当前错误码
         * @param rx_error          存放获取的错误码数组, 共 8 个错误码
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e GetErrCode(err_code_t &rx_error,
                         int         timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                         uint32_t    max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY) const;

        /**
         * @brief                   获取最新的订阅数据
         * @param subs_data         存放获取的订阅数据
         * @return                  状态码
         */
        ret_e GetSubsData(subs_data_t &subs_data) const;
        /* ---------------------------------- State --------------------------------- */

        /* --------------------------------- Config --------------------------------- */

        /**
         * @brief                   获取临时立即生效(imm) PID 参数
         * @param tx_pos_kp         位置环 Kp
         * @param tx_vel_kp         速度环 Kp
         * @param tx_vel_ki         速度环 Ki
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e SetPIDParams(double   tx_pos_kp,
                           double   tx_vel_kp,
                           double   tx_vel_ki,
                           int      timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                           uint32_t max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY);

        /**
         * @brief                   获取临时立即生效(imm) PID 参数
         * @param rx_pid_param      存放获取的 PID 参数
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         * @warning                 执行器 V1, V2/2.5 的 ESP32 固件版本若在 0.3.12.25 以下,
         *                          该接口将返回持久化而非 imm 的 PID 参数
         */
        ret_e GetPIDParams(pid_param_t &rx_pid_param,
                           int          timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                           uint32_t     max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY) const;

        /**
         * @brief                   设置临时立即生效(imm) PD 参数
         * @param tx_pd_kp          PD 环 Kp
         * @param tx_pd_kd          PD 环 Kd
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         */
        ret_e SetPDParams(double   tx_pd_kp,
                          double   tx_pd_kd,
                          int      timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                          uint32_t max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY);

        /**
         * @brief                   获取临时立即生效(imm) PD 参数
         * @param rx_pd_param       存放获取的 PD 参数
         * @param timeout_ms        超时时间(ms)(可选)
         * @param max_retry         最大重试次数(可选)
         * @return                  状态码
         * @warning                 执行器 V1, V2/2.5 的 ESP32 固件版本若在 0.3.12.25 以下,
         *                          该接口将返回持久化而非 imm 的 PD 参数
         */
        ret_e GetPDParams(pd_param_t &rx_pd_param,
                          int         timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                          uint32_t    max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY) const;
        /* --------------------------------- Config --------------------------------- */

        /* -------------------------------- Advanced -------------------------------- */

        /**
         * @brief                                   配置超时保护功能
         * @param tx_setpvc_timeout_protect_config  超时保护配置
         * @param timeout_ms                        超时时间(ms)(可选)
         * @param max_retry                         最大重试次数(可选)
         * @return                                  状态码
         */
        ret_e EnableSetPVCTimeOutProtect(const setpvc_timeout_protect_config_t &tx_setpvc_timeout_protect_config,
                                         int                                    timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                                         uint32_t                               max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY);

        /**
         * @brief                                       清除超时保护状态
         * @param tx_clear_back_last_mode_of_operation  清除保护状态时是否恢复到进入保护状态前的操作模式
         * @param timeout_ms                            超时时间(ms)(可选)
         * @param max_retry                             最大重试次数(可选)
         * @return                                      状态码
         */
        ret_e ClearSetPVCTimeOutProtect(const uint32_t tx_clear_back_last_mode_of_operation,
                                        int            timeout_ms = SDK_CONFIG.DEFAULT_TIMEOUT_MS,
                                        uint32_t       max_retry  = SDK_CONFIG.DEFAULT_MAX_RETRY);
        /* -------------------------------- Advanced -------------------------------- */

        FSA() { lib_ver_check(); };
        ~FSA();

        ret_e Init(const char *ip, const net_recv_mode_e net_recv_mode);

        /* -------------------------------------------------------------------------- */
        /*                                    私有变量                                */
        /* -------------------------------------------------------------------------- */
      private:
        const char  *ip_{};
        net_manager *mgr_{};
        struct {
                net_channel *fast, *ctrl, *comm, *subs;
        } chs_{};

        uint32_t cnt;

        double tor2cur[3]{};
        double cur2tor[3]{};

        ctrl_config_t ctrl_config_{};
        root_t        root_{};

        ret_e version_check() const;
};
} // namespace AC2

#endif // FSAV2_H