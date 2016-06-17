#include <iostream>
using namespace std;

class A
{
    public:
        A()         = delete;   //will not generate a default ctor
        A(const A&) = delete;   //will not generate copy ctor
        A(string s) {}          //we only want objects to be initialized with a parameterized ctor

};

//another way is to put them as private (like in singleton patterns)
class B
{
    private:
        B();            
};

int main(int argc, char *argv[])
{
    A a("string");

    A a1 = a;               //This will not compile!
    B b;                    //This won't either
    return 0;    
}

