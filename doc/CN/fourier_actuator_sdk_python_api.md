# 执行器python脚本接口文档

# 文档说明

数据单位说明：

| 数据类型 | 单位 |
| --- | --- |
| 位置 | 弧度（弧度制） |
| 速度 | 弧度/秒（弧度制） |
| 电流 | A |
| 力矩 | N·m |

# 接口函数说明

## ctrl接口

### EnableControl(ctrl_mode, timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_position_control.py`](fourier_actuator_sdk_python_demo.md#demo_position_controlpy)

**函数说明：**

| 函数作用 | 执行器控制使能 |
| --- | --- |
| 函数输入 | **ctrl_mode：** 控制模式<br> **timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |

| 函数输出 | 返回详细执行状态ret_e(int) |

| 控制模式具体配置 | 含义 | 类型 |
| --- | --- | --- |
| CURRENT_MODE | 电流控制模式，建议使用转矩控制模式 | int |
| TORQUE_MODE | 转矩控制模式 | int |
| VELOCITY_MODE | 转矩速度控制模式 | int |
| POSITION_MODE | 转矩位置控制模式 | int |
| PD_MODE | 转矩PD控制模式 | int |

### DisableControl(timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_position_control.py`](fourier_actuator_sdk_python_demo.md#demo_position_controlpy)

**函数说明：**

| 函数作用 | 失能执行器 |
| --- | --- |
| 函数输入 | **timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |

| 函数输出 | 返回详细执行状态ret_e(int) |

### SetPIDParams(p_kp, v_kp, v_ki, timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_position_control.py`](fourier_actuator_sdk_python_demo.md#demo_position_controlpy)

**函数说明：**

| 函数作用 | 实时设置位置环速度环PID参数 |
| --- | --- |
| 函数输入 | **p_kp：** 位置环比例增益<br>**v_kp：**  速度环比例增益<br>**v_ki：** 速度环积分增益<br>**timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |
| 函数输出 | 返回详细执行状态ret_e(int) |

### GetPIDParams(rx_pid, timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_get_info.py`](fourier_actuator_sdk_python_demo.md#demo_get_infopy)

**函数说明：**

| 函数作用 | 实时获取位置环速度环PID参数 |
| --- | --- |
| 函数输入 | **rx_pid：** 存放获取的 PID 参数<br>**timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |
| 函数输出 | 返回详细执行状态ret_e(int) |

### GetPVCTTe(rx_PVCTTe, timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_get_info.py`](fourier_actuator_sdk_python_demo.md#demo_get_infopy)

**函数说明：**

| 函数作用 | 获取执行器位置、速度、电流、力矩，电磁转矩 |
| --- | --- |
| 函数输入 | **rx_PVCTTe：** 存放获取的位置、速度、电流、力矩、电磁转矩<br>**timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |
| 函数输出 | 返回详细执行状态ret_e(int) |

### SetPosition(p_rad, v_ff_radps, t_ff_Nm, max_retry)

该函数对应的python脚本demo为[`demo_position_control.py`](fourier_actuator_sdk_python_demo.md#demo_position_controlpy)

**函数说明：**

| 函数作用 | 发送位置目标指令、速度前馈指令、力矩前馈指令，执行器回复数据帧 |
| --- | --- |
| 函数输入 | **p_rad：** 目标位置<br>**v_ff_radps：** 速度前馈<br>**v_ff_radps：** 力矩前馈<br>**t_ff_Nm：** 力矩前馈<br>**timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |
| 函数输出 | 返回详细执行状态ret_e(int) |

### SetTorque(t_Nm, timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_torque_control.py`](fourier_actuator_sdk_python_demo.md#demo_torque_controlpy)

**函数说明：**

| 函数作用 | 发送力矩目标指令，执行器回复数据帧 |
| --- | --- |
| 函数输入 | **t_Nm：** 目标力矩<br>**timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |
| 函数输出 | 返回详细执行状态ret_e(int) |

### GetTempVbus(rx_temp_vbus, timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_get_info.py`](fourier_actuator_sdk_python_demo.md#demo_get_infopy)

**函数说明：**

| 函数作用 | 获取执行器mos温度，绕组温度，电压 |
| --- | --- |
| 函数输入 | **rx_temp_vbus：** 存放获取的mos温度，绕组温度，电压<br>**timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |
| 函数输出 | 返回详细执行状态ret_e(int) |

### GetErrCode(rx_errcode, timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_get_info.py`](fourier_actuator_sdk_python_demo.md#demo_get_infopy)

**函数说明：**

| 函数作用 | 获取执行器当前错误码 |
| --- | --- |
| 函数输入 | **rx_errcode：** 存放获取的错误码<br>**timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |
| 函数输出 | 返回详细执行状态ret_e(int) |

### ParseErrCode(err_code, parsed_err_code)

该函数对应的python脚本demo为[`demo_get_info.py`](fourier_actuator_sdk_python_demo.md#demo_get_infopy)

**函数说明：**

| 函数作用 | 解析执行器错误码 |
| --- | --- |
| 函数输入 | **err_code：** 获取到的8个uint32_t错误码<br>**parsed_err_code：** 解析后的错误码 |
| 函数输出 | 返回详细执行状态ret_e(int) |

### GetPDParams(rx_pd, timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_get_info.py`](fourier_actuator_sdk_python_demo.md#demo_get_infopy)

**函数说明：**

| 函数作用 | 获取临时立即生效 (imm) PD 参数 |
| --- | --- |
| 函数输入 | **rx_pd：** 存放获取的 PD 参数<br>**timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |
| 函数输出 | 返回详细执行状态ret_e(int) |

### GetTypeSubversion(type_subversion, timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_get_info.py`](fourier_actuator_sdk_python_demo.md#demo_get_infopy)

**函数说明：**

| 函数作用 | 获取执行器型号和子版本号 |
| --- | --- |
| 函数输入 | **type_subversion：** 存放获取的型号和子版本号<br>**timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |
| 函数输出 | 返回详细执行状态ret_e(int) |

### GetCommConfig(comm_req_get, comm_resp_get, timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_get_info.py`](fourier_actuator_sdk_python_demo.md#demo_get_infopy)

**函数说明：**

| 函数作用 | 获取执行器通信配置参数 |
| --- | --- |
| 函数输入 | **comm_req_get：** 请求哪些通信配置参数<br>**comm_resp_get：** 存放获取的通信配置参数<br>**timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |
| 函数输出 | 返回详细执行状态ret_e(int) |

| 通信参数具体配置 | 含义 | 类型 |
| --- | --- | --- |
| DHCP_enable | 是否获取 DHCP 启用状态 | bool |
| PCBA_sn | 是否获取 PCBA SN | bool |
| dns_1 | 是否获取 DNS 1 | bool |
| dns_2 | 是否获取 DNS 2 | bool |
| gateway | 是否获取网关 | bool |
| gearbox_sn | 是否获取齿轮箱 SN | bool |
| mac_address | 是否获取 MAC 地址 | bool |
| mcu_fw_version | 是否获取 MCU 固件版本 | bool |
| name | 是否获取名称 | bool |
| sn | 是否获取 SN | bool |
| static_IP | 是否获取静态 IP | bool |
| subnet_mask | 是否获取子网掩码 | bool |
| type | 是否获取类型 | bool |
| uid | 是否获取 UID | bool |

### EnableSubscribe(subs_config, timeout_ms, max_retry)

该函数对应的python脚本demo为[`demo_subscribe.py`](fourier_actuator_sdk_python_demo.md#demo_subscribepy)

**函数说明：**

| 函数作用 | 配置订阅模式 |
| --- | --- |
| 函数输入 | **subs_config：** 订阅模式配置<br>**timeout_ms：** 超时时间（ms），默认为 5ms<br>**max_retry：** 最大重试次数，默认为 1 次 |
| 函数输出 | 返回详细执行状态ret_e(int) |

| 订阅参数具体配置 | 含义 | 类型 |
| --- | --- | --- |
| cur | 电流订阅使能，0:禁用，1:启用 | int |
| enable | 订阅使能，0:禁用，1:启用 | int |
| error | 错误码订阅使能，0:禁用，1:启用 | int |
| error_ext2 | 错误码扩展2订阅使能，0:禁用，1:启用 | int |
| error_ext3 | 错误码扩展3订阅使能，0:禁用，1:启用 | int |
| error_ext4 | 错误码扩展4订阅使能，0:禁用，1:启用 | int |
| error_ext5 | 错误码扩展4订阅使能，0:禁用，1:启用 | int |
| error_ext6 | 错误码扩展4订阅使能，0:禁用，1:启用 | int |
| error_ext7 | 错误码扩展4订阅使能，0:禁用，1:启用 | int |
| error_ext8 | 错误码扩展4订阅使能，0:禁用，1:启用 | int |
| freq | 订阅回传频率，单位Hz | int |
| keepalive_time_ms | 保持时间时间，单位ms | int |
| pos | 位置订阅使能，0:禁用，1:启用 | int |
| temp_coil | 线圈温度订阅使能，0:禁用，1:启用 | int |
| temp_mos | MOS温度订阅使能，0:禁用，1:启用 | int |
| tor | 转矩订阅使能，0:禁用，1:启用 | int |
| tor_em | 电磁转矩订阅使能，0:禁用，1:启用 | int |
| vbus | VBUS电压订阅使能，0:禁用，1:启用 | int |
| vel | 速度订阅使能，0:禁用，1:启用 | int |

### GetSubsData(subs_data)

该函数对应的python脚本demo为[`demo_subscribe.py`](fourier_actuator_sdk_python_demo.md#demo_subscribepy)

**函数说明：**

| 函数作用 | 获取最新的订阅数据 |
| --- | --- |
| 函数输入 | **subs_data：** 存放获取的订阅数据 |
| 函数输出 | 返回详细执行状态ret_e(int) |

