CC = g++
CFLAGS = -static -std=c++14 -Wall -Wextra -Werror -Weffc++ -pedantic-errors -fpermissive

build: main.cpp
	$(CC) $(CFLAGS) $@.cpp -o dist/$@

run: main
	dist/main.exe

install:
	cp dist/main.exe nginx.exe

clean:
	$(RM) *.exe
