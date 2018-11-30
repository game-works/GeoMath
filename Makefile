PROJECT_NAME = MathProject
BUILD = Debug

test:
	cmake --build build/${BUILD} --target install
	./bin/${BUILD}/${PROJECT_NAME}

rebuild:
	cmake -H. -Bbuild/${BUILD} -DCMAKE_BUILD_TYPE=${BUILD} -DCMAKE_INSTALL_PREFIX:PATH=`realpath bin/${BUILD}`

clean:
	rm -rf build/${BUILD}
