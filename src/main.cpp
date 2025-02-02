#include <GL/glew.h>
#include <chrono>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/fwd.hpp>
#include <ios>
#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utils.h>

// #define WINDOW_HEIGHT 1200
#define WINDOW_HEIGHT 1200
// #define WINDOW_WIDTH 2200
#define WINDOW_WIDTH 1200

int main() {
  auto t_start = std::chrono::system_clock::now();
  if (!glfwInit())
    return -1;

  utils::glfwHints();

  GLFWwindow *window =
      glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL", nullptr, nullptr);

  if (!window)
    return -1;

  glfwMakeContextCurrent(window);

  glewExperimental = true;
  if (glewInit() != GLEW_OK)
    return -1;

  // GLfloat vertices[] = {
  //     //  Position         Color             Texcoords
  //     0.5f,  -0.5f, 0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // 0 - Bottom-right
  //     -0.5f, -0.5f, 0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // 1 - Bottom-left
  //     0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // 2 - Top-right
  //     -0.5f, 0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // 3 - Top-left
  //     0.5f,  -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, // 4 - Bottom-right
  //     -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // 5 - Bottom-left
  //     0.5f,  0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, // 6 - Top-right
  //     -0.5f, 0.5f,  -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // 7 - Top-left
  //     0.5f,  0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f  // 6 - Top-right
  // };

  GLfloat vertices[] = {
      -1.5f, -1.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // yeah no
      1.5f,  -1.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, // yeah no
      1.5f,  1.5f,  -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // yeah no
      1.5f,  1.5f,  -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // yeah no
      -1.5f, 1.5f,  -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, // yeah no
      -1.5f, -1.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // yeah no

      -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, // yeah no
      0.5f,  -0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, // yeah no
      0.5f,  0.5f,  -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, // yeah no
      0.5f,  0.5f,  -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, // yeah no
      -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // yeah no
      -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, // yeah no

      -0.5f, -0.5f, 0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 0.0f, // yeah no
      0.5f,  -0.5f, 0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 0.0f, // yeah no
      0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 1.0f, // yeah no
      0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 1.0f, // yeah no
      -0.5f, 0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 0.0f, 1.0f, // yeah no
      -0.5f, -0.5f, 0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 0.0f, // yeah no

      -0.5f, 0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // yeah no
      -0.5f, 0.5f,  -0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, // yeah no
      -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // yeah no
      -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // yeah no
      -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // yeah no
      -0.5f, 0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // yeah no

      0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // yeah no
      0.5f,  0.5f,  -0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, // yeah no
      0.5f,  -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // yeah no
      0.5f,  -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // yeah no
      0.5f,  -0.5f, 0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f, // yeah no
      0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // yeah no

      -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // yeah no
      0.5f,  -0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, // yeah no
      0.5f,  -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 0.0f, // yeah no
      0.5f,  -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 0.0f, // yeah no
      -0.5f, -0.5f, 0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // yeah no
      -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // yeah no

      -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // yeah no
      0.5f,  0.5f,  -0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, // yeah no
      0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 0.0f, // yeah no
      0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 0.0f, // yeah no
      -0.5f, 0.5f,  0.5f,  1.0f, 0.5f, 0.5f, 0.0f, 0.0f, // yeah no
      -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  //, 0.0f // yeah no
  };

  // GLuint elements[] = {
  //     0, 1, 2, 1, 2, 3, // top plane
  //     4, 5, 6, 5, 6, 7, // bottom plane
  //     0, 1, 4, 1, 4, 5, // left bl-wh
  //     0, 2, 4, 2, 4, 6, // fwd
  //     1, 3, 5, 3, 5, 7, // bck
  //     2, 3, 6, 3, 6, 7, // right rd-green
  // };

  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // GLuint ebo;
  // glGenBuffers(1, &ebo);
  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements,
  //              GL_STATIC_DRAW);

  auto vertexShader =
      utils::makeShader("src/shaders/triangle.vert", GL_VERTEX_SHADER);
  auto fragmentShader =
      utils::makeShader("src/shaders/triangle.frag", GL_FRAGMENT_SHADER);

  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);

  glBindFragDataLocation(shaderProgram, 0, "outColor");
  glLinkProgram(shaderProgram);
  glUseProgram(shaderProgram);

  GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);

  GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
  glEnableVertexAttribArray(colAttrib);
  glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void *)(3 * sizeof(float)));

  GLint texAttrib = glGetAttribLocation(shaderProgram, "texCord");
  glEnableVertexAttribArray(texAttrib);
  glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void *)(6 * sizeof(float)));

  // GLuint tex;
  // glGenTextures(1, &tex);
  // glActiveTexture(GL_TEXTURE0);
  // glBindTexture(GL_TEXTURE_2D, tex);

  GLuint tex[3];
  glGenTextures(3, tex);
  // glBindTexture(GL_TEXTURE_2D, tex);
  utils::getImage("res/mask.png", GL_TEXTURE1, tex[1]);
  utils::getImage("res/glass.png", GL_TEXTURE2, tex[2]);

  glUniform1i(glGetUniformLocation(shaderProgram, "texMask"), 1);
  glUniform1i(glGetUniformLocation(shaderProgram, "texGlass"), 2);

  glm::mat4 model = glm::mat4(0.5f);
  GLint uniModel = glGetUniformLocation(shaderProgram, "model");
  glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(model));

  glm::mat4 view = glm::lookAt(    //
      glm::vec3(4.2f, 4.2f, 2.0f), //
      glm::vec3(0.0f, 0.0f, 0.f),  //
      glm::vec3(0.0f, 0.0f, 1.0f)  //
  );

  GLint uniView = glGetUniformLocation(shaderProgram, "view");
  glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

  glm::mat4 proj = glm::perspective(glm::radians(45.0f),                   //
                                    (1.0f * WINDOW_WIDTH) / WINDOW_HEIGHT, //
                                    1.0f,                                  //
                                    20.0f);
  GLint uniProj = glGetUniformLocation(shaderProgram, "projection");
  glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));

  auto uniOverride = glGetUniformLocation(shaderProgram, "overrideColor");

  // for (int i = 0; i < 4; i++) {
  //   for (int j = 0; j < 4; j++) {
  //     std::cout << proj[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }

  float time = 0;

  glEnable(GL_DEPTH_TEST);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    auto t_now = std::chrono::system_clock::now();
    float t_diff = std::chrono::duration_cast<std::chrono::duration<float>>(
                       t_now - t_start)
                       .count();
    t_start = t_now;
    t_diff *= 0.2;
    time += t_diff;
    time = time - floor(time);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model,                       // model,
                        glm::radians(360.0f) * time, // * glm::radians(0.1f), //
                        glm::vec3(0.0f, 0.0f, 1.0f));
    glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(model));
    // std::cout << time << std::endl;

    glUseProgram(shaderProgram);

    glUniform3f(uniOverride, 1.0f, 1.0f, 1.0f);

    glBindVertexArray(vao);

    // glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 6, 36);

    glUniform3f(uniOverride, 0.4f, 0.4f, 0.4f);

    glEnable(GL_STENCIL_TEST);

    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    glStencilMask(0xFF);
    glDepthMask(GL_FALSE);
    glClear(GL_STENCIL_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDepthMask(GL_TRUE);
    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilMask(0x00);

    model = glm::scale(                                      //
        glm::translate(model, glm::vec3(0.0f, 0.0f, -1.0f)), // no
        glm::vec3(1.0f, 1.0f, -1.0f));

    glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 6, 36);

    glDisable(GL_STENCIL_TEST);

    glfwSwapBuffers(window);
    glfwPollEvents();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, GL_TRUE);
    }
  }

  glDeleteTextures(3, tex);

  glDeleteProgram(shaderProgram);
  glDeleteProgram(fragmentShader);
  glDeleteProgram(vertexShader);

  // glDeleteBuffers(1, &ebo);
  glDeleteBuffers(1, &vbo);

  glDeleteVertexArrays(1, &vao);

  // utils::removeImage(image);

  // std::this_thread::sleep_for(std::chrono::seconds(10));

  glfwTerminate();
  return 0;
}
