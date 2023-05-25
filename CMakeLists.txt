cmake_minimum_required (VERSION 3.11)
project(smbus_analyzer)

add_definitions( -DLOGIC2 )

set(CMAKE_OSX_DEPLOYMENT_TARGET "10.14" CACHE STRING "Minimum supported MacOS version" FORCE)

# enable generation of compile_commands.json, helpful for IDEs to locate include files.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# custom CMake Modules are located in the cmake directory.
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(ExternalAnalyzerSDK)

set(SOURCES 
src/SMBusAnalyzer.cpp
src/SMBusAnalyzer.h
src/SMBusAnalyzerResults.cpp
src/SMBusAnalyzerResults.h
src/SMBusAnalyzerSettings.cpp
src/SMBusAnalyzerSettings.h
src/SMBusCommands.cpp
src/SMBusCommands.h
src/SMBusSimulationDataGenerator.cpp
src/SMBusSimulationDataGenerator.h
src/SMBusTypes.cpp
src/SMBusTypes.h
)

add_analyzer_plugin(smbus_analyzer SOURCES ${SOURCES})
