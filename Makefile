PROJECT_NAME = MathProject
BUILD = Release

test:
	./bin/${BUILD}/${PROJECT_NAME}

compile:
	cmake --build build/${BUILD} --target install

rebuild:
	cmake -H. -Bbuild/${BUILD} -DCMAKE_BUILD_TYPE=${BUILD} -DCMAKE_INSTALL_PREFIX:PATH=`realpath bin/${BUILD}`

clean:
	rm -rf build/${BUILD}
