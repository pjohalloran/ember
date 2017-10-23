#!lua

require 'thirdparty'
require 'thirdparty_build_flags'

-- Checks to see if the platform you are developing on is supported and will exit right away if not.
check_platform_supported()

-- Directory variables.
flextgl_lib_name = "flextGL"
flextGL_src_dir = path.join(ember_root_src, flextgl_lib_name)
remotery_lib_name = "Remotery"
remotery_src_dir = path.join(path.join(ember_thirdparty_src, remotery_lib_name), "lib")
ember_test_dir = path.join(ember_root_src, "ember-test")
generated_project_dir = "generated_project"

-- A solution contains projects, and defines the available configurations
workspace "ember-engine"
   configurations
   {
      "Debug",
      "Release"
   }
   includedirs
   {
      ember_root_include
   }
   libdirs
   {
      ember_root_lib
   }
   location(generated_project_dir)

   project "flextGL"
      kind "StaticLib"
      language "C"
      files 
      {
         path.join(flextGL_src_dir, "**.h"),
         path.join(flextGL_src_dir, "**.c")
      }
      location(generated_project_dir)
      targetdir (ember_root_lib)

      filter "configurations:Debug"
         defines { "DEBUG" }
         symbols "On"

      filter "configurations:Release"
         defines { "NDEBUG", "RELEASE" }
         optimize "On"

   project "Remotery"
      kind "StaticLib"
      language "C"
      files 
      {
         path.join(remotery_src_dir, "**.h"),
         path.join(remotery_src_dir, "**.c")
      }
      location(generated_project_dir)
      targetdir (ember_root_lib)

      filter "options:API=metal"
         files 
         {
            path.join(remotery_src_dir, "**.mm")
         }

      filter "configurations:Debug"
         defines { "DEBUG" }
         symbols "On"

      filter "configurations:Release"
         defines { "RELEASE" }
         optimize "On"

   project "ember"
      kind "StaticLib"
      language "C++"
      files
      {
         path.join(ember_root_src, "**.h"),
         path.join(ember_root_src, "**.cpp")
      }
      removefiles
      {
         path.join(ember_test_dir, "**.h"),
         path.join(ember_test_dir, "**.cpp"),
         path.join(flextGL_src_dir, "**.h"),
         path.join(flextGL_src_dir, "**.c"),
         path.join(remotery_src_dir, "**.h"),
         path.join(remotery_src_dir, "**.c"),
         path.join(ember_thirdparty_src, "**")
      }
      location(generated_project_dir)
      linkoptions
      {
         ember_shared_link_flags
      }
      links
      {
         ember_libs
      }
      buildoptions
      {
         ember_cpp_flags
      }
      sysincludedirs
      {
         ember_root_include,
         remotery_src_dir,
         path.join(ember_root_include, "string_id"),
         path.join(ember_root_include, "luajit"),
         path.join(ember_root_include, "lua")
      }
      includedirs
      {
         ember_root_src
      }
      targetdir(ember_root_lib)
      filter "configurations:Debug"
         defines { "DEBUG" }
         symbols "On"

      filter "configurations:Release"
         defines { "RELEASE" }
         optimize "On"

      filter "system:macosx"
         frameworkdirs{ "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks" }
         defines
         {
            "TARGET_OS_MAC"
         }

   project "ember-test"
      kind "ConsoleApp"
      language "C++"
      buildoptions
      {
         ember_cpp_flags
      }
      links
      {
         ember_libs,
         flextgl_lib_name,
         remotery_lib_name,
         "ember"
      }
      linkoptions
      {
         ember_exe_link_flags
      }
      files
      {
         path.join(ember_test_dir, "**.h"),
         path.join(ember_test_dir, "**.cpp")
      }
      sysincludedirs
      {
         ember_root_include,
         remotery_src_dir,
         path.join(ember_root_include, "string_id"),
         path.join(ember_root_include, "luajit"),
         path.join(ember_root_include, "lua")
      }
      includedirs
      {
         ember_root_src
      }
      location(generated_project_dir)
      targetdir (ember_root_bin)
      libdirs { ember_root_lib }

      filter "configurations:Debug"
         defines { "DEBUG" }
         symbols "On"

      filter "configurations:Release"
         defines { "RELEASE" }
         optimize "On"

      filter "system:macosx"
         frameworkdirs{ "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks" }
         defines
         {
            "TARGET_OS_MAC"
         }