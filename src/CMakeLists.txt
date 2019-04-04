set(HEADERS PhysicalUnit.h Vector.h VectorUnit.h Point.h)
set(SOURCE_FILES PhysicalUnit.cpp Vector.cpp VectorUnit.cpp Point.cpp)

add_library(PhysicalUnit STATIC ${SOURCE_FILES} main.cpp)
target_include_directories(PhysicalUnit PUBLIC . )

