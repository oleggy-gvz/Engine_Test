TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Interpolation/LinearInterpolation.cpp \
    Interpolation/Interpolation.cpp \
    Engine/Engine.cpp \
    Exception/Exception.cpp \
    Engine/InternalCombustionEngine.cpp \
    Environment/Environment.cpp \
    Test/Test.cpp \
    TestStand/TestStand.cpp \
    Test/OverheatingTest.cpp \
    TestStand/SearchTests.cpp \
    EngineAssembly/EngineAssembly.cpp \
    EngineAssembly/FuelEngines.cpp \
	main.cpp \
    Interpolation/CubicSplineInterpolation.cpp

HEADERS += \
    Interpolation/LinearInterpolation.h \
    Interpolation/Interpolation.h \
    Engine/Engine.h \
    Exception/Exception.h \
    Engine/InternalCombustionEngine.h \
    Environment/Environment.h \
    Test/Test.h \
    TestStand/TestStand.h \
    Test/OverheatingTest.h \
    TestStand/SearchTests.h \
    EngineAssembly/EngineAssembly.h \
    EngineAssembly/FuelEngines.h \
    Interpolation/CubicSplineInterpolation.h