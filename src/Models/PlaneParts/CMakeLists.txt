set(HEDEAR_FILES Part.h)
set(SOURCE_FILES Part.cpp Wing.cpp Wing.h)

add_library(libparts STATIC ${SOURCE_FILES})
target_include_directories(libparts PUBLIC ./)

target_link_libraries(libparts Units)
target_link_libraries(libparts GLFW)


