compile := gcc -fdiagnostics-color=always -Wall -Wpedantic -std=c99 src/tests/tests.c src/libs/vector/_vector.c src/libs/util/_util.c src/libs/test/_test.c  -lm -o build/tests.out
main:
	${compile}
	./build/vec_calc.out

test:
	${compile}
	./build/tests.out --silent

verbose_test:
	${compile}
	./build/tests.out

clean:
	rm ./build/*
