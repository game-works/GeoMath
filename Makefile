release: rebuild-release
	cmake --build build/release --target install --config Release
	./build/release/MathProject

debug: rebuild-debug
	cmake --build build/debug --target install --config Debug
	./build/debug/MathProject

rebuild-release:
	cmake -H. -Bbuild/release -DCMAKE_INSTALL_PREFIX:PATH=`realpath bin`

rebuild-debug:
	cmake -H. -Bbuild/debug -DCMAKE_INSTALL_PREFIX:PATH=`realpath bin`

clean-release:
	rm -rf build/release

clean-debug:
	rm -rf build/debug
