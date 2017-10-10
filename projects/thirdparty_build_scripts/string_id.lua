#!lua

--
-- @file string_id.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- For building the string_id library.
--

local function build()
	local lib_name = "string_id"
	local output_lib_name = "foonathan_" .. lib_name
	local lib_src_dir = path.join(ember_thirdparty_src, lib_name)
	
	do_pre_build(lib_name)

	os.execute("cmake -DCMAKE_INSTALL_PREFIX:PATH=\"" .. ember_home .. "\" \"" .. lib_src_dir .. "\"")
	os.execute("cmake --build . --target \"" .. output_lib_name .. "\"")

	if(copy_files("*." .. lib_ext, ember_root_lib) == false) then
		os.exit()
	end

	lib_include_path = path.join(ember_root_include, lib_name)

	os.mkdir(lib_include_path)

	if(copy_files(path.join(lib_src_dir, "*.hpp*"), lib_include_path) == false) then
		os.exit()
	end

	if(copy_files("config_impl.hpp", path.join(ember_root_include, lib_name)) == false) then
		os.exit()
	end

	append_lib(output_lib_name)
	append_shared_link_flag("-std=c++14")
	append_exe_link_flag("-std=c++14")
	append_cpp_flag("-std=c++14")
	append_cpp_flag("-stdlib=libc++")

	do_post_build(lib_name)
end

build()
