test:
	gcc -fdiagnostics-color=always -Wall -Wpedantic -std=c99 src/tests/tests.c src/libs/vector/_vector.c src/libs/util/_util.c src/libs/test/_test.c  -lm -o build/tests.out
	./build/tests.out --silent

verbose_test:
	gcc -fdiagnostics-color=always -Wall -Wpedantic -std=c99 src/tests/tests.c src/libs/vector/_vector.c src/libs/util/_util.c src/libs/test/_test.c  -lm -o build/tests.out
	./build/tests.out

main:
	gcc -fdiagnostics-color=always -Wall -Wpedantic -std=c99 src/vec_calc.c src/libs/vector/_vector.c src/libs/util/_util.c src/libs/test/_test.c  -lm -o build/vec_calc.out
	./build/vec_calc.out

clean:
	rm ./build/*