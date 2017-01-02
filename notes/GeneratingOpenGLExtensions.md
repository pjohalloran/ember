# Generating OpenGL Headers/Extensions with flextGL

ember uses flextGL (https://github.com/ginkgo/flextGL) to generate OpenGL extensions and loaders.

flextGL is included as an optional submodulw dependancy inside of ember.

We use a OpenGL 4.1 Core context by default at present and the generated flext headers are already included in ember for this.
Here are the steps in order to generate a new GL loader/extension for a different profile.

## Steps (on OSX)
- Get tje flextGL submodule by running `git submodule update --init --recursive`
- Change into the flextGL submodule `cd tools\flextGL`
- Install python3 and glfw with brew `brew install python3 glfw`
- Upgrade pip3 tools `pip3 install --upgrade pip setuptools wheel`
- Install wheezy template engine `pip3 install wheezy.template`
- cd into the flextGL home directory.
- Run `python3 flextGLgen.py -T glfw3 -D ../../src/flextGL/ profiles/gl41_core.txt` (where the profile file is the one you want to switch to)