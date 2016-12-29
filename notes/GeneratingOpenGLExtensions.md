# Generating OpenGL Headers/Extensions with flextGL

ember uses flextGL (https://github.com/ginkgo/flextGL) to generate OpenGL extensions and loaders.

We use a OpenGL 4.1 Core context by default at present and the generated flext headers are already included in ember for this.
Here are the steps in order to generate a new GL loader/extension for a different profile.

## Steps (on OSX)
- Clone flextGL at https://github.com/ginkgo/flextGL
- Install python3 and glfw with brew `brew install python3 glfw`
- Upgrade pip3 tools `pip3 install --upgrade pip setuptools wheel`
- Install wheezy template engine `pip3 install wheezy.template`
- cd into the flextGL home directory.
- Run `python3 flextGLgen.py -T glfw3 -D generated profiles/gl41_core.txt` (where the profile file is the one you want to switch to)