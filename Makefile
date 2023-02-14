CC= g++


all:
	$(CC) -o pong main.cpp bat.cpp -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm pong
