#!/bin/sh

PREMAKE_DIR="projects/"

pushd "${PREMAKE_DIR}"

premake5 clean_thirdparty

popd

echo "[SUCCESS]"
