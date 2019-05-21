TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ../EngineTest/Interpolation/CubicSplineInterpolation.cpp \
    ../EngineTest/Interpolation/Interpolation.cpp \
    ../EngineTest/Interpolation/LinearInterpolation.cpp \
    ../EngineTest/Exception/Exception.cpp

HEADERS += \
    ../EngineTest/Interpolation/CubicSplineInterpolation.h \
    ../EngineTest/Interpolation/Interpolation.h \
    ../EngineTest/Interpolation/LinearInterpolation.h \
    ../EngineTest/Exception/Exception.h
