#include "audio_in.h"
#include "stm32746g_discovery_audio.h"

int16_t audioBuffer[AUDIO_BUFFER_SIZE] __attribute__((aligned(32)));
static uint32_t AudioFreq = AUDIO_FREQUENCY_44K;

// DEFINITION: Create the actual flag variable here so main.c can see it
volatile uint8_t audioDataReadyFlag = 0;

void AUDIO_IN_Init(void)
{
    /* * NOTE: If your compiler gives a warning/error here, remove the 1st parameter.
     * Standard STM32746G-Discovery BSP functions usually take 3 parameters:
     * BSP_AUDIO_IN_Init(AudioFreq, DEFAULT_AUDIO_IN_BIT_RESOLUTION, DEFAULT_AUDIO_IN_CHANNEL_NBR);
     */
	BSP_AUDIO_IN_InitEx(
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

// DMA callbacks - NOW ACTIVE
void BSP_AUDIO_IN_HalfTransfer_CallBack(void)
{
    SCB_InvalidateDCache_by_Addr((uint32_t*)audioBuffer, (AUDIO_BUFFER_SIZE / 2) * sizeof(int16_t));
    audioDataReadyFlag = 1; // Signal that the first half is ready
}

void BSP_AUDIO_IN_TransferComplete_CallBack(void)
{
    SCB_InvalidateDCache_by_Addr((uint32_t*)(audioBuffer + AUDIO_BUFFER_SIZE / 2), (AUDIO_BUFFER_SIZE / 2) * sizeof(int16_t));
    audioDataReadyFlag = 2; // Signal that the second half is ready
}
