#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Models/DummyModel.h"
#include "PlaneController.h"
#include "Scene/main2.cpp"
#include "Scene/FreeImage.h"
#include <iostream>


int main(int argc, char** argv)
{

    Plane p;
    DummyModel m;

    PlaneController pc(&p,&m);
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(640, 480, "Simulation", nullptr, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetWindowRefreshCallback(window, display);
    glfwSetWindowSizeCallback(window, reshape);

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);

    init();

    printHelp();

    do{
        glfwPollEvents();
        display(window);
        pc.simulate();
        roll((m.getCurrentPosition().angles.roll-m.getPreviousPosition().angles.roll)*M_PI/180);
        pitch((m.getCurrentPosition().angles.pitch-m.getPreviousPosition().angles.pitch)*M_PI/180);
        yaw((m.getCurrentPosition().angles.yaw-m.getPreviousPosition().angles.yaw)*M_PI/180);
        glfwSwapBuffers(window);
    } while( !glfwWindowShouldClose(window) );


    cleanup();
    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);

}

