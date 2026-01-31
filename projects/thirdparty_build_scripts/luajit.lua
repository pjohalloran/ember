#!lua

--
-- @file luajit.lua
-- @author PJ O Halloran
-- @date 30/09/2017
--
-- For building the luajit library.
--

local function build()
	local lib_name = "luajit"
	local target_lib_name = "lua"
	local lib_src_dir = path.join(ember_thirdparty_src, lib_name)
	
	if(_OPTIONS["sol2.Config"] ~= lib_name) then
		return
	end

	do_pre_build(lib_name)

	local tmp_install_dir = path.join(os.getcwd(), "tmp_install")

	safe_mkdir(tmp_install_dir)

	execute_or_fail("cmake -DCMAKE_INSTALL_PREFIX:PATH=\"" .. tmp_install_dir .. "\" \"" .. lib_src_dir .. "\"", "Failed to configure " .. lib_name .. " with CMake")
	execute_or_fail("cmake --build . --target install", "Failed to build " .. lib_name)

	local lib_include_path = path.join(ember_root_include, lib_name)
	safe_mkdir(lib_include_path)

	if(copy_files(path.join(tmp_install_dir, "include/*"), lib_include_path) == false) then
		os.exit()
	end

	if(copy_files(path.join(tmp_install_dir, "lib/*"), ember_root_lib) == false) then
		os.exit()
	end

	append_lib(target_lib_name)

	do_post_build(lib_name)
end

build()
