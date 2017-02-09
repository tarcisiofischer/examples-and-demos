#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h> 
#include <functional>

struct SomeDataStructure
{
public:
    int xx[500];
};


void use_stack()
{
    SomeDataStructure sds;

    /* Use sds ... */
    sds.xx[50] = 7;

    /* sds is automatically destroyed when exiting this scope */
}

void use_heap()
{
//    SomeDataStructure *sds = (SomeDataStructure *)malloc(sizeof(SomeDataStructure));
    SomeDataStructure *sds = new SomeDataStructure;

    /* Use sds ... */
    sds->xx[50] = 7;

    /* Remember to free the malloc-ated memory */
    free(sds);
}

void measure(std::function<void(void)> const& f, int n_times)
{
    timeb start;
    ftime(&start);

    int i = 0;
    while (i++ < n_times) {
        f();
    }

    timeb end;
    ftime(&end);
    int diff = (int)(1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
    printf("Operation took %u milliseconds\n", diff);
}

int main()
{
    measure(use_stack, 1000000);
    measure(use_heap, 1000000);

    return 0;
}
