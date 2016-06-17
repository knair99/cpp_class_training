#include <iostream>

using namespace std;


//There are two types of polymorphisms: static and dynamic
//dynamic is when you use something of the type Base* ptr = new Derived() with
//virtual functions overridden and then use it to dynamically name different things with same name

//The other is static inheritance. there are two forms of this.
//both forms means that the compiler itself will know what the polymorphism is
//and won't have to wait till the runtime

///////////////////////////////////
//First type of static polymorphism
template <class T>
class Base 
{
    public:

        string s; 

        void DoSomething()
        {
            cout << "Hello from base" << endl;
        }

        void DoSomethingFirst()
        {
            //This is going to be used to refer to even objects copy without the expense
            //of a virtual table lookup
            static_cast<T*>(this)->s = "Preprocessing in base";            
            
            static_cast<T*>(this)->DoSomething();
        }
};

//and the derived class will use the templated ability of base to construct itself
//now the base class method can be invoked on the derived object to do some pre processing in base
//and then will call the derived DoSomething FROM base
class Derived : public Base <Derived>
{
    public:    
       void DoSomething()
       {
           cout << s << " and post processing in Derived" << endl;
       }
};

///////////////////////////////////
//The second type of static polymorphism 
//are templates


int main(int argc, char *argv[])
{
    Derived d;
    d.DoSomethingFirst(); //this will now pre process in base class and instead of calling Base's DoSomething
                          //it will polymorphically recognize that it has to do the derived's post processing
                          //by invoking Derived::DoSomething() - this recognition is explicitly built into it using
                          //static cast
    return 0;    
}

