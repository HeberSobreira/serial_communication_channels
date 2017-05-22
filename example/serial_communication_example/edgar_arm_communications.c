#include "edgar_arm_communications.h"

TDataCommunicationsChannels DataCommunicationsChannels_;

TDataCommunicationsChannels *InitEdgarArmCommunications()
{
    AddVallueToChannel_int32_t('g', (int32_t *)&(DataCommunicationsChannels_.dataTest1));
    AddVallueToChannel_int64_t('r', &(DataCommunicationsChannels_.dataTest2));
    AddVallueToChannel_float('r', &(DataCommunicationsChannels_.dataTest3));

    return &DataCommunicationsChannels_;
}
