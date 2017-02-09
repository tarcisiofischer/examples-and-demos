#include <iostream>

int VeryComplexSimulator_counter = 0;

struct VeryComplexSimulator
{
    VeryComplexSimulator()
    {
        VeryComplexSimulator_counter++;
    }

    VeryComplexSimulator(VeryComplexSimulator const& other)
    {
        VeryComplexSimulator_counter++;
    }

    int x;
    int y;
    int z;
    // ...Many more very complex data structures...
};

void simulate1(VeryComplexSimulator s)
{
    // Do stuff with simulator
}

void simulate2(VeryComplexSimulator &s)
{
    // Do stuff with simulator
    s.x = 9; // Modify the simulator!!!!
}

void simulate3(VeryComplexSimulator const& s)
{
    // Do stuff with simulator

    // Compilation error
    //s.x = 9;
}


int main()
{
    {
        VeryComplexSimulator_counter = 0;

        VeryComplexSimulator s;
        simulate1(s);
        std::cout << VeryComplexSimulator_counter << "\n";
    }

    {
        VeryComplexSimulator_counter = 0;
    
        VeryComplexSimulator s;
        simulate2(s);
        std::cout << VeryComplexSimulator_counter << "\n";
    }

    {
        VeryComplexSimulator_counter = 0;

        VeryComplexSimulator s;
        simulate3(s);
        std::cout << VeryComplexSimulator_counter << "\n";
    }
}