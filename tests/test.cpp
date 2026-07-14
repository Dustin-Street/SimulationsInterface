// test headers
#include <iostream>
#include <limits>

// test logic headers
#include <unordered_set>
#include <iostream>
#include <random>
#include "../src/utils/idGenerator.cpp"

auto testLogic()
{
    // test logic here
    return idGenerator();
}

int main()
{
    int testCount{1};

    bool codeTesting = true;
    char input{' '};

    std::cout << "Press R to run code \nPress C to cancel code test \nPress I to input a number of test runs";
    while (codeTesting)
    {

        std::cin >> input;
        if (!std::cin)
        {
            std::cout << "inputs : flushing bad input \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        }
        else if (input == 'R' || input == 'r')
        {
            std::cout << "Running test number : " << testCount << " \n";
            // test logic
            std::cout << testLogic() << '\n';
            testCount++;
        }
        else if (input == 'c' || input == 'C')
        {
            std::cout << "Exiting testing after " << testCount << " run of the logic \n";
            codeTesting = false;
        }
        else if (input == 'I' || input == 'i')
        {
            int testLimit{0};
            std::cout << "Enter Desired Number of tests to run : " << std::endl;
            std::cin >> testLimit;
            if (!std::cin)
            {
                std::cout << "inputs : flushing bad input \n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            }
            else
            {

                for (int i = 0; i < testLimit; ++i)
                {

                    std::cout << "Running test number : " << testCount << " \n";
                    std::cout << testLogic() << '\n';
                    testCount++;
                }
            }
        }
    }
}