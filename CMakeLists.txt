cmake_minimum_required(VERSION 3.26)
project(sdkmath_prealgebra)

set(CMAKE_CXX_STANDARD 14)

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

add_executable(integer src/Integer.cpp test/IntegerTest.cpp)
target_link_libraries(integer gtest gtest_main)

add_executable(fraction_test include/Fraction.hpp src/Fraction.cpp test/FractionTest.cpp)
target_link_libraries(fraction_test gtest gtest_main)

add_executable(decimal_test include/Decimal.hpp src/Fraction.cpp src/Decimal.cpp test/DecimalTest.cpp)
target_link_libraries(decimal_test gtest gtest_main)