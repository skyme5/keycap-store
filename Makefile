CC = g++
CFLAGS = -static -std=c++14 -Wall -Wextra -Werror -Weffc++ -pedantic-errors -fpermissive

build: keycap.cpp
	$(CC) $(CFLAGS) $@.cpp -o dist/$@

run: build
	dist/keycap.exe

install:
	cp dist/keycap.exe nginx.exe

clean:
	$(RM) -rf *.exe
