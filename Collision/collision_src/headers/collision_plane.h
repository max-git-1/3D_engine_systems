#include "shader.h"
#include <vector>


class collisionPlane
{
private:

    glm::vec4     plane_Normal = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);

    glm::vec4     plane_vertex1 = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
    glm::vec4     plane_vertex2 = glm::vec4(1.0f, 0.0f, -1.0f, 1.0f);
    glm::vec4     plane_vertex3 = glm::vec4(-1.0f, 0.0f, -1.0f, 1.0f);
    glm::vec4     plane_vertex4 = glm::vec4(-1.0f, 0.0f, 1.0f, 1.0f);

    glm::vec4     plane_Vertices[4] =
    {
        // positions                 
        plane_vertex1,
        plane_vertex2,
        plane_vertex3,
        plane_vertex4
    };

    //float plane_VBO_array[36] = {
    //       // positions                                                 // normals         
    //     plane_vertex1.x, plane_vertex1.y, plane_vertex1.z,   plane_Normal.x, plane_Normal.y, plane_Normal.z,
    //     plane_vertex4.x, plane_vertex4.y, plane_vertex4.z,   plane_Normal.x, plane_Normal.y, plane_Normal.z,
    //     plane_vertex3.x, plane_vertex3.y, plane_vertex3.z,   plane_Normal.x, plane_Normal.y, plane_Normal.z,

    //     plane_vertex1.x, plane_vertex1.y, plane_vertex1.z,   plane_Normal.x, plane_Normal.y, plane_Normal.z,
    //     plane_vertex3.x, plane_vertex3.y, plane_vertex3.z,   plane_Normal.x, plane_Normal.y, plane_Normal.z,
    //     plane_vertex2.x, plane_vertex2.y, plane_vertex2.z,   plane_Normal.x, plane_Normal.y, plane_Normal.z
    //};

    float        plane_VBO_array[36] = {
        // positions            // normals         
         1.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
        -1.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
        -1.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f,

         1.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
        -1.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
         1.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f
    };

    //glm::vec3 planePos = glm::vec3(0.0f, -3.0f, 0.0f);



    glm::vec4    plane_Point_0 = plane_Vertices[0];

    float        plane_A = plane_Normal.x;
    float        plane_B = plane_Normal.y;
    float        plane_C = plane_Normal.z;

    float        plane_D = -(plane_A * plane_Point_0.x + plane_B * plane_Point_0.y + plane_C * plane_Point_0.z);

    Shader       plane_shader;

    unsigned int plane_VAO, plane_VBO;

    glm::vec3    plane_color;
    glm::vec3    plane_position;
    glm::vec3    plane_scale;
    glm::vec3    plane_rotation_axis;
    float        plane_rotation_degree;

    float        plane_Xmin;
    float        plane_Xmax;
    float        plane_Ymin;
    float        plane_Ymax;
    float        plane_Zmin;
    float        plane_Zmax;

    float findMinPlaneX();
    float findMaxPlaneX();
    float findMinPlaneY();
    float findMaxPlaneY();
    float findMinPlaneZ();
    float findMaxPlaneZ();


    // проекции с помощью отрезков, созданных в помощью уравнения плоскости

    /*
    struct plane_projection
    {
        glm::vec4     plane_proj_Normal;
        glm::vec4     plane_proj_Point_0;
        float         plane_proj_A;
        float         plane_proj_B;
        float         plane_proj_C;
        float         plane_proj_D;
        //float         plane_proj_degree;
    };

    // плоскость проекции YX
    glm::vec4     plane_Normal_YX_01 = glm::vec4(   1.0f,   0.0f,  0.0f, 1.0f);
    glm::vec4     plane_Normal_YX_12 = glm::vec4(   0.0f,  -1.0f,  0.0f, 1.0f);
    glm::vec4     plane_Normal_YX_23 = glm::vec4(  -1.0f,   0.0f,  0.0f, 1.0f);
    glm::vec4     plane_Normal_YX_30 = glm::vec4(   0.0f,   1.0f,  0.0f, 1.0f);

    glm::vec4     plane_Point_0_YX_01 = plane_Vertices[0];
    glm::vec4     plane_Point_0_YX_12 = plane_Vertices[1];
    glm::vec4     plane_Point_0_YX_23 = plane_Vertices[2];
    glm::vec4     plane_Point_0_YX_30 = plane_Vertices[3];


    float         plane_A_YX_01 = plane_Normal_YX_01.x;
    float         plane_B_YX_01 = plane_Normal_YX_01.y;
    float         plane_C_YX_01 = 0.0f;
    float         plane_D_YX_01 = -(plane_A_YX_01 * plane_Point_0_YX_01.x + plane_B_YX_01 * plane_Point_0_YX_01.y + plane_C_YX_01 * plane_Point_0_YX_01.z);

    float         plane_A_YX_12 = plane_Normal_YX_12.x;
    float         plane_B_YX_12 = plane_Normal_YX_12.y;
    float         plane_C_YX_12 = 0.0f;
    float         plane_D_YX_12 = -(plane_A_YX_12 * plane_Point_0_YX_12.x + plane_B_YX_12 * plane_Point_0_YX_12.y + plane_C_YX_12 * plane_Point_0_YX_12.z);

    float         plane_A_YX_23 = plane_Normal_YX_23.x;
    float         plane_B_YX_23 = plane_Normal_YX_23.y;
    float         plane_C_YX_23 = 0.0f;
    float         plane_D_YX_23 = -(plane_A_YX_23 * plane_Point_0_YX_23.x + plane_B_YX_23 * plane_Point_0_YX_23.y + plane_C_YX_23 * plane_Point_0_YX_23.z);

    float         plane_A_YX_30 = plane_Normal_YX_30.x;
    float         plane_B_YX_30 = plane_Normal_YX_30.y;
    float         plane_C_YX_30 = 0.0f;
    float         plane_D_YX_30 = -(plane_A_YX_30 * plane_Point_0_YX_30.x + plane_B_YX_30 * plane_Point_0_YX_30.y + plane_C_YX_30 * plane_Point_0_YX_30.z);


    // плоскость проекции YZ
    glm::vec4     plane_Normal_YZ_01 = glm::vec4(0.0f, -1.0f,  0.0f, 1.0f);
    glm::vec4     plane_Normal_YZ_12 = glm::vec4(0.0f,  0.0f, -1.0f, 1.0f);
    glm::vec4     plane_Normal_YZ_23 = glm::vec4(0.0f,  1.0f,  0.0f, 1.0f);
    glm::vec4     plane_Normal_YZ_30 = glm::vec4(0.0f,  0.0f,  1.0f, 1.0f);

    glm::vec4     plane_Point_0_YZ_01 = plane_Vertices[0];
    glm::vec4     plane_Point_0_YZ_12 = plane_Vertices[1];
    glm::vec4     plane_Point_0_YZ_23 = plane_Vertices[2];
    glm::vec4     plane_Point_0_YZ_30 = plane_Vertices[3];


    float         plane_A_YZ_01 = 0.0f;
    float         plane_B_YZ_01 = plane_Normal_YZ_01.y;
    float         plane_C_YZ_01 = plane_Normal_YZ_01.z;
    float         plane_D_YZ_01 = -(plane_A_YZ_01 * plane_Point_0_YZ_01.x + plane_B_YZ_01 * plane_Point_0_YZ_01.y + plane_C_YZ_01 * plane_Point_0_YZ_01.z);

    float         plane_A_YZ_12 = 0.0f;
    float         plane_B_YZ_12 = plane_Normal_YZ_12.y;
    float         plane_C_YZ_12 = plane_Normal_YZ_12.z;
    float         plane_D_YZ_12 = -(plane_A_YZ_12 * plane_Point_0_YZ_12.x + plane_B_YZ_12 * plane_Point_0_YZ_12.y + plane_C_YZ_12 * plane_Point_0_YZ_12.z);

    float         plane_A_YZ_23 = 0.0f;
    float         plane_B_YZ_23 = plane_Normal_YZ_23.y;
    float         plane_C_YZ_23 = plane_Normal_YZ_23.z;
    float         plane_D_YZ_23 = -(plane_A_YZ_23 * plane_Point_0_YZ_23.x + plane_B_YZ_23 * plane_Point_0_YZ_23.y + plane_C_YZ_23 * plane_Point_0_YZ_23.z);

    float         plane_A_YZ_30 = 0.0f;
    float         plane_B_YZ_30 = plane_Normal_YZ_30.y;
    float         plane_C_YZ_30 = plane_Normal_YZ_30.z;
    float         plane_D_YZ_30 = -(plane_A_YZ_30 * plane_Point_0_YZ_30.x + plane_B_YZ_30 * plane_Point_0_YZ_30.y + plane_C_YZ_30 * plane_Point_0_YZ_30.z);


    // плоскость проекции XZ
    glm::vec4     plane_Normal_XZ_01 = glm::vec4(  1.0f, 0.0f,  0.0f, 1.0f);
    glm::vec4     plane_Normal_XZ_12 = glm::vec4(  0.0f, 0.0f, -1.0f, 1.0f);
    glm::vec4     plane_Normal_XZ_23 = glm::vec4( -1.0f, 0.0f,  0.0f, 1.0f);
    glm::vec4     plane_Normal_XZ_30 = glm::vec4(  0.0f, 0.0f,  1.0f, 1.0f);

    glm::vec4     plane_Point_0_XZ_01 = plane_Vertices[0];
    glm::vec4     plane_Point_0_XZ_12 = plane_Vertices[1];
    glm::vec4     plane_Point_0_XZ_23 = plane_Vertices[2];
    glm::vec4     plane_Point_0_XZ_30 = plane_Vertices[3];


    float         plane_A_XZ_01 = plane_Normal_XZ_01.x;
    float         plane_B_XZ_01 = 0.0f;
    float         plane_C_XZ_01 = plane_Normal_XZ_01.z;
    float         plane_D_XZ_01 = -(plane_A_XZ_01 * plane_Point_0_XZ_01.x + plane_B_XZ_01 * plane_Point_0_XZ_01.y + plane_C_XZ_01 * plane_Point_0_XZ_01.z);

    float         plane_A_XZ_12 = plane_Normal_XZ_12.x;
    float         plane_B_XZ_12 = 0.0f;
    float         plane_C_XZ_12 = plane_Normal_XZ_12.z;
    float         plane_D_XZ_12 = -(plane_A_XZ_12 * plane_Point_0_XZ_12.x + plane_B_XZ_12 * plane_Point_0_XZ_12.y + plane_C_XZ_12 * plane_Point_0_XZ_12.z);

    float         plane_A_XZ_23 = plane_Normal_XZ_23.x;
    float         plane_B_XZ_23 = 0.0f;
    float         plane_C_XZ_23 = plane_Normal_XZ_23.z;
    float         plane_D_XZ_23 = -(plane_A_XZ_23 * plane_Point_0_XZ_23.x + plane_B_XZ_23 * plane_Point_0_XZ_23.y + plane_C_XZ_23 * plane_Point_0_XZ_23.z);

    float         plane_A_XZ_30 = plane_Normal_XZ_30.x;
    float         plane_B_XZ_30 = 0.0f;
    float         plane_C_XZ_30 = plane_Normal_XZ_30.z;
    float         plane_D_XZ_30 = -(plane_A_XZ_30 * plane_Point_0_XZ_30.x + plane_B_XZ_30 * plane_Point_0_XZ_30.y + plane_C_XZ_30 * plane_Point_0_XZ_30.z);


    plane_projection P_YX[4] =
    {
        {plane_Normal_YX_01, plane_Point_0_YX_01, plane_A_YX_01, plane_B_YX_01, plane_C_YX_01, plane_D_YX_01},
        {plane_Normal_YX_12, plane_Point_0_YX_12, plane_A_YX_12, plane_B_YX_12, plane_C_YX_12, plane_D_YX_12},
        {plane_Normal_YX_23, plane_Point_0_YX_23, plane_A_YX_23, plane_B_YX_23, plane_C_YX_23, plane_D_YX_23},
        {plane_Normal_YX_30, plane_Point_0_YX_30, plane_A_YX_30, plane_B_YX_30, plane_C_YX_30, plane_D_YX_30}
    };

    plane_projection P_YZ[4] =
    {
        {plane_Normal_YZ_01, plane_Point_0_YZ_01, plane_A_YZ_01, plane_B_YZ_01, plane_C_YZ_01, plane_D_YZ_01},
        {plane_Normal_YZ_12, plane_Point_0_YZ_12, plane_A_YZ_12, plane_B_YZ_12, plane_C_YZ_12, plane_D_YZ_12},
        {plane_Normal_YZ_23, plane_Point_0_YZ_23, plane_A_YZ_23, plane_B_YZ_23, plane_C_YZ_23, plane_D_YZ_23},
        {plane_Normal_YZ_30, plane_Point_0_YZ_30, plane_A_YZ_30, plane_B_YZ_30, plane_C_YZ_30, plane_D_YZ_30}
    };

    plane_projection P_XZ[4] =
    {
        {plane_Normal_XZ_01, plane_Point_0_XZ_01, plane_A_XZ_01, plane_B_XZ_01, plane_C_XZ_01, plane_D_XZ_01},
        {plane_Normal_XZ_12, plane_Point_0_XZ_12, plane_A_XZ_12, plane_B_XZ_12, plane_C_XZ_12, plane_D_XZ_12},
        {plane_Normal_XZ_23, plane_Point_0_XZ_23, plane_A_XZ_23, plane_B_XZ_23, plane_C_XZ_23, plane_D_XZ_23},
        {plane_Normal_XZ_30, plane_Point_0_XZ_30, plane_A_XZ_30, plane_B_XZ_30, plane_C_XZ_30, plane_D_XZ_30}
    };
    */

    // проекции с помощью отрезков и коэффициентов a, t и y0(x0)

    /*
    struct plane_projection_segment
    {
        float plane_a;// коэффициент y (x для X(Z)). равен 1 или 0 (если отрезок параллелен оси Y (x для X(Z)))
        float plane_t;//коэффициент приращения(применяется к x (z для X(Z)))
        float plane_0_coefficient;// коэффициент y0(x0 для X(Z))
        float plane_top_max;// максимальное значение по оси Y (X для X(Z)) макс. значение для оси, направленной вверх
        float plane_top_min;// минимальное  значение по оси Y (X для X(Z)) мин.  значение для оси, направленной вверх
        float plane_right_max;// максимальное значение по оси X (Z для X(Z) и Y(Z)) макс. значение для оси, направленной вправо
        float plane_right_min;// минимальное  значение по оси X (Z для X(Z) и Y(Z)) мин.  значение для оси, направленной вправо
    };

    // коэффициенты уравнений отрезков проекции Y(X)  y0 и t(a*y = y0 + t*x)
    // a
    float        plane_a_YX_01;
    float        plane_a_YX_12;
    float        plane_a_YX_23;
    float        plane_a_YX_30;

    // t
    float        plane_t_YX_01;
    float        plane_t_YX_12;
    float        plane_t_YX_23;
    float        plane_t_YX_30;

    //y0         
    float        plane_y0_YX_01;
    float        plane_y0_YX_12;
    float        plane_y0_YX_23;
    float        plane_y0_YX_30;

    // границы, которые ограничивают отрезки проекций
    float plane_YX_01_top_max;
    float plane_YX_01_top_min;
    float plane_YX_01_right_max;
    float plane_YX_01_right_min;

    float plane_YX_12_top_max;
    float plane_YX_12_top_min;
    float plane_YX_12_right_max;
    float plane_YX_12_right_min;

    float plane_YX_23_top_max;
    float plane_YX_23_top_min;
    float plane_YX_23_right_max;
    float plane_YX_23_right_min;

    float plane_YX_30_top_max;
    float plane_YX_30_top_min;
    float plane_YX_30_right_max;
    float plane_YX_30_right_min;

public:

    plane_projection_segment P_YX[4] =
    {
        {plane_a_YX_01, plane_t_YX_01, plane_y0_YX_01, plane_YX_01_top_max, plane_YX_01_top_min,plane_YX_01_right_max, plane_YX_01_right_min },
        {plane_a_YX_12, plane_t_YX_12, plane_y0_YX_12, plane_YX_12_top_max, plane_YX_12_top_min,plane_YX_12_right_max, plane_YX_12_right_min},
        {plane_a_YX_23, plane_t_YX_23, plane_y0_YX_23, plane_YX_23_top_max, plane_YX_23_top_min,plane_YX_23_right_max, plane_YX_23_right_min},
        {plane_a_YX_30, plane_t_YX_30, plane_y0_YX_30, plane_YX_30_top_max, plane_YX_30_top_min,plane_YX_30_right_max, plane_YX_30_right_min}
    };


private:

    // коэффициенты уравнений отрезков проекции Y(Z)  y0 и t(a*y = y0 + t*z)

    //a
    float        plane_a_YZ_01;
    float        plane_a_YZ_12;
    float        plane_a_YZ_23;
    float        plane_a_YZ_30;

    // t
    float        plane_t_YZ_01;
    float        plane_t_YZ_12;
    float        plane_t_YZ_23;
    float        plane_t_YZ_30;

    //y0         
    float        plane_y0_YZ_01;
    float        plane_y0_YZ_12;
    float        plane_y0_YZ_23;
    float        plane_y0_YZ_30;

    // границы, которые ограничивают отрезки проекций
    float plane_YZ_01_top_max;
    float plane_YZ_01_top_min;
    float plane_YZ_01_right_max;
    float plane_YZ_01_right_min;

    float plane_YZ_12_top_max;
    float plane_YZ_12_top_min;
    float plane_YZ_12_right_max;
    float plane_YZ_12_right_min;

    float plane_YZ_23_top_max;
    float plane_YZ_23_top_min;
    float plane_YZ_23_right_max;
    float plane_YZ_23_right_min;

    float plane_YZ_30_top_max;
    float plane_YZ_30_top_min;
    float plane_YZ_30_right_max;
    float plane_YZ_30_right_min;
public:

    plane_projection_segment P_YZ[4] =
    {
        {plane_a_YZ_01, plane_t_YZ_01, plane_y0_YZ_01, plane_YZ_01_top_max, plane_YZ_01_top_min,plane_YZ_01_right_max, plane_YZ_01_right_min},
        {plane_a_YZ_12, plane_t_YZ_12, plane_y0_YZ_12, plane_YZ_12_top_max, plane_YZ_12_top_min,plane_YZ_12_right_max, plane_YZ_12_right_min},
        {plane_a_YZ_23, plane_t_YZ_23, plane_y0_YZ_23, plane_YZ_23_top_max, plane_YZ_23_top_min,plane_YZ_23_right_max, plane_YZ_23_right_min},
        {plane_a_YZ_30, plane_t_YZ_30, plane_y0_YZ_30, plane_YZ_30_top_max, plane_YZ_30_top_min,plane_YZ_30_right_max, plane_YZ_30_right_min}
    };

private:

    // коэффициенты уравнений отрезков проекции X(Z)  x0 и t(a*x = x0 + t*z)

    //a
    float        plane_a_XZ_01;
    float        plane_a_XZ_12;
    float        plane_a_XZ_23;
    float        plane_a_XZ_30;

    // t
    float        plane_t_XZ_01;
    float        plane_t_XZ_12;
    float        plane_t_XZ_23;
    float        plane_t_XZ_30;

    //x0         
    float        plane_x0_XZ_01;
    float        plane_x0_XZ_12;
    float        plane_x0_XZ_23;
    float        plane_x0_XZ_30;

    // границы, которые ограничивают отрезки проекций
    float plane_XZ_01_top_max;
    float plane_XZ_01_top_min;
    float plane_XZ_01_right_max;
    float plane_XZ_01_right_min;

    float plane_XZ_12_top_max;
    float plane_XZ_12_top_min;
    float plane_XZ_12_right_max;
    float plane_XZ_12_right_min;

    float plane_XZ_23_top_max;
    float plane_XZ_23_top_min;
    float plane_XZ_23_right_max;
    float plane_XZ_23_right_min;

    float plane_XZ_30_top_max;
    float plane_XZ_30_top_min;
    float plane_XZ_30_right_max;
    float plane_XZ_30_right_min;

public:

    plane_projection_segment P_XZ[4] =
    {
        {plane_a_XZ_01, plane_t_XZ_01, plane_x0_XZ_01, plane_XZ_01_top_max, plane_XZ_01_top_min,plane_XZ_01_right_max, plane_XZ_01_right_min},
        {plane_a_XZ_12, plane_t_XZ_12, plane_x0_XZ_12, plane_XZ_12_top_max, plane_XZ_12_top_min,plane_XZ_12_right_max, plane_XZ_12_right_min},
        {plane_a_XZ_23, plane_t_XZ_23, plane_x0_XZ_23, plane_XZ_23_top_max, plane_XZ_23_top_min,plane_XZ_23_right_max, plane_XZ_23_right_min},
        {plane_a_XZ_30, plane_t_XZ_30, plane_x0_XZ_30, plane_XZ_30_top_max, plane_XZ_30_top_min,plane_XZ_30_right_max, plane_XZ_30_right_min}
    };
private:


    bool ProjectionYX(glm::vec4 vertex);
    bool ProjectionYZ(glm::vec4 vertex);
    bool ProjectionXZ(glm::vec4 vertex);

    float findMaxBorder(float begin_point_coord, float end_point_coord);
    float findMinBorder(float begin_point_coord, float end_point_coord);

    */

    // проекции с помощью уравнений прямых на плоскости и  коэффициентов A, B, C

    struct plane_projection
    {
        // уравнение прямой на плоскости A*x + B*y + C = 0
        float plane_A;// коэффициент прямой при x(Y(X)), z(Y(Z), X(Z))
        float plane_B;// коэффициент прямой при y(Y(X)), y(Y(Z)), z(X(Z))
        float plane_C;// свободный коэффициент (не при переменных который)
        float plane_top_max;// максимальное значение по оси Y (X для X(Z)) макс. значение для оси, направленной вверх
        float plane_top_min;// минимальное  значение по оси Y (X для X(Z)) мин.  значение для оси, направленной вверх
        float plane_right_max;// максимальное значение по оси X (Z для X(Z) и Y(Z)) макс. значение для оси, направленной вправо
        float plane_right_min;// минимальное  значение по оси X (Z для X(Z) и Y(Z)) мин.  значение для оси, направленной вправо
    };

    // YX

    float   plane_YX_01_A;
    float   plane_YX_12_A;
    float   plane_YX_23_A;
    float   plane_YX_30_A;

    float   plane_YX_01_B;
    float   plane_YX_12_B;
    float   plane_YX_23_B;
    float   plane_YX_30_B;

    float   plane_YX_01_C;
    float   plane_YX_12_C;
    float   plane_YX_23_C;
    float   plane_YX_30_C;

    // границы, которые ограничивают отрезки проекций (t - top, r - right)
    float plane_YX_01_t_max;
    float plane_YX_01_t_min;
    float plane_YX_01_r_max;
    float plane_YX_01_r_min;
                 
    float plane_YX_12_t_max;
    float plane_YX_12_t_min;
    float plane_YX_12_r_max;
    float plane_YX_12_r_min;
                 
    float plane_YX_23_t_max;
    float plane_YX_23_t_min;
    float plane_YX_23_r_max;
    float plane_YX_23_r_min;
                 
    float plane_YX_30_t_max;
    float plane_YX_30_t_min;
    float plane_YX_30_r_max;
    float plane_YX_30_r_min;

    public:
    // уравнение прямой на плоскости A*x + B*y + C = 0
    plane_projection Pl_YX[4] = 
    {
        {plane_YX_01_A, plane_YX_01_B, plane_YX_01_C, plane_YX_01_t_max, plane_YX_01_t_min,plane_YX_01_r_max, plane_YX_01_r_min },
        {plane_YX_12_A, plane_YX_12_B, plane_YX_12_C, plane_YX_12_t_max, plane_YX_12_t_min,plane_YX_12_r_max, plane_YX_12_r_min },
        {plane_YX_23_A, plane_YX_23_B, plane_YX_23_C, plane_YX_23_t_max, plane_YX_23_t_min,plane_YX_23_r_max, plane_YX_23_r_min },
        {plane_YX_30_A, plane_YX_30_B, plane_YX_30_C, plane_YX_30_t_max, plane_YX_30_t_min,plane_YX_30_r_max, plane_YX_30_r_min }
    };

    private:

    // YZ

    float   plane_YZ_01_A;
    float   plane_YZ_12_A;
    float   plane_YZ_23_A;
    float   plane_YZ_30_A;
                   
    float   plane_YZ_01_B;
    float   plane_YZ_12_B;
    float   plane_YZ_23_B;
    float   plane_YZ_30_B;
                   
    float   plane_YZ_01_C;
    float   plane_YZ_12_C;
    float   plane_YZ_23_C;
    float   plane_YZ_30_C;

    // границы, которые ограничивают отрезки проекций (t - top, r - right)
    float plane_YZ_01_t_max;
    float plane_YZ_01_t_min;
    float plane_YZ_01_r_max;
    float plane_YZ_01_r_min;
                 
    float plane_YZ_12_t_max;
    float plane_YZ_12_t_min;
    float plane_YZ_12_r_max;
    float plane_YZ_12_r_min;
                 
    float plane_YZ_23_t_max;
    float plane_YZ_23_t_min;
    float plane_YZ_23_r_max;
    float plane_YZ_23_r_min;
                 
    float plane_YZ_30_t_max;
    float plane_YZ_30_t_min;
    float plane_YZ_30_r_max;
    float plane_YZ_30_r_min;

    public:
    // уравнение прямой на плоскости A*z + B*y + C = 0
    plane_projection Pl_YZ[4] =
    {
        {plane_YZ_01_A, plane_YZ_01_B, plane_YZ_01_C, plane_YZ_01_t_max, plane_YZ_01_t_min,plane_YZ_01_r_max, plane_YZ_01_r_min },
        {plane_YZ_12_A, plane_YZ_12_B, plane_YZ_12_C, plane_YZ_12_t_max, plane_YZ_12_t_min,plane_YZ_12_r_max, plane_YZ_12_r_min },
        {plane_YZ_23_A, plane_YZ_23_B, plane_YZ_23_C, plane_YZ_23_t_max, plane_YZ_23_t_min,plane_YZ_23_r_max, plane_YZ_23_r_min },
        {plane_YZ_30_A, plane_YZ_30_B, plane_YZ_30_C, plane_YZ_30_t_max, plane_YZ_30_t_min,plane_YZ_30_r_max, plane_YZ_30_r_min }
    };

    private:
    // XZ

    float   plane_XZ_01_A;
    float   plane_XZ_12_A;
    float   plane_XZ_23_A;
    float   plane_XZ_30_A;
                  
    float   plane_XZ_01_B;
    float   plane_XZ_12_B;
    float   plane_XZ_23_B;
    float   plane_XZ_30_B;
                  
    float   plane_XZ_01_C;
    float   plane_XZ_12_C;
    float   plane_XZ_23_C;
    float   plane_XZ_30_C;

    // границы, которые ограничивают отрезки проекций (t - top, r - right)
    float plane_XZ_01_t_max;
    float plane_XZ_01_t_min;
    float plane_XZ_01_r_max;
    float plane_XZ_01_r_min;
                
    float plane_XZ_12_t_max;
    float plane_XZ_12_t_min;
    float plane_XZ_12_r_max;
    float plane_XZ_12_r_min;
                
    float plane_XZ_23_t_max;
    float plane_XZ_23_t_min;
    float plane_XZ_23_r_max;
    float plane_XZ_23_r_min;
                
    float plane_XZ_30_t_max;
    float plane_XZ_30_t_min;
    float plane_XZ_30_r_max;
    float plane_XZ_30_r_min;

    public:

    // уравнение прямой на плоскости A*z + B*x + C = 0
    plane_projection Pl_XZ[4] =
    {
        {plane_XZ_01_A, plane_XZ_01_B, plane_XZ_01_C, plane_XZ_01_t_max, plane_XZ_01_t_min,plane_XZ_01_r_max, plane_XZ_01_r_min },
        {plane_XZ_12_A, plane_XZ_12_B, plane_XZ_12_C, plane_XZ_12_t_max, plane_XZ_12_t_min,plane_XZ_12_r_max, plane_XZ_12_r_min },
        {plane_XZ_23_A, plane_XZ_23_B, plane_XZ_23_C, plane_XZ_23_t_max, plane_XZ_23_t_min,plane_XZ_23_r_max, plane_XZ_23_r_min },
        {plane_XZ_30_A, plane_XZ_30_B, plane_XZ_30_C, plane_XZ_30_t_max, plane_XZ_30_t_min,plane_XZ_30_r_max, plane_XZ_30_r_min }
    };

    private:

    float findMaxPoint(float begin_point_coord, float end_point_coord);
    float findMinPoint(float begin_point_coord, float end_point_coord);

public:

    

    collisionPlane(Shader& shader, glm::vec3 color, glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f),
        glm::vec3 new_scale = glm::vec3(1.0f,1.0f,1.0f), float degrees = 0.0f, glm::vec3 axis_rotation = glm::vec3(0.0f,0.0f,1.0f));
    ~collisionPlane();
    void  resizePlaneVertex(glm::vec3 new_position, glm::vec3 new_scale, float new_degrees, glm::vec3 new_axis_rotation);
    void  DrawPlane(glm::mat4 &view, glm::mat4 &projection);
    float result(glm::vec4 &cube_vertex);

    float minX();
    float maxX();

    float minY();
    float maxY();

    float minZ();
    float maxZ();

    // методы для отрезков, созданных с помощью уравнений плоскости

    /*float isOnProjectionYX(glm::vec4 vertex, int index);
    float isOnProjectionYZ(glm::vec4 vertex, int index);
    float isOnProjectionXZ(glm::vec4 vertex, int index);*/

    

    // методы для отрезков, созданных с помощью коэффициентов

    //bool isInProjectionOfPlane(glm::vec4 vertex_position);

    //int PlaneProjectionYX(glm::vec4 vertex);
    //int PlaneProjectionYZ(glm::vec4 vertex);
    //int PlaneProjectionXZ(glm::vec4 vertex);
};