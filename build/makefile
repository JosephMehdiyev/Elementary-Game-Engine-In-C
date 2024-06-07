build:
	gcc  -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith  -Wno-missing-braces -Wno-missing-field-initializers -Werror  -Wlogical-op \
	-Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -Wcast-qual  -Wswitch-enum \
	-Wconversion -Wunreachable-code -Wformat=2 ../src/main.c ../src/glad.c ../src/stb_image.c ../src/shader.c ../src/texture.c ../src/glfw.c -lglfw -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl -o main

builde:
	gcc  -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith  -Wno-missing-braces -Wno-missing-field-initializers  -Wlogical-op \
	-Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -Wcast-qual  -Wswitch-enum \
	-Wconversion -Wunreachable-code -Wformat=2 ../src/main.c ../src/glad.c ../src/stb_image.c ../src/shader.c ../src/texture.c ../src/glfw.c -lglfw -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl -o main

run:
	./main

prime-run:
	prime-run ./main
	
all:
	make build && make run

alle:
	make builde && make run
clean:
	rm main	