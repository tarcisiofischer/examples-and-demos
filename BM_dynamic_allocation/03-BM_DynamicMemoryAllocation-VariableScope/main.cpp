#include <string>
#include <iostream>

class Human {
public:
    Human()
    {
        std::cout << "Hello!\n";
    }

    ~Human()
    {
        std::cout << "Bye\n";
    }
};

class File {
public:
    File(std::string const& filename)
    {
        std::cout << "Open file!\n";
    }

    ~File()
    {
        std::cout << "Closing File!\n";
    }
};

int main()
{
    Human h1;

    {
        Human h2;

        printf("&h1 = 0x%08x\n", &h1);
        printf("&h2 = 0x%08x\n", &h2);
    }

    // RAII - Resource Acquisition Is Initialization
    {
        File f("abc.txt");
        std::cout << "Working with the file....\n";
    }
}