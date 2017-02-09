#include <iostream>

class SomeClass
{
public:

    void show_data()
    {
        std::cout << i << "\n";
        std::cout << j << "\n";
        std::cout << k[0] << k[1] << k[2] << k[3] << "\n";
    }

    int i;
    float j;
    char k[4];
};

// Reserve some contiguous global memory
int x = 42;
int y = 1067320914;
int z = 1701013870;

int main()
{
    // error C2440: 'initializing' : cannot convert from 'int *' to 'SomeClass *'
    //SomeClass* sc = &x;

    SomeClass* sc = (SomeClass*)(&x);
    sc->show_data();
}
