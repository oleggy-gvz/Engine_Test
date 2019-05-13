TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

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
    EngineAssembly/FuelEngines.h