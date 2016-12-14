#!lua

require 'conanpremake'

-- Project names
ember = "ember"
libember = "libember"
ember_test = "ember-test"

-- Directory variables.
local_src_dir = "../../src/"
local_ember_test_dir = local_src_dir .. ember_test
local_include_dir = "../../include/"
local_lib_dir = "../../libs/"
generated_project_dir = "generated_project"

-- A solution contains projects, and defines the available configurations
solution ember
   configurations
   {
      "Debug",
      "Release"
   }
   includedirs
   {
      conan_includedirs
   }
   libdirs
   {
      conan_libdirs
   }
   links
   {
      conan_libs
   }

   project libember
      kind "StaticLib"
      language "C++"
      files
      {
         local_src_dir .. "**.h",
         local_src_dir .. "**.cpp"
      }
      excludes
      {
         local_ember_test_dir .. "**.h",
         local_ember_test_dir .. "**.cpp"
      }
      location(generated_project_dir)
      configuration "Debug"
         defines
         {
            "DEBUG"
         }
         flags
         {
            "Symbols"
         }
         targetdir (local_lib_dir .. "debug")
      configuration "Release"
         defines
         {
            "RELEASE"
         }
         flags
         {
            "Optimize"
         }
         targetdir (local_lib_dir .. "release")

   project ember_test
      kind "ConsoleApp"
      language "C++"
      links
      {
         libember
      }
      files
      {
         local_ember_test_dir .. "**.h",
         local_ember_test_dir .. "**.cpp"
      }
      location(generated_project_dir)
      configuration "Debug"
         defines
         {
            "DEBUG"
         }
         flags
         {
            "Symbols"
         }
      configuration "Release"
         defines
         {
            "RELEASE"
         }
         flags
         {
            "Optimize"
         }