# Actuator Control Modes

## Current Mode

![FSA-电流控制模式-控制框图.drawio](../images/FSA-电流控制模式-控制框图.drawio.svg "Current Mode")

## Velocity Mode

![FSA-速度控制模式-控制框图.drawio](../images/FSA-速度控制模式-控制框图.drawio.svg "Velocity Mode")

## Position Mode

![FSA-位置控制模式-控制框图.drawio](../images/FSA-位置控制模式-控制框图.drawio.svg "Position Mode")

$$
I_{q_{set_{j}}} = r K_{d}^{series} (r K_{p}^{series} q_{err}- \dot{q} G_{\omega})
$$

$$
\rm{(A) = (A \cdot s) \left((\frac{1}{deg \cdot s})(deg) - (\frac{deg}{s})(\frac{1}{deg}) \right)}
$$

- $K_{p}^{series}: \rm{A \cdot s}$
- $K_{d}^{series}: \rm{\frac{1}{deg \cdot s}}$

If the integral coefficient of the velocity loop is set to 0 in position mode, it is equivalent to **Series PD**.

## PD Mode

![FSA-PD 控制模式-控制框图.drawio](../images/FSA-PD控制模式-控制框图.drawio.svg "PD Mode")

$$
I_{q_{set_{j}}} = \frac{(K_{p}^{parallel} q_{err} - K_{d}^{parallel} \dot{q})}{K_{t}} \cdot \frac{\pi}{180^{\circ}}
$$

$$
\rm{(A) = \frac{(\frac{Nm}{rad}) (deg) - (\frac{Nm \cdot s}{rad}) (\frac{deg}{s})}{(\frac{Nm}{A})} \cdot \frac{(rad)}{(deg)}}}
$$

- $K_{p}^{parallel}: \rm{\frac{Nm}{rad}}$
- $K_{d}^{parallel}: \rm{\frac{Nm \cdot s}{rad}}$

## Parameter Conversion between Position Mode and PD Mode

- Series parameters to parallel parameters (Position Mode --> PD Mode)

$$
K_{p}^{parallel} = r^{2} K_{t} K_{p}^{series} K_{d}^{series} \cdot \frac{180^{\circ}}{\pi}
$$

$$
K_{d}^{parallel} = r K_{t} K_{d}^{series} G_{\omega} \cdot \frac{180^{\circ}}{\pi}
$$

- Parallel parameters to series parameters (PD Mode --> Position Mode)

$$
K_{p}^{series} = \frac{K_{p}^{parallel} G_{\omega}}{r K_{d}^{parallel}}
$$

$$
K_{d}^{series} = \frac{K_{d}^{parallel}}{r K_{t} G_{\omega}} \cdot \frac{\pi}{180^{\circ}}
$$

## Symbol Table

| Symbol | Value | Unit | Description |
| :-------------: | :---------------------------------------: | :------------------: | :--------------: |
|     $q_{d}$     | Variable |      $\rm{deg}$      | Desired position     |
|       $q$       | Variable |      $\rm{deg}$      | Feedback position     |
|    $q_{err}$    | Variable |      $\rm{deg}$      | Position error     |
|  $\dot{q_{d}}$  | Variable | $\rm{\frac{deg}{s}}$ | Desired velocity     |
|    $\dot{q}$    | Variable |     $\rm{deg/s}$     | Feedback velocity     |
| $\dot{q}_{err}$ | Variable |     $\rm{deg/s}$     | Velocity error     |
|  $I_{q_{set}}$  | Variable |       $\rm{A}$       | Desired $q$-axis current  |
|     $I_{q}$     | Variable |       $\rm{A}$       | Feedback $q$-axis current  |
|    $\tau_d$     | Variable |   $\rm{N \cdot m}$   | Desired torque     |
|  $T_{\omega}$   | $0.1$ |      $\rm{ms}$       | Velocity loop control period  |
|     $K_{t}$     | Constant (determined by actuator model) |          -           | Current-to-torque conversion coefficient |
|       $r$       | Constant (determined by actuator model) |          -           | Reduction ratio      |
|    $N_{pp}$     | Constant (determined by actuator model) |          -           | Pole pairs      |
|  $G_{\omega}$   | $\rm{\frac{r \cdot N_{pp}}{360^{\circ}}}$ | $\rm{\frac{1}{deg}}$ | Velocity conversion coefficient   |

# Other Actuator Features

## PVCT Feedback Filtering

| Default Cutoff Frequency fc (Hz) | Gain | Period ts (s) |
| -------------------- | -------------------------------- | ------------------------- |
| 200 (user adjustable) | 0.9409 (calculated from cutoff frequency and period) | 5e-5 (20KHz, same frequency as FOC) |

$$
gain = \frac{1}{(1 + 2 \pi f_{c} T_{s})}
$$

$$
out_{j} = (1 - gain) \cdot input_{j} + gain \cdot out_{j - 1}
$$

> This filter will cause feedback data delay, so try not to add another filter in your user program, or set the filter cutoff frequency as high as possible to avoid impact.

![image](../images/一阶低通滤波器.png "First-order Low-pass Filter")

![image](../images/伯德图1.png "Bode Plot")

Input signal: 200Hz sine wave

![image](../images/一阶低通滤波器仿真结果.png "First-order Low-pass Filter Simulation Results")

![image](../images/伯德图2.png "Bode Plot")

## Homing Mode

> This mode is only available on FSA with **dual encoders**.

Homing mode uses the output shaft encoder data as position feedback (full closed-loop). Compared to using position mode to return to zero, homing mode can return to zero more accurately, avoiding zero position offset issues caused by reducer backlash and installation errors between internal and external encoders.

![FSA-回零模式-控制框图.drawio](../images/FSA-回零模式-控制框图.drawio.svg "Homing Mode")

## Friction Compensation

The friction compensation function can only be enabled after the actuator friction identification has been performed.

For friction identification, the actuator needs to be removed separately, and then the friction identification command is sent through the host computer. The actuator will automatically start identification, during which the actuator will rotate at high speed. After identification is complete, the obtained friction coefficients will be saved in the actuator.

![FSA-摩擦补偿-控制框图.drawio](../images/FSA-摩擦补偿-控制框图.drawio.svg "Friction Compensation")

## Load Observer

After enabling load compensation, the low-speed performance of the actuator will be greatly improved. If the load compensation parameters are properly adjusted, very small velocity fluctuations can be maintained at extremely low speeds (below 1 deg/s).

![FSA-负载观测器-控制框图.drawio](../images/FSA-负载观测器-控制框图.drawio.svg "Load Observer")
