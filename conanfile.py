from conan import ConanFile
from conan.tools.cmake import cmake_layout


class EmberEngineConan(ConanFile):
    name = "ember-engine"
    version = "0.1.0"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    # Options for customizing the build
    options = {
        "use_luajit": [True, False],
        "enable_remotery": [True, False],
        "shared": [True, False],
        "fPIC": [True, False]
    }

    default_options = {
        "use_luajit": False,
        "enable_remotery": True,
        "shared": False,
        "fPIC": True,
        # GLFW options
        "glfw/*:shared": False,
    }

    # Dependencies
    def requirements(self):
        # Core dependencies
        self.requires("glfw/3.4")
        self.requires("eastl/3.21.23")
        self.requires("sol2/3.3.1")

        # Conditional Lua dependency
        if self.options.use_luajit:
            self.requires("luajit/2.1.0-beta3")
        else:
            self.requires("lua/5.4.7")

    def build_requirements(self):
        # Build-only dependencies (like CMake, if needed)
        pass

    def layout(self):
        cmake_layout(self)

    def configure(self):
        # fPIC is only relevant for static libraries
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def config_options(self):
        # Remove fPIC option on Windows
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")
