PROJECT_NAME = MathProject
BUILD = Release

test:
	./bin/${BUILD}/${PROJECT_NAME}

compile:
	cmake --build build/${BUILD} --target install

rebuild:
	cmake -H. -Bbuild/${BUILD} -DCMAKE_BUILD_TYPE=${BUILD} -DCMAKE_INSTALL_PREFIX:PATH=`realpath bin/${BUILD}`
	cp build/${BUILD}/compile_commands.json build/

clean:
	rm build/compile_commands.json
	rm -rf build/${BUILD}
