add_custom_command(
    OUTPUT config_values.h
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/json_to_cpp.py ${CMAKE_CURRENT_SOURCE_DIR}/config.json ${CMAKE_CURRENT_BINARY_DIR}/config_values.h
    DEPENDS json_to_cpp.py config.json
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(MyApp main.cc ${CMAKE_CURRENT_BINARY_DIR}/config_values.h)