#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Models/DummyModel.h"
#include "PlaneController.h"
#include "Scene/main2.cpp"
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
                if(useGlu) {
                    std::cout << "Please disable glm::LookAt by pressing 'g'"
                              << " before running tests\n";
                }
                else if(!allowGrader) {
                    std::cout << "Error: no input file specified for grader\n";
                } else {
                    std::cout << "Running tests...\n";
                    grader.runTests();
                    std::cout << "Done! [ESC to quit]\n";
                }
                break;
            case GLFW_KEY_G:
                useGlu = !useGlu;
                std::cout << "Using glm::LookAt set to: "
                          << (useGlu ? " true " : " false ") << "\n";
                break;
            case GLFW_KEY_H:
                printHelp();
                break;
            case GLFW_KEY_R:  // reset eye and up vectors
                eye = eyeinit;
                up = upinit;
                amount = amountinit;
                std::cout << "eye and up vectors reset, amount set to " << amountinit << "\n";
                break;
            case GLFW_KEY_LEFT: //left
                pc.moveAilerons(amount);
                break;
            case GLFW_KEY_UP: //up
                pc.moveElevators(amount);
                break;
            case GLFW_KEY_RIGHT: //right
                pc.moveAilerons(-amount);
                break;
            case GLFW_KEY_DOWN: //down
                pc.moveElevators(-amount);
                break;
            default:
                break;
        }
    }
}


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

