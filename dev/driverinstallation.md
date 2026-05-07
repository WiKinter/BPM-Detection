# Audio Treiber von [Git Repo]()https://github.com/STMicroelectronics/STM32CubeF7.git) leider keine passenden Treiber vorhanden.

cd ~/git/STM32CubeF7
git submodule update --init --recursive # Damit Treiber auch gepullt werden
find Drivers/BSP -name "stm32746g_discovery_audio.h"
find Drivers/BSP -name "wm8994.h"

Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.h
Drivers/BSP/Components/wm8994/wm8994.h
