@echo off
setlocal enabledelayedexpansion
chcp 65001 >nul 2>&1

echo =======================================================================
echo          FluxSPICE: Official Sample Simulation Runner
echo =======================================================================

set CLI_BIN=
if exist "bin\fluxspice-cli.exe" (
    set "CLI_BIN=bin\fluxspice-cli.exe"
) else if exist "..\build\fluxspice-cli.exe" (
    set "CLI_BIN=..\build\fluxspice-cli.exe"
) else if exist "fluxspice-cli.exe" (
    set "CLI_BIN=fluxspice-cli.exe"
)

if "%CLI_BIN%"=="" (
    echo [ERROR] No binary found. Please compile first using cmake/ninja or scripts\release.bat.
    exit /b 1
)

echo [*] Using CLI binary: %CLI_BIN%
echo.

if not exist "sample_waveforms" mkdir sample_waveforms

echo [SAMPLE 1] Simulating ISCAS-85 c17 Benchmark (81 JJs) [Threads=1]...
%CLI_BIN% -v -t 1 -o sample_waveforms\c17_waveforms.csv circuits\c17.cir
if %errorlevel% neq 0 (
    echo [FAILED] Sample 1 c17 simulation failed!
    exit /b %errorlevel%
)
echo [+] Sample 1 PASSED.
echo.

echo [SAMPLE 2] Simulating SFQ ALU Core (102 JJs) [Threads=1]...
%CLI_BIN% -v -t 1 -o sample_waveforms\alu_waveforms.csv circuits\alu.cir
if %errorlevel% neq 0 (
    echo [FAILED] Sample 2 alu simulation failed!
    exit /b %errorlevel%
)
echo [+] Sample 2 PASSED.
echo.

echo [SAMPLE 3] Simulating Brent-Kung 4-bit Parallel Prefix Adder (198 JJs) [Threads=4]...
%CLI_BIN% -v -t 4 -o sample_waveforms\brent_kung_waveforms.csv circuits\brent_kung_4b.cir
if %errorlevel% neq 0 (
    echo [FAILED] Sample 3 brent_kung_4b simulation failed!
    exit /b %errorlevel%
)
echo [+] Sample 3 PASSED.
echo.

echo [SAMPLE 4] Simulating Synchronous Shift Register (110 JJs) [Threads=2]...
%CLI_BIN% -v -t 2 -o sample_waveforms\shift_reg_waveforms.csv circuits\shift_register_left.cir
if %errorlevel% neq 0 (
    echo [FAILED] Sample 4 shift_register_left simulation failed!
    exit /b %errorlevel%
)
echo [+] Sample 4 PASSED.
echo.

echo [SAMPLE 5] Simulating Kogge-Stone 4-bit Fast Adder (186 JJs) [Threads=8]...
%CLI_BIN% -v -t 8 -o sample_waveforms\kogge_stone_waveforms.csv circuits\kogge_stone_4b.cir
if %errorlevel% neq 0 (
    echo [FAILED] Sample 5 kogge_stone_4b simulation failed!
    exit /b %errorlevel%
)
echo [+] Sample 5 PASSED.
echo.

echo =======================================================================
echo   [SUCCESS] All 5 FluxSPICE sample simulations completed cleanly!
echo   Waveform CSV traces exported to: sample_waveforms\
echo =======================================================================
exit /b 0
