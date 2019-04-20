set(UnitsHeaders Basic/ScalarUnit.h Basic/Vector.h Basic/VectorUnit.h Basic/Point.h Basic/Position.h)
set(UnitsSourceFiles Basic/ScalarUnit.cpp Basic/Vector.cpp Basic/VectorUnit.cpp Basic/Point.cpp)

set(ModelsHeaders Models/PhysicalModel.h Models/DummyModel.h)
set(ModelsSourceFiles Models/PhysicalModel.cpp Models/DummyModel.cpp)

set(ControllerSourceFiles PlaneController.cpp)
set(ControllerHearder PlaneController.h)

set(PlanesSourceFiles Plane.cpp)
set(PlanesHeaders Plane.h)
add_library(Units STATIC ${UnitsSourceFiles})
target_include_directories(Units PUBLIC . )

add_library(Models STATIC ${ModelsSourceFiles})
target_include_directories(Models PUBLIC . )

add_library(Controller STATIC ${ControllerSourceFiles})
target_include_directories(Controller PUBLIC .)
target_link_libraries(Controller Units)

add_library(Planes STATIC ${PlanesSourceFiles})
target_include_directories(Planes PUBLIC .)


add_executable(main main.cpp)
target_link_libraries(main Models)
target_link_libraries(main Controller)
target_link_libraries(main Planes)


