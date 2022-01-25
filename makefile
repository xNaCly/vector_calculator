run_tests:
	gcc -fdiagnostics-color=always -Wall -Wpedantic -std=c99 src/tests/test.c src/libs/vector/_vector.c src/libs/util/_util.c src/libs/test/_test.c  -lm -o build/test.out
	./build/test.out

main:
	gcc -fdiagnostics-color=always -Wall -Wpedantic -std=c99 src/vec_calc.c src/libs/vector/_vector.c src/libs/util/_util.c src/libs/test/_test.c  -lm -o build/main.out
	./build/main.out