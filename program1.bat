
@echo off
cls

g++ -I.\CSC2110 -c SortedListArrayDriver.cpp

g++ -L.\CSC2110 -o program1.exe SortedListArrayDriver.o -lCSC2110
  