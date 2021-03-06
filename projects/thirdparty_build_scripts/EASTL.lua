#!lua

--
-- @file EASTL.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- For building the EASTL library.
--

local function build()
	local lib_name = "EASTL"
	local lib_src_dir = path.join(ember_thirdparty_src, lib_name)

	do_pre_build(lib_name)

	os.execute("cmake -DCMAKE_INSTALL_PREFIX:PATH=\"" .. ember_home .. "\" \"" .. lib_src_dir .. "\"")
	os.execute("cmake --build . --target install --config " .. _OPTIONS["EASTL.Config"])

	append_lib(lib_name)

	do_post_build(lib_name)
end

build()
