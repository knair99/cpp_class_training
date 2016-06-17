#include <iostream>
using namespace std;

//RAII stands for Resource Aquisition IS also INITIALIZATION
//Rajeev Pitre used this trick once 

class Lock
{
    private:
        Mutex m_;

    public:
        explicit Lock(Mutex m_in)             //explicit keyword protects us from accidental copy construction or invocation 
        {
            //Acquire resource in here by default
            acquire_mutex(m);
            
            //Now keep a copy to it
            m_ = m_in;
        }

        ~Lock()
        {
            //And release resource here
            release_mutex(m_); //LESSON: the destructor will ALWAYS be called, even if some exception is thrown in between 

        }

};


int main(int argc, char *argv[])
{
    //Lesson: Now all I have to do is this and let it go out of scope automatically when the stack unwinds
    
    Mutex mm;

    Lock l(mm);

    //And we're done - since Lock has a copy reference to this, it will destroy it in its destructor

    return 0;    
}

