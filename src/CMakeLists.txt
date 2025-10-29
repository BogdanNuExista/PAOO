# Adăugăm fișierele sursă
add_executable(dynamic_array_demo 
    main.cpp
    DynamicArray.cpp
)

# Linkăm include directory
target_include_directories(dynamic_array_demo PRIVATE ${PROJECT_SOURCE_DIR}/include)
