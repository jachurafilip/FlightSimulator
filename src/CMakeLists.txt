set(HEADERS PhysicalUnit.h)
set(SOURCE_FILES PhysicalUnit.cpp)

add_library(PhysicalUnit STATIC ${SOURCE_FILES} main.cpp)
target_include_directories(PhysicalUnit PUBLIC . )

