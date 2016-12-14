#!/bin/sh

PREMAKE_DIR="projects/premake/"
CONAN_DIR="projects/conan/"
PREMAKE_CONAN_FILE="conanpremake.lua"
CONAN_FILENAME="conanfile.txt"
CONAN_INFO_FILE="conaninfo.txt"

conan install --build --file "${CONAN_DIR}${CONAN_FILENAME}"

if [ $? -ne 0 ]; then
	echo "[FAILED] Installing dependancies"
	exit 1
fi

mv -f "${PREMAKE_CONAN_FILE}" "${PREMAKE_DIR}"

if [ $? -ne 0 ]; then
	echo "[FAILED] copying premake dependancies"
	exit 1
fi

mv -f "${CONAN_INFO_FILE}" "${CONAN_DIR}"

if [ $? -ne 0 ]; then
	echo "[FAILED] Copying conaninfo"
	exit 1
fi

echo "[SUCCESS]"