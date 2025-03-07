#include "collision_cube.h"

collisionCube::collisionCube(Shader& shader, glm::vec3 position )
	:cube_shader(shader),
    cube_position(position)
{
    glGenVertexArrays(1, &cube_VAO);
    glGenBuffers(1, &cube_VBO);

    glBindBuffer(GL_ARRAY_BUFFER, cube_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_VBO_array), cube_VBO_array, GL_STATIC_DRAW);

    glBindVertexArray(cube_VAO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

}

collisionCube::~collisionCube()
{
    glDeleteVertexArrays(1, &cube_VAO);
    glDeleteBuffers(1, &cube_VBO);
}

void collisionCube::DrawCube(glm::mat4& view, glm::mat4& projection, glm::vec3 color)
{
    cube_shader.use();
    // world transformation
    cube_shader.setMat4("projection", projection);
    cube_shader.setMat4("view", view);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, cube_position);
    cube_shader.setMat4("model", model);

    cube_shader.setVec3("objectColor", color);
    // render the cube
    glBindVertexArray(cube_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

}

void collisionCube::resizeCubeVertexY(float Yoffset)
{
    

    cube_position = glm::vec3(0.0f, 0.0f + Yoffset, 0.0f);

    glm::vec3 offset_y = glm::vec3(0.0f, 0.0f + Yoffset, 0.0f);

    for (int i = 0; i < 8; i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, offset_y);
        cube_vertex[i] = model * cube_vertex[i];

        //std::cout << "cubeVertex  x: " << cube_vertex[i].x << " y: " << cube_vertex[i].y << " z: " << cube_vertex[i].z << std::endl;
    }

}

glm::vec4 collisionCube::getVertex(int index)
{
    return cube_vertex[index];
}

