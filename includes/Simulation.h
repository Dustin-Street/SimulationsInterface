#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>

class Simulation
{
public:
    Simulation(int id, const std::string& name, double simulationData);
    ~Simulation();

    double runSimulation(double value1, double value2);
    double runSimulation(double value1);
    std::string getSimulationName() const;
    int getSimulationID() const;

private:
    int simulationID{};
    std::string name;
    double simulationLogic{};
};

#endif