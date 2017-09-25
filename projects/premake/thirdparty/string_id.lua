--
-- @file string_id.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- For building the string_id library.
--

local lib_name = "string_id"
local lib_src_dir = path.join(ember_thirdparty_src, lib_name)

local function build()
	os.mkdir(lib_name)
	os.chdir(lib_name)

	os.execute("cmake -DCMAKE_INSTALL_PREFIX:PATH=\"" .. ember_home .. "\" \"" .. lib_src_dir .. "\"")
	os.execute("cmake --build . --target \"foonathan_string_id\"")

	if(copy_files("*." .. lib_ext, ember_root_lib) == false) then
		os.exit()
	end

	lib_include_path = path.join(ember_root_include, lib_name)

	os.mkdir(lib_include_path)

	if(copy_files(path.join(lib_src_dir, "*.hpp*"), lib_include_path) == false) then
		os.exit()
	end

	os.chdir("..")
	os.rmdir(lib_name)
end

build()
