rem echo off
SET program = "%1"
if %program% == "" goto err
echo invert matrix at determinate = 0
%program% determinantIsZero.txt > determinantIsZeroOutput.txt
if errorlevel 1 goto testFailed
fc /b determinantIsZeroOutput.txt standard/no_invert.txt
if errorlevel 1 goto testFailed

echo invert matrix with int value
%program% matrixIntInput.txt > matrixIntOutput.txt
if errorlevel 1 goto testFailed
fc /b matrixIntOutput.txt standard/matrixIntOutput.txt
if errorlevel 1 goto testFailed

echo invert matrix with float value
%program% matrixFloatInput.txt > matrixFloatOutput.txt
if errorlevel 1 goto testFailed
fc /b matrixFloatOutput.txt standard/matrixFloatOutput.txt
if errorlevel 1 goto testFailed

echo open empty file
%program% matrixEmpty.txt > matrixEmptyOutput.txt
if errorlevel 1 goto testFailed
fc /b matrixEmptyOutput.txt standard/matrixEmptyOutput.txt
if errorlevel 1 goto testFailed

echo invert matrix identity
%program% matrixIdentity.txt > matrixIdentityOutput.txt
if errorlevel 1 goto testFailed
fc /b matrixIdentityOutput.txt standard/matrixIdentityOutput.txt
if errorlevel 1 goto testFailed

echo matrix with symbol 
%program% matrixSymbolInput.txt > matrixSymbolOutput.txt
if errorlevel 1 goto testFailed
fc /b matrixSymbolOutput.txt standard/matrixSymbolOutput.txt
if errorlevel 1 goto testFailed

echo file size exceeds
%program% wrongSize.txt > wrongSizeOutput.txt
if errorlevel 1 goto testFailed
fc /b wrongSizeOutput.txt standard/wrongSizeOutput.txt
if errorlevel 1 goto testFailed


echo OK
exit /b

:testFailed
echo Testing failed 
pause
exit /b

:err
echo Usage: test.bat <Path to program>