set(UnitsHeaders Basic/ScalarUnit.h Basic/Vector.h Basic/VectorUnit.h Basic/Point.h Basic/Position.h Basic/Matrix.h Basic/MatrixUnit.h Basic/Physics.h)
set(UnitsSourceFiles Basic/Vector.cpp Basic/VectorUnit.cpp Basic/Point.cpp Basic/Matrix.cpp Basic/MatrixUnit.cpp Basic/Physics.cpp)

add_library(Units STATIC ${UnitsSourceFiles})
target_include_directories(Units PUBLIC ./)
set(ModelsHeaders Models/PhysicalModel.h Models/DummyModel.h Models/Model_6DOF.h Models/PlaneState.h Models/AtmosphereModel.cpp)
set(ModelsSourceFiles Models/PhysicalModel.cpp Models/DummyModel.cpp Models/Model_6DOF.cpp Models/AtmosphereModel.h)

set(ControllerSourceFiles PlaneController.cpp tests)
set(ControllerHearder PlaneController.h)

set(PlanesSourceFiles Plane.cpp)
set(PlanesHeaders Plane.h)

add_library(Models STATIC ${ModelsSourceFiles})
target_include_directories(Models PUBLIC . )
target_link_libraries(Models Units)

add_library(Controller STATIC ${ControllerSourceFiles})
target_include_directories(Controller PUBLIC .)
#target_link_libraries(Controller Units)
target_link_libraries(Controller glfw)
target_link_libraries(Controller glad)

add_library(Planes STATIC ${PlanesSourceFiles})
target_include_directories(Planes PUBLIC .)

add_subdirectory(Models/PlaneParts)

add_executable(main main.cpp)
target_link_libraries(main Models)
target_link_libraries(main Controller)
target_link_libraries(main Planes)
target_link_libraries(main glfw)
target_link_libraries(main glad)
target_link_libraries(main glm)




