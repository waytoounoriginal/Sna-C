@echo off

type build-ascii-src.txt


powershell write-host "Starting Job..." -fore green

cd ./sources
powershell write-host "Building Sna-C..." -fore green


::  Still have to figure out what flags to use for linux
gcc snake.c engine.c main.c -o snake_linux -I C:\msys64\mingw64\include\ncurses -lncurses -L/mingw64/bin -O2 -Wall -Winit-self -Wpointer-arith -Wno-unused-function -D __unix__

if %ERRORLEVEL% NEQ 0 (
    powershell write-host "Build Failed!" -fore red
) else (
    move snake_linux.exe ../

    cd ../

    powershell write-host "Building finished!" -fore green
)

pause