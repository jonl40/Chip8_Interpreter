INCLUDES = -I ./include
FLAGS = -g
OBJECTS = ./build/chip8memory.o ./build/chip8.o  ./build/hashtable.o ./build/chip8keyboard.o
all: ${OBJECTS}
	gcc ${FLAGS} ${INCLUDES} ./src/main.c ${OBJECTS} -L ./lib -lmingw32 -lSDL2main -lSDL2 -o ./bin/main

./build/chip8memory.o:src/chip8memory.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8memory.c -c -o ./build/chip8memory.o

./build/chip8.o:src/chip8.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8.c -c -o ./build/chip8.o

./build/hashtable.o:src/hashtable.c
	gcc ${FLAGS} ${INCLUDES} ./src/hashtable.c -c -o ./build/hashtable.o

./build/chip8keyboard.o:src/chip8keyboard.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8keyboard.c -c -o ./build/chip8keyboard.o


clean:
	del build\*