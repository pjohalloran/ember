#!/bin/sh

ASTYLE_CONFIG_FILE=""

function should_style_file {
	file_exts=( '.h' '.c' '.cpp' )
	filename=$(basename "$1")
	extension="${filename##*.}"
	filename="${filename%.*}"

	for i in "${file_exts[@]}"; do
		if [ ".$extension" == "$i" ]; then
			#echo "$1 is valid"
			return 0
		fi
	done

	return 1
}

function style_files {
	if [ ! -d $1 ]; then
		should_style_file $file
		if [ $? -eq 0 ]; then
			astyle $file --options=${ASTYLE_CONFIG_FILE} -n
		fi
	elif [ -d $1 ]; then
		for file in $1/*; do
			style_files $file
		done
	fi
}

curr_dir=`pwd`
ASTYLE_CONFIG_FILE="$curr_dir/build_scripts/astyle.conf"
tmp="$curr_dir/src"
style_files $tmp
