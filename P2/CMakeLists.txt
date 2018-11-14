cmake_minimum_required(VERSION 3.9)
project(P2)

set(CMAKE_CXX_STANDARD 11)

add_executable(P2
        P2/.idea/codeStyles/Project.xml
        P2/.idea/2DFourier.iml
        P2/.idea/misc.xml
        P2/.idea/modules.xml
        P2/.idea/workspace.xml
        P2/CMakeLists.txt
        P2/Complex.cc
        P2/Complex.h
        P2/fft2d.cc
        P2/InputImage.cc
        P2/InputImage.h)
