#ifndef EASCORE_HPP
#define EASCORE_HPP



#include <string>
#include <FRetResCodes.hpp>
#include <QtNetwork>




class FEasCore
{
protected:



private:
    static FEasCore* selfPtr;
    bool isConnectedFlag;


    FEasCore();
    ~FEasCore();




public:
    static FEasCore* getInstance()
    {
        if( !selfPtr )
        {
            selfPtr = new FEasCore;
        }

        return selfPtr;
    }

    FRetResCodes::code rs485Connect( std::string address );
    FRetResCodes::code ethernetConnect( std::string address );
    FRetResCodes::code disconnect();
    bool isConnected();
};

#endif // EASCORE_HPP
