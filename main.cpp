#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

float vertices[]={

-0.5f,-0.5f,0.0f,
0.5f,-0.5f,0.0f,
0.0f,0.5f,0.0f
};

void framebuffer_size_callback(GLFWwindow *window,int width,int height){

    glViewport(0,0,width,height);

}
void processInput(GLFWwindow *window){
    if (glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
int main() {
    unsigned int VBO;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window=glfwCreateWindow(800, 600, "Pussy", NULL, NULL);

    if (window==NULL) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initalize glad\n");
        return -1;
    }

    glViewport(0,0,800,600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glGenBuffers(1,&VBO);


    while (!glfwWindowShouldClose(window)) {
        //inputs
        processInput(window);

        //rendering commands
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //check and call events and swap the buffers
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
