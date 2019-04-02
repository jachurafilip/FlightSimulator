set(GTEST_LIBS gtest gtest_main gmock gmock_main)

include_directories(lib/gtest/googletest/include)
include_directories(lib/gtest/googlemock/include)

add_executable(PhysicalUnitsTests PhysicalUnitsTests.cpp)
target_link_libraries(PhysicalUnitsTests ${GTEST_LIBS})
target_link_libraries(PhysicalUnitsTests PhysicalUnit)