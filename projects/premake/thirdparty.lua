#!lua

--
-- @file thirdparty.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- premake related build scripts for building embers third party libraries.
-- The libs and headers are placed in the root directory of ember.
--

-- im doing this (calling getdirectory * 2) as i know script is 2 dirs above root!
-- Not great but unsure how else to do it.
ember_home = path.getdirectory(path.getdirectory(path.join(os.getcwd())))

ember_root_include = path.join(ember_home, "include")
ember_root_lib = path.join(ember_home, "lib")
ember_root_src = path.join(ember_home, "src")
ember_root_bin = path.join(ember_home, "bin")
ember_thirdparty_src = path.join(ember_home, path.join("src", "thirdparty"))
ember_thirdparty_project = path.join(path.join(ember_home, "projects"), "premake")
ember_thirdparty_build = path.join(ember_thirdparty_project, "thirdparty_build_scripts")
ember_thirdparty_incremental = path.join(ember_thirdparty_project, "incremental_build")

ember_shared_link_flags = ""
ember_cpp_flags = ""
ember_exe_link_flags = ""
ember_libs = ""

lib_ext = ""

-- ember premake5.lua needs this to exist if it does not already..
if(not os.isfile("thirdparty_build_flags.lua")) then
   os.touchfile("thirdparty_build_flags.lua")
end

--
-- Gets the library extension for this type of OS.
--
local function get_lib_ext()
	if(os.ishost("windows")) then
		return "lib"
	else
		return "a"
	end
end

--
-- Checks if cmake is installed and on the path.
--
local function check_for_cmake()
	res = os.execute("cmake --version")

	if(res == nil) then
		print("cmake is not installed and is required in order to build the third party dependacies!\ncmake can be found at: \"https://cmake.org\"")
		os.exit(1)
	end
end

local function trim(s)
  return string.gsub(s, "^%s*(.-)%s*$", "%1")
end

local function write_build_flags_to_file()
	local filename = "thirdparty_build_flags.lua"
	local content = string.format("ember_shared_link_flags = \"%s\"\nember_cpp_flags = \"%s\"\nember_exe_link_flags = \"%s\"\nember_libs = \"%s\"\n",
		trim(ember_shared_link_flags),
		trim(ember_cpp_flags),
		trim(ember_exe_link_flags),
		trim(ember_libs))
	io.writefile(filename, content)
end

function do_pre_build(lib_name)
	local tmp_dir = path.join(ember_thirdparty_incremental, lib_name)
	os.mkdir(tmp_dir)
	os.chdir(tmp_dir)
end

function do_post_build(lib_name)
	os.chdir(path.join("..", ".."))
end

--
-- Triggers building all third party libraries.
--
local function build()
	check_for_cmake()

	lib_ext = get_lib_ext()

	if(not os.isdir(ember_root_include)) then
		os.mkdir(ember_root_include)
	end

	if(not os.isdir(ember_root_lib)) then
		os.mkdir(ember_root_lib)
	end

	if(not os.isdir(ember_thirdparty_incremental)) then
		os.mkdir(ember_thirdparty_incremental)
	end

	local third_party_libs = os.matchfiles(path.join(ember_thirdparty_build, "*.lua"))

	local i = 1
	local size = #third_party_libs

	-- Execute all the lua scripts defined in "thirdparty_build_scripts".
	while i <= size do
		local lib_name = path.getbasename(third_party_libs[i])
		print("Executing " .. third_party_libs[i] .. " for Lib: " .. lib_name);
		if(third_party_libs[i] ~= nil) then
	   		dofile(third_party_libs[i])
		end
		i = i + 1
	end

	write_build_flags_to_file()
end

--
-- Cleans all files generated by the build.
--
local function clean()
	if(os.isdir(ember_root_include)) then
		os.rmdir(ember_root_include)
	end

	if(os.isdir(ember_root_lib)) then
		os.rmdir(ember_root_lib)
	end

	if(os.isdir(ember_thirdparty_incremental)) then
		os.rmdir(ember_thirdparty_incremental)
	end
end

--
-- Common helper function to copy files matching a file pattern.
-- e.g.
-- *.lib, *.hpp, etc.
--
-- @param lib_name The name of the library we are copying files for.
-- @param file_pattern The wildcard, file pattern of files to copy.
--
function copy_files(file_pattern, target_dir)
	if(not os.isdir(target_dir)) then
		print("Cannot copy files with pattern \"" .. file_pattern .. "\" as \"" .. target_dir .. "\" is not a valid directory")
		return false
	end

	matched_files = os.matchfiles(file_pattern)

	local i = 1
	local size = #matched_files

	while i <= size do
	   	res, errorString = os.copyfile(matched_files[i], target_dir)

		if(res == nil) then
			print("Failed to copy " .. matched_files[i] .. " to target \"" .. target_dir .. "\"\nReason: " .. errorString)
			os.exit(1)
		end
	   i = i + 1
	end

	return true
end

--
-- Common helper function to copy files matching a file pattern
-- AND create the target directory if it does not yet exist.
-- e.g.
-- *.lib, *.hpp, etc.
--
-- @param lib_name The name of the library we are copying files for.
-- @param file_pattern The wildcard, file pattern of files to copy.
--
function copy_files_to_new_directory(file_pattern, target_dir)
	if(not os.isdir(target_dir)) then
		os.mkdir(target_dir)
	end

	return copy_files(file_pattern, target_dir)
end

--
-- Common helper function to copy & prepare header only libraries
--
-- @param lib_name The name of the library we are copying files for.
-- @param file_pattern The wildcard, file pattern of files to copy.
--
function do_header_only_lib_copy(lib_name, file_pattern)
	local lib_src_dir = path.join(ember_thirdparty_src, lib_name)

	local lib_include_path = path.join(ember_root_include, lib_name)

	os.mkdir(lib_include_path)

	if(copy_files(path.join(lib_src_dir, file_pattern), lib_include_path) == false) then
		os.exit()
	end
end

local function string_starts_with(original_string, starts_string)
   return string.sub(original_string, 1, string.len(starts_string)) == starts_string
end

local function append_string_if_not_exists(original_string, append_string)
	if (append_string == nil or string.len(append_string) == 0) then
		return original_string
	end

	if(string.find(original_string, append_string, 1, true)) then
		return original_string
	end

	return original_string .. " " .. append_string
end

-- buildoptions
function append_cpp_flag(flag)
	ember_cpp_flags = append_string_if_not_exists(ember_cpp_flags, flag)
end

-- linkoptions lib
function append_shared_link_flag(flag)
	ember_shared_link_flags = append_string_if_not_exists(ember_shared_link_flags, flag)
end

-- linkoptions lib (frameworks for OSX)
function append_framework_shared_link_flag(flag)
	ember_shared_link_flags = append_string_if_not_exists(ember_shared_link_flags, "-framework " .. flag)
end

-- linkoptions exe
function append_exe_link_flag(flag)
	ember_exe_link_flags = append_string_if_not_exists(ember_exe_link_flags, flag)
end

-- linkoptions exe (frameworks for OSX)
function append_framework_exe_link_flag(flag)
	ember_exe_link_flags = append_string_if_not_exists(ember_exe_link_flags, "-framework " .. flag)
end

-- libs
function append_lib(flag)
	-- work around for a bug in premake TODO keep an eye on and revise this.
	-- on xcode it generates an extra -l before the first library
	l_flag = "-l"
	if (string.len(ember_libs) == 0) then
		l_flag = ""
	end

	ember_libs = append_string_if_not_exists(ember_libs, l_flag .. flag)
end

--
-- Options
--

newoption {
   trigger     = "EASTL.Config",
   value       = "Config",
   description = "Choose which build config to use to build the EASTL library",
   allowed = {
      { "Release",    "Release mode" },
      { "Debug",    "Debug symbols included" },
      { "RelWithDebInfo",  "Release with some debug info" },
      { "MinSizeRel",  "Small Release" }
   },
   default = "MinSizeRel"
}

newoption {
   trigger     = "sol2.Config",
   value       = "Config",
   description = "Choose which lua library to link with",
   allowed = {
      { "lua",    "Standard Lua" },
      { "luajit",    "LuaJIT" }
   },
   default = "lua"
}

--
-- Script ACTIONS
--

newaction {
   trigger     = "build_thirdparty",
   description = "Build the ember third party dependancies.",
   execute = function ()
      build()
   end
}

newaction {
   trigger     = "clean_thirdparty",
   description = "Clean the ember third party dependancies.",
   execute = function ()
      clean()
   end
}
