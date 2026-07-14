#include <unordered_set>
#include <iostream>
#include <random>
// create a simple 7 digit random id number that is stored in a hash table to be sure it does not generate the same id twice

int getRandomNumber()
{
    std::mt19937 range(std::random_device{}());
    std::uniform_int_distribution<int> dist(1000000, 9999999);
    int randomId = dist(range);
    return randomId;
}

int idGenerator()
{
    int newId{};
    bool ungeneratedID = true;
    std::unordered_set<int> idList{};

    int randomNewId = getRandomNumber();

    while (ungeneratedID)
    {
        if (idList.insert(randomNewId).second)
        {
            std::cout << "new ID inserted : " << randomNewId << '\n';
            ungeneratedID = false;
            newId = randomNewId;
        }
        else
        {
            std::cout << "unable to add duplicate ID regenerating...";
        }
    }

    return newId;
}