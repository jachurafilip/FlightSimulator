set(UnitsHeaders ScalarUnit.h Vector.h VectorUnit.h Point.h Position.h)
set(UnitsSourceFiles ScalarUnit.cpp Vector.cpp VectorUnit.cpp Point.cpp)

add_library(Units STATIC ${UnitsSourceFiles})
target_include_directories(Units PUBLIC ./)
