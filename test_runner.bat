@echo off
REM CPH Test Helper Batch Script for Windows
REM This script provides easy access to common testing operations

echo.
echo ====================================
echo    CPH Test Case Helper - Windows
echo ====================================
echo.

if "%1"=="" goto show_menu
if "%1"=="help" goto show_help
if "%1"=="test" goto run_test
if "%1"=="import" goto import_cases
if "%1"=="list" goto list_cases
goto show_help

:show_menu
echo Available commands:
echo.
echo   test_runner.bat test [cpp_file] [test_file]    - Test a C++ file
echo   test_runner.bat import [json_file]             - Import test cases to CPH
echo   test_runner.bat list                           - List available test cases
echo   test_runner.bat help                           - Show this help
echo.
echo Examples:
echo   test_runner.bat test "Homework 1\Graph\1.cpp" test_cases\graph\island_perimeter.json
echo   test_runner.bat import test_cases\sorting\bubble_sort.json
echo   test_runner.bat list
goto end

:show_help
echo.
echo CPH Test Helper - Usage Guide
echo =============================
echo.
echo This tool helps you test your C++ solutions using predefined test cases.
echo.
echo Commands:
echo   test    - Run automated tests on your C++ code
echo   import  - Import test cases to CPH extension
echo   list    - Show available test case files
echo.
echo Requirements:
echo   - Python 3.x installed
echo   - g++ compiler available
echo   - CPH extension in VS Code (optional)
echo.
goto end

:run_test
if "%2"=="" (
    echo Error: Please specify both C++ file and test case file
    echo Usage: test_runner.bat test [cpp_file] [test_file]
    goto end
)
if "%3"=="" (
    echo Error: Please specify test case file
    echo Usage: test_runner.bat test [cpp_file] [test_file]
    goto end
)

echo Testing %2 with %3...
python cph_helper.py --test "%2" "%3"
goto end

:import_cases
if "%2"=="" (
    echo Error: Please specify JSON test case file to import
    echo Usage: test_runner.bat import [json_file]
    goto end
)

echo Importing test cases from %2...
python cph_helper.py --import "%2"
goto end

:list_cases
echo Listing available test case files...
python cph_helper.py --list
goto end

:end
echo.
pause
