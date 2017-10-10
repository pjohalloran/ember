#!lua

--
-- @file sol2.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- For building the sol2 library.
--

local function build()
	local lib_name = "sol2"
	
	hpp_dir = path.join("single", "sol")
	hpp_name = path.join(hpp_dir, "sol.hpp")

	do_header_only_lib_copy(lib_name, hpp_name)
end

build()
