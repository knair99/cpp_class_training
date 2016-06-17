#include <iostream>
using namespace std;

//A clone method is also known as a virtual constructor
//Lets say you had a situation where you did
//Base *b = new Base(derived_object);
//this will be a shallow copy
//For taking proper advantage of polymorphism, you need it of the form
//Base *b = new Derived(derived_object)
//A clone method is a lovely way to solve that, because it will auto detect what kind of object to new
//and copy construct

class Base
{
    public:
        virtual void foo()
        {
            cout << "base class foo" << endl;
        }

        virtual Base* clone()
        {
            return new Base(*this); // you invoke its default copy ctor
        }
};

class Derived : public Base
{
    public:  
        virtual void foo()
        {
            cout << "Derived class foo" << endl;
        }
        virtual Derived* clone()
        {
            return new Derived(*this); //Again, take advantage of default copy ctor
        }
};

void foo (Base& b)
{
    Base *b1 = new Base(b); //THIS IS A PROBLEM: 
                           //This will only copy the base portion of b, and not the derived part of it

    b1->foo();              //THIS WILL USE BASE::foo!
                           
    Base *b2 = b.clone();   //This will do a full copy - make it equivalent to Base *ptr = new Derived() kinda thing

    b2->foo();              //This will use the "appropriate" foo - like we want (Derived::foo)
}

int main(int argc, char *argv[])
{

    Derived d;
    foo(d);
    return 0;    
}

