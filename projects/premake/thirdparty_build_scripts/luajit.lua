#!lua

--
-- @file luajit.lua
-- @author PJ O Halloran
-- @date 30/09/2017
--
-- For building the luajit library.
--

local lib_name = "luajit"
local target_lib_name = "lua"
local lib_src_dir = path.join(ember_thirdparty_src, lib_name)

local function build()
	do_pre_build(lib_name)

	local tmp_install_dir = path.join(os.getcwd(), "tmp_install")

	os.mkdir(tmp_install_dir)

	os.execute("cmake -DCMAKE_INSTALL_PREFIX:PATH=\"" .. tmp_install_dir .. "\" \"" .. lib_src_dir .. "\"")
	os.execute("cmake --build . --target install")

	local lib_include_path = path.join(ember_root_include, lib_name)
	os.mkdir(lib_include_path)

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
