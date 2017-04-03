[![Project Status: WIP - Initial development is in progress, but there has not yet been a stable, usable release suitable for the public.](http://www.repostatus.org/badges/latest/wip.svg)](http://www.repostatus.org/#wip)

# 概述

本固件程序为Saturn rotbot(本组织正在开发的机器人)的专用固件程序，核心部件是Arduino Mega 2560。目前主要支持AB相编码器、L298N双路电动机驱动板、GY-85 IMU惯性测量模组等传感器。

# 引脚分配

- L298N电动机驱动板


| L298N     | Arduino  |
| :------------- | :------------- |
| ENA | D5 |
| IN1 | D7 |
| IN2 | D8 |
| ENB | D6 |
| IN3 | D9 |
| IN4 | D10 |

- AB相编码器

| encoders | Arduino  |
| :------------- | :------------- |
| 左A相 | D2 |
| 左B相 | D22 |
| 右A相 | D3 |
| 右B相 | D24 |
| 左+5V  | +5V |
| 左GND | GND |
| 右+5V  | +5V |
| 右GND | GND |

- GY85惯性测量模组

| GY85 | Arduino  |
| :------------- | :------------- |
| VCC | +5V |
| GND | GND |
| SDA | D20 |
| SCL | D21 |
