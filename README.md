# FSA SDK Open Source Package

## About:

Version: v3.0.0.15

Build Number: 1

## Directory Structure:

```
fourier_actuator_sdk
├── .gitattributes
├── Linux-x86_64
│   ├── cpp
│   │   ├── fsav3.h
│   │   └── libfsav3.so
│   └── python
│       └── README.md
├── README.md
└── Windows-x86_64
    ├── cpp
    │   ├── fsav3.dll
    │   ├── fsav3.exp
    │   ├── fsav3.h
    │   ├── fsav3.lib
    │   ├── msvcp140.dll
    │   ├── vcruntime140.dll
    │   └── vcruntime140_1.dll
    └── python
        └── README.md
```

## 🚀 Quick Start Guide

### Step 1: Hardware Setup

1. **Connect Power and Network**
   - Connect the 48V DC power supply to the FSA
   - Connect the network cable to the FSA
   - Observe the FSA indicator light status after powering on

2. **Check Indicator Light Status**
   - ✅ **Purple breathing light**: Normal status
   - ⚠️ **Yellow/Red breathing light**: Error occurred, need to query error code through host computer

3. **Confirm IP Address**
   - Check if the FSA IP is `192.168.137.101`
   - > 💡 **Tip**: cpp example uses `192.168.137.101` as the default target FSA address

---

### Step 2: Environment Configuration

#### Linux Environment

```bash
# Install build tools
sudo apt install build-essential cmake

# Install Python dependencies
pip install fi_fsa_v3 --break-system-packages
```

#### Windows Environment

```powershell
# Install Python dependencies
pip install fi_fsa_v3
```

---

### Step 3: Run Example

#### C++ - Linux

```bash
# Navigate to example directory
cd example/cpp

# Build
cmake -S . -B build_linux_cpp && cmake --build build_linux_cpp -j

# Run example
./build_linux_cpp/demo_get_info
```

#### C++ - Windows

```powershell
# Navigate to example directory
cd example\cpp

# Build (requires MSVC)
cmake -S . -B build_windows_cpp; cmake --build build_windows_cpp --config Release

# Run example
.\build_windows_cpp\Debug\demo_get_info.exe
```

**Note:** Only the Release configuration can be used during the build process.

#### C++ Example Output

If successful, you should see output similar to the following:

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

> ⚠️ **Troubleshooting**: If an error code is returned, please refer to the [C++ API Documentation](doc/EN/fourier_actuator_sdk_cpp_api.md) to query the corresponding status code and troubleshoot.

---

#### Python - Linux

```bash
# Navigate to example directory
cd example/python

# Run example
python3 ./demo_get_info.py
```

#### Python - Windows

```powershell
# Navigate to example directory
cd example\python

# Run example
python .\demo_get_info.py
```

#### Python Example Output

If successful, you should see output similar to the following:

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

### Step 4: Make FSA Rotate

> ⚠️ **Safety Warning**:
>
> - **Secure the FSA** before making it rotate
> - Ensure the DC power supply current limit threshold is set appropriately (no-load current can be limited within 2A)
> - If the FSA response is slow, you may need to adjust PID/PD parameters

#### Position Control Example - C++ (Linux)

```bash
# Navigate to example directory
cd example/cpp/build_linux_cpp

# Run example
./demo_position_control
```

#### Position Control Example - C++ (Windows)

```powershell
# Navigate to example directory
cd example\cpp\build_windows_cpp

# Run example
.\Debug\demo_position_control.exe
```

#### Position Control Example - Python (Linux)

```bash
# Navigate to example directory
cd example/python

# Run example
python3 ./demo_position_control.py
```

#### Position Control Example - Python (Windows)

```powershell
# Navigate to example directory
cd example\python

# Run example
python .\demo_position_control.py
```