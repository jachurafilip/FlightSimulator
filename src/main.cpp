#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Models/DummyModel.h"
#include "PlaneController.h"
#include "Scene/main2.cpp"
#include "Scene/FixObj.cpp"
#include "Scene/Scene.cpp"
#include "Scene/FreeImage.h"
#include <iostream>

Plane p;
DummyModel m;

PlaneController pc(&p,&m);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_REPEAT || action == GLFW_PRESS)
    {


        switch(key) {
            case GLFW_KEY_ESCAPE:
                cout << "ESC";
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                break;
            case GLFW_KEY_RIGHT_BRACKET:
                amount++;
                std::cout << "amount set to " << amount << "\n";
                break;
            case GLFW_KEY_LEFT_BRACKET:
                amount--;
                std::cout << "amount set to " << amount << "\n";
                break;
            case GLFW_KEY_I:
                pc.throttle(amount);
                break;
            case GLFW_KEY_O:
                pc.throttle(-amount);
                break;
            case GLFW_KEY_H:
                printHelp();
                break;
            case GLFW_KEY_LEFT: //left
                cameraLeft(amount,eye,up);
                break;
            case GLFW_KEY_UP: //up
                pc.moveElevators(-amount);
                break;
            case GLFW_KEY_RIGHT: //right
                cameraLeft(-amount,eye,up);
                break;
            case GLFW_KEY_DOWN: //down
                pc.moveElevators(amount);
                break;
            default:
                break;
        }
    }
}

int main(int argc, char** argv) {
    fix("/Users/asia/Documents/FlightSimulator/src/Scene/blguru.obj", "Scene/teapot.obj");
}


/*
int main(int argc, char** argv)
{


    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

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
*/
