#include <stdio.h>
#include <cstdlib>

int x1 = 10;
int x2 = 11;

int main()
{
    int y1 = 20;
    int y2 = 21;

    int* z1 = (int*)malloc(sizeof(int));
    int* z2 = (int*)malloc(sizeof(int));

    printf("&x1 = 0x%08x \n", &x1);
    printf("&x2 = 0x%08x \n", &x2);
    printf("&y1 = 0x%08x \n", &y1);
    printf("&y2 = 0x%08x \n", &y2);
    printf("&z1 = 0x%08x \n", z1);
    printf("&z2 = 0x%08x \n", z2);

    free(z1);
    free(z2);

    // -------------------------------------------

    int* ptr1 = (int*)calloc(5, sizeof(int));
    int* ptr2 = (int*)malloc(5 * sizeof(int));
    ptr2[2] = 99;

    int* arr[2] = { ptr1, ptr2 };

    for (int i = 0; i < 5; ++i) {
        printf("%i, ", arr[0][i]);
    }
    printf("\n");
    for (int i = 0; i < 5; ++i) {
        printf("%i, ", arr[1][i]);
    }
    printf("\n");
    printf("\n");

    free(ptr1);

    // The original pointer ptr is invalidated and any access to it is undefined behavior
    // http://en.cppreference.com/w/c/memory/realloc
    //

    for (int i = 0; i < 10; ++i) {
        if (i < 5) {
            ptr2[i] = i;
        }
        printf("%i, ", ptr2[i]); // This is not good.
    }
    printf("\n");

    int* realloc_ptr2 = (int*)realloc(ptr2, sizeof(int) * 10);

    for (int i = 0; i < 10; ++i) {
        printf("%i, ", realloc_ptr2[i]);
    }
    printf("\n");

    free(realloc_ptr2);

    return 0;
}