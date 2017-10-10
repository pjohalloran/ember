#!lua

--
-- @file loguru.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- For building the loguru library.
--

local function build()
	local lib_name = "loguru"
	
	do_header_only_lib_copy(lib_name, "loguru.hpp")

	append_shared_link_flag("-std=c++14")
	
	append_exe_link_flag("-std=c++14")
	
	append_lib("stdc++")
	append_lib("pthread")
	append_lib("dl")

	append_cpp_flag("-std=c++14")
	append_cpp_flag("-stdlib=libc++")
end

build()
