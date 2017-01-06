# ember
Hobbiyst game programming experiments.

## Dependencies
- conan package manager (for all third party dependencies). http://conan.io/
- cmake (to build third party dependencies). https://cmake.org
- premake4 (for project generation) http://premake.github.io/

## To begin on OSX (using homebrew http://brew.sh/)
- Install cmake. `brew install cmake`
- Install conan package manager. `brew install conan`
- Install premake4. `brew install premake`
- To install and build all third party dependencies, run `. build_scripts\build_dependancies.sh`
- To generate xcode solution, run `. build_scripts\regen_project.sh`
- Open the xcode project in `projects\premake\generated_project\` and play.

Currently, an OpenGL 4.1 Core Context is used, for instructions on how to setup ember to be used with a different OpenGL profile, [see](notes/GeneratingOpenGLExtensions.md)

## Uses
- glfw (http://http://www.glfw.org/)
- OpenGL (https://www.opengl.org/)
- flextGL (https://github.com/ginkgo/flextGL)
- loguru (https://github.com/emilk/loguru)
- Remotery (https://github.com/Celtoys/Remotery)
- EASTL (https://github.com/electronicarts/EASTL)
- filesystem (https://github.com/wjakob/filesystem)
- string_id (https://github.com/foonathan/string_id)
- sol2 (https://github.com/ThePhD/sol2)