#ifndef EDGAR_ARM_COMMUNICATIONS_H
#define EDGAR_ARM_COMMUNICATIONS_H

#include "serial_communication_channels.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct structDataCommunicationsChannels
{
    uint32_t dataTest1;
    int64_t dataTest2;
    float dataTest3;
}TDataCommunicationsChannels;

TDataCommunicationsChannels* InitEdgarArmCommunications();

#ifdef __cplusplus
}
#endif

#endif // EDGAR_ARM_COMMUNICATIONS_H
