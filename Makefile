PROJECT_NAME = MathProject
BUILD = Release

test:
	cmake --build build/${BUILD} --target install
	./bin/${BUILD}/${PROJECT_NAME}

rebuild:
	cmake -H. -Bbuild/${BUILD} -DCMAKE_BUILD_TYPE=${BUILD} -DCMAKE_INSTALL_PREFIX:PATH=`realpath bin/${BUILD}`
	cp build/${BUILD}/compile_commands.json build/

clean:
	rm -rf build/${BUILD}
