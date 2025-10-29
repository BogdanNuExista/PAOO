cmake_minimum_required(VERSION 3.10)
project(DynamicArrayDemo VERSION 1.0)

# Setăm standardul C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Includem directorul cu header-ele
include_directories(include)

# Adăugăm subdirectorul src
add_subdirectory(src)
