#include <iostream>
using namespace std;

class Base
{
    public: 
       void DoBase()
       {
            cout << "Base" << endl;
       }

};


class Base1 : virtual public Base
{
    public:
       void DoSomething()
       {
            cout << "Base1" << endl;
       }
};

class Base2 : virtual public Base 
{
    public:
       void DoSomething()
       {
            cout << "Base2" << endl;
       }
};

class Derived1: public Base1, public Base2
{
    public:    
};



int main(int argc, char *argv[])
{

    Derived1 d1;
   
    //d1.DoSomething(); //this would've errored with ambiguous name lookup 
    
    //Solution for that is:
    d1.Base1::DoSomething();

    //Now what about accessing Base alone (the original)
    //there are two DoBase()s in each of the derived classes 
    //from which Derived multiple inherits 
    //this is solved using the virtual keywords at the time of inheritance
    d1.DoBase();

    return 0;    
}

