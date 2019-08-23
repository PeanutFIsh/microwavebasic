@echo off
title MicrowaveBASIC Epic Compiler
echo Compiling MicrowaveBASIC for Windows...
g++ *.cpp libs\*.cpp -o .\bin\microwavebasic.exe
echo Done! Press any key to commit exit
pause>nul