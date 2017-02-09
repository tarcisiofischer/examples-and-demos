#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <vector>
#include <iostream>

int counter = 0;

class SimulationResults {
public:
    SimulationResults()
    {
        c = counter++;
        std::cout << "Constructor " << c << "\n";
        value = new int;
    }

    ~SimulationResults()
    {
        std::cout << "Destructor " << c << "\n";
        delete value;
    }

private:
    int c;
    int* value;
};


int main()
{
    {
        std::vector<SimulationResults> results(3);
        std::cout << "Will replace the first simulation result\n";
        results[0] = SimulationResults();
        std::cout << "Replace has been done.\n";
    }

    _CrtDumpMemoryLeaks();
}
