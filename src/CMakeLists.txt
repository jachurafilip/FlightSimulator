set(UnitsHeaders Basic/ScalarUnit.h Basic/Vector.h Basic/VectorUnit.h Basic/Point.h Basic/Position.h)
set(UnitsSourceFiles Basic/ScalarUnit.cpp Basic/Vector.cpp Basic/VectorUnit.cpp Basic/Point.cpp)

set(ModelsHeaders Models/PhysicalModel.h Models/DummyModel.h Models/Model_6DOF.h)
set(ModelsSourceFiles Models/PhysicalModel.cpp Models/DummyModel.cpp Models/Model_6DOF.cpp)

set(ControllerSourceFiles PlaneController.cpp tests)
set(ControllerHearder PlaneController.h)

set(PlanesSourceFiles Plane.cpp)
set(PlanesHeaders Plane.h linmath.h)

set(SceneSourceFiles Scene/Geometry.cpp Scene/shaders.cpp Scene/Transform.cpp Scene/grader.cpp Scene/Scene.cpp Scene/FixObj.cpp)
set(SceneHearder Scene/Geometry.h Scene/shaders.h Scene/Transform.h Scene/grader.h Scene/FreeImage.h)

add_library(Scene STATIC ${SceneSourceFiles})
target_include_directories(Scene PUBLIC . )

target_link_libraries(Scene Units)
target_link_libraries(Scene glfw)
target_link_libraries(Scene glad)
target_link_libraries(Scene glm)

add_library(Units STATIC ${UnitsSourceFiles})
target_include_directories(Units PUBLIC . )

add_library(Models STATIC ${ModelsSourceFiles})
target_include_directories(Models PUBLIC . )

add_library(Controller STATIC ${ControllerSourceFiles})
target_include_directories(Controller PUBLIC .)

target_link_libraries(Controller Units)
target_link_libraries(Controller glfw)
target_link_libraries(Controller glad)

add_library(Planes STATIC ${PlanesSourceFiles})
target_include_directories(Planes PUBLIC .)

add_executable(main main.cpp)
target_link_libraries(main Scene)
target_link_libraries(main Models)
target_link_libraries(main Controller)
target_link_libraries(main Planes)
target_link_libraries(main glfw)
target_link_libraries(main glad)
target_link_libraries(main glm)



