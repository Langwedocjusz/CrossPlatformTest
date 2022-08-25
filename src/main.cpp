#include <iostream>

#include <GLFW/glfw3.h>

int main() {

  //Example - only log information in non-distribution builds
  #if !(DISTRIBUTION_BUILD)
  std::cout << "Hello world!" << '\n';
  #endif

  //Initialize glfw:
  if (!glfwInit()) {
    throw "Failed to initialize glfw!";
  }

  //Set OpenGL version to 3.3 core
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  //Create a window
  GLFWwindow* window = glfwCreateWindow(800, 600, "CrossPlatformTest", NULL, NULL);

  if (!window) {
    throw "Failed to create a window!";
  }

  //Set the created window as current context
  glfwMakeContextCurrent(window);
  //Enable vsync
  glfwSwapInterval(1);

  //Rendering loop
  while(!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  //Cleanup
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
