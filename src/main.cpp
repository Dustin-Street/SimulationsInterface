#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>
#include <QPalette>
#include <QtQml/qqmlregistration.h>
#include "./ui/controllers/includes/SimulationController.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QPalette palette = app.palette();
    app.setPalette(palette);

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed, &app, []()
                     { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    qmlRegisterType<SimulationController>("SimulationsInterface", 1, 0, "SimulationController");

    // Add the build directory (provided by CMake via QML_IMPORT_PATH)
    // so the engine can locate the generated qmldir and plugin.
#ifdef QML_IMPORT_PATH
    engine.addImportPath(QStringLiteral(QML_IMPORT_PATH));
#endif

#ifdef QML_MODULE_URI
    engine.loadFromModule(QStringLiteral(QML_MODULE_URI), "Main");
#else
    engine.loadFromModule("QtCppTemplate", "Main");
#endif

    return app.exec();
}