#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>

struct SimulationResults {
    float result1;
    float result2;
};

class Simulator
{
public:
    SimulationResults* run_simulation(float input1, float input2)
    {
        SimulationResults* results = new SimulationResults;
        results->result1 = input1 + input2;
        results->result2 = input2 - 2 * input1;
        return results;
    }
};

int main()
{
    Simulator* sim = new Simulator;

    SimulationResults* best_result = sim->run_simulation(0.0, 0.0);
    for (int i = 0; i < 100; ++i) {
        SimulationResults* current_run = sim->run_simulation(1.1*i, 3.2*i);

        if (current_run->result1 > best_result->result1 && current_run->result2 > best_result->result2) {
            delete best_result;
            best_result = current_run;
        }
        else {
            delete current_run;
        }
    }
    std::cout << best_result->result1 << "\n";

    delete sim;
    delete best_result;

    _CrtDumpMemoryLeaks();
}
