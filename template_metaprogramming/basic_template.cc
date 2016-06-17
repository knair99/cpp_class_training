#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout;        using std::cin;
using std::endl;        using std::vector;      using std::size_t;

//One way of using templates
template <class X, class Y>
struct SimplePair
{
    X first_;
    Y second_;
    SimplePair(X first, Y second) : first_(first), second_(second) {}
};


//Lesser known use of templates
template <size_t N>
void MultiplyByN (const int value)
{
    cout << " Multiplying with " << N << ". Result = " <<  value * N << endl;
}

int main(int argc, char *argv[])
{
    //Simple use
    SimplePair<int, float> sp (10, 11.1);
    cout << "Sp: first: " << sp.first_ << endl;


    //Second, different use - using templates as parameters
    MultiplyByN<3> (5);

    return 0;    
}


