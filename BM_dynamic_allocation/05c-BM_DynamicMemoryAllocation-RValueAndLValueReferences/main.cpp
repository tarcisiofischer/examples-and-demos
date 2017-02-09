#include <iostream>

int complex_number_counter = 0;

struct ComplexNumber {
    ComplexNumber(int r, int i) : r(r), i(i) {
        complex_number_counter += 1;
    }

    ComplexNumber(ComplexNumber& other) {
        complex_number_counter += 1;

        r = other.r;
        i = other.i;
    }

    int r;
    int i;
};

int sum_of_real_parts(ComplexNumber a, ComplexNumber b)
{
    return a.r + b.r;
}

int sum_of_real_parts_with_refs(ComplexNumber &a, ComplexNumber &b)
{
    return a.r + b.r;
}

int main()
{
    ComplexNumber a(5, 3);
    ComplexNumber b(3, 7);

    //sum_of_real_parts(a, b);

    sum_of_real_parts_with_refs(a, b);
    sum_of_real_parts_with_refs(a, ComplexNumber(7, 9));

    std::cout << complex_number_counter << "\n";
}