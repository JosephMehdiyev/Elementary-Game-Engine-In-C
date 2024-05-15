build:
	gcc -pedantic -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith  -Wno-missing-braces -Wno-missing-field-initializers -Werror  -Wlogical-op \
	-Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -Wcast-qual  -Wswitch-enum \
	-Wconversion -Wunreachable-code -Wformat=2 ../src/main.c -lSDL2 -lSDL2main -o main

run:
	./main

clean:
	rm main