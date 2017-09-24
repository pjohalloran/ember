local lib_name = "EASTL"
local lib_src_dir = path.join(ember_thirdparty_src, lib_name)

local function build()
	os.mkdir(lib_name)
	os.chdir(lib_name)

	if not _OPTIONS["EASTL.Config"] then
		print("EASTL.Config was not defined so will use MinSizeRel!")
	   _OPTIONS["EASTL.Config"] = "MinSizeRel"
	end

	os.execute("cmake -DCMAKE_INSTALL_PREFIX:PATH=\"" .. ember_home .. "\" \"" .. lib_src_dir .. "\"")
	os.execute("cmake --build . --target install --config " .. _OPTIONS["EASTL.Config"])

	os.chdir("..")
	os.rmdir(lib_name)
end

build()
