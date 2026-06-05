# Real-Time BPM Detector

A high-performance Beats Per Minute (BPM) detection application for the **STM32F746NGH6 DSP Discovery Kit**, featuring a modern GUI built with **TouchGFX**.

## 📋 Overview

This project transforms the STM32F746G-DISCO into a real-time audio analyzer. It samples an analog audio signal, processes it using digital signal processing (DSP) techniques to identify rhythmic peaks, and displays the calculated BPM on the integrated 4.3" LCD.

### Key Features
*   **Real-Time Analysis:** Sub-second latency using the ARM Cortex-M7 DSP instructions.
*   **TouchGFX GUI:** Responsive visual feedback.
---

## 🛠 Hardware Setup

1.  **MCU:** STM32F746NGH6 (Discovery Kit).
2.  **Display:** Integrated 480x272 capacitive touch screen.
3.  **Connection:** 
    *   Connect your audio source (Phone, Instrument, etc.) to the input pin.

---

## 💻 Software Architecture

### Backend (DSP)
The audio signal is captured via **DMA** in circular mode to prevent CPU stalling. The detection engine calculates the tempo based on the time interval ($\Delta t$) between detected onsets:

$$\text{BPM} = \frac{60}{\Delta t}$$

### Frontend (UI)
The interface is managed by **TouchGFX** using the Model-View-Presenter (MVP) pattern:

---

## 🚀 Getting Started

1.  **Clone the Repo:**
    ```bash
    git clone https://github.com//WiKinter/BPM-Detection.git
    cd BPM-Detection
    ```
2.  **Generate Assets:** Open `Application.touchgfx` in **TouchGFX Designer** and click *Generate Code*.
3.  **Build:** Open the project in **STM32CubeIDE** and compile.
4.  **Flash:** Connect the board via USB and upload the binary.
