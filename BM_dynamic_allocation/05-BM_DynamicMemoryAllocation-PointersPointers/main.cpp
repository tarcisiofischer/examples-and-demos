#include <iostream>

int xx[10] = {  1,  2,  3,  4,  5,  6,  7,  8,  9, 10 };
int yy[10] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
int zz[10] = { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };

int sum_arr(int** arr, int lines, int cols)
{
    int sum = 0;
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += (*(arr + i))[j];
        }
    }
    return sum;
}

int sum_hard(int** arr, int lines, int cols)
{
    int sum = 0;
    for (int pos = 0; pos < lines * cols; sum += *((*(arr + (pos / cols))) + (pos++ % cols)));
    return sum;
}

int main()
{
    int* ptr1 = xx; // Is an array a pointer?
    int* ptr2 = &(yy[0]);
    int* ptr3 = &(*zz);

    std::cout << "sizeof(ptr1) = " << sizeof(ptr1) << "\n";
    std::cout << "sizeof(xx) = " << sizeof(xx) << "\n";
    std::cout << "sizeof(&(yy[0])) = " << sizeof(&(yy[0])) << "\n";
    std::cout << "sizeof(&(*zz)) = " << sizeof(&(*zz)) << "\n";

    int* arr[3] = { ptr1, ptr2, ptr3 };

    std::cout << arr[0][0] << "\n";
    std::cout << arr[0][1] << "\n";
    std::cout << arr[1][0] << "\n";
    std::cout << arr[1][1] << "\n";
    std::cout << arr[2][0] << "\n";
    std::cout << arr[2][1] << "\n";
    std::cout << "\n";

    std::cout << sum_arr(arr, 3, 3) << "\n";
    std::cout << sum_hard(arr, 3, 3) << "\n";
    std::cout << "\n";

    std::cout << sum_arr(arr, 2, 4) << "\n";
    std::cout << sum_hard(arr, 2, 4) << "\n";
    std::cout << "\n";

    std::cout << sum_arr(arr, 1, 2) << "\n";
    std::cout << sum_hard(arr, 1, 2) << "\n";
    std::cout << "\n";

    return 0;
}
