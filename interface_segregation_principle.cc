#include <iostream>
using namespace std;


//We implement interfaces with ADTs anyway

//For clients only interested in connecting to server, why expose them to data?
class IClientConnectInterface
{
    public:    
        virtual void connect() = 0;
        virtual void disconnect() = 0;
        virtual ~IClientConnectInterface(){} //always, ALWAYS declare a virtual destructor
                                            //also give it an empty body
};

//For clients only interested in accessing data, why bother them with connect functions
class IClientDataInterface
{
    public:    
        virtual void getdata() = 0;
        virtual void setdata() = 0;
        virtual ~IClientDataInterface(){}
};


class Server: public IClientConnectInterface, public IClientDataInterface
{
    public:
        virtual void connect() {cout << "connecting" << endl;}
        virtual void disconnect() {cout << "disconnecting" << endl;}
        virtual void getdata()  {cout << "retrieving data" << endl;}
        virtual void setdata() {cout << "storing data" << endl;}

};


int main(int argc, char *argv[])
{
    //Now clients can choose the interface that they're interested in
    
    IClientDataInterface* data_ptr = new Server;
    data_ptr->setdata();

    IClientConnectInterface* connect_ptr = new Server;
    connect_ptr->connect();
    
    delete data_ptr;
    delete connect_ptr;

    return 0;    
}

