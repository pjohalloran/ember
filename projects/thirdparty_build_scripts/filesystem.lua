#!lua

--
-- @file filesystem.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- For building the filesystem library.
--

local function build()
	local lib_name = "filesystem"
	
	headers_pattern = path.join(lib_name, "*.h")
	do_header_only_lib_copy(lib_name, headers_pattern)

	append_shared_link_flag("-std=c++14")
	
	append_exe_link_flag("-std=c++14")

	append_cpp_flag("-std=c++14")
	append_cpp_flag("-stdlib=libc++")
end

build()
