.DEFAULT_GOAL := linux

builds:
	mkdir -p builds

mkb_linux:
	cmake -S . -B builds/linux

mkb_windows:
	cmake -S . -B builds/windows -DCMAKE_TOOLCHAIN_FILE=mingw-toolchain.cmake

mkb_switch:
	cmake -S . -B builds/switch -DCMAKE_TOOLCHAIN_FILE"=${DEVKITPRO}/cmake/Switch.cmake"

linux : mkb_linux
	sudo cmake --build builds/linux

windows : mkb_windows
	cmake --build builds/windows

switch : mkb_switch
	cmake --build builds/switch

clean:
	sudo rm -rf builds