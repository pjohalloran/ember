SET PREMAKE_DIR="../projects"

pushd %PREMAKE_DIR%

premake5 build_thirdparty

popd
