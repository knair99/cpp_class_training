// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.
// write auto-pointer

//Aptr<Object>  ptr (new Object);
//*ptr++;
//ptr->Foo();

template <class T>
class Aptr
{
    T* data;
    
public:
    Aptr (T* val) : data(val) { } 
    
    ~Aptr()
    {
        delete data;
    }
    
    T& operator* ()
    {
        return *data;
    }
    
    T* operator->()
    {
        return data;
    }
    
    T& operator=(const T& rhs)
    {
        if(rhs != this)
        {
            data = rhs.data;
        }
        return *this;
    }

};

int main(int argc, char* argv[])
{
    Aptr<int> a (new int);
    
}
