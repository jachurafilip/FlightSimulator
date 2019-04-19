set(GTEST_LIBS gtest gtest_main gmock gmock_main)

include_directories(lib/gtest/googletest/include)
include_directories(lib/gtest/googlemock/include)

add_executable(ScalarUnitsTests ScalarUnitsTests.cpp)
target_link_libraries(ScalarUnitsTests ${GTEST_LIBS})
target_link_libraries(ScalarUnitsTests Units)

add_executable(VectorUnitsTests VectorUnitsTests.cpp)
target_link_libraries(VectorUnitsTests ${GTEST_LIBS})
target_link_libraries(VectorUnitsTests Units)

add_executable(DummyModelTests DummyModelTests.cpp)
target_link_libraries(DummyModelTests ${GTEST_LIBS})
target_link_libraries(DummyModelTests Units)
target_link_libraries(DummyModelTests Models)
target_link_libraries(DummyModelTests Controller)
target_link_libraries(DummyModelTests Planes)