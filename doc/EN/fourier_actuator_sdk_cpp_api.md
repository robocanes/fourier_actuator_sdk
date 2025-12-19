# Actuator CPP SDK API

## Init

**Function:** Initialize FSA object

**Parameters:**

1. `ip`: Target actuator IP;
2. `net_recv_mode`: Network receive mode, optional YIELD_WAIT (blocking wait) or SPIN_WAIT (spin wait).

**Return Value:** Status code

## Power

### OpenRelay

**Function:** Open power control board relay

**Parameters:**

1. `timeout_ms`: Timeout (ms), default is 5ms;
2. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

### CloseRelay

**Function:** Close power control board relay

**Parameters:**

1. `timeout_ms`: Timeout (ms), default is 5ms;
2. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

### Reboot

**Function:** Reboot actuator

**Parameters:**

1. `timeout_ms`: Timeout (ms), default is 5ms;
2. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

## Control

### EnableControl

**Function:** Enable actuator position/velocity/torque/PD mode

**Parameters:**

1. `ctrl_mode`: Control mode enumeration (position/velocity/torque/PD);
2. `timeout_ms`: Timeout (ms), default is 5ms;
3. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

**Note:** This interface internally executes the following commands sequentially. Failure of any step will cause the interface to return a status code directly:

1. Get current position/velocity/current/torque feedback;
2. Set target position/velocity/current command;
   1. Set target position to current position, feedforward velocity to 0, feedforward current to 0 (if enabling position or PD mode);
   2. Set target velocity to 0, feedforward current to 0 (if enabling velocity mode);
   3. Set target current to 0 (if enabling torque mode).
3. Enable.

### DisableControl

**Function:** Disable actuator

**Parameters:**

1. `timeout_ms`: Timeout (ms), default is 5ms;
2. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

### SetPositionNoAck

**Function:** Send target position command, feedforward velocity command, feedforward torque command, actuator does not reply

**Parameters:**

1. `tx_pos`: Target position;
2. `tx_vel_ff`: Feedforward velocity;
3. `tx_tor_ff`: Feedforward torque;
4. `timeout_ms`: Timeout (ms), default is 5ms;
5. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

**Note:** This interface will convert target position and feedforward velocity from radians to degrees, and convert feedforward torque to current value before sending to the actuator. Please check that the actuator parameter configuration (motor model and reduction ratio) is correct before use.

### SetPosition

**Function:** Send target position command, feedforward velocity command, feedforward torque command, actuator replies with status

**Parameters:**

1. `tx_pos`: Target position;
2. `tx_vel_ff`: Feedforward velocity;
3. `tx_tor_ff`: Feedforward torque;
4. `timeout_ms`: Timeout (ms), default is 5ms;
5. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

**Note:** This interface will convert target position and feedforward velocity from radians to degrees, and convert feedforward torque to current value before sending to the actuator. Please check that the actuator parameter configuration (motor model and reduction ratio) is correct before use.

### SetVelocityNoAck

**Function:** Send target velocity command, feedforward torque command, actuator does not reply

**Parameters:**

1. `tx_vel`: Target velocity;
2. `tx_tor_ff`: Feedforward torque;
3. `timeout_ms`: Timeout (ms), default is 5ms;
4. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

**Note:** This interface will convert target velocity from radians to degrees, and convert feedforward torque to current value before sending to the actuator. Please check that the actuator parameter configuration (motor model and reduction ratio) is correct before use.

### SetVelocity

**Function:** Send target velocity command, feedforward torque command, actuator replies with status

**Parameters:**

1. `tx_vel`: Target velocity;
2. `tx_tor_ff`: Feedforward torque;
3. `timeout_ms`: Timeout (ms), default is 5ms;
4. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

**Note:** This interface will convert target velocity from radians to degrees, and convert feedforward torque to current value before sending to the actuator. Please check that the actuator parameter configuration (motor model and reduction ratio) is correct before use.

### SetTorqueNoAck

**Function:** Send target torque command, actuator does not reply

**Parameters:**

1. `tx_tor`: Target torque;
2. `timeout_ms`: Timeout (ms), default is 5ms;
3. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

**Note:** This interface will convert target torque to current value before sending to the actuator. Please check that the actuator parameter configuration (motor model and reduction ratio) is correct before use.

### SetTorque

**Function:** Send target torque command, actuator replies with status

**Parameters:**

1. `tx_tor`: Target torque;
2. `timeout_ms`: Timeout (ms), default is 5ms;
3. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

**Note:** This interface will convert target torque to current value before sending to the actuator. Please check that the actuator parameter configuration (motor model and reduction ratio) is correct before use.

## SetPDPositionVelocityNoAck

**Function:** Send target position command, target velocity command, feedforward torque command, actuator does not reply

**Parameters:**

1. `tx_pos`: Target position;
2. `tx_vel`: Target velocity;
3. `tx_tor_ff`: Feedforward torque;
4. `timeout_ms`: Timeout (ms), default is 5ms;
5. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

**Note:** This interface will convert target position and target velocity from radians to degrees. PD mode does not need to convert feedforward torque to current value. FSA treats it as feedforward torque by default. Please check that the actuator parameter configuration (motor model and reduction ratio) is correct before use.

## SetPDPositionVelocity

**Function:** Send target position command, target velocity command, feedforward torque command, actuator replies with status

**Parameters:**

1. `tx_pos`: Target position;
2. `tx_vel`: Target velocity;
3. `tx_tor_ff`: Feedforward torque;
4. `timeout_ms`: Timeout (ms), default is 5ms;
5. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

**Note:** This interface will convert target position and target velocity from radians to degrees. PD mode does not need to convert feedforward torque to current value. FSA treats it as feedforward torque by default. Please check that the actuator parameter configuration (motor model and reduction ratio) is correct before use.

## State

### GetPVCTTe

**Function:** Get actuator feedback position, velocity, current, load torque and electromagnetic torque

**Parameters:**

1. `rx_pvctte`: Store the obtained position, velocity, current, load torque and electromagnetic torque;
2. `timeout_ms`: Timeout (ms), default is 5ms;
3. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

**Note:** This interface will convert feedback position and feedback velocity from degrees to radians, and convert feedback current to electromagnetic torque. Please check that the actuator parameter configuration (motor model and reduction ratio) is correct before use.

### EnableSubscribe

**Function:** Enable subscribe mode

**Parameters:**

1. `tx_subs_config`: Subscribe mode configuration;
2. `timeout_ms`: Timeout (ms), default is 5ms;
3. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

### GetSubsData

**Function:** Get the latest subscription data

**Parameters:**

1. `subs_data`: Store the obtained subscription data;

**Return Value:** Status code

**Note:** This interface guarantees that each call returns the latest frame of subscription data and discards cached data frames in the Socket buffer.

### GetTempVbus

**Function:** Get actuator temperature and bus voltage

**Parameters:**

1. `rx_temp_vbus`: Store the obtained actuator temperature and bus voltage;
2. `timeout_ms`: Timeout (ms), default is 5ms;
3. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

**Note:** This interface internally executes the following commands:

1. Get actuator temperature;
2. Get actuator bus voltage.

### GetErrCode

**Function:** Get actuator error

**Parameters:**

1. `rx_error`: Store the obtained error code array, a total of 8 error codes;
2. `timeout_ms`: Timeout (ms), default is 5ms;
3. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

## Config

### SetPIDParams

**Function:** Set temporary immediately effective (imm) PID parameters

**Parameters:**

1. `tx_pos_kp`: Position loop Kp;
2. `tx_vel_kp`: Velocity loop Kp;
3. `tx_vel_ki`: Velocity loop Ki;
4. `timeout_ms`: Timeout (ms), default is 5ms;
5. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

### GetPIDParams

**Function:** Get temporary immediately effective (imm) PID parameters

**Parameters:**

1. `rx_pid_param`: Store the obtained temporary immediately effective (imm) PID parameters;
2. `timeout_ms`: Timeout (ms), default is 5ms;
3. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

### SetPDParams

**Function:** Set temporary immediately effective (imm) PD parameters

**Parameters:**

1. `tx_pd_kp`: PD loop Kp;
2. `tx_pd_kd`: PD loop Kd;
3. `timeout_ms`: Timeout (ms), default is 5ms;
4. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

### GetPDParams

**Function:** Get temporary immediately effective (imm) PD parameters

**Parameters:**

1. `rx_pd_param`: Store the obtained temporary immediately effective (imm) PD parameters;
2. `timeout_ms`: Timeout (ms), default is 5ms;
3. `max_retry`: Maximum retry count, default is 0 times.

**Return Value:** Status code

## Advanced

To be implemented

## Status Codes

| Status Code | `SUCCESS` | `SDK_VER_NOT_MATCH` | `CTRL_PARAM_ERR` | `INTERFACE_HANDLE_ERR` | `ARG_ERR` | `NET_ERR` | `TIMEOUT` | `NET_RXBUF_DATA_ERR` |
| :------: | :-------: | :-----------------------------------------------: | :--------------------: | :--------------------: | :----------------------: | :-----------------------: | :----------------------------------------: | :--------------------------------------------------: |
| Value | `0` | `-101` | `-102` | `-201` | `-202` | `-301` | `-302` | `-303` |
| Meaning | Operation successful | SDK version mismatch | Actuator configuration parameter error | Actuator object not initialized | Invalid interface parameter | Network error | Network receive timeout | Network receive buffer data does not match sent command |
| Possible Cause | / | Actuator firmware version too low or SDK dynamic library and header file version mismatch | Model and version number not obtained successfully | Init function not executed | Parameters passed to interface do not meet requirements | FSA network for corresponding IP is disconnected | Waiting time for receiving actuator return data exceeds specified timeout | Received system socket input buffer previous frames cause command mismatch |
