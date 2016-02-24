rem echo off
SET program="%1"
if %program% == "" goto err
OopLab1Task1Var4.exe > wrongAmountOfArguments.txt
IF NOT ERRORLEVEL 1 GOTO testFailed
fc /b wrongAmountOfArguments.txt standard/wrongAmountOfArguments.txt
IF ERRORLEVEL 1 GOTO testFailed

echo empty search string
OopLab1Task1Var4.exe "input.txt" "output1.txt" "" "REPLACE"
IF ERRORLEVEL 1 GOTO testFailed
fc /b output1.txt checkOutput/emptySearch.txt
IF ERRORLEVEL 1 GOTO testFailed

echo replace ma on mama
OopLab1Task1Var4.exe "input.txt" "output2.txt" "ma" "Mama"
IF ERRORLEVEL 1 GOTO testFailed
fc /b output2.txt checkOutput/maOnMama.txt
if ERRORLEVEL 1 goto testFailed

echo replace 1231234
OopLab1Task1Var4.exe input.txt output3.txt 1231234 true 
IF ERRORLEVEL 1 GOTO testFailed
fc /b output2.txt checkOutput/1231234.txt
if ERRORLEVEL 1 goto testFailed

echo empty replace string
OopLab1Task1Var4.exe "input.txt" "output4.txt" "search" "" 
IF ERRORLEVEL 1 GOTO testFailed
fc /b output4.txt checkOutput/emptyReplace.txt
IF ERRORLEVEL 1 GOTO testFailed

echo OK
exit /B

:testFailed
ECHO Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>