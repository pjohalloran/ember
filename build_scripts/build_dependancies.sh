#!/bin/sh

PREMAKE_DIR="projects/premake/"
CONAN_DIR="projects/conan/"
PREMAKE_CONAN_FILE="conanpremake.lua"
CONAN_FILENAME="conanfile.txt"
CONAN_INFO_FILE="conaninfo.txt"

FORCE=0

if [ $# -gt 0 ]; then
	if [ "$1" == "-f" ]; then
		FORCE=1
	fi
fi

if [ $FORCE -eq 1 ]; then
	conan install --build --file "${CONAN_DIR}${CONAN_FILENAME}"
else
	conan install --build=outdated --file "${CONAN_DIR}${CONAN_FILENAME}"
fi

if [ $? -ne 0 ]; then
	echo "[FAILED] Installing dependancies"
	return 1
fi

mv -f "${PREMAKE_CONAN_FILE}" "${PREMAKE_DIR}"

if [ $? -ne 0 ]; then
	echo "[FAILED] copying premake dependancies"
	return 1
fi

mv -f "${CONAN_INFO_FILE}" "${CONAN_DIR}"

if [ $? -ne 0 ]; then
	echo "[FAILED] Copying conaninfo"
	return 1
fi

echo "[SUCCESS]"