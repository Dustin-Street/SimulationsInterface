#include "SimulationController.h"

SimulationController::SimulationController(QObject *parent)
    : QObject(parent)
{
}

bool SimulationController::loadSimulation(const QString &name, double simulationData)
{
    return addSimulation(name.toStdString(), simulationData);
}

std::map<int, Simulation> SimulationController::populateSimulationList()
{
    return getSimulationList();
}