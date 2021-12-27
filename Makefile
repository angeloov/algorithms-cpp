all: build execute

build:
	@g++ $(file) -fsanitize=address -lasan -std=c++11

execute:
	@./a.out