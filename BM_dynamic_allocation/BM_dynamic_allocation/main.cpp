#include <cstdio>

int x1 = 7;
int x2 = 8;

void other_function(int z3)
{
    int z4 = 9;

    printf("&z3, &z4 = 0x%08x ; 0x%08x\n", &z3, &z4);
}

int main()
{
    static int y1 = 9;
    int z1;
    int z2;

    printf("&x1, &x2 = 0x%08x ; 0x%08x\n", &x1, &x2);
    printf("&y1 = 0x%08x\n", &y1);
    printf("&z1, &z2 = 0x%08x ; 0x%08x\n", &z1, &z2);
    other_function(9);

    return 0;
}
