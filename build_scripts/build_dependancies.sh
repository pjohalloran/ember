#!/bin/sh

PREMAKE_DIR="projects/premake/"

pushd "${PREMAKE_DIR}"

premake5 build_thirdparty

popd

echo "[SUCCESS]"
