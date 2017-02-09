#include <iostream>

int i = 1;
int j = 2;
int k = 3;
int xx[10] = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

int main()
{
    int* ptr = &i;
    std::cout << *ptr << "\n";
    std::cout << *(ptr + 1) << "\n"; // Is it ok to do this?
    std::cout << *(ptr + 2) << "\n";
    std::cout << *(ptr + 3) << "\n";
    std::cout << *(ptr + 4) << "\n";
    std::cout << *(ptr + 5) << "\n";

    std::cout << "\n";

    std::cout << ptr[0] << "\n";
    std::cout << ptr[1] << "\n";
    std::cout << ptr[2] << "\n";
    std::cout << ptr[3] << "\n";
    std::cout << ptr[4] << "\n";
    std::cout << ptr[5] << "\n";

    std::cout << "\n";

    char* other_ptr = (char*)&i;
    std::cout << (int)*other_ptr << "\n";
    std::cout << (int)*(other_ptr + 1) << "\n";
    std::cout << (int)*(other_ptr + 2) << "\n";
    std::cout << (int)*(other_ptr + 3) << "\n";
    std::cout << (int)*(other_ptr + 4) << "\n";
    std::cout << (int)*(other_ptr + 5) << "\n";

    return 0;
}
