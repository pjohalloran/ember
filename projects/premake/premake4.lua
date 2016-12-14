#!lua

require 'conanpremake'

-- Directory variables.
local_src_dir = "../../src/"
local_ember_test_dir = local_src_dir .. "ember-test"
local_include_dir = "../../include/"
local_lib_dir = "../../libs/"
local_bin_dir = "../../bin/"
generated_project_dir = "generated_project"

-- A solution contains projects, and defines the available configurations
solution "ember"
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
   location(generated_project_dir)

   project "libember"
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

   project "ember-test"
      kind "ConsoleApp"
      language "C++"
      links
      {
         "libember"
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
         libdirs
         {
            local_lib_dir .. "debug"
         }
         targetdir (local_bin_dir .. "debug")
      configuration "Release"
         defines
         {
            "RELEASE"
         }
         flags
         {
            "Optimize"
         }
         libdirs
         {
            local_lib_dir .. "release"
         }
         targetdir (local_bin_dir .. "release")