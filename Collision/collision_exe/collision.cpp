#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <string>

#include "camera.h"
#include "shader.h"
#include "collision_plane.h"
#include "collision_cube.h"




//int WIDTH = 800;
//int HEIGHT = 600;
//
//// camera
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = WIDTH / 2.0f;
//float lastY = HEIGHT / 2.0f;
//bool firstMouse = true;
//
//// timing
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
//void processInput(GLFWwindow* window);
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//bool isCollisionEnable(collisionCube& cube, collisionPlane& plane);
//
//bool isKeyPressed = false;
//
////void resizeCubeVertexY(float offset);
//
////void resizePlaneVertex(glm::vec3 planePos);
//
////void showCubeVertex();
////void showPlaneVertex();
////bool isCollisionEnable();
//
//
//glm::vec3 cubePos = glm::vec3(0.0f, 0.0f, 0.0f);
//
//float y_offset = 0.01f;
//
///*glm::vec3 cubePos1 = glm::vec3(0.0f, 0.0f, 0.0f);
//
//
//glm::vec4 cube_vertex[8] =
//{
//    glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f),
//    glm::vec4(-0.5f, -0.5f,  0.5f, 1.0f),
//    glm::vec4( 0.5f, -0.5f,  0.5f, 1.0f),
//    glm::vec4( 0.5f, -0.5f, -0.5f, 1.0f),
//                                 
//    glm::vec4(-0.5f,  0.5f, -0.5f, 1.0f),
//    glm::vec4(-0.5f,  0.5f,  0.5f, 1.0f),
//    glm::vec4( 0.5f,  0.5f,  0.5f, 1.0f),
//    glm::vec4( 0.5f,  0.5f, -0.5f, 1.0f)
//                                 
//};  */                             
//                                 
//                                 
//                                 
////glm::vec4 planeVertex[4] =       
////{                                
////    // positions                 
////    glm::vec4( 1.0f,  0.0f,  1.0f, 1.0f),
////    glm::vec4( 1.0f,  0.0f, -1.0f, 1.0f),
////    glm::vec4(-1.0f,  0.0f, -1.0f, 1.0f),
////    glm::vec4(-1.0f,  0.0f,  1.0f, 1.0f)
////};
////
////glm::vec3 planePos = glm::vec3(0.0f, -3.0f, 0.0f);
////
////glm::vec4 planeNormal = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
////
////glm::vec4 planePoint_0 = planeVertex[0];
////
////
////
////
////
////
////float A = planeNormal.x;
////float B = planeNormal.y;
////float C = planeNormal.z;
////
////float D = -(A * planePoint_0.x + B * planePoint_0.y + C * planePoint_0.z);
//
//int main()
//{
//    // glfw: initialize and configure
//        // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    // glfw window creation
//    // --------------------
//
//
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
//
//    // tell GLFW to capture our mouse
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // configure global opengl state
//   // -----------------------------
//    glEnable(GL_DEPTH_TEST);
//
//    // build and compile our shader zprogram
//    // ------------------------------------
//
//    Shader simpleShader
//    (
//        "C:/Users/Koros/OneDrive/Рабочий стол/Collision/Collision/collision_src/txt/shader_vs.txt",
//        "C:/Users/Koros/OneDrive/Рабочий стол/Collision/Collision/collision_src/txt/shader_fs.txt"
//    );
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    
//    
//    //float vertices[] = {
//    //    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//    //     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//    //     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//    //     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//    //    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//    //    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//    //    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//    //     0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//    //     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//    //     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//    //    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//    //    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//    //    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//    //    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//    //    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//    //    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//    //    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//    //    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//    //     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//    //     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//    //     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//    //     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//    //     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//    //     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//    //    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//    //     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//    //     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//    //     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//    //    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//    //    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//    //    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//    //     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//    //     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//    //     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//    //    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//    //    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//    //};
//    //// first, configure the cube's VAO (and VBO)
//    //unsigned int VBO, VAO;
//    //glGenVertexArrays(1, &VAO);
//    //glGenBuffers(1, &VBO);
//
//    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    //glBindVertexArray(VAO);
//
//    //// position attribute
//    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    //glEnableVertexAttribArray(0);
//    
//    //float planeVertices[] = {
//    //    // positions            // normals         
//    //     1.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
//    //    -1.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
//    //    -1.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
//    //                
//    //     1.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
//    //    -1.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
//    //     1.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f
//    //};
//    //// plane VAO
//    //unsigned int planeVAO, planeVBO;
//    //glGenVertexArrays(1, &planeVAO);
//    //glGenBuffers(1, &planeVBO);
//    //glBindVertexArray(planeVAO);
//    //glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
//    //glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
//    //glEnableVertexAttribArray(0);
//    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    //
//
//    glm::vec3 cubeColorGreen = glm::vec3(0.0f, 0.5f, 0.0f);
//    glm::vec3 cubeColorRed = glm::vec3(0.5f, 0.0f, 0.0f);
//
//    glm::vec3 cubeColor;
//
//    collisionCube cube(simpleShader);
//
//    glm::vec3 planeColorBlue = glm::vec3(0.0f, 0.0f, 0.5f);
//    glm::vec3 planePosition = glm::vec3(0.0f, -3.0f, 0.0f);
//
//
//    collisionPlane plane(simpleShader, planeColorBlue, planePosition);
//
//
//
//    //resizePlaneVertex(planePos);
//    
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        // per-frame time logic
//        // --------------------
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // input
//        // -----
//        processInput(window);
//
//
//        // render
//        // ------
//        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//        
//
//        simpleShader.use();
//
//        if (isCollisionEnable(cube,plane) == true)
//        {
//            cubeColor = cubeColorRed;
//        }
//        else
//        {
//            cubeColor = cubeColorGreen;
//        }
//        //simpleShader.setVec3("objectColor", 0.0f, 0.5f, 0.0f);
//        // view/projection transformations
//        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//        glm::mat4 view = camera.GetViewMatrix();
//        simpleShader.setMat4("projection", projection);
//        simpleShader.setMat4("view", view);
//
//        ////// world transformation
//        //glm::mat4 model = glm::mat4(1.0f);
//        //model = glm::translate(model, cubePos1);
//        //simpleShader.setMat4("model", model);
//        //
//        //// render the cube
//        //glBindVertexArray(VAO);
//        //glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//        //simpleShader.setVec3("objectColor", 0.0f, 0.0f, 0.5f);
//        //// world transformation
//        //model = glm::mat4(1.0f);
//        //model = glm::translate(model, planePos);
//        //simpleShader.setMat4("model", model);
//        //
//
//        //// render the cube
//        //glBindVertexArray(planeVAO);
//        //glDrawArrays(GL_TRIANGLES, 0, 6);
//
//        
//        
//
//        cube.DrawCube(view, projection, cubeColor);
//
//        plane.DrawPlane(view, projection);
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//    // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//    
//   
//   
//
//
//    // glfw: terminate, clearing all previously allocated GLFW resources.
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        camera.ProcessKeyboard(LEFT, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        camera.ProcessKeyboard(RIGHT, deltaTime);
//
//    
//    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
//    {
//        //showCubeVertex();
//        std::cout << std::endl;
//        //showPlaneVertex();
//    }
//   
//    
//    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//    {
//        cubePos.y += y_offset;
//        
//        
//       
//        
//    }
//    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//    {
//        cubePos.y -= y_offset;
//        //std::cout << "cubePos  x: " << cubePos1.x << " y: " << cubePos1.y << " z: " << cubePos1.z << std::endl;
//        
//        
//    }
//
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos;
//    lastX = xpos;
//    lastY = ypos;
//
//    camera.ProcessMouseMovement(xoffset, yoffset);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    camera.ProcessMouseScroll(static_cast<float>(yoffset));
//}
//
//bool isCollisionEnable(collisionCube &cube, collisionPlane &plane)
//{
//    for (int i = 0; i < 8; i++)
//    {
//        
//        float r = plane.result(cube.getVertex(i));
//        if (r >= -0.1f && r <= 0.1f)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}



// 2 variant--------------------------------------------------------------------------------------------------------------------------------------

//int WIDTH = 800;
//int HEIGHT = 600;
//
//// camera
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = WIDTH / 2.0f;
//float lastY = HEIGHT / 2.0f;
//bool firstMouse = true;
//
//// timing
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
//void processInput(GLFWwindow* window);
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//// cube functions
//void resizeCubeVertex(float offset_x, float offset_y, float offset_z);
//void showCubeVertex();
//
//// plane functions
//void resizePlaneVertex(glm::vec3 planePos);
//void showPlaneVertex();
//float findMinPlaneX();
//float findMaxPlaneX();
//float findMinPlaneY();
//float findMaxPlaneY();
//float findMinPlaneZ();
//float findMaxPlaneZ();
//
//
//bool isCollisionEnable();
//
//
//
//
//float y_offset = 0.01f;
//float x_offset = 0.01f;
//
//glm::vec3 cubePos1 = glm::vec3(0.0f, 0.0f, 0.0f);
//
//
//glm::vec4 cube_vertex[8] =
//{
//    glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f),
//    glm::vec4(-0.5f, -0.5f,  0.5f, 1.0f),
//    glm::vec4( 0.5f, -0.5f,  0.5f, 1.0f),
//    glm::vec4( 0.5f, -0.5f, -0.5f, 1.0f),
//
//    glm::vec4(-0.5f,  0.5f, -0.5f, 1.0f),
//    glm::vec4(-0.5f,  0.5f,  0.5f, 1.0f),
//    glm::vec4( 0.5f,  0.5f,  0.5f, 1.0f),
//    glm::vec4( 0.5f,  0.5f, -0.5f, 1.0f)
//
//};  
//
//
//
//glm::vec4 planeVertex[4] =       
//{                                
//    // positions                 
//    glm::vec4( 1.0f,  0.0f,  1.0f, 1.0f),
//    glm::vec4( 1.0f,  0.0f, -1.0f, 1.0f),
//    glm::vec4(-1.0f,  0.0f, -1.0f, 1.0f),
//    glm::vec4(-1.0f,  0.0f,  1.0f, 1.0f)
//};
//
//glm::vec3 planePos = glm::vec3(0.0f, -3.0f, 0.0f);
//
//glm::vec4 planeNormal = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
//
//glm::vec4 planePoint_0 = planeVertex[0];
//
//float A = planeNormal.x;
//float B = planeNormal.y;
//float C = planeNormal.z;
//
//float D = -(A * planePoint_0.x + B * planePoint_0.y + C * planePoint_0.z);
//
//float Xmin;
//float Xmax;
//float Ymin;
//float Ymax;
//float Zmin;
//float Zmax;
//
//int main()
//{
//    // glfw: initialize and configure
//        // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    // glfw window creation
//    // --------------------
//
//
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
//
//    // tell GLFW to capture our mouse
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // configure global opengl state
//   // -----------------------------
//    glEnable(GL_DEPTH_TEST);
//
//    // build and compile our shader zprogram
//    // ------------------------------------
//
//    Shader simpleShader
//    (
//        "C:/Users/Koros/OneDrive/Рабочий стол/Collision/Collision/collision_src/txt/shader_vs.txt",
//        "C:/Users/Koros/OneDrive/Рабочий стол/Collision/Collision/collision_src/txt/shader_fs.txt"
//    );
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//
//
//    float vertices[] = {
//        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//    };
//    // first, configure the cube's VAO (and VBO)
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glBindVertexArray(VAO);
//
//    // position attribute
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    float planeVertices[] = {
//        // positions            // normals         
//         1.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
//        -1.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
//        -1.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
//                    
//         1.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
//        -1.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
//         1.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f
//    };
//    // plane VAO
//    unsigned int planeVAO, planeVBO;
//    glGenVertexArrays(1, &planeVAO);
//    glGenBuffers(1, &planeVBO);
//    glBindVertexArray(planeVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//   
//
//    resizePlaneVertex(planePos);
//    Xmin = findMinPlaneX();
//    Xmax = findMaxPlaneX();
//    Ymin = findMinPlaneY();
//    Ymax = findMaxPlaneY();
//    Zmin = findMinPlaneZ();
//    Zmax = findMaxPlaneZ();
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        // per-frame time logic
//        // --------------------
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // input
//        // -----
//        processInput(window);
//
//
//        // render
//        // ------
//        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//        simpleShader.use();
//
//        if (isCollisionEnable() == true)
//        {
//            simpleShader.setVec3("objectColor", 0.5f, 0.0f, 0.0f);
//        }
//        else
//        {
//            simpleShader.setVec3("objectColor", 0.0f, 0.5f, 0.0f);
//        }
//        //simpleShader.setVec3("objectColor", 0.0f, 0.5f, 0.0f);
//        // view/projection transformations
//        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//        glm::mat4 view = camera.GetViewMatrix();
//        simpleShader.setMat4("projection", projection);
//        simpleShader.setMat4("view", view);
//
//        //// world transformation
//        glm::mat4 model = glm::mat4(1.0f);
//        model = glm::translate(model, cubePos1);
//        simpleShader.setMat4("model", model);
//        
//        // render the cube
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//        simpleShader.setVec3("objectColor", 0.0f, 0.0f, 0.5f);
//        // world transformation
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, planePos);
//        simpleShader.setMat4("model", model);
//        
//
//        // render the cube
//        glBindVertexArray(planeVAO);
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//    // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//
//
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//
//    glDeleteVertexArrays(1, &planeVAO);
//    glDeleteBuffers(1, &planeVBO);
//
//    // glfw: terminate, clearing all previously allocated GLFW resources.
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        camera.ProcessKeyboard(LEFT, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        camera.ProcessKeyboard(RIGHT, deltaTime);
//
//
//    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
//    {
//        //showCubeVertex();
//        std::cout << std::endl;
//        //showPlaneVertex();
//        float low_result = A * cube_vertex[0].x + B * cube_vertex[0].y + C * cube_vertex[0].z + D; // нижняя точка куба
//        float high_result = A * cube_vertex[4].x + B * cube_vertex[4].y + C * cube_vertex[4].z + D; // вехняя точка куба
//        std::cout << "low_result " << low_result << std::endl;
//        std::cout << "high_result " << high_result << std::endl;
//    }
//
//
//    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//    {
//        cubePos1.y += y_offset;
//        resizeCubeVertex(0.0f, y_offset, 0.0f);
//
//    }
//    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//    {
//        cubePos1.y -= y_offset;
//        //std::cout << "cubePos  x: " << cubePos1.x << " y: " << cubePos1.y << " z: " << cubePos1.z << std::endl;
//        resizeCubeVertex(0.0f, -y_offset, 0.0f);
//
//    }
//
//    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
//    {
//        cubePos1.x -= x_offset;
//        resizeCubeVertex(-x_offset, 0.0f, 0.0f);
//
//    }
//    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
//    {
//        cubePos1.x += x_offset;
//        //std::cout << "cubePos  x: " << cubePos1.x << " y: " << cubePos1.y << " z: " << cubePos1.z << std::endl;
//        resizeCubeVertex(x_offset, 0.0f, 0.0f);
//    }
//
//
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos;
//    lastX = xpos;
//    lastY = ypos;
//
//    camera.ProcessMouseMovement(xoffset, yoffset);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    camera.ProcessMouseScroll(static_cast<float>(yoffset));
//}
//
//void resizeCubeVertex(float offset_x, float offset_y, float offset_z)
//{ 
//
//    glm::vec3 Offset = glm::vec3(0.0f + offset_x, 0.0f + offset_y, 0.0f + offset_z);
//
//    for (int i = 0; i < 8; i++)
//    {
//        glm::mat4 model = glm::mat4(1.0f);
//        model = glm::translate(model, Offset);
//        cube_vertex[i] = model*cube_vertex[i];
//
//        //std::cout << "cubeVertex  x: " << cube_vertex[i].x << " y: " << cube_vertex[i].y << " z: " << cube_vertex[i].z << std::endl;
//    }
//
//
//}
//
//void showCubeVertex()
//{
//    for (int i = 0; i < 8; i++)
//    {
//        std::cout << "point " << i << " x: " << cube_vertex[i].x << " y: " << cube_vertex[i].y << " z: " << cube_vertex[i].z << std::endl;
//    }
//
//}
//
//
//
//
//void resizePlaneVertex(glm::vec3 planePos)
//{
//
//    for (int i = 0; i < 4; i++)
//    {
//        glm::mat4 trans = glm::mat4(1.0f);
//        trans = glm::translate(trans, planePos);
//        planeVertex[i] = trans * planeVertex[i];
//        std::cout << "plane point " << i << " x: " << planeVertex[i].x << " y: " << planeVertex[i].y << " z: " << planeVertex[i].z << std::endl;
//    }
//
//    glm::mat4 trans = glm::mat4(1.0f);
//    trans = glm::translate(trans, planePos);
//    planeNormal = trans * planeNormal;
//
//    A = planeNormal.x;
//    B = planeNormal.y;
//    C = planeNormal.z;
//
//
//    trans = glm::mat4(1.0f);
//    trans = glm::translate(trans, planePos);
//    planePoint_0 = trans * planePoint_0;
//
//    D = -(A * planePoint_0.x + B * planePoint_0.y + C * planePoint_0.z);
//
//    //std::cout << "plane normal  x: " << planeNormal.x << " y: " << planeNormal.y << " z: " << planeNormal.z << std::endl;
//    //std::cout << "plane point zero  x: " << planePoint_0.x << " y: " << planePoint_0.y << " z: " << planePoint_0.z << std::endl;
//    //std::cout << "A: " << A << " B: " << B << " C: " << C << " D: " << D << std::endl;
//}
//
//void showPlaneVertex()
//{
//    for (int i = 0; i < 4; i++)
//    {
//        std::cout << "plane point " << i << " x: " << planeVertex[i].x << " y: " << planeVertex[i].y << " z: " << planeVertex[i].z << std::endl;
//    }
//
//}
//
//float findMinPlaneX()
//{
//    float min_x = planeVertex[0].x;
//
//    for (int i = 0; i < 4; i++)
//    {
//        if (planeVertex[i].x < min_x)
//        {
//            min_x = planeVertex[i].x;
//        }
//    }
//
//    return min_x;
//}
//
//float findMaxPlaneX()
//{
//    float max_x = planeVertex[1].x;
//
//    for (int i = 0; i < 4; i++)
//    {
//        if (planeVertex[i].x > max_x)
//        {
//            max_x = planeVertex[i].x;
//        }
//    }
//
//    return max_x;
//}
//
//float findMinPlaneY()
//{
//    float min_y = planeVertex[0].y;
//
//    for (int i = 0; i < 4; i++)
//    {
//        if (planeVertex[i].y < min_y)
//        {
//            min_y = planeVertex[i].y;
//        }
//    }
//
//    return min_y;
//}
//
//float findMaxPlaneY()
//{
//    float max_y = planeVertex[1].y;
//
//    for (int i = 0; i < 4; i++)
//    {
//        if (planeVertex[i].y > max_y)
//        {
//            max_y = planeVertex[i].y;
//        }
//    }
//
//    return max_y;
//}
//
//float findMinPlaneZ()
//{
//    float min_z = planeVertex[0].z;
//
//    for (int i = 0; i < 4; i++)
//    {
//        if (planeVertex[i].z < min_z)
//        {
//            min_z = planeVertex[i].z;
//        }
//    }
//
//    return min_z;
//}
//
//float findMaxPlaneZ()
//{
//    float max_z = planeVertex[1].z;
//
//    for (int i = 0; i < 4; i++)
//    {
//        if (planeVertex[i].z > max_z)
//        {
//            max_z = planeVertex[i].z;
//        }
//    }
//
//    return max_z;
//}
//
//
//bool isCollisionEnable()
//{
//    for (int i = 0; i < 8; i++)
//    {
//
//        float result = A * cube_vertex[i].x + B * cube_vertex[i].y + C * cube_vertex[i].z + D;
//
//        
//        
//        if (result >= -0.05f && result <= 0.05f)
//        {
//            if (   ((cube_vertex[i].x > Xmin && cube_vertex[i].x < Xmax) || Xmin == Xmax)
//                && ((cube_vertex[i].y > Ymin && cube_vertex[i].y < Ymax) || Ymin == Ymax)
//                && ((cube_vertex[i].z > Zmin && cube_vertex[i].z < Zmax) || Zmin == Zmax))
//            {
//                return true;
//            }
//        
//        }           
//        
//   
//    }
//
//    return false;
//}



// 3 variant(include class collision_plane)-------------------------------------------------------------------------------------------------------------------------------------

int WIDTH = 800;
int HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = WIDTH / 2.0f;
float lastY = HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

// cube functions
void resizeCubeVertex(float offset_x, float offset_y, float offset_z);
void showCubeVertex();
float findMax(float begin, float end);
float findMin(float begin, float end);

//collision functions
bool isCollisionEnable(collisionPlane &plane, bool isDebug);

float y_offset = 0.01f;
float x_offset = 0.01f;
float z_offset = 0.01f;

glm::vec3 axis_x = glm::vec3(1.0f, 0.0f, 0.0f);
glm::vec3 axis_y = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 axis_z = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);

//cube data
glm::vec3 cubePos1 = glm::vec3(0.0f, 0.0f, 0.0f);

glm::vec4 cube_vertex[8] =
{
    glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f), //0
    glm::vec4(-0.5f, -0.5f,  0.5f, 1.0f), //1
    glm::vec4( 0.5f, -0.5f,  0.5f, 1.0f), //2
    glm::vec4( 0.5f, -0.5f, -0.5f, 1.0f),//3

    glm::vec4(-0.5f,  0.5f, -0.5f, 1.0f),//4
    glm::vec4(-0.5f,  0.5f,  0.5f, 1.0f),//5
    glm::vec4( 0.5f,  0.5f,  0.5f, 1.0f),//6
    glm::vec4( 0.5f,  0.5f, -0.5f, 1.0f)//7

};

int cube_projectionn_YX_positive[4] =
{
    1,2,6,5
};

int cube_projectionn_YZ_positive[4] =
{
    2,3,7,6
};

int cube_projectionn_XZ_positive[4] =
{
    4,5,6,7
};

/*
struct cube_projection_segment
{
    float cube_a;
    float cube_t;
    float cube_0_coefficient;
    float cube_top_max;// максимальное значение по оси Y (X для X(Z)) макс. значение для оси, направленной вверх
    float cube_top_min;// минимальное  значение по оси Y (X для X(Z)) мин.  значение для оси, направленной вверх
    float cube_right_max;// максимальное значение по оси X (Z для X(Z) и Y(Z)) макс. значение для оси, направленной вправо
    float cube_right_min;// минимальное  значение по оси X (Z для X(Z) и Y(Z)) мин.  значение для оси, направленной вправо
};

// коэффициенты уравнений отрезков проекции Y(X)  y0 и t(y = y0 + t*x)
 
// a
float        cube_a_YX_01;
float        cube_a_YX_12;
float        cube_a_YX_23;
float        cube_a_YX_30;


// t
float        cube_t_YX_01;
float        cube_t_YX_12;
float        cube_t_YX_23;
float        cube_t_YX_30;
             
//y0        
float        cube_y0_YX_01;
float        cube_y0_YX_12;
float        cube_y0_YX_23;
float        cube_y0_YX_30;

// границы, которые ограничивают отрезки проекций
float cube_YX_01_top_max;
float cube_YX_01_top_min;
float cube_YX_01_right_max;
float cube_YX_01_right_min;
     
float cube_YX_12_top_max;
float cube_YX_12_top_min;
float cube_YX_12_right_max;
float cube_YX_12_right_min;
      
float cube_YX_23_top_max;
float cube_YX_23_top_min;
float cube_YX_23_right_max;
float cube_YX_23_right_min;
     
float cube_YX_30_top_max;
float cube_YX_30_top_min;
float cube_YX_30_right_max;
float cube_YX_30_right_min;

cube_projection_segment C_YX[4] =
{
    {cube_a_YX_01, cube_t_YX_01, cube_y0_YX_01, cube_YX_01_top_max, cube_YX_01_top_min, cube_YX_01_right_max, cube_YX_01_right_min},
    {cube_a_YX_12, cube_t_YX_12, cube_y0_YX_12, cube_YX_12_top_max, cube_YX_12_top_min, cube_YX_12_right_max, cube_YX_12_right_min},
    {cube_a_YX_23, cube_t_YX_23, cube_y0_YX_23, cube_YX_23_top_max, cube_YX_23_top_min, cube_YX_23_right_max, cube_YX_23_right_min},
    {cube_a_YX_30, cube_t_YX_30, cube_y0_YX_30, cube_YX_30_top_max, cube_YX_30_top_min, cube_YX_30_right_max, cube_YX_30_right_min}
};                                                                        

// коэффициенты уравнений отрезков проекции Y(Z)  y0 и t(y = y0 + t*z)

// a
float        cube_a_YZ_01;
float        cube_a_YZ_12;
float        cube_a_YZ_23;
float        cube_a_YZ_30;
 
// t
float        cube_t_YZ_01;
float        cube_t_YZ_12;
float        cube_t_YZ_23;
float        cube_t_YZ_30;
             
//y0         
float        cube_y0_YZ_01;
float        cube_y0_YZ_12;
float        cube_y0_YZ_23;
float        cube_y0_YZ_30;

// границы, которые ограничивают отрезки проекций
float cube_YZ_01_top_max;
float cube_YZ_01_top_min;
float cube_YZ_01_right_max;
float cube_YZ_01_right_min;
      
float cube_YZ_12_top_max;
float cube_YZ_12_top_min;
float cube_YZ_12_right_max;
float cube_YZ_12_right_min;
      
float cube_YZ_23_top_max;
float cube_YZ_23_top_min;
float cube_YZ_23_right_max;
float cube_YZ_23_right_min;
      
float cube_YZ_30_top_max;
float cube_YZ_30_top_min;
float cube_YZ_30_right_max;
float cube_YZ_30_right_min;

cube_projection_segment C_YZ[4] =
{
    {cube_a_YZ_01, cube_t_YZ_01, cube_y0_YZ_01, cube_YZ_01_top_max, cube_YZ_01_top_min,cube_YZ_01_right_max, cube_YZ_01_right_min},
    {cube_a_YZ_12, cube_t_YZ_12, cube_y0_YZ_12, cube_YZ_12_top_max, cube_YZ_12_top_min,cube_YZ_12_right_max, cube_YZ_12_right_min},
    {cube_a_YZ_23, cube_t_YZ_23, cube_y0_YZ_23, cube_YZ_23_top_max, cube_YZ_23_top_min,cube_YZ_23_right_max, cube_YZ_23_right_min},
    {cube_a_YZ_30, cube_t_YZ_30, cube_y0_YZ_30, cube_YZ_30_top_max, cube_YZ_30_top_min,cube_YZ_30_right_max, cube_YZ_30_right_min}
};

// коэффициенты уравнений отрезков проекции X(Z)  x0 и t(x = x0 + t*z)

// a
float        cube_a_XZ_01;
float        cube_a_XZ_12;
float        cube_a_XZ_23;
float        cube_a_XZ_30;

// t
float        cube_t_XZ_01;
float        cube_t_XZ_12;
float        cube_t_XZ_23;
float        cube_t_XZ_30;
             
//x0         
float        cube_x0_XZ_01;
float        cube_x0_XZ_12;
float        cube_x0_XZ_23;
float        cube_x0_XZ_30;

// границы, которые ограничивают отрезки проекций
float cube_XZ_01_top_max;
float cube_XZ_01_top_min;
float cube_XZ_01_right_max;
float cube_XZ_01_right_min;
      
float cube_XZ_12_top_max;
float cube_XZ_12_top_min;
float cube_XZ_12_right_max;
float cube_XZ_12_right_min;
     
float cube_XZ_23_top_max;
float cube_XZ_23_top_min;
float cube_XZ_23_right_max;
float cube_XZ_23_right_min;
      
float cube_XZ_30_top_max;
float cube_XZ_30_top_min;
float cube_XZ_30_right_max;
float cube_XZ_30_right_min;

cube_projection_segment C_XZ[4] =
{
    {cube_a_XZ_01, cube_t_XZ_01, cube_x0_XZ_01, cube_XZ_01_top_max, cube_XZ_01_top_min,cube_XZ_01_right_max, cube_XZ_01_right_min},
    {cube_a_XZ_12, cube_t_XZ_12, cube_x0_XZ_12, cube_XZ_12_top_max, cube_XZ_12_top_min,cube_XZ_12_right_max, cube_XZ_12_right_min},
    {cube_a_XZ_23, cube_t_XZ_23, cube_x0_XZ_23, cube_XZ_23_top_max, cube_XZ_23_top_min,cube_XZ_23_right_max, cube_XZ_23_right_min},
    {cube_a_XZ_30, cube_t_XZ_30, cube_x0_XZ_30, cube_XZ_30_top_max, cube_XZ_30_top_min,cube_XZ_30_right_max, cube_XZ_30_right_min}
};

//bool YX = false;
//bool YZ = false;
//bool XZ = false;

// направляющие векторы 
    // нижняя грань куба
//glm::vec3 cube_directional_vector_0_1 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[1].x - cube_vertex[0].x,
//    cube_vertex[1].y - cube_vertex[0].y,
//    cube_vertex[1].z - cube_vertex[0].z
//);
//
//glm::vec3 cube_directional_vector_1_2 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[2].x - cube_vertex[1].x,
//    cube_vertex[2].y - cube_vertex[1].y,
//    cube_vertex[2].z - cube_vertex[1].z
//);
//
//glm::vec3 cube_directional_vector_3_2 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[3].x - cube_vertex[2].x,
//    cube_vertex[3].y - cube_vertex[2].y,
//    cube_vertex[3].z - cube_vertex[2].z
//);
//
//glm::vec3 cube_directional_vector_0_3 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[0].x - cube_vertex[3].x,
//    cube_vertex[0].y - cube_vertex[3].y,
//    cube_vertex[0].z - cube_vertex[3].z
//);
//
//
////верхняя грань куба ()
//glm::vec3 cube_directional_vector_5_4 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[5].x - cube_vertex[4].x,
//    cube_vertex[5].y - cube_vertex[4].y,
//    cube_vertex[5].z - cube_vertex[4].z
//);
//
//glm::vec3 cube_directional_vector_6_5 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[6].x - cube_vertex[5].x,
//    cube_vertex[6].y - cube_vertex[5].y,
//    cube_vertex[6].z - cube_vertex[5].z
//);
//
//glm::vec3 cube_directional_vector_7_6 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[7].x - cube_vertex[6].x,
//    cube_vertex[7].y - cube_vertex[6].y,
//    cube_vertex[7].z - cube_vertex[6].z
//);
//
//glm::vec3 cube_directional_vector_4_7 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[4].x - cube_vertex[7].x,
//    cube_vertex[4].y - cube_vertex[7].y,
//    cube_vertex[4].z - cube_vertex[7].z
//);
//
//// боковые грани
//glm::vec3 cube_directional_vector_0_4 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[0].x - cube_vertex[4].x,
//    cube_vertex[0].y - cube_vertex[4].y,
//    cube_vertex[0].z - cube_vertex[4].z
//);
//
//glm::vec3 cube_directional_vector_1_5 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[1].x - cube_vertex[5].x,
//    cube_vertex[1].y - cube_vertex[5].y,
//    cube_vertex[1].z - cube_vertex[5].z
//);
//
//glm::vec3 cube_directional_vector_2_6 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[2].x - cube_vertex[6].x,
//    cube_vertex[2].y - cube_vertex[6].y,
//    cube_vertex[2].z - cube_vertex[6].z
//);
//
//glm::vec3 cube_directional_vector_3_7 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
//(
//    cube_vertex[3].x - cube_vertex[7].x,
//    cube_vertex[3].y - cube_vertex[7].y,
//    cube_vertex[3].z - cube_vertex[7].z
//);
//
//glm::vec3 cube_directional_vectors[12] =
//{
//    cube_directional_vector_0_1,
//    cube_directional_vector_1_2,
//    cube_directional_vector_3_2,
//    cube_directional_vector_0_3,
//    cube_directional_vector_5_4,
//    cube_directional_vector_6_5,
//    cube_directional_vector_7_6,
//    cube_directional_vector_4_7,
//    cube_directional_vector_0_4,
//    cube_directional_vector_1_5,
//    cube_directional_vector_2_6,
//    cube_directional_vector_3_7
//
//};
*/

// проекции с помощью уравнений прямых на плоскости и  коэффициентов A, B, C

struct cube_projection
{
    // уравнение прямой на плоскости A*x + B*y + C = 0
    float cube_A;// коэффициент прямой при x(Y(X)), z(Y(Z), X(Z))
    float cube_B;// коэффициент прямой при y(Y(X)), y(Y(Z)), z(X(Z))
    float cube_C;// свободный коэффициент (не при переменных который)
    float cube_top_max;// максимальное значение по оси Y (X для X(Z)) макс. значение для оси, направленной вверх
    float cube_top_min;// минимальное  значение по оси Y (X для X(Z)) мин.  значение для оси, направленной вверх
    float cube_right_max;// максимальное значение по оси X (Z для X(Z) и Y(Z)) макс. значение для оси, направленной вправо
    float cube_right_min;// минимальное  значение по оси X (Z для X(Z) и Y(Z)) мин.  значение для оси, направленной вправо
};

// YX

float   cube_YX_01_A;
float   cube_YX_12_A;
float   cube_YX_23_A;
float   cube_YX_30_A;
        
float   cube_YX_01_B;
float   cube_YX_12_B;
float   cube_YX_23_B;
float   cube_YX_30_B;
        
float   cube_YX_01_C;
float   cube_YX_12_C;
float   cube_YX_23_C;
float   cube_YX_30_C;

// границы, которые ограничивают отрезки проекций (t - top, r - right)
float cube_YX_01_t_max;
float cube_YX_01_t_min;
float cube_YX_01_r_max;
float cube_YX_01_r_min;
     
float cube_YX_12_t_max;
float cube_YX_12_t_min;
float cube_YX_12_r_max;
float cube_YX_12_r_min;
      
float cube_YX_23_t_max;
float cube_YX_23_t_min;
float cube_YX_23_r_max;
float cube_YX_23_r_min;
     
float cube_YX_30_t_max;
float cube_YX_30_t_min;
float cube_YX_30_r_max;
float cube_YX_30_r_min;

// уравнение прямой на плоскости A*x + B*y + C = 0
cube_projection Cu_YX[4] =
{
    {cube_YX_01_A, cube_YX_01_B, cube_YX_01_C, cube_YX_01_t_max, cube_YX_01_t_min,cube_YX_01_r_max, cube_YX_01_r_min },
    {cube_YX_12_A, cube_YX_12_B, cube_YX_12_C, cube_YX_12_t_max, cube_YX_12_t_min,cube_YX_12_r_max, cube_YX_12_r_min },
    {cube_YX_23_A, cube_YX_23_B, cube_YX_23_C, cube_YX_23_t_max, cube_YX_23_t_min,cube_YX_23_r_max, cube_YX_23_r_min },
    {cube_YX_30_A, cube_YX_30_B, cube_YX_30_C, cube_YX_30_t_max, cube_YX_30_t_min,cube_YX_30_r_max, cube_YX_30_r_min }
};

// YZ

float   cube_YZ_01_A;
float   cube_YZ_12_A;
float   cube_YZ_23_A;
float   cube_YZ_30_A;
        
float   cube_YZ_01_B;
float   cube_YZ_12_B;
float   cube_YZ_23_B;
float   cube_YZ_30_B;
        
float   cube_YZ_01_C;
float   cube_YZ_12_C;
float   cube_YZ_23_C;
float   cube_YZ_30_C;

// границы, которые ограничивают отрезки проекций (t - top, r - right)
float cube_YZ_01_t_max;
float cube_YZ_01_t_min;
float cube_YZ_01_r_max;
float cube_YZ_01_r_min;
      
float cube_YZ_12_t_max;
float cube_YZ_12_t_min;
float cube_YZ_12_r_max;
float cube_YZ_12_r_min;
      
float cube_YZ_23_t_max;
float cube_YZ_23_t_min;
float cube_YZ_23_r_max;
float cube_YZ_23_r_min;
     
float cube_YZ_30_t_max;
float cube_YZ_30_t_min;
float cube_YZ_30_r_max;
float cube_YZ_30_r_min;

// уравнение прямой на плоскости A*z + B*y + C = 0
cube_projection Cu_YZ[4] =
{
    {cube_YZ_01_A, cube_YZ_01_B, cube_YZ_01_C, cube_YZ_01_t_max, cube_YZ_01_t_min,cube_YZ_01_r_max, cube_YZ_01_r_min },
    {cube_YZ_12_A, cube_YZ_12_B, cube_YZ_12_C, cube_YZ_12_t_max, cube_YZ_12_t_min,cube_YZ_12_r_max, cube_YZ_12_r_min },
    {cube_YZ_23_A, cube_YZ_23_B, cube_YZ_23_C, cube_YZ_23_t_max, cube_YZ_23_t_min,cube_YZ_23_r_max, cube_YZ_23_r_min },
    {cube_YZ_30_A, cube_YZ_30_B, cube_YZ_30_C, cube_YZ_30_t_max, cube_YZ_30_t_min,cube_YZ_30_r_max, cube_YZ_30_r_min }
};

// XZ

float   cube_XZ_01_A;
float   cube_XZ_12_A;
float   cube_XZ_23_A;
float   cube_XZ_30_A;
        
float   cube_XZ_01_B;
float   cube_XZ_12_B;
float   cube_XZ_23_B;
float   cube_XZ_30_B;
        
float   cube_XZ_01_C;
float   cube_XZ_12_C;
float   cube_XZ_23_C;
float   cube_XZ_30_C;

// границы, которые ограничивают отрезки проекций (t - top, r - right)
float cube_XZ_01_t_max;
float cube_XZ_01_t_min;
float cube_XZ_01_r_max;
float cube_XZ_01_r_min;
      
float cube_XZ_12_t_max;
float cube_XZ_12_t_min;
float cube_XZ_12_r_max;
float cube_XZ_12_r_min;
      
float cube_XZ_23_t_max;
float cube_XZ_23_t_min;
float cube_XZ_23_r_max;
float cube_XZ_23_r_min;
      
float cube_XZ_30_t_max;
float cube_XZ_30_t_min;
float cube_XZ_30_r_max;
float cube_XZ_30_r_min;

// уравнение прямой на плоскости A*z + B*x + C = 0
cube_projection Cu_XZ[4] =
{
    {cube_XZ_01_A, cube_XZ_01_B, cube_XZ_01_C, cube_XZ_01_t_max, cube_XZ_01_t_min,cube_XZ_01_r_max, cube_XZ_01_r_min },
    {cube_XZ_12_A, cube_XZ_12_B, cube_XZ_12_C, cube_XZ_12_t_max, cube_XZ_12_t_min,cube_XZ_12_r_max, cube_XZ_12_r_min },
    {cube_XZ_23_A, cube_XZ_23_B, cube_XZ_23_C, cube_XZ_23_t_max, cube_XZ_23_t_min,cube_XZ_23_r_max, cube_XZ_23_r_min },
    {cube_XZ_30_A, cube_XZ_30_B, cube_XZ_30_C, cube_XZ_30_t_max, cube_XZ_30_t_min,cube_XZ_30_r_max, cube_XZ_30_r_min }
};

int main()
{
    // glfw: initialize and configure
        // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------


    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
   // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader simpleShader
    (
        "C:/Users/Koros/OneDrive/Рабочий стол/Git-engine/Collision/collision_src/txt/shader_vs.txt",
        "C:/Users/Koros/OneDrive/Рабочий стол/Git-engine/Collision/collision_src/txt/shader_fs.txt"
    );
    

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------


    float vertices[] = {
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
    // first, configure the cube's VAO (and VBO)
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //axis

    float axis_vertices[] =
    {
        //x
        axis_x.x, axis_x.y, axis_x.z,
        center.x, center.y, center.z,
        //y
        axis_y.x, axis_y.y, axis_y.z,
        center.x, center.y, center.z,
        //z
        axis_z.x, axis_z.y, axis_z.z,
        center.x, center.y, center.z,
    };

    unsigned int axisVBO, axisVAO;
    glGenVertexArrays(1, &axisVAO);
    glGenBuffers(1, &axisVBO);

    glBindBuffer(GL_ARRAY_BUFFER, axisVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(axis_vertices), axis_vertices, GL_STATIC_DRAW);

    glBindVertexArray(axisVAO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //plane data(1)
    /*glm::vec3 plane1_Color = glm::vec3(0.0f, 0.0f, 0.5f);
    glm::vec3 plane1_Position = glm::vec3(0.0f, -3.0f, -2.0f);
    glm::vec3 plane1_Scale = glm::vec3(2.0f, 1.0f, 1.0f);
    float     plane1_degree = 0.0f;
    glm::vec3 plane1_rotation_axis = glm::vec3(0.0f, 0.0f, 1.0f); // по какой оси поворачивает, в данном случае 0.0f, 1.0f, 0.0f - ось У
                                                                  // 1.0f, 0.0f, 0.0f - ось X
                                                                  // 0.0f, 0.0f, 1.0f - ось Z

    collisionPlane plane1(simpleShader, 
                   plane1_Color, 
                   plane1_Position,
                   plane1_Scale,
                   plane1_degree,
                   plane1_rotation_axis);
                   */

    /*glm::vec3 plane2_Color = glm::vec3(0.0f, 0.5f, 0.5f);
    glm::vec3 plane2_Position = glm::vec3(0.0f, -3.0f, 0.0f);
    glm::vec3 plane2_Scale = glm::vec3(1.0f, 1.0f, 1.0f);
    float     plane2_degree = 90.0f;
    glm::vec3 plane2_rotation_axis = glm::vec3(0.0f, 0.0f, 1.0f);
    

    collisionPlane plane2(simpleShader,
                   plane2_Color, 
                   plane2_Position, 
                   plane2_Scale, 
                   plane2_degree, 
                   plane2_rotation_axis);

    glm::vec3 plane3_Color = glm::vec3(0.5f, 0.5f, 0.0f);
    glm::vec3 plane3_Position = glm::vec3(0.0f, 3.0f, 0.0f);
    glm::vec3 plane3_Scale = glm::vec3(1.0f, 1.0f, 1.0f);
    float     plane3_degree = 45.0f;
    glm::vec3 plane3_rotation_axis = glm::vec3(0.0f, 0.0f, 1.0f);


    collisionPlane plane3(simpleShader,
                   plane3_Color,
                   plane3_Position,
                   plane3_Scale,
                   plane3_degree,
                   plane3_rotation_axis);

    glm::vec3 plane4_Color = glm::vec3(0.5f, 0.5f, 0.0f);
    glm::vec3 plane4_Position = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 plane4_Scale = glm::vec3(1.0f, 1.0f, 1.0f);
    float     plane4_degree = 180.0f;
    glm::vec3 plane4_rotation_axis = glm::vec3(0.0f, 0.0f, 1.0f);


    collisionPlane plane4(simpleShader,
                   plane4_Color,
                   plane4_Position,
                   plane4_Scale,
                   plane4_degree,
                   plane4_rotation_axis);

    glm::vec3 plane5_Color = glm::vec3(0.5f, 0.0f, 0.5f);
    glm::vec3 plane5_Position = glm::vec3(-2.0f, 0.0f, 0.0f);
    glm::vec3 plane5_Scale = glm::vec3(1.0f, 1.0f, 1.0f);
    float     plane5_degree = 45.0f;
    glm::vec3 plane5_rotation_axis = glm::vec3(0.0f, 0.0f, 1.0f);


    collisionPlane plane5(simpleShader,
                   plane5_Color,
                   plane5_Position,
                   plane5_Scale,
                   plane5_degree,
                   plane5_rotation_axis);*/

    glm::vec3 plane6_Color = glm::vec3(0.2f, 0.8f, 0.2f);
    glm::vec3 plane6_Position = glm::vec3(2.0f, 2.0f, 0.0f);
    glm::vec3 plane6_Scale = glm::vec3(1.0f, 1.0f, 1.0f);
    float     plane6_degree = -180.0f;
    glm::vec3 plane6_rotation_axis = glm::vec3(1.0f, 1.0f, 1.0f);


    collisionPlane plane6(simpleShader,
                   plane6_Color,
                   plane6_Position,
                   plane6_Scale,
                   plane6_degree,
                   plane6_rotation_axis);

    bool is_debug = false;

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        //if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        //{
        //    //showCubeVertex();
        //    std::cout << std::endl;
        //    ////showPlaneVertex();
        //    //float low_result = plane6.result(cube_vertex[5]);// нижняя точка куба
        //    //float high_result = plane6.result(cube_vertex[6]); // вехняя точка куба
        //    //std::cout << "low_result " << low_result << std::endl;
        //    //std::cout << "high_result " << high_result << std::endl;

        //    //////std::cout << "Plane min Z: " << plane4.minZ() << std::endl;
        //    //////std::cout << "Plane max Z: " << plane4.maxZ() << std::endl;

        //    for (int i = 0; i < 8; i++)
        //    {
        //        float result = plane6.result(cube_vertex[i]);
        //        std::cout << "result of vertex: " <<  i << " is " << result << std::endl;

        //        
        //    }

        //    //std::cout << " YX: " << YX << " YZ: " << YZ << " XZ: " << XZ << std::endl;

        //    //showCubeVertex();
        //    
        //}

        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        {
            
            is_debug = true;
        }
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
        {

            is_debug = false;
        }


        
        // render
        // ------
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        simpleShader.use();

        if (
            /*(isCollisionEnable(plane1) == true) 
            ||*/ 
            //(isCollisionEnable(plane2) == true)
            // || 
            //(isCollisionEnable(plane3) == true) 
            // ||
            //(isCollisionEnable(plane4) == true)
            //||
            //(isCollisionEnable(plane5) == true)
            //||
            (isCollisionEnable(plane6, is_debug) == true)
            )
        {
            simpleShader.setVec3("objectColor", 0.5f, 0.0f, 0.0f);
        }
        else
        {
            simpleShader.setVec3("objectColor", 0.0f, 0.5f, 0.0f);
        }
        //simpleShader.setVec3("objectColor", 0.0f, 0.5f, 0.0f);
        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        simpleShader.setMat4("projection", projection);
        simpleShader.setMat4("view", view);

        //// world transformation
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePos1);
        simpleShader.setMat4("model", model);

        // render the cube
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        //axis (указаны положительные направления всех осей. ось, что наверх смотрит - ось у)
        model = glm::mat4(1.0f);
        simpleShader.setMat4("model", model);

        simpleShader.setVec3("objectColor", 0.5f, 0.0f, 0.0f);
        glBindVertexArray(axisVAO);
        glLineWidth(5);
        glDrawArrays(GL_LINES, 0,18);


        //planes draw
        //plane1.DrawPlane(view, projection);
        /*plane2.DrawPlane(view, projection);
        plane3.DrawPlane(view, projection);
        plane4.DrawPlane(view, projection);
        plane5.DrawPlane(view, projection);*/
        plane6.DrawPlane(view, projection);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------


    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glDeleteVertexArrays(1, &axisVAO);
    glDeleteBuffers(1, &axisVBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;

}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);


    //if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    //{
    //    //showCubeVertex();
    //    std::cout << std::endl;
    //    //showPlaneVertex();
    //    float low_result = A * cube_vertex[0].x + B * cube_vertex[0].y + C * cube_vertex[0].z + D; // нижняя точка куба
    //    float high_result = A * cube_vertex[4].x + B * cube_vertex[4].y + C * cube_vertex[4].z + D; // вехняя точка куба
    //    std::cout << "low_result " << low_result << std::endl;
    //    std::cout << "high_result " << high_result << std::endl;
    //}


    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        cubePos1.y += y_offset;
        resizeCubeVertex(0.0f, y_offset, 0.0f);

    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        cubePos1.y -= y_offset;
        resizeCubeVertex(0.0f, -y_offset, 0.0f);
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        cubePos1.x -= x_offset;
        resizeCubeVertex(-x_offset, 0.0f, 0.0f);

    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        cubePos1.x += x_offset;
        resizeCubeVertex(x_offset, 0.0f, 0.0f);
    }

    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        cubePos1.z += z_offset;
        resizeCubeVertex(0.0f, 0.0f, z_offset);
    }

    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        cubePos1.z -= z_offset;
        resizeCubeVertex(0.0f, 0.0f, -z_offset);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

void resizeCubeVertex(float offset_x, float offset_y, float offset_z)
{

    glm::vec3 Offset = glm::vec3(0.0f + offset_x, 0.0f + offset_y, 0.0f + offset_z);

    for (int i = 0; i < 8; i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, Offset);
        cube_vertex[i] = model * cube_vertex[i];

        //std::cout << "cubeVertex  x: " << cube_vertex[i].x << " y: " << cube_vertex[i].y << " z: " << cube_vertex[i].z << std::endl;
    }


    float dy = 0.0f;
    float dx = 0.0f;
    float dz = 0.0f;
    int next_i = 0;

    // отезки проекции коэффициенты t y0

    /*Плоскость проекции Y(X)
     коэффициенты t рассчитываются как приращение по осям проекций (в случае плоскости проекции Y(X) t = (y2-y1)/(x2-x1), где
     y2, x2 - координаты условного конца отрезка  (примем правая цифра в индексе),
     y1, x1 - координаты условного начала отрезка (примем левая цифра в индексе),
     из координат конца вычитаем координаты начала, как для вектора)


     y0 рассчитывается, исходя из уравнения y = y0 + t*x, откуда следует, что y0 = y - t*x
     примем в качестве y и x - координаты начала отрезка (левая цифра в индексе)

     для плоскости YX*/

    /*
    //std::cout << std::endl;
    //std::cout <<"begin" << std::endl;
    //std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        next_i = i + 1;
        if (next_i == 4)
        {
            next_i = 0;
        }
        dy = cube_vertex[cube_projectionn_YX_positive[next_i]].y - cube_vertex[cube_projectionn_YX_positive[i]].y;
        dx = cube_vertex[cube_projectionn_YX_positive[next_i]].x - cube_vertex[cube_projectionn_YX_positive[i]].x;

        if ((dy < 0.1f && dy > -0.1f) && (dx < 0.1f && dx > -0.1f))
            // если оба приращения равны 0, то проекция на плоскость будет точка, соответственно ее можно не учитывать
            // и все коэффициенты ставим 0
        {
            C_YX[i].cube_a = 0.0f;
            C_YX[i].cube_t = 0.0f;
            C_YX[i].cube_0_coefficient = 0.0f;
            C_YX[i].cube_top_max =   C_YX[i].cube_0_coefficient;
            C_YX[i].cube_top_min =   C_YX[i].cube_0_coefficient;
            C_YX[i].cube_right_max = C_YX[i].cube_0_coefficient;
            C_YX[i].cube_right_min = C_YX[i].cube_0_coefficient;
        }
        else if (dy < 0.1f && dy > -0.1f)
            // проверка, есть ли приращение по у, если его нет(т.е. dy = 0 или около 0), то
            //отрезок проекции параллелен оси х, отсюда следует, что в итоговом уравнении a*y - t*x = y0 мы х не учитываем
            // и нам нужно только проверить, выше или ниже относительно у0 находятся точки проекций куба (или проекции другой фигуры)
        {
            C_YX[i].cube_a = 1.0f;
            C_YX[i].cube_t = 0.0f;
            C_YX[i].cube_0_coefficient = cube_vertex[cube_projectionn_YX_positive[i]].y;
            C_YX[i].cube_top_max = C_YX[i].cube_0_coefficient;
            C_YX[i].cube_top_min = C_YX[i].cube_0_coefficient;
            C_YX[i].cube_right_max = findMax(cube_vertex[cube_projectionn_YX_positive[next_i]].x, cube_vertex[cube_projectionn_YX_positive[i]].x);
            C_YX[i].cube_right_min = findMin(cube_vertex[cube_projectionn_YX_positive[next_i]].x, cube_vertex[cube_projectionn_YX_positive[i]].x);
        }
        else if (dx < 0.1f && dx > -0.1f)
            // проверка, есть ли приращение по x, если его нет(т.е. dx = 0 или около 0), то
            //отрезок проекции параллелен оси у, отсюда следует, что в итоговом уравнении a*y - t*x = y0 мы у не учитываем
            // и нам нужно только проверить, правее или левее относительно у0 = х находятся точки проекций куба (или проекции другой фигуры)
        {
            C_YX[i].cube_a = 0.0f; // а = 0, поскольку в случае параллельности оси у мы у не учитываем
            C_YX[i].cube_t = -1.0f;// t = -1, чтобы убрать минус перед  (- t*x)
            C_YX[i].cube_0_coefficient = cube_vertex[cube_projectionn_YX_positive[i]].x;// в данном случае у0 = х, чтобы потом в уравнении  - t*x = y0 
            // мы могли сравнить х точки куба с Х плоскости и сравнить, больше он или меньше х плоскости(правее или левее) 
            C_YX[i].cube_top_max = findMax(cube_vertex[cube_projectionn_YX_positive[next_i]].y, cube_vertex[cube_projectionn_YX_positive[i]].y);
            C_YX[i].cube_top_min = findMin(cube_vertex[cube_projectionn_YX_positive[next_i]].y, cube_vertex[cube_projectionn_YX_positive[i]].y);
            C_YX[i].cube_right_max = C_YX[i].cube_0_coefficient;
            C_YX[i].cube_right_min = C_YX[i].cube_0_coefficient;

        }
        else // если ни одно из условий выше не было выполнено (отрезки не параллельны осям или не аппроксимируются в точку)
            // то тогда по стандартному расчету для прямой
        {
            C_YX[i].cube_a = 1.0f;
            C_YX[i].cube_t = dy / dx;
            C_YX[i].cube_0_coefficient = cube_vertex[cube_projectionn_YX_positive[i]].y - C_YX[i].cube_t * cube_vertex[cube_projectionn_YX_positive[i]].x;
            
            C_YX[i].cube_top_max =   findMax(cube_vertex[cube_projectionn_YX_positive[next_i]].y, cube_vertex[cube_projectionn_YX_positive[i]].y);
            C_YX[i].cube_top_min =   findMin(cube_vertex[cube_projectionn_YX_positive[next_i]].y, cube_vertex[cube_projectionn_YX_positive[i]].y);
            C_YX[i].cube_right_max = findMax(cube_vertex[cube_projectionn_YX_positive[next_i]].x, cube_vertex[cube_projectionn_YX_positive[i]].x);
            C_YX[i].cube_right_min = findMin(cube_vertex[cube_projectionn_YX_positive[next_i]].x, cube_vertex[cube_projectionn_YX_positive[i]].x);
        }

        std::cout << "C_YX[i].plane_t: " <<         C_YX[i].cube_t << "\t C_YX[i].plane_0_coefficient: " << C_YX[i].cube_0_coefficient << std::endl;
        std::cout << "C_YX[i].plane_top_max: " <<   C_YX[i].cube_top_max << std::endl;
        std::cout << "C_YX[i].plane_top_min: " <<   C_YX[i].cube_top_min << std::endl;
        std::cout << "C_YX[i].plane_right_max: " << C_YX[i].cube_right_max << std::endl;
        std::cout << "C_YX[i].plane_right_min: " << C_YX[i].cube_right_min << std::endl;

    }

    //std::cout << std::endl;
    
    // Плоскость проекции Y(Z)
   // коэффициенты t рассчитываются как приращение по осям проекций (в случае плоскости проекции Y(Z) t = (y2-y1)/(z2-z1), где
   // y2, z2 - координаты условного конца отрезка  (примем правая цифра в индексе), 
   // y1, z1 - координаты условного начала отрезка (примем левая цифра в индексе),
   // из координат конца вычитаем координаты начала, как для вектора)

    //y0 рассчитывается, исходя из уравнения y = y0 + t*z, откуда следует, что y0 = y - t*z
   // примем в качестве y и z - координаты начала отрезка (левая цифра в индексе)
    //для плоскости YZ
    for (int i = 0; i < 4; i++)
    {
        next_i = i + 1;
        if (next_i == 4)
        {
            next_i = 0;
        }
        dy = cube_vertex[cube_projectionn_YZ_positive[next_i]].y - cube_vertex[cube_projectionn_YZ_positive[i]].y;
        dz = cube_vertex[cube_projectionn_YZ_positive[next_i]].z - cube_vertex[cube_projectionn_YZ_positive[i]].z;

        if ((dy < 0.1f && dy > -0.1f) && (dz < 0.1f && dz > -0.1f))
            // если оба приращения равны 0, то проекция на плоскость будет точка, соответственно ее можно не учитывать
            // и все коэффициенты ставим 0
        {
            C_YZ[i].cube_a = 0.0f;
            C_YZ[i].cube_t = 0.0f;
            C_YZ[i].cube_0_coefficient = 0.0f;
            C_YZ[i].cube_top_max =   C_YZ[i].cube_0_coefficient;
            C_YZ[i].cube_top_min =   C_YZ[i].cube_0_coefficient;
            C_YZ[i].cube_right_max = C_YZ[i].cube_0_coefficient;
            C_YZ[i].cube_right_min = C_YZ[i].cube_0_coefficient;
        }
        else if (dy < 0.1f && dy > -0.1f)
            // проверка, есть ли приращение по у, если его нет(т.е. dy = 0 или около 0), то
            //отрезок проекции параллелен оси х, отсюда следует, что в итоговом уравнении a*y - t*x = y0 мы х не учитываем
            // и нам нужно только проверить, выше или ниже относительно у0 находятся точки проекций куба (или проекции другой фигуры)
        {
            C_YZ[i].cube_a = 1.0f;
            C_YZ[i].cube_t = 0.0f;
            C_YZ[i].cube_0_coefficient = cube_vertex[cube_projectionn_YZ_positive[i]].y;
            C_YZ[i].cube_top_max = C_YZ[i].cube_0_coefficient;
            C_YZ[i].cube_top_min = C_YZ[i].cube_0_coefficient;
            C_YZ[i].cube_right_max = findMax(cube_vertex[cube_projectionn_YZ_positive[next_i]].z, cube_vertex[cube_projectionn_YZ_positive[i]].z);
            C_YZ[i].cube_right_min = findMin(cube_vertex[cube_projectionn_YZ_positive[next_i]].z, cube_vertex[cube_projectionn_YZ_positive[i]].z);
        }
        else if (dz < 0.1f && dz > -0.1f)
            // проверка, есть ли приращение по x, если его нет(т.е. dx = 0 или около 0), то
            //отрезок проекции параллелен оси у, отсюда следует, что в итоговом уравнении a*y - t*x = y0 мы у не учитываем
            // и нам нужно только проверить, правее или левее относительно у0 = х находятся точки проекций куба (или проекции другой фигуры)
        {
            C_YZ[i].cube_a = 0.0f; // а = 0, поскольку в случае параллельности оси у мы у не учитываем
            C_YZ[i].cube_t = -1.0f;// t = -1, чтобы убрать минус перед  (- t*x)
            C_YZ[i].cube_0_coefficient = cube_vertex[cube_projectionn_YZ_positive[i]].z;// в данном случае у0 = х, чтобы потом в уравнении  - t*x = y0 
            // мы могли сравнить х точки куба с Х плоскости и сравнить, больше он или меньше х плоскости(правее или левее) 
            C_YZ[i].cube_top_max = findMax(cube_vertex[cube_projectionn_YZ_positive[next_i]].y, cube_vertex[cube_projectionn_YZ_positive[i]].y);
            C_YZ[i].cube_top_min = findMin(cube_vertex[cube_projectionn_YZ_positive[next_i]].y, cube_vertex[cube_projectionn_YZ_positive[i]].y);
            C_YZ[i].cube_right_max = C_YZ[i].cube_0_coefficient;
            C_YZ[i].cube_right_min = C_YZ[i].cube_0_coefficient;

        }
        else // если ни одно из условий выше не было выполнено (отрезки не параллельны осям или не аппроксимируются в точку)
            // то тогда по стандартному расчету для прямой
        {
            C_YZ[i].cube_a = 1.0f;
            C_YZ[i].cube_t = dy / dz;
            C_YZ[i].cube_0_coefficient = cube_vertex[cube_projectionn_YZ_positive[i]].y - C_YZ[i].cube_t * cube_vertex[cube_projectionn_YZ_positive[i]].z;
                    
            C_YZ[i].cube_top_max =   findMax(cube_vertex[cube_projectionn_YZ_positive[next_i]].y, cube_vertex[cube_projectionn_YZ_positive[i]].y);
            C_YZ[i].cube_top_min =   findMin(cube_vertex[cube_projectionn_YZ_positive[next_i]].y, cube_vertex[cube_projectionn_YZ_positive[i]].y);
            C_YZ[i].cube_right_max = findMax(cube_vertex[cube_projectionn_YZ_positive[next_i]].z, cube_vertex[cube_projectionn_YZ_positive[i]].z);
            C_YZ[i].cube_right_min = findMin(cube_vertex[cube_projectionn_YZ_positive[next_i]].z, cube_vertex[cube_projectionn_YZ_positive[i]].z);
        }

        std::cout << "C_YZ[i].plane_t: " <<         C_YZ[i].cube_t << "\t P_YX[i].plane_0_coefficient: " << C_YZ[i].cube_0_coefficient << std::endl;
        std::cout << "C_YZ[i].plane_top_max: " <<   C_YZ[i].cube_top_max << std::endl;
        std::cout << "C_YZ[i].plane_top_min: " <<   C_YZ[i].cube_top_min << std::endl;
        std::cout << "C_YZ[i].plane_right_max: " << C_YZ[i].cube_right_max << std::endl;
        std::cout << "C_YZ[i].plane_right_min: " << C_YZ[i].cube_right_min << std::endl;
    }

    //std::cout << std::endl;
    
    // Плоскость проекции X(Z)
   // коэффициенты t рассчитываются как приращение по осям проекций (в случае плоскости проекции X(Z) t = (x2-x1)/(z2-z1), где
   // x2, z2 - координаты условного конца отрезка  (примем правая цифра в индексе), 
   // x1, z1 - координаты условного начала отрезка (примем левая цифра в индексе),
   // из координат конца вычитаем координаты начала, как для вектора)

   // y0 рассчитывается, исходя из уравнения x = x0 + t*z, откуда следует, что x0 = x - t*z
   // примем в качестве x и z - координаты начала отрезка (левая цифра в индексе)
   // для плоскости XZ
    for (int i = 0; i < 4; i++)
    {
        next_i = i + 1;
        if (next_i == 4)
        {
            next_i = 0;
        }
        dx = cube_vertex[cube_projectionn_XZ_positive[next_i]].x - cube_vertex[cube_projectionn_XZ_positive[i]].x;
        dz = cube_vertex[cube_projectionn_XZ_positive[next_i]].z - cube_vertex[cube_projectionn_XZ_positive[i]].z;

        if ((dx < 0.1f && dx > -0.1f) && (dz < 0.1f && dz > -0.1f))
            // если оба приращения равны 0, то проекция на плоскость будет точка, соответственно ее можно не учитывать
            // и все коэффициенты ставим 0
        {
            C_XZ[i].cube_a = 0.0f;
            C_XZ[i].cube_t = 0.0f;
            C_XZ[i].cube_0_coefficient = 0.0f;
            C_XZ[i].cube_top_max =   C_XZ[i].cube_0_coefficient;
            C_XZ[i].cube_top_min =   C_XZ[i].cube_0_coefficient;
            C_XZ[i].cube_right_max = C_XZ[i].cube_0_coefficient;
            C_XZ[i].cube_right_min = C_XZ[i].cube_0_coefficient;
        }
        else if (dx < 0.1f && dx > -0.1f)
            // проверка, есть ли приращение по у, если его нет(т.е. dy = 0 или около 0), то
            //отрезок проекции параллелен оси х, отсюда следует, что в итоговом уравнении a*y - t*x = y0 мы х не учитываем
            // и нам нужно только проверить, выше или ниже относительно у0 находятся точки проекций куба (или проекции другой фигуры)
        {
            C_XZ[i].cube_a = 1.0f;
            C_XZ[i].cube_t = 0.0f;
            C_XZ[i].cube_0_coefficient = cube_vertex[cube_projectionn_XZ_positive[i]].x;
            C_XZ[i].cube_top_max = C_XZ[i].cube_0_coefficient;
            C_XZ[i].cube_top_min = C_XZ[i].cube_0_coefficient;
            C_XZ[i].cube_right_max = findMax(cube_vertex[cube_projectionn_XZ_positive[next_i]].z, cube_vertex[cube_projectionn_XZ_positive[i]].z);
            C_XZ[i].cube_right_min = findMin(cube_vertex[cube_projectionn_XZ_positive[next_i]].z, cube_vertex[cube_projectionn_XZ_positive[i]].z);
        }
        else if (dz < 0.1f && dz > -0.1f)
            // проверка, есть ли приращение по x, если его нет(т.е. dx = 0 или около 0), то
            //отрезок проекции параллелен оси у, отсюда следует, что в итоговом уравнении a*x - t*z = y0 мы у не учитываем
            // и нам нужно только проверить, правее или левее относительно у0 = х находятся точки проекций куба (или проекции другой фигуры)
        {
            C_XZ[i].cube_a = 0.0f; // а = 0, поскольку в случае параллельности оси у мы у не учитываем
            C_XZ[i].cube_t = -1.0f;// t = -1, чтобы убрать минус перед  (- t*x)
            C_XZ[i].cube_0_coefficient = cube_vertex[cube_projectionn_XZ_positive[i]].z;// в данном случае у0 = х, чтобы потом в уравнении  - t*x = y0 
            // мы могли сравнить х точки куба с Х плоскости и сравнить, больше он или меньше х плоскости(правее или левее) 
            C_XZ[i].cube_top_max = findMax(cube_vertex[cube_projectionn_XZ_positive[next_i]].x, cube_vertex[cube_projectionn_XZ_positive[i]].x);
            C_XZ[i].cube_top_min = findMin(cube_vertex[cube_projectionn_XZ_positive[next_i]].x, cube_vertex[cube_projectionn_XZ_positive[i]].x);
            C_XZ[i].cube_right_max = C_XZ[i].cube_0_coefficient;
            C_XZ[i].cube_right_min = C_XZ[i].cube_0_coefficient;

        }
        else // если ни одно из условий выше не было выполнено (отрезки не параллельны осям или не аппроксимируются в точку)
            // то тогда по стандартному расчету для прямой
        {
            C_XZ[i].cube_a = 1.0f;
            C_XZ[i].cube_t = dx / dz;
            C_XZ[i].cube_0_coefficient = cube_vertex[cube_projectionn_XZ_positive[i]].x - C_XZ[i].cube_t * cube_vertex[cube_projectionn_XZ_positive[i]].z;
                    
            C_XZ[i].cube_top_max =   findMax(cube_vertex[cube_projectionn_XZ_positive[next_i]].x, cube_vertex[cube_projectionn_XZ_positive[i]].x);
            C_XZ[i].cube_top_min =   findMin(cube_vertex[cube_projectionn_XZ_positive[next_i]].x, cube_vertex[cube_projectionn_XZ_positive[i]].x);
            C_XZ[i].cube_right_max = findMax(cube_vertex[cube_projectionn_XZ_positive[next_i]].z, cube_vertex[cube_projectionn_XZ_positive[i]].z);
            C_XZ[i].cube_right_min = findMin(cube_vertex[cube_projectionn_XZ_positive[next_i]].z, cube_vertex[cube_projectionn_XZ_positive[i]].z);
        }

        std::cout << "C_XZ[i].plane_t: " <<         C_XZ[i].cube_t << "\t C_YX[i].plane_0_coefficient: " << C_XZ[i].cube_0_coefficient << std::endl;
        std::cout << "C_XZ[i].plane_top_max: " <<   C_XZ[i].cube_top_max << std::endl;
        std::cout << "C_XZ[i].plane_top_min: " <<   C_XZ[i].cube_top_min << std::endl;
        std::cout << "C_XZ[i].plane_right_max: " << C_XZ[i].cube_right_max << std::endl;
        std::cout << "C_XZ[i].plane_right_min: " << C_XZ[i].cube_right_min << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "end" << std::endl;
    std::cout << std::endl;
    */

    // проекции с помощью коэфиициентов A,B,C

     /*
     std::cout << std::endl;
     std::cout << "cube resize begin" << std::endl;
     std::cout << std::endl;
     */

     //YX
     for (int i = 0; i < 4; i++)
     {
         next_i = i + 1;
         if (next_i == 4)
         {
             next_i = 0;
         }
     
         // уравнене прямой составляем, исходя из 2 точек плоскости, ограничивающих отрезок 
         // общее уравнение (х - х1)/(х2 - х1) = (у - у1)/(у2 - у1), отсюда 
         // (х - х1)(у2 - у1) = (у - у1)(х2 - х1)
         // х(у2 - у1) - х1(у2 - у1) - у(х2 - х1) + у1(х2 - х1) = 0
         // х(у2 - у1) + у(х1 - х2) + у1(х2 - х1) - х1(у2 - у1) = 0
         // таким образом A = (у2 - у1), B = (х1 - х2), C = -(x1 * A + y1 * B)
         Cu_YX[i].cube_A = cube_vertex[cube_projectionn_YX_positive[next_i]].y - cube_vertex[cube_projectionn_YX_positive[i]].y;
         Cu_YX[i].cube_B = cube_vertex[cube_projectionn_YX_positive[i]].x - cube_vertex[cube_projectionn_YX_positive[next_i]].x;
         Cu_YX[i].cube_C = -(cube_vertex[cube_projectionn_YX_positive[i]].x * Cu_YX[i].cube_A
                           + cube_vertex[cube_projectionn_YX_positive[i]].y * Cu_YX[i].cube_B);
         
         Cu_YX[i].cube_top_max =   findMax(cube_vertex[cube_projectionn_YX_positive[next_i]].y, cube_vertex[cube_projectionn_YX_positive[i]].y);
         Cu_YX[i].cube_top_min =   findMin(cube_vertex[cube_projectionn_YX_positive[next_i]].y, cube_vertex[cube_projectionn_YX_positive[i]].y);
         Cu_YX[i].cube_right_max = findMax(cube_vertex[cube_projectionn_YX_positive[next_i]].x, cube_vertex[cube_projectionn_YX_positive[i]].x);
         Cu_YX[i].cube_right_min = findMin(cube_vertex[cube_projectionn_YX_positive[next_i]].x, cube_vertex[cube_projectionn_YX_positive[i]].x);
     
         /*
         std::cout << "i: " << i << std::endl;
         std::cout << "Cu_YX[i].cube_A: " <<         Cu_YX[i].cube_A << std::endl;
         std::cout << "Cu_YX[i].cube_B: " <<         Cu_YX[i].cube_B << std::endl;
         std::cout << "Cu_YX[i].cube_C: " <<         Cu_YX[i].cube_C << std::endl;
                                                  
         std::cout << "Cu_YX[i].cube_top_max:   " << Cu_YX[i].cube_top_max << std::endl;
         std::cout << "Cu_YX[i].cube_top_min:   " << Cu_YX[i].cube_top_min << std::endl;
         std::cout << "Cu_YX[i].cube_right_max: " << Cu_YX[i].cube_right_max << std::endl;
         std::cout << "Cu_YX[i].cube_right_min: " << Cu_YX[i].cube_A << std::endl;
         */
     }
     
     //YZ
     for (int i = 0; i < 4; i++)
     {
         next_i = i + 1;
         if (next_i == 4)
         {
             next_i = 0;
         }

         // уравнене прямой составляем, исходя из 2 точек плоскости, ограничивающих отрезок 
         // общее уравнение (х - х1)/(х2 - х1) = (у - у1)/(у2 - у1), отсюда 
         // (х - х1)(у2 - у1) = (у - у1)(х2 - х1)
         // х(у2 - у1) - х1(у2 - у1) - у(х2 - х1) + у1(х2 - х1) = 0
         // х(у2 - у1) + у(х1 - х2) + у1(х2 - х1) - х1(у2 - у1) = 0
         // таким образом A = (у2 - у1), B = (х1 - х2), C = -(x1 * A + y1 * B)
         Cu_YZ[i].cube_A =   cube_vertex[cube_projectionn_YZ_positive[next_i]].y - cube_vertex[cube_projectionn_YZ_positive[i]].y;
         Cu_YZ[i].cube_B =   cube_vertex[cube_projectionn_YZ_positive[i]].z      - cube_vertex[cube_projectionn_YZ_positive[next_i]].z;
         Cu_YZ[i].cube_C = -(cube_vertex[cube_projectionn_YZ_positive[i]].z * Cu_YZ[i].cube_A
                           + cube_vertex[cube_projectionn_YZ_positive[i]].y * Cu_YZ[i].cube_B);

         Cu_YZ[i].cube_top_max =   findMax(cube_vertex[cube_projectionn_YZ_positive[next_i]].y, cube_vertex[cube_projectionn_YZ_positive[i]].y);
         Cu_YZ[i].cube_top_min =   findMin(cube_vertex[cube_projectionn_YZ_positive[next_i]].y, cube_vertex[cube_projectionn_YZ_positive[i]].y);
         Cu_YZ[i].cube_right_max = findMax(cube_vertex[cube_projectionn_YZ_positive[next_i]].z, cube_vertex[cube_projectionn_YZ_positive[i]].z);
         Cu_YZ[i].cube_right_min = findMin(cube_vertex[cube_projectionn_YZ_positive[next_i]].z, cube_vertex[cube_projectionn_YZ_positive[i]].z);

         /*
         std::cout << "i: " << i << std::endl;
         std::cout << "Cu_YZ[i].cube_A: " <<         Cu_YZ[i].cube_A << std::endl;
         std::cout << "Cu_YZ[i].cube_B: " <<         Cu_YZ[i].cube_B << std::endl;
         std::cout << "Cu_YZ[i].cube_C: " <<         Cu_YZ[i].cube_C << std::endl;
                                                         
         std::cout << "Cu_YZ[i].cube_top_max:   " << Cu_YZ[i].cube_top_max << std::endl;
         std::cout << "Cu_YZ[i].cube_top_min:   " << Cu_YZ[i].cube_top_min << std::endl;
         std::cout << "Cu_YZ[i].cube_right_max: " << Cu_YZ[i].cube_right_max << std::endl;
         std::cout << "Cu_YZ[i].cube_right_min: " << Cu_YZ[i].cube_A << std::endl;
         */
     }
     
     //XZ
     for (int i = 0; i < 4; i++)
     {
         next_i = i + 1;
         if (next_i == 4)
         {
             next_i = 0;
         }

         // уравнене прямой составляем, исходя из 2 точек плоскости, ограничивающих отрезок 
         // общее уравнение (х - х1)/(х2 - х1) = (у - у1)/(у2 - у1), отсюда 
         // (х - х1)(у2 - у1) = (у - у1)(х2 - х1)
         // х(у2 - у1) - х1(у2 - у1) - у(х2 - х1) + у1(х2 - х1) = 0
         // х(у2 - у1) + у(х1 - х2) + у1(х2 - х1) - х1(у2 - у1) = 0
         // таким образом A = (у2 - у1), B = (х1 - х2), C = -(x1 * A + y1 * B)
         Cu_XZ[i].cube_A =   cube_vertex[cube_projectionn_XZ_positive[next_i]].x - cube_vertex[cube_projectionn_XZ_positive[i]].x;
         Cu_XZ[i].cube_B =   cube_vertex[cube_projectionn_XZ_positive[i]].z      - cube_vertex[cube_projectionn_XZ_positive[next_i]].z;
         Cu_XZ[i].cube_C = -(cube_vertex[cube_projectionn_XZ_positive[i]].z * Cu_XZ[i].cube_A
                           + cube_vertex[cube_projectionn_XZ_positive[i]].x * Cu_XZ[i].cube_B);

         Cu_XZ[i].cube_top_max =   findMax(cube_vertex[cube_projectionn_XZ_positive[next_i]].x, cube_vertex[cube_projectionn_XZ_positive[i]].x);
         Cu_XZ[i].cube_top_min =   findMin(cube_vertex[cube_projectionn_XZ_positive[next_i]].x, cube_vertex[cube_projectionn_XZ_positive[i]].x);
         Cu_XZ[i].cube_right_max = findMax(cube_vertex[cube_projectionn_XZ_positive[next_i]].z, cube_vertex[cube_projectionn_XZ_positive[i]].z);
         Cu_XZ[i].cube_right_min = findMin(cube_vertex[cube_projectionn_XZ_positive[next_i]].z, cube_vertex[cube_projectionn_XZ_positive[i]].z);

         /*
         std::cout << "i: " << i << std::endl;
         std::cout << "Cu_XZ[i].cube_A: " <<         Cu_XZ[i].cube_A << std::endl;
         std::cout << "Cu_XZ[i].cube_B: " <<         Cu_XZ[i].cube_B << std::endl;
         std::cout << "Cu_XZ[i].cube_C: " <<         Cu_XZ[i].cube_C << std::endl;
                                                       
         std::cout << "Cu_XZ[i].cube_top_max:   " << Cu_XZ[i].cube_top_max << std::endl;
         std::cout << "Cu_XZ[i].cube_top_min:   " << Cu_XZ[i].cube_top_min << std::endl;
         std::cout << "Cu_XZ[i].cube_right_max: " << Cu_XZ[i].cube_right_max << std::endl;
         std::cout << "Cu_XZ[i].cube_right_min: " << Cu_XZ[i].cube_A << std::endl;
         */
     }

     /*
     std::cout << std::endl;
     std::cout << "cube resize end" << std::endl;
     std::cout << std::endl;
     */

    //// направляющие векторы 
    //// нижняя грань куба
    //glm::vec3 cube_directional_vector_0_1 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[1].x - cube_vertex[0].x,
    //    cube_vertex[1].y - cube_vertex[0].y,
    //    cube_vertex[1].z - cube_vertex[0].z
    //);

    //glm::vec3 cube_directional_vector_1_2 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[2].x - cube_vertex[1].x,
    //    cube_vertex[2].y - cube_vertex[1].y,
    //    cube_vertex[2].z - cube_vertex[1].z
    //);

    //glm::vec3 cube_directional_vector_3_2 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[3].x - cube_vertex[2].x,
    //    cube_vertex[3].y - cube_vertex[2].y,
    //    cube_vertex[3].z - cube_vertex[2].z
    //);

    //glm::vec3 cube_directional_vector_0_3 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[0].x - cube_vertex[3].x,
    //    cube_vertex[0].y - cube_vertex[3].y,
    //    cube_vertex[0].z - cube_vertex[3].z
    //);

    //
    ////верхняя грань куба ()
    //glm::vec3 cube_directional_vector_5_4 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[5].x - cube_vertex[4].x,
    //    cube_vertex[5].y - cube_vertex[4].y,
    //    cube_vertex[5].z - cube_vertex[4].z
    //);

    //glm::vec3 cube_directional_vector_6_5 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[6].x - cube_vertex[5].x,
    //    cube_vertex[6].y - cube_vertex[5].y,
    //    cube_vertex[6].z - cube_vertex[5].z
    //);

    //glm::vec3 cube_directional_vector_7_6 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[7].x - cube_vertex[6].x,
    //    cube_vertex[7].y - cube_vertex[6].y,
    //    cube_vertex[7].z - cube_vertex[6].z
    //);

    //glm::vec3 cube_directional_vector_4_7 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[4].x - cube_vertex[7].x,
    //    cube_vertex[4].y - cube_vertex[7].y,
    //    cube_vertex[4].z - cube_vertex[7].z
    //);

    //// боковые грани
    //glm::vec3 cube_directional_vector_0_4 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[0].x - cube_vertex[4].x,
    //    cube_vertex[0].y - cube_vertex[4].y,
    //    cube_vertex[0].z - cube_vertex[4].z
    //);

    //glm::vec3 cube_directional_vector_1_5 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[1].x - cube_vertex[5].x,
    //    cube_vertex[1].y - cube_vertex[5].y,
    //    cube_vertex[1].z - cube_vertex[5].z
    //);

    //glm::vec3 cube_directional_vector_2_6 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[2].x - cube_vertex[6].x,
    //    cube_vertex[2].y - cube_vertex[6].y,
    //    cube_vertex[2].z - cube_vertex[6].z
    //);

    //glm::vec3 cube_directional_vector_3_7 = glm::vec3 // первая цифра (0) - начало вектора, вторая (1) - конец
    //(
    //    cube_vertex[3].x - cube_vertex[7].x,
    //    cube_vertex[3].y - cube_vertex[7].y,
    //    cube_vertex[3].z - cube_vertex[7].z
    //);

}


void showCubeVertex()
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << "point " << i << " x: " << cube_vertex[i].x << " y: " << cube_vertex[i].y << " z: " << cube_vertex[i].z << std::endl;
    }

}


bool isCollisionEnable(collisionPlane &plane, bool isDebug)
{
    //float low_result = plane.result(cube_vertex[0]);// нижняя точка куба
    //float high_result = plane.result(cube_vertex[6]); // вехняя точка куба

    /*if ((low_result > 0.0f && high_result < 0.0f) || (low_result < 0.0f && high_result > 0.0f))
    {
        return true;
    }*/
    bool debug = isDebug;
    bool step_1 = false;
    
        for (int i = 0; i < 8; i++)
        {
            if (// шаг 1: проверка, заходит ли хотя бы одна точка куба в область проекций Х, У, Z плоскости коллизии
                // путем сравнения координаты точки куба с максимальными и минимальными значениями Х, У, Z
                // если точка находится в диапазоне между минимальным и максимальным значением каждой из осей, то шаг 1 выполнен
                    (
                        cube_vertex[i].x > plane.minX() && cube_vertex[i].x < plane.maxX() || plane.maxX() - plane.minX() < 0.01f
                    )
                    ||
                    (
                        cube_vertex[i].y > plane.minY() && cube_vertex[i].y < plane.maxY() || plane.maxY() - plane.minY() < 0.01f
                    )
                    ||
                    (
                        cube_vertex[i].z > plane.minZ() && cube_vertex[i].z < plane.maxZ() || plane.maxZ() - plane.minZ() < 0.01f
                    )
                )
            {

                step_1 = true;
                break;
            }
            
        }



        if (step_1 != true)
        {
            if (debug == true)
            {
                
                std::cout << "step 1 not true" << std::endl;
                
            }
            return false;
        }

        bool step_2 = false;
        
        if (debug == true)
        {
            std::cout << std::endl;
            std::cout << "step 2 begin" << std::endl;
            std::cout << std::endl;
        }

        if (step_1 == true)
        {// шаг 2: проверка, пересекает ли хотя бы одна точка куба плоскость коллизии. Для этого подставляем координаты точки куба
            // в уравнение плоскости коллизии, рассчитываем результат result. Если хотя бы одна точка куба будет с другим знаком, значит 
            // точка пересекла плоскость коллизии, шаг 2 выполнен
            // проверка на знак проверяется путем сравнения знака result текущей вершины цикла с индексом i и следующей за ней вершиной next_i = i + 1
            // поскольку вершин у нашего куба 8, а в массиве они будут храниться как от 0 до 7, то при достижении  next_i = 8 результат 
            // next_i необходимо вернуть к первой вершине, т.е. 0. Таким образом, если у result и next_result будут разные знаки - то плоскость пересечена

            for (int i = 0; i < 8; i++)
            {
                float result = plane.result(cube_vertex[i]);
                int next_i = i + 1;
                if (next_i == 8)
                {
                    next_i = 0;
                }
                float next_result = plane.result(cube_vertex[next_i]);

                if (debug == true)
                {
                    std::cout << "  vertex i "<<i<<" x: " << cube_vertex[i].x << "\tvertex next_i "<<next_i <<" x: " << cube_vertex[next_i].x << std::endl;
                    std::cout << "  vertex i "<<i<<" y: " << cube_vertex[i].y << "\tvertex next_i "<<next_i <<" y: " << cube_vertex[next_i].y << std::endl;
                    std::cout << "  vertex i "<<i<<" z: " << cube_vertex[i].z << "\tvertex next_i "<<next_i <<" z: " << cube_vertex[next_i].z << std::endl;
                }

                if ((result >= 0.0f && next_result < 0.0f) || (result <= 0.0f && next_result > 0.0f))
                {

                    step_2 = true;
                    break;
                }
            }

            //    if (result >= 0.0f)
            //    {
            //        ++upper_then_plane;
            //        if (upper_then_plane == 1)
            //        {
            //            collision_point = i;
            //        }
            //        else
            //        {
            //            collision_point = 0;
            //        }
            //        upper_index = i;
            //    }
            //    else
            //    {
            //        ++lower_then_plane;
            //        if (lower_then_plane == 1)
            //        {
            //            collision_point = i;
            //        }
            //        else
            //        {
            //            collision_point = 0;
            //        }
            //        lower_index = i;
            //    }
  
            //} 

            //if (upper_then_plane == 1) // проверка, что пересечена только одна точка выше плоскости
            //{
            //    step_2 = true;
            //}
            //else if (lower_then_plane == 1)// проверка, что пересечена только одна точка ниже плоскости
            //{
            //    step_2 = true;
            //}
            //else if(upper_then_plane != 8 || lower_then_plane != 8) // если количество точек выше\ниже плоскости не равно количеству вершин куба (8) и 
            //    // при этом количество точек выше\ниже плоскости не равно 1, то значит точек выше\ниже плоскости больше 2-х, следовательно, можно
            //    //сразу вернуть true и не выполнять 3 шаг
            //{
            //    return true;
            //}
            //else
            //{
            //    step_2 = false;
            //}
        }

        if (debug == true)
        {
            std::cout << std::endl;
            std::cout << "step 2 end" << std::endl;
            std::cout << std::endl;
        }

        int next_i;
        int next_j;
        bool YX = false;
        bool YZ = false;
        bool XZ = false;
        // коэффициенты-счетчики, которые считают, сколько результатов было больше (меньше), либо равно нулю
        // если все результаты уравнений вершин проекций куба одинакового знака(+ или -), то значит что проекция куба лежит внутри проекции плоскости
        // так как при любом раскладе векторы нормали прямых отрезков проекций будут либо повернуты от плоскости (тогда результаты будут с минусом),
        //либо в плоскость (тогда результаты будут с плюсом)
        int vertex_in_YX_plus  = 0;
        int vertex_in_YX_minus = 0;
        int vertex_in_YZ_plus = 0;
        int vertex_in_YZ_minus = 0;
        int vertex_in_XZ_plus = 0;
        int vertex_in_XZ_minus = 0;

        // если пересекает только одна точка
        if (step_2 == true)
        {// Если бы плоскость коллизии была повернута только вдоль одной из осей, то проекции на плоскость YX, YZ, XZ были бы 
            // прямоугольники (либо прямые, если плоскость параллельна одной из плоскостей проекции), ограниченной максимальным и минимальным
            // значением по каждой из осей  Х, У, Z, и, по сути, шаг 3 для таких плоскостей не требуется, так как в шаге 1 мы уже вычислили, что
            // хотя бы одна точка куба заходит в пределы плоскости коллизии, ограниченной значениями  minX-maxX, minY-maxY, minZ-maxZ, и единственное, что 
            // нам осталось понять, пересекает ли хотя бы одна точка саму плоскость, для чего выполняем шаг 2. Поскольку в случае данных плоскостей 
            //проекции будут прямоугольниками, значениями которых будут minX-maxX, minY-maxY, minZ-maxZ, и отрезки, ограничивающие эти прямоугольниками -
            // будут отрезки, параллельные осям (соответственно, где бы точка куба ни пересекла проекции, она все равно попадет в область проекции)
            // , то при выполнении шага 2 становится ясно, что
            // точка пересекла плоскость коллизии. Но в общем случае, если плоскость расположена произвольным образом и повернута произвольно вдоль
            // двух или трех осей, то проекции уже будут фигуры, находящиеся в пределах minX-maxX, minY-maxY, minZ-maxZ, но при этом отрезки, ограничивающие
            // проекции, перестают быть параллельными осям Х, У, Z, соответственно, может сложиться ситуация, когда точка заходит в область 
            // minX-maxX, minY-maxY, minZ-maxZ, в то время как другая точка куба пересекла плоскость колизии, но при этом ни одна из этих точек
            // не пересекла пространство, ограниченное отрезками коллизии. Для исключения этой ситуации вводим шаг 3. В нем мы проверяем, 
            // входит ли точка, которая пересекла плоскость коллизии, хотя бы в одну из проекций YX, YZ, XZ данной плоскости.
            // Если входит. то есть пересечение. 
            // Примечание: поскольку куб коллизии всегда выровнен по осям и никогда не поворачивается, то 
            // если если точка, которая пересекла плоскость коллизии, пересекла границы проекции, то и отрезок куба, примыкающий к данной точке, 
            // также пересек границы проекции

            // шаг 3 выполняем в несколько этапов:
            //этап 1: 
             // определяем, 

            // проекции с помощью коэффициента t y0

            /*
            if (debug == true)
            {
                std::cout << "Begin step 3" << std::endl;
            }


            // YX

            if (debug == true)
            {
                std::cout << "YX projection" << std::endl;
            }

            for (int i = 0; i < 4; i++)
            {// цикл для отрезков проекции куба
                next_i = i + 1;
                if (next_i == 4)
                {
                    next_i = 0;
                }

                if (debug == true)
                {
                    std::cout << "  cube cycle index: " << i << std::endl;
                    std::cout << "  cube vertex begin index: " << cube_projectionn_YX_positive[i] << std::endl;
                    std::cout << "  cube vertex end   index: " << cube_projectionn_YX_positive[next_i] << std::endl;
                    std::cout << "  begin.x: " << cube_vertex[cube_projectionn_YX_positive[i]].x << "\tend.x: " << cube_vertex[cube_projectionn_YX_positive[next_i]].x << std::endl;
                    std::cout << "  begin.y: " << cube_vertex[cube_projectionn_YX_positive[i]].y << "\tend.y: " << cube_vertex[cube_projectionn_YX_positive[next_i]].y << std::endl;
                    std::cout << "  begin.z: " << cube_vertex[cube_projectionn_YX_positive[i]].z << "\tend.z: " << cube_vertex[cube_projectionn_YX_positive[next_i]].z << std::endl;
                }

                for (int j = 0; j < 4; j++)
                {// цикл для отрезков проекции плоскости

                    next_j = j + 1;
                    if (next_j == 4)
                    {
                        next_j = 0;
                    }

                    if (debug == true)
                    {
                        std::cout << "    plane cycle index: " << j << std::endl;
                        std::cout << "    plane x max: " << plane.P_YX[j].plane_right_max << std::endl;
                        std::cout << "    plane x min: " << plane.P_YX[j].plane_right_min << std::endl;
                        std::cout << "    plane y max: " << plane.P_YX[j].plane_top_max << std::endl;
                        std::cout << "    plane y min: " << plane.P_YX[j].plane_top_min << std::endl;
                        std::cout << "    plane t: " << plane.P_YX[j].plane_t << std::endl;
                        std::cout << "    plane 0 coef: " << plane.P_YX[j].plane_0_coefficient << std::endl; 
                    }

                    

                    if (
                            (
                                (
                                    (cube_vertex[cube_projectionn_YX_positive[next_i]].x < plane.P_YX[j].plane_right_max)
                                    &&                   
                                    (cube_vertex[cube_projectionn_YX_positive[next_i]].x > plane.P_YX[j].plane_right_min)
                                )
                                &&
                                (
                                    ( cube_vertex[cube_projectionn_YX_positive[next_i]].y < plane.P_YX[j].plane_top_max)
                                    &&                                        
                                    (cube_vertex[cube_projectionn_YX_positive[next_i]].y > plane.P_YX[j].plane_top_min)
                                )
                            )
                            ||
                            (
                                (
                                    (cube_vertex[cube_projectionn_YX_positive[i]].x < plane.P_YX[j].plane_right_max)
                                    &&
                                    (cube_vertex[cube_projectionn_YX_positive[i]].x > plane.P_YX[j].plane_right_min)
                                )
                                &&
                                (
                                    (cube_vertex[cube_projectionn_YX_positive[i]].y < plane.P_YX[j].plane_top_max)
                                    &&            
                                    (cube_vertex[cube_projectionn_YX_positive[i]].y > plane.P_YX[j].plane_top_min)
                                )
                            )
                            
                        )
                        // проверка, что хотя бы одна из точек отрезка проекции куба входит в область ограничения отрезка проекции плоскости
                    {
                        // подставляем в уравнение a*y - t*x координаты по осям двух точек отрезка проекции куба, получаем 2 результата 
                        float result1 = plane.P_YX[j].plane_a * cube_vertex[cube_projectionn_YX_positive[next_i]].y 
                            - plane.P_YX[j].plane_t * cube_vertex[cube_projectionn_YX_positive[next_i]].x;
                        float result2 = plane.P_YX[j].plane_a * cube_vertex[cube_projectionn_YX_positive[i]].y
                            - plane.P_YX[j].plane_t * cube_vertex[cube_projectionn_YX_positive[i]].x;

                        if (debug == true)
                        {

                            std::cout << "      plane result1: " << result1 << std::endl;
                            std::cout << "      plane result2: " << result2 << std::endl;
                        }
                        // затем сравниваем результаты на предмет того, больше они или меньше, чем у0. если результаты разные по
                        // отношению к у0, то есть пересечение отрезка проекции плоскости
                        // но перед сравнением результатов исключим ситуацию, когда все коэффициенты и результаты равны нулю
                        // эта ситуация возникла бы, если бы проекция плоскости была бы точкой
                        if (result1 == 0.0f && result2 == 0.0f)
                        {

                        }
                        else if 
                            (
                                (result1 > plane.P_YX[j].plane_0_coefficient && result2 < plane.P_YX[j].plane_0_coefficient)
                                ||
                                (result1 < plane.P_YX[j].plane_0_coefficient && result2 > plane.P_YX[j].plane_0_coefficient)
                           )
                        {

                            if (debug == true)
                            {
                                std::cout << "        YX = true" << std::endl;
                            }
                            //std::cout << "YX = true" << std::endl;
                            YX = true;
                            break;
                        }
                        
                    }

                }
               
            }

            // YZ
            if (debug == true)
            {
                std::cout << "YZ projection" << std::endl;
            }

            for (int i = 0; i < 4; i++)
            {// цикл для отрезков проекции куба
                next_i = i + 1;
                if (next_i == 4)
                {
                    next_i = 0;
                }

                if (debug == true)
                {
                    std::cout << "  cube cycle index: " << i << std::endl;
                    std::cout << "  cube vertex begin index: " << cube_projectionn_YZ_positive[i] << std::endl;
                    std::cout << "  cube vertex end   index: " << cube_projectionn_YZ_positive[next_i] << std::endl;
                    std::cout << "  begin.x: " << cube_vertex[cube_projectionn_YZ_positive[i]].x << "\tend.x: " << cube_vertex[cube_projectionn_YZ_positive[next_i]].x << std::endl;
                    std::cout << "  begin.y: " << cube_vertex[cube_projectionn_YZ_positive[i]].y << "\tend.y: " << cube_vertex[cube_projectionn_YZ_positive[next_i]].y << std::endl;
                    std::cout << "  begin.z: " << cube_vertex[cube_projectionn_YZ_positive[i]].z << "\tend.z: " << cube_vertex[cube_projectionn_YZ_positive[next_i]].z << std::endl;
                }

                for (int j = 0; j < 4; j++)
                {// цикл для отрезков проекции плоскости

                    next_j = j + 1;
                    if (next_j == 4)
                    {
                        next_j = 0;
                    }

                    if (debug == true)
                    {
                        std::cout << "    plane cycle index: " << j << std::endl;
                        std::cout << "    plane z max: " <<  plane.P_YZ[j].plane_right_max << std::endl;
                        std::cout << "    plane z min: " <<  plane.P_YZ[j].plane_right_min << std::endl;
                        std::cout << "    plane y max: " <<  plane.P_YZ[j].plane_top_max << std::endl;
                        std::cout << "    plane y min: " <<  plane.P_YZ[j].plane_top_min << std::endl;
                        std::cout << "    plane t: " <<      plane.P_YZ[j].plane_t << std::endl;
                        std::cout << "    plane 0 coef: " << plane.P_YZ[j].plane_0_coefficient << std::endl;
                    }

                    
                    if (
                        (
                            (
                                (cube_vertex[cube_projectionn_YZ_positive[next_i]].z < plane.P_YZ[j].plane_right_max)
                                &&
                                (cube_vertex[cube_projectionn_YZ_positive[next_i]].z > plane.P_YZ[j].plane_right_min)
                                )
                            &&
                            (
                                (cube_vertex[cube_projectionn_YZ_positive[next_i]].y < plane.P_YZ[j].plane_top_max)
                                &&
                                (cube_vertex[cube_projectionn_YZ_positive[next_i]].y > plane.P_YZ[j].plane_top_min)
                                )
                            )
                        ||
                        (
                            (
                                (cube_vertex[cube_projectionn_YZ_positive[i]].z < plane.P_YZ[j].plane_right_max)
                                &&
                                (cube_vertex[cube_projectionn_YZ_positive[i]].z > plane.P_YZ[j].plane_right_min)
                                )
                            &&
                            (
                                (cube_vertex[cube_projectionn_YZ_positive[i]].y < plane.P_YZ[j].plane_top_max)
                                &&
                                (cube_vertex[cube_projectionn_YZ_positive[i]].y > plane.P_YZ[j].plane_top_min)
                                )
                            )
                        )
                        // проверка, что хотя бы одна из точек отрезка проекции куба входит в область ограничения отрезка проекции плоскости
                    {
                        // подставляем в уравнение a*y - t*z координаты по осям двух точек отрезка проекции куба, получаем 2 результата 
                        float result1 = plane.P_YZ[j].plane_a * cube_vertex[cube_projectionn_YZ_positive[next_i]].y
                                      - plane.P_YZ[j].plane_t * cube_vertex[cube_projectionn_YZ_positive[next_i]].z;
                        float result2 = plane.P_YZ[j].plane_a * cube_vertex[cube_projectionn_YZ_positive[i]].y
                                      - plane.P_YZ[j].plane_t * cube_vertex[cube_projectionn_YZ_positive[i]].z;

                        if (debug == true)
                        {

                            std::cout << "      plane result1: " << result1 << std::endl;
                            std::cout << "      plane result2: " << result2 << std::endl;
                        }
                        // затем сравниваем результаты на предмет того, больше они или меньше, чем у0. если результаты разные по
                        // отношению к у0, то есть пересечение отрезка проекции плоскости
                        // но перед сравнением результатов исключим ситуацию, когда все коэффициенты и результаты равны нулю
                        // эта ситуация возникла бы, если бы проекция плоскости была бы точкой
                        if (result1 == 0.0f && result2 == 0.0f)
                        {

                        }
                        else if
                            (
                                (result1 > plane.P_YZ[j].plane_0_coefficient && result2 < plane.P_YZ[j].plane_0_coefficient)
                                ||
                                (result1 < plane.P_YZ[j].plane_0_coefficient && result2 > plane.P_YZ[j].plane_0_coefficient)
                                )
                        {
                            if (debug == true)
                            {
                                std::cout << "        YZ = true" << std::endl;
                            }

                            //std::cout << "YZ = true" << std::endl;
                            YZ = true;
                            break;
                        }

                    }

                }

            }

            // XZ
            if (debug == true)
            {
                std::cout << "XZ projection" << std::endl;
            }

            for (int i = 0; i < 4; i++)
            {// цикл для отрезков проекции куба
                next_i = i + 1;
                if (next_i == 4)
                {
                    next_i = 0;
                }

                if (debug == true)
                {
                    std::cout << "  cube cycle index: " << i << std::endl;
                    std::cout << "  cube vertex begin index: " << cube_projectionn_XZ_positive[i] << std::endl;
                    std::cout << "  cube vertex end   index: " << cube_projectionn_XZ_positive[next_i] << std::endl;
                    std::cout << "  begin.x: " << cube_vertex[cube_projectionn_XZ_positive[i]].x << "\tend.x: " << cube_vertex[cube_projectionn_XZ_positive[next_i]].x << std::endl;
                    std::cout << "  begin.y: " << cube_vertex[cube_projectionn_XZ_positive[i]].y << "\tend.y: " << cube_vertex[cube_projectionn_XZ_positive[next_i]].y << std::endl;
                    std::cout << "  begin.z: " << cube_vertex[cube_projectionn_XZ_positive[i]].z << "\tend.z: " << cube_vertex[cube_projectionn_XZ_positive[next_i]].z << std::endl;
                }

                for (int j = 0; j < 4; j++)
                {// цикл для отрезков проекции плоскости

                    next_j = j + 1;
                    if (next_j == 4)
                    {
                        next_j = 0;
                    }

                    if (debug == true)
                    {
                        std::cout << "    plane cycle index: " << j << std::endl;
                        std::cout << "    plane z max: " <<  plane.P_XZ[j].plane_right_max << std::endl;
                        std::cout << "    plane z min: " <<  plane.P_XZ[j].plane_right_min << std::endl;
                        std::cout << "    plane y max: " <<  plane.P_XZ[j].plane_top_max << std::endl;
                        std::cout << "    plane y min: " <<  plane.P_XZ[j].plane_top_min << std::endl;
                        std::cout << "    plane t: " <<      plane.P_XZ[j].plane_t << std::endl;
                        std::cout << "    plane 0 coef: " << plane.P_XZ[j].plane_0_coefficient << std::endl;
                    }

                    
                    if (
                        (
                            (
                                (cube_vertex[cube_projectionn_XZ_positive[next_i]].z < plane.P_XZ[j].plane_right_max)
                                &&
                                (cube_vertex[cube_projectionn_XZ_positive[next_i]].z > plane.P_XZ[j].plane_right_min)
                                )
                            &&
                            (
                                (cube_vertex[cube_projectionn_XZ_positive[next_i]].x < plane.P_XZ[j].plane_top_max)
                                &&
                                (cube_vertex[cube_projectionn_XZ_positive[next_i]].x > plane.P_XZ[j].plane_top_min)
                                )
                            )
                        ||
                        (
                            (
                                (cube_vertex[cube_projectionn_XZ_positive[i]].z < plane.P_XZ[j].plane_right_max)
                                &&
                                (cube_vertex[cube_projectionn_XZ_positive[i]].z > plane.P_XZ[j].plane_right_min)
                                )
                            &&
                            (
                                (cube_vertex[cube_projectionn_XZ_positive[i]].x < plane.P_XZ[j].plane_top_max)
                                &&
                                (cube_vertex[cube_projectionn_XZ_positive[i]].x > plane.P_XZ[j].plane_top_min)
                                )
                            )
                        )
                        // проверка, что хотя бы одна из точек отрезка проекции куба входит в область ограничения отрезка проекции плоскости
                    {
                        // подставляем в уравнение a*y - t*z координаты по осям двух точек отрезка проекции куба, получаем 2 результата 
                        float result1 = plane.P_XZ[j].plane_a * cube_vertex[cube_projectionn_XZ_positive[next_i]].x
                                      - plane.P_XZ[j].plane_t * cube_vertex[cube_projectionn_XZ_positive[next_i]].z;
                        float result2 = plane.P_XZ[j].plane_a * cube_vertex[cube_projectionn_XZ_positive[i]].x
                                      - plane.P_XZ[j].plane_t * cube_vertex[cube_projectionn_XZ_positive[i]].z;

                        if (debug == true)
                        {

                            std::cout << "      plane result1: " << result1 << std::endl;
                            std::cout << "      plane result2: " << result2 << std::endl;
                        }
                        // затем сравниваем результаты на предмет того, больше они или меньше, чем у0. если результаты разные по
                        // отношению к у0, то есть пересечение отрезка проекции плоскости
                        // но перед сравнением результатов исключим ситуацию, когда все коэффициенты и результаты равны нулю
                        // эта ситуация возникла бы, если бы проекция плоскости была бы точкой
                        if (result1 == 0.0f && result2 == 0.0f)
                        {

                        }
                        else if
                            (
                                (result1 > plane.P_XZ[j].plane_0_coefficient && result2 < plane.P_XZ[j].plane_0_coefficient)
                                ||
                                (result1 < plane.P_XZ[j].plane_0_coefficient && result2 > plane.P_XZ[j].plane_0_coefficient)
                                )
                        {
                            if (debug == true)
                            {
                                std::cout << "        XZ = true" << std::endl;
                            }
                            //std::cout << "XZ = true" << std::endl;
                            XZ = true;
                            break;
                        }

                    }

                }

            }

            if (debug == true)
            {
                std::cout << "YX: " << YX << std::endl;
                std::cout << "YZ: " << YZ << std::endl;
                std::cout << "XZ: " << XZ << std::endl;
                std::cout << std::endl;
                std::cout << "step 3 end" << XZ << std::endl;
                std::cout  << std::endl;
            }

            if (YX == true && YZ == true && XZ == true)
            {
                return true;
            }
            */

            // проекции с помощью коэфиициентов A,B,C
 
             if (debug == true)
             {
                 std::cout << "Begin step 3" << std::endl;
             }
             
             
             // YX
             
             if (debug == true)
             {
                 std::cout << "YX projection" << std::endl;
             }
             
             for (int i = 0; i < 4; i++)
             {// цикл для отрезков проекции куба
                 next_i = i + 1;
                 if (next_i == 4)
                 {
                     next_i = 0;
                 }
             
                 if (debug == true)
                 {
                     std::cout << "  cube cycle index: " << i << std::endl;
                     std::cout << "  cube vertex begin index: " << cube_projectionn_YX_positive[i] << std::endl;
                     std::cout << "  cube vertex end   index: " << cube_projectionn_YX_positive[next_i] << std::endl;
                     std::cout << "  cube proj A: " << Cu_YX[i].cube_A << std::endl;
                     std::cout << "  cube proj B: " << Cu_YX[i].cube_B << std::endl;
                     std::cout << "  cube proj C: " << Cu_YX[i].cube_C << std::endl;
                     std::cout << "  begin.x: " << cube_vertex[cube_projectionn_YX_positive[i]].x << "\tend.x: " << cube_vertex[cube_projectionn_YX_positive[next_i]].x << std::endl;
                     std::cout << "  begin.y: " << cube_vertex[cube_projectionn_YX_positive[i]].y << "\tend.y: " << cube_vertex[cube_projectionn_YX_positive[next_i]].y << std::endl;
                     std::cout << "  begin.z: " << cube_vertex[cube_projectionn_YX_positive[i]].z << "\tend.z: " << cube_vertex[cube_projectionn_YX_positive[next_i]].z << std::endl;
                 }
             
                 for (int j = 0; j < 4; j++)
                 {// цикл для отрезков проекции плоскости
             
                     next_j = j + 1;
                     if (next_j == 4)
                     {
                         next_j = 0;
                     }
             
                     if (debug == true)
                     {
                         std::cout << "    plane cycle index: " << j << std::endl;
                         std::cout << "    plane x max: " <<  plane.Pl_YX[j].plane_right_max << std::endl;
                         std::cout << "    plane x min: " <<  plane.Pl_YX[j].plane_right_min << std::endl;
                         std::cout << "    plane y max: " <<  plane.Pl_YX[j].plane_top_max << std::endl;
                         std::cout << "    plane y min: " <<  plane.Pl_YX[j].plane_top_min << std::endl;
                         std::cout << "    plane A: " <<      plane.Pl_YX[j].plane_A << std::endl;
                         std::cout << "    plane B: " <<      plane.Pl_YX[j].plane_B << std::endl;
                         std::cout << "    plane C: " <<      plane.Pl_YX[j].plane_C << std::endl;
                     }

                     //if ((plane.Pl_YX[j].plane_A == 0.0f && plane.Pl_YX[j].plane_B == 0.0) || (Cu_YX[i].cube_A == 0.0f && Cu_YX[i].cube_B == 0.0f))
                     //{// проверка, проецируется ли отрезок проеции куба/плоскости в точку (тогда коэф-ты при А и В будут равны нулю)
                     //    // если это так, то просто пропускаем этот ход цикла
                     //    continue;
                     //}
                     float p1, p2, p3;

                     p1 = plane.Pl_YX[j].plane_A / Cu_YX[i].cube_A;
                     p2 = plane.Pl_YX[j].plane_B / Cu_YX[i].cube_B;
                     p3 = plane.Pl_YX[j].plane_C / Cu_YX[i].cube_C;

                     
             
                     if (
                         (p1 - p2 < 0.01f && p1 - p2 > -0.01f) && (p1 - p3 < 0.01f && p1 - p3 > -0.01f)
                         )
                     {// проверка, совпадают ли прямые друг с другом (если p1, p2, p3 одинаковые, то совпадают и есть пересечение)
                         YX = true;
                         break;
                     }
                     else if (
                              (p1 - p2 < 0.01f && p1 - p2 > -0.01f) && (p1 != p3  && p2 != p3 )
                              )
                     {// проверка, параллельны ли прямые друг  другу (если p1, p2 одинаковые, а p3 отличается,то они параллельны и никогда не пересекутся
                         //следовательно, пересечения нет)
                         YX = false;
                     }
                     else
                     {// если ни одно из предыдущих условий не было выполнено, то значит p1, p2, p3 разные и прямые пересекаются
                         //найдем точку пересечения

                         float A = plane.Pl_YX[j].plane_A * Cu_YX[i].cube_C - plane.Pl_YX[j].plane_C * Cu_YX[i].cube_A;
                         float B = plane.Pl_YX[j].plane_B * Cu_YX[i].cube_A - plane.Pl_YX[j].plane_A * Cu_YX[i].cube_B;

                         float C = plane.Pl_YX[j].plane_B * Cu_YX[i].cube_C - plane.Pl_YX[j].plane_C * Cu_YX[i].cube_B;

                         float point_y =  A / B;
                         float point_x = -C / B;

                         // подставяем координаты точки куба в уравнение прямой отрезка плоскости A*x+B*y+C
                         float result = plane.Pl_YX[j].plane_A * cube_vertex[cube_projectionn_YX_positive[i]].x
                             + plane.Pl_YX[j].plane_B * cube_vertex[cube_projectionn_YX_positive[i]].y + plane.Pl_YX[j].plane_C;

                         // знак результата приплюсовываем соответствующему счетчику
                         if (result >= 0.0f)
                         {
                             ++vertex_in_YX_plus;
                         }
                         if (result <= 0.0f)
                         {
                             ++vertex_in_YX_minus;
                         }

                         if (debug == true)
                         {
                             std::cout << "           point_y: " << point_y << std::endl;
                             std::cout << "           point_x: " << point_x << std::endl;
                             std::cout << "           result:  " << result << std::endl;
                         }

                         if (// проверка, лежит ли точка пересечения в пределах отрезков проекций куба и плоскости
                                  (
                                      //(point_y <plane.Pl_YX[j].plane_right_max) && (point_y > plane.Pl_YX[j].plane_right_min)
                                      //&& 
                                      (point_y < Cu_YX[i].cube_top_max) && (point_y > Cu_YX[i].cube_top_min)
                                      ||
                                      (point_x < Cu_YX[i].cube_right_max) && (point_x > Cu_YX[i].cube_right_min)
                                  )
                                  &&
                                  (
                                      (point_y < plane.Pl_YX[j].plane_top_max) && (point_y > plane.Pl_YX[j].plane_top_min)
                                      ||
                                      (point_x < plane.Pl_YX[j].plane_right_max) && (point_x > plane.Pl_YX[j].plane_right_min)
                                      //&&
                                      //(point_x < Cu_YX[i].cube_right_max) && (point_x > Cu_YX[i].cube_right_min)
                                  )
                             )
                         {
                             if (debug == true)
                             {
                                 std::cout << "YX true" << std::endl;
                             }

                             YX = true;
                             break;
                         }

                     }
                     
                  
             }

                 if (i == 3)
                 {
                     if (debug == true)
                     {
                         std::cout << "  vertex_in_YX_plus:  " << vertex_in_YX_plus << std::endl;
                         std::cout << "  vertex_in_YX_minus: " << vertex_in_YX_minus << std::endl;
                     }

                     if (vertex_in_YX_plus == (4 * 4) || vertex_in_YX_minus == (4 * 4))
                     {// Если для всех вершин куба знак результатов уравнений одинаковый, то значит проекция куба находится внутри проекции плоскости
                         // следовательно YX = true
                         // примечание - здесь идет проверка каждой вершины куба к каждому отрезку плоскости, т.е. 
                         // необходимо, чтобы корректно отрабатывало условие, надо, чтобы каждая вершина (всего их 4)
                         // была с одинаковым знаком для каждого отрезка (из тоже 4), итого 4 * 4 = 16
                         YX = true;
                     }
                 }
             

             }
             
             //std::cout << std::endl;
             // YZ

             if (debug == true)
             {
                 std::cout << "YZ projection" << std::endl;
             }

             for (int i = 0; i < 4; i++)
             {// цикл для отрезков проекции куба
                 next_i = i + 1;
                 if (next_i == 4)
                 {
                     next_i = 0;
                 }

                 if (debug == true)
                 {
                     std::cout << "  cube cycle index: " << i << std::endl;
                     std::cout << "  cube vertex begin index: " << cube_projectionn_YZ_positive[i] << std::endl;
                     std::cout << "  cube vertex end   index: " << cube_projectionn_YZ_positive[next_i] << std::endl;
                     std::cout << "  cube proj A: " << Cu_YZ[i].cube_A << std::endl;
                     std::cout << "  cube proj B: " << Cu_YZ[i].cube_B << std::endl;
                     std::cout << "  cube proj C: " << Cu_YZ[i].cube_C << std::endl;
                     std::cout << "  begin.x: " << cube_vertex[cube_projectionn_YZ_positive[i]].x << "\tend.x: " << cube_vertex[cube_projectionn_YZ_positive[next_i]].x << std::endl;
                     std::cout << "  begin.y: " << cube_vertex[cube_projectionn_YZ_positive[i]].y << "\tend.y: " << cube_vertex[cube_projectionn_YZ_positive[next_i]].y << std::endl;
                     std::cout << "  begin.z: " << cube_vertex[cube_projectionn_YZ_positive[i]].z << "\tend.z: " << cube_vertex[cube_projectionn_YZ_positive[next_i]].z << std::endl;
                 }

                 for (int j = 0; j < 4; j++)
                 {// цикл для отрезков проекции плоскости

                     next_j = j + 1;
                     if (next_j == 4)
                     {
                         next_j = 0;
                     }

                     if (debug == true)
                     {
                         std::cout << "    plane cycle index: " << j << std::endl;
                         std::cout << "    plane x max: " << plane.Pl_YZ[j].plane_right_max << std::endl;
                         std::cout << "    plane x min: " << plane.Pl_YZ[j].plane_right_min << std::endl;
                         std::cout << "    plane y max: " << plane.Pl_YZ[j].plane_top_max << std::endl;
                         std::cout << "    plane y min: " << plane.Pl_YZ[j].plane_top_min << std::endl;
                         std::cout << "    plane A: " <<     plane.Pl_YZ[j].plane_A << std::endl;
                         std::cout << "    plane B: " <<     plane.Pl_YZ[j].plane_B << std::endl;
                         std::cout << "    plane C: " <<     plane.Pl_YZ[j].plane_C << std::endl;
                     }

                     //if ((plane.Pl_YZ[j].plane_A == 0.0f && plane.Pl_YZ[j].plane_B == 0.0) || (Cu_YZ[i].cube_A == 0.0f && Cu_YZ[i].cube_B == 0.0f))
                     //{// проверка, проецируется ли отрезок проеции куба/плоскости в точку (тогда коэф-ты при А и В будут равны нулю)
                     //    // если это так, то просто пропускаем этот ход цикла
                     //    continue;
                     //}
                     float p1, p2, p3;

                     p1 = plane.Pl_YZ[j].plane_A / Cu_YZ[i].cube_A;
                     p2 = plane.Pl_YZ[j].plane_B / Cu_YZ[i].cube_B;
                     p3 = plane.Pl_YZ[j].plane_C / Cu_YZ[i].cube_C;

                     if (
                         (p1 - p2 < 0.01f && p1 - p2 > -0.01f) && (p1 - p3 < 0.01f && p1 - p3 > -0.01f)
                         )
                     {// проверка, совпадают ли прямые друг с другом (если p1, p2, p3 одинаковые, то совпадают и есть пересечение)
                         YZ = true;
                         break;
                     }
                     else if (
                         (p1 - p2 < 0.01f && p1 - p2 > -0.01f) && (p1 != p3 && p2 != p3)
                         )
                     {// проверка, параллельны ли прямые друг  другу (если p1, p2 одинаковые, а p3 отличается,то они параллельны и никогда не пересекутся
                         //следовательно, пересечения нет)
                         YZ = false;
                     }
                     else
                     {// если ни одно из предыдущих условий не было выполнено, то значит p1, p2, p3 разные и прямые пересекаются
                         //найдем точку пересечения

                         float A = plane.Pl_YZ[j].plane_A * Cu_YZ[i].cube_C - plane.Pl_YZ[j].plane_C * Cu_YZ[i].cube_A;
                         float B = plane.Pl_YZ[j].plane_B * Cu_YZ[i].cube_A - plane.Pl_YZ[j].plane_A * Cu_YZ[i].cube_B;
                         float C = plane.Pl_YZ[j].plane_B * Cu_YZ[i].cube_C - plane.Pl_YZ[j].plane_C * Cu_YZ[i].cube_B;

                         float point_y =  A / B;
                         float point_x = -C / B;

                         float result = plane.Pl_YZ[j].plane_A * cube_vertex[cube_projectionn_YZ_positive[i]].z
                             + plane.Pl_YZ[j].plane_B * cube_vertex[cube_projectionn_YZ_positive[i]].y + plane.Pl_YZ[j].plane_C;

                         // знак результата приплюсовываем соответствующему счетчику
                         if (result >= 0.0f)
                         {
                             ++vertex_in_YZ_plus;
                         }
                         if (result <= 0.0f)
                         {
                             ++vertex_in_YZ_minus;
                         }

                         if (debug == true)
                         {
                             std::cout << "           point_y: " << point_y << std::endl;
                             std::cout << "           point_z: " << point_x << std::endl;
                             std::cout << "           result:  " << result << std::endl;
                         }

                         if (// проверка, лежит ли точка пересечения в пределах отрезков проекций куба и плоскости
                             (
                                 //(point_y <plane.Pl_YX[j].plane_right_max) && (point_y > plane.Pl_YX[j].plane_right_min)
                                 //&& 
                                 (point_y < Cu_YZ[i].cube_top_max) && (point_y > Cu_YZ[i].cube_top_min)
                                 ||
                                 (point_x < Cu_YZ[i].cube_right_max) && (point_x > Cu_YZ[i].cube_right_min)
                                 )
                             &&
                             (
                                 (point_y < plane.Pl_YZ[j].plane_top_max) && (point_y > plane.Pl_YZ[j].plane_top_min)
                                 ||
                                 (point_x < plane.Pl_YZ[j].plane_right_max) && (point_x > plane.Pl_YZ[j].plane_right_min)
                                 //&&
                                 //(point_x < Cu_YX[i].cube_right_max) && (point_x > Cu_YX[i].cube_right_min)
                                 )
                             )
                         {
                             if (debug == true)
                             {
                                 std::cout << "YZ true" << std::endl;
                             }

                             YZ = true;
                             break;
                         }
                     }


                 }

                 if (i == 3)
                 {
                     if (debug == true)
                     {
                         std::cout << "  vertex_in_YZ_plus:  " << vertex_in_YZ_plus << std::endl;
                         std::cout << "  vertex_in_YZ_minus: " << vertex_in_YZ_minus << std::endl;
                     }

                     if (vertex_in_YZ_plus == (4 * 4)  || vertex_in_YZ_minus == (4 *4))
                     {// Если для всех вершин куба знак результатов уравнений одинаковый, то значит проекция куба находится внутри проекции плоскости
                         // следовательно YX = true
                         YZ = true;
                     }
                 }
             }

             //std::cout << std::endl;
             // XZ

             if (debug == true)
             {
                 std::cout << "XZ projection" << std::endl;
             }

             for (int i = 0; i < 4; i++)
             {// цикл для отрезков проекции куба
                 next_i = i + 1;
                 if (next_i == 4)
                 {
                     next_i = 0;
                 }

                 if (debug == true)
                 {
                     std::cout << "  cube cycle index: " << i << std::endl;
                     std::cout << "  cube vertex begin index: " << cube_projectionn_XZ_positive[i] << std::endl;
                     std::cout << "  cube vertex end   index: " << cube_projectionn_XZ_positive[next_i] << std::endl;
                     std::cout << "  cube proj A: " << Cu_XZ[i].cube_A << std::endl;
                     std::cout << "  cube proj B: " << Cu_XZ[i].cube_B << std::endl;
                     std::cout << "  cube proj C: " << Cu_XZ[i].cube_C << std::endl;
                     std::cout << "  begin.x: " <<     cube_vertex[cube_projectionn_XZ_positive[i]].x << "\tend.x: " << cube_vertex[cube_projectionn_XZ_positive[next_i]].x << std::endl;
                     std::cout << "  begin.y: " <<     cube_vertex[cube_projectionn_XZ_positive[i]].y << "\tend.y: " << cube_vertex[cube_projectionn_XZ_positive[next_i]].y << std::endl;
                     std::cout << "  begin.z: " <<     cube_vertex[cube_projectionn_XZ_positive[i]].z << "\tend.z: " << cube_vertex[cube_projectionn_XZ_positive[next_i]].z << std::endl;
                 }

                 for (int j = 0; j < 4; j++)
                 {// цикл для отрезков проекции плоскости

                     next_j = j + 1;
                     if (next_j == 4)
                     {
                         next_j = 0;
                     }

                     if (debug == true)
                     {
                         std::cout << "    plane cycle index: " << j << std::endl;
                         std::cout << "    plane x max: " << plane.Pl_XZ[j].plane_right_max << std::endl;
                         std::cout << "    plane x min: " << plane.Pl_XZ[j].plane_right_min << std::endl;
                         std::cout << "    plane y max: " << plane.Pl_XZ[j].plane_top_max << std::endl;
                         std::cout << "    plane y min: " << plane.Pl_XZ[j].plane_top_min << std::endl;
                         std::cout << "    plane A: " <<     plane.Pl_XZ[j].plane_A << std::endl;
                         std::cout << "    plane B: " <<     plane.Pl_XZ[j].plane_B << std::endl;
                         std::cout << "    plane C: " <<     plane.Pl_XZ[j].plane_C << std::endl;
                     }

                     //if ((plane.Pl_XZ[j].plane_A == 0.0f && plane.Pl_XZ[j].plane_B == 0.0) || (Cu_XZ[i].cube_A == 0.0f && Cu_XZ[i].cube_B == 0.0f))
                     //{// проверка, проецируется ли отрезок проеции куба/плоскости в точку (тогда коэф-ты при А и В будут равны нулю)
                     //    // если это так, то просто пропускаем этот ход цикла
                     //    continue;
                     //}
                     float p1, p2, p3;

                     p1 = plane.Pl_XZ[j].plane_A / Cu_XZ[i].cube_A;
                     p2 = plane.Pl_XZ[j].plane_B / Cu_XZ[i].cube_B;
                     p3 = plane.Pl_XZ[j].plane_C / Cu_XZ[i].cube_C;

                     if (
                         (p1 - p2 < 0.01f && p1 - p2 > -0.01f) && (p1 - p3 < 0.01f && p1 - p3 > -0.01f)
                         )
                     {// проверка, совпадают ли прямые друг с другом (если p1, p2, p3 одинаковые, то совпадают и есть пересечение)
                         XZ = true;
                         break;
                     }
                     else if (
                         (p1 - p2 < 0.01f && p1 - p2 > -0.01f) && (p1 != p3 && p2 != p3)
                         )
                     {// проверка, параллельны ли прямые друг  другу (если p1, p2 одинаковые, а p3 отличается,то они параллельны и никогда не пересекутся
                         //следовательно, пересечения нет)
                         XZ = false;
                     }
                     else
                     {// если ни одно из предыдущих условий не было выполнено, то значит p1, p2, p3 разные и прямые пересекаются
                         //найдем точку пересечения

                         float A = plane.Pl_XZ[j].plane_A * Cu_XZ[i].cube_C - plane.Pl_XZ[j].plane_C * Cu_XZ[i].cube_A;
                         float B = plane.Pl_XZ[j].plane_B * Cu_XZ[i].cube_A - plane.Pl_XZ[j].plane_A * Cu_XZ[i].cube_B;
                         float C = plane.Pl_XZ[j].plane_B * Cu_XZ[i].cube_C - plane.Pl_XZ[j].plane_C * Cu_XZ[i].cube_B;

                         float point_y =  A / B;
                         float point_x = -C / B;

                         float result = plane.Pl_XZ[j].plane_A * cube_vertex[cube_projectionn_XZ_positive[i]].z
                             + plane.Pl_XZ[j].plane_B * cube_vertex[cube_projectionn_XZ_positive[i]].x + plane.Pl_XZ[j].plane_C;

                         // знак результата приплюсовываем соответствующему счетчику
                         if (result >= 0.0f)
                         {
                             ++vertex_in_XZ_plus;
                         }
                         if (result <= 0.0f)
                         {
                             ++vertex_in_XZ_minus;
                         }

                         if (debug == true)
                         {
                             std::cout << "           point_y: " << point_y << std::endl;
                             std::cout << "           point_z: " << point_x << std::endl;
                             std::cout << "           result:  " << result << std::endl;
                         }

                         if (// проверка, лежит ли точка пересечения в пределах отрезков проекций куба и плоскости
                             (
                                 //(point_y <plane.Pl_YX[j].plane_right_max) && (point_y > plane.Pl_YX[j].plane_right_min)
                                 //&& 
                                 (point_y < Cu_XZ[i].cube_top_max) && (point_y > Cu_XZ[i].cube_top_min)
                                 ||
                                 (point_x < Cu_XZ[i].cube_right_max) && (point_x > Cu_XZ[i].cube_right_min)
                                 )
                             &&
                             (
                                 (point_y < plane.Pl_XZ[j].plane_top_max) && (point_y > plane.Pl_XZ[j].plane_top_min)
                                 ||
                                 (point_x < plane.Pl_XZ[j].plane_right_max) && (point_x > plane.Pl_XZ[j].plane_right_min)
                                 //&&
                                 //(point_x < Cu_YX[i].cube_right_max) && (point_x > Cu_YX[i].cube_right_min)
                                 )
                             )
                         {
                             if (debug == true)
                             {
                                 std::cout << "XZ true" << std::endl;
                             }

                             XZ = true;
                             break;
                         }
                     }


                 }

                 if (i == 3)
                 {
                     if (debug == true)
                     {
                         std::cout << "  vertex_in_XZ_plus:  " << vertex_in_XZ_plus << std::endl;
                         std::cout << "  vertex_in_XZ_minus: " << vertex_in_XZ_minus << std::endl;
                     }

                     if (vertex_in_XZ_plus == (4 * 4) || vertex_in_XZ_minus == (4 * 4))
                     {// Если для всех вершин куба знак результатов уравнений одинаковый, то значит проекция куба находится внутри проекции плоскости
                         // следовательно YX = true
                         XZ = true;
                     }
                 }
             }


             if (debug == true)
             {
                 std::cout << "YX: " << YX << std::endl;
                 std::cout << "YZ: " << YZ << std::endl;
                 std::cout << "XZ: " << XZ << std::endl;
                 std::cout << std::endl;
                 std::cout << "step 3 end" << XZ << std::endl;
                 std::cout << std::endl;
             }
             
             if (YX == true && YZ == true && XZ == true)
             {
                 return true;
             }



            // метод для отрезков, с коэффициентами t y(0)

            /*bool isOnProjection;

            for (int i = 0; i < 8; i++)
            {
                isOnProjection = plane.isInProjectionOfPlane(cube_vertex[i]);
                if (isOnProjection == true)
                {
                    return true;
                }
            }*/

           /* bool YX = false;
            bool YZ = false;
            bool XZ = false;*/

            //// плоскость Y(X)
            //for (int i = 0; i < 4; i++)
            //{
            //    int start_point = plane.PlaneProjectionYX(cube_vertex[cube_projectionn_YX_positive[i]]);
            //    int next_i = i + 1;
            //    if (next_i == 4)
            //    {
            //        next_i = 0;
            //    }
            //    int finish_point = plane.PlaneProjectionYX(cube_vertex[cube_projectionn_YX_positive[next_i]]);

            //    if (
            //        (start_point == 0 && finish_point == 0)
            //        ||
            //        (start_point== 1 && finish_point == 2)
            //        ||
            //        (start_point == 2 && finish_point == 1)
            //        ||
            //        (start_point == 0 && (finish_point == 1 || finish_point == 2 || finish_point == 3))
            //        ||
            //        (finish_point == 0 && (start_point == 1 || start_point == 2 || start_point == 3))
            //        )
            //    {
            //        YX = true;
            //        break;
            //    }
            //    
            //}

            //// плоскость Y(Z)
            //for (int i = 0; i < 4; i++)
            //{
            //    int start_point = plane.PlaneProjectionYZ(cube_vertex[cube_projectionn_YZ_positive[i]]);
            //    int next_i = i + 1;
            //    if (next_i == 4)
            //    {
            //        next_i = 0;
            //    }
            //    int finish_point = plane.PlaneProjectionYZ(cube_vertex[cube_projectionn_YZ_positive[next_i]]);

            //    if (
            //        (start_point == 0 && finish_point == 0)
            //        ||
            //        (start_point == 1 && finish_point == 2)
            //        ||
            //        (start_point == 2 && finish_point == 1)
            //        ||
            //        (start_point == 0 && (finish_point == 1 || finish_point == 2 || finish_point == 3))
            //        ||
            //        (finish_point == 0 && (start_point == 1 || start_point == 2 || start_point == 3))
            //        )
            //    {
            //        YZ = true;
            //        break;
            //    }
            //    
            //}

            //// плоскость X(Z)
            //for (int i = 0; i < 4; i++)
            //{


            //    int start_point = plane.PlaneProjectionXZ(cube_vertex[cube_projectionn_XZ_positive[i]]);
            //    int next_i = i + 1;
            //    if (next_i == 4)
            //    {
            //        next_i = 0;
            //    }
            //    int finish_point = plane.PlaneProjectionXZ(cube_vertex[cube_projectionn_XZ_positive[next_i]]);

            //    std::cout << " cube_projectionn_XZ_positive[i]: " << cube_projectionn_XZ_positive[i] << " cube_projectionn_XZ_positive[next_i]: " << cube_projectionn_XZ_positive[next_i] << std::endl;
            //    std::cout << " start_point: " << start_point << " finish_point: " << finish_point << std::endl;
            //    std::cout << std::endl;
            //    if (
            //        (start_point == 0 && finish_point == 0)
            //        ||
            //        (start_point == 1 && finish_point == 2)
            //        ||
            //        (start_point == 2 && finish_point == 1)
            //        ||
            //        (start_point == 0 && (finish_point == 1 || finish_point == 2 || finish_point == 3))
            //        ||
            //        (finish_point == 0 && (start_point == 1 || start_point == 2 || start_point == 3))
            //        )
            //    {
            //        XZ = true;
            //        break;
            //    }
            //    
            //}
            ////std::cout << " YX: " << YX << " YZ: " << YZ << " XZ: " << XZ << std::endl;
            //if (YX == true && YZ == true && XZ == true)
            //{
            //    return true;
            //}
            //std::cout << std::endl;
            //for (int i = 0; i < 8; i++)
            //{
            //    int next_i = i + 1;
            //    if (next_i == 8)
            //    {
            //        next_i = 0;
            //    }

            //    for (int j = 0; j < 4; j++)
            //    {
            //        float result = plane.isOnProjectionYX(cube_vertex[i],j);
            //        float next_result = plane.isOnProjectionYX(cube_vertex[next_i], j);

            //        std::cout << "for P_YX j = " << j << "\t vertex "<< i <<" result: " << result << std::endl;

            //        /*if (i == 5)
            //        {
            //            std::cout << "for P_YX j = " << j << "\tXZ vertex 5 result: " << result << std::endl;
            //        }*/
            //        /*if ((result >= 0.0f && next_result < 0.0f) || (result <= 0.0f && next_result > 0.0f))
            //        {

            //            YX = true;
            //            break;
            //        }*/
            //    }
            //}


            ///*if (YX == false)
            //{
            //    return false;
            //}*/
            //std::cout << std::endl;
            //for (int i = 0; i < 8; i++)
            //{
            //    int next_i = i + 1;
            //    if (next_i == 8)
            //    {
            //        next_i = 0;
            //    }

            //    for (int j = 0; j < 4; j++)
            //    {
            //        float result = plane.isOnProjectionYZ(cube_vertex[i], j);
            //        float next_result = plane.isOnProjectionYZ(cube_vertex[next_i], j);

            //        std::cout << "for P_YZ j = " << j << "\t vertex "<< i <<" result: " << result << std::endl;

            //        /*if (i == 5)
            //        {
            //            std::cout << "for P_YZ j = " << j << "\tXZ vertex 5 result: " << result << std::endl;
            //        }*/
            //        /*if ((result >= 0.0f && next_result < 0.0f) || (result <= 0.0f && next_result > 0.0f))
            //        {

            //            YZ = true;
            //            break;
            //        }*/
            //    }
            //}

            ///*if (YZ == false)
            //{
            //    return false;
            //}*/
            //std::cout << std::endl;
            //for (int i = 0; i < 8; i++)
            //{
            //    int next_i = i + 1;
            //    if (next_i == 8)
            //    {
            //        next_i = 0;
            //    }

            //    for (int j = 0; j < 4; j++)
            //    {
            //        float result = plane.isOnProjectionXZ(cube_vertex[i], j);
            //        float next_result = plane.isOnProjectionXZ(cube_vertex[next_i], j);

            //        std::cout << "for P_XZ j = " << j << "\t vertex " <<  i << " result: " << result << std::endl;

            //        /*if (i == 5)
            //        {
            //            std::cout << "for P_XZ j = " << j << "\tXZ vertex 5 result: " << result << std::endl;
            //        }*/


            //        /*if ((result >= 0.0f && next_result < 0.0f) || (result <= 0.0f && next_result > 0.0f))
            //        {

            //            XZ = true; 
            //            break;
            //        }*/
            //    }
            //}
            //std::cout << std::endl;
            ///*if (XZ == false)
            //{
            //    return false;
            //}
            //else
            //{
            //    return true;
            //}*/
        }




        /*float result = plane.result(cube_vertex[i]);
        int next_i = i+1;
        if (next_i == 8)
        //{
        //    next_i = 0;
        //}
        float next_result = plane.result(cube_vertex[next_i]);

        if ((result >= 0.0f && next_result <0.0f) || (result <= 0.0f && next_result > 0.0f))
        {
            

        }*/

        //if (result >= -0.05f && result <= 0.05f)
        //{
        //    if (   ((cube_vertex[i].x > plane.minX() && cube_vertex[i].x < plane.maxX()) 
        //             //|| plane.minX() == plane.maxX()
        //             || plane.maxX() - plane.minX() < 0.1f)

        //        && ((cube_vertex[i].y > plane.minY() && cube_vertex[i].y < plane.maxY()) 
        //             //|| plane.minY() == plane.maxY() 
        //             || plane.maxY() - plane.minY() < 0.1f)

        //        && ((cube_vertex[i].z > plane.minZ() && cube_vertex[i].z < plane.maxZ())
        //             //|| plane.minZ() == plane.maxZ()
        //             || plane.maxZ() - plane.minZ() < 0.1f)
        //        )
        //    {  
        //        return true;
        //    }

        //}

    

    return false;
}

float findMax(float begin, float end)
{
    if (begin >= end)
    {
        return begin;
    }
    else
    {
        return end;
    }

}

float findMin(float begin, float end)
{
    if (begin >= end)
    {
        return end;
    }
    else
    {
        return begin;
    }

}