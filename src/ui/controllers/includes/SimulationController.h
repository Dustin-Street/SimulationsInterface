#ifndef SIMULATION_CONTROLLER_H
#define SIMULATION_CONTROLLER_H

#include <QObject>
#include <QString>
#include <map>
#include <string>
#include "Simulation.h"
#include "simulationRegistery.h"

class SimulationController : public QObject
{
    Q_OBJECT
public:
    explicit SimulationController(QObject *parent = nullptr);

public slots:
    bool loadSimulation(const QString &name, double simulationData);
    std::map<int, Simulation> populateSimulationList();
};

#endif