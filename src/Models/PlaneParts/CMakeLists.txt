set(HEDEAR_FILES Part.h Engine.h Wing.h)
set(SOURCE_FILES Part.cpp Wing.cpp Engine.cpp)

add_library(libparts STATIC ${SOURCE_FILES})
target_include_directories(libparts PUBLIC ./)

target_link_libraries(libparts Units)
target_link_libraries(libparts GLFW)


