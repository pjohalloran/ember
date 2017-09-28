#!/bin/sh

PREMAKE_DIR="projects/premake/"

pushd "${PREMAKE_DIR}"

premake5 clean_thirdparty

popd

echo "[SUCCESS]"
