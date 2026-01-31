# CMake + Conan vs Premake + Lua Comparison

This document compares the current Premake + Lua build system with a proposed CMake + Conan approach.

## Executive Summary

| Aspect | Premake + Lua | CMake + Conan |
|--------|---------------|---------------|
| **Complexity** | 3 layers (Premake→Lua→CMake) | 1 layer (CMake) |
| **Dependencies** | Git submodules | Conan package manager |
| **Build Speed** | Slow (builds from source) | Fast (binary caching) |
| **IDE Support** | Good (VS, Xcode) | Excellent (VS, Xcode, CLion, VSCode) |
| **Learning Curve** | Medium-High | Medium |
| **Maintenance** | Custom scripts per library | Declarative configuration |
| **Error Handling** | Manual (recently improved) | Built-in |
| **Community** | Smaller | Larger |

## Current System: Premake + Lua + Git Submodules

### Build Process

```bash
# Clone with submodules (10 third-party libraries)
git clone --recursive https://github.com/pjohalloran/ember.git

# Build third-party dependencies (takes ~10-20 minutes)
cd projects
premake5 build_thirdparty

# Generate IDE projects
premake5 xcode4  # or vs2017

# Open IDE and build
```

### Architecture

```
User runs: premake5 build_thirdparty
    ↓
Loads: thirdparty.lua (orchestration)
    ↓
Executes: Each library's Lua script (9 files)
    ↓
Runs: CMake commands via os.execute()
    ↓
Copies: Libraries to lib/, headers to include/
    ↓
Saves: Compiler flags to thirdparty_build_flags.lua
    ↓
User runs: premake5 xcode4/vs2017
    ↓
Loads: premake5.lua + thirdparty_build_flags.lua
    ↓
Generates: Xcode/VS project files
```

### Third-Party Libraries

| Library | How It's Built | Time |
|---------|---------------|------|
| EASTL | CMake via Lua | ~2 min |
| GLFW | CMake via Lua | ~2 min |
| Lua/LuaJIT | CMake via Lua | ~2 min |
| string_id | CMake via Lua | ~1 min |
| loguru | Header copy | <1 sec |
| sol2 | Header copy | <1 sec |
| filesystem | Header copy | <1 sec |
| flextGL | Built in main project | N/A |
| Remotery | Built in main project | N/A |

**Total build time**: ~10-15 minutes on first build

### Strengths

✅ **Custom control**: Full control over build process per library
✅ **Premake simplicity**: Premake5.lua syntax is clean and readable
✅ **Works today**: Already integrated and functional
✅ **No external package manager**: Self-contained (except premake5 itself)
✅ **Version pinning**: Git submodules pin exact commits

### Weaknesses

❌ **Slow builds**: Everything built from source every time
❌ **No binary caching**: Changing one library script rebuilds all
❌ **Submodule management**: 10 submodules to keep updated
❌ **Three-layer abstraction**: Premake → Lua → CMake
❌ **Error handling gaps**: Silent failures possible (being fixed)
❌ **Clone complexity**: Must remember `--recursive` flag
❌ **Disk space**: Full source for all libraries in repo
❌ **CI/CD overhead**: Every CI run builds all dependencies

### File Count

- **9** Lua build scripts (one per library)
- **1** orchestration script (thirdparty.lua)
- **1** main premake file (premake5.lua)
- **10** git submodules
- **~375 lines** of custom Lua build code

---

## Proposed System: CMake + Conan

### Build Process

```bash
# Clone (no submodules needed!)
git clone https://github.com/pjohalloran/ember.git
cd ember

# Install dependencies via Conan (~30 seconds with binary cache)
conan install . --output-folder=build --build=missing

# Configure with CMake
cmake --preset conan-default

# Build
cmake --build build

# Done! (~2 minutes total on first build with binary cache)
```

### Architecture

```
User runs: conan install
    ↓
Conan: Downloads pre-built binaries (or builds if needed)
    ↓
Saves: CMake configuration files to build/
    ↓
User runs: cmake --preset conan-default
    ↓
CMake: Configures project using Conan-provided dependencies
    ↓
User runs: cmake --build
    ↓
Builds: Only ember code (dependencies already built)
```

### Third-Party Libraries

| Library | How It's Provided | Time |
|---------|------------------|------|
| EASTL | Conan binary | <5 sec |
| GLFW | Conan binary | <5 sec |
| Lua/LuaJIT | Conan binary | <5 sec |
| sol2 | Conan binary | <5 sec |
| string_id | FetchContent | ~1 min |
| flextGL | Built in main project | N/A |
| Remotery | Built in main project | N/A |

**Total setup time**: ~30 seconds (with Conan cache)
**First build time**: ~2-3 minutes

### Strengths

✅ **Fast builds**: Binary caching (10-20x faster than source builds)
✅ **Single build system**: Only CMake, no Premake/Lua layer
✅ **Industry standard**: CMake is ubiquitous (better IDE support, documentation)
✅ **No submodules**: Conan manages dependencies
✅ **Smaller repo**: No third-party source in git
✅ **Better IDE support**: CLion, VSCode, Qt Creator work great
✅ **Cross-platform**: CMake handles platform differences
✅ **Built-in error handling**: CMake fails fast with clear errors
✅ **CI/CD friendly**: Binary cache = fast CI builds
✅ **Version management**: `conanfile.txt` clearly shows all dependencies
✅ **Transitive dependencies**: Conan handles deps of deps

### Weaknesses

❌ **External dependency**: Requires Conan to be installed
❌ **Learning curve**: CMake syntax can be verbose
❌ **Less control**: Can't customize library builds as easily
❌ **Conan learning curve**: New tool to learn
❌ **Binary trust**: Downloading pre-built binaries (can verify checksums)
❌ **Network dependency**: First build needs internet (Conan cache)

### File Count

- **3** CMakeLists.txt files (root, src, ember-test)
- **1** conanfile.txt or conanfile.py
- **0** git submodules
- **~200 lines** of CMake code

---

## Side-by-Side Comparison

### Initial Setup

**Premake + Lua**
```bash
# Clone (downloads ~50MB of third-party source)
git clone --recursive https://github.com/pjohalloran/ember.git
cd ember

# Install premake5 (manual download)
# macOS: brew install premake
# Windows: download from premake.github.io

# Build dependencies (10-15 minutes)
cd projects
premake5 build_thirdparty

# Generate projects
premake5 xcode4  # or vs2017

# Total time: 15-20 minutes
```

**CMake + Conan**
```bash
# Clone (repo is ~5MB smaller without submodules)
git clone https://github.com/pjohalloran/ember.git
cd ember

# Install Conan (one-time setup)
pip install conan

# Install dependencies (30 seconds with binary cache)
conan install . --output-folder=build --build=missing

# Configure and build
cmake --preset conan-default
cmake --build build

# Total time: 2-3 minutes
```

### Adding a New Dependency

**Premake + Lua**
1. Add git submodule: `git submodule add <url> src/thirdparty/<name>`
2. Create `projects/thirdparty_build_scripts/<name>.lua`
3. Write custom build logic (20-50 lines)
4. Debug CMake commands, path issues, etc.
5. Update `.gitmodules`
6. Commit submodule + build script

**CMake + Conan**
1. Add to `conanfile.txt`: `<name>/<version>`
2. Add to `CMakeLists.txt`: `find_package(<name> REQUIRED)`
3. Link: `target_link_libraries(ember PUBLIC <name>::<name>)`
4. Commit `conanfile.txt` + `CMakeLists.txt`

### Changing Build Configuration

**Premake + Lua**
- Edit `projects/thirdparty_build_scripts/<lib>.lua`
- Re-run `premake5 build_thirdparty` (rebuilds everything)
- Re-run `premake5 xcode4/vs2017`

**CMake + Conan**
- Edit `CMakeLists.txt` or `conanfile.txt`
- Re-run `cmake --build build` (only rebuilds changed parts)

### CI/CD Build Time

**Premake + Lua**
- Downloads all git submodules: ~30 sec
- Builds all dependencies from source: ~10-15 min
- Builds ember: ~2 min
- **Total: ~15-20 minutes**

**CMake + Conan**
- Installs Conan: ~10 sec
- Downloads binary cache: ~30 sec
- Builds ember: ~2 min
- **Total: ~3 minutes** (5-6x faster!)

---

## Migration Path

If you decide to migrate, here's a suggested approach:

### Phase 1: Proof of Concept (This Branch)
- ✅ Create CMakeLists.txt files (done)
- ✅ Create conanfile.txt/py (done)
- ✅ Test builds on macOS and Windows
- ✅ Measure build time improvements
- ✅ Document any issues

### Phase 2: Parallel Support
- Keep both build systems working
- Let contributors choose
- Gather feedback

### Phase 3: Gradual Migration
- Make CMake the default
- Keep Premake as fallback
- Update documentation

### Phase 4: Full Migration
- Remove Premake files
- Remove git submodules
- Update README

---

## Recommendation

### For **Learning and Control** → Stay with Premake
If you value understanding exactly how dependencies are built and enjoy the Lua scripting, the current system is fine (especially with the error handling fixes).

### For **Speed and Modern Workflow** → Migrate to CMake + Conan
If you want:
- **10x faster builds**
- **Smaller repository**
- **Better IDE support**
- **Industry-standard tooling**
- **Easier onboarding for contributors**

Then CMake + Conan is the clear winner.

---

## Build Instructions for This Branch

### Prerequisites

```bash
# Install Conan
pip install conan

# Configure Conan profile (first time only)
conan profile detect
```

### Build Steps

```bash
# Install dependencies
conan install . --output-folder=build --build=missing

# Configure
cmake --preset conan-default

# Build
cmake --build build --config Release

# Run
./build/bin/ember-test
```

### Using LuaJIT instead of Lua

Edit `conanfile.py` and set:
```python
default_options = {
    "use_luajit": True,
    ...
}
```

Then rebuild:
```bash
conan install . --output-folder=build --build=missing -o use_luajit=True
cmake --preset conan-default
cmake --build build
```

---

## Questions?

Feel free to test this branch and provide feedback on:
1. Build times on your machine
2. Any missing dependencies or features
3. IDE integration experience
4. Overall preference

**Both approaches are valid** – this POC is meant to help you make an informed decision!
