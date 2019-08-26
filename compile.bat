@echo off
title MicrowaveBASIC Epic Compiler

if not exist bin\ (
    echo bin/ folder not detected! Creating directory...
    mkdir bin
)
if not exist bin\programs\ (
    echo bin/programs/ folder not detected! Creating directory...
    mkdir bin\programs
)

echo !!! It is recommended to not compile
echo !!! the software yourself and use the
echo !!! pre-built binary instead.
echo.
echo Compiling MicrowaveBASIC for Windows...
g++ *.cpp libs\*.cpp -o .\bin\microwavebasic.exe
echo Done! Press any key to commit exit
pause>nul
