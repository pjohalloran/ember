# ember
Hobbiyst game programming experiments.

## Dependencies
- conan package manager (for all third party dependencies). http://conan.io/
- premake4 (for project generation) http://premake.github.io/

## To begin on OSX (using homebrew http://brew.sh/)
- Install conan package manager. `brew install conan`.
- Install premake4. `brew install premake`
- To install and build all third party dependencies, run `. build_scripts\build_dependancies.sh`
- To generate xcode solution, run `. build_scripts\regen_project.sh`
- Open the xcode project in `projects\premake\generated_project\` and play.

## To begin on Windows
- Instructions coming soon.

## Uses
- glfw (http://http://www.glfw.org/)
- OpenGL (https://www.opengl.org/)