#include "edgar_arm_communications.h"

TDataCommunicationsChannels DataCommunicationsChannels_;

TDataCommunicationsChannels *InitEdgarArmCommunications()
{
    AddValueToChannel_int32_t('g', &(DataCommunicationsChannels_.dataTest1));
    AddValueToChannel_int64_t('r', &(DataCommunicationsChannels_.dataTest2));
    AddValueToChannel_float('r', &(DataCommunicationsChannels_.dataTest3));

    return &DataCommunicationsChannels_;
}
