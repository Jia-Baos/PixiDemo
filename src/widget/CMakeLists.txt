file(GLOB WIDGET_SRC *.cpp)
add_library(widget SHARED ${WIDGET_SRC})
target_include_directories(widget PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS widget RUNTIME DESTINATION bin)