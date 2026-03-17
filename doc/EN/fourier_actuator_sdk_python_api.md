# Actuator Python SDK Interface Documentation

The unit descriptions of the relevant physical quantities mentioned in the following text are as follows:

| Data Type | Unit         |
| --------- | ------------ |
| Position  | rad (radian) |
| Velocity  | rad/s        |
| Current   | A            |
| Torque    | N·m          |

## Control Interfaces 

### EnableControl(ctrl_mode, timeout_ms, max_retry)

The corresponding Python script demo for this function is [`demo_position_control.py`](../../example/python/demo_position_control.py)

**Function Description:**

| Description | Enable actuator control                                                                                            |
| ----------- | ------------------------------------------------------------------------------------------------------------------ |
| Inputs      | **ctrl_mode:** Control mode<br>**timeout_ms:** Timeout in ms, default 5<br>**max_retry:** Maximum retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                                    |

| Specific configuration of control mode            | Meaning                                              | Type |
| --------------- | ---------------------------------------------------- | ---- |
| CURRENT_MODE  | Current control mode, use torque control recommended | int  |
| TORQUE_MODE   | Torque control mode                                  | int  |
| VELOCITY_MODE | Torque + velocity control mode                       | int  |
| POSITION_MODE | Torque + position control mode                       | int  |
| PD_MODE       | Torque PD control mode                               | int  |

### DisableControl(timeout_ms, max_retry)

The corresponding Python script demo for this function is[`demo_position_control.py`](../../example/python/demo_position_control.py)

**Function Description:**

| Description | Disable actuator                                                                    |
| ----------- | ----------------------------------------------------------------------------------- |
| Inputs      | **timeout_ms:** Timeout in ms, default 5<br>**max_retry:** Maximum retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                     |

### SetPIDParams(p_kp, v_kp, v_ki, timeout_ms, max_retry)

The corresponding Python script demo for this function is[`demo_position_control.py`](../../example/python/demo_position_control.py)

**Function Description:**

| Description | Set position and velocity loop PID parameters in real time                                                                                                                                                        |
| ----------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Inputs      | **p_kp:** Position loop proportional gain<br>**v_kp:** Velocity loop proportional gain<br>**v_ki:** Velocity loop integral gain<br>**timeout_ms:** Timeout (ms), default 5<br>**max_retry:** Max retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                                                                                                                                   |

### GetPIDParams(rx_pid, timeout_ms, max_retry)

The corresponding Python script demo for this function is[`demo_get_info.py`](../../example/python/demo_get_info.py)

**Function Description:**

| Description | Get position and velocity loop PID parameters                                                                                |
| ----------- | ---------------------------------------------------------------------------------------------------------------------------- |
| Inputs      | **rx_pid:** Store retrieved PID parameters<br>**timeout_ms:** Timeout (ms), default 5<br>**max_retry:** Max retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                                              |

### GetPVCTTe(rx_PVCTTe, timeout_ms, max_retry)

The corresponding Python script demo for this function is[`demo_get_info.py`](../../example/python/demo_get_info.py)

**Function Description:**

| Description | Get actuator feedback: position, velocity, current, torque, electromagnetic torque                                    |
| ----------- | --------------------------------------------------------------------------------------------------------------------- |
| Inputs      | **rx_PVCTTe:** Store retrieved data<br>**timeout_ms:** Timeout (ms), default 5<br>**max_retry:** Max retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                                       |

### SetPosition(p_rad, v_ff_radps, t_ff_Nm, timeout_ms, max_retry)

The corresponding Python script demo for this function is[`demo_position_control.py`](../../example/python/demo_position_control.py)

**Function Description:**

| Description | Send position target, velocity feedforward, torque feedforward; actuator replies                                                                                                        |
| ----------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Inputs      | **p_rad:** Target position<br>**v_ff_radps:** Velocity feedforward<br>**t_ff_Nm:** Torque feedforward<br>**timeout_ms:** Timeout (ms), default 5<br>**max_retry:** Max retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                                                                                                         |

### SetTorque(t_Nm, timeout_ms, max_retry)

The corresponding Python script demo for this function is[`demo_torque_control.py`](../../example/python/demo_torque_control.py)

**Function Description:**

| Description | Send torque target; actuator replies                                                                      |
| ----------- | --------------------------------------------------------------------------------------------------------- |
| Inputs      | **t_Nm:** Target torque<br>**timeout_ms:** Timeout (ms), default 5<br>**max_retry:** Max retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                           |

### GetTempVbus(rx_temp_vbus, timeout_ms, max_retry)

The corresponding Python script demo for this function is[`demo_get_info.py`](../../example/python/demo_get_info.py)

**Function Description:**

| Description | Get MOS temperature, winding temperature, voltage                                                                        |
| ----------- | ------------------------------------------------------------------------------------------------------------------------ |
| Inputs      | **rx_temp_vbus:** Store retrieved data<br>**timeout_ms:** Timeout (ms), default 5<br>**max_retry:** Max retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                                          |

### GetErrCode(rx_errcode, timeout_ms, max_retry)

The corresponding Python script demo for this function is[`demo_get_info.py`](../../example/python/demo_get_info.py)

**Function Description:**

| Description | Get actuator current error code                                                                                    |
| ----------- | ------------------------------------------------------------------------------------------------------------------ |
| Inputs      | **rx_errcode:** Store error code<br>**timeout_ms:** Timeout (ms), default 5<br>**max_retry:** Max retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                                    |

### ParseErrCode(err_code, parsed_err_code)

The corresponding Python script demo for this function is[`demo_get_info.py`](../../example/python/demo_get_info.py)

**Function Description:**

| Description | Parse actuator error code                                                        |
| ----------- | -------------------------------------------------------------------------------- |
| Inputs      | **err_code:** 8 uint32_t error codes<br>**parsed_err_code:** Parsed error code |
| Output      | Returns detailed execution status ret_e(int)                                  |

### GetPDParams(rx_pd, timeout_ms, max_retry)

The corresponding Python script demo for this function is[`demo_get_info.py`](../../example/python/demo_get_info.py)

**Function Description:**

| Description | Get immediate (imm) PD parameters                                                                                |
| ----------- | ---------------------------------------------------------------------------------------------------------------- |
| Inputs      | **rx_pd:** Store PD parameters<br>**timeout_ms:** Timeout (ms), default 5<br>**max_retry:** Max retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                                  |

### GetTypeSubversion(type_subversion, timeout_ms, max_retry)

The corresponding Python script demo for this function is[`demo_get_info.py`](../../example/python/demo_get_info.py)

**Function Description:**

| Description | Get actuator model and subversion                                                                                                 |
| ----------- | --------------------------------------------------------------------------------------------------------------------------------- |
| Inputs      | **type_subversion:** Store model and subversion<br>**timeout_ms:** Timeout (ms), default 5<br>**max_retry:** Max retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                                                   |

### GetCommConfig(comm_req_get, comm_resp_get, timeout_ms=5, max_retry=1)

The corresponding Python script demo for this function is[`demo_get_info.py`](../../example/python/demo_get_info.py)

**Function Description:**

| Description | Get actuator communication configuration                                                                                                                                             |
| ----------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Inputs      | **comm_req_get:** Specify which parameters to request<br>**comm_resp_get:** Store retrieved config<br>**timeout_ms:** Timeout (ms), default 5<br>**max_retry:** Max retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                                                                                                      |

| Specific configuration of communication parameters      | Meaning                       | Type |
| -------------- | ----------------------------- | ---- |
| DHCP_enable    | Whether DHCP is enabled       | bool |
| PCBA_sn        | Retrieve PCBA SN              | bool |
| dns_1          | Retrieve DNS 1                | bool |
| dns_2          | Retrieve DNS 2                | bool |
| gateway        | Retrieve gateway              | bool |
| gearbox_sn     | Retrieve gearbox SN           | bool |
| mac_address    | Retrieve MAC address          | bool |
| mcu_fw_version | Retrieve MCU firmware version | bool |
| name           | Retrieve name                 | bool |
| sn             | Retrieve SN                   | bool |
| static_IP      | Retrieve static IP            | bool |
| subnet_mask    | Retrieve subnet mask          | bool |
| type           | Retrieve type                 | bool |
| uid            | Retrieve UID                  | bool |

### EnableSubscribe(subs_config, timeout_ms, max_retry)

The corresponding Python script demo for this function is[`demo_subscribe.py`](../../example/python/demo_subscribe.py)

**Function Description:**

| Description | Configure subscription mode                                                                                                   |
| ----------- | ----------------------------------------------------------------------------------------------------------------------------- |
| Inputs      | **subs_config:** Subscription configuration<br>**timeout_ms:** Timeout (ms), default 5<br>**max_retry:** Max retry, default 1 |
| Output      | Returns detailed execution status ret_e(int)                                                                               |

| Specific configuration of subscription parameters         | Meaning                                                  | Type |
| ----------------- | -------------------------------------------------------- | ---- |
| cur               | Current subscription, 0:disable, 1:enable                | int  |
| enable            | Subscription enable, 0:disable, 1:enable                 | int  |
| error             | Error code subscription, 0:disable, 1:enable             | int  |
| error_ext2        | Error code ext2 subscription, 0:disable, 1:enable        | int  |
| error_ext3        | Error code ext3 subscription, 0:disable, 1:enable        | int  |
| error_ext4        | Error code ext4 subscription, 0:disable, 1:enable        | int  |
| error_ext5        | Error code ext5 subscription, 0:disable, 1:enable        | int  |
| error_ext6        | Error code ext6 subscription, 0:disable, 1:enable        | int  |
| error_ext7        | Error code ext7 subscription, 0:disable, 1:enable        | int  |
| error_ext8        | Error code ext8 subscription, 0:disable, 1:enable        | int  |
| freq              | Subscription frequency (Hz)                              | int  |
| keepalive_time_ms | Keepalive duration (ms)                                  | int  |
| pos               | Position subscription, 0:disable, 1:enable               | int  |
| temp_coil         | Coil temperature subscription, 0:disable, 1:enable       | int  |
| temp_mos          | MOS temperature subscription, 0:disable, 1:enable        | int  |
| tor               | Torque subscription, 0:disable, 1:enable                 | int  |
| tor_em            | Electromagnetic torque subscription, 0:disable, 1:enable | int  |
| vbus              | VBUS voltage subscription, 0:disable, 1:enable           | int  |
| vel               | Velocity subscription, 0:disable, 1:enable               | int  |

### GetSubsData(subs_data)

The corresponding Python script demo for this function is[`demo_subscribe.py`](../../example/python/demo_subscribe.py)

**Function Description:**

| Description | Get latest subscription data                     |
| ----------- | ------------------------------------------------ |
| Inputs      | **subs_data:** Store retrieved subscription data |
| Output      | Returns detailed execution status ret_e(int)  |