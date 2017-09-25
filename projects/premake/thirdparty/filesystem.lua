--
-- @file filesystem.lua
-- @author PJ O Halloran
-- @date 25/09/2017
--
-- For building the filesystem library.
--

local lib_name = "filesystem"

local function build()
	headers_pattern = path.join(lib_name, "*.h")
	do_header_only_lib_copy(lib_name, headers_pattern)
end

build()
