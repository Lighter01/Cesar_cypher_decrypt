cmake_minimum_required(VERSION 3.5)

project(decryptor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(decryptor main.cpp ceaser_chipher_decryption.h ceaser_chipher_decryption.cpp run_decryptor.h run_decryptor.cpp)

file(COPY ${PROJECT_SOURCE_DIR}/data DESTINATION ${PROJECT_BINARY_DIR})

install(TARGETS decryptor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
