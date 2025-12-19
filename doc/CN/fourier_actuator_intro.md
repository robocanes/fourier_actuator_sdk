# 执行器控制模式

## 电流模式

![FSA-电流控制模式-控制框图.drawio](../images/FSA-电流控制模式-控制框图.drawio.svg "电流模式")

## 速度模式

![FSA-速度控制模式-控制框图.drawio](../images/FSA-速度控制模式-控制框图.drawio.svg "速度模式")

## 位置模式

![FSA-位置控制模式-控制框图.drawio](../images/FSA-位置控制模式-控制框图.drawio.svg "位置模式")

$$
I_{q_{set_{j}}} = r K_{d}^{series} (r K_{p}^{series} q_{err}- \dot{q} G_{\omega})
$$

$$
\rm{(A) = (A \cdot s) \left((\frac{1}{deg \cdot s})(deg) - (\frac{deg}{s})(\frac{1}{deg}) \right)}
$$

- $K_{p}^{series}: \rm{A \cdot s}$
- $K_{d}^{series}: \rm{\frac{1}{deg \cdot s}}$

位置模式下如果将速度环的积分系数设置为 0，则等价于**串联 PD**。

## PD 模式

![FSA-PD 控制模式-控制框图.drawio](../images/FSA-PD控制模式-控制框图.drawio.svg "PD 模式")

$$
I_{q_{set_{j}}} = \frac{(K_{p}^{parallel} q_{err} - K_{d}^{parallel} \dot{q})}{K_{t}} \cdot \frac{\pi}{180^{\circ}}
$$

$$
\rm{(A) = \frac{(\frac{Nm}{rad}) (deg) - (\frac{Nm \cdot s}{rad}) (\frac{deg}{s})}{(\frac{Nm}{A})} \cdot \frac{(rad)}{(deg)}}
$$

- $K_{p}^{parallel}: \rm{\frac{Nm}{rad}}$
- $K_{d}^{parallel}: \rm{\frac{Nm \cdot s}{rad}}$

## 位置模式与 PD 模式参数转换

- 串联参数到并联参数（位置模式 --> PD 模式）

$$
K_{p}^{parallel} = r^{2} K_{t} K_{p}^{series} K_{d}^{series} \cdot \frac{180^{\circ}}{\pi}
$$

$$
K_{d}^{parallel} = r K_{t} K_{d}^{series} G_{\omega} \cdot \frac{180^{\circ}}{\pi}
$$

- 并联参数到串联参数（PD 模式 --> 位置模式）

$$
K_{p}^{series} = \frac{K_{p}^{parallel} G_{\omega}}{r K_{d}^{parallel}}
$$

$$
K_{d}^{series} = \frac{K_{d}^{parallel}}{r K_{t} G_{\omega}} \cdot \frac{\pi}{180^{\circ}}
$$

## 符号表

|      符号       |                    值                     |         单位         |       释义       |
| :-------------: | :---------------------------------------: | :------------------: | :--------------: |
|     $q_{d}$     |                   变量                    |      $\rm{deg}$      |     目标位置     |
|       $q$       |                   变量                    |      $\rm{deg}$      |     反馈位置     |
|    $q_{err}$    |                   变量                    |      $\rm{deg}$      |     位置误差     |
|  $\dot{q_{d}}$  |                   变量                    | $\rm{\frac{deg}{s}}$ |     目标速度     |
|    $\dot{q}$    |                   变量                    |     $\rm{deg/s}$     |     反馈速度     |
| $\dot{q}_{err}$ |                   变量                    |     $\rm{deg/s}$     |     速度误差     |
|  $I_{q_{set}}$  |                   变量                    |       $\rm{A}$       | 目标 $q$ 轴电流  |
|     $I_{q}$     |                   变量                    |       $\rm{A}$       | 反馈 $q$ 轴电流  |
|    $\tau_d$     |                   变量                    |   $\rm{N \cdot m}$   |     目标力矩     |
|  $T_{\omega}$   |                   $0.1$                   |      $\rm{ms}$       |  速度环控制周期  |
|     $K_{t}$     |         常量（由执行器型号决定）          |          -           | 电流力矩转换系数 |
|       $r$       |         常量（由执行器型号决定）          |          -           |      减速比      |
|    $N_{pp}$     |         常量（由执行器型号决定）          |          -           |      极对数      |
|  $G_{\omega}$   | $\rm{\frac{r \cdot N_{pp}}{360^{\circ}}}$ | $\rm{\frac{1}{deg}}$ |   速度转换系数   |

# 执行器其他功能

## PVCT 反馈滤波

| 默认截止频率 fc (Hz) | 增益 gain                        | 周期 ts (s)               |
| -------------------- | -------------------------------- | ------------------------- |
| 200（用户可调节）    | 0.9409（根据截止频率和周期计算） | 5e-5（20KHz 与 FOC 同频） |

$$
gain = \frac{1}{(1 + 2 \pi f_{c} T_{s})}
$$

$$
out_{j} = (1 - gain) \cdot input_{j} + gain \cdot out_{j - 1}
$$

> 该滤波会导致反馈数据延迟，所以尽量不要在自己用户程序中再叠加一个滤波，或者将该滤波截止频率设置的尽可能大以避免影响。

![image](../images/一阶低通滤波器.png "一阶低通滤波器")

![image](../images/伯德图1.png "伯德图")

输入信号：200Hz 正弦

![image](../images/一阶低通滤波器仿真结果.png "一阶低通滤波器仿真结果")

![image](../images/伯德图2.png "伯德图")

## 回零模式

> 该模式仅在支持【双编码器】的 FSA 上可用。

回零模式将出轴编码器数据作为位置反馈（全闭环），相较于使用位置模式回到零位，回零模式能够更加精准的回到零位，避免了减速机背隙和内外编码器之间的安装误差导致的零位偏移问题。

![FSA-回零模式-控制框图.drawio](../images/FSA-回零模式-控制框图.drawio.svg "回零模式")

## 摩擦补偿

摩擦补偿功能需要执行了执行器摩擦辨识之后才能够开启。

摩擦辨识需要单独拆下执行器，然后通过上位机下发摩擦辨识指令，执行器将自动开始辨识，期间执行器将会高速旋转，辨识结束后得到的摩擦系数将会保存在执行器中。

![FSA-摩擦补偿-控制框图.drawio](../images/FSA-摩擦补偿-控制框图.drawio.svg "摩擦补偿")

## 负载观测器

开启负载补偿后，执行器的低速性能将大大提升，若负载补偿参数调整合适，在极低的转速下（1 deg/s 以下）能够维持很小的速度波动。

![FSA-负载观测器-控制框图.drawio](../images/FSA-负载观测器-控制框图.drawio.svg "负载观测器")
