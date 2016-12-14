#!/bin/sh

PREMAKE_DIR="projects/premake/"

pushd "${PREMAKE_DIR}"

premake4 xcode4

if [ $? -ne 0 ]; then
	echo "[FAILED] generating project"
	popd
	return 1
fi

popd

echo "[SUCCESS]"