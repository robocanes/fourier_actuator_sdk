# FSA SDK 开源包

## 📋 关于

| 项目   | 信息     |
|--------|----------|
| 版本   | v2.0.0.2 |
| 构建号 | 1        |

---

## 📁 目录结构

```text
fourier_actuator_sdk
├── Linux-x86_64
│   ├── cpp
│   │   ├── example
│   │   ├── fsav2.h
│   │   └── libfsav2.so
│   └── python
│       ├── README.md
│       ├── v1
│       └── v2
├── README.md
├── Windows-x86_64
│   ├── cpp
│   │   ├── example
│   │   ├── fsav2.dll
│   │   ├── fsav2.h
│   │   └── libfsav2.dll.a
│   └── python
│       ├── README.md
│       ├── v1
│       └── v2
└── doc
    ├── CN
    │   ├── fourier_actuator_intro.md
    │   ├── fourier_actuator_sdk_cpp_api.md
    │   ├── fourier_actuator_sdk_python_api.md
    │   └── fourier_actuator_sdk_python_demo.md
    ├── EN
    │   ├── fourier_actuator_intro.md
    │   ├── fourier_actuator_sdk_cpp_api.md
    │   ├── fourier_actuator_sdk_python_api.md
    │   └── fourier_actuator_sdk_python_demo.md
    └── images
```

---

## 🚀 上手指南

### 步骤 1: 硬件准备

1. **连接电源和网络**
   - 将 48V 直流电源接入 FSA
   - 连接网线到 FSA
   - 上电后观察 FSA 指示灯状态

2. **检查指示灯状态**
   - ✅ **紫色呼吸灯**：正常状态
   - ⚠️ **黄色/红色呼吸灯**：出现错误，需要通过上位机查询错误码

3. **确认 IP 地址**
   - 检查 FSA IP 是否为 `192.168.137.101`
   - > 💡 **提示**：cpp example 默认使用 `192.168.137.101` 作为目标 FSA 地址

---

### 步骤 2: 环境配置

#### Linux 环境

```bash
# 安装编译工具
sudo apt install build-essential cmake

# 安装 Python 依赖
pip install numpy pandas fi_fsa
```

#### Windows 环境

```powershell
# 安装 Python 依赖
pip install numpy pandas fi_fsa
```

---

### 步骤 3: 运行示例

#### C++ - Linux

```bash
# 进入示例目录
cd Linux-x86_64/cpp/example

# 编译
cmake -B build -G "Unix Makefiles" && cmake --build build

# 运行示例
./build/get_pvctte
```

#### C++ - Windows

```powershell
# 进入示例目录
cd Windows-x86_64\cpp\example

# 编译（需要 MinGW）
cmake -B build -G "MinGW Makefiles" && cmake --build build

# 运行示例
.\build\get_pvctte.exe
```

#### C++ 示例输出

如果运行成功，应该看到类似以下输出：

```text
FSA(192.168.137.101): pos: 0.5418, vel: 0.0008, cur: 0.0000, tor: -0.0018, tor_e: 0.0000
FSA(192.168.137.101): elapsed time: 260 us
FSA(192.168.137.101): pos: 0.5418, vel: 0.0008, cur: 0.0000, tor: 0.0104, tor_e: 0.0000
FSA(192.168.137.101): elapsed time: 314 us
FSA(192.168.137.101): pos: 0.5418, vel: 0.0008, cur: 0.0000, tor: 0.0104, tor_e: 0.0000
FSA(192.168.137.101): elapsed time: 99 us
FSA(192.168.137.101): pos: 0.5418, vel: 0.0008, cur: 0.0000, tor: 0.0104, tor_e: 0.0000
FSA(192.168.137.101): elapsed time: 276 us
FSA(192.168.137.101): pos: 0.5418, vel: 0.0008, cur: 0.0000, tor: 0.0104, tor_e: 0.0000
FSA(192.168.137.101): elapsed time: 231 us
FSA(192.168.137.101): pos: 0.5418, vel: 0.0008, cur: 0.0000, tor: 0.0104, tor_e: 0.0000
FSA(192.168.137.101): elapsed time: 1308 us
FSA(192.168.137.101): pos: 0.5418, vel: -0.0012, cur: 0.0000, tor: 0.0032, tor_e: 0.0000
FSA(192.168.137.101): elapsed time: 88 us
FSA(192.168.137.101): pos: 0.5418, vel: -0.0012, cur: 0.0000, tor: 0.0032, tor_e: 0.0000
```

> ⚠️ **故障排除**：若返回错误码，请参考 [C++ API 文档](doc/CN/fourier_actuator_sdk_cpp_api.md) 查询对应状态码并排除错误。

#### Python - Linux

```bash
# 进入示例目录
cd Linux-x86_64/python/v2/example

# 运行示例
python3 ./demo_fast_get_pvct.py
```

#### Python - Windows

```powershell
# 进入示例目录
cd Windows-x86_64\python\v2\example

# 运行示例
python .\demo_fast_get_pvct.py
```

#### Python 示例输出

如果运行成功，应该看到类似以下输出：

```text
[2026.01.19 13:37:27.333.072]  Info:    192.168.137.101 : Send Data: b'\x1d'
[2026.01.19 13:37:27.333.072]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'\x1dA\xf8U&\xbc\xa0\xac\xbb\x00\x00\x00\x00:t\xfbX'
Position = 31.041576, Velocity = -0.019614, Current = 0.000000, Torque = 0.000935
[2026.01.19 13:37:27.534.313]  Info:    192.168.137.101 : Send Data: b'\x1d'
[2026.01.19 13:37:27.534.864]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'\x1dA\xf8U)<A\x96\xa8\x00\x00\x00\x00:\xa7\xf56'
Position = 31.041582, Velocity = 0.011816, Current = 0.000000, Torque = 0.001281
[2026.01.19 13:37:27.735.719]  Info:    192.168.137.101 : Send Data: b'\x1d'
[2026.01.19 13:37:27.736.739]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'\x1dA\xf8UA=x\x04\x86\x00\x00\x00\x00;\x7ff\xdc'
Position = 31.041628, Velocity = 0.060551, Current = 0.000000, Torque = 0.003897
[2026.01.19 13:37:27.936.982]  Info:    192.168.137.101 : Send Data: b'\x1d'
[2026.01.19 13:37:27.937.490]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'\x1dA\xf8UO<\xf7\xba\xe6\x00\x00\x00\x00\xbb\xc1\x8c\x80'
Position = 31.041655, Velocity = 0.030240, Current = 0.000000, Torque = -0.005907
[2026.01.19 13:37:28.138.463]  Info:    192.168.137.101 : Send Data: b'\x1d'
[2026.01.19 13:37:28.138.967]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'\x1dA\xf8U\x1a=r\x1d\xd2\x00\x00\x00\x00;\x91^\xcd'
Position = 31.041553, Velocity = 0.059110, Current = 0.000000, Torque = 0.004436
```

---

### 步骤 4: 使 FSA 转动

> ⚠️ **安全提示**：
>
> - 在使 FSA 转动前，**必须将 FSA 固定好**
> - 确保直流电源限流阈值设置合理（空载可限流在 2A 内）
> - 若 FSA 响应较慢，可能需要调整 PID/PD 参数

#### 位置控制示例 - C++ (Linux)

```bash
# 进入示例目录
cd Linux-x86_64/cpp/example

# 运行示例
./build/position_control
```

#### 位置控制示例 - C++ (Windows)

```powershell
# 进入示例目录
cd Windows-x86_64\cpp\example

# 运行示例
.\build\position_control.exe
```

#### 位置控制示例 - Python (Linux)

```bash
# 进入示例目录
cd Linux-x86_64/python/v2/example

# 运行示例
python3 ./demo_fast_control_position_mode.py
```

#### 位置控制示例 - Python (Windows)

```powershell
# 进入示例目录
cd Windows-x86_64\python\v2\example

# 运行示例
python .\demo_fast_control_position_mode.py
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
