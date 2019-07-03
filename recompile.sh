#!/bin/sh

g++ main.cpp ./wheelDrive/twoWheelDrive.cpp ./dcMotor/DCmotor.cpp ./encoder/encoder.cpp ./regulatorPD/regulatorPD.cpp positionAnalyser/positionAnalyser.cpp lineDetector/detector.cpp -o main -std=c++17 -lwiringPi -lpthread
