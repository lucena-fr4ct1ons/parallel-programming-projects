cmake_minimum_required (VERSION 2.8)

file( GLOB sourceFiles
	${CMAKE_SOURCE_DIR}/GlobalSources/*.cpp
	${CMAKE_SOURCE_DIR}/GlobalSources/*.c
)

# Add source to this project's executable.
add_executable (MatMult_PRLL "main_prll.cpp"  ${sourceFiles})
add_executable (MatMult_SRL "main_srl.cpp"  ${sourceFiles})

#set_property(TARGET MatMult_SRL PROPERTY CXX_STANDARD 99)
#set_property(TARGET MatMult_PRLL PROPERTY CXX_STANDARD 99)

# TODO: Add tests and install targets if needed.
#target_link_libraries(TestingProject PRIVATE mpi)

message(DIR\ 1234\ IS:\ ${CMAKE_SOURCE_DIR})

#include_directories(${CMAKE_SOURCE_DIR}/GlobalIncludes)

target_link_libraries(MatMult_PRLL pthread)
target_link_libraries(MatMult_PRLL rt)
target_include_directories(MatMult_PRLL PUBLIC ${CMAKE_SOURCE_DIR}/GlobalIncludes)

target_link_libraries(MatMult_SRL pthread)
target_include_directories(MatMult_SRL PUBLIC ${CMAKE_SOURCE_DIR}/GlobalIncludes)

#target_include_directories(TestingProject_SRL PUBLIC ${CMAKE_SOURCE_DIR}/GlobalIncludes)

#link_directories(${CMAKE_SOURCE_DIR}/GlobalSources)