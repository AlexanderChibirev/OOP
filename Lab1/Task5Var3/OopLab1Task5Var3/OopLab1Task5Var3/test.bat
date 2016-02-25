echo off
SET program="%1"
echo check on empty file
OopLab1Task5Var3.exe empty.txt outputEmpty.txt > outputEmpty.txt
if not errorlevel 1 goto testFailed
fc /b outputEmpty.txt standard/Empty.txt
if errorlevel 1 goto testFailed

echo to fill normal file
OopLab1Task5Var3.exe fill.txt outputNormalFile.txt
if errorlevel 1 goto testFailed
fc /b outputNormalFile.txt standard/NormalFile.txt
if errorlevel 1 goto testFailed

echo check invalid symbol
OopLab1Task5Var3.exe invalidSymbol.txt out3.txt > outputInvalidSymbol.txt
if not errorlevel 1 goto testFailed
fc /b outputInvalidSymbol.txt standard/InvalidSymbol.txt
if errorlevel 1 goto testFailed

echo fill with one point
OopLab1Task5Var3.exe fillWithOnePoint.txt outputOnePoint.txt
if errorlevel 1 goto testFailed
fc /b outputOnePoint.txt standard/OnePoint.txt
if errorlevel 1 goto testFailed

echo fill big array
OopLab1Task5Var3.exe fillBigArray.txt outputFillBigArray.txt
if errorlevel 1 goto testFailed
fc /b outputFillBigArray.txt standard/FillBigArray.txt
if errorlevel 1 goto testFailed

echo errorWithOpeningInputFile
OopLab1Task5Var3.exe qwesdasdqw.txt outputEmpty.txt > errorWithOpeningInputFile.txt
if not errorlevel 1 goto testFailed
fc /b errorWithOpeningInputFile.txt standard/errorWithOpeningInputFile.txt
if errorlevel 1 goto testFailed

echo OK
pause
exit /b

:testFailed
echo Testing failed
pause
exit /b
