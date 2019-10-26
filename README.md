* Introduction

Keycap is a simple keystroke logger for Windows XP or newer Windows desktop and 
server operating systems. It logs the key pressed, the date and time of the 
press and the active window. It is intended solely for educational purposes.  
Keycap is meant to demonstrate one approach to software based keyboard API 
logging. Keycap does not require system wide kernel hooks or other low-level 
integration. It can be executed by normal users. 

Video games pause when a player presses the 'P' key because the game software 
is monitoring the state of that key. When the key is pressed, the game knows to 
pause and wait until some other action occurs (typically another key press). 
That's basically how Keycap works, except the concept of monitoring a key's 
state is applied to the entire keyboard, not just a few keys.  

* Compiling

Keycap is written in C++11 and uses a few Windows specific functions and types. 
Any modern C++11 compiler that targets Windows should be able to build it. See 
'build.sh' for compiler settings used with MinGW (g++). If you prefer to use 
MSVC++, download the free Visual Studio Community Edition, create an empty 
Win32 Console Application project and add the Keycap files (one source, one 
header) to the project, then build.

* Character Notes

The '|' character is used to separate fields in the output so that character is 
logged as the word 'pipe' rather than the character itself. Some Window titles 
may include the '|' character. Window titles are enclosed in quotations, 
however, additional '|' characters may cause parsing/rendering issues with 
certain csv parsing programs. If you record keystrokes to a file 'Keycap.exe > 
log.csv', be prepared to handle those issues. 

Keycap does not log all characters/keys on a typical U.S. QWERTY keyboard. See 
if you can figure out what keys are missing and add them to the source, or 
modify the code to work with different keyboards and languages.

* MSDN Types & Keyboard API Notes

short - Holds signed 16-bit (2-byte) integers that range in value from -32,768 
through 32,767.
GetAsyncKeyState - returns a short.
HWND  - handle to a window.

When GetAsyncKeyState returns, if the most significant bit is set, the key is 
down, and if the least significant bit is set, the key was pressed after the 
previous call to GetAsyncKeyState. (-32768 : 1000000000000000) (-32767 : 
1000000000000001)

In 'main.hpp' some keys use constant names such as 'VK_TAB' or 'VK_RETURN' 
while other use the decimal (57) or hex (0x39) representation for keys. If you 
add keys, experiment with which form is accepted on your system. Some systems 
will take any form while others may only take one.

* Conclusion

Remember that Keycap is meant solely for educational purposes and 
demonstration. It could be written very differently. The code is meant to be 
explicit and obvious so that it can be easily understood and modified.
