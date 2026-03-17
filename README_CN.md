# FSA SDK 开源软件包

## 📋 关于

版本号：v3.0.0.15

构建号：1

## 📁 目录结构

```
fourier_actuator_sdk
├── .gitattributes
├── README.md
│
├── Linux-x86_64
│   ├── cpp
│   │   ├── fsav3.h
│   │   └── libfsav3.so
│   └── python
│       └── README.md
│
├── Windows-x86_64
│   ├── cpp
│   │   ├── fsav3.dll
│   │   ├── fsav3.exp
│   │   ├── fsav3.h
│   │   ├── fsav3.lib
│   │   ├── msvcp140.dll
│   │   ├── vcruntime140.dll
│   │   └── vcruntime140_1.dll
│   └── python
│       └── README.md
│
├── example
│   ├── cpp
│   └── python
│      
└── doc
    ├── CN
    │   ├── fourier_actuator_intro.md
    │   ├── fourier_actuator_sdk_cpp_api.md
    │   └── fourier_actuator_sdk_python_api.md
    ├── EN
    │   ├── fourier_actuator_intro.md
    │   ├── fourier_actuator_sdk_cpp_api.md
    │   └── fourier_actuator_sdk_python_api.md
    └── images
```

## 🚀 快速开始指南

### 第一步：硬件连接

1. **连接电源与网络**

   * 将 48V 直流电源连接到 FSA
   * 将网线连接到 FSA
   * 上电后观察 FSA 指示灯状态

2. **确认指示灯状态**

   * ✅ **紫色呼吸灯**：正常状态
   * ⚠️ **黄色 / 红色呼吸灯**：发生错误，需要通过上位机查询错误码

3. **确认 IP 地址**

   * 检查 FSA IP 是否为 `192.168.137.101`
   * > 💡 **提示**：C++ 示例程序默认使用 `192.168.137.101` 作为目标 FSA 地址

---

### 第二步：环境配置

#### Linux 环境

```bash
# 安装构建工具
sudo apt install build-essential cmake

# 安装 Python 依赖
pip install fi_fsa_v3 --break-system-packages
```

#### Windows 环境

```powershell
# 安装 Python 依赖
pip install fi_fsa_v3
```

---

### 第三步：运行示例程序

#### C++ - Linux

```bash
# 进入示例目录
cd example/cpp

# 编译
cmake -S . -B build_linux_cpp && cmake --build build_linux_cpp -j

# 运行示例
./build_linux_cpp/demo_get_info
```

#### C++ - Windows

```powershell
# 进入示例目录
cd example\cpp

# 编译（需要 MSVC）
cmake -S . -B build_windows_cpp; cmake --build build_windows_cpp --config Release

# 运行示例
.\build_windows_cpp\Debug\demo_get_info.exe
```

**注意：** 构建过程中只能使用 Release 配置。

---

#### C++ 示例输出

如果运行成功，你将看到类似如下的输出：

```text
Hello, FSA!
FSA initialized
p: -0.733910, v: 0.003944, c: 0.000000, t: 0.370531, te: 0.000000
mos: 24.196949, coil: 26.697445, vbus: 39.140625
err_code[0]: 0x0
err_code[1]: 0x2
err_code[2]: 0x8
err_code[3]: 0x0
err_code[4]: 0x0
err_code[5]: 0x0
err_code[6]: 0x0
err_code[7]: 0xC
parsed_err_codes size: 3
err_level: 1, err_u32_index: 2, err_bit_index: 3, parsed_code: 0x3303, str_for_log: WARNING3_DOUBLE_ENCODER
err_level: -2, err_u32_index: 7, err_bit_index: 2, parsed_code: 0x3802, str_for_log: INFO8_M4_FW_CHANGED
err_level: -2, err_u32_index: 7, err_bit_index: 3, parsed_code: 0x3803, str_for_log: INFO8_M4_VER_CHANGED
FSA: pos_kp: 0.0000, vel_kp: 0.0000, vel_ki: 0.0000
FSA: pd_kp: 0.0100, pd_kd: 0.0000
type: , sub_version: 
name: , type: , mcu_fw_version: , mac_address: , uid: , sn: , PCBA_sn: , gearbox_sn: , static_IP: , gateway: , subnet_mask: , dns_1: , dns_2: , DHCP_enable: 195
```

> ⚠️ **故障排查**：
> 如果返回了错误码，请参考 [C++ API 文档](doc/CN/fourier_actuator_sdk_cpp_api.md) 查询对应状态码并进行问题定位。

---

#### Python - Linux

```bash
# 进入示例目录
cd example/python

# 运行示例
python3 ./demo_get_info.py
```

#### Python - Windows

```powershell
# 进入示例目录
cd example\python

# 运行示例
python .\demo_get_info.py
```

---

#### Python 示例输出

如果运行成功，你将看到类似如下的输出：

```text
Hello, FSA!

FSA initialized

p: -0.7339, v: 0.0005, c: 0.0000, t: 0.0641, te: 0.0000

mos: 34.316509, coil: 28.619947, vbus: 39.147949

err_code[0]: 0x0

err_code[1]: 0x2

err_code[2]: 0x8

err_code[3]: 0x0

err_code[4]: 0x0

err_code[5]: 0x0

err_code[6]: 0x0

err_code[7]: 0xC

parsed_err_codes size: 3

err_level: 1, err_u32_index: 2, err_bit_index: 3, parsed_code: 0x3303, str_for_log: WARNING3_DOUBLE_ENCODER

err_level: -2, err_u32_index: 7, err_bit_index: 2, parsed_code: 0x3802, str_for_log: INFO8_M4_FW_CHANGED

err_level: -2, err_u32_index: 7, err_bit_index: 3, parsed_code: 0x3803, str_for_log: INFO8_M4_VER_CHANGED

PID: pos_kp=0.0000, vel_kp=0.0000, vel_ki=0.0000

PD: kp=0.0100, kd=0.0000

type: , sub_version: 

name: , type: , mcu_fw_version: , mac_address: , uid: , sn: , PCBA_sn: , gearbox_sn: , static_IP: , gateway: , subnet_mask: , dns_1: , dns_2: , DHCP_enable: False
```

---

### 第四步：让 FSA 转动

> ⚠️ **安全警告**：
>
> * 在使 FSA 转动前请务必**固定好执行器**
> * 请合理设置直流电源的限流阈值（空载电流可限制在 2A 以内）
> * 若 FSA 响应较慢，可能需要调整 PID / PD 参数

---

#### 位置控制示例 - C++（Linux）

```bash
# 进入示例目录
cd example/cpp/build_linux_cpp

# 运行示例
./demo_position_control
```

#### 位置控制示例 - C++（Windows）

```powershell
# 进入示例目录
cd example\cpp\build_windows_cpp

# 运行示例
.\Debug\demo_position_control.exe
```

#### 位置控制示例 - Python（Linux）

```bash
# 进入示例目录
cd example/python

# 运行示例
python3 ./demo_position_control.py
```

#### 位置控制示例 - Python（Windows）

```powershell
# 进入示例目录
cd example\python

# 运行示例
python .\demo_position_control.py
```

---

## 📚 相关文档

更多详细文档请参考：

- 📖 [执行器介绍](doc/CN/fourier_actuator_intro.md) - 了解 FSA 执行器的基本概念和控制模式

- 🔧 [C++ API 文档](doc/CN/fourier_actuator_sdk_cpp_api.md) - C++ 接口函数说明和示例

- 🐍 [Python API 文档](doc/CN/fourier_actuator_sdk_python_api.md) - Python 接口函数说明和示例

---

## 💡 提示

- 如果遇到问题，请先检查硬件连接和 IP 地址配置

- 错误码查询请参考对应的 API 文档

- 建议在固定 FSA 后再进行运动控制测试