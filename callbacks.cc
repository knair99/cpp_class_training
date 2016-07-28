#include <iostream>
#include <vector>

using namespace std;

//A templated callback - just for kicks
//Returns 1 if x > y, 0 if equal, -1 if x < y
//Anything that uses this obviously need overloaded > operator
template <class T>
int CompareCallBack(T* x, T* y)
{

    if(x > y)
        return 1;
    else if (x < y)
        return -1;
    else
        return 0;
}

typedef int (*fptr)(int*, int*);

//Another function to which we pass callback
template <typename T>
void Sort (vector<T>& v, fptr f1)
{

}

int main(int argc, char *argv[])
{
    vector<int> v;

    Sort(v, CompareCallBack);
    return 0;    
}

