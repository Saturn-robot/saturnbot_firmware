# OVERVIEW

This project is to driver our robot's hardwares.

# mannul

## 内部接线

## 电动机驱动板

L298N电动机驱动板

- Arduino

| L298N     | Arduino  |
| :------------- | :------------- |
| ENA | D5 |
| IN1 | D7 |
| IN2 | D8 |
| ENB | D6 |
| IN3 | D9 |
| IN4 | D10 |

- 电源

使用12V电源，因此+12v接线柱接电源正极，GND接电源负极。

- 电动机

| L298N     | MOTORS |
| :------------- | :------------- |
| OUT1 | 左电机线+ |
| OUT2 | 左电机线- |
| OUT3 | 右电机线- |
| OUT4 | 右电机线+ |

## 编码器

- Arduino

| encoders | Arduino  |
| :------------- | :------------- |
| 左A相 | D2 |
| 左B相 | D22 |
| 右A相 | D21 |
| 右B相 | D24 |
| 左+5V  | +5V |
| 左GND | GND |
| 右+5V  | +5V |
| 右GND | GND |

## 外部接线

在每个杜邦线上都贴有相应的标识，以标识这些线对应的接口。

