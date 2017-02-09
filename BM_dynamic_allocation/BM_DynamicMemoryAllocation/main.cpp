#include <iostream>

class Human {
public:
    Human() {
        std::cout << "Hello.\n";
    }

    int x;
};

int i1 = 99;
Human m1;


void other_function() {
    Human m3;
    static Human m4;
    printf("&m3 = 0x%08x\n", &m3);
    printf("m3.x = %i\n", m3.x);
    printf("&m4 = 0x%08x\n", &m4);
    printf("m4.x = %i\n", m4.x);

    m3.x = 7;
    m4.x = 8;
}

int main()
{
    printf("Main begins!\n");
    Human m2;

    printf("&i1 = 0x%08x\n", &i1);
    printf("&m1 = 0x%08x\n", &m1);
    printf("&m2 = 0x%08x\n", &m2);

    printf("----------\n");
    other_function();
    other_function();
}
