CC = g++
CFLAGS = -static -std=c++14 -Wall -Wextra -Werror -Weffc++ -pedantic-errors -fpermissive

main: main.cpp
	$(CC) $(CFLAGS) $@.cpp -o $@

test: main
	./main.exe

install:
	cp main.exe nginx.exe

clean:
	$(RM) *.exe
