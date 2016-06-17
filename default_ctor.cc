#include <iostream>
using namespace std;

class A{

    public: 
        A(string s) {} //We provide a parameterized ctor
};

class B{

    public:
        //A a;        //A is a member of B
};

int main(int argc, char *argv[])
{

    A a;            // THIS WILL NOT COMPILE!

    B b;            //This will not compile either, because A doesn't have an explicit default dtor
                    
    //LESSON: The reason is, the compiler will try and generate a default ctor for A
    //but will see a parameterized ctor and then won't

    return 0;    
}

