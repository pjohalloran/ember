#!lua

--
-- @file remotery.lua
-- @author PJ O Halloran
-- @date 03/10/2017
--
-- For building the remotery library.
--

local custom_header_file_content = [[
//
// @file EmberRemotery.h
// 
// AUTOGENERATED file to customize Remotery for Ember
//

#define RMT_ENABLED %i

#define RMT_USE_CUDA %i

#define RMT_USE_D3D11 %i

#define RMT_USE_OPENGL %i

#define RMT_USE_METAL %i

#include <Remotery.h>

]]

local function write_header_file(filename)
	local enable_remotery = tonumber(_OPTIONS["Remotery.Enabled"])
	local enable_cuda_profiling = tonumber(_OPTIONS["Remotery.CudaEnabled"])
	local enable_opengl_profiling = 0
	local enable_d3d11_profiling = 0
	local enable_metal_profiling = 0

	if(os.istarget("macosx")) then
		if(_OPTIONS["Remotery.API"] == "opengl") then
			enable_opengl_profiling = 1
		elseif(_OPTIONS["Remotery.API"] == "metal") then
			enable_metal_profiling = 1
		end
	elseif(os.istarget("windows")) then
		if(_OPTIONS["Remotery.API"] == "opengl") then
			enable_opengl_profiling = 1
		elseif(_OPTIONS["Remotery.API"] == "d3d11") then
			enable_d3d11_profiling = 1
		end
	end

	local content = string.format(custom_header_file_content,
		enable_remotery,
		enable_cuda_profiling,
		enable_d3d11_profiling,
		enable_opengl_profiling,
		enable_metal_profiling)

	io.writefile(filename, content)
end

local function build()
	-- This does not build Remotery, but creates a customized header file
	-- turning on certain defines needed for each platform.
	-- Remotery is built in the solution that premake generates.
	-- We do it this way as premake has a limitation and doesnt allow us to build
	-- c and c++ files in the same project and give them different build flags (as of writing)

	local lib_name = "remotery"
	local lib_src_dir = path.join(ember_thirdparty_src, lib_name)
	local src_location = path.join(lib_src_dir, "lib")
	local custom_header_file_name = path.join(src_location, "EmberRemotery.h")
	
	write_header_file(custom_header_file_name)


end

build()
