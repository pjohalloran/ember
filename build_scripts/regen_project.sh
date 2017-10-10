#!/bin/sh

PREMAKE_DIR="projects/"

pushd "${PREMAKE_DIR}"

premake5 xcode4

if [ $? -ne 0 ]; then
	echo "[FAILED] generating project"
	popd
	return 1
fi

popd

echo "[SUCCESS]"