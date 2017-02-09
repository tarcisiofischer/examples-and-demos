#include <iostream>

class Human {
public:
    Human()
    {
        std::cout << "Hello.\n";
    }

    ~Human()
    {
        std::cout << "Bye.\n";
    }

    void say_something()
    {
        std::cout << "Something!\n";
    }

};

int main()
{
    std::cout << "New Human Begins\n";
    Human* h = new Human;
    std::cout << "New Human Ends\n";

    h->say_something();

    std::cout << "Delete Human Begins\n";
    delete h;
    std::cout << "Delete Human Ends\n";

    return 0;
}
