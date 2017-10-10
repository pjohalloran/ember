- Research premake5.
- Add initial configs for premake.
- Code styling script.

- Make simple demo opening a window & gl context.
	- Ability to clone and script installation of initial 3rd party dependancies.
	- premake scripts that generate xcode & VS project files.
	- minimal src added from gameframework.
	- demo app that opens a gl window with nothing in it.

- List 3rd party libs i want to include initially.
	- glfw
	- opengl
	- loguru
	- EASTL
	- filesystem
	- flextgl
	- Remotery
	- string_id
	- lua
	- sol2

- Bring over gameframework code i still like.
	- premake scripts
	- gamebase (some)
	- Math

- Decide on gameframework code i will not bring over.
	- datastructures

- Strings
	- Add string hash functionality to the project.
	- Investigate a way to not have strings used at runtime.

- Add flexgl as git submodule as cant be included as conan dependancies as they are too custom and or tools.
- Add Remotery as git submodule as it cant be included as conan dependancies as it is too custom and or tools.