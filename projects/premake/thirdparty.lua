
-- 
ember_home = path.join(os.getcwd(), path.join("..", ".."))
ember_root_include = path.join(ember_home, "include")
ember_root_lib = path.join(ember_home, "lib")
ember_thirdparty_src = path.join(ember_home, path.join("src", "thirdparty"))

lib_ext = ""

local function get_lib_ext()
	if(os.ishost("windows")) then
		return "lib"
	else
		return "a"
	end
end

local function check_for_cmake()
	res = os.execute("cmake --version")

	if(res == nil) then
		print("cmake is not installed and is required in order to build the third party dependacies!\ncmake can be found at: \"https://cmake.org\"")
		os.exit(1)
	end
end

local function build()
	check_for_cmake()

	lib_ext = get_lib_ext()

	if(not os.isdir(ember_root_include)) then
		os.mkdir(ember_root_include)
	end

	if(not os.isdir(ember_root_lib)) then
		os.mkdir(ember_root_lib)
	end

	local third_party_libs = {
	   "thirdparty/glfw.lua",
	   "thirdparty/EASTL.lua",
	   "thirdparty/string_id.lua",
	};

	local i = 1
	local size = #third_party_libs

	-- Execute all the scripts defined in "third_party_libs".
	while i <= size do
	   print("Executing " .. third_party_libs[i]);
	   if(third_party_libs[i] == nil) then
	      print(third_party_libs[i] .. " is nil")
	   else
	      dofile(third_party_libs[i])
	   end
	   i = i + 1
	end
end

local function clean()
	if(os.isdir(ember_root_include)) then
		os.rmdir(ember_root_include)
	end

	if(os.isdir(ember_root_lib)) then
		os.rmdir(ember_root_lib)
	end
end

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
   }
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
