#!lua

--
-- @file remotery.lua
-- @author PJ O Halloran
-- @date 03/10/2017
--
-- For building the remotery library.
--

local function build()
	-- This does not build Remotery, but creates a customized header file
	-- turning on certain defines needed for each platform.
	-- Remotery is built in the solution that premake generates.
	-- We do it this way as premake has a limitation and doesnt allow us to build
	-- c and c++ files in the same project and give them different build flags (as of writing)

	local lib_name = "remotery"
	local lib_src_dir = path.join(ember_thirdparty_src, lib_name)
	local src_location = path.join(lib_src_dir, "lib")
	
	local custom_header_file_name = path.join(src_location, "Remotery.h")
	
	local f = io.open(custom_header_file_name, "r")
 	local content = f:read("*all")
 	f:close()

 	content = string.gsub(content, "#define RMT_ENABLED 1", string.format("#define RMT_ENABLED %s", _OPTIONS["Remotery.Enabled"]))
 	content = string.gsub(content, "#define RMT_USE_CUDA 0", string.format("#define RMT_USE_CUDA %s", _OPTIONS["Remotery.CudaEnabled"]))

	local enable_opengl_profiling = "0"
	local enable_d3d11_profiling = "0"
	local enable_metal_profiling = "0"

	if(os.istarget("macosx")) then
		if(_OPTIONS["Remotery.API"] == "opengl") then
			enable_opengl_profiling = "1"
		elseif(_OPTIONS["Remotery.API"] == "metal") then
			enable_metal_profiling = "1"
		end
	elseif(os.istarget("windows")) then
		if(_OPTIONS["Remotery.API"] == "opengl") then
			enable_opengl_profiling = "1"
		elseif(_OPTIONS["Remotery.API"] == "d3d11") then
			enable_d3d11_profiling = "1"
		end
	end

	content = string.gsub(content, "#define RMT_USE_OPENGL 0", string.format("#define RMT_USE_OPENGL %s", enable_opengl_profiling))
	content = string.gsub(content, "#define RMT_USE_D3D11 0", string.format("#define RMT_USE_D3D11 %s", enable_d3d11_profiling))
	content = string.gsub(content, "#define RMT_USE_METAL 0", string.format("#define RMT_USE_METAL %s", enable_metal_profiling))

	local f = io.open(custom_header_file_name, "w")
	f:write(content)
	f:close()
end

build()
