
#include "audio_in.h"
#include "stm32746g_discovery_audio.h"

int16_t audioBuffer[AUDIO_BUFFER_SIZE];

static uint32_t AudioFreq = AUDIO_FREQUENCY_44K;

void AUDIO_IN_Init(void)
{
    BSP_AUDIO_IN_Init(
        INPUT_DEVICE_INPUT_LINE_1,
        AudioFreq,
        DEFAULT_AUDIO_IN_BIT_RESOLUTION,
        DEFAULT_AUDIO_IN_CHANNEL_NBR
    );

    BSP_AUDIO_IN_SetVolume(80);
}

void AUDIO_IN_Start(void)
{
    BSP_AUDIO_IN_Record((uint16_t*)audioBuffer, AUDIO_BUFFER_SIZE);
}

// DMA callbacks
void BSP_AUDIO_IN_HalfTransfer_CallBack(void)
{
    // Erste Hälfte auswerten
}

void BSP_AUDIO_IN_TransferComplete_CallBack(void)
{
    // Zweite Hälfte auswerten
}