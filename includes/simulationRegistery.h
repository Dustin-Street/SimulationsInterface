#ifndef SIMULATION_REGISTERY_H
#define SIMULATION_REGISTERY_H

#include <map>
#include "Simulation.h"
#include "idGenerator.h"

extern std::map<int, Simulation> simulationList;
bool addSimulation(std::string name, double simulationData);
std::map<int, Simulation> getSimulationList();
bool removeSimulation(int simulationId);
#endif