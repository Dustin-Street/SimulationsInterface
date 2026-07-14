cmake_minimum_required(VERSION 3.28)

# Change only the values in this block when copying this template to a new project.
set(TEMPLATE_PROJECT_NAME "SimulationsInterface")
set(TEMPLATE_QML_URI "SimulationsInterface")
set(TEMPLATE_QML_VERSION "1.0")
set(TEMPLATE_EXECUTABLE_NAME "simulationsinterface")

project(${TEMPLATE_PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

find_package(Qt6 REQUIRED COMPONENTS Quick Qml QuickControls2)

qt_add_qml_module(${TEMPLATE_PROJECT_NAME}
    URI ${TEMPLATE_QML_URI}
    VERSION ${TEMPLATE_QML_VERSION}
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${TEMPLATE_QML_URI}
    QML_FILES
        src/ui/Main.qml
)


add_executable(${TEMPLATE_EXECUTABLE_NAME}
    src/main.cpp
    src/Simulation.cpp
)


target_link_libraries(${TEMPLATE_EXECUTABLE_NAME}
    Qt6::Quick
    Qt6::Qml
    Qt6::QuickControls2
    ${TEMPLATE_PROJECT_NAME}
    
)





# Expose the CMake build directory to the application so QQmlEngine
# can find the generated qmldir/plugin under the build tree at runtime.
target_compile_definitions(${TEMPLATE_EXECUTABLE_NAME} PRIVATE
    QML_IMPORT_PATH="${CMAKE_BINARY_DIR}"
    QML_MODULE_URI="${TEMPLATE_QML_URI}"
)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(includes)
add_subdirectory(docs)

# Install rules: install the QML module (qmldir + plugin) into
# ${CMAKE_INSTALL_PREFIX}/qml/<uri> so the module can be used by installed
# applications or when testing via an install tree.
install(DIRECTORY ${CMAKE_BINARY_DIR}/${TEMPLATE_QML_URI}/ DESTINATION qml/${TEMPLATE_QML_URI} FILES_MATCHING PATTERN "*")

# Install the plugin library (MODULE) and the module shared library if present.
install(TARGETS ${TEMPLATE_PROJECT_NAME}plugin
    LIBRARY DESTINATION qml/${TEMPLATE_QML_URI}
    RUNTIME DESTINATION qml/${TEMPLATE_QML_URI}
)

install(TARGETS ${TEMPLATE_PROJECT_NAME}
    LIBRARY DESTINATION lib
)

# Install the application executable for easy testing after install.
install(TARGETS ${TEMPLATE_EXECUTABLE_NAME}
    RUNTIME DESTINATION bin
)