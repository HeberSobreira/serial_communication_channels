#include "serial_communications_example.h"

TDataCommunicationsChannels DataCommunicationsChannels_;

TDataCommunicationsChannels *InitExampleCommunications()
{
    AddValueToChannel_int32_t('g', &(DataCommunicationsChannels_.dataTest1));
    AddValueToChannel_int64_t('r', &(DataCommunicationsChannels_.dataTest2));
    AddValueToChannel_float('r', &(DataCommunicationsChannels_.dataTest3));

    return &DataCommunicationsChannels_;
}
