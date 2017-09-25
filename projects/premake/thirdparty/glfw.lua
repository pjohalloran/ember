--
-- @file glfw.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- For building the glfw library.
--

local lib_name = "glfw"
local lib_src_dir = path.join(ember_thirdparty_src, lib_name)

local function build()
	os.mkdir(lib_name)
	os.chdir(lib_name)

	os.execute("cmake -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_DOCS=OFF -DCMAKE_INSTALL_PREFIX:PATH=\"" .. ember_home .. "\" \"" .. lib_src_dir .. "\"")
	os.execute("cmake --build . --target install")

	os.chdir("..")
	os.rmdir(lib_name)
end

build()
