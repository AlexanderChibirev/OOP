rem echo off
SET program="%1"

echo perimeter and area alphabetically sort for dot
%program% "input1.txt" "result1.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b result1.txt standard/dot.txt
IF ERRORLEVEL 1 GOTO testFailed

echo perimeter and area an  alphabetically sort for lineSegment
%program% "input2.txt" "result2.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b result2.txt standard/lineSegment.txt
if ERRORLEVEL 1 goto testFailed

echo perimeter and area  alphabetically sort for rectangle
%program% "input3.txt" "result3.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b result3.txt standard/rectangle.txt
if ERRORLEVEL 1 goto testFailed

echo perimeter and area  alphabetically sort for triangle
%program% "input4.txt" "result4.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b result4.txt standard/triangle.txt
IF ERRORLEVEL 1 GOTO testFailed

echo perimeter and area  alphabetically sort for circle 
%program% "input5.txt" "result5.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b result5.txt standard/circle.txt
IF ERRORLEVEL 1 GOTO testFailed

echo perimeter and area  alphabetically sort for all shapes
%program% "input6.txt" "result6.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b result6.txt standard/allShapes.txt
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