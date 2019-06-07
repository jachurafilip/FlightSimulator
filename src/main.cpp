#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Models/DummyModel.h"
#include "Models/Model_6DOF.h"
#include "PlaneController.h"
#include "Scene/FixObj.cpp"
#include "Scene/Scene.cpp"
#include "Scene/FreeImage.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

Plane p;
Model6DOF m;

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
            case GLFW_KEY_R:
                reset();
                break;
            case GLFW_KEY_I:
                pc.throttle(amount);
                break;
            case GLFW_KEY_O:
                pc.throttle(-amount);
                break;
            case GLFW_KEY_K:
                pc.turnLogs();
                break;
            case GLFW_KEY_H:
                printHelp();
                break;
            case GLFW_KEY_F:
                pc.flaps();
                break;
            case GLFW_KEY_LEFT:
                pc.moveAilerons(-amount);
                break;
            case GLFW_KEY_UP:
                pc.moveElevators(-amount);
                break;
            case GLFW_KEY_DOWN:
                pc.moveElevators(amount);
                break;
            case  GLFW_KEY_RIGHT:
                pc.moveAilerons(amount);
                break;
            case GLFW_KEY_D:
                cameraLeft(amount,eye,up);
                break;
            case GLFW_KEY_A:
                cameraLeft(-amount,eye,up);
                break;
            case GLFW_KEY_W:
                cameraUp(amount,eye,up);
                break;
            case GLFW_KEY_S:
                cameraUp(-amount,eye,up);
                break;
            default:
                break;
        }
    }
}

int main(int argc, char** argv)
{

    if(fork())
    system("feh ../../sterowanie.png");
    else {

        GLFWwindow *window;
        glfwSetErrorCallback(error_callback);

        if (!glfwInit())
            exit(EXIT_FAILURE);

        int windowWidth = 640;
        int windowHeight = 480;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        window = glfwCreateWindow(windowWidth, windowHeight, "Simulation", nullptr, nullptr);
        if (!window) {
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
        reshape(window, windowWidth, windowHeight);

        printHelp();
        move(0, 0, 0, floorVertices);

        try {

            do {
                glfwPollEvents();
                display(window);
                pc.simulate();
                roll((m.getCurrentPosition().angles.roll - m.getPreviousPosition().angles.roll) * M_PI / 180,
                     modelVertices);
                pitch((m.getCurrentPosition().angles.pitch - m.getPreviousPosition().angles.pitch) * M_PI / 180,
                      modelVertices);
                yaw((m.getCurrentPosition().angles.yaw - m.getPreviousPosition().angles.yaw) * M_PI / 180,
                    modelVertices);
                move(m.getPreviousPosition().point.getX() - m.getCurrentPosition().point.getX(),
                     m.getPreviousPosition().point.getZ() - m.getCurrentPosition().point.getZ(),
                     m.getPreviousPosition().point.getY() - m.getCurrentPosition().point.getY(), modelVertices);
                glfwSwapBuffers(window);
            } while (!glfwWindowShouldClose(window));
        }
        catch (int e) {
            std::cout << "You crashed";
            cleanup();
            glfwDestroyWindow(window);
            //glfwTerminate();
            exit(EXIT_SUCCESS);
        }


        cleanup();
        glfwDestroyWindow(window);

        glfwTerminate();
        exit(EXIT_SUCCESS);

    }
}

