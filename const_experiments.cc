#include <iostream>
#include <vector>
using namespace std;

//CASE 1
//const return value (without reference or pointer)
const string GetString (int times)
{
    return string(times, '*');
}


//CASE 2
//overloaded const functions
class A
{
    public:
        int GetA() { cout<<"GetA()" << endl;  return a_;}        //this is a non-const version of GetA()
        int GetA() const {cout <<"const GetA()" << endl;return a_;}   //this is a const version of GetA() which is overloaded

    private:
        int a_;
    
};


//CASE 3
//overloaded const functions (const in parameters)
class AA
{
    public:
        void SetA(int& a) { cout<<"SetA()" << endl;   a_=a;}        
        void SetA(const int& a){cout <<"const SetA()" << endl;  a_ = a;} 

    private:
        int a_;
    
};

//CASE 4
//over-riding const
class Array
{
    public:
        int GetItem (int index) const //This promises bitwise const
                                      //meaning - nothing in Array should be changed
        {
            //access_counter++; //ERROR: changes bitwise constant
                                //two solutions - either make this variable mutable
                                //or const_cast the this object into non-const
            
            const_cast<Array*>(this)->access_counter++; //const_casting this away         
            return v[index];
        }

    private:
        vector<int> v;
        size_t access_counter;
};

int main(int argc, char *argv[])
{

    //////////////CASE 1
    string s = GetString(20);

    cout << s << endl;
    
    s += "$"; //Lesson: This can totally modify the string return even though it's a const return value
              //because it's a temporary rvalue that's being returned, which is only existent till it's accessed

    cout << s << endl;

    //////////////CASE 2
    
    A a_1;
    a_1.GetA(); //Q: Which of the GetA() will be called?
              //Lesson: The non-const version 
              //The const version will only be called if A itself is const

    const A& a_2 = a_1;
    a_2.GetA(); //Now the const version of GetA() will be called

    //////////////CASE 3
    AA a1;

    a1.SetA(100); //Q: Which one will be called?
                  //Lesson: the const one because 100 is passed by value, and the program obviously cannot change it

    int i = 1000;

    a1.SetA(i);   //now that this value, i can be changed by the class, the non-const param SetA() is called

    return 0;    
}

