[![Project Status: WIP - Initial development is in progress, but there has not yet been a stable, usable release suitable for the public.](http://www.repostatus.org/badges/latest/wip.svg)](http://www.repostatus.org/#wip)

# 概述

本固件程序为Saturn rotbot(本组织正在开发的机器人)的专用固件程序，核心部件是Arduino Mega 2560。目前主要支持AB相编码器、L298N双路电动机驱动板、GY-85 IMU惯性测量模组等传感器。

# 硬件参数

## 外形参数

| 参数 | 值 |
| :------------- | :------------- |
| 轮胎直径       | 65mm      |
| 尺寸 | 198.07x186mm |
| 两轮间距 | 145.07 |

## 电动机参数

| 参数     | 值  |
| :------------- | :------------- |
| 工作电压  | 7～13V  |
|额定功率 | 7W|
|电机类型 | 永磁有刷|
|堵转电流|5.4A|
|堵转扭矩|15kgf.cm|
|额定电流|540mA|
|额定扭矩|1.5kgf.cm|
|原始转速|15000rpm|
|空载转速|500rpm|
|减速比|1:30|
|输出轴直径|6mm|
|输出轴类型|D型偏心轴|

**NOTE：**以上数据在12V环境下测量的到。

## 编码器参数

|参数|值|
|:-------|:-----|
|型号|AB相增量式霍尔（磁）编码器|
|线数|390（以减速器输出轴测量）|
|供电电压|5.0V|
|特色功能|自带上拉整形，单片机可以直接读取|

**NOTE:**详细内容请访问:<https://github.com/Saturn-robot/Encoder_driver>

## IMU参数

|参数|值|
|:-------|:-----|
|型号|GY-85|
|加速度计分辨率|13位|
|陀螺仪敏感范围因子|14.375 LSB pro °/s|
|电子罗盘数字分辨率|0.92|

**NOTE:**详细内容请访问:<https://github.com/Saturn-robot/GY85_driver>

# 引脚分配

## L298N电动机驱动板


| L298N     | Arduino  |
| :------------- | :------------- |
| ENA | D5 |
| IN1 | D7 |
| IN2 | D8 |
| ENB | D6 |
| IN3 | D9 |
| IN4 | D10 |

## AB相编码器

| Encoders | Arduino  |
| :------------- | :------------- |
| 左A相 | D2 |
| 左B相 | D22 |
| 右A相 | D3 |
| 右B相 | D24 |
| 左+5V  | +5V |
| 左GND | GND |
| 右+5V  | +5V |
| 右GND | GND |

## GY85惯性测量模组

| GY85 | Arduino  |
| :------------- | :------------- |
| VCC | +5V |
| GND | GND |
| SDA | D20 |
| SCL | D21 |
