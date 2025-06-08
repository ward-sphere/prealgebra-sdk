cmake_minimum_required(VERSION 3.26)
project(sdkmath_prealgebra)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-g -Wall)

include_directories(include)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# add_executable(integer src/Integer.cpp test/IntegerTest.cpp)
# target_link_libraries(integer gtest gtest_main)
# 
# add_executable(fraction src/Fraction.cpp test/FractionTest.cpp)
# target_link_libraries(fraction gtest gtest_main)
# 
add_executable(translator 
        src/Integer.cpp
        src/Fraction.cpp
        src/Decimal.cpp src/DefaultDecimalRepresentation.cpp 
        src/Translator.cpp src/DefaultFractionTranslator.cpp 
        test/TranslatorTest.cpp)
target_link_libraries(translator gtest gtest_main)

add_executable(decimal 
        src/Fraction.cpp
        src/Decimal.cpp src/DefaultDecimalRepresentation.cpp 
        src/Translator.cpp src/DefaultFractionTranslator.cpp 
        test/DecimalTest.cpp)
target_link_libraries(decimal gtest gtest_main)

add_executable(regex_decimal_string_parser test/RegexDecimalStringParserTest.cpp)
target_link_libraries(regex_decimal_string_parser gtest gtest_main)