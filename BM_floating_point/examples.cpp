#include <iostream>
#include <ctime>
#include <float.h> 

void print_float(float const& x)
{
    unsigned int hex = *(int*)&x;
    printf("%+.40f (%x)\n", x, hex);
}

void print_bin(int const& x, int nbits=32)
{
    unsigned int b = 0x1 << (nbits - 1);
    for (int i = 0; i < nbits; ++i) {
        if (x & (b >> i))
            printf("1");
        else
            printf("0");
    }
}

void inspect_float(float const& x)
{
    int hex = *(int*)&x;
    printf("Inspect %+.64f (0x%x) (", x, hex); print_bin(hex); printf(")\n");

    // First bit is sign
    if (hex & 0x80000000) {
        printf("Sign bit  = 1 (-)\n");
    } else {
        printf("Sign bit  = 0 (+)\n");
    }

    // Next 8 bits are the biased exponent
    int bias = 127;
    int e = ((hex & 0x7F800000) >> 23) - bias;
    printf("Exponent  = %d\n", e);

    // Remaining 23 bits are the precision (mantissa)
    int p = (hex & 0x007FFFFF);
    printf("Precision = (1.) 0x%x (", p); print_bin(p, 23); printf(")\n");

    printf("===================\n");
}

void weird_sum()
{
    printf("Weird sum\n");

    printf("0.1 + 0.1 + 0.1 + ... + 0.1 =\n");
    float sum = 0.0;
    for (int i = 0; i < 100; ++i) {
        sum += 0.01f;
    }
    print_float(sum);

    // But... Is 1.0 even representable?
    printf("1.0 =\n");
    sum = 1.0f;
    print_float(sum);

    // Ok, but what if we avoid the for loop?
    printf("0.01 * 100.0 =\n");
    sum = 0.01f * 100.0f;
    print_float(sum);

    printf("\n");
}

void weird_math()
{
    printf("Weird math\n");
    float x0 = 10.0e30f; 
    float x1 = -10.0e30f; 
    float s = 1.0f;
    float result = 0.0f;

    printf("(10.0e30 + -10.0e30) + 1.0 =\n");
    result = (x0 + x1) + s;
    print_float(result);

    printf("10.0e30 + (-10.0e30 + 1.0) =\n");
    result = x0 + (x1 + s);
    print_float(result);

    printf("\n");
}

void weird_optimization()
{
    clock_t begin = clock();
    float y = 1.0f;
    for (int j = 0; j < 10000000; j++)
    {
        y *= 1.5f;
        y /= 3.0f;
        // "Optimization"?
        //y = y + 0.1; // <--
        //y = y - 0.1; // <--
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %.6f\n", elapsed_secs);
}

void special_floats()
{
    printf("Special float representations\n");

    unsigned int a;
    float x;

    // Zero
    a = 0x00000000;
    x = *(float*)&a;
    inspect_float(x);

    // Negative zero
    a = 0x80000000;
    x = *(float*)&a;
    inspect_float(x);

    // Infinite
    a = 0x7F800000;
    x = *(float*)&a;
    inspect_float(x);

    // Negative infinite
    a = 0xFF800000;
    x = *(float*)&a;
    inspect_float(x);

    // NaN
    a = 0xFF8abcde;
    x = *(float*)&a;
    inspect_float(x);
}

void inspect_common_floats()
{
    printf("Inspect some floats:\n");
    inspect_float(0.5f);
    inspect_float(32.0f);

    int v;

    inspect_float(2.0f);
    v = 0x40000001;
    inspect_float(*(float*)&v);

    float value = 32.0f;
    inspect_float(value);
    v = 0x42000001;
    inspect_float(*(float*)&v);

    float value2 = 0.000001f;
    inspect_float(value2);
    inspect_float(value + value2);
}

void denormalized_vs_normalized()
{
//    _controlfp_s(NULL, _DN_FLUSH, _MCW_DN);
    float x;

    clock_t begin = clock();

    float k = 0.0;
    x = 1.0;
    for (int i = 0; i < 100000000; ++i) {
        k += x + 0.1;
        k /= 1.727f;
        k *= 0.3f;
        printf("%3f\n", k);
    }

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %.6f\n", elapsed_secs);
}

void weird_comparation()
{
    float a = 1e-38;
    float b = 1e-39;

    print_float(a);
    print_float(b);

    if (a == b) {
        printf("a == c :)");
    }
    else {
        printf("a != c :(");
    }

    if (a - b == 0.0f) {
        printf("a == c :)");
    }
    else {
        printf("a != c :(");
    }
}

int main()
{
    weird_sum();
    weird_math();
    weird_optimization();
    weird_comparation();


    inspect_common_floats();
    special_floats();
    denormalized_vs_normalized();
}
