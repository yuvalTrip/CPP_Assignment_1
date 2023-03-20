cmake_minimum_required(VERSION 3.24)
project(1Task C)

set(CMAKE_C_STANDARD 11)

add_executable(1Task book.c book.h Person.c AdptArray.c Demo.c)
