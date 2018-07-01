cmake_minimum_required (VERSION 3.11)
project(smbus_analyzer)

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

add_library(smbus_analyzer SHARED ${SOURCES})
target_link_libraries(smbus_analyzer PRIVATE Saleae::AnalyzerSDK)

if(MSVC)
    install(TARGETS smbus_analyzer RUNTIME DESTINATION ".")
else()
    install(TARGETS smbus_analyzer LIBRARY DESTINATION ".")
endif()
