test:
	./bin/app

compile:
	cmake --build build --target install

rebuild: clean
	cmake -H. -Bbuild -DCMAKE_INSTALL_PREFIX:PATH=`realpath bin`

clean:
	rm -rf build
