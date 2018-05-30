@echo off
mkdir _build2
cd _build2
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat" 

C:\prog\CMake\bin\cmake.exe -TLLVM-vs2014 ../
