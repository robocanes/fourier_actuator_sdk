# 执行器python脚本接口和例程文档

# 文档说明

数据单位说明：

| 数据类型 | 单位 |
| --- | --- |
| 位置 | 度（角度制） |
| 速度 | 度/秒（角度制） |
| 电流 | A |
| 力矩 | N·m |

python脚本仓库：[https://gitee.com/FourierIntelligence/wiki-fsa.git](https://gitee.com/FourierIntelligence/wiki-fsa.git)

# 接口函数说明

## comm接口

### get\_comm\_root(server\_ip)

该函数对应的python脚本demo为[`demo_lookup.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2u4qee7669v0uwn9t5)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器的基本属性 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 对应执行器的所有基本属性，包括序列号、网络配置等，类型为dict。 |

### get\_comm\_driver\_version(server\_ip)

该函数对应的python脚本demo为[`demo_comm_driver_firmware_version_get.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2v8ystkrgjxe6rtixj)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器的驱动固件版本 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 对应执行器的驱动固件版本，类型为str。 |

### get\_comm\_firmware\_version(server\_ip)

该函数对应的python脚本demo为[`demo_comm_driver_firmware_version_get.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2v8ystkrgjxe6rtixj)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器的通信固件版本 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 对应执行器的通信固件版本，类型为str。 |

### get\_comm\_config(server\_ip)

该函数对应的python脚本demo为[`get_comm_config_get.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2v9jlckd1f8g1nfe7)（双击可跳转）

| 函数作用 | 获取执行器的config属性（会在终端打印执行器的config属性） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_comm\_config(server\_ip, dict)

该函数对应的python脚本demo为[`demo_comm_config_set.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vb89cedj4a1s2h3ph)（双击可跳转）

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

### set\_subscribe(server\_ip, cfg\_dict)

该函数对应的python脚本demo为[`demo_set_subscribe.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vibmvkk9o0yb0v57j)（双击可跳转）

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

该函数对应的python脚本demo为[`demo_ota.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vjcuvma9muqqld8b)（双击可跳转）

| 函数作用 | 对执行器进行通信ota升级，升级版本为生产版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 无返回值 |

### ota\_test(server\_ip)

该函数对应的python脚本demo为[`demo_ota_text.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vjdcpbhown7e6x806)（双击可跳转）

| 函数作用 | 对执行器进行通信ota升级，升级版本为测试版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 无返回值 |

### ota\_devel(server\_ip)

该函数对应的python脚本demo为[`demo_ota_devel.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vjen6lfittvfnqkv)（双击可跳转）

| 函数作用 | 对执行器进行通信ota升级，升级版本为开发版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 无返回值 |

### ota\_cloud(server\_ip)

该函数对应的python脚本demo为[`demo_ota_cloud.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vjdyhq7qdtjbtoit)（双击可跳转）

| 函数作用 | 对执行器进行通信ota升级，升级版本为云端版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 无返回值 |

### ota\_custom(server\_ip, version\_str)

该函数对应的python脚本demo为[`demo_ota_custom.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vjeb2elk4prflixk)（双击可跳转）

| 函数作用 | 对执行器进行通信ota升级，升级版本为自定义版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str<br>**version\_str：** 升级的版本号，类型为str |
| 函数输出 | 无返回值 |

### ota\_driver(server\_ip)

该函数对应的python脚本demo为[`demo_ota_driver.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vkejaigh78klvyiw)

| 函数作用 | 对执行器进行驱动ota升级，升级版本为生产版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str |
| 函数输出 | 无返回值 |

### ota\_driver\_test(server\_ip)

该函数对应的python脚本demo为[`demo_ota_driver_test.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vkevwy4jg1oeh6wmm)

| 函数作用 | 对执行器进行驱动ota升级，升级版本为测试版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str |
| 函数输出 | 无返回值 |

### ota\_driver\_devel(server\_ip)

该函数对应的python脚本demo为[`demo_ota_driver_devel.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vkf7q9qybt4eqrle)

| 函数作用 | 对执行器进行驱动ota升级，升级版本为开发版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str |
| 函数输出 | 无返回值 |

### ota\_driver\_cloud(server\_ip)

该函数对应的python脚本demo为[`demo_ota_driver_cloud.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vkfpf4j02qpbivof)

| 函数作用 | 对执行器进行驱动ota升级，升级版本为云端版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str |
| 函数输出 | 无返回值 |

### ota\_driver\_custom(server\_ip ,version\_str)

该函数对应的python脚本demo为[`demo_ota_driver_custom.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2vkfxfjlj2h65jmtos)

| 函数作用 | 对执行器进行驱动ota升级，升级版本为自定义版。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip 执行器,类型为str<br>**version\_str：** 升级的版本号，类型为str |
| 函数输出 | 无返回值 |

## ctrl接口

### set\_enable(server\_ip)

该函数对应的python脚本demo为[`demo_enable_set.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2wrmoj64i7pbise853)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的使能 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_disable(server\_ip)

该函数对应的python脚本demo为[`demo_enable_set.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2wucgoxh6o7x0bj1i6)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的失能 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### clear\_fault(server\_ip)

该函数对应的python脚本demo为[demo\_clear\_fault.py](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m3e3w573l53rlewlgf)（双击可跳转）

**函数说明：**

| 函数作用 | 清空执行器的错误码 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_calibrate\_encoder(server\_ip)

该函数对应的python脚本demo为[`demo_set_calibrate_encoder.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2wybvalrv343vcvm8q)（双击可跳转）（注意：校准过程中，执行器会转动，建议要把执行器固定好再校准）

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

该函数对应的python脚本demo为（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的操作模式（位置、速度、电流、力矩） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**mode\_of\_operation：**执行器的操作模式，类型为int，具体有位置、速度、电流、力矩可以选择 |
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

该函数对应的python脚本demo为[`demo_pid_param_get.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zl8hin91rjobopvv)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器的pid参数（注意：该pid参数需要重启后才能生效） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_pid\_param(server\_ip, dict)

该函数对应的python脚本demo为[`demo_pid_param_set.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zmdt5rbgyn9bcmt2s)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的pid参数（注意：该pid参数需要重启后才能生效） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict：**pid参数,类型为dict |
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

该函数对应的python脚本demo为[`demo_pid_param_imm_get.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zq0xppomslpymxaa)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器的pid（临时）参数（注意：该pid参数立即生效，但是断电后不会保存该参数） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_pid\_param\_imm(server\_ip, dict)

该函数对应的python脚本demo为[`demo_pid_param_imm_set.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zq6zpuoe3jmj9sun)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的pid（临时）参数（注意：该pid参数立即生效，但是断电后不会保存该参数） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict：**pid参数,类型为dict |
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

该函数对应的python脚本demo为[`demo_control_param_get.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zrte09qejdyrwz8ya)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器的控制参数（注意：该控制参数需要重启后才能生效） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_control\_param(server\_ip, dict)该函数暂时不能用

该函数对应的python脚本demo为[`demo_control_param_set.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zryh1jwvr96dj699)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的控制参数（注意：该控制参数需要重启后才能生效） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict：**控制参数,类型为dict |
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

### get\_control\_param\_imm(server\_ip)

该函数对应的python脚本demo为[`demo_control_param_imm_get.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zsviv6xqz66gv9sm)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器的临时控制参数（注意：该pid参数立即生效，但是断电后不会保存该参数） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_control\_param\_imm(server\_ip, dict) 该函数暂时用不了

该函数对应的python脚本demo为[`demo_control_param_imm_set.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zsviw0dymuyzbwcr)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的临时控制参数（注意：该pid参数立即生效，但是断电后不会保存该参数） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict：**控制参数,类型为dict |
| 函数输出 | 是否设置成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

| 控制参数具体配置 | 含义 | 类型 |
| --- | --- | --- |
| motor\_max\_speed\_imm | 执行器的最大速度（临时生效，断电消失） | int |
| motor\_max\_acceleration\_imm | 执行器的最大加速度（临时生效，断电消失） | int |
| motor\_max\_current\_imm | 执行器的最大电流（临时生效，断电消失） | int |

```python
            dict = {
                "motor_max_speed_imm": 3000,
                "motor_max_acceleration_imm": 60000,
                "motor_max_current_imm": 8,
            }
```

### get\_flag\_of\_operation(server\_ip)

该函数对应的python脚本demo为[`demo_flag_of_operation_get.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zsuz3pv9v6jhieh19)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器的操作标识 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_flag\_of\_operation(server\_ip, dict\_cfg)

该函数对应的python脚本demo为[`demo_flag_of_operation_set.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zukgqezoukjntojo)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的操作标识 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict\_cfg****：**操作标识,类型为dict |
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

该函数对应的python脚本demo为[`demo_ctrl_config_get.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zsuzjkg54ip9jlqfd)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器的配置信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否获取成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### set\_config(server\_ip, dict)

该函数对应的python脚本demo为[`demo_ctrl_config_set.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m32dmme1jyntdvnnyef)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的配置信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**dict：**执行器的配置信息，类型为dict |
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

该函数对应的python脚本demo为[`demo_reboot.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zuejlnc4f5kwh0fh)（双击可跳转）

**函数说明：**

| 函数作用 | 重启执行器 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 是否重启成功，成功返回FSAFunctionResult.SUCCESS，失败返回None。 |

### get\_error\_code(server\_ip)

该函数对应的python脚本demo为[`demo_get_error.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m32etll4j08fmoapl69)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器的错误码 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 具体的错误码，返回类型为int或者list或者None。获取失败返回None,错误码为一个时，返回值类型为int,错误码为多个时，返回值类型为list。 |

### get\_pvc(server\_ip)

该函数对应的python脚本demo为[`demo_get_pvc.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zuejre0nj7h00mcdzn)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器当前的位置、速度、电流的信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 具体的位置、速度、电流的信息，返回类型为tuple,返回值按顺序为位置、速度、电流。 |

### get\_foc\_target\_PVC(server\_ip)

该函数对应的python脚本demo为[`demo_get_foc_target_PVC.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m32fjg89kpyze8zyual)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器FOC执行的目标位置、目标速度、目标电流的信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 具体FOC执行的目标位置、目标速度、目标电流的信息，返回类型为tuple,返回值按顺序为位置、速度、电流。 |

### get\_pvct(server\_ip)

该函数对应的python脚本demo为[`demo_get_pvct.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m32fjgdl1lfqlv5e3yy)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器当前的位置、速度、电流、力矩的信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 具体FOC执行的位置、速度、电流、力矩的信息，返回类型为tuple,返回值按顺序为位置、速度、电流、力矩。 |

### get\_fsa\_abs\_position(server\_ip) 

该函数对应的python脚本demo为[`demo_get_fsa_abs_position.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m32gugevm5ygbgueevr)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器绝对编码器的位置信息 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 绝对编码器的位置信息,类型为float。 |

### set\_fsa\_abs\_zero(server\_ip)

该函数对应的python脚本demo为[`demo_set_fsa_abs_zero.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m32gugixn4uetvc801)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的绝对编码器的零点，以此刻的位置为零点。 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### set\_eth\_recovery(server\_ip)

该函数对应的python脚本demo为[`demo_set_eth_recovery.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m32gugrt7jge15c2dqg)（双击可跳转）

**函数说明：**

| 函数作用 | 恢复执行器的网络 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### set\_eth\_timeout\_protect(server\_ip, is\_enable, timeout\_interval)低版本不能用

该函数对应的python脚本demo为[`demo_set_eth_timeout_protect.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zuekdsw64nka6w438)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器网络的超时保护 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**is\_enable：**是否启用网络的超时保护，类型为int，0为不启用，1为启用<br>**timeout\_interval：**超时检测时间，单位毫秒，类型为int |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### set\_control\_loop\_freq\_div(server\_ip, position\_loop\_freq\_div, velocity\_loop\_freq\_div, PD\_loop\_freq\_div)低版本不能用

该函数对应的python脚本demo为[`demo_set_control_loop_freq_div.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m359l80dl9eh2094cg)（双击可跳转）

**函数说明：**

| 函数作用 | 将执行器的控制频率除于一个特定数值，以做到修改实际控制频率的作用 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**position\_loop\_freq\_div：**在位置模式下，位置控制频率所需除以的特定数值，类型为float<br>**velocity\_loop\_freq\_div：**在速度模式下，速度控制频率所需除以的特定数值，类型为float<br>**PD\_loop\_freq\_div：**在PD位置模式下，位置控制频率所需除以的特定数值，类型为float |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### set\_torque\_limit\_max(server\_ip, torque\_limit\_max)

该函数对应的python脚本demo为[`demo_set_torque_limit_max.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m35a5i2uayw9nouwe)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的最大扭矩 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**torque\_limit\_max：**执行器的最大扭矩，类型为float |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### set\_inertia\_ff(server\_ip, inertia\_ff)

该函数对应的python脚本demo为[`demo_set_inertia_ff.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m35a9yp1by0z49piske)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的惯量补偿 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**inertia\_ff：**执行器的惯量补偿，类型为float |
| 函数输出 | 设置成功返回True，失败则返回错误码。 |

### get\_ntc\_temperature(server\_ip)

该函数对应的python脚本demo为[`demo_get_ntc_temperature.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m32m5olejlibhaazgmn)（双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器的绕组温度和mos温度 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | 返回绕组温度和mos温度。类型为tuple，第一个是mos温度，第二个是绕组温度。 |

### set\_position\_control(server\_ip, position, velocity\_ff=0.0, current\_ff=0.0)

该函数对应的python脚本demo为（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器在位置模式下的目标位置 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**position：**（必填）执行器的目标位置，类型为float<br>**velocity\_ff：**（选填）执行器的速度环前馈，类型为float，默认值为0.0<br>**current\_ff：**（选填）执行器的位置环前馈，类型为float，默认值为0.0 |
| 函数输出 | 设置成功，返回当前速度、位置、电流，设置失败，返回为None |

### set\_velocity\_control(server\_ip, velocity, current\_ff=0.0)

该函数对应的python脚本demo为（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器在速度模式下的目标速度 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**velocity：**（必填）执行器的目标位置，类型为float<br>**current\_ff：**（选填）执行器的位置环前馈，类型为float，默认值为0.0 |
| 函数输出 | 设置成功，返回当前速度、位置、电流，设置失败，返回为None |

### set\_current\_control(server\_ip, current)

该函数对应的python脚本demo为（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器在电流模式下的目标电流 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**current：**（必填）执行器的目标位置，类型为float |
| 函数输出 | 设置成功，返回当前速度、位置、电流，设置失败，返回为None |

### set\_torque\_control(server\_ip, torque)

该函数对应的python脚本demo为（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器在力矩模式下的目标力矩 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**current：**（必填）执行器的目标位置，类型为float |
| 函数输出 | 设置成功，返回当前速度、位置、电流，设置失败，返回为None |

## fast接口

### fast\_set\_enable(server\_ip)

该函数对应的python脚本demo为[`demo_fast_set_enable.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zt1tvnpf42bjs9cu)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的使能 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_enable(server\_ip, cnt)

该函数对应的python脚本demo为[`demo_fast_set_ack_enable.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m4e28imqb9ceyqjk5b)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的使能并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_disable(server\_ip)

该函数对应的python脚本demo为[`demo_fast_set_disable.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zugs4zwhuy4actqw)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的失能 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_disable(server\_ip, cnt)

该函数对应的python脚本demo为[`demo_fast_set_ack_disable.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m4e2cc6qxetiw87qo0m)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器的失能并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表成功，超时返回None |

### fast\_set\_clear\_fault(server\_ip)

该函数对应的python脚本demo为[`demo_fast_set_clear_fault.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2zw2h6un4hcb5mk42)（双击可跳转）

**函数说明：**

| 函数作用 | 清除执行器驱动端的错误码 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_clear\_fault(server\_ip, cnt)

该函数对应的python脚本demo为[`demo_fast_set_ack_clear_fault.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m4e2eck5cilz3s5vhob)（双击可跳转）

**函数说明：**

| 函数作用 | 清除执行器驱动端的错误码并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值 |
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
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值 |
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
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值 |
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
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值 |
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
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值 |
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
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_mode\_of\_operation(server\_ip, mode\_of\_operation)

该函数无对应的python脚本。

**函数说明：**

| 函数作用 | 设置执行器的操作模式（位置、速度、电流、力矩、PD） |
| --- | --- |
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**mode\_of\_operation：**执行器的操作模式，类型为int，具体有位置、速度、电流、力矩、PD可以选择 |
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
| 函数输入 | **server\_ip：** 执行器的ip ,类型为str<br>**tx\_cnt：**用于异步通信的计数值<br>**mode\_of\_operation：**执行器的操作模式，类型为int，具体有位置、速度、电流、力矩、PD可以选择 |
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

该函数对应的python脚本demo为[`demo_fast_set_pd_position.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m3k4ugf9ylyltkd1yee)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器在位置模式下的目标位置 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**position：**（必填）执行器的目标位置，类型为float<br>**velocity\_ff：**（选填）执行器的速度环前馈，类型为float，默认值为0.0<br>**current\_ff：**（选填）执行器的位置环前馈，类型为float，默认值为0.0 |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_pd\_control(server\_ip, cnt, position, velocity\_ff=0, current\_ff=0)

该函数对应的python脚本demo为[`demo_fast_set_ack_pd_position.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m5834oe76763pxplb93)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器在位置模式下的目标位置，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：**（必填） 执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值<br>**position：**（必填）执行器的目标位置，类型为float<br>**velocity\_ff：**（选填）执行器的速度环前馈，类型为float，默认值为0.0<br>**current\_ff：**（选填）执行器的位置环前馈，类型为float，默认值为0.0 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_pid\_imm(server\_ip, position\_kp, velocity\_kp, velocity\_ki)

该函数对应的python脚本demo为[`demo_fast_set_pid_imm.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m3k68rpkrr29ygpvuoa)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器临时pid参数 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str<br>**position\_kp：**执行器三环控制位置环kp，类型为float<br>**velocity\_kp：**执行器三环控制速度环kp，类型为float<br>**velocity\_ki：**执行器三环控制速度环ki，类型为float |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_pid\_imm(server\_ip, cnt, position\_kp, velocity\_kp, velocity\_ki)

该函数对应的python脚本demo为[`demo_fast_set_ack_pid_imm.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m583owtu7c3zkfv39m5)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器临时pid参数，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值<br>**position\_kp：**执行器三环控制位置环kp，类型为float<br>**velocity\_kp：**执行器三环控制速度环kp，类型为float<br>**velocity\_ki：**执行器三环控制速度环ki，类型为float |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_pd\_imm(server\_ip, kp, kd)

该函数对应的python脚本demo为[`demo_fast_set_pd_imm.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m3k75rvdkt40li9a2q)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器临时pd参数 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str<br>**kp：**执行器PD控制位置环kp，类型为float<br>**kd：**执行器PD控制速度环kd，类型为float |
| 函数输出 | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_pd\_imm(server\_ip, cnt, kp, kd)

该函数对应的python脚本demo为[`demo_fast_set_ack_pd_imm.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m584sw6r6cuyf7h3b9m)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器临时pd参数，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值<br>**kp：**执行器PD控制位置环kp，类型为float<br>**kd：**执行器PD控制速度环kd，类型为float |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_control\_loop\_freq\_div(server\_ip, position\_loop\_freq\_div, velocity\_loop\_freq\_div, PD\_loop\_freq\_div)

该函数对应的python脚本demo为[`demo_fast_set_control_loop_freq_div.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m3k81keldlhrrfutf1o)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器环路控制分频系数 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str<br>**position\_loop\_freq\_div：**位置环控制频率分频系数，类型为float<br>**velocity\_loop\_freq\_div：**速度环控制频率分频系数，类型为float<br>**PD\_loop\_freq\_div：**PD控制频率分频系数，类型为float |
| 函数输出 | 成功输出收到的udp报文，失败输出None |

### fast\_set\_ack\_control\_loop\_freq\_div(server\_ip, cnt, position\_loop\_freq\_div, velocity\_loop\_freq\_div, PD\_loop\_freq\_div)

该函数对应的python脚本demo为[`demo_fast_set_ack_control_loop_freq_div.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m5851hq1jp7fh5dn78h)（双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器环路控制分频系数，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值<br>**position\_loop\_freq\_div：**位置环控制频率分频系数，类型为float<br>**velocity\_loop\_freq\_div：**速度环控制频率分频系数，类型为float<br>**PD\_loop\_freq\_div：**PD控制频率分频系数，类型为float |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_friction\_FFD(server\_ip, SET, DeadSpeedK, DeadSpeed, Fs, Fc, B, percent):

该函数对应的python脚本demo为[`demo_fast_set_friction_FFD.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m3k8dj1p92xiu5tfjtg) （双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器摩擦补偿 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str<br>**SET：**是否开启摩擦补偿，类型为uint32<br>**DeadSpeedK：**死区斜率，类型为float<br>**DeadSpeed：**死区速度，类型为float<br>**Fs：**静摩擦力，类型为float<br>**Fc：**库伦摩擦力，类型为float<br>**B：**粘滞摩擦系数，类型为float<br>**percent：**生效倍数，范围0~2，类型为float |
| 函数输出 | 成功输出收到的udp报文，失败输出None |

### fast\_set\_ack\_friction\_FFD(server\_ip, cnt, SET, DeadSpeedK, DeadSpeed, Fs, Fc, B, percent)

该函数对应的python脚本demo为[`demo_fast_set_ack_friction_FFD.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m585go9knikc4ncwd9e) （双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器摩擦补偿，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值<br>**SET：**是否开启摩擦补偿，类型为uint32<br>**DeadSpeedK：**死区斜率，类型为float<br>**DeadSpeed：**死区速度，类型为float<br>**Fs：**静摩擦力，类型为float<br>**Fc：**库伦摩擦力，类型为float<br>**B：**粘滞摩擦系数，类型为float<br>**percent：**生效倍数，范围0~2，类型为float |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_ack\_setpvc\_timeout\_protect(server\_ip, cnt, protect\_enable, timeout\_ms, protect\_mode\_of\_operation, close\_back\_last\_mode\_of\_operation, ignore\_set\_mode\_of\_operation)

该函数对应的python脚本demo为[`demo_fast_set_ack_setpvc_timeout_protect.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m5adw54btjtv5gjs13) （双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器setpvc超时保护，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值<br>**protect\_enable：**是否开启setpvc超时保护，0关闭，1开启，类型为uint32<br>**timeout\_ms：**超时时间，单位毫秒，类型为uint32<br>**protect\_mode\_of\_operation：**设置进入保护状态时使用三环位置控制还是PD控制，可选FSAModeOfOperation.POSITION\_CONTROL，FSAModeOfOperation.POSITION\_CONTROL\_PD，类型为uint32<br>**close\_back\_last\_mode\_of\_operation：**如果关闭该功能时正在保护状态，是否恢复到进入保护状态前的操作模式，0: 不恢复, 1: 恢复，类型为uint32<br>**ignore\_set\_mode\_of\_operation：**进入保护模式后是否禁止修改mode\_of\_operation，0: 不禁止, 1: 禁止，类型为uint32 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_ack\_interface\_filter\_fc(server\_ip, cnt, position, velocity, current)

该函数对应的python脚本demo为[`demo_fast_set_ack_interface_filter_fc.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m5ahqdm3rzgiimxf9q) （双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器反馈pvc的滤波截止频率，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值<br>**position：**设置位置反馈滤波截止频率，类型为float<br>**velocity：**设置速度反馈滤波截止频率，类型为float<br>**current：**设置电流、力矩反馈滤波截止频率，类型为float |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_set\_ack\_setpvc\_protect\_clear(server\_ip, cnt, clear\_back\_last\_mode\_of\_operation)

该函数对应的python脚本demo为[`demo_fast_set_ack_setpvc_protect_clear.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m5alb7aul6etu2fj3vg) （双击可跳转）

**函数说明：**

| 函数作用 | 设置执行器setpvc保护状态清除，并返回cnt计数值和执行结果 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str<br>**cnt：**用于异步通信的计数值<br>**close\_back\_last\_mode\_of\_operation：**清除保护状态时是否恢复到进入保护状态前的操作模式，0: 不恢复, 1: 恢复，类型为uint32 |
| 函数输出 | 未超时返回cnt计数值和res执行结果，res为0代表使能成功，超时返回None |

### fast\_get\_pvc(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_pvc.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m3mml4a0nfrah3thpuk) （双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器当前的位置、速度、电流的信息 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器位置，速度，电流信息，失败输出None |

### fast\_get\_foc\_target\_pvc(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_foc_target_pvc.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m3mndbnrt8tettxbs0m) （双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器底层FOC的目标的位置、速度、电流信息 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str |
| 函数输出 | 成功输出底层FOC的目标的位置、速度、电流信息，失败输出None |

### fast\_get\_pvct(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_pvct.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m3mnohmezz3dsq487mp) （双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器当前的位置、速度、电流、力矩信息 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器当前的位置、速度、电流、力矩信息，失败输出None |

### fast\_get\_error(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_error.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m3mnxt21rf1wsqs3tz) （双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器错误码 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器错误码，失败输出None |

### fast\_get\_pvct\_error(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_pvct_error.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m5amlkf54f09xz0t584) （双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器位置、速度、电流、力矩，错误码 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器位置、速度、电流、力矩，错误码，失败输出None |

### fast\_get\_friction\_FFD(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_friction_FFD.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m5amlsgmw6zr49k0b4p) （双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器摩擦补偿参数 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str |
| 函数输出 | 成功输出是否开启摩擦补偿，死区斜率，死区速度，静摩擦力，库伦摩擦力，粘滞摩擦系数，生效倍数，失败输出None |

### fast\_get\_ntc\_temp(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_ntc_temp.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m5amlt961sqcn0h1c0qi) （双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器MOS，绕组温度 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器MOS，绕组温度，失败输出None |

### fast\_get\_vbus(server\_ip)

该函数对应的python脚本demo为[`demo_fast_get_vbus.py`](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m5amltqlm6tudrd6cb) （双击可跳转）

**函数说明：**

| 函数作用 | 获取执行器母线电压 |
| --- | --- |
| 函数输入 | **server\_ip：**执行器的ip ,类型为str |
| 函数输出 | 成功输出执行器母线电压，失败输出None |

## subscribe接口

详见

[《执行器python脚本接口和例程文档》](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2u09m4gifpbsosubym)

# demo例程说明

## demo\_lookup.py

**代码****说明：**

该脚本主要用于演示如何获取执行器的基本属性。

该脚本执行以下操作：`demo_lookup.py`

1.  使用`broadcast_func`函数，发现网络上的全部傅利叶自研设备。
    
2.  使用`get_comm_root`函数，检索每个检测到的傅利叶自研设备的基本属性。
    
3.  将最后一个傅利叶自研设备的基本属性显示在终端中。
    

**用法：**

要运行该脚本，请执行以下步骤：`demo_lookup.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  连接到 FSA执行器。
    
3.  打开终端并导航到包含 的目录。`demo_lookup.py`
    
4.  使用以下命令运行脚本：
    
    ```python
    python demo_lookup.py
    ```
    
5.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```plaintext
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_lookup.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.30 09:24:53.652.378]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.30 09:24:53.654.011]  Info:    FSA start listening for broadcast...
[2024.10.30 09:24:53.654.051]  Info:    FSA start listening for broadcast...


[2024.10.30 09:24:53.657.026]  Info:    Received from ('192.168.137.51', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.51","IP":"192.168.137.51"}


found servers
['192.168.137.51']
lookup Finished! 

[2024.10.30 09:24:56.658.454]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.10.30 09:24:56.661.219]  Info:    Received from ('192.168.137.51', 2334):{"status":"OK","reqTarget":"/","property":"","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.51","IP":"192.168.137.51","DHCP_enable":false,"SSID":"FSA","password":"fftai2015","static_IP":[192,168,137,51],"gateway":[192,168,137,1],"subnet_mask":[255,255,255,0],"dns_1":[114,114,114,114],"dns_2":[8,8,8,8],"OTAstatus":"HTTP_UPDATE_IDLE","OTADriverstatus":"HTTP_UPDATE_DRIVER_IDLE"}
The communication root is:  {'status': 'OK', 'reqTarget': '/', 'property': '', 'type': 'Actuator', 'model': '', 'name': 'FSA-0', 'serial_number': 'A4D32BE0F908', 'driver_version': '0.2.8.35', 'firmware_version': '0.3.9.9', 'connect_mode': 'ETH', 'mac_address': '08:F9:E0:2B:D3:A7', 'ip_address': '192.168.137.51', 'IP': '192.168.137.51', 'DHCP_enable': False, 'SSID': 'FSA', 'password': 'fftai2015', 'static_IP': [192, 168, 137, 51], 'gateway': [192, 168, 137, 1], 'subnet_mask': [255, 255, 255, 0], 'dns_1': [114, 114, 114, 114], 'dns_2': [8, 8, 8, 8], 'OTAstatus': 'HTTP_UPDATE_IDLE', 'OTADriverstatus': 'HTTP_UPDATE_DRIVER_IDLE'}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
3.  检查执行器是否有任何需要清除的现有故障。
    
    ## demo\_comm\_driver\_firmware\_version\_get.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的驱动固件版本和通讯固件版本。
    
    该脚本执行以下操作：`demo_comm_driver_firmware_version_get.py`
    
    1.  使用`broadcast_func_with_filter`函数，发现网络上的全部傅利叶自研执行器。
        
    2.  使用`get_comm_driver_version`、`get_comm_firmware_version`函数，检索每个检测到的傅利叶自研设备的通讯版本和驱动版本。
        
    3.  将每个检测到的傅利叶自研设备的通讯版本和驱动版本都在终端显示出来。
        
    4.  暂停1s。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_comm_driver_firmware_version_get.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  连接到 FSA执行器。
    
3.  打开终端并导航到包含 的目录。`demo_comm_driver_firmware_version_get.py`
    
4.  使用以下命令运行脚本：
    
    ```python
    python demo_comm_driver_firmware_version_get.py
    ```
    
5.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_comm_driver_firmware_version_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.30 10:31:21.816.769]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.30 10:31:21.817.742]  Info:    FSA start listening for broadcast...
[2024.10.30 10:31:21.817.772]  Info:    FSA start listening for broadcast...


[2024.10.30 10:31:21.820.757]  Info:    Received from ('192.168.137.51', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.51","IP":"192.168.137.51"}


found servers
['192.168.137.51']
lookup Finished! 

[2024.10.30 10:31:24.822.164]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.10.30 10:31:24.825.019]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
{"driver_version":"0.2.8.35"}
{"firmware_version":"0.3.9.9"}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
3.  检查执行器是否有任何需要清除的现有故障。
    
    ## demo\_comm\_config\_get.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的config属性。
    
    该脚本执行以下操作：`demo_comm_config_get.py`
    
    1.  使用`broadcast_func_with_filter`函数，发现网络上的 FSA 执行器。
        
    2.  使用`get_comm_config`函数，检索并打印每个检测到的 FSA 执行器的通信配置。
        

**配置参数****：**

通信配置参数包括：

*   **“name” （str） 的**设备的名称。
    
*   **“DHCP\_enable” （bool）：**启用 DHCP （True） 或使用静态 IP （False）。
    
*   **“SSID” （str）：**网络的 SSID。
    
*   **“password” （str） 的**网络的密码。
    
*   **“static\_IP” （str）：**静态 IP 地址（如果禁用了 DHCP）。
    
*   **“网关” （STR）：**网关地址（如果禁用了 DHCP）。
    
*   **“subnet\_mask” （str）：**子网掩码（如果禁用了 DHCP）。
    
*   **“dns\_1” （str）：**主 DNS 服务器（如果禁用了 DHCP）。
    
*   **“dns\_2” （str）：**辅助 DNS 服务器（如果禁用了 DHCP）。
    

**用法：**

要运行该脚本，请执行以下步骤：`demo_comm_config_get.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_comm_config_get.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_comm_config_get.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
(base) len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_comm_config_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.30 10:59:21.728.891]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.30 10:59:21.729.890]  Info:    FSA start listening for broadcast...
[2024.10.30 10:59:21.729.921]  Info:    FSA start listening for broadcast...


[2024.10.30 10:59:21.731.356]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.30 10:59:24.731.949]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.10.30 10:59:24.733.415]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/config","property":"","DHCP_enable":false,"SSID":"fftai-6","password":"fftai2015","name":"FSA-0","static_IP":[192,168,137,101],"gateway":[192,168,137,1],"subnet_mask":[255,255,255,0],"dns_1":[114,114,114,114],"dns_2":[8,8,8,8]}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_comm\_config\_set.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器的config属性。
    
    该脚本执行以下操作：`demo_comm_config_set.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`set_comm_config`函数为每个 Actuator 设置新的通信配置。新配置包括 `name``DHCP_enable``SSID``password``static_IP``gateway``subnet_mask``dns_1``dns_2`  等参数。
        
    3.  等待一秒
        
    4.  使用`get_comm_config`函数获取每个 Actuator 新的通信配置。
        
    5.  使用`reboot`函数重新启动每个 Actuator 以应用新的通信配置。
        

**配置参数****：**

通信配置参数包括：

*   **“name” （str） 的**设备的名称。
    
*   **“DHCP\_enable” （bool）：**启用 DHCP （True） 或使用静态 IP （False）。
    
*   **“SSID” （str）：**网络的 SSID。
    
*   **“password” （str） 的**网络的密码。
    
*   **“static\_IP” （str）：**静态 IP 地址（如果禁用了 DHCP）。
    
*   **“网关” （STR）：**网关地址（如果禁用了 DHCP）。
    
*   **“subnet\_mask” （str）：**子网掩码（如果禁用了 DHCP）。
    
*   **“dns\_1” （str）：**主 DNS 服务器（如果禁用了 DHCP）。
    
*   **“dns\_2” （str）：**辅助 DNS 服务器（如果禁用了 DHCP）。
    

**用法：**

要运行该脚本，请执行以下步骤：`demo_comm_config_set.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_comm_config_set.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_comm_config_set.py
    
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_comm_config_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.30 11:43:08.337.742]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.30 11:43:08.338.789]  Info:    FSA start listening for broadcast...
[2024.10.30 11:43:08.338.823]  Info:    FSA start listening for broadcast...


[2024.10.30 11:43:08.340.208]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.30 11:43:11.341.567]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/config", "property": "", "name": "FSA-0", "DHCP_enable": false, "SSID": "fftai-6", "password": "fftai2015", "static_IP": [192, 168, 137, 101], "gateway": [192, 168, 137, 1], "subnet_mask": [255, 255, 255, 0], "dns_1": [114, 114, 114, 114], "dns_2": [8, 8, 8, 8]}
[2024.10.30 11:43:11.543.882]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/config","property":""}


[2024.10.30 11:43:12.544.228]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.10.30 11:43:12.545.935]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/config","property":"","DHCP_enable":false,"SSID":"fftai-6","password":"fftai2015","name":"FSA-0","static_IP":[192,168,137,101],"gateway":[192,168,137,1],"subnet_mask":[255,255,255,0],"dns_1":[114,114,114,114],"dns_2":[8,8,8,8]}


[2024.10.30 11:43:12.546.139]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": ""}
[2024.10.30 11:43:12.547.780]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_set\_subscribe.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何将执行器的位置、速度、电流、力矩数据可选择地发送到指定端口
    
    该脚本执行以下操作：`demo_set_subscribe.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`set_subscribe`函数为每个 Actuator 设置subscribe的配置参数。具体配置内容请看[cfg\_dict](https://alidocs.dingtalk.com/i/nodes/Gl6Pm2Db8DNkPm7pF4yMnRBaVxLq0Ee4?utm_scene=person_space&iframeQuery=anchorId%3Duu_m2u173uwrjf4npd00qa)
        
    3.  判断是否开启了发送，如果开启了发送则循环接收执行器发送的位置、速度、电流、力矩等数据信息。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_set_subscribe.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_set_subscribe.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_set_subscribe.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.30 20:53:50.084.473]  Info:    FSA start listening for broadcast...
Socket is bound to port: 53063
[2024.12.30 20:53:50.084.473]  Info:    FSA start listening for broadcast...


[2024.12.30 20:53:50.086.441]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 20:53:53.096.084]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 20:53:53.098.371]  Info:    Send JSON Obj: {"port": 53063, "enable": 1, "position": 1, "velocity": 1, "current": 1, "torque": 1, "error": 1, "error_ext2": 1, "error_ext3": 1, "error_ext4": 1, "error_ext5": 1, "error_ext6": 1, "error_ext7": 1, "error_ext8": 1, "method": "SET", "reqTarget": "/subscribe", "property": ""}
[2024.12.30 20:53:53.100.387]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/subscribe","property":""}
: Server received from ('192.168.137.101', 2336):b'\x02\xba1\xbbS\x03\xbeu\xac\x93\x04\x80\x00\x00\x00\x05\xbd\x8a\x1c0\x06\x00\x00\x00\x00\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000678
index = 0x03, velocity = -0.239916
index = 0x04, current = -0.000000
index = 0x05, torque = -0.067437
index = 0x06, cnt = 0
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xba1\xbbS\x03\xbeu\xac\x93\x04\x80\x00\x00\x00\x05\xbd\x8a\x1c0\x06\x00\x00\x00\x01\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000678
index = 0x03, velocity = -0.239916
index = 0x04, current = -0.000000
index = 0x05, torque = -0.067437
index = 0x06, cnt = 1
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xba\x10\xbaw\x03>\xb0e`\x04\x80\x00\x00\x00\x05\xbd\x18\xd1\n\x06\x00\x00\x00\x02\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000552
index = 0x03, velocity = 0.344523
index = 0x04, current = -0.000000
index = 0x05, torque = -0.037309
index = 0x06, cnt = 2
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xba\x10\xbaw\x03>\xb0e`\x04\x80\x00\x00\x00\x05\xbd\x18\xd1\n\x06\x00\x00\x00\x03\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000552
index = 0x03, velocity = 0.344523
index = 0x04, current = -0.000000
index = 0x05, torque = -0.037309
index = 0x06, cnt = 3
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xbaf\xf7l\x03\xbe\x044\x04\x04\x80\x00\x00\x00\x05<\xd6\x95\x86\x06\x00\x00\x00\x04\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000881
index = 0x03, velocity = -0.129105
index = 0x04, current = -0.000000
index = 0x05, torque = 0.026194
index = 0x06, cnt = 4
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xbaf\xf7l\x03\xbe\x044\x04\x04\x80\x00\x00\x00\x05<\xd6\x95\x86\x06\x00\x00\x00\x05\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.000881
index = 0x03, velocity = -0.129105
index = 0x04, current = -0.000000
index = 0x05, torque = 0.026194
index = 0x06, cnt = 5
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
: Server received from ('192.168.137.101', 2336):b'\x02\xba\x86.U\x03\xbe\xbc\x92\xeb\x04\x80\x00\x00\x00\x05<\xce\x16\xf4\x06\x00\x00\x00\x06\x07\x00\x00\x00\x10\x08\x00\x00\x00\x01\t\x00\x00\x00\x00\n\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x0c\x00\x00\x00\x00\r\x00\x00\x00\x00\x0e\x00\x00\x00\x00'
65
index = 0x02, position = -0.001024
index = 0x03, velocity = -0.368308
index = 0x04, current = -0.000000
index = 0x05, torque = 0.025157
index = 0x06, cnt = 6
index = 0x07, error = 16
index = 0x08, error_ext2 = 1
index = 0x09, error_ext3 = 0
index = 0x0A, error_ext4 = 0
index = 0x0B, error_ext5 = 0
index = 0x0C, error_ext6 = 0
index = 0x0D, error_ext7 = 0
index = 0x0E, error_ext8 = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ota.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器进行通信ota升级，升级版本为生产版
    
    该脚本执行以下操作：`demo_ota.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`ota`函数为每个 Actuator 进行通信ota升级，升级版本为生产版。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ota.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ota.py`
    
3.  使用以下命令运行脚本：
    

```plaintext
python demo_ota.py

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ota\_test.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器进行通信ota升级，升级版本为测试版
    
    该脚本执行以下操作：`demo_ota_test.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`ota_test`函数为每个 Actuator 进行通信ota升级，升级版本为测试版。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ota_test.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ota_test.py`
    
3.  使用以下命令运行脚本：
    

```plaintext
python demo_ota_test.py

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ota\_devel.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器进行通信ota升级，升级版本为开发版
    
    该脚本执行以下操作：`demo_ota_devel.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`ota_devel`函数为每个 Actuator 进行通信ota升级，升级版本为开发版。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ota_devel.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ota_devel.py`
    
3.  使用以下命令运行脚本：
    

```plaintext
python demo_ota_devel.py

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ota\_cloud.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器进行通信ota升级，升级版本为云端版
    
    该脚本执行以下操作：`demo_ota_cloud.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`ota_cloud`函数为每个 Actuator 进行通信ota升级，升级版本为云端版。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ota_cloud.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ota_cloud.py`
    
3.  使用以下命令运行脚本：
    

```plaintext
python demo_ota_cloud.py

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ota\_custom.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器进行通信ota升级，升级版本为自定义版
    
    该脚本执行以下操作：`demo_ota_custom.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  设置version\_str为你升级的版本。
        
    3.  使用`ota_custom`函数为每个 Actuator 进行通信ota升级，升级版本为自定义版。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ota_custom.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ota_custom.py`
    
3.  使用以下命令运行脚本：
    

```plaintext
python demo_ota_custom.py

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ota\_driver.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器进行驱动ota升级，升级版本为生产版
    
    该脚本执行以下操作：`demo_ota_driver.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`ota_driver`函数为每个 Actuator 进行驱动ota升级，升级版本为生产版。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ota_driver.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ota_driver.py`
    
3.  使用以下命令运行脚本：
    

```plaintext
python demo_ota_driver.py

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ota\_driver\_test.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器进行驱动ota升级，升级版本为测试版
    
    该脚本执行以下操作：`demo_ota_driver_test.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`ota_driver_test`函数为每个 Actuator 进行驱动ota升级，升级版本为测试版。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ota_driver_test.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ota_driver_test.py`
    
3.  使用以下命令运行脚本：
    

```plaintext
python demo_ota_driver_test.py
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ota\_driver\_devel.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器进行驱动ota升级，升级版本为开发版
    
    该脚本执行以下操作：`demo_ota_driver_devel.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`ota_driver_devel`函数为每个 Actuator 进行驱动ota升级，升级版本为开发版。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ota_driver_devel.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ota_driver_devel.py`
    
3.  使用以下命令运行脚本：
    

```plaintext
python demo_ota_driver_devel.py

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ota\_driver\_cloud.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器进行驱动ota升级，升级版本为云端版
    
    该脚本执行以下操作：`demo_ota_driver_cloud.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`ota_driver_cloud`函数为每个 Actuator 进行驱动ota升级，升级版本为云端版。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ota_driver_cloud.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ota_driver_cloud.py`
    
3.  使用以下命令运行脚本：
    

```plaintext
python demo_ota_driver_cloud.py

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ota\_driver\_custom.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器进行驱动ota升级，升级版本为自定义版
    
    该脚本执行以下操作：`demo_ota_driver_custom.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  设置version\_str为你升级的版本。
        
    3.  使用`ota_driver_custom`函数为每个 Actuator 进行驱动ota升级，升级版本为自定义版。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ota_driver_custom.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ota_driver_custom.py`
    
3.  使用以下命令运行脚本：
    

```plaintext
python demo_ota_driver_custom.py

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_enable\_set.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器执行使能操作，即启动执行器。
    
    该脚本执行以下操作：`demo_enable_set.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`set_enable`函数为每个执行器执行使能操作。
        
    3.  打印一条消息并等待 1 秒钟，以便有时间启用 Actuators。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_enable_set.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_enable_set.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_enable_set.py
    
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_enable_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.31 11:42:45.075.500]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.31 11:42:45.077.056]  Info:    FSA start listening for broadcast...
[2024.10.31 11:42:45.077.088]  Info:    FSA start listening for broadcast...


[2024.10.31 11:42:45.078.506]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.31 11:42:48.079.720]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 15}
[2024.10.31 11:42:48.080.855]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/control_word","property":""}



```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_disable\_set.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器执行失能操作。
    
    该脚本执行以下操作：`demo_disable_set.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`set_disable`函数为每个执行器执行失能操作。
        
    3.  打印一条消息并等待 1 秒钟，以便有时间启用 Actuators。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_disable_set.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_disable_set.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_disable_set.py
    
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_disable_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.31 11:42:55.084.026]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.31 11:42:55.085.034]  Info:    FSA start listening for broadcast...
[2024.10.31 11:42:55.085.065]  Info:    FSA start listening for broadcast...


[2024.10.31 11:42:55.086.520]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.31 11:42:58.087.818]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 6}
[2024.10.31 11:42:58.088.929]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/control_word","property":""}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_clear\_fault.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器执行失能操作。
    
    该脚本执行以下操作：`demo_fault.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`get_error_code`函数获取每个执行器的错误码。
        
    3.  使用`clear_fault`函数清除每个执行器的错误码。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_clear_fault.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_clear_fault.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_clear_fault.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
(base) len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_clear_fault.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.12 15:00:44.136.179]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.12 15:00:44.137.512]  Info:    FSA start listening for broadcast...
[2024.11.12 15:00:44.137.543]  Info:    FSA start listening for broadcast...


[2024.11.12 15:00:44.138.830]  Info:    Received from ('192.168.137.70', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"CC64AC8D3A08","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"08:3A:8D:AC:64:CF","ip_address":"192.168.137.70","IP":"192.168.137.70"}


found servers
['192.168.137.70']
lookup Finished! 

[2024.11.12 15:00:47.139.925]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/error_code", "property": ""}
[2024.11.12 15:00:47.140.904]  Info:    Received from ('192.168.137.70', 2333):{"status":"OK","reqTarget":"/error_code","property":"","error_code":16}
[2024.11.12 15:00:47.140.997]  Info:    Now Error Type =  ERROR_UNDER_VBUS
Error code = 16
[2024.11.12 15:00:47.141.107]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 134, "reply_enable": true}
[2024.11.12 15:00:47.141.991]  Info:    Received from ('192.168.137.70', 2333):{"status":"OK","reqTarget":"/control_word","property":""}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_set\_calibrate\_encoder.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器进行校准（注意：校准过程中，执行器会转动，建议要把执行器固定好再校准）。
    
    该脚本执行以下操作：`demo_set_calibrate_encoder.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`set_calibrate_encoder`函数为每个执行器进行校准操作。
        
    3.  使用`get_state`函数获取每个执行器当前的状态。
        
    4.  使用`set_disable`函数对校准完的执行器进行失能的操作。
        
    5.  最后，使用`set_disable`函数对每个执行器进行失能的操作。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_set_calibrate_encoder.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_set_calibrate_encoder.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_set_calibrate_encoder.py
    
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_calibrate_encoder.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.31 15:14:29.483.510]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.31 15:14:29.484.559]  Info:    FSA start listening for broadcast...
[2024.10.31 15:14:29.484.592]  Info:    FSA start listening for broadcast...


[2024.10.31 15:14:29.485.906]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.31 15:14:32.487.312]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 163}
[2024.10.31 15:14:32.488.180]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/control_word","property":""}
[2024.10.31 15:14:33.488.424]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 15:14:33.489.222]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
[2024.10.31 15:14:34.489.539]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 15:14:34.490.436]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
[2024.10.31 15:14:35.490.726]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 15:14:35.491.509]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
[2024.10.31 15:14:36.491.769]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 15:14:36.492.663]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
[2024.10.31 15:14:37.493.009]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 15:14:37.493.833]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
[2024.10.31 15:14:38.494.138]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 6}
[2024.10.31 15:14:38.494.989]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/control_word","property":""}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_pid\_param\_get.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的pid配置参数。
    
    该脚本执行以下操作：`demo_pid_param_get.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`get_pid_param`函数获取每个执行器的pid配置参数。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_pid_param_get.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_pid_param_get.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_pid_param_get.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_pid_param_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 11:27:36.661.864]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 11:27:36.662.922]  Info:    FSA start listening for broadcast...
[2024.11.02 11:27:36.662.965]  Info:    FSA start listening for broadcast...


[2024.11.02 11:27:36.665.580]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 11:27:39.666.649]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/pid_param", "property": ""}
[2024.11.02 11:27:39.668.296]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param","property":"","control_position_kp":0.050000001,"control_velocity_kp":0.01,"control_velocity_ki":0.0001,"control_current_kp":0.600044012,"control_current_ki":0.079842001}
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_pid\_param\_set.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器的pid配置参数（该参数必须要重启后才能生效）。
    
    该脚本执行以下操作：`demo_pid_param_set.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`set_pid_param`函数设置每个执行器的pid配置参数。
        
    3.  使用`get_pid_param`函数获取每个执行器的pid配置参数。
        
    4.  使用`reboot`函数重启每个执行器，以使用设置之后的pid配置参数。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_pid_param_set.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_pid_param_set.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_pid_param_set.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_pid_param_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 11:50:10.196.510]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 11:50:10.197.515]  Info:    FSA start listening for broadcast...
[2024.11.02 11:50:10.197.553]  Info:    FSA start listening for broadcast...


[2024.11.02 11:50:10.200.202]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 11:50:13.201.685]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/pid_param", "property": "", "control_position_kp": 0.5, "control_velocity_kp": 0.0025, "control_velocity_ki": 1e-05, "control_PD_kp": 1.0, "control_PD_kd": 1.0, "reply_enable": true}
[2024.11.02 11:50:13.273.576]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param","property":""}


[2024.11.02 11:50:14.273.918]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/pid_param", "property": ""}
[2024.11.02 11:50:14.275.480]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param","property":"","control_position_kp":0.5,"control_velocity_kp":0.0025,"control_velocity_ki":9.999999747e-6,"control_current_kp":0,"control_current_ki":0}


[2024.11.02 11:50:14.275.684]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": "", "reply_enable": true}
[2024.11.02 11:50:14.277.134]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_pid\_param\_imm\_get.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的pid临时配置参数。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`get_pid_param_imm`函数获取每个执行器的pid临时配置参数。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_pid_param_imm_get.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_pid_param_imm_get.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_pid_param_imm_get.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_pid_param_imm_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 13:30:35.176.151]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 13:30:35.177.175]  Info:    FSA start listening for broadcast...
[2024.11.02 13:30:35.177.206]  Info:    FSA start listening for broadcast...


[2024.11.02 13:30:35.179.804]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 13:30:38.181.122]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/pid_param_imm", "property": ""}
[2024.11.02 13:30:38.182.743]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param_imm","property":"","control_position_kp_imm":0.050000001,"control_velocity_kp_imm":0.01,"control_velocity_ki_imm":0.0001,"control_current_kp_imm":0.600044012,"control_current_ki_imm":0.079842001}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_pid\_param\_imm\_set.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器的pid临时配置参数（该参数设置后立即生效，但是断电后不会保存）。
    
    该脚本执行以下操作：`demo_pid_param_imm_set.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`set_pid_param_imm`函数设置每个执行器的pid临时配置参数。
        
    3.  使用`get_pid_param_imm`函数获取每个执行器的pid临时配置参数。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_pid_param_imm_set.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_pid_param_imm_set.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_pid_param_imm_set.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_pid_param_imm_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 13:35:14.138.717]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 13:35:14.139.704]  Info:    FSA start listening for broadcast...
[2024.11.02 13:35:14.139.740]  Info:    FSA start listening for broadcast...


[2024.11.02 13:35:14.141.100]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 13:35:17.142.496]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/pid_param_imm", "property": "", "control_position_kp_imm": 0.0, "control_velocity_kp_imm": 0.1, "control_velocity_ki_imm": 0.001, "control_PD_kp_imm": 1.0, "control_PD_kd_imm": 1.0, "reply_enable": true}
[2024.11.02 13:35:17.143.886]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param_imm","property":""}


[2024.11.02 13:35:18.144.121]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/pid_param_imm", "property": ""}
[2024.11.02 13:35:18.145.184]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/pid_param_imm","property":"","control_position_kp_imm":0,"control_velocity_kp_imm":0.100000001,"control_velocity_ki_imm":0.001,"control_current_kp_imm":0,"control_current_ki_imm":0}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_control\_param\_get.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的控制参数（该参数必须要重启后才能生效）。
    
    该脚本执行以下操作：`demo_control_param_get.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`get_control_param`函数获取每个执行器的控制参数。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_control_param_get.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_control_param_get.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_control_param_get.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_control_param_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 14:01:02.649.769]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 14:01:02.650.855]  Info:    FSA start listening for broadcast...
[2024.11.02 14:01:02.650.895]  Info:    FSA start listening for broadcast...


[2024.11.02 14:01:02.652.100]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 14:01:05.653.424]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/control_param", "property": ""}
[2024.11.02 14:01:05.654.556]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/control_param","property":"","motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_control\_param\_set.py 该脚本暂时不能用
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器的控制参数（该参数必须要重启后才能生效）。
    
    该脚本执行以下操作：`demo_control_param_set.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`set_control_param`函数设置每个执行器的控制参数。
        
    3.  使用`get_control_param`函数获取每个执行器的控制参数。
        
    4.  使用`reboot`函数重启每个执行器，以使用设置之后的控制参数。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_control_param_set.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_control_param_set.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_control_param_set.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_control\_param\_imm\_get.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的临时控制参数（该参数设置后立即生效，但是断电后不会保存）。
    
    该脚本执行以下操作：`demo_control_param_imm_get.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`get_control_param_imm`函数获取每个执行器的临时控制参数。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_control_param_imm_get.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_control_param_imm_get.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_control_param_imm_get.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_control_param_imm_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 14:48:52.129.294]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 14:48:52.141.229]  Info:    FSA start listening for broadcast...
[2024.11.02 14:48:52.141.258]  Info:    FSA start listening for broadcast...


[2024.11.02 14:48:52.142.568]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 14:48:55.143.883]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/control_param_imm", "property": ""}
[2024.11.02 14:48:55.145.052]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/control_param_imm","motor_max_speed_imm":3000,"motor_max_acceleration_imm":60000,"motor_max_current_imm":100}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_control\_param\_imm\_set.py 该脚本暂时不能用
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器的临时控制参数（该参数设置后立即生效，但是断电后不会保存）。
    
    该脚本执行以下操作：`demo_control_param_imm_set.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`set_control_param_imm`函数设置每个执行器的临时控制参数。
        
    3.  使用`get_control_param_imm`函数获取每个执行器的临时控制参数。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_control_param_imm_set.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_control_param_imm_set.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_control_param_imm_set.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_flag\_of\_operation\_get.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的操作标识。
    
    该脚本执行以下操作：`demo_flag_of_operation_get.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`get_flag_of_operation`函数获取每个执行器的操作标识。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_flag_of_operation_get.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_flag_of_operation_get.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_flag_of_operation_get.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_flag_of_operation_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 15:33:25.309.503]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 15:33:25.310.538]  Info:    FSA start listening for broadcast...
[2024.11.02 15:33:25.310.568]  Info:    FSA start listening for broadcast...


[2024.11.02 15:33:25.311.849]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 15:33:28.313.160]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/flag_of_operation", "property": ""}
[2024.11.02 15:33:28.314.339]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/flag_of_operation","property":"","flag_do_use_store_motor_param":1,"flag_do_use_store_pid_param":0}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_flag\_of\_operation\_set.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的操作标识。
    
    该脚本执行以下操作：`demo_flag_of_operation_set.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`set_flag_of_operation`函数设置每个执行器的操作标识。
        
    3.  使用`get_flag_of_operation`函数获取每个执行器的操作标识。
        
    4.  使用`reboot`函数重启每个执行器，以使用设置之后的操作标识。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_flag_of_operation_set.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_flag_of_operation_set.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_flag_of_operation_set.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_flag_of_operation_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 15:43:42.958.014]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 15:43:42.959.018]  Info:    FSA start listening for broadcast...
[2024.11.02 15:43:42.959.051]  Info:    FSA start listening for broadcast...


[2024.11.02 15:43:42.960.393]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 15:43:45.961.738]  Info:    Send JSON Obj: {"flag_do_use_store_actuator_param": 0, "flag_do_use_store_motor_param": 1, "flag_do_use_store_encoder_param": 0, "flag_do_use_store_pid_param": 0, "actuator_double_encoder_enable": 1, "method": "SET", "reqTarget": "/flag_of_operation", "property": "", "reply_enable": true}
[2024.11.02 15:43:46.035.195]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/flag_of_operation","property":""}


[2024.11.02 15:43:47.035.466]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/flag_of_operation", "property": ""}
[2024.11.02 15:43:47.036.733]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/flag_of_operation","property":"","flag_do_use_store_motor_param":1,"flag_do_use_store_pid_param":0}


[2024.11.02 15:43:47.036.855]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": "", "reply_enable": true}
[2024.11.02 15:43:47.038.095]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ctrl\_config\_get.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的配置信息。
    
    该脚本执行以下操作：`demo_ctrl_config_get.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`get_config`函数获取每个执行器的配置信息。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ctrl_config_get.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ctrl_config_get.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_ctrl_config_get.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_ctrl_config_get.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 10:02:26.890.860]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 10:02:26.892.567]  Info:    FSA start listening for broadcast...
[2024.11.04 10:02:26.892.598]  Info:    FSA start listening for broadcast...


[2024.11.04 10:02:26.893.788]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.04 10:02:29.895.150]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.11.04 10:02:29.896.550]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":31,"motor_type":4,"motor_hardware_type":3,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_ctrl\_config\_set.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的配置信息。
    
    该脚本执行以下操作：`demo_ctrl_config_set.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`set_config`函数设置每个执行器的配置信息。
        
    3.  使用`get_config`函数获取每个执行器的配置信息。
        
    4.  使用`reboot`函数重启每个执行器，以使用设置之后的执行器配置信息。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_ctrl_config_set.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_ctrl_config_set.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_ctrl_config_set.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_ctrl_config_set.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 10:09:37.179.770]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 10:09:37.180.775]  Info:    FSA start listening for broadcast...
[2024.11.04 10:09:37.180.812]  Info:    FSA start listening for broadcast...


[2024.11.04 10:09:37.182.082]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.04 10:09:40.183.584]  Info:    Send JSON Obj: {"actuator_type": 1, "actuator_direction": 1, "actuator_reduction_ratio": 81, "motor_type": 6, "motor_hardware_type": 4, "motor_vbus": 48, "motor_direction": 1, "motor_max_speed": 3000, "motor_max_acceleration": 60000, "motor_max_current": 3.3, "actuator_comm_hardware_type": 2, "method": "SET", "reqTarget": "/config", "property": "", "reply_enable": true}
[2024.11.04 10:09:40.258.475]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":""}


[2024.11.04 10:09:41.258.890]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.11.04 10:09:41.260.547]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":81,"motor_type":6,"motor_hardware_type":4,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":3.299999952}


[2024.11.04 10:09:41.260.759]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": "", "reply_enable": true}
[2024.11.04 10:09:41.262.103]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_reboot.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何重启执行器。
    
    该脚本执行以下操作：`demo_reboot.py`
    
    1.  使用`broadcast_func`函数，发现网络上的全部傅利叶自研设备。    
        
    2.  使用`reboot`函数重启每个执行器。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_reboot.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_reboot.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_reboot.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_reboot.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 10:23:01.025.692]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 10:23:01.026.763]  Info:    FSA start listening for broadcast...
[2024.11.04 10:23:01.026.793]  Info:    FSA start listening for broadcast...


[2024.11.04 10:23:01.029.494]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.04 10:23:04.030.842]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": "", "reply_enable": true}
[2024.11.04 10:23:04.032.520]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_get\_error.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的错误码。
    
    该脚本执行以下操作：`demo_get_error.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`get_error_code`函数获取执行器的错误码。
        
    3.  将其显示在终端上。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_get_error.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_get_error.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_get_error.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_error.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 10:40:03.841.246]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 10:40:03.842.325]  Info:    FSA start listening for broadcast...
[2024.11.04 10:40:03.842.359]  Info:    FSA start listening for broadcast...


[2024.11.04 10:40:03.843.536]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.04 10:40:06.844.401]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/error_code", "property": ""}
[2024.11.04 10:40:06.845.354]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/error_code","property":"","error_code":0}
Error = 0
[2024.11.04 10:40:07.045.631]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/error_code", "property": ""}
[2024.11.04 10:40:07.046.425]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/error_code","property":"","error_code":0}
Error = 0

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_get\_pvc.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器当前的位置、速度、电流信息。
    
    该脚本执行以下操作：`demo_get_pvc.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`get_pvc`函数获取执行器当前的位置、速度、电流信息。
        
    3.  将其显示在终端上。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_get_pvc.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_get_pvc.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_get_pvc.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_pvc.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 10:58:39.952.803]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 10:58:39.953.854]  Info:    FSA start listening for broadcast...
[2024.11.04 10:58:39.953.884]  Info:    FSA start listening for broadcast...


[2024.11.04 10:58:39.955.101]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.04 10:58:42.956.583]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.11.04 10:58:42.957.822]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":0.000542568,"velocity":-0.129396752,"current":0}
Position = 0.000543, Velocity = -0.129397, Current = 0.0000
[2024.11.04 10:58:43.158.203]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.11.04 10:58:43.159.197]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":0.000813852,"velocity":0.032842342,"current":0}
Position = 0.000814, Velocity = 0.032842, Current = 0.0000

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_get\_foc\_target\_PVC.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的FOC执行的目标位置、目标速度、目标电流信息。
    
    该脚本执行以下操作：`demo_get_foc_target_PVC.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`get_foc_target_PVC`函数获取执行器的FOC执行的目标位置、目标速度、目标电流信息。
        
    3.  将其显示在终端上。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_get_foc_target_PVC.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_get_foc_target_PVC.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_get_foc_target_PVC.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_foc_target_PVC.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 11:24:28.202.320]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 11:24:28.203.338]  Info:    FSA start listening for broadcast...
[2024.11.04 11:24:28.203.368]  Info:    FSA start listening for broadcast...


[2024.11.04 11:24:28.204.748]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

[2024.11.04 11:24:31.206.141]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/foc_target_PVC"}
[2024.11.04 11:24:31.207.431]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/foc_target_PVC","property":null,"position":-91.6812973,"velocity":0,"current":0}
Position = -91.681297, Velocity = 0.000000, Current = 0.0000
[2024.11.04 11:24:31.407.767]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/foc_target_PVC"}
[2024.11.04 11:24:31.408.842]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/foc_target_PVC","property":null,"position":-91.6812973,"velocity":0,"current":0}
Position = -91.681297, Velocity = 0.000000, Current = 0.0000
[2024.11.04 11:24:31.609.187]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/foc_target_PVC"}
[2024.11.04 11:24:31.610.334]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/foc_target_PVC","property":null,"position":-91.6812973,"velocity":0,"current":0}
Position = -91.681297, Velocity = 0.000000, Current = 0.0000

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_get\_pvct.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器当前的位置、速度、电流、力矩信息。
    
    该脚本执行以下操作：`demo_get_pvct.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`get_pvct`函数获取执行器当前的位置、速度、电流、力矩信息。
        
    3.  将其显示在终端上。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_get_pvct.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_get_pvct.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_get_pvct.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_pvct.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 11:34:58.507.450]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 11:34:58.508.468]  Info:    FSA start listening for broadcast...
[2024.11.04 11:34:58.508.503]  Info:    FSA start listening for broadcast...


[2024.11.04 11:34:58.509.863]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

[2024.11.04 11:35:01.511.120]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/PVCT"}
[2024.11.04 11:35:01.512.277]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/PVCT","property":null,"position":89.58617401,"velocity":0.03555651,"current":0,"torque":-0.03296325}
Position = 89.586174, Velocity = 0.035557, Current = 0.0000, Torque =   -0
[2024.11.04 11:35:01.712.625]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/PVCT"}
[2024.11.04 11:35:01.713.676]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/PVCT","property":null,"position":89.58609772,"velocity":-0.108989172,"current":0,"torque":0.015949339}
Position = 89.586098, Velocity = -0.108989, Current = 0.0000, Torque =    0
[2024.11.04 11:35:01.914.034]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/PVCT"}
[2024.11.04 11:35:01.915.123]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/PVCT","property":null,"position":89.58616638,"velocity":-0.02177074,"current":0,"torque":-0.021388493}
Position = 89.586166, Velocity = -0.021771, Current = 0.0000, Torque =   -0
[2024.11.04 11:35:02.115.460]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/PVCT"}
[2024.11.04 11:35:02.116.494]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/PVCT","property":null,"position":89.58615875,"velocity":-0.072669469,"current":0,"torque":-0.010420063}
Position = 89.586159, Velocity = -0.072669, Current = 0.0000, Torque =   -0

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_get\_fsa\_abs\_position.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器绝对编码器的位置信息。
    
    该脚本执行以下操作：`demo_get_fsa_abs_position.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`get_fsa_abs_position`函数获取执行器绝对编码器的位置信息。
        
    3.  将其显示在终端上。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_get_fsa_abs_position.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_get_fsa_abs_position.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_get_fsa_abs_position.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_fsa_abs_position.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 13:22:27.628.713]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 13:22:27.630.404]  Info:    FSA start listening for broadcast...
[2024.11.04 13:22:27.630.435]  Info:    FSA start listening for broadcast...


[2024.11.04 13:22:27.633.344]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

[2024.11.04 13:22:30.634.706]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/get_abs_position"}
[2024.11.04 13:22:30.638.086]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/get_abs_position","property":null,"abs_position":94.93286133}
Position = 94.932861

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_set\_fsa\_abs\_zero.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器的绝对编码器零点位置。
    
    该脚本执行以下操作：`demo_set_fsa_abs_zero.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`set_fsa_abs_zero`函数设置执行器的绝对编码器的零点位置，将当前位置设置为零点。
        
    3.  使用`reboot`函数重启每个执行器，以使用设置之后的绝对编码器的零点。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_set_fsa_abs_zero.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_set_fsa_abs_zero.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_set_fsa_abs_zero.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_fsa_abs_zero.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 13:34:37.314.672]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 13:34:37.315.687]  Info:    FSA start listening for broadcast...
[2024.11.04 13:34:37.315.717]  Info:    FSA start listening for broadcast...


[2024.11.04 13:34:37.317.110]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

now is setting: 192.168.137.10
[2024.11.04 13:34:40.318.626]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/set_abs_zero", "reply_enable": true}
[2024.11.04 13:34:40.320.024]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/set_abs_zero","property":null}
True
[2024.11.04 13:34:44.320.446]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/reboot", "property": "", "reply_enable": true}
[2024.11.04 13:34:44.322.374]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/reboot","property":""}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_set\_eth\_recovery.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器的网络恢复。
    
    该脚本执行以下操作：`demo_set_eth_recovery.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`set_eth_recovery`函数设置执行器的网络恢复。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_set_eth_recovery.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_set_eth_recovery.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_set_eth_recovery.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_eth_recovery.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 13:46:51.055.208]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 13:46:51.056.247]  Info:    FSA start listening for broadcast...
[2024.11.04 13:46:51.056.278]  Info:    FSA start listening for broadcast...


[2024.11.04 13:46:51.059.472]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

[2024.11.04 13:46:54.060.707]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/set_eth_recovery", "reply_enable": true}
[2024.11.04 13:46:54.062.374]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/set_eth_recovery","property":null}
True

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_set\_eth\_timeout\_protect.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器网络的超时保护。
    
    该脚本执行以下操作：`demo_set_eth_timeout_protect.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`set_eth_timeout_protect`函数启动网络的超时保护，并将超时时间设置为1000ms。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_set_eth_timeout_protect.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_set_eth_timeout_protect.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_set_eth_timeout_protect.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_eth_timeout_protect.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.04 17:30:34.142.725]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.04 17:30:34.143.765]  Info:    FSA start listening for broadcast...
[2024.11.04 17:30:34.143.796]  Info:    FSA start listening for broadcast...


[2024.11.04 17:30:34.145.178]  Info:    Received from ('192.168.137.10', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"4861061C0610","driver_version":"0.2.9.1","firmware_version":"0.3.10.5","connect_mode":"ETH","mac_address":"10:06:1C:06:61:4B","ip_address":"192.168.137.10","IP":"192.168.137.10"}


found servers
['192.168.137.10']
lookup Finished! 

[2024.11.04 17:30:37.146.500]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/set_eth_timeout_protect", "protect_enable": 0, "timeout_interval": 1000, "reply_enable": true}
[2024.11.04 17:30:37.147.705]  Info:    Received from ('192.168.137.10', 2333):{"status":"OK","reqTarget":"/set_eth_timeout_protect","property":null}
True

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_set\_control\_loop\_freq\_div.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何修改执行器的控制频率。
    
    该脚本执行以下操作：`demo_set_control_loop_freq_div.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`set_control_loop_freq_div`函数修改执行器的控制频率，其中函数输入的position\_loop\_freq\_div，velocity\_loop\_freq\_div，PD\_loop\_freq\_div的含义是，分别是将对应的控制模式的控制频率除与该值，以修改控制频率。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_set_control_loop_freq_div.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_set_control_loop_freq_div.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_set_control_loop_freq_div.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_control_loop_freq_div.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.06 10:41:28.723.825]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.06 10:41:28.724.844]  Info:    FSA start listening for broadcast...
[2024.11.06 10:41:28.724.880]  Info:    FSA start listening for broadcast...


[2024.11.06 10:41:28.727.973]  Info:    Received from ('192.168.137.52', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.11.4","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.52","IP":"192.168.137.52"}


found servers
['192.168.137.52']
lookup Finished! 

[2024.11.06 10:41:31.728.735]  Info:    Send JSON Obj: {"method": "SET", "reply_enable": true, "reqTarget": "/set_control_loop_freq_div", "position_loop_freq_div": 1, "velocity_loop_freq_div": 1, "PD_loop_freq_div": 1}
[2024.11.06 10:41:31.730.439]  Info:    Received from ('192.168.137.52', 2333):{"status":"OK","reqTarget":"/set_control_loop_freq_div","property":null}
True

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_set\_torque\_limit\_max.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器的最大扭矩。
    
    该脚本执行以下操作：`demo_set_torque_limit_max.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`set_torque_limit_max`函数设置执行器的最大扭矩。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_set_torque_limit_max.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_set_torque_limit_max.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_set_torque_limit_max.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_torque_limit_max.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.06 10:45:28.214.635]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.06 10:45:28.215.689]  Info:    FSA start listening for broadcast...
[2024.11.06 10:45:28.215.721]  Info:    FSA start listening for broadcast...


[2024.11.06 10:45:28.217.193]  Info:    Received from ('192.168.137.52', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.11.4","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.52","IP":"192.168.137.52"}


found servers
['192.168.137.52']
lookup Finished! 

[2024.11.06 10:45:31.218.649]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/torque_limit_max", "torque_limit_max": 30, "reply_enable": true}
[2024.11.06 10:45:31.219.960]  Info:    Received from ('192.168.137.52', 2333):{"status":"OK","reqTarget":"/torque_limit_max","property":null}
True

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_set\_inertia\_ff.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器的惯量补偿。
    
    该脚本执行以下操作：`demo_set_inertia_ff.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`set_torque_limit_max`函数设置执行器的惯量补偿。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_set_inertia_ff.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_set_inertia_ff.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_set_inertia_ff.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_set_inertia_ff.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.06 10:54:03.575.090]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.06 10:54:03.576.146]  Info:    FSA start listening for broadcast...
[2024.11.06 10:54:03.576.177]  Info:    FSA start listening for broadcast...


[2024.11.06 10:54:03.577.478]  Info:    Received from ('192.168.137.52', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.11.4","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.52","IP":"192.168.137.52"}


found servers
['192.168.137.52']
lookup Finished! 

[2024.11.06 10:54:06.578.890]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/inertia_ff", "inertia_ff": 0.5, "reply_enable": true}
[2024.11.06 10:54:06.580.401]  Info:    Received from ('192.168.137.52', 2333):{"status":"OK","reqTarget":"/inertia_ff","property":null}
True

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_get\_ntc\_temperature.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器的绕组温度和mos温度。
    
    该脚本执行以下操作：`demo_get_ntc_temperature.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选  
        
    2.  使用`get_ntc_temperature`函数获取执行器的绕组温度和mos温度。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_get_ntc_temperature.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_get_ntc_temperature.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_get_ntc_temperature.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_get_ntc_temperature.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.05 14:16:45.269.404]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.05 14:16:45.270.412]  Info:    FSA start listening for broadcast...
[2024.11.05 14:16:45.270.442]  Info:    FSA start listening for broadcast...


[2024.11.05 14:16:45.271.868]  Info:    Received from ('192.168.137.53', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"A4D32BE0F908","driver_version":"0.2.8.35","firmware_version":"0.3.11.4","connect_mode":"ETH","mac_address":"08:F9:E0:2B:D3:A7","ip_address":"192.168.137.53","IP":"192.168.137.53"}


found servers
['192.168.137.53']
lookup Finished! 

[2024.11.05 14:16:48.273.155]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/get_ntc_temperature"}
[2024.11.05 14:16:48.276.090]  Info:    Received from ('192.168.137.53', 2333):{"status":"OK","reqTarget":"/get_ntc_temperature","property":null,"mos_temperature":36.29999924,"armature_temperature":-49.90000153}
mos_temperature = 36.299999, armature_temperature = -49.900002

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_control\_position\_mode.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器执行位置控制操作（注意：控制过程中，执行器会转动，建议要把执行器固定好再校准，如果当前位置距离零点较远，执行器会在脚本执行的过程中快速回到零点）。
    
    该脚本执行以下操作：`demo_control_position_mode.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`get_state`函数检索每个检测到的执行器的状态，并显示在终端。
        
    3.  使用`get_config`函数检索每个检测到的执行器的配置，并显示在终端。
        
    4.  使用`get_pvc`函数检索每个检测到的执行器的当前位置、速度和电流 （PVC） 值。
        
    5.  使用`set_position_control`函数将每个检测到的执行器当前控制位置设置为 0.0。
        
    6.  使用`set_enable`函数对每个检测到的执行器进行使能操作，即启动执行器。
        
    7.  使用`set_mode_of_operation`函数对每个检测到的执行器的操作模式切换为位置控制。
        
    8.  使用`set_position_control`函数再次将每个检测到的执行器当前控制位置设置为 0.0。
        
    9.  使用`set_position_control`函数对每一个检测到的执行器进行sin控制。
        
    10.  使用`set_disable`函数对每个检测到的执行器进行失能操作。
        
    11.  最后，使用`set_mode_of_operation`函数对每个检测到的执行器的操作模式切换为位置控制。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_control_position_mode.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_control_position_mode.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_control_position_mode.py
    
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_control_position_mode.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/10/
[2024.10.31 17:35:59.281.834]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/10/
[2024.10.31 17:35:59.282.815]  Info:    FSA start listening for broadcast...
[2024.10.31 17:35:59.282.845]  Info:    FSA start listening for broadcast...


[2024.10.31 17:35:59.285.325]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.10.31 17:36:02.286.731]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.10.31 17:36:02.287.973]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
State = 0


[2024.10.31 17:36:03.288.232]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.10.31 17:36:03.289.532]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":31,"motor_type":4,"motor_hardware_type":3,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}


[2024.10.31 17:36:04.289.931]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.10.31 17:36:04.291.055]  Info:    Received from ('192.168.137.101', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":-0.019138644,"velocity":0.056626827,"current":0}
Position = -0.02, Velocity = 0.057, Current = 0.0000


[2024.10.31 17:36:05.301.525]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/position_control", "reply_enable": true, "position": 0.0, "velocity_ff": 0.0, "current_ff": 0.0}
[2024.10.31 17:36:05.302.895]  Info:    192.168.137.101 : Position = -0.02, Velocity = 0.080, Current = 0.0000 

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_control\_velocity\_mode.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器执行速度控制操作（注意：控制过程中，执行器会转动，建议要把执行器固定好再校准）。
    
    该脚本执行以下操作：`demo_control_velocity_mode.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`get_state`函数检索每个检测到的执行器的状态，并显示在终端。
        
    3.  使用`get_config`函数检索每个检测到的执行器的配置，并显示在终端。
        
    4.  使用`get_pvc`函数检索每个检测到的执行器的当前位置、速度和电流 （PVC） 值。
        
    5.  使用`set_velocity_control`函数将每个检测到的执行器当前控制速度设置为 0.0。
        
    6.  使用`set_enable`函数对每个检测到的执行器进行使能操作，即启动执行器。
        
    7.  使用`set_mode_of_operation`函数对每个检测到的执行器的操作模式切换为速度控制。
        
    8.  使用`set_velocity_control`函数对每一个检测到的执行器进行sin控制。
        
    9.  使用`set_velocity_control`函数再次将每个检测到的执行器当前控制速度设置为 0.0。
        
    10.  使用`set_disable`函数对每个检测到的执行器进行失能操作。
        
    11.  最后，使用`set_mode_of_operation`函数对每个检测到的执行器的操作模式切换为速度控制。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_control_velocity_mode.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_control_velocity_mode.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_control_velocity_mode.py
    
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_control_velocity_mode.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.01 15:22:45.519.533]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.01 15:22:45.520.550]  Info:    FSA start listening for broadcast...
[2024.11.01 15:22:45.520.588]  Info:    FSA start listening for broadcast...


[2024.11.01 15:22:45.523.057]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.01 15:22:48.523.836]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.11.01 15:22:48.525.035]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/state","property":"","state":0}
State = 0


[2024.11.01 15:22:49.525.306]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.11.01 15:22:49.526.559]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":31,"motor_type":4,"motor_hardware_type":3,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}


[2024.11.01 15:22:50.526.846]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.11.01 15:22:50.527.956]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":0,"velocity":0.125966877,"current":0}
Position = 0.00, Velocity = 0.126, Current = 0.0000


[2024.11.01 15:22:51.538.301]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/velocity_control", "reply_enable": true, "velocity": 0.0, "current_ff": 0.0}
[2024.11.01 15:22:51.539.865]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.275, Current = 0.0000 



[2024.11.01 15:22:52.540.111]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 15}
[2024.11.01 15:22:52.541.083]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/control_word","property":""}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_control\_current\_mode.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器执行电流控制操作（注意：控制过程中，执行器会转动，建议要把执行器固定好再校准）。
    
    该脚本执行以下操作：`demo_control_current_mode.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`get_state`函数检索每个检测到的执行器的状态，并显示在终端。
        
    3.  使用`get_config`函数检索每个检测到的执行器的配置，并显示在终端。
        
    4.  使用`get_pvc`函数检索每个检测到的执行器的当前位置、速度和电流 （PVC） 值。
        
    5.  使用`set_current_control`函数将每个检测到的执行器当前控制电流设置为 0.0。
        
    6.  使用`set_mode_of_operation`函数对每个检测到的执行器的操作模式切换为电流控制。
        
    7.  使用`set_enable`函数对每个检测到的执行器进行使能操作，即启动执行器。
        
    8.  使用`set_current_control`函数将每个检测到的执行器当前控制电流设置为 0.0。
        
    9.  使用`set_velocity_control`函数在指定的持续时间内运行电流控制回路，命令恒定电流值，脚本中为0.0。
        
    10.  使用`set_current_control`函数再次函数将每个检测到的执行器当前控制电流设置为 0.0。
        
    11.  使用`set_disable`函数对每个检测到的执行器进行失能操作。
        
    12.  最后，使用`set_mode_of_operation`函数对每个检测到的执行器的操作模式切换为速度控制。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_control_current_mode.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_control_current_mode.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_control_current_mode.py
    
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_control_current_mode.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.01 15:36:31.719.880]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.01 15:36:31.720.913]  Info:    FSA start listening for broadcast...
[2024.11.01 15:36:31.720.942]  Info:    FSA start listening for broadcast...


[2024.11.01 15:36:31.722.233]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.01 15:36:34.723.014]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.11.01 15:36:34.723.904]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/state","property":"","state":2}
State = 2
[2024.11.01 15:36:35.724.152]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.11.01 15:36:35.725.317]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":31,"motor_type":4,"motor_hardware_type":3,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}
[2024.11.01 15:36:36.725.599]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.11.01 15:36:36.726.725]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":-0.000708839,"velocity":-0.029984923,"current":0.020255003}
Position = -0.00, Velocity = -0.030, Current = 0.0203
[2024.11.01 15:36:37.737.073]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:37.738.249]  Info:    192.168.137.93 : Position = -0.00, Velocity = 0.009, Current = 0.0027 

[2024.11.01 15:36:38.738.493]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/mode_of_operation", "mode_of_operation": 4}
[2024.11.01 15:36:38.739.432]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/mode_of_operation","property":null}
[2024.11.01 15:36:39.739.686]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 15}
[2024.11.01 15:36:39.740.656]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/control_word","property":""}
[2024.11.01 15:36:40.740.882]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:40.741.835]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.016, Current = 0.0510 

[2024.11.01 15:36:41.742.110]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.743.343]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.117, Current = 0.0179 

[2024.11.01 15:36:41.743.535]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.744.499]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.117, Current = 0.0179 

[2024.11.01 15:36:41.744.679]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.745.588]  Info:    192.168.137.93 : Position = 0.00, Velocity = 0.058, Current = -0.0019 

[2024.11.01 15:36:41.745.777]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.746.755]  Info:    192.168.137.93 : Position = 0.00, Velocity = 0.075, Current = -0.0326 

[2024.11.01 15:36:41.746.954]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.747.851]  Info:    192.168.137.93 : Position = 0.00, Velocity = 0.075, Current = -0.0326 

[2024.11.01 15:36:41.748.039]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.748.881]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.061, Current = 0.0377 

[2024.11.01 15:36:41.748.987]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.749.717]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.061, Current = 0.0377 

[2024.11.01 15:36:41.749.811]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.750.579]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.167, Current = -0.0105 

[2024.11.01 15:36:41.750.670]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.751.403]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.167, Current = -0.0105 

[2024.11.01 15:36:41.751.492]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.752.254]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.167, Current = -0.0105 

[2024.11.01 15:36:41.752.349]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.753.183]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.107, Current = 0.0116 

[2024.11.01 15:36:41.753.365]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.754.139]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.107, Current = 0.0116 

[2024.11.01 15:36:41.754.244]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.755.118]  Info:    192.168.137.93 : Position = -0.00, Velocity = 0.076, Current = 0.0004 

[2024.11.01 15:36:41.755.212]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.755.979]  Info:    192.168.137.93 : Position = -0.00, Velocity = 0.076, Current = 0.0004 

[2024.11.01 15:36:41.756.069]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.756.844]  Info:    192.168.137.93 : Position = -0.00, Velocity = -0.064, Current = 0.0620 

[2024.11.01 15:36:41.756.937]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.757.659]  Info:    192.168.137.93 : Position = -0.00, Velocity = -0.064, Current = 0.0620 

[2024.11.01 15:36:41.757.746]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.758.518]  Info:    192.168.137.93 : Position = -0.00, Velocity = -0.064, Current = 0.0620 

[2024.11.01 15:36:41.758.603]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.759.346]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.144, Current = -0.0105 

[2024.11.01 15:36:41.759.432]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.760.159]  Info:    192.168.137.93 : Position = 0.00, Velocity = -0.144, Current = -0.0105 

[2024.11.01 15:36:41.760.243]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.761.002]  Info:    192.168.137.93 : Position = 0.00, Velocity = 0.127, Current = 0.0289 

[2024.11.01 15:36:41.761.093]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/current_control", "reply_enable": true, "current": 0.0}
[2024.11.01 15:36:41.761.814]  Info:    192.168.137.93 : Position = 0.00, Velocity = 0.127, Current = 0.0289 

[2024.11.01 15:36:42.761.997]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 6}
[2024.11.01 15:36:42.762.874]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/control_word","property":""}
[2024.11.01 15:36:43.763.089]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/mode_of_operation", "mode_of_operation": 4}
[2024.11.01 15:36:43.763.922]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/mode_of_operation","property":null}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_control\_position\_ff\_mode.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何在位置控制模式下使用前馈值操作 FSA 执行器（注意：控制过程中，执行器会转动，建议要把执行器固定好再校准）。
    
    该脚本执行以下操作：`demo_control_position_ff_mode.py`
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`get_state`函数检索每个检测到的执行器的状态，并显示在终端。
        
    3.  使用`get_config`函数检索每个检测到的执行器的配置，并显示在终端。
        
    4.  使用`get_pvc`函数检索每个检测到的执行器的当前位置、速度和电流 （PVC） 值。
        
    5.  使用`set_position_control`函数将每个检测到的执行器当前控制位置设置为 0.0。
        
    6.  使用`set_enable`函数对每个检测到的执行器进行使能操作，即启动执行器。
        
    7.  使用`set_mode_of_operation`函数对每个检测到的执行器的操作模式切换为位置控制。
        
    8.  使用`set_position_control`函数将每个检测到的执行器当前控制位置设置为 0.0。
        
    9.  使用`set_pid_param_imm`函数设置每个检测到的执行器的pid相关参数(脚本原本参数可能缺少，导致脚本错误)。
        
    10.  使用`set_position_control`函数在指定的持续时间内在位置控制模式下使用前馈值控制执行器运动到固定位置。
        
    11.  使用`set_disable`函数对每个检测到的执行器进行失能操作。
        
    12.  最后，使用`set_mode_of_operation`函数对每个检测到的执行器的操作模式切换为位置控制。
        

**用法：**

要运行该脚本，请执行以下步骤：`demo_control_position_ff_mode.py`

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 FSA SDK。
    
2.  打开终端并导航到包含 的目录。`demo_control_position_ff_mode.py`
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_control_position_ff_mode.py
    
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
len3@len3-System-Product-Name:~/wiki-fsa/v2/example$ python3 ./demo_control_position_ff_mode.py 
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v1
Log Already Existed ./log/2024/11/
[2024.11.02 10:21:05.132.593]  Info:    FSA start listening for broadcast...
current_workspace_path = 
 /home/len3/wiki-fsa/v2/example
config_yaml_path = 
 /home/len3/wiki-fsa/v2/example/config.yaml
#################################
config.yaml is: 
null
...

#################################
/home/len3/anaconda3/lib/python3.11/site-packages/fi_fsa/v2
Log Already Existed ./log/2024/11/
[2024.11.02 10:21:05.133.605]  Info:    FSA start listening for broadcast...
[2024.11.02 10:21:05.133.636]  Info:    FSA start listening for broadcast...


[2024.11.02 10:21:05.135.189]  Info:    Received from ('192.168.137.93', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"8C506D144B8C","driver_version":"0.1.10.7","firmware_version":"0.2.15.5","connect_mode":"ETH","mac_address":"8C:4B:14:6D:50:8F","ip_address":"192.168.137.93","IP":"192.168.137.93"}


found servers
['192.168.137.93']
lookup Finished! 

[2024.11.02 10:21:08.136.629]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/state", "property": ""}
[2024.11.02 10:21:08.137.728]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/state","property":"","state":2}
State = 2


[2024.11.02 10:21:09.138.033]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/config", "property": ""}
[2024.11.02 10:21:09.139.294]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/config","property":"","actuator_type":1,"actuator_direction":1,"actuator_reduction_ratio":31,"motor_type":4,"motor_hardware_type":3,"motor_vbus":48,"motor_direction":1,"motor_max_speed":3000,"motor_max_acceleration":60000,"motor_max_current":100}


[2024.11.02 10:21:10.139.573]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/measured", "position": true, "velocity": true, "current": true}
[2024.11.02 10:21:10.140.701]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/measured","property":null,"position":38.13693619,"velocity":0.070324488,"current":0.361414254}
Position = 38.14, Velocity = 0.070, Current = 0.3614


[2024.11.02 10:21:11.151.098]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/position_control", "reply_enable": true, "position": 0.0, "velocity_ff": 0.0, "current_ff": 0.0}
[2024.11.02 10:21:11.152.463]  Info:    192.168.137.93 : Position = 38.14, Velocity = 0.045, Current = 0.3907 



[2024.11.02 10:21:12.152.767]  Info:    Send JSON Obj: {"method": "SET", "reqTarget": "/control_word", "property": "", "control_word": 15, "reply_enable": true}
[2024.11.02 10:21:12.153.852]  Info:    Received from ('192.168.137.93', 2333):{"status":"OK","reqTarget":"/control_word","property":""}

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_enable.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器执行使能操作，即启动执行器。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_enable`函数为每个执行器执行使能操作。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_enable.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
current_workspace_path = 
 D:\1_work\4_fsa\wiki-fsa\v2\example
config_yaml_path = 
 D:\1_work\4_fsa\wiki-fsa\v2\example/config.yaml
#################################
config.yaml is: 
null
...

#################################
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v1
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v1\log\2024\11\
[2024.11.02 15:26:23.014.914]  Info:    FSA start listening for broadcast...
current_workspace_path =
 D:\1_work\4_fsa\wiki-fsa\v2\example
config_yaml_path =
 D:\1_work\4_fsa\wiki-fsa\v2\example/config.yaml
#################################
config.yaml is:
null
...

#################################
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.02 15:26:23.021.752]  Info:    FSA start listening for broadcast...
[2024.11.02 15:26:23.021.752]  Info:    FSA start listening for broadcast...


[2024.11.02 15:26:23.023.751]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished!

[2024.11.02 15:26:26.034.276]  Info:    192.168.137.101 : Send Data: b'\x01'
PS D:\1_work\4_fsa\wiki-fsa\v2\example> 
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_ack\_enable.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器执行使能操作，即启动执行器。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_ack_enable`函数为每个执行器执行使能操作。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_ack_enable.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.07 18:58:32.576.429]  Info:    FSA start listening for broadcast...
[2024.12.07 18:58:32.576.429]  Info:    FSA start listening for broadcast...


[2024.12.07 18:58:32.578.420]  Info:    Received from ('192.168.137.90', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.16","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.90","IP":"192.168.137.90"}


found servers
['192.168.137.90']
lookup Finished! 

[2024.12.07 18:58:35.584.321]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.07 18:58:35.586.593]  Info:    192.168.137.90 : Send Data: b'Q\x00\x00\x00\x01'
[2024.12.07 18:58:35.587.593]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'Q\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_disable.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器执行失能操作。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_disable`函数为每个执行器执行失能操作。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_disable.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
current_workspace_path = 
 D:\1_work\4_fsa\wiki-fsa\v2\example
config_yaml_path = 
 D:\1_work\4_fsa\wiki-fsa\v2\example/config.yaml
#################################
config.yaml is: 
null
...

#################################
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v1
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v1\log\2024\11\
[2024.11.02 16:02:52.974.325]  Info:    FSA start listening for broadcast...
current_workspace_path =
 D:\1_work\4_fsa\wiki-fsa\v2\example
config_yaml_path =
 D:\1_work\4_fsa\wiki-fsa\v2\example/config.yaml
#################################
config.yaml is:
null
...

#################################
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.02 16:02:52.980.326]  Info:    FSA start listening for broadcast...
[2024.11.02 16:02:52.980.326]  Info:    FSA start listening for broadcast...


[2024.11.02 16:02:52.983.342]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.9.9","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished!

[2024.11.02 16:02:55.996.504]  Info:    192.168.137.101 : Send Data: b'\x02'
[2024.11.02 16:02:56.196.948]  Info:    192.168.137.101 : Send Data: b'\x02'
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_ack\_disable.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器执行失能操作。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_ack_disable`函数为每个执行器执行失能操作。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_ack_disable.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.07 19:01:04.581.537]  Info:    FSA start listening for broadcast...
[2024.12.07 19:01:04.581.537]  Info:    FSA start listening for broadcast...


[2024.12.07 19:01:04.583.543]  Info:    Received from ('192.168.137.90', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.16","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.90","IP":"192.168.137.90"}


found servers
['192.168.137.90']
lookup Finished! 

[2024.12.07 19:01:07.590.611]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.07 19:01:07.592.850]  Info:    192.168.137.90 : Send Data: b'R\x00\x00\x00\x00'
[2024.12.07 19:01:07.593.850]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'R\x00\x00\x00\x00\x00\x00\x00\x00'
cnt = 0, res = 0
[2024.12.07 19:01:07.794.760]  Info:    192.168.137.90 : Send Data: b'R\x00\x00\x00\x01'
[2024.12.07 19:01:07.794.760]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'R\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_clear\_fault.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器的错误码进行清除操作。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_clear_fault`函数为每个执行器执行使能操作。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_clear_fault.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_ack\_clear\_fault.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何对执行器的错误码进行清除操作。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_ack_clear_fault`函数为每个执行器执行使能操作。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_ack_clear_fault.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.07 19:02:37.874.117]  Info:    FSA start listening for broadcast...
[2024.12.07 19:02:37.874.117]  Info:    FSA start listening for broadcast...


[2024.12.07 19:02:37.875.117]  Info:    Received from ('192.168.137.90', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.16","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.90","IP":"192.168.137.90"}


found servers
['192.168.137.90']
lookup Finished! 

[2024.12.07 19:02:40.878.294]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.07 19:02:40.880.801]  Info:    192.168.137.90 : Send Data: b'S\x00\x00\x00\x00'
[2024.12.07 19:02:40.880.801]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'S\x00\x00\x00\x00\x00\x00\x00\x00'
cnt = 0, res = 0
[2024.12.07 19:02:41.082.033]  Info:    192.168.137.90 : Send Data: b'S\x00\x00\x00\x01'
[2024.12.07 19:02:41.082.537]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'S\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
[2024.12.07 19:02:41.283.158]  Info:    192.168.137.90 : Send Data: b'S\x00\x00\x00\x02'
[2024.12.07 19:02:41.283.158]  Info:    192.168.137.90: Server received from ('192.168.137.90', 2335):b'S\x00\x00\x00\x02\x00\x00\x00\x00'
cnt = 2, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_pd\_position.py 
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器在pd模式下的位置，前馈速度，前馈电流。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_pd_control`函数为每个执行器设置目标位置。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_pd_position.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.16 20:16:32.148.634]  Info:    FSA start listening for broadcast...
[2024.11.16 20:16:32.148.634]  Info:    FSA start listening for broadcast...


[2024.11.16 20:16:32.150.634]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.16 20:16:35.152.065]  Info:    192.168.137.54 : Send Data: b'\x0e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_ack\_pd\_position.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器在pd模式下的位置，前馈速度，前馈电流。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_ack_pd_control`函数为每个执行器设置目标位置。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_ack_pd_position.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.28 19:19:03.716.108]  Info:    FSA start listening for broadcast...
[2024.12.28 19:19:03.716.108]  Info:    FSA start listening for broadcast...


[2024.12.28 19:19:03.720.105]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.28 19:19:06.723.440]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.28 19:19:06.726.460]  Info:    192.168.137.101 : Send Data: b'^\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
[2024.12.28 19:19:06.727.465]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'^\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_pid\_imm.py 
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置临时执行器pid参数。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_pid_imm`函数为每个执行器设置临时pid参数。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_pid_imm.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.16 20:55:45.824.959]  Info:    FSA start listening for broadcast...
[2024.11.16 20:55:45.824.959]  Info:    FSA start listening for broadcast...


[2024.11.16 20:55:45.826.937]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.16 20:55:48.828.571]  Info:    192.168.137.54 : Send Data: b'\xa0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_ack\_pid\_imm.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置临时执行器pid参数。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_ack_pid_imm`函数为每个执行器设置临时pid参数。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_ack_pid_imm.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.28 19:32:48.238.072]  Info:    FSA start listening for broadcast...
[2024.12.28 19:32:48.238.072]  Info:    FSA start listening for broadcast...


[2024.12.28 19:32:48.239.072]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.28 19:32:51.248.922]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.28 19:32:51.251.647]  Info:    192.168.137.101 : Send Data: b'`\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
[2024.12.28 19:32:51.252.518]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'`\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_pd\_imm.py 
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器临时执行器pd参数。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_pd_imm`函数为每个执行器设置临时pd参数。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_pd_imm.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.16 21:22:10.542.682]  Info:    FSA start listening for broadcast...
[2024.11.16 21:22:10.542.682]  Info:    FSA start listening for broadcast...


[2024.11.16 21:22:10.544.719]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.16 21:22:13.548.673]  Info:    192.168.137.54 : Send Data: b'\xa1\x00\x00\x00\x00\x00\x00\x00\x00'
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_ack\_pd\_imm.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器临时执行器pd参数。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_ack_pd_imm`函数为每个执行器设置临时pd参数。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_ack_pd_imm.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.28 20:03:49.607.938]  Info:    FSA start listening for broadcast...
[2024.12.28 20:03:49.607.938]  Info:    FSA start listening for broadcast...


[2024.12.28 20:03:49.609.939]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.28 20:03:52.625.572]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.28 20:03:52.627.924]  Info:    192.168.137.101 : Send Data: b'a\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00'
[2024.12.28 20:03:52.628.906]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'a\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_control\_loop\_freq\_div.py 
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器控制频率分频系数。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_control_loop_freq_div`函数为每个执行器设置控制频率分频系数。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_control_loop_freq_div.py 
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.30 11:42:41.285.564]  Info:    FSA start listening for broadcast...
[2024.12.30 11:42:41.285.564]  Info:    FSA start listening for broadcast...


[2024.12.30 11:42:41.288.548]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 11:42:44.299.396]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 11:42:44.301.675]  Info:    192.168.137.101 : Send Data: b'f\x00\x00\x00\x01F\x1c@\x00F\x1c@\x00F\x1c@\x00'
[2024.12.30 11:42:44.302.658]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'f\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_ack\_control\_loop\_freq\_div.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何设置执行器控制频率分频系数。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_ack_control_loop_freq_div`函数为每个执行器设置控制频率分频系数。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_ack_control_loop_freq_div.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.28 20:09:53.279.328]  Info:    FSA start listening for broadcast...
[2024.12.28 20:09:53.279.328]  Info:    FSA start listening for broadcast...


[2024.12.28 20:09:53.281.961]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.28 20:09:56.292.176]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.28 20:09:56.294.479]  Info:    192.168.137.101 : Send Data: b'b\x00\x00\x00\x01?\x80\x00\x00?\x80\x00\x00?\x80\x00\x00'
[2024.12.28 20:09:56.295.477]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'b\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_friction\_FFD.py 
    
    **代码****说明：**
    
    该脚本主要用于演示如何配置执行器摩擦补偿。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_friction_FFD`函数为每个执行器配置摩擦补偿。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_friction_FFD.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.16 21:57:14.094.351]  Info:    FSA start listening for broadcast...
[2024.11.16 21:57:14.094.351]  Info:    FSA start listening for broadcast...


[2024.11.16 21:57:14.097.036]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.16 21:57:17.100.794]  Info:    192.168.137.54 : Send Data: b'\xa3\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
[2024.11.16 21:57:17.101.654]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\xa3'
b'\xa3'
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_ack\_friction\_FFD.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何配置执行器摩擦补偿。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_ack_friction_FFD`函数为每个执行器配置摩擦补偿。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_ack_friction_FFD.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.28 20:21:45.749.986]  Info:    FSA start listening for broadcast...
[2024.12.28 20:21:45.749.986]  Info:    FSA start listening for broadcast...


[2024.12.28 20:21:45.753.017]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.28 20:21:48.755.818]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.28 20:21:48.758.848]  Info:    192.168.137.101 : Send Data: b'c\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00?\x80\x00\x00'
[2024.12.28 20:21:48.759.832]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'c\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_ack\_setpvc\_timeout\_protect.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何配置执行器setpvc超时保护。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_ack_setpvc_timeout_protect`函数为每个执行器设置setpvc超时保护。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_ack_setpvc_timeout_protect.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.30 09:54:12.954.932]  Info:    FSA start listening for broadcast...
[2024.12.30 09:54:12.954.932]  Info:    FSA start listening for broadcast...


[2024.12.30 09:54:12.957.931]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 09:54:15.974.027]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
1
[2024.12.30 09:54:15.976.050]  Info:    192.168.137.101 : Send Data: b'd\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00d\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x01'
[2024.12.30 09:54:15.977.031]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'd\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_ack\_interface\_filter\_fc.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何配置执行器反馈pvc的滤波截止频率。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_ack_interface_filter_fc`函数为每个执行器配置反馈pvc的滤波截止频率。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_ack_setpvc_timeout_protect.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.30 09:54:12.954.932]  Info:    FSA start listening for broadcast...
[2024.12.30 09:54:12.954.932]  Info:    FSA start listening for broadcast...


[2024.12.30 09:54:12.957.931]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 09:54:15.974.027]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
1
[2024.12.30 09:54:15.976.050]  Info:    192.168.137.101 : Send Data: b'd\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00d\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x01'
[2024.12.30 09:54:15.977.031]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'd\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_set\_ack\_setpvc\_protect\_clear.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何配置执行器setpvc保护状态清除。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_set_ack_setpvc_protect_clear`函数为每个执行器配置setpvc保护状态清除。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_set_ack_setpvc_protect_clear.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.30 13:28:16.443.834]  Info:    FSA start listening for broadcast...
[2024.12.30 13:28:16.443.834]  Info:    FSA start listening for broadcast...


[2024.12.30 13:28:16.446.812]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 13:28:19.454.411]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
1
[2024.12.30 13:28:19.457.445]  Info:    192.168.137.101 : Send Data: b'e\x00\x00\x00\x01\x00\x00\x00\x00'
[2024.12.30 13:28:19.458.425]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'e\x00\x00\x00\x01\x00\x00\x00\x00'
cnt = 1, res = 0
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_get\_pvc.py 
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器当前的位置、速度、电流。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_get_pvc`函数获取执行器当前的位置、速度、电流。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_get_pvc.py 
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.18 14:21:43.399.693]  Info:    FSA start listening for broadcast...
[2024.11.18 14:21:43.399.693]  Info:    FSA start listening for broadcast...


[2024.11.18 14:21:43.402.695]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.18 14:21:46.404.556]  Info:    192.168.137.54 : Send Data: b'\x1a'
[2024.11.18 14:21:46.405.062]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1a@\x16\x04l=\xb5\xdf\x98\x00\x00\x00\x00'
Position = 2.344020, Velocity = 0.088805, Current = 0.0000
[2024.11.18 14:21:46.407.569]  Info:    192.168.137.54 : Send Data: b'\x1a'
[2024.11.18 14:21:46.407.569]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1a@\x15\xff\xfe\xbd9;\x1d\x00\x00\x00\x00'
Position = 2.343750, Velocity = -0.045222, Current = 0.0000
[2024.11.18 14:21:46.410.396]  Info:    192.168.137.54 : Send Data: b'\x1a'
[2024.11.18 14:21:46.410.396]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1a@\x16\x03\xdb\xbe\x10\x96\x1e\x00\x00\x00\x00'
Position = 2.343985, Velocity = -0.141198, Current = 0.0000
[2024.11.18 14:21:46.413.121]  Info:    192.168.137.54 : Send Data: b'\x1a'
[2024.11.18 14:21:46.413.121]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1a@\x16\x00\xef\xbd\xa4\xaa|\x00\x00\x00\x00'
Position = 2.343807, Velocity = -0.080403, Current = 0.0000
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_get\_foc\_target\_pvc.py 
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器底层FOC的目标的位置、速度、电流信息。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_get_foc_target_pvc`函数获取执行器底层FOC的目标的位置、速度、电流信息。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_get_foc_target_pvc.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.18 14:36:08.385.112]  Info:    FSA start listening for broadcast...
[2024.11.18 14:36:08.385.112]  Info:    FSA start listening for broadcast...


[2024.11.18 14:36:08.387.111]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.18 14:36:11.394.328]  Info:    192.168.137.54 : Send Data: b'\x1f'
[2024.11.18 14:36:11.394.328]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Position = 0.000000, Velocity = 0.000000, Current = 0.0000
[2024.11.18 14:36:11.595.690]  Info:    192.168.137.54 : Send Data: b'\x1f'
[2024.11.18 14:36:11.595.690]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Position = 0.000000, Velocity = 0.000000, Current = 0.0000
[2024.11.18 14:36:11.796.942]  Info:    192.168.137.54 : Send Data: b'\x1f'
[2024.11.18 14:36:11.796.942]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Position = 0.000000, Velocity = 0.000000, Current = 0.0000
[2024.11.18 14:36:11.997.908]  Info:    192.168.137.54 : Send Data: b'\x1f'
[2024.11.18 14:36:11.997.908]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Position = 0.000000, Velocity = 0.000000, Current = 0.0000

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_get\_pvct.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器当前的位置、速度、电流、力矩。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_get_pvct`函数获取执行器当前的位置、速度、电流、力矩。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_get_pvct.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.18 14:43:15.402.617]  Info:    FSA start listening for broadcast...
[2024.11.18 14:43:15.402.617]  Info:    FSA start listening for broadcast...


[2024.11.18 14:43:15.405.755]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.18 14:43:18.412.669]  Info:    192.168.137.54 : Send Data: b'\x1d'
[2024.11.18 14:43:18.412.669]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1d@\x16\x04s>\x8a\xc5\xc3\x00\x00\x00\x00\xbd\xfd\xa6\xa0'
Position = 2.344022, Velocity = 0.271040, Current = 0.000000, Torque = -0.123853
[2024.11.18 14:43:18.614.096]  Info:    192.168.137.54 : Send Data: b'\x1d'
[2024.11.18 14:43:18.614.606]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1d@\x16\x01\x92\xbd4\x8a:\x00\x00\x00\x00\xb9%d)'
Position = 2.343846, Velocity = -0.044077, Current = 0.000000, Torque = -0.000158
[2024.11.18 14:43:18.815.447]  Info:    192.168.137.54 : Send Data: b'\x1d'
[2024.11.18 14:43:18.815.447]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1d@\x15\xfei>\x02;\x8d\x00\x00\x00\x00=\xe1\xedk'
Position = 2.343653, Velocity = 0.127180, Current = 0.000000, Torque = 0.110316
[2024.11.18 14:43:19.016.410]  Info:    192.168.137.54 : Send Data: b'\x1d'
[2024.11.18 14:43:19.016.410]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1d@\x16\x05\xbb\xbe\x808(\x00\x00\x00\x00=i\xca\xd4'
Position = 2.344100, Velocity = -0.250428, Current = 0.000000, Torque = 0.057078
[2024.11.18 14:43:19.217.864]  Info:    192.168.137.54 : Send Data: b'\x1d'
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_get\_error.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器错误码。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_get_error`函数获取执行器错误码。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_get_error.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\11\
[2024.11.18 14:48:32.067.444]  Info:    FSA start listening for broadcast...
[2024.11.18 14:48:32.067.444]  Info:    FSA start listening for broadcast...


[2024.11.18 14:48:32.069.443]  Info:    Received from ('192.168.137.54', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA-0","serial_number":"F0BE83CD31E8","driver_version":"0.2.9.1","firmware_version":"0.3.12.3","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.54","IP":"192.168.137.54"}


found servers
['192.168.137.54']
lookup Finished! 

[2024.11.18 14:48:35.080.749]  Info:    192.168.137.54 : Send Data: b'\x1b'
[2024.11.18 14:48:35.081.520]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1b\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Error =[16, 0, 0, 0, 0, 0, 0, 0]
[2024.11.18 14:48:35.282.117]  Info:    192.168.137.54 : Send Data: b'\x1b'
[2024.11.18 14:48:35.282.117]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1b\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Error =[16, 0, 0, 0, 0, 0, 0, 0]
[2024.11.18 14:48:35.483.065]  Info:    192.168.137.54 : Send Data: b'\x1b'
[2024.11.18 14:48:35.483.065]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1b\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Error =[16, 0, 0, 0, 0, 0, 0, 0]
[2024.11.18 14:48:35.683.977]  Info:    192.168.137.54 : Send Data: b'\x1b'
[2024.11.18 14:48:35.683.977]  Info:    192.168.137.54: Server received from ('192.168.137.54', 2335):b'\x1b\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
Error =[16, 0, 0, 0, 0, 0, 0, 0]
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_get\_pvct\_error.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器位置、速度、电流、力矩，错误码。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_get_pvct_error`函数获取执行器位置、速度、电流、力矩，错误码。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_get_pvct_error.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.30 14:03:31.306.617]  Info:    FSA start listening for broadcast...
[2024.12.30 14:03:31.306.617]  Info:    FSA start listening for broadcast...


[2024.12.30 14:03:31.309.616]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 14:03:34.321.228]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 14:03:34.323.525]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:34.324.506]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!\xbc\xa9[\xe6\xc2\x83\xe0\x90\x80\x00\x00\x00:\x05.<\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = -0.020674, Velocity = -65.938599, Current = -0.000000, Torque = 0.000508
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:34.525.921]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:34.525.921]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!\xbcDH\xdd\xc1\xe1\xd2c\x80\x00\x00\x00\xb9\x85H\x97\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = -0.011980, Velocity = -28.227728, Current = -0.000000, Torque = -0.000254
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:34.727.323]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:34.727.323]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!\xbc?O\xa8\xc2\xa6gY\x80\x00\x00\x00\xba\x18\xceN\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = -0.011677, Velocity = -83.201851, Current = -0.000000, Torque = -0.000583
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:34.928.815]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:34.928.815]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!<\xb4IU@\xf9\x05\x06\x80\x00\x00\x00\xba\xbb3)\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = 0.022008, Velocity = 7.781863, Current = -0.000000, Torque = -0.001428
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:35.130.164]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:35.131.181]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!=04%C\x066l\x80\x00\x00\x00\xba<\t6\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = 0.043018, Velocity = 134.212585, Current = -0.000000, Torque = -0.000717
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:35.331.343]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:35.331.343]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!=\x1f\x7f\xd3C\x056F\x80\x00\x00\x008\xbfH}\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = 0.038940, Velocity = 133.212006, Current = -0.000000, Torque = 0.000091
Error =[16, 1, 0, 0, 0, 0, 0, 1]
[2024.12.30 14:03:35.532.835]  Info:    192.168.137.101 : Send Data: b'!'
[2024.12.30 14:03:35.532.835]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'!\xbd,N&\xc2\xdb\xe2\x8c\x80\x00\x00\x00:\x07\xd8H\x00\x00\x00\x10\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01'
Position = -0.042067, Velocity = -109.942474, Current = -0.000000, Torque = 0.000518
Error =[16, 1, 0, 0, 0, 0, 0, 1]
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_get\_friction\_FFD.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器错误码。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_get_friction_FFD`函数获取执行器错误码。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_get_friction_FFD.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.30 14:11:39.890.762]  Info:    FSA start listening for broadcast...
[2024.12.30 14:11:39.890.762]  Info:    FSA start listening for broadcast...


[2024.12.30 14:11:39.892.818]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 14:11:42.904.089]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 14:11:42.906.294]  Info:    192.168.137.101 : Send Data: b' '
[2024.12.30 14:11:42.910.311]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b' \x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
friction_FFD_SET=0, friction_FFD_DeadSpeedK=0.000000, friction_FFD_DeadSpeed=0.000000, friction_FFD_Fs=0.000000,friction_FFD_Fc=0.000000, friction_FFD_B=0.000000, friction_FFD_percent=0.000000

```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_get\_ntc\_temp.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器MOS，绕组温度。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_get_ntc_temp`函数获取执行器MOS，绕组温度。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_get_ntc_temp.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
Log Already Existed C:\Users\whl\AppData\Local\Programs\Python\Python312\Lib\site-packages\fi_fsa\v2\log\2024\12\
[2024.12.30 14:15:54.654.751]  Info:    FSA start listening for broadcast...
[2024.12.30 14:15:54.654.751]  Info:    FSA start listening for broadcast...


[2024.12.30 14:15:54.656.755]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 14:15:57.658.234]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 14:15:57.660.566]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:57.661.547]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf5\x99\x9a\xc2G\x99\x9a'
mos_temperature = 30.700001, armature_temperature = -49.900002
[2024.12.30 14:15:57.862.809]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:57.863.813]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf5\x99\x9a\xc2G\x99\x9a'
mos_temperature = 30.700001, armature_temperature = -49.900002
[2024.12.30 14:15:58.064.968]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:58.064.968]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf5\x99\x9a\xc2G\x99\x9a'
mos_temperature = 30.700001, armature_temperature = -49.900002
[2024.12.30 14:15:58.266.119]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:58.266.119]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf6ff\xc2G\x99\x9a'
mos_temperature = 30.799999, armature_temperature = -49.900002
[2024.12.30 14:15:58.467.551]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:58.467.551]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf6ff\xc2G\x99\x9a'
mos_temperature = 30.799999, armature_temperature = -49.900002
[2024.12.30 14:15:58.668.558]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:58.668.558]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf5\x99\x9a\xc2G\x99\x9a'
mos_temperature = 30.700001, armature_temperature = -49.900002
[2024.12.30 14:15:58.869.813]  Info:    192.168.137.101 : Send Data: b'"'
[2024.12.30 14:15:58.869.813]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'"A\xf5\x99\x9a\xc2G\x99\x9a'
mos_temperature = 30.700001, armature_temperature = -49.900002
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。
    
    ## demo\_fast\_get\_vbus.py
    
    **代码****说明：**
    
    该脚本主要用于演示如何获取执行器母线电压。
    
    该脚本执行以下操作：
    
    1.  使用`broadcast_func_with_filter`函数发现网络上的 FSA 执行器，并根据执行器类型进行筛选
        
    2.  使用`fast_get_vbus`函数获取执行器母线电压。
        

**用法：**

要运行该脚本，请执行以下步骤：

1.  确保您已按照快速入门指南中所述设置 Python 环境并安装了 fi\_fsa。
    
2.  打开终端并导航到包含此脚本的目录。
    
3.  使用以下命令运行脚本：
    
    ```plaintext
    python demo_fast_get_vbus.py
    ```
    
4.  运行结果（实际运行可能和演示有不符合的地方，比如ip等信息）：
    

```python
[2024.12.30 14:18:38.501.453]  Info:    FSA start listening for broadcast...
[2024.12.30 14:18:38.501.453]  Info:    FSA start listening for broadcast...


[2024.12.30 14:18:38.503.451]  Info:    Received from ('192.168.137.101', 2334):{"status":"OK","reqTarget":"/broadcast","property":"reply","type":"Actuator","model":"","name":"FSA","serial_number":"F0BE83CD31E8","driver_version":"0.2.10.11","firmware_version":"0.3.12.17","connect_mode":"ETH","mac_address":"E8:31:CD:83:BE:F3","ip_address":"192.168.137.101","IP":"192.168.137.101"}


found servers
['192.168.137.101']
lookup Finished! 

[2024.12.30 14:18:41.513.599]  Info:    Send JSON Obj: {"method": "GET", "reqTarget": "/", "property": ""}
[2024.12.30 14:18:41.515.612]  Info:    192.168.137.101 : Send Data: b'#'
[2024.12.30 14:18:41.516.611]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'#@\x84f\x00'
vbus = 4.137451
[2024.12.30 14:18:41.717.842]  Info:    192.168.137.101 : Send Data: b'#'
[2024.12.30 14:18:41.717.842]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'#@\x86^\x00'
vbus = 4.198975
[2024.12.30 14:18:41.918.814]  Info:    192.168.137.101 : Send Data: b'#'
[2024.12.30 14:18:41.918.814]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'#@\x84\xe4\x00'
vbus = 4.152832
[2024.12.30 14:18:42.120.281]  Info:    192.168.137.101 : Send Data: b'#'
[2024.12.30 14:18:42.120.905]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'#@\x84f\x00'
vbus = 4.137451
[2024.12.30 14:18:42.321.550]  Info:    192.168.137.101 : Send Data: b'#'
[2024.12.30 14:18:42.321.550]  Info:    192.168.137.101: Server received from ('192.168.137.101', 2335):b'#@\x86^\x00'
vbus = 4.198975
```

**常见问题****：**

如果您在运行此脚本时遇到任何问题，请考虑以下事项：

1.  确保您按照快速入门指南中的建议使用兼容的 Python 版本。
    
2.  验证您的网络配置是否正确，并且 FSA 执行器可以访问。