rem echo off
SET program="%1"
if %program% == "" goto err
%program% > wrongAmountOfArguments.txt
IF NOT ERRORLEVEL 1 GOTO testFailed
fc /b wrongAmountOfArguments.txt standard/wrongAmountOfArguments.txt
IF ERRORLEVEL 1 GOTO testFailed

echo empty search string
%program% "input.txt" "output1.txt" "" "REPLACE"
IF ERRORLEVEL 1 GOTO testFailed
fc /b output1.txt standard/emptySearch.txt
IF ERRORLEVEL 1 GOTO testFailed

echo replace ma on mama
%program% "input.txt" "output2.txt" "ma" "Mama"
IF ERRORLEVEL 1 GOTO testFailed
fc /b output2.txt standard/maOnMama.txt
if ERRORLEVEL 1 goto testFailed

echo replace 1231234
%program% input.txt output3.txt 1231234 true 
IF ERRORLEVEL 1 GOTO testFailed
fc /b output2.txt standard/1231234.txt
if ERRORLEVEL 1 goto testFailed

echo empty replace string
%program% "input.txt" "output4.txt" "search" "" 
IF ERRORLEVEL 1 GOTO testFailed
fc /b output4.txt standard/emptyReplace.txt
IF ERRORLEVEL 1 GOTO testFailed

echo OK
pause 
exit /B

:testFailed
ECHO Testing failed
pause
exit /B

:err
echo Usage: test.bat <Path to %program%>

pause