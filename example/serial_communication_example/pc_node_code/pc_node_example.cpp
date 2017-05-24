#include "ros/ros.h"
#include "SerialStream.h"
#include "serial_communication_channels/serial_communication_channels.h"
#include "serial_communications_example.h"

using namespace LibSerial;
SerialStream my_serial_stream ;


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "serial_communications_example");
    ros::NodeHandle nh;

    std::cout << "Program initialized!" << std::endl;

    //----------------------------Arduino communication -----------------------------------------------------------//

    my_serial_stream.Open("/dev/ttyACM0") ;

    if ( ! my_serial_stream.good() )
    {
        std::cerr << "[" << __FILE__ << ":" << __LINE__ << "] "
                  << "Error: Could not open serial port."
                  << std::endl ;
        exit(1) ;
    }

    my_serial_stream.SetBaudRate( SerialStreamBuf::BAUD_9600 ) ;

    if ( ! my_serial_stream.good() )
    {
        std::cerr << "Error: Could not set the baud rate." <<
                     std::endl ;
        exit(1) ;
    }

    my_serial_stream.SetCharSize( SerialStreamBuf::CHAR_SIZE_8 ) ;

    if ( ! my_serial_stream.good() )
    {
        std::cerr << "Error: Could not set the character size." <<
                     std::endl ;
        exit(1) ;
    }

    my_serial_stream.SetNumOfStopBits(1) ;

    if ( ! my_serial_stream.good() )
    {
        std::cerr << "Error: Could not set the number of stop bits." <<
                     std::endl ;
    }

    my_serial_stream.SetParity( SerialStreamBuf::PARITY_NONE ) ;
    if ( ! my_serial_stream.good() )
    {
        std::cerr << "Error: Could not disable the parity." <<
                     std::endl ;
        exit(1) ;
    }

    my_serial_stream.SetFlowControl( SerialStreamBuf::FLOW_CONTROL_NONE ) ;
    if ( ! my_serial_stream.good() )
    {
        std::cerr << "Error: Could not use hardware flow control." <<
                     std::endl ;
        exit(1) ;
     }

    TDataCommunicationsChannels *FDataCommunications;
    FDataCommunications = InitExampleCommunications();
    FDataCommunications->dataTest1 = 3000;
    char next_char;
    char channel;
    while(ros::ok())
    {
        while(my_serial_stream.rdbuf()->in_avail() > 0)
        {
            // read serial port:
            my_serial_stream.get(next_char);
            // process serial port data:
            channel = ProcessChannelsSerialData(next_char);
            if(channel > 0)
            {
                switch (channel) {
                case 'g':
                {
                    std::cout << "received g channel: " << FDataCommunications->dataTest1 << std::endl;
                    break;
                }
                case 'r':
                {
                    std::cout << "received r channel: " << FDataCommunications->dataTest2 << ", and " << FDataCommunications->dataTest3 << std::endl;
                    std::string s = SendChannell('g');
                    my_serial_stream.write((char*) s.c_str(), s.size());
                    std::cout << "wrote: " << s.c_str() << std::endl;
                    break;
                }
                default:
                {
                    break;
                }
                }
            }
        }

        ros::spinOnce();
    }

    my_serial_stream.Close() ;
    return 0;
}
