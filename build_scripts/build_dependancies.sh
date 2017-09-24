#!/bin/sh

THIRD_PARTY_SRC_DIR="../../../src/thirdparty/"
THIRD_PARTY_SRC_DIR_TWO="../../src/thirdparty/"
INSTALL_DIR="../.."
INSTALL_DIR_TWO="../"
TMP_DIR="third_party_tmp"
EASTL_CONFIG="MinSizeRel" # Release|Debug|RelWithDebInfo|MinSizeRel

PREMAKE_DIR="projects/premake/"

# Clean any previous
rm -Rf "${TMP_DIR}"
rm -Rf "${INSTALL_DIR}/lib"
rm -Rf "${INSTALL_DIR}/include"

# Prepare install Dirs
mkdir "${INSTALL_DIR}/lib"
mkdir "${INSTALL_DIR}/include"

# TMP CMAKE/Build Directory
mkdir "${TMP_DIR}"
pushd "${TMP_DIR}"

# GLFW

echo ""
echo " #### Building GLFW ####"
echo ""

mkdir "glfw"
pushd "glfw"

pwd

cmake -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_DOCS=OFF -DCMAKE_INSTALL_PREFIX:PATH="${INSTALL_DIR}" "${THIRD_PARTY_SRC_DIR}/glfw"
cmake --build . --target install
popd # glfw

# EASTL

echo ""
echo " #### Building EASTL ####"
echo ""

mkdir "EASTL"
pushd "EASTL"

pwd

cmake -DCMAKE_INSTALL_PREFIX:PATH="${INSTALL_DIR}" "${THIRD_PARTY_SRC_DIR}/EASTL"
cmake --build . --config "${EASTL_CONFIG}" --target install
popd # EASTL

# string_id

echo ""
echo " #### Building string_id ####"
echo ""

mkdir "string_id"
pushd "string_id"

pwd

cmake -DCMAKE_INSTALL_PREFIX:PATH="${INSTALL_DIR}" "${THIRD_PARTY_SRC_DIR}/string_id"
cmake --build . --target "foonathan_string_id"
cp -v *.a *.lib "${INSTALL_DIR}/lib/"
mkdir "${INSTALL_DIR}/include/string_id"
ls -l "${THIRD_PARTY_SRC_DIR}/string_id"
cp -v "${THIRD_PARTY_SRC_DIR}/string_id/*.hpp*" "${INSTALL_DIR}/include/string_id/"
popd # string_id

# loguru

echo ""
echo " #### Building loguru ####"
echo ""

pwd

ls -l "${THIRD_PARTY_SRC_DIR_TWO}/loguru"
mkdir "${INSTALL_DIR_TWO}/include/loguru"
cp -v "${THIRD_PARTY_SRC_DIR_TWO}/loguru/loguru.hpp" "${INSTALL_DIR_TWO}/include/loguru"

# filesystem

echo ""
echo " #### Building filesystem ####"
echo ""

pwd

ls -l "${THIRD_PARTY_SRC_DIR_TWO}/filesystem/filesystem"
mkdir "${INSTALL_DIR_TWO}/include/filesystem"
cp -v "${THIRD_PARTY_SRC_DIR_TWO}/filesystem/filesystem/*.h" "${INSTALL_DIR_TWO}/include/filesystem"

# sol2

echo ""
echo " #### Building sol2 ####"
echo ""

pwd

ls -l "${THIRD_PARTY_SRC_DIR_TWO}/sol2"
mkdir "${INSTALL_DIR_TWO}/include/sol2"
cp -v "${THIRD_PARTY_SRC_DIR_TWO}/sol2/single/sol/sol.hpp" "${INSTALL_DIR_TWO}/include/sol2"

popd # TMP_DIR

rm -Rf "${TMP_DIR}"
