--
-- @file loguru.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- For building the loguru library.
--

local lib_name = "loguru"

local function build()
	do_header_only_lib_copy(lib_name, "loguru.hpp")
end

build()
