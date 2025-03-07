#include "shader.h"


class collisionCube
{
private:
    glm::vec3 cube_position = glm::vec3(0.0f, 0.0f, 0.0f);

    glm::vec4 cube_vertex1 = glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f);
    glm::vec4 cube_vertex2 = glm::vec4(-0.5f, -0.5f, 0.5f, 1.0f);
    glm::vec4 cube_vertex3 = glm::vec4(0.5f, -0.5f, 0.5f, 1.0f);
    glm::vec4 cube_vertex4 = glm::vec4(0.5f, -0.5f, -0.5f, 1.0f);
              
    glm::vec4 cube_vertex5 = glm::vec4(-0.5f, 0.5f, -0.5f, 1.0f);
    glm::vec4 cube_vertex6 = glm::vec4(-0.5f, 0.5f, 0.5f, 1.0f);
    glm::vec4 cube_vertex7 = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);
    glm::vec4 cube_vertex8 = glm::vec4(0.5f, 0.5f, -0.5f, 1.0f);


    glm::vec4 cube_vertex[8] =
    {
       cube_vertex1,
       cube_vertex2,
       cube_vertex3,
       cube_vertex4,
                   
       cube_vertex5,
       cube_vertex6,
       cube_vertex7,
       cube_vertex8
    };

    float cube_VBO_array[6*6*6] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };

    Shader cube_shader;
    unsigned int cube_VAO, cube_VBO;


public:
    collisionCube(Shader &shader, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
    ~collisionCube();

    void DrawCube(glm::mat4& view, glm::mat4& projection, glm::vec3 color);

    void resizeCubeVertexY(float offset);

    glm::vec4 getVertex(int index);

};