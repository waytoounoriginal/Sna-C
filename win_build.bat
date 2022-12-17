@echo off

type build-ascii-src.txt


powershell write-host "Starting Job..." -fore green

cd ./sources
powershell write-host "Building Sna-C..." -fore green

gcc snake.c engine.c main.c -o snake_win -O2 -Wall -Winit-self -Wpointer-arith -Wno-unused-function -D __windows__

if %ERRORLEVEL% NEQ 0 (
    powershell write-host "Build Failed!" -fore red
) else (
    move snake_win.exe ../

    cd ../

    powershell write-host "Building finished!" -fore green
)

pause