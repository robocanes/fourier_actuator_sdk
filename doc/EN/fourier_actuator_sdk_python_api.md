# Actuator Python Script API Documentation

The unit descriptions of the relevant physical quantities mentioned in the following text are as follows:
| Data Type | Unit |
| --- | --- |
| Position | Degrees (angular) |
| Velocity | Degrees/second (angular) |
| Current | A |
| Torque | N·m |

## comm Interface

### get\_comm\_root(server\_ip)

The corresponding Python script demo for this function is[`demo_lookup.py`](fourier_actuator_sdk_python_demo.md#demo_lookuppy)

**Function Description:**

| Function | Get the basic properties of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | All basic properties of the corresponding actuator, including serial number, network configuration, etc., type: dict. |

### get\_comm\_driver\_version(server\_ip)

The corresponding Python script demo for this function is[`demo_comm_driver_firmware_version_get.py`](fourier_actuator_sdk_python_demo.md#demo_comm_driver_firmware_version_getpy)

**Function Description:**

| Function | Get the driver firmware version of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Driver firmware version of the corresponding actuator, type: str. |

### get\_comm\_firmware\_version(server\_ip)

The corresponding Python script demo for this function is[`demo_comm_driver_firmware_version_get.py`](fourier_actuator_sdk_python_demo.md#demo_comm_driver_firmware_version_getpy)

**Function Description:**

| Function | Get the communication firmware version of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Communication firmware version of the corresponding actuator, type: str. |

### get\_comm\_config(server\_ip)

The corresponding Python script demo for this function is[`demo_comm_config_get.py`](fourier_actuator_sdk_python_demo.md#demo_comm_config_getpy)

| Function | Get the config properties of the actuator (will print the actuator's config properties in the terminal) |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the operation was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### set\_comm\_config(server\_ip, dict)

The corresponding Python script demo for this function is[`demo_comm_config_set.py`](fourier_actuator_sdk_python_demo.md#demo_comm_config_setpy)

| Function | Set the actuator's config properties |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**dict：** Config configuration parameters. Details are shown in the table below |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

| Config Configuration Parameters | Type | Description | Recommended Value |
| --- | --- | --- | --- |
| **name** | str | Actuator name | "Name of the currently connected actuator" |
| **DHCP\_enable** | bool | Whether to enable DHCP, it is recommended to disable DHCP (when enabled, IP will be automatically assigned) | False |
| **SSID** | str | WiFi name to connect to, only used for wireless OTA when wired connection is unavailable during OTA upgrade (only V1 actuators support wireless OTA) | "WiFi name of available wireless network in current network environment" |
| **password** | str | WiFi password to connect to, only used for wireless OTA when wired connection is unavailable during OTA upgrade (only V1 actuators support wireless OTA) | "WiFi password of available wireless network in current network environment" |
| **static\_IP** | list | Static IP, the actuator's own IP | IP address to be set for the currently connected actuator |
| **gateway** | list | Gateway | \[192,168,137,1\] |
| **subnet\_mask** | list | Subnet mask | \[255,255,255,0\] |
| **dns\_1** | list | Primary DNS server address, only used during OTA upgrade | \[114,114,114,114\] |
| **dns\_2** | list | Secondary DNS server address, only used during OTA upgrade | \[8,8,8,8\] |

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

This function is basically used in all Python scripts.

| Function | Broadcast query all Fourier self-developed devices on the local network |
| --- | --- |
| Parameters | None |
| Return Value | **address\_list**： All found Fourier self-developed device IPs, type: list |

### broadcast\_func\_with\_filter(filter\_type)

This function is used in most Python scripts.

| Function | Broadcast query all qualified Fourier self-developed devices on the local network |
| --- | --- |
| Parameters | **filter\_type：** Filter actuator category, type: str, options include Actuator, AbsEncoder, CtrlBox. |
| Return Value | All found qualified Fourier self-developed device IPs, type: list |

<a id="set_subscribe"></a>

### set\_subscribe(server\_ip, cfg\_dict)

The corresponding Python script demo for this function is[`demo_set_subscribe.py`](fourier_actuator_sdk_python_demo.md#demo_set_subscribepy)

| Function | Subscribe interface, selectively send actuator data to a specified port |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cfg\_dict：**  Subscribe configuration parameters, type: dict. Details are shown below |
| Return Value | None return value |

| Subscribe Configuration Parameters | Type | Description | Recommended Value |
| --- | --- | --- | --- |
| **port** | int | Target port number for the actuator to send data to PC | Port on the current computer |
| **enable** | int | Whether to send, 0 means not send, 1 means send | 1 |
| **position** | int | Whether to send position, 0 means not send, 1 means send | 1 |
| **velocity** | int | Whether to send velocity, 0 means not send, 1 means send | 1 |
| **current** | int | Whether to send current, 0 means not send, 1 means send | 1 |
| **torque** | int | Whether to send torque, 0 means not send, 1 means send | 1 |
| **error** | int | Whether to send error code, 0 means not send, 1 means send | 1 |
| **error\_ext2** | int | Whether to send extended error code2, 0 means not send, 1 means send | 1 |
| **error\_ext3** | int | Whether to send extended error code3, 0 means not send, 1 means send | 1 |
| **error\_ext4** | int | Whether to send extended error code4, 0 means not send, 1 means send | 1 |
| **error\_ext5** | int | Whether to send extended error code5, 0 means not send, 1 means send | 1 |
| **error\_ext6** | int | Whether to send extended error code6, 0 means not send, 1 means send | 1 |
| **error\_ext7** | int | Whether to send extended error code7, 0 means not send, 1 means send | 1 |
| **error\_ext8** | int | Whether to send extended error code8, 0 means not send, 1 means send | 1 |

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

The corresponding Python script demo for this function is[`demo_ota.py`](fourier_actuator_sdk_python_demo.md#demo_otapy)

| Function | Perform communication OTA upgrade on the actuator, upgrade version is production. |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | None return value |

### ota\_test(server\_ip)

The corresponding Python script demo for this function is[`demo_ota_test.py`](fourier_actuator_sdk_python_demo.md#demo_ota_testpy)

| Function | Perform communication OTA upgrade on the actuator, upgrade version is test. |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | None return value |

### ota\_devel(server\_ip)

The corresponding Python script demo for this function is[`demo_ota_devel.py`](fourier_actuator_sdk_python_demo.md#demo_ota_develpy)

| Function | Perform communication OTA upgrade on the actuator, upgrade version is development. |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | None return value |

### ota\_cloud(server\_ip)

The corresponding Python script demo for this function is[`demo_ota_cloud.py`](fourier_actuator_sdk_python_demo.md#demo_ota_cloudpy)

| Function | Perform communication OTA upgrade on the actuator, upgrade version is cloud. |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | None return value |

### ota\_custom(server\_ip, version\_str)

The corresponding Python script demo for this function is[`demo_ota_custom.py`](fourier_actuator_sdk_python_demo.md#demo_ota_custompy)

| Function | Perform communication OTA upgrade on the actuator, upgrade version is custom. |
| --- | --- |
| Parameters | **server\_ip：** actuator IP, type: str<br>**version\_str：** Version number to upgrade, type: str |
| Return Value | None return value |

### ota\_driver(server\_ip)

The corresponding Python script demo for this function is[`demo_ota_driver.py`](fourier_actuator_sdk_python_demo.md#demo_ota_driverpy)

| Function | Perform driver OTA upgrade on the actuator, upgrade version is production. |
| --- | --- |
| Parameters | **server\_ip：** actuator IP, type: str |
| Return Value | None return value |

### ota\_driver\_test(server\_ip)

The corresponding Python script demo for this function is[`demo_ota_driver_test.py`](fourier_actuator_sdk_python_demo.md#demo_ota_driver_testpy)

| Function | Perform driver OTA upgrade on the actuator, upgrade version is test. |
| --- | --- |
| Parameters | **server\_ip：** actuator IP, type: str |
| Return Value | None return value |

### ota\_driver\_devel(server\_ip)

The corresponding Python script demo for this function is[`demo_ota_driver_devel.py`](fourier_actuator_sdk_python_demo.md#demo_ota_driver_develpy)

| Function | Perform driver OTA upgrade on the actuator, upgrade version is development. |
| --- | --- |
| Parameters | **server\_ip：** actuator IP, type: str |
| Return Value | None return value |

### ota\_driver\_cloud(server\_ip)

The corresponding Python script demo for this function is[`demo_ota_driver_cloud.py`](fourier_actuator_sdk_python_demo.md#demo_ota_driver_cloudpy)

| Function | Perform driver OTA upgrade on the actuator, upgrade version is cloud. |
| --- | --- |
| Parameters | **server\_ip：** actuator IP, type: str |
| Return Value | None return value |

### ota\_driver\_custom(server\_ip ,version\_str)

The corresponding Python script demo for this function is[`demo_ota_driver_custom.py`](fourier_actuator_sdk_python_demo.md#demo_ota_driver_custompy)

| Function | Perform driver OTA upgrade on the actuator, upgrade version is custom. |
| --- | --- |
| Parameters | **server\_ip：** actuator IP, type: str<br>**version\_str：** Version number to upgrade, type: str |
| Return Value | None return value |

## ctrl Interface

### set\_enable(server\_ip)

The corresponding Python script demo for this function is[`demo_enable_set.py`](fourier_actuator_sdk_python_demo.md#demo_enable_setpy)

**Function Description:**

| Function | Set the actuator's enable |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### set\_disable(server\_ip)

The corresponding Python script demo for this function is[`demo_enable_set.py`](fourier_actuator_sdk_python_demo.md#demo_enable_setpy)

**Function Description:**

| Function | Set the actuator's disable |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### clear\_fault(server\_ip)

The corresponding Python script demo for this function is[`demo_clear_fault.py`](fourier_actuator_sdk_python_demo.md#demo_clear_faultpy)

**Function Description:**

| Function | Clear the actuator's error codes |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### set\_calibrate\_encoder(server\_ip)

The corresponding Python script demo for this function is[`demo_set_calibrate_encoder.py`](fourier_actuator_sdk_python_demo.md#demo_set_calibrate_encoderpy) (Note: During calibration, the actuator will rotate. It is recommended to secure the actuator before calibration)

**Function Description:**

| Function | Set the actuator mode to calibration mode |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### get\_state(server\_ip)

**Function Description:**

| Function | Get the current status of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Current status of the actuator, type: str or empty. Returns "OK" if status is normal, None if abnormal |

### set\_mode\_of\_operation(server\_ip, mode\_of\_operation)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the actuator's operation mode (position, velocity, current, torque) |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**mode\_of\_operation：** Actuator operation mode, type: int, options include position, velocity, current, torque |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

| **mode\_of\_operation Modes** | Corresponding int Value | Corresponding Variable in FSAModeOfOperation Class |
| --- | --- | --- |
| None mode | 0 | NONE |
| Position mode | 1 | POSITION\_CONTROL |
| Velocity mode | 3 | VELOCITY\_CONTROL |
| Current mode | 4 | CURRENT\_CONTROL |
| Torque mode | 6 | TORQUE\_CONTROL |
| Position PD mode | 7 | POSITION\_CONTROL\_PD |

```python
# Set Position mode
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.NONE)
# Set Position mode
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL)
# Set Velocity mode
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.VELOCITY_CONTROL)
# Set Current mode
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.CURRENT_CONTROL)
# Set Torque mode
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.TORQUE_CONTROL)
# Set Position PD mode
fi_fsa_v2.set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL_PD)
```

### get\_pid\_param(server\_ip)

The corresponding Python script demo for this function is[`demo_pid_param_get.py`](fourier_actuator_sdk_python_demo.md#demo_pid_param_getpy)

**Function Description:**

| Function | Get the PID parameters of the actuator (Note: These PID parameters require a restart to take effect) |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the operation was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### set\_pid\_param(server\_ip, dict)

The corresponding Python script demo for this function is[`demo_pid_param_set.py`](fourier_actuator_sdk_python_demo.md#demo_pid_param_setpy)

**Function Description:**

| Function | Set the PID parameters of the actuator (Note: These PID parameters require a restart to take effect) |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**dict：** PID parameters, type: dict |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

| PID Parameter Specific Configuration | Description | Type |
| --- | --- | --- |
| control\_position\_kp | Position loop Kp | float |
| control\_velocity\_kp | Velocity loop Kp | float |
| control\_velocity\_ki | Velocity loop Ki | float |
| control\_current\_kp | Current loop Kp | float |
| control\_current\_ki | Current loop Ki | float |
| control\_PD\_kp | PD mode Kp | float |
| control\_PD\_kd | PD mode Kd | float |

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

The corresponding Python script demo for this function is[`demo_pid_param_imm_get.py`](fourier_actuator_sdk_python_demo.md#demo_pid_param_imm_getpy)

**Function Description:**

| Function | Get the temporary PID parameters of the actuator (Note: These PID parameters take effect immediately, but will not be saved after power off) |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the operation was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### set\_pid\_param\_imm(server\_ip, dict)

The corresponding Python script demo for this function is[`demo_pid_param_imm_set.py`](fourier_actuator_sdk_python_demo.md#demo_pid_param_imm_setpy)

**Function Description:**

| Function | Set the temporary PID parameters of the actuator (Note: These PID parameters take effect immediately, but will not be saved after power off) |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**dict：** PID parameters, type: dict |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

| PID Parameter Specific Configuration | Description | Type |
| --- | --- | --- |
| control\_position\_kp\_imm | Temporary position loop Kp | float |
| control\_velocity\_kp\_imm | Temporary velocity loop Kp | float |
| control\_velocity\_ki\_imm | Temporary velocity loop Ki | float |
| control\_PD\_kp\_imm | Temporary PD mode Kp | float |
| control\_PD\_kd\_imm | Temporary PD mode Kd | float |

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

The corresponding Python script demo for this function is[`demo_control_param_get.py`](fourier_actuator_sdk_python_demo.md#demo_control_param_getpy)

**Function Description:**

| Function | Get the control parameters of the actuator (Note: These control parameters require a restart to take effect) |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the operation was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### set\_control\_param(server\_ip, dict)

The corresponding Python script demo for this function is[`demo_control_param_set.py`](fourier_actuator_sdk_python_demo.md#demo_control_param_setpy)

**Function Description:**

| Function | Set the control parameters of the actuator (Note: These control parameters require a restart to take effect) |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**dict：** Control parameters, type: dict |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

| Control Parameter Specific Configuration | Description | Type |
| --- | --- | --- |
| motor\_max\_speed | Maximum speed of the actuator | int |
| motor\_max\_acceleration | Maximum acceleration of the actuator | int |
| motor\_max\_current | Maximum current of the actuator | int |

```python
            dict = {
                "motor_max_speed": 3000,
                "motor_max_acceleration": 60000,
                "motor_max_current": 8,
            }
```

### get\_control\_param\_imm(server\_ip)

The corresponding Python script demo for this function is[`demo_control_param_imm_get.py`](fourier_actuator_sdk_python_demo.md#demo_control_param_imm_getpy)

**Function Description:**

| Function | Get the temporary control parameters of the actuator (Note: These parameters take effect immediately, but will not be saved after power off) |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the operation was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### get\_flag\_of\_operation(server\_ip)

The corresponding Python script demo for this function is[`demo_flag_of_operation_get.py`](fourier_actuator_sdk_python_demo.md#demo_flag_of_operation_getpy)

**Function Description:**

| Function | Get the actuator's operation flag |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the operation was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### set\_flag\_of\_operation(server\_ip, dict\_cfg)

The corresponding Python script demo for this function is[`demo_flag_of_operation_set.py`](fourier_actuator_sdk_python_demo.md#demo_flag_of_operation_setpy)

**Function Description:**

| Function | Set the operation flags of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**dict\_cfg：** Operation flags, type: dict |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

| Operation Flag Configuration | Description | Type |
| --- | --- | --- |
| flag\_do\_use\_store\_motor\_param | Whether to enable configuration parameters, 1 means enable, 0 means disable | int |
| flag\_do\_use\_store\_pid\_param | Whether to enable PID parameters, 1 means enable, 0 means disable | int |
| actuator\_double\_encoder\_enable | Whether to enable dual encoder function, 1 means enable, 0 means disable | int |

```python
 dict_cfg = {
                "flag_do_use_store_motor_param": 1,
                "flag_do_use_store_pid_param": 0,
                "actuator_double_encoder_enable": 1,
            }
```

### get\_config(server\_ip)

The corresponding Python script demo for this function is[`demo_ctrl_config_get.py`](fourier_actuator_sdk_python_demo.md#demo_ctrl_config_getpy)

**Function Description:**

| Function | Get the actuator's configuration information |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the operation was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### set\_config(server\_ip, dict)

The corresponding Python script demo for this function is[`demo_ctrl_config_set.py`](fourier_actuator_sdk_python_demo.md#demo_ctrl_config_setpy)

**Function Description:**

| Function | Set the configuration information of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**dict：** Actuator configuration information, type: dict |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

| Actuator Configuration Information | Description | Type |
| --- | --- | --- |
| actuator\_direction | Actuator direction | int |
| actuator\_reduction\_ratio | Reduction ratio | float |
| motor\_type | Motor model | unsigned int |
| motor\_hardware\_type | Driver board model | unsigned int |
| motor\_direction | Motor rotation direction | int |
| motor\_max\_speed | Motor maximum speed | float |
| motor\_max\_acceleration | Motor maximum acceleration | float |
| motor\_max\_current | Motor current limit | float |
| actuator\_comm\_hardware\_type | Communication board model | int |

| Actuator Direction Values | Description |
| --- | --- |
| 1 | Forward (clockwise) |
| \-1 | Reverse (counterclockwise) |

| Motor Model Values | Description |
| --- | --- |
| 0 | MOTOR\_NULL (None model) |
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

| Driver Board Model Values | Description |
| --- | --- |
| 0 | HARDWARE\_NULL (None model) |
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

| Motor Direction Values | Description |
| --- | --- |
| 1 | Forward (clockwise) |
| \-1 | Reverse (counterclockwise) |

| Communication Board Model | Description |
| --- | --- |
| 0 | NULL (None version) |
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

The corresponding Python script demo for this function is[`demo_reboot.py`](fourier_actuator_sdk_python_demo.md#demo_rebootpy)

**Function Description:**

| Function | Reboot the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Whether the reboot was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

### get\_error\_code(server\_ip)

The corresponding Python script demo for this function is[`demo_get_error.py`](fourier_actuator_sdk_python_demo.md#demo_get_errorpy)

**Function Description:**

| Function | Get the error code of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Specific error code, return type: int or list or None. Returns None on failure, return type is int when there is one error code, return type is list when there are multiple error codes. |

### get\_pvc(server\_ip)

The corresponding Python script demo for this function is[`demo_get_pvc.py`](fourier_actuator_sdk_python_demo.md#demo_get_pvcpy)

**Function Description:**

| Function | Get the position, velocity, and current information of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Specific position, velocity, and current information, return type is tuple, return values in order are position, velocity, current. |

### get\_foc\_target\_PVC(server\_ip)

The corresponding Python script demo for this function is[`demo_get_foc_target_PVC.py`](fourier_actuator_sdk_python_demo.md#demo_get_foc_target_pvcpy)

**Function Description:**

| Function | Get the target position, target velocity, and target current information of the actuator FOC execution |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Specific target position, target velocity, and target current information of FOC execution, return type is tuple, return values in order are position, velocity, current. |

### get\_pvct(server\_ip)

The corresponding Python script demo for this function is[`demo_get_pvct.py`](fourier_actuator_sdk_python_demo.md#demo_get_pvctpy)

**Function Description:**

| Function | Get the current position, velocity, current, and torque information of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Specific position, velocity, current, and torque information of FOC execution, return type is tuple, return values in order are position, velocity, current, torque. |

### get\_fsa\_abs\_position(server\_ip) 

The corresponding Python script demo for this function is[`demo_get_fsa_abs_position.py`](fourier_actuator_sdk_python_demo.md#demo_get_fsa_abs_positionpy)

**Function Description:**

| Function | Get the absolute encoder position information of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Absolute encoder position information, type: float. |

### set\_fsa\_abs\_zero(server\_ip)

The corresponding Python script demo for this function is[`demo_set_fsa_abs_zero.py`](fourier_actuator_sdk_python_demo.md#demo_set_fsa_abs_zeropy)

**Function Description:**

| Function | Set the zero point of the actuator's absolute encoder, using the current position as the zero point. |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Returns True on success, returns error code on failure. |

### set\_eth\_recovery(server\_ip)

The corresponding Python script demo for this function is[`demo_set_eth_recovery.py`](fourier_actuator_sdk_python_demo.md#demo_set_eth_recoverypy)

**Function Description:**

| Function | Recover the actuator's network |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Returns True on success, returns error code on failure. |

### set\_eth\_timeout\_protect(server\_ip, is\_enable, timeout\_interval)Not available in low versions

The corresponding Python script demo for this function is[`demo_set_eth_timeout_protect.py`](fourier_actuator_sdk_python_demo.md#demo_set_eth_timeout_protectpy)

**Function Description:**

| Function | Set the network timeout protection of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**is\_enable：** Whether to enable network timeout protection, type: int, 0 means disable, 1 means enable<br>**timeout\_interval：** Timeout detection time, unit: milliseconds, type: int |
| Return Value | Returns True on success, returns error code on failure. |

### set\_control\_loop\_freq\_div(server\_ip, position\_loop\_freq\_div, velocity\_loop\_freq\_div, PD\_loop\_freq\_div)Not available in low versions

The corresponding Python script demo for this function is[`demo_set_control_loop_freq_div.py`](fourier_actuator_sdk_python_demo.md#demo_set_control_loop_freq_divpy)

**Function Description:**

| Function | Divide the actuator's control frequency by a specific value to modify the actual control frequency |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**position\_loop\_freq\_div：** Specific value to divide the position control frequency in Position mode, type: float<br>**velocity\_loop\_freq\_div：** Specific value to divide the velocity control frequency in Velocity mode, type: float<br>**PD\_loop\_freq\_div：** Specific value to divide the position control frequency in PD Position mode, type: float |
| Return Value | Returns True on success, returns error code on failure. |

### set\_torque\_limit\_max(server\_ip, torque\_limit\_max)

The corresponding Python script demo for this function is[`demo_set_torque_limit_max.py`](fourier_actuator_sdk_python_demo.md#demo_set_torque_limit_maxpy)

**Function Description:**

| Function | Set the maximum torque of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**torque\_limit\_max：** Maximum torque of the actuator, type: float |
| Return Value | Returns True on success, returns error code on failure. |

### set\_inertia\_ff(server\_ip, inertia\_ff)

The corresponding Python script demo for this function is[`demo_set_inertia_ff.py`](fourier_actuator_sdk_python_demo.md#demo_set_inertia_ffpy)

**Function Description:**

| Function | Set the inertia compensation of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**inertia\_ff：** Inertia compensation of the actuator, type: float |
| Return Value | Returns True on success, returns error code on failure. |

### get\_ntc\_temperature(server\_ip)

The corresponding Python script demo for this function is[`demo_get_ntc_temperature.py`](fourier_actuator_sdk_python_demo.md#demo_get_ntc_temperaturepy)

**Function Description:**

| Function | Get the winding temperature and MOS temperature of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Returns winding temperature and MOS temperature. Type is tuple, first is MOS temperature, second is winding temperature. |

### set\_position\_control(server\_ip, position, velocity\_ff=0.0, current\_ff=0.0)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the target position of the actuator in Position mode |
| --- | --- |
| Parameters | **server\_ip：** (required) actuator IP ,type: str<br>**position：** (required)Target position of the actuator, type: float<br>**velocity\_ff：** (optional)Velocity loop feedforward of the actuator, type: float, default value is 0.0<br>**current\_ff：** (optional)Position loop feedforward of the actuator, type: float, default value is 0.0 |
| Return Value | Returns current velocity, position, current on success, returns None on failure |

### set\_velocity\_control(server\_ip, velocity, current\_ff=0.0)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the target velocity of the actuator in Velocity mode |
| --- | --- |
| Parameters | **server\_ip：** (required) actuator IP ,type: str<br>**velocity：** (required)Target velocity of the actuator, type: float<br>**current\_ff：** (optional)Current feedforward of the actuator, type: float, default value is 0.0 |
| Return Value | Returns current velocity, position, current on success, returns None on failure |

### set\_current\_control(server\_ip, current)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the target current of the actuator in Current mode |
| --- | --- |
| Parameters | **server\_ip：** (required) actuator IP ,type: str<br>**current：** (required)Target current of the actuator, type: float |
| Return Value | Returns current velocity, position, current on success, returns None on failure |

### set\_torque\_control(server\_ip, torque)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the target torque of the actuator in Torque mode |
| --- | --- |
| Parameters | **server\_ip：**(required) actuator IP ,type: str<br>**torque：**(required)Target torque of the actuator, type: float |
| Return Value | Returns current velocity, position, current on success, returns None on failure |

## fast Interface

### fast\_set\_enable(server\_ip)

The corresponding Python script demo for this function is[`demo_fast_set_enable.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_enablepy)

**Function Description:**

| Function | Set the enable of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_enable(server\_ip, cnt)

The corresponding Python script demo for this function is[`demo_fast_set_ack_enable.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_enablepy)

**Function Description:**

| Function | Enable the actuator and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_disable(server\_ip)

The corresponding Python script demo for this function is[`demo_fast_set_disable.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_disablepy)

**Function Description:**

| Function | Set the actuator's disable |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_disable(server\_ip, cnt)

The corresponding Python script demo for this function is[`demo_fast_set_ack_disable.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_disablepy)

**Function Description:**

| Function | Disable the actuator and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means successful, returns None on timeout |

### fast\_set\_clear\_fault(server\_ip)

The corresponding Python script demo for this function is[`demo_fast_set_clear_fault.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_clear_faultpy)

**Function Description:**

| Function | Clear the error code of the actuator driver |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_clear\_fault(server\_ip, cnt)

The corresponding Python script demo for this function is[`demo_fast_set_ack_clear_fault.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_clear_faultpy)

**Function Description:**

| Function | Clear the error code of the actuator driver and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_position\_mode(server\_ip)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the actuator to position control mode |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_position\_mode(server\_ip, cnt)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the actuator to position control mode and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_velocity\_mode(server\_ip)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the actuator to velocity control mode |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_velocity\_mode(server\_ip, cnt)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the actuator to velocity control mode and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_torque\_mode(server\_ip)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the actuator to torque control mode |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_torque\_mode(server\_ip, cnt)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the actuator to torque control mode and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_current\_mode(server\_ip)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the actuator to current control mode |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_current\_mode(server\_ip, cnt)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the actuator to current control mode and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_pd\_mode(server\_ip)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the actuator to PD control mode |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_pd\_mode(server\_ip, cnt)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the actuator to PD control mode and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_mode\_of\_operation(server\_ip, mode\_of\_operation)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the operation mode of the actuator (position, velocity, current, torque, PD) |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**mode\_of\_operation：** Actuator operation mode, type: int, options include position, velocity, current, torque, PD |
| Return Value | Whether the setting was successful, returns FSAFunctionResult.SUCCESS on success, None on failure. |

| **mode\_of\_operation Modes** | Corresponding int Value | Corresponding Variable in FSAModeOfOperation Class |
| --- | --- | --- |
| None mode | 0 | NONE |
| Position mode | 1 | POSITION\_CONTROL |
| Velocity mode | 3 | VELOCITY\_CONTROL |
| Current mode | 4 | CURRENT\_CONTROL |
| Torque mode | 6 | TORQUE\_CONTROL |
| Position PD mode | 7 | POSITION\_CONTROL\_PD |

```python
# Set Position mode
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.NONE)
# Set Position mode
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL)
# Set Velocity mode
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.VELOCITY_CONTROL)
# Set Current mode
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.CURRENT_CONTROL)
# Set Torque mode
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.TORQUE_CONTROL)
# Set Position PD mode
fi_fsa_v2.fast_set_mode_of_operation(server_ip_list[i], fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL_PD)
```

### fast\_set\_ack\_mode\_of\_operation(server\_ip, tx\_cnt, mode\_of\_operation)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the operation mode of the actuator (position, velocity, current, torque, PD) and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**tx\_cnt：** Counter value for asynchronous communication<br>**mode\_of\_operation：** Actuator operation mode, type: int, options include position, velocity, current, torque, PD |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

| **mode\_of\_operation Modes** | Corresponding int Value | Corresponding Variable in FSAModeOfOperation Class |
| --- | --- | --- |
| None mode | 0 | NONE |
| Position mode | 1 | POSITION\_CONTROL |
| Velocity mode | 3 | VELOCITY\_CONTROL |
| Current mode | 4 | CURRENT\_CONTROL |
| Torque mode | 6 | TORQUE\_CONTROL |
| Position PD mode | 7 | POSITION\_CONTROL\_PD |

```python
# Set Position mode
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.NONE)
# Set Position mode
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL)
# Set Velocity mode
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.VELOCITY_CONTROL)
# Set Current mode
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.CURRENT_CONTROL)
# Set Torque mode
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.TORQUE_CONTROL)
# Set Position PD mode
fi_fsa_v2.fast_set_ack_mode_of_operation(server_ip_list[i], tx_cnt, fi_fsa_v2.FSAModeOfOperation.POSITION_CONTROL_PD)
```

### fast\_set\_position\_control(server\_ip, position, velocity\_ff=0, current\_ff=0)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the target position of the actuator in Position mode |
| --- | --- |
| Parameters | **server\_ip：**(required) actuator IP ,type: str<br>**position：** (required)Target position of the actuator, type: float<br>**velocity\_ff：** (optional)Velocity loop feedforward of the actuator, type: float, default value is 0.0<br>**current\_ff：** (optional)Position loop feedforward of the actuator, type: float, default value is 0.0 |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_velocity\_control(server\_ip, velocity, current\_ff=0)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the target velocity of the actuator in Velocity mode |
| --- | --- |
| Parameters | **server\_ip：** (required) actuator IP ,type: str<br>**velocity：** (required)Target velocity of the actuator, type: float<br>**current\_ff：** (optional)Current feedforward of the actuator, type: float, default value is 0.0 |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_current\_control(server\_ip, current)

This function has no corresponding Python script.

**Function Description:**

| Function | Set the target current of the actuator in Current mode |
| --- | --- |
| Parameters | **server\_ip：** (required) actuator IP ,type: str<br>**current：** (required)Target current of the actuator, type: float |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_pd\_control(server\_ip, position, velocity\_ff=0, current\_ff=0)

The corresponding Python script demo for this function is[`demo_fast_set_pd_position.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_pd_positionpy)

**Function Description:**

| Function | Set the target position of the actuator in Position mode |
| --- | --- |
| Parameters | **server\_ip：** (required) actuator IP ,type: str<br>**position：** (required)Target position of the actuator, type: float<br>**velocity\_ff：** (optional)Velocity loop feedforward of the actuator, type: float, default value is 0.0<br>**current\_ff：** (optional)Position loop feedforward of the actuator, type: float, default value is 0.0 |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_pd\_control(server\_ip, cnt, position, velocity\_ff=0, current\_ff=0)

The corresponding Python script demo for this function is[`demo_fast_set_ack_pd_position.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_pd_positionpy)

**Function Description:**

| Function | Set the target position of the actuator in Position mode and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** (required) actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication<br>**position：** (required)Target position of the actuator, type: float<br>**velocity\_ff：** (optional)Velocity loop feedforward of the actuator, type: float, default value is 0.0<br>**current\_ff：** (optional)Position loop feedforward of the actuator, type: float, default value is 0.0 |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_pid\_imm(server\_ip, position\_kp, velocity\_kp, velocity\_ki)

The corresponding Python script demo for this function is[`demo_fast_set_pid_imm.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_pid_immpy)

**Function Description:**

| Function | Set temporary PID parameters for the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**position\_kp：** Actuator three-loop control position loop Kp, type: float<br>**velocity\_kp：** Actuator three-loop control velocity loop Kp, type: float<br>**velocity\_ki：** Actuator three-loop control velocity loop Ki, type: float |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_pid\_imm(server\_ip, cnt, position\_kp, velocity\_kp, velocity\_ki)

The corresponding Python script demo for this function is[`demo_fast_set_ack_pid_imm.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_pid_immpy)

**Function Description:**

| Function | Set temporary PID parameters for the actuator and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication<br>**position\_kp：** Actuator three-loop control position loop Kp, type: float<br>**velocity\_kp：** Actuator three-loop control velocity loop Kp, type: float<br>**velocity\_ki：** Actuator three-loop control velocity loop Ki, type: float |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_pd\_imm(server\_ip, kp, kd)

The corresponding Python script demo for this function is[`demo_fast_set_pd_imm.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_pd_immpy)

**Function Description:**

| Function | Set temporary PD parameters for the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**kp：** Actuator PD control position loop Kp, type: float<br>**kd：** Actuator PD control velocity loop Kd, type: float |
| Return Value | FSAFunctionResult.SUCCESS |

### fast\_set\_ack\_pd\_imm(server\_ip, cnt, kp, kd)

The corresponding Python script demo for this function is[`demo_fast_set_ack_pd_imm.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_pd_immpy)

**Function Description:**

| Function | Set temporary PD parameters for the actuator and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication<br>**kp：** Actuator PD control position loop Kp, type: float<br>**kd：** Actuator PD control velocity loop Kd, type: float |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_control\_loop\_freq\_div(server\_ip, position\_loop\_freq\_div, velocity\_loop\_freq\_div, PD\_loop\_freq\_div)

The corresponding Python script demo for this function is[`demo_fast_set_control_loop_freq_div.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_control_loop_freq_divpy)

**Function Description:**

| Function | Set the loop control frequency division coefficient of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**position\_loop\_freq\_div：** Position loop control frequency division coefficient, type: float<br>**velocity\_loop\_freq\_div：** Velocity loop control frequency division coefficient, type: float<br>**PD\_loop\_freq\_div：** PD control frequency division coefficient, type: float |
| Return Value | Successfully output the received UDP packet, output None on failure |

### fast\_set\_ack\_control\_loop\_freq\_div(server\_ip, cnt, position\_loop\_freq\_div, velocity\_loop\_freq\_div, PD\_loop\_freq\_div)

The corresponding Python script demo for this function is[`demo_fast_set_ack_control_loop_freq_div.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_control_loop_freq_divpy)

**Function Description:**

| Function | Set the loop control frequency division coefficient of the actuator and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication<br>**position\_loop\_freq\_div：** Position loop control frequency division coefficient, type: float<br>**velocity\_loop\_freq\_div：** Velocity loop control frequency division coefficient, type: float<br>**PD\_loop\_freq\_div：** PD control frequency division coefficient, type: float |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_friction\_FFD(server\_ip, SET, DeadSpeedK, DeadSpeed, Fs, Fc, B, percent):

The corresponding Python script demo for this function is[`demo_fast_set_friction_FFD.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_friction_ffdpy) 

**Function Description:**

| Function | Set actuator friction compensation |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**SET：** Whether to enable friction compensation, type: uint32<br>**DeadSpeedK：** Dead zone slope, type: float<br>**DeadSpeed：** Dead zone speed, type: float<br>**Fs：** Static friction, type: float<br>**Fc：** Coulomb friction, type: float<br>**B：** Viscous friction coefficient, type: float<br>**percent：** Effective multiple, range 0~2, type: float |
| Return Value | Successfully output the received UDP packet, output None on failure |

### fast\_set\_ack\_friction\_FFD(server\_ip, cnt, SET, DeadSpeedK, DeadSpeed, Fs, Fc, B, percent)

The corresponding Python script demo for this function is[`demo_fast_set_ack_friction_FFD.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_friction_ffdpy) 

**Function Description:**

| Function | Set actuator friction compensation and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication<br>**SET：** Whether to enable friction compensation, type: uint32<br>**DeadSpeedK：** Dead zone slope, type: float<br>**DeadSpeed：** Dead zone speed, type: float<br>**Fs：** Static friction, type: float<br>**Fc：** Coulomb friction, type: float<br>**B：** Viscous friction coefficient, type: float<br>**percent：** Effective multiple, range 0~2, type: float |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_ack\_setpvc\_timeout\_protect(server\_ip, cnt, protect\_enable, timeout\_ms, protect\_mode\_of\_operation, close\_back\_last\_mode\_of\_operation, ignore\_set\_mode\_of\_operation)

The corresponding Python script demo for this function is[`demo_fast_set_ack_setpvc_timeout_protect.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_setpvc_timeout_protectpy) 

**Function Description:**

| Function | Set actuator setpvc timeout protection and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication<br>**protect\_enable：** Whether to enable setpvc timeout protection, 0 disable, 1 enable, type: uint32<br>**timeout\_ms：** Timeout time, in milliseconds, type: uint32<br>**protect\_mode\_of\_operation：** Set whether to use three-loop position control or PD control when entering protection state, optional FSAModeOfOperation.POSITION\_CONTROL, FSAModeOfOperation.POSITION\_CONTROL\_PD, type: uint32<br>**close\_back\_last\_mode\_of\_operation：** If the function is disabled and currently in protection state, whether to restore to the operation mode before entering protection state, 0: do not restore, 1: restore, type: uint32<br>**ignore\_set\_mode\_of\_operation：** Whether to prohibit modifying mode\_of\_operation after entering protection mode, 0: do not prohibit, 1: prohibit, type: uint32 |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_ack\_interface\_filter\_fc(server\_ip, cnt, position, velocity, current)

The corresponding Python script demo for this function is[`demo_fast_set_ack_interface_filter_fc.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_interface_filter_fcpy) 

**Function Description:**

| Function | Set the filter cutoff frequency of the actuator feedback pvc and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication<br>**position：** Set position feedback filter cutoff frequency, type: float<br>**velocity：** Set velocity feedback filter cutoff frequency, type: float<br>**current：** Set current and torque feedback filter cutoff frequency, type: float |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_set\_ack\_setpvc\_protect\_clear(server\_ip, cnt, clear\_back\_last\_mode\_of\_operation)

The corresponding Python script demo for this function is[`demo_fast_set_ack_setpvc_protect_clear.py`](fourier_actuator_sdk_python_demo.md#demo_fast_set_ack_setpvc_protect_clearpy) 

**Function Description:**

| Function | Clear actuator setpvc protection status and return cnt counter value and execution result |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str<br>**cnt：** Counter value for asynchronous communication<br>**close\_back\_last\_mode\_of\_operation：** Whether to restore to the operation mode before entering protection state when clearing protection status, 0: do not restore, 1: restore, type: uint32 |
| Return Value | Returns cnt counter value and res execution result if not timeout, res=0 means enable successful, returns None on timeout |

### fast\_get\_pvc(server\_ip)

The corresponding Python script demo for this function is[`demo_fast_get_pvc.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_pvcpy) 

**Function Description:**

| Function | Get the current position, velocity, and current information of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Successfully output actuator position, velocity, and current information, output None on failure |

### fast\_get\_foc\_target\_pvc(server\_ip)

The corresponding Python script demo for this function is[`demo_fast_get_foc_target_pvc.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_foc_target_pvcpy) 

**Function Description:**

| Function | Get the target position, velocity, and current information of the actuator's underlying FOC |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Successfully output the target position, velocity, and current information of the underlying FOC, output None on failure |

### fast\_get\_pvct(server\_ip)

The corresponding Python script demo for this function is[`demo_fast_get_pvct.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_pvctpy) 

**Function Description:**

| Function | Get the current position, velocity, current, and torque information of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Successfully output the current position, velocity, current, and torque information of the actuator, output None on failure |

### fast\_get\_error(server\_ip)

The corresponding Python script demo for this function is[`demo_fast_get_error.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_errorpy) 

**Function Description:**

| Function | Get the error code of the actuator |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Successfully output the actuator error code, output None on failure |

### fast\_get\_pvct\_error(server\_ip)

The corresponding Python script demo for this function is[`demo_fast_get_pvct_error.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_pvct_errorpy) 

**Function Description:**

| Function | Get actuator position, velocity, current, torque, and error code |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Successfully output actuator position, velocity, current, torque, and error code, output None on failure |

### fast\_get\_friction\_FFD(server\_ip)

The corresponding Python script demo for this function is[`demo_fast_get_friction_FFD.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_friction_ffdpy) 

**Function Description:**

| Function | Get actuator friction compensation parameters |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Successfully output whether friction compensation is enabled, dead zone slope, dead zone speed, static friction, Coulomb friction, viscous friction coefficient, effective multiple, output None on failure |

### fast\_get\_ntc\_temp(server\_ip)

The corresponding Python script demo for this function is[`demo_fast_get_ntc_temp.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_ntc_temppy) 

**Function Description:**

| Function | Get actuator MOS and winding temperature |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Successfully output actuator MOS and winding temperature, output None on failure |

### fast\_get\_vbus(server\_ip)

The corresponding Python script demo for this function is[`demo_fast_get_vbus.py`](fourier_actuator_sdk_python_demo.md#demo_fast_get_vbuspy) 

**Function Description:**

| Function | Get actuator bus voltage |
| --- | --- |
| Parameters | **server\_ip：** actuator IP ,type: str |
| Return Value | Successfully output actuator bus voltage, output None on failure |

## subscribe Interface

The corresponding Python script function for this interface is [`set_subscribe(server_ip, cfg_dict)`](#set_subscribe)