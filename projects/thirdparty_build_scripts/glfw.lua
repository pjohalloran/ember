#!lua

--
-- @file glfw.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- For building the glfw library.
--

local function build()
	local lib_name = "glfw"
	local target_lib_name = lib_name .. "3"
	local lib_src_dir = path.join(ember_thirdparty_src, lib_name)

	do_pre_build(lib_name)
	
	local cmake_flags = "-DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_DOCS=OFF -DCMAKE_INSTALL_PREFIX:PATH=\"" .. ember_home .. "\" \"" .. lib_src_dir .. "\""

	if(os.istarget("windows")) then
		cmake_flags = cmake_flags .. " -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ON"
	end

	print(cmake_flags)

	os.execute("cmake " .. cmake_flags)
	os.execute("cmake --build . --target install")

	append_lib(target_lib_name)

	if (os.istarget("macosx")) then
		append_framework_shared_link_flag("OpenGL")
		append_framework_shared_link_flag("Cocoa")
		append_framework_shared_link_flag("IOKit")
		append_framework_shared_link_flag("CoreVideo")

		append_framework_exe_link_flag("OpenGL")
		append_framework_exe_link_flag("Cocoa")
		append_framework_exe_link_flag("IOKit")
		append_framework_exe_link_flag("CoreVideo")
	elseif(os.istarget("windows")) then
		append_lib("opengl32")
	end

	do_post_build(lib_name)
end

build()
