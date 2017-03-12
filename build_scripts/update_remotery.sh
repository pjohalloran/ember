#!/bin/sh

git submodule update --init --recursive

if [ $? -ne 0 ]; then
	echo "[FAILED] To update Remotery submodule."
	return 1
fi

cp "tools/Remotery/lib/*" "src/Remotery/"

if [ $? -ne 0 ]; then
	echo "[FAILED] To copy files inside the src directory"
	return 1
fi

echo "[SUCCESS]"