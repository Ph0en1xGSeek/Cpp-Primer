#include <typeinfo>
#include <iostream>

class Base {
    int a;
    int b;
};

int main()
{
	int arr[10];
    Base *p;
    std::cout << typeid(arr).name() << std::endl;
    std::cout << typeid(Base).name() << std::endl;
    std::cout << typeid(p).name() << std::endl;
	return 0;
}