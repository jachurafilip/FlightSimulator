#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Models/DummyModel.h"
#include "PlaneController.h"
#include "Scene/main2.cpp"
#include "Scene/FreeImage.h"
#include <iostream>


int main(int argc, char** argv)
{
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

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);


    init();
    glfwSetWindowRefreshCallback(window, (GLFWwindowrefreshfun)display);
    glfwSetWindowSizeCallback(window, (GLFWwindowsizefun)reshape);

    printHelp();
    bool redraw = true;

    do{
        glfwWaitEvents ();
        if(redraw)
            display();
    } while( !glfwWindowShouldClose(window) );


    cleanup();
    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);

    return 0;
    Plane f(VelocityV(1,0,0));
    DummyModel m{Position()};
    PlaneController p(&f,&m);
    p.simulate();

    return 0;
}

