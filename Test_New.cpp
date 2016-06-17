#include <iostream>

using namespace std;

class Fred
{
public:
	int data;
	~Fred(){}
};

class MemAddr
{
	int data_;
public:
	MemAddr() : data_(5)
	{
	}
};

void TryReinterpret()
{
	MemAddr* m = new MemAddr;
	void* place = m;
	Fred *f;
	cout << "Size of m: " << sizeof(m) << endl;

	cout << "Address of m: " << &m << endl;
	
	f = reinterpret_cast<Fred*> (&m);
	//f = new(place) Fred();

	delete m;
	(*f).data	= 15;

	cout << "Address of f: " << f << endl;
	cout << "Size of f: " << sizeof(f) << endl;;

}

void TryPlacementNew()
{
	MemAddr *m = new MemAddr;
	void* place = &m;
	Fred *f;

	cout << "Size of m: " << sizeof(m) << " Address of m: " << &m << endl;

	f = new(place) Fred();

	(*f).data	= 5;

	cout << "Size of f: " << sizeof(f) << " Address of f: " << f << endl;;

	f->~Fred();
}

int main(int argc, char**argv)
{
	TryReinterpret();
	TryPlacementNew();

}