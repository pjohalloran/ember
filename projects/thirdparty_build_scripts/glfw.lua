#!lua

--
-- @file glfw.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- For building the glfw library.
--

local lib_name = "glfw"
local target_lib_name = lib_name .. "3"
local lib_src_dir = path.join(ember_thirdparty_src, lib_name)

local function build()
	do_pre_build(lib_name)
	
	os.execute("cmake -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_DOCS=OFF -DCMAKE_INSTALL_PREFIX:PATH=\"" .. ember_home .. "\" \"" .. lib_src_dir .. "\"")
	os.execute("cmake --build . --target install")

	append_lib(target_lib_name)

	append_framework_shared_link_flag("OpenGL")
	append_framework_shared_link_flag("Cocoa")
	append_framework_shared_link_flag("IOKit")
	append_framework_shared_link_flag("CoreVideo")

	append_framework_exe_link_flag("OpenGL")
	append_framework_exe_link_flag("Cocoa")
	append_framework_exe_link_flag("IOKit")
	append_framework_exe_link_flag("CoreVideo")

	do_post_build(lib_name)
end

build()
