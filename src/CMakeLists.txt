set(ModelsHeaders Models/PhysicalModel.h Models/DummyModel.h Models/Model_6DOF.h Models/PlaneState.h)
set(ModelsSourceFiles Models/PhysicalModel.cpp Models/DummyModel.cpp Models/Model_6DOF.cpp)

set(ControllerSourceFiles PlaneController.cpp tests)
set(ControllerHearder PlaneController.h)

set(PlanesSourceFiles Plane.cpp)
set(PlanesHeaders Plane.h)

add_library(Models STATIC ${ModelsSourceFiles})
target_include_directories(Models PUBLIC . )

add_library(Controller STATIC ${ControllerSourceFiles})
target_include_directories(Controller PUBLIC .)
target_link_libraries(Controller Units)
target_link_libraries(Controller glfw)
target_link_libraries(Controller glad)

add_library(Planes STATIC ${PlanesSourceFiles})
target_include_directories(Planes PUBLIC .)

add_subdirectory(Models/PlaneParts)
add_subdirectory(Basic)

add_executable(main main.cpp)
target_link_libraries(main Models)
target_link_libraries(main Controller)
target_link_libraries(main Planes)
target_link_libraries(main glfw)
target_link_libraries(main glad)
target_link_libraries(main glm)




