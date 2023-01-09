all:
	g++ -g src/*.cpp src/glad.c -lglfw -ldl -o main

