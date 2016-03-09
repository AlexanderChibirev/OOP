echo off
SET program="%1"
echo translate whithout arguments
%program%
if not errorlevel 1 goto testFailed

echo translate from 16 to 10 value FF
%program% "16" "10" "FF" > 16_10_FF.txt
if errorlevel 1 goto testFailed
fc /b 16_10_FF.txt standard/16_10_FF.txt
if errorlevel 1 goto testFailed

echo translate from 15 to 3 value 34AB3
%program% "15" "3" "34AB3" > 15_3_34AB3.txt
if errorlevel 1 goto testFailed
fc /b 15_3_34AB3.txt standard/15_3_34AB3.txt
if errorlevel 1 goto testFailed

echo translate from 20 to 2 value -642
%program% "20" "2" "-642" > 20_2_-642.txt
if errorlevel 1 goto testFailed
fc /b 20_2_-642.txt standard/20_2_-642.txt
if errorlevel 1 goto testFailed

echo translate from 16 to 10 value 0
%program% "16" "10" "0" > 16_10_0.txt
if errorlevel 1 goto testFailed
fc /b 16_10_0.txt standard/16_10_0.txt
if errorlevel 1 goto testFailed

echo translate from 1 to 37 value 0
%program% "1" "37" "0" > 1_37_0.txt
if not errorlevel 1 goto testFailed
fc /b 1_37_0.txt standard/1_37_0.txt
if errorlevel 1 goto testFailed

echo translate from 15 to 2 value FF
%program% "1" "37" "0" > 15_2_FF.txt
if not errorlevel 1 goto testFailed
fc /b 15_2_FF.txt standard/15_2_FF.txt
if errorlevel 1 goto testFailed

echo translate from 16 to 10 value -800000000
%program% "16" "10" "-800000000" > 16_10_-800000000.txt
if errorlevel 1 goto testFailed
fc /b 16_10_-800000000.txt standard/16_10_-800000000.txt
if errorlevel 1 goto testFailed


echo OK
pause
exit /b

:testFailed
ECHO Testing failed
pause
exit /b