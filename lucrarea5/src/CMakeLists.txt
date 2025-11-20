add_executable(lucrarea5_demo 
    main.cpp
    Number.cpp
    SafeString.cpp
    Student.cpp
)

target_include_directories(lucrarea5_demo PRIVATE ${CMAKE_SOURCE_DIR}/include)
