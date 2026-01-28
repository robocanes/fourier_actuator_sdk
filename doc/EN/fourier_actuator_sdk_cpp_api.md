
# Actuator CPP SDK Interface

## Init

**Function:** Initialize the FSA object

**Parameters:**

1. `ip`: Target actuator IP
2. `net_recv_mode`: Network receive mode, optional YIELD_WAIT (blocking wait) or SPIN_WAIT (spin wait), default is blocking wait
3. `rtcko_path`: Default is an empty string, recommended to ignore

**Return:** Returns detailed execution status ret_e(int)

## Power

### OpenRelay

**Function:** Turn on the robot power board relay

**Parameters:**

1. `timeout_ms`: Timeout (ms), default 5ms
2. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

**Note:** Controls the robot's power management board; the actuator itself does not have this function

### CloseRelay

**Function:** Turn off the robot power board relay

**Parameters:**

1. `timeout_ms`: Timeout (ms), default 5ms
2. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

**Note:** Controls the robot's power management board; the actuator itself does not have this function

### Reboot

**Function:** Reboot the actuator

**Parameters:**

1. `timeout_ms`: Timeout (ms), default 5ms
2. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

## Control

### EnableControl

**Function:** Enable actuator control in position/velocity/torque/PD mode

**Parameters:**

1. `ctrl_mode`: Control mode enum (Position/Velocity/Torque/PD)
2. `timeout_ms`: Timeout (ms), default 5ms
3. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

**Note:** Internally executes the following steps; any failure will return a status code:

1. Get current position, velocity, current, torque feedback
2. Set target commands:

   1. Position = current, feedforward velocity = 0, feedforward current = 0 (for position or PD mode)
   2. Velocity = 0, feedforward current = 0 (for velocity mode)
   3. Current = 0 (for torque mode)
3. Enable actuator

### DisableControl

**Function:** Disable actuator control

**Parameters:**

1. `timeout_ms`: Timeout (ms), default 5ms
2. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

### SetPositionNoAck

**Function:** Send position target command, velocity feedforward, torque feedforward; actuator does not reply

**Parameters:**

1. `p_rad`: Target position
2. `v_ff_radps`: Velocity feedforward
3. `t_ff_Nm`: Torque feedforward

**Return:** Returns detailed execution status ret_e(int)

### SetPosition

**Function:** Send position target command, velocity feedforward, torque feedforward; actuator replies

**Parameters:**

1. `p_rad`: Target position
2. `v_ff_radps`: Velocity feedforward
3. `t_ff_Nm`: Torque feedforward
4. `timeout_ms`: Timeout (ms), default 5ms
5. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

### SetVelocityNoAck

**Function:** Send velocity target command, torque feedforward; actuator does not reply

**Parameters:**

1. `v_radps`: Target velocity
2. `t_ff_Nm`: Torque feedforward

**Return:** Returns detailed execution status ret_e(int)

### SetVelocity

**Function:** Send velocity target command, torque feedforward; actuator replies

**Parameters:**

1. `v_radps`: Target velocity
2. `t_ff_Nm`: Torque feedforward
3. `timeout_ms`: Timeout (ms), default 5ms
4. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

### SetTorqueNoAck

**Function:** Send torque target command; actuator does not reply

**Parameters:**

1. `t_Nm`: Target torque

**Return:** Returns detailed execution status ret_e(int)

### SetTorque

**Function:** Send torque target command; actuator replies

**Parameters:**

1. `t_Nm`: Target torque
2. `timeout_ms`: Timeout (ms), default 5ms
3. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

### SetPDPositionVelocityNoAck

**Function:** Send position target, velocity target, torque feedforward; actuator does not reply

**Parameters:**

1. `p_rad`: Target position
2. `v_radps`: Target velocity
3. `t_ff_Nm`: Torque feedforward

**Return:** Returns detailed execution status ret_e(int)

### SetPDPositionVelocity

**Function:** Send position target, velocity target, torque feedforward; actuator replies

**Parameters:**

1. `p_rad`: Target position
2. `v_radps`: Target velocity
3. `t_ff_Nm`: Torque feedforward
4. `timeout_ms`: Timeout (ms), default 5ms
5. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

## State

### GetPVCTTe

**Function:** Get actuator feedback: position, velocity, current, load torque, and electromagnetic torque

**Parameters:**

1. `rx_PVCTTe`: Store position, velocity, current, load torque, electromagnetic torque
2. `timeout_ms`: Timeout (ms), default 5ms
3. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

### EnableSubscribe

**Function:** Configure subscription mode

**Parameters:**

1. `subs_config`: Subscription configuration
2. `timeout_ms`: Timeout (ms), default 5ms
3. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

### GetSubsData

**Function:** Get the latest subscription data

**Parameters:**

1. `subs_data`: Store subscription data

**Return:** Status code

**Note:** Returns the latest frame every call, discards any cached frames in the socket buffer

### GetTempVbus

**Function:** Get MOS temperature, winding temperature, voltage

**Parameters:**

1. `rx_temp_vbus`: Store MOS temp, winding temp, voltage
2. `timeout_ms`: Timeout (ms), default 5ms
3. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

### GetErrCode

**Function:** Get current actuator error code

**Parameters:**

1. `rx_errcode`: Store error code
2. `timeout_ms`: Timeout (ms), default 5ms
3. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

### ParseErrCode

**Function:** Parse actuator error code

**Parameters:**

1. `err_code`: 8 uint32_t error codes obtained
2. `parsed_err_code`: Parsed error code

**Return:** Returns detailed execution status ret_e(int)

### GetTypeSubversion

**Function:** Get actuator model and subversion

**Parameters:**

1. `type_subversion`: Store model and subversion
2. `timeout_ms`: Timeout (ms), default 5ms
3. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)


## Config

### SetPIDParams

**Function:** Set position/velocity PID parameters in real time

**Parameters:**

1. `p_kp`: Position loop proportional gain
2. `v_kp`: Velocity loop proportional gain
3. `v_ki`: Velocity loop integral gain
4. `timeout_ms`: Timeout (ms), default 5ms
5. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

### GetPIDParams

**Function:** Get position/velocity PID parameters in real time

**Parameters:**

1. `rx_pid_param`: Store PID parameters
2. `timeout_ms`: Timeout (ms), default 5ms
3. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

### SetPDParams

**Function:** Set PD parameters in real time

**Parameters:**

1. `pd_kp`: PD proportional gain
2. `pd_kd`: PD derivative gain
3. `timeout_ms`: Timeout (ms), default 5ms
4. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

### GetPDParams

**Function:** Get immediate PD parameters

**Parameters:**

1. `rx_pd_param`: Store PD parameters
2. `timeout_ms`: Timeout (ms), default 5ms
3. `max_retry`: Maximum retry times, default 1

**Return:** Returns detailed execution status ret_e(int)

## Advanced

To be implemented

## Status Codes

| Code           | `SUCCESS`            | `SDK_VER_NOT_MATCH`                                      | `CTRL_PARAM_ERR`              | `INTERFACE_HANDLE_ERR`          | `ARG_ERR`                   | `NET_ERR`                | `TIMEOUT`                          | `NET_RXBUF_DATA_ERR`                               |
| -------------- | -------------------- | -------------------------------------------------------- | ----------------------------- | ------------------------------- | --------------------------- | ------------------------ | ---------------------------------- | -------------------------------------------------- |
| Value          | 0                    | -101                                                     | -102                          | -201                            | -202                        | -301                     | -302                               | -303                                               |
| Meaning        | Operation successful | SDK version mismatch                                     | Failed to get actuator config | Actuator object not initialized | Invalid interface parameter | Network error            | Network receive timeout            | Received socket buffer data does not match command |
| Possible Cause | /                    | Actuator firmware too low or SDK library/header mismatch | Model/subversion not obtained | init not executed             | Parameter invalid           | FSA network disconnected | Actuator response exceeded timeout | Socket buffer contains old frames causing mismatch |