set(GTEST_LIBS gtest gtest_main gmock gmock_main)

include_directories(lib/gtest/googletest/include)
include_directories(lib/gtest/googlemock/include)

add_executable(ScalarUnitsTests ScalarUnitsTests.cpp)
target_link_libraries(ScalarUnitsTests ${GTEST_LIBS})
target_link_libraries(ScalarUnitsTests Units)

add_executable(VectorUnitsTests VectorUnitsTests.cpp)
target_link_libraries(VectorUnitsTests ${GTEST_LIBS})
target_link_libraries(VectorUnitsTests Units)
