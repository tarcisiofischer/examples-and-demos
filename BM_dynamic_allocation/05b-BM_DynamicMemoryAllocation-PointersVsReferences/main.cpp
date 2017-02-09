#include <iostream>
#include <vector>


int main()
{
    // Practical differences between pointers and references

    // A pointer is just a variable that holds an address
    // A reference is an "alias" to a variable
    {
        int x = 5;
        int* y = &x; // Variable that can hold any memory address to an 'int' variable

        // Error. A reference must always be initialized
        // int& z;

        int& z = x; // Ok. Now 'x' has an alias named 'z'.

        // To set the variable value with pointers you must dereference it
        *y = 7;
        std::cout << "x=" << x << "\n";
        // You don't need to do this with references, since they are just an alias
        z = 9;
        std::cout << "x=" << x << "\n";

        // Extra note: For classes and structs, you'll access their data with '->' when using pointers and '.' when using references.
        // Something like this:

        struct Simulator {
            void run() {
                std::cout << "running simulation...\n";
            }
        };
        Simulator sim;

        Simulator& sim_ref = sim;
        sim_ref.run();

        Simulator* sim_ptr = &sim;
        sim_ptr->run();
        // which is the same as
        (*sim_ptr).run();
    }
    std::cout << "\n";

    // 1- A pointer can be re-assigned, references can't
    {
        int x = 5;
        int y = 6;
        int *p;
        p = &x;
        p = &y;

        int &r = x;
    }

    // 2- Pointer can be assigned nullptr directly, whereas reference cannot.
    {
        int x = 5;
        int* y = nullptr;

        // Error: Can't initialize reference to nullptr
        // int& z = nullptr; 
    }

    // 3- You can do pointer arithmetic. This makes no sense for references.
    {
        int x[2] = { 1, 5 };
        int* y = &x[0];
        int& z = x[0];

        z++; // Increments x[0] from '1' to '2', so the array will contain { 2, 5 } after that
        y++; // Will increment the POINTER, so that it'll point to the second element on the array, that is, the int '5'.

        std::cout << z << "\n";
        std::cout << *y << "\n";
    }

    // 4- You can't do a vector of references, but you can do a vector of pointers
    //std::vector<int&> bad;
    std::vector<int*> not_so_bad;

    // Further Readings:
    // 
    // http://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in
}