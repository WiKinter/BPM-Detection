#ifndef AUDIO_IN_H
#define AUDIO_IN_H

#include "main.h"

#define AUDIO_BUFFER_SIZE 4096

extern int16_t audioBuffer[AUDIO_BUFFER_SIZE];

void AUDIO_IN_Init(void);
void AUDIO_IN_Start(void);

#endif