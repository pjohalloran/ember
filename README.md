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

## To begin on Windows
- Instructions coming soon.

## Uses
- glfw (http://http://www.glfw.org/)
- OpenGL (https://www.opengl.org/)
- loguru (https://github.com/emilk/loguru)
- EASTL (https://github.com/electronicarts/EASTL)
- filesystem (https://github.com/wjakob/filesystem)