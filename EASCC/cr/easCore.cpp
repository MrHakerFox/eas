#include "easCore.hpp"



FEasCore* FEasCore::selfPtr = 0;



FEasCore::FEasCore()
{
    isConnectedFlag = false;
}



FEasCore::~FEasCore()
{

}



FRetResCodes::code FEasCore::rs485Connect( std::string address )
{
    isConnectedFlag = false;
    return FRetResCodes::Failed;
}



FRetResCodes::code FEasCore::ethernetConnect( std::string address )
{
    isConnectedFlag = true;
    return FRetResCodes::OK;
}



FRetResCodes::code FEasCore::disconnect()
{
    isConnectedFlag = false;
}



bool FEasCore::isConnected()
{
    return isConnectedFlag;
}

