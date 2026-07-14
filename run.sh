#!/usr/bin/env bash
set -euo pipefail

# Simple developer run helper for this template.
# Ensures the build dir is added to QML import paths so loadFromModule() works.

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$ROOT_DIR/build"
INSTALL_DIR="$ROOT_DIR/install"

EXECUTABLE_NAME="$(sed -n 's/^set(TEMPLATE_EXECUTABLE_NAME[[:space:]]*"\([^"]*\)")/\1/p' "$ROOT_DIR/CMakeLists.txt" | head -n 1)"
if [ -z "$EXECUTABLE_NAME" ]; then
  EXECUTABLE_NAME="qtcpptemplate"
fi

EXECUTABLE="$BUILD_DIR/$EXECUTABLE_NAME"

USE_INSTALL=0
if [ "${1:-}" = "--use-install" ]; then
  USE_INSTALL=1
  shift
fi

if [ $USE_INSTALL -eq 1 ]; then
  if [ ! -d "$INSTALL_DIR" ]; then
    echo "Install tree not found. Create it with: cmake --install build --prefix install"
    exit 1
  fi
  export QML2_IMPORT_PATH="$INSTALL_DIR/qml${QML2_IMPORT_PATH:+:$QML2_IMPORT_PATH}"
  # The installed executable is under install/bin
  EXECUTABLE="$INSTALL_DIR/bin/$EXECUTABLE_NAME"
else
  if [ ! -x "$EXECUTABLE" ]; then
    echo "Executable not found. Build first: cmake -S . -B build && cmake --build build -j"
    exit 1
  fi
  export QML2_IMPORT_PATH="$BUILD_DIR${QML2_IMPORT_PATH:+:$QML2_IMPORT_PATH}"
fi

# Run the app with any provided args
"$EXECUTABLE" "$@"
