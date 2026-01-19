# 执行器python脚本接口文档

# 文档说明

数据单位说明：

| 数据类型 | 单位 |
| --- | --- |
| 位置 | 度（角度制） |
| 速度 | 度/秒（角度制） |
| 电流 | A |
| 力矩 | N·m |

# 接口函数说明

## comm接口

### get\_comm\_root(server\_ip)

该函数对应的python脚本demo为[`demo_lookup.py`](fourier_actuator_sdk_python_demo.md#demo_lookuppy)

**函数说明：**

| 函数作用 | 获取执行器的基本属性 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 对应执行器的所有基本属性，包括序列号、网络配置等，类型为dict。 |

### get\_comm\_driver\_version(server\_ip)

该函数对应的python脚本demo为[`demo_comm_driver_firmware_version_get.py`](fourier_actuator_sdk_python_demo.md#demo_comm_driver_firmware_version_getpy)

**函数说明：**

| 函数作用 | 获取执行器的驱动固件版本 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 对应执行器的驱动固件版本，类型为str。 |

### get\_comm\_firmware\_version(server\_ip)

该函数对应的python脚本demo为[`demo_comm_driver_firmware_version_get.py`](fourier_actuator_sdk_python_demo.md#demo_comm_driver_firmware_version_getpy)

**函数说明：**

| 函数作用 | 获取执行器的通信固件版本 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 对应执行器的通信固件版本，类型为str。 |

### get\_comm\_config(server\_ip)

该函数对应的python脚本demo为[`demo_comm_config_get.py`](fourier_actuator_sdk_python_demo.md#demo_comm_config_getpy)

| 函数作用 | 获取执行器的config属性（会在终端打印执行器的config属性） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_comm\_config(server\_ip, dict)

该函数对应的python脚本demo为[`demo_comm_config_set.py`](fourier_actuator_sdk_python_demo.md#demo_comm_config_setpy)

| 函数作用 | 设置执行器的config属性 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict：** config的配置参数。详细内容如下表所示 |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

| config的配置参数 | 类型 | 含义 | 推荐设置值 |
| --- | --- | --- | --- |
| **name** | str | 执行器名字 | "当前连接的执行器的名字" |
| **DHCP\_enable** | bool | 是否开启DHCP,建议关闭DHCP(开启的情况下会自动分配ip) | False |
| **SSID** | str | 需要连接的wifi名称，仅在ota升级时，有线不可用的情况下，无线ota时使用（只有V1执行器支持无线ota） | "当前网络环境下可用无线网络的wifi名" |
| **password** | str | 需要连接的wifi密码，仅在ota升级时，有线不可用的情况下，无线ota时使用（只有V1执行器支持无线ota） | "当前网络环境下可用无线网络的wifi密码" |
| **static\_IP** | list | 静态ip，为执行器自己的ip | 当前连接执行器的需要设置的ip |
| **gateway** | list | 网关 | \[192,168,137,1\] |
| **subnet\_mask** | list | 子网掩码 | \[255,255,255,0\] |
| **dns\_1** | list | 首选域名服务器地址，仅在ota升级时使用 | \[114,114,114,114\] |
| **dns\_2** | list | 备选域名服务器地址,仅在ota升级时使用 | \[8,8,8,8\] |

```python
            dict = {
                "name": "FSA-0",
                "DHCP_enable": False,
                "SSID": "fftai-6",
                "password": "fftai2015",
                "static_IP": [192, 168, 137, 101],
                "gateway": [192, 168, 137, 1],
                "subnet_mask": [255, 255, 255, 0],
                "dns_1": [114, 114, 114, 114],
                "dns_2": [8, 8, 8, 8],
            }
```

### broadcast\_func()

该函数基本上在所有python脚本中都有用到。

| 函数作用 | 广播查询局域网下的全部傅利叶自研设备 |
| --- | --- |
| 函数输入 | 无 |
| 函数输出 | **address\_list**： 所有查询到的傅利叶自研设备ip,类型为list |

### broadcast\_func\_with\_filter(filter\_type)

该函数在大部分的python脚本中都有用到。

| 函数作用 | 广播查询局域网下的全部符合条件的傅利叶自研设备 |
| --- | --- |
| 函数输入 | **filter\_type：** 筛选的执行器类别，类型为str,可以有Actuator、AbsEncoder、CtrlBox可以选择。 |
| 函数输出 | 所有查询到的符合条件的傅利叶自研设备ip,类型为list |

<a id="set_subscribe"></a>

### set\_subscribe(server\_ip, cfg\_dict)

该函数对应的python脚本demo为[`demo_set_subscribe.py`](fourier_actuator_sdk_python_demo.md#demo_set_subscribepy)

| 函数作用 | 订阅接口，将执行器的数据可选择地发送到指定端口 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cfg\_dict：**  subscribe的配置参数，类型为dict。详细内容如下 |
| 函数输出 | 无返回值 |

| subscribe的配置参数 | 类型 | 含义 | 推荐设置值 |
| --- | --- | --- | --- |
| **port** | int | 执行器发送给PC的目标端口号 | 当前电脑上的端口 |
| **enable** | int | 是否发送，0表示不发送，1表示发送 | 1 |
| **position** | int | 是否发送位置，0表示不发送，1表示发送 | 1 |
| **velocity** | int | 是否发送速度，0表示不发送，1表示发送 | 1 |
| **current** | int | 是否发送电流，0表示不发送，1表示发送 | 1 |
| **torque** | int | 是否发送力矩，0表示不发送，1表示发送 | 1 |
| **error** | int | 是否发送错误码，0表示不发送，1表示发送 | 1 |
| **error\_ext2** | int | 是否发送扩展错误码2，0表示不发送，1表示发送 | 1 |
| **error\_ext3** | int | 是否发送扩展错误码3，0表示不发送，1表示发送 | 1 |
| **error\_ext4** | int | 是否发送扩展错误码4，0表示不发送，1表示发送 | 1 |
| **error\_ext5** | int | 是否发送扩展错误码5，0表示不发送，1表示发送 | 1 |
| **error\_ext6** | int | 是否发送扩展错误码6，0表示不发送，1表示发送 | 1 |
| **error\_ext7** | int | 是否发送扩展错误码7，0表示不发送，1表示发送 | 1 |
| **error\_ext8** | int | 是否发送扩展错误码8，0表示不发送，1表示发送 | 1 |

```python
udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_socket.bind(("", 0))
addr_not_use, port = udp_socket.getsockname()
print("Socket is bound to port:", port)
config = {
    "port": port,
    "enable": 1,
    "position": 1,
    "velocity": 1,
    "current": 1,
    "torque": 1,
    "error": 1,
    "error_ext2": 1,
    "error_ext3": 1,
    "error_ext4": 1,
    "error_ext5": 1,
    "error_ext6": 1,
    "error_ext7": 1,
    "error_ext8": 1,
}
```

### ota(server\_ip)

该函数对应的python脚本demo为[`demo_ota.py`](fourier_actuator_sdk_python_demo.md#demo_otapy)

| 函数作用 | 对执行器进行通信ota升级，升级版本为生产版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 无返回值 |

### ota\_test(server\_ip)

该函数对应的python脚本demo为[`demo_ota_test.py`](fourier_actuator_sdk_python_demo.md#demo_ota_testpy)

| 函数作用 | 对执行器进行通信ota升级，升级版本为测试版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 无返回值 |

### ota\_devel(server\_ip)

该函数对应的python脚本demo为[`demo_ota_devel.py`](fourier_actuator_sdk_python_demo.md#demo_ota_develpy)

| 函数作用 | 对执行器进行通信ota升级，升级版本为开发版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 无返回值 |

### ota\_cloud(server\_ip)

该函数对应的python脚本demo为[`demo_ota_cloud.py`](fourier_actuator_sdk_python_demo.md#demo_ota_cloudpy)

| 函数作用 | 对执行器进行通信ota升级，升级版本为云端版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 无返回值 |

### ota\_custom(server\_ip, version\_str)

该函数对应的python脚本demo为[`demo_ota_custom.py`](fourier_actuator_sdk_python_demo.md#demo_ota_custompy)

| 函数作用 | 对执行器进行通信ota升级，升级版本为自定义版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str<br>**version\_str：** 升级的版本号，类型为str |
| 函数输出 | 无返回值 |

### ota\_driver(server\_ip)

该函数对应的python脚本demo为[`demo_ota_driver.py`](fourier_actuator_sdk_python_demo.md#demo_ota_driverpy)

| 函数作用 | 对执行器进行驱动ota升级，升级版本为生产版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str |
| 函数输出 | 无返回值 |

### ota\_driver\_test(server\_ip)

该函数对应的python脚本demo为[`demo_ota_driver_test.py`](fourier_actuator_sdk_python_demo.md#demo_ota_driver_testpy)

| 函数作用 | 对执行器进行驱动ota升级，升级版本为测试版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str |
| 函数输出 | 无返回值 |

### ota\_driver\_devel(server\_ip)

该函数对应的python脚本demo为[`demo_ota_driver_devel.py`](fourier_actuator_sdk_python_demo.md#demo_ota_driver_develpy)

| 函数作用 | 对执行器进行驱动ota升级，升级版本为开发版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str |
| 函数输出 | 无返回值 |

### ota\_driver\_cloud(server\_ip)

该函数对应的python脚本demo为[`demo_ota_driver_cloud.py`](fourier_actuator_sdk_python_demo.md#demo_ota_driver_cloudpy)

| 函数作用 | 对执行器进行驱动ota升级，升级版本为云端版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str |
| 函数输出 | 无返回值 |

### ota\_driver\_custom(server\_ip ,version\_str)

该函数对应的python脚本demo为[`demo_ota_driver_custom.py`](fourier_actuator_sdk_python_demo.md#demo_ota_driver_custompy)

| 函数作用 | 对执行器进行驱动ota升级，升级版本为自定义版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str<br>**version\_str：** 升级的版本号，类型为str |
| 函数输出 | 无返回值 |

## ctrl接口

### set\_enable(server\_ip)

该函数对应的python脚本demo为[`demo_enable_set.py`](fourier_actuator_sdk_python_demo.md#demo_enable_setpy)

**函数说明：**

| 函数作用 | 设置执行器的使能 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_disable(server\_ip)

该函数对应的python脚本demo为[`demo_enable_set.py`](fourier_actuator_sdk_python_demo.md#demo_enable_setpy)

**函数说明：**

| 函数作用 | 设置执行器的失能 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### clear\_fault(server\_ip)

该函数对应的python脚本demo为[`demo_clear_fault.py`](fourier_actuator_sdk_python_demo.md#demo_clear_faultpy)

**函数说明：**

| 函数作用 | 清空执行器的错误码 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_calibrate\_encoder(server\_ip)

该函数对应的python脚本demo为[`demo_set_calibrate_encoder.py`](fourier_actuator_sdk_python_demo.md#demo_set_calibrate_encoderpy)（注意：校准过程中，执行器会转动，建议要把执行器固定好再校准）

**函数说明：**

| 函数作用 | 设置执行器的模式为校准模式 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### get\_state(server\_ip)

**函数说明：**

| 函数作用 | 获取执行器当前的状态 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 执行器当前状态，类型为str或空。当前状态正常返回“OK”,不正常返回None |

### set\_mode\_of\_operation(server\_ip, mode\_of\_operation)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器的操作模式（位置、速度、电流、力矩） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**mode\_of\_operation：** 执行器的操作模式，类型为int，具体有位置、速度、电流、力矩可以选择 |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

| **mode\_of\_operation的模式** | 对应的int值 | FSAModeOfOperation类中对应的变量 |
| --- | --- | --- |
| 无模式 | 0 | NONE |
| 位置模式 | 1 | POSITION\_CONTROL |
| 速度模式 | 3 | VELOCITY\_CONTROL |
| 电流模式 | 4 | CURRENT\_CONTROL |
| 力矩模式 | 6 | TORQUE\_CONTROL |
| 位置pd模式 | 7 | POSITION\_CONTROL\_PD |

```python
#设置位置模式
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.NONE)
#设置位置模式
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL)
#设置速度模式
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.VELOCITY_CONTROL)
#设置电流模式
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.CURRENT_CONTROL)
#设置力矩模式
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.TORQUE_CONTROL)
#设置位置pd模式
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL_PD)
```

### get\_pid\_param(server\_ip)

该函数对应的python脚本demo为[`demo_pid_param_get.py`](fourier_actuator_sdk_python_demo.md#demo_pid_param_getpy)

**函数说明：**

| 函数作用 | 获取执行器的pid参数（注意：该pid参数需要重启后才能生效） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_pid\_param(server\_ip, dict)

该函数对应的python脚本demo为[`demo_pid_param_set.py`](fourier_actuator_sdk_python_demo.md#demo_pid_param_setpy)

**函数说明：**

| 函数作用 | 设置执行器的pid参数（注意：该pid参数需要重启后才能生效） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict：** pid参数,类型为dict |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

| pid参数具体配置 | 含义 | 类型 |
| --- | --- | --- |
| control\_position\_kp | 位置环kp | float |
| control\_velocity\_kp | 速度环kp | float |
| control\_velocity\_ki | 速度环ki | float |
| control\_current\_kp | 电流环kp | float |
| control\_current\_ki | 电流环ki | float |
| control\_PD\_kp | PD模式kp | float |
| control\_PD\_kd | PD模式kd | float |

```python
  dict = { 
                "control_position_kp": 0.5,
                "control_velocity_kp": 0.0025,
                "control_velocity_ki": 0.00001,
                "control_PD_kp": 1.0,
                "control_PD_kd": 1.0,
            }
```

### get\_pid\_param\_imm(server\_ip)

该函数对应的python脚本demo为[`demo_pid_param_imm_get.py`](fourier_actuator_sdk_python_demo.md#demo_pid_param_imm_getpy)

**函数说明：**

| 函数作用 | 获取执行器的pid（临时）参数（注意：该pid参数立即生效，但是断电后不会保存该参数） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_pid\_param\_imm(server\_ip, dict)

该函数对应的python脚本demo为[`demo_pid_param_imm_set.py`](fourier_actuator_sdk_python_demo.md#demo_pid_param_imm_setpy)

**函数说明：**

| 函数作用 | 设置执行器的pid（临时）参数（注意：该pid参数立即生效，但是断电后不会保存该参数） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict：** pid参数,类型为dict |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

| pid参数具体配置 | 含义 | 类型 |
| --- | --- | --- |
| control\_position\_kp\_imm | 临时位置环kp | float |
| control\_velocity\_kp\_imm | 临时速度环kp | float |
| control\_velocity\_ki\_imm | 临时速度环ki | float |
| control\_PD\_kp\_imm | 临时PD模式kp | float |
| control\_PD\_kd\_imm | 临时PD模式kd | float |

```python
dict = { 
                "control_position_kp_imm": 0.0,
                "control_velocity_kp_imm": 0.1,
                "control_velocity_ki_imm": 0.001,
                "control_PD_kp_imm": 1.0,
                "control_PD_kd_imm": 1.0,
            }
```

### get\_control\_param(server\_ip)

该函数对应的python脚本demo为[`demo_control_param_get.py`](fourier_actuator_sdk_python_demo.md#demo_control_param_getpy)

**函数说明：**

| 函数作用 | 获取执行器的控制参数（注意：该控制参数需要重启后才能生效） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_control\_param(server\_ip, dict)

该函数对应的python脚本demo为[`demo_control_param_set.py`](fourier_actuator_sdk_python_demo.md#demo_control_param_setpy)

**函数说明：**

| 函数作用 | 设置执行器的控制参数（注意：该控制参数需要重启后才能生效） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict：** 控制参数,类型为dict |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

| 控制参数具体配置 | 含义 | 类型 |
| --- | --- | --- |
| motor\_max\_speed | 执行器的最大速度 | int |
| motor\_max\_acceleration | 执行器的最大加速度 | int |
| motor\_max\_current | 执行器的最大电流 | int |

```python
            dict = {
                "motor_max_speed": 3000,
                "motor_max_acceleration": 60000,
                "motor_max_current": 8,
            }
```

### get\_flag\_of\_operation(server\_ip)

该函数对应的python脚本demo为[`demo_flag_of_operation_get.py`](fourier_actuator_sdk_python_demo.md#demo_flag_of_operation_getpy)

**函数说明：**

| 函数作用 | 获取执行器的操作标识 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_flag\_of\_operation(server\_ip, dict\_cfg)

该函数对应的python脚本demo为[`demo_flag_of_operation_set.py`](fourier_actuator_sdk_python_demo.md#demo_flag_of_operation_setpy)

**函数说明：**

| 函数作用 | 设置执行器的操作标识 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict\_cfg：** 操作标识,类型为dict |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

| 操作标识具体配置 | 含义 | 类型 |
| --- | --- | --- |
| flag\_do\_use\_store\_motor\_param | 是否启动配置参数，1表示启用，0表示不启用 | int |
| flag\_do\_use\_store\_pid\_param | 是否启动pid参数，1表示启用，0表示不启用 | int |
| actuator\_double\_encoder\_enable | 是否启动双编功能，1表示启用，0表示不启用 | int |

```python
 dict_cfg = {
                "flag_do_use_store_motor_param": 1,
                "flag_do_use_store_pid_param": 0,
                "actuator_double_encoder_enable": 1,
            }
```

### get\_config(server\_ip)

该函数对应的python脚本demo为[`demo_ctrl_config_get.py`](fourier_actuator_sdk_python_demo.md#demo_ctrl_config_getpy)

**函数说明：**

| 函数作用 | 获取执行器的配置信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_config(server\_ip, dict)

该函数对应的python脚本demo为[`demo_ctrl_config_set.py`](fourier_actuator_sdk_python_demo.md#demo_ctrl_config_setpy)

**函数说明：**

| 函数作用 | 设置执行器的配置信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict：** 执行器的配置信息，类型为dict |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

| 执行器的配置信息具体配置 | 含义 | 类型 |
| --- | --- | --- |
| actuator\_direction | 执行器转向 | int |
| actuator\_reduction\_ratio | 减速比 | float |
| motor\_type | 电机型号 | unsigned int |
| motor\_hardware\_type | 驱动板型号 | unsigned int |
| motor\_direction | 电机转向 | int |
| motor\_max\_speed | 电机最大速度 | float |
| motor\_max\_acceleration | 电机最大加速度 | float |
| motor\_max\_current | 电机限幅 | float |
| actuator\_comm\_hardware\_type | 通讯板型号 | int |

| 执行器方向具体数值 | 含义 |
| --- | --- |
| 1 | 正向（顺时针） |
| \-1 | 反向（逆时针） |

| 电机型号具体数值 | 含义 |
| --- | --- |
| 0 | MOTOR\_NULL（无型号） |
| 7 | 25\_08V0 |
| 6 | 36\_08V0 |
| 8 | 36\_10V0 |
| 5 | 60\_08V0 |
| 4 | 80\_10V0 |
| 3 | 100\_15V0 |
| 2 | 130\_20V0 |
| 13 | 45\_15V1 |
| 12 | 60\_08V1 |
| 11 | 80\_10V1 |
| 10 | 100\_15V1 |
| 9 | 130\_20V1 |

| 驱动板型号具体数值 | 含义 |
| --- | --- |
| 0 | HARDWARE\_NULL（无型号） |
| 2 | H95V104 |
| 3 | H66V104 |
| 4 | H46V104 |
| 5 | H30V303 |
| 7 | H54V100 |
| 8 | H66V106 |
| 9 | H88V100 |
| 10 | H106V100 |
| 11 | H142V100 |
| 12 | H142V102 |
| 13 | H66V202 |
| 16 | H100V100 |
| 17 | H58V100 |

| 电机转向具体数值 | 含义 |
| --- | --- |
| 1 | 正向（顺时针） |
| \-1 | 反向（逆时针） |

| 通讯板型号 | 含义 |
| --- | --- |
| 0 | NULL（无版本） |
| 1 | V1 |
| 2 | V2 |

```python
 cfg_dict = {
                'actuator_direction': 1,
                'actuator_reduction_ratio': 31,
                'motor_type': 7,
                'motor_hardware_type': 5,
                'motor_direction': 1,
                "motor_max_speed": 3000,
                "motor_max_acceleration": 60000,
                'motor_max_current': 60,
                "actuator_comm_hardware_type": 2,
                "actuator_double_encoder_enable": 0
            }
```

### reboot(server\_ip)

该函数对应的python脚本demo为[`demo_reboot.py`](fourier_actuator_sdk_python_demo.md#demo_rebootpy)

**函数说明：**

| 函数作用 | 重启执行器 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否重启成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### get\_error\_code(server\_ip)

该函数对应的python脚本demo为[`demo_get_error.py`](fourier_actuator_sdk_python_demo.md#demo_get_errorpy)

**函数说明：**

| 函数作用 | 获取执行器的错误码 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 具体的错误码，返回类型为int或者list或者None。获取失败返回None,错误码为一个时，返回值类型为int,错误码为多个时，返回值类型为list。 |

### get\_pvc(server\_ip)

该函数对应的python脚本demo为[`demo_get_pvc.py`](fourier_actuator_sdk_python_demo.md#demo_get_pvcpy)

**函数说明：**

| 函数作用 | 获取执行器当前的位置、速度、电流的信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 具体的位置、速度、电流的信息，返回类型为tuple,返回值按顺序为位置、速度、电流。 |

### get\_foc\_target\_PVC(server\_ip)

该函数对应的python脚本demo为[`demo_get_foc_target_PVC.py`](fourier_actuator_sdk_python_demo.md#demo_get_foc_target_pvcpy)

**函数说明：**

| 函数作用 | 获取执行器FOC执行的目标位置、目标速度、目标电流的信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 具体FOC执行的目标位置、目标速度、目标电流的信息，返回类型为tuple,返回值按顺序为位置、速度、电流。 |

### get\_pvct(server\_ip)

该函数对应的python脚本demo为[`demo_get_pvct.py`](fourier_actuator_sdk_python_demo.md#demo_get_pvctpy)

**函数说明：**

| 函数作用 | 获取执行器当前的位置、速度、电流、力矩的信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 具体FOC执行的位置、速度、电流、力矩的信息，返回类型为tuple,返回值按顺序为位置、速度、电流、力矩。 |

### get\_fsa\_abs\_position(server\_ip) 

该函数对应的python脚本demo为[`demo_get_fsa_abs_position.py`](fourier_actuator_sdk_python_demo.md#demo_get_fsa_abs_positionpy)

**函数说明：**

| 函数作用 | 获取执行器绝对编码器的位置信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 绝对编码器的位置信息,类型为float。 |

### set\_fsa\_abs\_zero(server\_ip)

该函数对应的python脚本demo为[`demo_set_fsa_abs_zero.py`](fourier_actuator_sdk_python_demo.md#demo_set_fsa_abs_zeropy)

**函数说明：**

| 函数作用 | 设置执行器的绝对编码器的零点，以此刻的位置为零点。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### set\_eth\_recovery(server\_ip)

该函数对应的python脚本demo为[`demo_set_eth_recovery.py`](fourier_actuator_sdk_python_demo.md#demo_set_eth_recoverypy)

**函数说明：**

| 函数作用 | 恢复执行器的网络 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### set\_eth\_timeout\_protect(server\_ip, is\_enable, timeout\_interval)低版本不能用

该函数对应的python脚本demo为[`demo_set_eth_timeout_protect.py`](fourier_actuator_sdk_python_demo.md#demo_set_eth_timeout_protectpy)

**函数说明：**

| 函数作用 | 设置执行器网络的超时保护 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**is\_enable：** 是否启用网络的超时保护，类型为int，0为不启用，1为启用<br>**timeout\_interval：** 超时检测时间，单位毫秒，类型为int |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### set\_control\_loop\_freq\_div(server\_ip, position\_loop\_freq\_div, velocity\_loop\_freq\_div, PD\_loop\_freq\_div)低版本不能用

该函数对应的python脚本demo为[`demo_set_control_loop_freq_div.py`](fourier_actuator_sdk_python_demo.md#demo_set_control_loop_freq_divpy)

**函数说明：**

| 函数作用 | 将执行器的控制频率除于一个特定数值，以做到修改实际控制频率的作用 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**position\_loop\_freq\_div：** 在位置模式下，位置控制频率所需除以的特定数值，类型为float<br>**velocity\_loop\_freq\_div：** 在速度模式下，速度控制频率所需除以的特定数值，类型为float<br>**PD\_loop\_freq\_div：** 在PD位置模式下，位置控制频率所需除以的特定数值，类型为float |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### set\_torque\_limit\_max(server\_ip, torque\_limit\_max)

该函数对应的python脚本demo为[`demo_set_torque_limit_max.py`](fourier_actuator_sdk_python_demo.md#demo_set_torque_limit_maxpy)

**函数说明：**

| 函数作用 | 设置执行器的最大扭矩 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**torque\_limit\_max：** 执行器的最大扭矩，类型为float |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### set\_inertia\_ff(server\_ip, inertia\_ff)

该函数对应的python脚本demo为[`demo_set_inertia_ff.py`](fourier_actuator_sdk_python_demo.md#demo_set_inertia_ffpy)

**函数说明：**

| 函数作用 | 设置执行器的惯量补偿 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**inertia\_ff：** 执行器的惯量补偿，类型为float |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### get\_ntc\_temperature(server\_ip)

该函数对应的python脚本demo为[`demo_get_ntc_temperature.py`](fourier_actuator_sdk_python_demo.md#demo_get_ntc_temperaturepy)

**函数说明：**

| 函数作用 | 获取执行器的绕组温度和mos温度 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 返回绕组温度和mos温度。类型为tuple，第一个是mos温度，第二个是绕组温度。 |

### set\_position\_control(server\_ip, position, velocity\_ff=0.0, current\_ff=0.0)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器在位置模式下的目标位置 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**position：**（必填）执行器的目标位置，类型为float<br>**velocity\_ff：**（选填）执行器的速度环前馈，类型为float，默认值为0.0<br>**current\_ff：**（选填）执行器的位置环前馈，类型为float，默认值为0.0 |
| 函数输出 | 设置成功，返回当前速度、位置、电流，设置失败，返回为None |

### set\_velocity\_control(server\_ip, velocity, current\_ff=0.0)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器在速度模式下的目标速度 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**velocity：**（必填）执行器的目标位置，类型为float<br>**current\_ff：**（选填）执行器的位置环前馈，类型为float，默认值为0.0 |
| 函数输出 | 设置成功，返回当前速度、位置、电流，设置失败，返回为None |

### set\_current\_control(server\_ip, current)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器在电流模式下的目标电流 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**current：**（必填）执行器的目标位置，类型为float |
| 函数输出 | 设置成功，返回当前速度、位置、电流，设置失败，返回为None |

### set\_torque\_control(server\_ip, torque)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器在力矩模式下的目标力矩 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**current：**（必填）执行器的目标位置，类型为float |
| 函数输出 | 设置成功，返回当前速度、位置、电流，设置失败，返回为None |

## fast接口

### fast\_set\_enable(server\_ip)

该函数对应的python脚本demo为[`demo_fast_set_enable.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_enablepy)

**函数说明：**

| 函数作用 | 设置执行器的使能 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_enable(server\_ip, cnt)

该函数对应的python脚本demo为[`demo_fast_set_ack_enable.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_enablepy)

**函数说明：**

| 函数作用 | 设置执行器的使能并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_disable(server\_ip)

该函数对应的python脚本demo为[`demo_fast_set_disable.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_disablepy)

**函数说明：**

| 函数作用 | 设置执行器的失能 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_disable(server\_ip, cnt)

该函数对应的python脚本demo为[`demo_fast_set_ack_disable.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_disablepy)

**函数说明：**

| 函数作用 | 设置执行器的失能并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表成功，超时返回None |

### fast\_set\_clear\_fault(server\_ip)

该函数对应的python脚本demo为[`demo_fast_set_clear_fault.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_clear_faultpy)

**函数说明：**

| 函数作用 | 清除执行器驱动端的错误码 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_clear\_fault(server\_ip, cnt)

该函数对应的python脚本demo为[`demo_fast_set_ack_clear_fault.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_clear_faultpy)

**函数说明：**

| 函数作用 | 清除执行器驱动端的错误码并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_position\_mode(server\_ip)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器为位置控制模式 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_position\_mode(server\_ip, cnt)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器为位置控制模式并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_velocity\_mode(server\_ip)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器为速度控制模式 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_velocity\_mode(server\_ip, cnt)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器为速度控制模式并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_torque\_mode(server\_ip)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器为力矩控制模式 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_torque\_mode(server\_ip, cnt)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器为力矩控制模式并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_current\_mode(server\_ip)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器为电流控制模式 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_current\_mode(server\_ip, cnt)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器为电流控制模式并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_pd\_mode(server\_ip)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器为pd控制模式 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_pd\_mode(server\_ip, cnt)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器为pd控制模式并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_mode\_of\_operation(server\_ip, mode\_of\_operation)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器的操作模式（位置、速度、电流、力矩、PD） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**mode\_of\_operation：** 执行器的操作模式，类型为int，具体有位置、速度、电流、力矩、PD可以选择 |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

| **mode\_of\_operation的模式** | 对应的int值 | FSAModeOfOperation类中对应的变量 |
| --- | --- | --- |
| 无模式 | 0 | NONE |
| 位置模式 | 1 | POSITION\_CONTROL |
| 速度模式 | 3 | VELOCITY\_CONTROL |
| 电流模式 | 4 | CURRENT\_CONTROL |
| 力矩模式 | 6 | TORQUE\_CONTROL |
| 位置pd模式 | 7 | POSITION\_CONTROL\_PD |

```python
#设置位置模式
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.NONE)
#设置位置模式
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL)
#设置速度模式
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.VELOCITY_CONTROL)
#设置电流模式
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.CURRENT_CONTROL)
#设置力矩模式
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.TORQUE_CONTROL)
#设置位置pd模式
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL_PD)
```

### fast\_set\_ack\_mode\_of\_operation(server\_ip, tx\_cnt, mode\_of\_operation)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器的操作模式（位置、速度、电流、力矩、PD）并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**tx\_cnt：** 用于异步通信的计数值<br>**mode\_of\_operation：** 执行器的操作模式，类型为int，具体有位置、速度、电流、力矩、PD可以选择 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

| **mode\_of\_operation的模式** | 对应的int值 | FSAModeOfOperation类中对应的变量 |
| --- | --- | --- |
| 无模式 | 0 | NONE |
| 位置模式 | 1 | POSITION\_CONTROL |
| 速度模式 | 3 | VELOCITY\_CONTROL |
| 电流模式 | 4 | CURRENT\_CONTROL |
| 力矩模式 | 6 | TORQUE\_CONTROL |
| 位置pd模式 | 7 | POSITION\_CONTROL\_PD |

```python
#设置位置模式
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.NONE)
#设置位置模式
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL)
#设置速度模式
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.VELOCITY_CONTROL)
#设置电流模式
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.CURRENT_CONTROL)
#设置力矩模式
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.TORQUE_CONTROL)
#设置位置pd模式
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL_PD)
```

### fast\_set\_position\_control(server\_ip, position, velocity\_ff=0, current\_ff=0)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器在位置模式下的目标位置 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**position：**（必填）执行器的目标位置，类型为float<br>**velocity\_ff：**（选填）执行器的速度环前馈，类型为float，默认值为0.0<br>**current\_ff：**（选填）执行器的位置环前馈，类型为float，默认值为0.0 |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_velocity\_control(server\_ip, velocity, current\_ff=0)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器在速度模式下的目标速度 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**velocity：**（必填）执行器的目标速度，类型为float<br>**current\_ff：**（选填）执行器的电流前馈，类型为float，默认值为0.0 |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_current\_control(server\_ip, current)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器在电流模式下的目标电流 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**current：**（必填）执行器的目标电流，类型为float |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_pd\_control(server\_ip, position, velocity\_ff=0, current\_ff=0)

该函数对应的python脚本demo为[`demo_fast_set_pd_position.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_pd_positionpy)

**函数说明：**

| 函数作用 | 设置执行器在位置模式下的目标位置 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**position：**（必填）执行器的目标位置，类型为float<br>**velocity\_ff：**（选填）执行器的速度环前馈，类型为float，默认值为0.0<br>**current\_ff：**（选填）执行器的位置环前馈，类型为float，默认值为0.0 |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_pd\_control(server\_ip, cnt, position, velocity\_ff=0, current\_ff=0)

该函数对应的python脚本demo为[`demo_fast_set_ack_pd_position.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_pd_positionpy)

**函数说明：**

| 函数作用 | 设置执行器在位置模式下的目标位置，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值<br>**position：**（必填）执行器的目标位置，类型为float<br>**velocity\_ff：**（选填）执行器的速度环前馈，类型为float，默认值为0.0<br>**current\_ff：**（选填）执行器的位置环前馈，类型为float，默认值为0.0 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_pid\_imm(server\_ip, position\_kp, velocity\_kp, velocity\_ki)

该函数对应的python脚本demo为[`demo_fast_set_pid_imm.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_pid_immpy)

**函数说明：**

| 函数作用 | 设置执行器临时pid参数 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**position\_kp：** 执行器三环控制位置环kp，类型为float<br>**velocity\_kp：** 执行器三环控制速度环kp，类型为float<br>**velocity\_ki：** 执行器三环控制速度环ki，类型为float |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_pid\_imm(server\_ip, cnt, position\_kp, velocity\_kp, velocity\_ki)

该函数对应的python脚本demo为[`demo_fast_set_ack_pid_imm.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_pid_immpy)

**函数说明：**

| 函数作用 | 设置执行器临时pid参数，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值<br>**position\_kp：** 执行器三环控制位置环kp，类型为float<br>**velocity\_kp：** 执行器三环控制速度环kp，类型为float<br>**velocity\_ki：** 执行器三环控制速度环ki，类型为float |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_pd\_imm(server\_ip, kp, kd)

该函数对应的python脚本demo为[`demo_fast_set_pd_imm.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_pd_immpy)

**函数说明：**

| 函数作用 | 设置执行器临时pd参数 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**kp：** 执行器PD控制位置环kp，类型为float<br>**kd：** 执行器PD控制速度环kd，类型为float |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_pd\_imm(server\_ip, cnt, kp, kd)

该函数对应的python脚本demo为[`demo_fast_set_ack_pd_imm.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_pd_immpy)

**函数说明：**

| 函数作用 | 设置执行器临时pd参数，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值<br>**kp：** 执行器PD控制位置环kp，类型为float<br>**kd：** 执行器PD控制速度环kd，类型为float |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_control\_loop\_freq\_div(server\_ip, position\_loop\_freq\_div, velocity\_loop\_freq\_div, PD\_loop\_freq\_div)

该函数对应的python脚本demo为[`demo_fast_set_control_loop_freq_div.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_control_loop_freq_divpy)

**函数说明：**

| 函数作用 | 设置执行器环路控制分频系数 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**position\_loop\_freq\_div：** 位置环控制频率分频系数，类型为float<br>**velocity\_loop\_freq\_div：** 速度环控制频率分频系数，类型为float<br>**PD\_loop\_freq\_div：** PD控制频率分频系数，类型为float |
| 函数输出 | 成功输出收到的udp报文，失败输出None |

### fast\_set\_ack\_control\_loop\_freq\_div(server\_ip, cnt, position\_loop\_freq\_div, velocity\_loop\_freq\_div, PD\_loop\_freq\_div)

该函数对应的python脚本demo为[`demo_fast_set_ack_control_loop_freq_div.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_control_loop_freq_divpy)

**函数说明：**

| 函数作用 | 设置执行器环路控制分频系数，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值<br>**position\_loop\_freq\_div：** 位置环控制频率分频系数，类型为float<br>**velocity\_loop\_freq\_div：** 速度环控制频率分频系数，类型为float<br>**PD\_loop\_freq\_div：** PD控制频率分频系数，类型为float |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_friction\_FFD(server\_ip, SET, DeadSpeedK, DeadSpeed, Fs, Fc, B, percent):

该函数对应的python脚本demo为[`demo_fast_set_friction_FFD.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_friction_ffdpy) 

**函数说明：**

| 函数作用 | 设置执行器摩擦补偿 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**SET：** 是否开启摩擦补偿，类型为uint32<br>**DeadSpeedK：** 死区斜率，类型为float<br>**DeadSpeed：** 死区速度，类型为float<br>**Fs：** 静摩擦力，类型为float<br>**Fc：** 库伦摩擦力，类型为float<br>**B：** 粘滞摩擦系数，类型为float<br>**percent：** 生效倍数，范围0~2，类型为float |
| 函数输出 | 成功输出收到的udp报文，失败输出None |

### fast\_set\_ack\_friction\_FFD(server\_ip, cnt, SET, DeadSpeedK, DeadSpeed, Fs, Fc, B, percent)

该函数对应的python脚本demo为[`demo_fast_set_ack_friction_FFD.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_friction_ffdpy) 

**函数说明：**

| 函数作用 | 设置执行器摩擦补偿，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值<br>**SET：** 是否开启摩擦补偿，类型为uint32<br>**DeadSpeedK：** 死区斜率，类型为float<br>**DeadSpeed：** 死区速度，类型为float<br>**Fs：** 静摩擦力，类型为float<br>**Fc：** 库伦摩擦力，类型为float<br>**B：** 粘滞摩擦系数，类型为float<br>**percent：** 生效倍数，范围0~2，类型为float |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_ack\_setpvc\_timeout\_protect(server\_ip, cnt, protect\_enable, timeout\_ms, protect\_mode\_of\_operation, close\_back\_last\_mode\_of\_operation, ignore\_set\_mode\_of\_operation)

该函数对应的python脚本demo为[`demo_fast_set_ack_setpvc_timeout_protect.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_setpvc_timeout_protectpy) 

**函数说明：**

| 函数作用 | 设置执行器setpvc超时保护，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值<br>**protect\_enable：** 是否开启setpvc超时保护，0关闭，1开启，类型为uint32<br>**timeout\_ms：** 超时时间，单位毫秒，类型为uint32<br>**protect\_mode\_of\_operation：** 设置进入保护状态时使用三环位置控制还是PD控制，可选FSAModeOfOperation.POSITION\_CONTROL，FSAModeOfOperation.POSITION\_CONTROL\_PD，类型为uint32<br>**close\_back\_last\_mode\_of\_operation：** 如果关闭该功能时正在保护状态，是否恢复到进入保护状态前的操作模式，0: 不恢复, 1: 恢复，类型为uint32<br>**ignore\_set\_mode\_of\_operation：** 进入保护模式后是否禁止修改mode\_of\_operation，0: 不禁止, 1: 禁止，类型为uint32 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_ack\_interface\_filter\_fc(server\_ip, cnt, position, velocity, current)

该函数对应的python脚本demo为[`demo_fast_set_ack_interface_filter_fc.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_interface_filter_fcpy) 

**函数说明：**

| 函数作用 | 设置执行器反馈pvc的滤波截止频率，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值<br>**position：** 设置位置反馈滤波截止频率，类型为float<br>**velocity：** 设置速度反馈滤波截止频率，类型为float<br>**current：** 设置电流、力矩反馈滤波截止频率，类型为float |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_ack\_setpvc\_protect\_clear(server\_ip, cnt, clear\_back\_last\_mode\_of\_operation)

该函数对应的python脚本demo为[`demo_fast_set_ack_setpvc_protect_clear.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_setpvc_protect_clearpy) 

**函数说明：**

| 函数作用 | 设置执行器setpvc保护状态清除，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：** 用于异步通信的计数值<br>**close\_back\_last\_mode\_of\_operation：** 清除保护状态时是否恢复到进入保护状态前的操作模式，0: 不恢复, 1: 恢复，类型为uint32 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_get\_pvc(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_pvc.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_pvcpy) 

**函数说明：**

| 函数作用 | 获取执行器当前的位置、速度、电流的信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器位置，速度，电流信息，失败输出None |

### fast\_get\_foc\_target\_pvc(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_foc_target_pvc.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_foc_target_pvcpy) 

**函数说明：**

| 函数作用 | 获取执行器底层FOC的目标的位置、速度、电流信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 成功输出底层FOC的目标的位置、速度、电流信息，失败输出None |

### fast\_get\_pvct(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_pvct.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_pvctpy) 

**函数说明：**

| 函数作用 | 获取执行器当前的位置、速度、电流、力矩信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器当前的位置、速度、电流、力矩信息，失败输出None |

### fast\_get\_error(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_error.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_errorpy) 

**函数说明：**

| 函数作用 | 获取执行器错误码 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器错误码，失败输出None |

### fast\_get\_pvct\_error(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_pvct_error.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_pvct_errorpy) 

**函数说明：**

| 函数作用 | 获取执行器位置、速度、电流、力矩，错误码 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器位置、速度、电流、力矩，错误码，失败输出None |

### fast\_get\_friction\_FFD(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_friction_FFD.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_friction_ffdpy) 

**函数说明：**

| 函数作用 | 获取执行器摩擦补偿参数 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 成功输出是否开启摩擦补偿，死区斜率，死区速度，静摩擦力，库伦摩擦力，粘滞摩擦系数，生效倍数，失败输出None |

### fast\_get\_ntc\_temp(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_ntc_temp.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_ntc_temppy) 

**函数说明：**

| 函数作用 | 获取执行器MOS，绕组温度 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器MOS，绕组温度，失败输出None |

### fast\_get\_vbus(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_vbus.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_vbuspy) 

**函数说明：**

| 函数作用 | 获取执行器母线电压 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器母线电压，失败输出None |

## subscribe接口

该接口对应的python脚本的函数为[`set_subscribe(server_ip, cfg_dict)`](#set_subscribe)


