# FOC 控制系统项目

## 项目概述

本项目实现基于 Simulink 的磁场定向控制(FOC)算法，用于电机控制。项目包含：

- Simulink 模型设计(foc.slx)
- 使用 Embedded Coder 生成的 C 代码(FOC_control_ert_rtw/)
- PCB 设计文件(PCB_layout.pdf)

## 硬件要求

- 目标硬件：STM32G4 系列 MCU
- 电机类型：三相永磁同步电机(PMSM)
- 传感器：编码器
- 功率驱动：三相逆变器

## 控制模式

- 位置模式：Mode = 1 设置电机转动到指定位置
- 速度模式：Mode = 2 设置电机转动到指定速度
- 力矩模式：Mode = 3 设置电机转动的指定力矩

## 软件依赖

- MATLAB/Simulink R2021a 或更高版本
- Simulink Coder
- Embedded Coder
- STM32 硬件支持包

## 目录结构

```
simulink_to_FOC/
├── PCB_layout.pdf                # PCB设计文件
├── FOC_control_ert_rtw/         # 生成的嵌入式代码
│   ├── FOC_control.c/h          # 主算法实现
│   ├── ert_main.c               # 主程序入口
│   └── html/                    # 代码生成报告
└── simulink_project/            # Simulink项目文件
    ├── Foc_final.prj            # 项目配置文件
    ├── foc.slx                  # 主Simulink模型
    └── resources/               # 项目资源文件
```
