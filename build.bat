@echo off
g++ -static -std=c++11 -Wall -Wextra -Werror -Weffc++ -pedantic-errors -fpermissive main.cpp -o nginx.exe
pause
@echo on