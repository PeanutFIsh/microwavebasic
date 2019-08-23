@echo off
title MicrowaveBASIC Epic Compiler

if not exist bin\ mkdir bin
echo Compiling MicrowaveBASIC for Windows...
g++ *.cpp libs\*.cpp -o .\bin\microwavebasic.exe
echo Done! Press any key to commit exit
pause>nul
