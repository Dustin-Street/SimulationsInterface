Qt/C++ template — minimal Qt Quick (QML) + C++ starter project

Overview
- Small template combining C++ and QML using Qt 6 and CMake.
- Designed for development: you can quickly copy/rename this folder to start a new project and iterate on QML + C++.
- Works in-place (no install needed) by making the build directory available as a QML import path.

Quick start (build & run)
1. Configure and build:

```bash
cmake -S . -B build
cmake --build build -j
```

2. Run using helper script (ensures the QML import path points to the build tree):

```bash
./run.sh
```

Install & run from local install tree

You can install the QML module into a local `install/` prefix and run the installed app.

```bash
# install into ./install
cmake --install build --prefix install

# run the installed app; run.sh will point QML import path at ./install/qml
./run.sh --use-install
```

What the template does
- `qt_add_qml_module(...)` generates the QML module and plugin into the build tree for your chosen module URI.
- The executable target gets a compile definition `QML_IMPORT_PATH` set to the build directory; `main.cpp` adds that path to `QQmlApplicationEngine`'s import paths at runtime so `engine.loadFromModule(<your-module-uri>, "Main")` works during development.

How to reuse / make a new project
1. Copy the whole folder to a new location and rename it.
2. Edit the root `CMakeLists.txt`:
   - Change the template values at the top for your project name, QML URI, and executable name.
   - Update the QML module details if you want a different import URI.
3. Edit `src/ui/Main.qml` and `src/main.cpp` as needed.
4. Build and run with the commands above or `./run.sh`.



Enjoy playing with QML + C++!