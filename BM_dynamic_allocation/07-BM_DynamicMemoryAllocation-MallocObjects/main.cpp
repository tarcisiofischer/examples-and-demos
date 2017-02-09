#include <iostream>

class Simulator {
    Simulator()
    {
        std::cout << "Simulator Constructor.\n";
    }

    ~Simulator()
    {
        std::cout << "Simulator Destructor.\n";
    }

public:
    void run()
    {
        std::cout << "Simulation begins\n";
    }

};

int main()
{
    std::cout << "(m)alloc Simulator Begins\n";
    Simulator* sim = (Simulator*)malloc(sizeof(Simulator));
    std::cout << "(m)alloc Simulator Ends\n";

    sim->run();

    std::cout << "Free Simulator Begins\n";
    free(sim);
    std::cout << "Free Simulator Ends\n";

    return 0;
}
