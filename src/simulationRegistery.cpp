#include <map>
#include "Simulation.h"
#include "simulationRegistery.h"
// A set of functions that manages the registry of simulations in the application

// list point to all simulations
std::map<int, Simulation> simulationList{};

// insertion function accepts Simulation class object and its id Simulation::getSimulationId()
bool addSimulation(std::string name, double simulationData)
{
    int simulationId = idGenerator();
    Simulation newSimulation = Simulation(simulationId, name, simulationData); // simulationData may need to be revised to point to a file or something that run a logic chain / program
    if (simulationList.find(simulationId) == simulationList.end())
    {
        simulationList.insert({simulationId, newSimulation}); // takes the unique key from object creation as the key
        return true;
    }
    return false;
}
//get the list of inserted functions
std::map<int, Simulation> getSimulationList()
{
    return simulationList;
}

bool removeSimulation(int simulationId)
{
    if (simulationList.find(simulationId) != simulationList.end())
    {
        simulationList.erase(simulationId);
        return true;
    }
    return false;
}