#!/bin/sh

PREMAKE_DIR="projects/premake/"

pushd "${PREMAKE_DIR}"

premake4 xcode4

popd