/*
Original example from Cython's BookMeeting.
Remember:
%timeit factorial(2**16)
1 loops, best of 3: 1.27 s per loop


def factorial(int n):
    res = 1
    while n > 0:
        res *= n
        n -= 1
    return res
*/

#include "release_gil.hpp"

int factorial(int n)
{
    int res = 1;
    while (n > 0) {
        res *= n;
        n -= 1;
    }
    return res;
}

// Test 'return 1' cython vs boost::python (overhead test)
int factorial_nogil(int n)
{
    ScopedGILRelease s;

    int res = 1;
    while (n > 0) {
        res *= n;
        n -= 1;
    }
    return res;
}