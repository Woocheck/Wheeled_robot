cmake_minimum_required (VERSION 2.6)
project (Linefollower)

#add_subdirectory(dcMotor)
#add_subdirectory(encoder)
#add_subdirectory(lineDetector)
#add_subdirectory(positionAnalyser)
#add_subdirectory(regulatorPD)
#add_subdirectory(wheelDrive)

add_executable( main main.cpp dcMotor/DCmotor.cpp encoder/encoder.cpp lineDetector/detector.cpp positionAnalyser/positionAnalyser.cpp regulatorPD/regulatorPD.cpp wheelDrive/twoWheelDrive.cpp )
