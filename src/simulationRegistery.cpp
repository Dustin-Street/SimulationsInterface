#include <map>
#include "Simulation.h"
#include "./utils/idGenerator.cpp"
// A set of functions that manages the registry of simulations in the application

// list point to all simulations
std::map<int, Simulation> simulationList{};

// insertion function accepts Simulation class object and its id Simulation::getSimulationId()
bool addSimulation(Simulation simulation, int simulationId)
{
    if (simulationList.find(simulationId) != simulationList.end())
    {
        simulationList.insert({simulationId, simulation}); // takes the unique key from object creation as the key
        return true;
    }
    return false;
}

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