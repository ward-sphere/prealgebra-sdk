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

add_executable(number_simplifier_test include/Integer.hpp include/Fraction.hpp include/BasicNumberSimplifier.hpp
        src/Integer.cpp src/Fraction.cpp src/BasicNumberSimplifier.cpp test/INumberSimplifierTest.cpp)
target_link_libraries(number_simplifier_test gtest gtest_main)

add_executable(number_translator_test include/Integer.hpp include/Fraction.hpp include/MixedNumber.hpp include/BasicNumberTranslator.hpp
        src/Integer.cpp src/Fraction.cpp src/MixedNumber.cpp src/BasicNumberTranslator.cpp test/INumberTranslatorTest.cpp)
target_link_libraries(number_translator_test gtest gtest_main)

add_executable(negative_number_test include/Integer.hpp include/Fraction.hpp include/MixedNumber.hpp
        src/Integer.cpp src/Fraction.cpp src/MixedNumber.cpp test/NegativeNumberTest.cpp)
target_link_libraries(negative_number_test gtest gtest_main)

add_executable(addition_test include/Integer.hpp include/Fraction.hpp include/MixedNumber.hpp include/BasicNumberTranslator.hpp include/BasicNumberAddition.hpp
        src/Integer.cpp src/Fraction.cpp src/MixedNumber.cpp src/BasicNumberTranslator.cpp src/BasicNumberAddition.cpp test/INumberAdditionTest.cpp)
target_link_libraries(addition_test gtest gtest_main)