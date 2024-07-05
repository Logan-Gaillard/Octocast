.DEFAULT_GOAL := linux

builds:
	mkdir -p builds

mkb_linux:
	sudo cmake -S . -B builds/linux

mkb_windows:
	sudo cmake -S . -B builds/windows -DCMAKE_TOOLCHAIN_FILE=mingw-toolchain.cmake

linux : mkb_linux
	sudo cmake --build builds/linux

windows : mkb_windows
	sudo cmake --build builds/windows

clean:
	sudo rm -rf builds