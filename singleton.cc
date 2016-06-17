#include <iostream>

using namespace std;

//once again
class A
{
    public:
        static A& GetInstance()
        {
            static A a;
            return a; 
        }

        void DoSomething()
        {
            cout << "A's doing something" << endl;
        }

    private:
        A(){};
        A(const A&);
        A& operator=(const A&);

};

//Implementing singleton with references
class SingleLady
{
    public:    
        static SingleLady& GetInstance()
        {
            static SingleLady instance;
            return instance;
        }

        void PutARingOnIt()
        {
            cout << "If you like it" << endl;
        }

    private:

        SingleLady() {}//To make sure that there is only one instance ever, the default ctor should be private
        SingleLady(const SingleLady&);  //Same logic for the copy ctor
        SingleLady operator=(const SingleLady&);   //Same logic for the assignment operator
        
};


//A more intuitive way with pointers
class Singleton
{
    private:
        Singleton() {}
        static Singleton* s_;
        Singleton(const Singleton&);
        Singleton operator=(const Singleton&);


    public:
        static Singleton* GetInstance()
        {
            if(s_ == NULL)
            {
                s_ = new Singleton;
            }

            return s_;
        }

        void FooBar()
        {
            cout << "Singleton: The world is foo bar" << endl;
        }

        ~Singleton()
        {
            cout <<"Goodbye world" << endl;
            delete s_;
            s_ = NULL;
        }

};


//First initialize the static member, for these have to be explicitly initialized
Singleton *Singleton::s_ = 0;


int main(int argc, char *argv[])
{
    Singleton::GetInstance()->FooBar();


    //Beauty of implementing with references
    //With the pointer implementation, we could potentially still be deleting it
    //delete Singleton::GetInstance();
 
    SingleLady::GetInstance().PutARingOnIt(); //SO MUCH CLEANER - no need to initialize static member pointer, etc

    A::GetInstance().DoSomething();

    return 0;    
}


