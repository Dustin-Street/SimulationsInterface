#include "Simulation.h"

Simulation::Simulation(int id, const std::string &name, double simulationData)
    : simulationID(id), name(name), simulationLogic(simulationLogic)
{
}

Simulation::~Simulation() = default;

double Simulation::runSimulation(double value1, double value2)
{
    return value1 + value2 + simulationLogic;
}

double Simulation::runSimulation(double value1)
{
    return value1 + simulationLogic;
}

std::string Simulation::getSimulationName() const
{
    return name;
}

int Simulation::getSimulationID() const
{
    return simulationID;
}
