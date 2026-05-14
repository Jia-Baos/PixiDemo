add_subdirectory(widget)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE widget)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(TARGETS widget LIBRARY DESTINATION lib)