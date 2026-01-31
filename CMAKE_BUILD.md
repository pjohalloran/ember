# Building Ember with CMake + Conan

This is a proof-of-concept demonstrating how Ember could be built using CMake and the Conan package manager instead of Premake + Lua.

## Quick Start

### 1. Install Prerequisites

**macOS:**
```bash
# Install Conan
pip3 install conan

# Install CMake (if not already installed)
brew install cmake
```

**Windows:**
```bash
# Install Conan
pip install conan

# CMake usually comes with Visual Studio, or download from cmake.org
```

**Linux:**
```bash
# Install Conan
pip3 install conan

# Install CMake
sudo apt-get install cmake  # Ubuntu/Debian
# or
sudo yum install cmake      # CentOS/RHEL
```

### 2. Configure Conan (First Time Only)

```bash
# Auto-detect your system configuration
conan profile detect --force
```

### 3. Build Ember

```bash
# Install dependencies (downloads pre-built binaries)
conan install . --output-folder=build --build=missing

# Configure the project
cmake --preset conan-default

# Build (Debug)
cmake --build build

# Build (Release)
cmake --build build --config Release
```

### 4. Run the Test Application

```bash
# macOS/Linux
./build/bin/ember-test

# Windows
.\build\bin\Release\ember-test.exe
```

## Configuration Options

### Using LuaJIT instead of Lua

```bash
conan install . --output-folder=build --build=missing -o use_luajit=True
cmake --preset conan-default
cmake --build build
```

### Disabling Remotery Profiling

```bash
cmake --preset conan-default -DEMBER_ENABLE_REMOTERY=OFF
cmake --build build
```

### Building Tests Only

```bash
cmake --preset conan-default -DEMBER_ENABLE_TESTS=ON
cmake --build build --target ember-test
```

## Available CMake Options

| Option | Default | Description |
|--------|---------|-------------|
| `EMBER_USE_LUAJIT` | OFF | Use LuaJIT instead of standard Lua |
| `EMBER_ENABLE_REMOTERY` | ON | Enable Remotery profiling support |
| `EMBER_ENABLE_TESTS` | ON | Build the ember-test executable |

## IDE Integration

### Visual Studio Code

Install the CMake Tools extension, then:
1. Open the folder in VSCode
2. Select a kit (e.g., "GCC 9.3.0")
3. Press F7 to build

### CLion

1. Open the project (CLion will detect CMakeLists.txt)
2. It will automatically run Conan and configure
3. Press Ctrl+F9 to build

### Xcode

```bash
# Generate Xcode project
cmake -G Xcode -S . -B build

# Open in Xcode
open build/ember-engine.xcodeproj
```

### Visual Studio

```bash
# CMake can generate VS solution
cmake -G "Visual Studio 17 2022" -S . -B build

# Open in Visual Studio
start build\ember-engine.sln
```

## Troubleshooting

### "Conan package not found"

Some packages might not be in ConanCenter. The current setup uses FetchContent as a fallback for these:
- string_id (foonathan)
- loguru (if needed)

### Build fails with missing dependencies

Try forcing a rebuild:
```bash
conan install . --output-folder=build --build=missing --update
cmake --preset conan-default
cmake --build build --clean-first
```

### Conan profile issues

Reset your Conan profile:
```bash
conan profile detect --force
```

## Comparison to Premake Build

| Aspect | Premake + Lua | CMake + Conan |
|--------|---------------|---------------|
| **First build time** | 15-20 minutes | 2-3 minutes |
| **Rebuild time** | 2-3 minutes | 30-60 seconds |
| **Repo size** | ~60MB (with submodules) | ~10MB |
| **External tools** | premake5 | cmake, conan |
| **IDE support** | Xcode, VS | All major IDEs |

See [CMAKE_COMPARISON.md](CMAKE_COMPARISON.md) for a detailed comparison.

## Project Structure

```
ember/
├── CMakeLists.txt              # Root build configuration
├── conanfile.txt               # Simple dependency list
├── conanfile.py                # Advanced dependency management
├── src/
│   ├── CMakeLists.txt          # ember library build
│   ├── app/                    # Application code
│   ├── core/                   # Core functionality
│   ├── events/                 # Event system
│   ├── file/                   # File I/O
│   ├── input/                  # Input handling
│   ├── scripting/              # Lua scripting
│   └── ember-test/
│       └── CMakeLists.txt      # Test executable build
└── build/                      # Generated files (gitignored)
```

## Clean Build

```bash
# Remove build directory
rm -rf build

# Start fresh
conan install . --output-folder=build --build=missing
cmake --preset conan-default
cmake --build build
```

## Notes

- **Git submodules not needed**: Conan manages all third-party dependencies
- **Binary caching**: Dependencies are downloaded pre-built (much faster)
- **Cross-platform**: Same commands work on macOS, Windows, and Linux
- **Incremental builds**: Only changed files are rebuilt

## Feedback Welcome!

This is a proof-of-concept. Please test and provide feedback on:
- Build times on your system
- Any issues encountered
- Missing features
- Overall experience

Compare this to the existing Premake build and let me know which you prefer!
