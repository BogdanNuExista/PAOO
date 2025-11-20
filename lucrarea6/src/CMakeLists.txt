add_executable(lucrarea6_demo 
    main.cpp
    FileHandler.cpp
    ResourceManagers.cpp
)

target_include_directories(lucrarea6_demo PRIVATE ${CMAKE_SOURCE_DIR}/include)
