# Actuator Introduction

The physical quantity symbols involved in the following descriptions are explained in the table below:

|      Symbol     |                 Value                |       Unit       | Description                     |
| :-------------: | :----------------------------------: | :--------------: | :------------------------------ |
|     $q_{d}$     |               Variable               |    $\rm{rad}$    | Target position                 |
|       $q$       |               Variable               |    $\rm{rad}$    | Feedback position               |
|    $q_{err}$    |               Variable               |    $\rm{rad}$    | Position error                  |
|  $\dot{q_{d}}$  |               Variable               |   $\rm{rad/s}$   | Target velocity                 |
|    $\dot{q}$    |               Variable               |   $\rm{rad/s}$   | Feedback velocity               |
| $\dot{q}_{err}$ |               Variable               |   $\rm{rad/s}$   | Velocity error                  |
|  $I_{q_{set}}$  |               Variable               |     $\rm{A}$     | Target $q$-axis current         |
|     $I_{q}$     |               Variable               |     $\rm{A}$     | Feedback $q$-axis current       |
|     $\tau_d$    |               Variable               | $\rm{N \cdot m}$ | Target torque                   |
|   $T_{\omega}$  |                 $0.1$                |     $\rm{ms}$    | Velocity loop control period    |
|     $K_{t}$     | Constant (depends on actuator model) |         –        | Current-to-torque coefficient   |
|       $r$       | Constant (depends on actuator model) |         –        | Gear ratio                      |
|     $N_{pp}$    | Constant (depends on actuator model) |         –        | Number of pole pairs            |
|   $G_{\omega}$  |                   $1$                  |         –        | Velocity conversion coefficient |

## Actuator Control Modes

### Current Mode

![FSA-Current Control Mode Block Diagram](../images/FSA-电流控制模式-控制框图.drawio.svg "Current Mode")

### Velocity Mode

![FSA-Velocity Control Mode Block Diagram](../images/FSA-速度控制模式-控制框图.drawio.svg "Velocity Mode")

### Position Mode

![FSA-Position Control Mode Block Diagram](../images/FSA-位置控制模式-控制框图.drawio.svg "Position Mode")

$$
I_{q_{set_{j}}} = r K_{d}^{series} (r K_{p}^{series} q_{err}- \dot{q} G_{\omega})
$$

$$
\rm{(A) = (\frac{A \cdot s}{rad}) \left((\frac{1}{s})(rad) - (\frac{rad}{s}) \right)}
$$

* $K_{p}^{series}: \rm{\frac{1}{s}}$
* $K_{d}^{series}: \rm{\frac{A \cdot s}{rad}}$

In position mode, if the integral coefficient of the velocity loop is set to 0, it is equivalent to a **series PD controller**.

### PD Mode

![FSA-PD Control Mode Block Diagram](../images/FSA-PD控制模式-控制框图.drawio.svg "PD Mode")

$$
I_{q_{set_{j}}} = \frac{(K_{p}^{parallel} q_{err} - K_{d}^{parallel} \dot{q})}{K_{t}}
$$

$$
\rm{(A) = \frac{(\frac{Nm}{rad}) (rad) - (\frac{Nm \cdot s}{rad}) (\frac{rad}{s})}{(\frac{Nm}{A})}}
$$

* $K_{p}^{parallel}: \rm{\frac{Nm}{rad}}$
* $K_{d}^{parallel}: \rm{\frac{Nm \cdot s}{rad}}$

## Other Actuator Functions

### PVCT Feedback Filtering

| Default cutoff frequency fc (Hz) | Gain                                                 | Period ts (s)              |
| -------------------------------- | ---------------------------------------------------- | -------------------------- |
| 200 (user adjustable)            | 0.9409 (calculated from cutoff frequency and period) | 5e-5 (20 kHz, same as FOC) |

$$
gain = \frac{1}{(1 + 2 \pi f_{c} T_{s})}
$$

$$
out_{j} = (1 - gain) \cdot input_{j} + gain \cdot out_{j - 1}
$$

> This filter introduces delay in feedback data. Therefore, it is recommended not to stack another filter in user applications, or to set the cutoff frequency as high as possible to minimize the impact.

![image](../images/一阶低通滤波器.png "First-order Low-pass Filter")

![image](../images/伯德图1.png "Bode Plot")

Input signal: 200 Hz sine wave

![image](../images/一阶低通滤波器仿真结果.png "First-order Low-pass Filter Simulation Result")

![image](../images/伯德图2.png "Bode Plot")

### Load Observer

After enabling load compensation, the low-speed performance of the actuator will be significantly improved.
If the load compensation parameters are properly tuned, very small speed fluctuations can be maintained at extremely low speeds (below 1 deg/s).

![FSA-Load Observer Control Block Diagram](../images/FSA-负载观测器-控制框图.drawio.svg "Load Observer")