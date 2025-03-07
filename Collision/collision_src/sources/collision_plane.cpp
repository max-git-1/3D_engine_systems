#include "collision_plane.h"

float collisionPlane::findMinPlaneX()
{
    float min_x = plane_Vertices[0].x;

    for (int i = 0; i < 4; i++)
    {
        if (plane_Vertices[i].x < min_x)
        {
            min_x = plane_Vertices[i].x;
        }
    }

    return min_x;
}

float collisionPlane::findMaxPlaneX()
{
    float max_x = plane_Vertices[1].x;

    for (int i = 0; i < 4; i++)
    {
        if (plane_Vertices[i].x > max_x)
        {
            max_x = plane_Vertices[i].x;
        }
    }

    return max_x;
}

float collisionPlane::findMinPlaneY()
{
    float min_y = plane_Vertices[0].y;

    for (int i = 0; i < 4; i++)
    {
        if (plane_Vertices[i].y < min_y)
        {
            min_y = plane_Vertices[i].y;
        }
    }

    return min_y;
}

float collisionPlane::findMaxPlaneY()
{
    float max_y = plane_Vertices[1].y;

    for (int i = 0; i < 4; i++)
    {
        if (plane_Vertices[i].y > max_y)
        {
            max_y = plane_Vertices[i].y;
        }
    }

    return max_y;
}

float collisionPlane::findMinPlaneZ()
{
    float min_z = plane_Vertices[0].z;

    for (int i = 0; i < 4; i++)
    {
        if (plane_Vertices[i].z < min_z)
        {
            min_z = plane_Vertices[i].z;
        }
    }

    return min_z;
}

float collisionPlane::findMaxPlaneZ()
{
    float max_z = plane_Vertices[1].z;

    for (int i = 0; i < 4; i++)
    {
        if (plane_Vertices[i].z > max_z)
        {
            max_z = plane_Vertices[i].z;
        }
    }

    return max_z;
}




float collisionPlane::findMaxPoint(float begin_point_coord, float end_point_coord)
{
    if (begin_point_coord >= end_point_coord)
    {
        return begin_point_coord;
    }
    else
    {
        return end_point_coord;
    }
}

float collisionPlane::findMinPoint(float begin_point_coord, float end_point_coord)
{
    if (begin_point_coord <= end_point_coord)
    {
        return begin_point_coord;
    }
    else
    {
        return end_point_coord;
    }
}

collisionPlane::collisionPlane(Shader& shader, glm::vec3 color, glm::vec3 position, glm::vec3 scale, float degrees, glm::vec3 axis_rotation)
    :plane_shader(shader),
    plane_color(color)
{
    // plane VAO
    glGenVertexArrays(1, &plane_VAO);
    glGenBuffers(1, &plane_VBO);
    glBindVertexArray(plane_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, plane_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(plane_VBO_array), plane_VBO_array, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    resizePlaneVertex(position, scale, degrees, axis_rotation);

}

collisionPlane::~collisionPlane()
{
    glDeleteVertexArrays(1, &plane_VAO);
    glDeleteBuffers(1, &plane_VBO);

}

void collisionPlane::resizePlaneVertex(glm::vec3 new_position, glm::vec3 new_scale, float new_degrees, glm::vec3 new_axis_rotation)
{
    // ���������� ���������� ������ ����� ��������
    plane_position = new_position;
    plane_scale = new_scale;
    plane_rotation_axis = new_axis_rotation;
    plane_rotation_degree = new_degrees;

    int vertices = 4;

    // ���������� ��������� ������ ��������� �������� � ������ ����� ������
    for (int i = 0; i < vertices; i++)
    {
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(plane_rotation_degree), plane_rotation_axis);
        trans = glm::scale(trans, plane_scale);
        trans = glm::translate(trans, plane_position);
        plane_Vertices[i] = trans * plane_Vertices[i];
        std::cout << "plane point " << i << "\t x: " << plane_Vertices[i].x << "\t y: " << plane_Vertices[i].y << "\t z: " << plane_Vertices[i].z << std::endl;
    }

    // ���������� ���������� ������� ������� (� ��� ����� ���������� ������ �������� ��������, �������������� � ���������� ������)
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, glm::radians(plane_rotation_degree), plane_rotation_axis);
    plane_Normal = trans * plane_Normal;

    // ���������� ������� ����� � ������ ����� ������
    trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, glm::radians(plane_rotation_degree), plane_rotation_axis);
    trans = glm::scale(trans, plane_scale);
    trans = glm::translate(trans, plane_position);
    plane_Point_0 = trans * plane_Point_0;

    std::cout << "plane normal  x: " << plane_Normal.x << " y: " << plane_Normal.y << " z: " << plane_Normal.z << std::endl;
    std::cout << "plane_Point_0  x: " << plane_Point_0.x << " y: " << plane_Point_0.y << " z: " << plane_Point_0.z << std::endl;

    // ���������� ������������� ��������� ���������
    plane_A = plane_Normal.x;
    plane_B = plane_Normal.y;
    plane_C = plane_Normal.z;
    plane_D = -(plane_A * plane_Point_0.x + plane_B * plane_Point_0.y + plane_C * plane_Point_0.z);

    std::cout << "A: " << plane_A << " B: " << plane_B << " C: " << plane_C << " D: " << plane_D << std::endl;

    // ���������� ������� ����� (������������ � ����������� ��������� �� ���� ����)

    plane_Xmin=findMinPlaneX();
    plane_Xmax=findMaxPlaneX();
    plane_Ymin=findMinPlaneY();
    plane_Ymax=findMaxPlaneY();
    plane_Zmin=findMinPlaneZ();
    plane_Zmax=findMaxPlaneZ();

    std::cout << "Xmin: " << plane_Xmin << " Xmax: " << plane_Xmax << std::endl;
    std::cout << "Ymin: " << plane_Ymin << " Ymax: " << plane_Ymax << std::endl;
    std::cout << "Zmin: " << plane_Zmin << " Zmax: " << plane_Zmax << std::endl;


    float dy = 0.0f;
    float dx = 0.0f;
    float dz = 0.0f;
    int next_i = 0;

    // ����������� ���������, ��������� � ������� ��������� ���������

    /*
    // YX
    
    for (int i = 0; i < 4; i++)
    {
        
        // ���������� ���������� ������� ������� (� ��� ����� ���������� ������ �������� ��������, �������������� � ���������� ������)
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(plane_rotation_degree), plane_rotation_axis);
        P_YX[i].plane_proj_Normal = trans * P_YX[i].plane_proj_Normal;
        

        // ���������� ������� ����� � ������ ����� ������
        P_YX[i].plane_proj_Point_0 = plane_Vertices[i];

        std::cout << "P_YX[i].plane_proj_Normal "<<"\t x: " << P_YX[i].plane_proj_Normal.x << "\t y: " << P_YX[i].plane_proj_Normal.y << "\t z: " << P_YX[i].plane_proj_Normal.z << std::endl;
        std::cout << "P_YX[i].plane_proj_Point_0 "<<"\t x: " << P_YX[i].plane_proj_Point_0.x << "\t y: " << P_YX[i].plane_proj_Point_0.y << "\t z: " << P_YX[i].plane_proj_Point_0.z << std::endl;

        // ���������� ������������� ��������� ���������
        P_YX[i].plane_proj_A = P_YX[i].plane_proj_Normal.x;
        P_YX[i].plane_proj_B = P_YX[i].plane_proj_Normal.y;
        P_YX[i].plane_proj_C = 0.0f;
        P_YX[i].plane_proj_D = -(P_YX[i].plane_proj_A * P_YX[i].plane_proj_Point_0.x + P_YX[i].plane_proj_B * P_YX[i].plane_proj_Point_0.y + P_YX[i].plane_proj_C * P_YX[i].plane_proj_Point_0.z);

        std::cout << "A: " << P_YX[i].plane_proj_A << "\t B: " << P_YX[i].plane_proj_B << "\t C: " << P_YX[i].plane_proj_C << "\t D: " << P_YX[i].plane_proj_D << std::endl;
    }

    std::cout << std::endl;
    // YZ

    for (int i = 0; i < 4; i++)
    {
        // ���������� ���������� ������� ������� (� ��� ����� ���������� ������ �������� ��������, �������������� � ���������� ������)
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(plane_rotation_degree), plane_rotation_axis);
        P_YZ[i].plane_proj_Normal = trans * P_YZ[i].plane_proj_Normal;

        // ���������� ������� ����� � ������ ����� ������
        P_YZ[i].plane_proj_Point_0 = plane_Vertices[i];

        std::cout << "P_YZ[i].plane_proj_Normal "<<"\t x: " << P_YZ[i].plane_proj_Normal.x << "\t y: " << P_YZ[i].plane_proj_Normal.y << "\t z: " << P_YZ[i].plane_proj_Normal.z << std::endl;
        std::cout << "P_YZ[i].plane_proj_Point_0 " <<"\t x: " << P_YZ[i].plane_proj_Point_0.x << "\t y: " << P_YZ[i].plane_proj_Point_0.y << "\t z: " << P_YZ[i].plane_proj_Point_0.z << std::endl;

        // ���������� ������������� ��������� ���������
        P_YZ[i].plane_proj_A = 0.0f;
        P_YZ[i].plane_proj_B = P_YZ[i].plane_proj_Normal.y;
        P_YZ[i].plane_proj_C = P_YZ[i].plane_proj_Normal.z;
        P_YZ[i].plane_proj_D = -(P_YZ[i].plane_proj_A * P_YZ[i].plane_proj_Point_0.x + P_YZ[i].plane_proj_B * P_YZ[i].plane_proj_Point_0.y + P_YZ[i].plane_proj_C * P_YZ[i].plane_proj_Point_0.z);

        std::cout << "A: " << P_YZ[i].plane_proj_A << "\t B: " << P_YZ[i].plane_proj_B << "\t C: " << P_YZ[i].plane_proj_C << "\t D: " << P_YZ[i].plane_proj_D << std::endl;
    }
    std::cout << std::endl;

    // XZ

    for (int i = 0; i < 4; i++)
    {
        // ���������� ���������� ������� ������� (� ��� ����� ���������� ������ �������� ��������, �������������� � ���������� ������)
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(plane_rotation_degree), plane_rotation_axis);
        P_XZ[i].plane_proj_Normal = trans * P_XZ[i].plane_proj_Normal;

        // ���������� ������� ����� � ������ ����� ������
        P_XZ[i].plane_proj_Point_0 = plane_Vertices[i];

        std::cout << "P_XZ[i].plane_proj_Normal "<<"\t x: " << P_XZ[i].plane_proj_Normal.x << "\t y: " << P_XZ[i].plane_proj_Normal.y << "\t z: " << P_XZ[i].plane_proj_Normal.z << std::endl;
        std::cout << "P_XZ[i].plane_proj_Point_0 "<<"\t x: " << P_XZ[i].plane_proj_Point_0.x << "\t y: " << P_XZ[i].plane_proj_Point_0.y << "\t z: " << P_XZ[i].plane_proj_Point_0.z << std::endl;

        // ���������� ������������� ��������� ���������
        P_XZ[i].plane_proj_A = P_XZ[i].plane_proj_Normal.x;
        P_XZ[i].plane_proj_B = 0.0f;
        P_XZ[i].plane_proj_C = P_XZ[i].plane_proj_Normal.z;
        P_XZ[i].plane_proj_D = -(P_XZ[i].plane_proj_A * P_XZ[i].plane_proj_Point_0.x + P_XZ[i].plane_proj_B * P_XZ[i].plane_proj_Point_0.y + P_XZ[i].plane_proj_C * P_XZ[i].plane_proj_Point_0.z);

        std::cout << "A: " << P_XZ[i].plane_proj_A << "\t B: " << P_XZ[i].plane_proj_B << "\t C: " << P_XZ[i].plane_proj_C << "\t D: " << P_XZ[i].plane_proj_D << std::endl;
    }
    std::cout << std::endl;*/
    
    // ����������� ���������, ��������� � ������� ������������� t � y0(x0)

    
     /*��������� �������� Y(X)
     ������������ t �������������� ��� ���������� �� ���� �������� (� ������ ��������� �������� Y(X) t = (y2-y1)/(x2-x1), ���
     y2, x2 - ���������� ��������� ����� �������  (������ ������ ����� � �������), 
     y1, x1 - ���������� ��������� ������ ������� (������ ����� ����� � �������),
     �� ��������� ����� �������� ���������� ������, ��� ��� �������)

    
     y0 ��������������, ������ �� ��������� y = y0 + t*x, ������ �������, ��� y0 = y - t*x
     ������ � �������� y � x - ���������� ������ ������� (����� ����� � �������)
    
     ��� ��������� YX*/

     /*
    for (int i = 0; i < 4; i++)
    {
        next_i = i + 1;
        if (next_i == 4)
        {
            next_i = 0;
        }
        dy = plane_Vertices[next_i].y - plane_Vertices[i].y;
        dx = plane_Vertices[next_i].x - plane_Vertices[i].x;

        if ((dy < 0.1f && dy > -0.1f)&&(dx < 0.1f && dx > -0.1f))
            // ���� ��� ���������� ����� 0, �� �������� �� ��������� ����� �����, �������������� �� ����� �� ���������
            // � ��� ������������ ������ 0
        {
            P_YX[i].plane_a = 0.0f;
            P_YX[i].plane_t = 0.0f;
            P_YX[i].plane_0_coefficient = 0.0f;
            P_YX[i].plane_top_max = P_YX[i].plane_0_coefficient;
            P_YX[i].plane_top_min = P_YX[i].plane_0_coefficient;
            P_YX[i].plane_right_max = P_YX[i].plane_0_coefficient;
            P_YX[i].plane_right_min = P_YX[i].plane_0_coefficient;
        }
        else if (dy < 0.1f && dy > -0.1f)
            // ��������, ���� �� ���������� �� �, ���� ��� ���(�.�. dy = 0 ��� ����� 0), ��
            //������� �������� ���������� ��� �, ������ �������, ��� � �������� ��������� a*y - t*x = y0 �� � �� ���������
            // � ��� ����� ������ ���������, ���� ��� ���� ������������ �0 ��������� ����� �������� ���� (��� �������� ������ ������)
        {
            P_YX[i].plane_a = 1.0f;
            P_YX[i].plane_t = 0.0f;
            P_YX[i].plane_0_coefficient = plane_Vertices[i].y;
            P_YX[i].plane_top_max = P_YX[i].plane_0_coefficient;
            P_YX[i].plane_top_min = P_YX[i].plane_0_coefficient;
            P_YX[i].plane_right_max = findMaxBorder(plane_Vertices[next_i].x, plane_Vertices[i].x);
            P_YX[i].plane_right_min = findMinBorder(plane_Vertices[next_i].x, plane_Vertices[i].x);
        }
        else if (dx < 0.1f && dx > -0.1f)
            // ��������, ���� �� ���������� �� x, ���� ��� ���(�.�. dx = 0 ��� ����� 0), ��
            //������� �������� ���������� ��� �, ������ �������, ��� � �������� ��������� a*y - t*x = y0 �� � �� ���������
            // � ��� ����� ������ ���������, ������ ��� ����� ������������ �0 = � ��������� ����� �������� ���� (��� �������� ������ ������)
        {
            P_YX[i].plane_a = 0.0f; // � = 0, ��������� � ������ �������������� ��� � �� � �� ���������
            P_YX[i].plane_t = -1.0f;// t = -1, ����� ������ ����� �����  (- t*x)
            P_YX[i].plane_0_coefficient = plane_Vertices[i].x;// � ������ ������ �0 = �, ����� ����� � ���������  - t*x = y0 
            // �� ����� �������� � ����� ���� � � ��������� � ��������, ������ �� ��� ������ � ���������(������ ��� �����) 
            P_YX[i].plane_top_max = findMaxBorder(plane_Vertices[next_i].y, plane_Vertices[i].y);
            P_YX[i].plane_top_min = findMinBorder(plane_Vertices[next_i].y, plane_Vertices[i].y);
            P_YX[i].plane_right_max = P_YX[i].plane_0_coefficient;
            P_YX[i].plane_right_min = P_YX[i].plane_0_coefficient;
            
        }
        else // ���� �� ���� �� ������� ���� �� ���� ��������� (������� �� ����������� ���� ��� �� ���������������� � �����)
            // �� ����� �� ������������ ������� ��� ������
        {
            P_YX[i].plane_a = 1.0f;
            P_YX[i].plane_t = dy / dx;
            P_YX[i].plane_0_coefficient = plane_Vertices[i].y - P_YX[i].plane_t * plane_Vertices[i].x;

            P_YX[i].plane_top_max = findMaxBorder(plane_Vertices[next_i].y, plane_Vertices[i].y);
            P_YX[i].plane_top_min = findMinBorder(plane_Vertices[next_i].y, plane_Vertices[i].y);
            P_YX[i].plane_right_max = findMaxBorder(plane_Vertices[next_i].x, plane_Vertices[i].x);
            P_YX[i].plane_right_min = findMinBorder(plane_Vertices[next_i].x, plane_Vertices[i].x);
        }
        
        std::cout << "P_YX[i].plane_t: " << P_YX[i].plane_t << "\t P_YX[i].plane_0_coefficient: " << P_YX[i].plane_0_coefficient << std::endl;
        std::cout << "P_YX[i].plane_top_max: " << P_YX[i].plane_top_max << std::endl;
        std::cout << "P_YX[i].plane_top_min: " << P_YX[i].plane_top_min << std::endl;
        std::cout << "P_YX[i].plane_right_max: " << P_YX[i].plane_right_max << std::endl;
        std::cout << "P_YX[i].plane_right_min: " << P_YX[i].plane_right_min << std::endl;

    }

    std::cout << std::endl;
     // ��������� �������� Y(Z)
    // ������������ t �������������� ��� ���������� �� ���� �������� (� ������ ��������� �������� Y(Z) t = (y2-y1)/(z2-z1), ���
    // y2, z2 - ���������� ��������� ����� �������  (������ ������ ����� � �������), 
    // y1, z1 - ���������� ��������� ������ ������� (������ ����� ����� � �������),
    // �� ��������� ����� �������� ���������� ������, ��� ��� �������)

     //y0 ��������������, ������ �� ��������� y = y0 + t*z, ������ �������, ��� y0 = y - t*z
    // ������ � �������� y � z - ���������� ������ ������� (����� ����� � �������)
     //��� ��������� YZ
    for (int i = 0; i < 4; i++)
    {
        next_i = i + 1;
        if (next_i == 4)
        {
            next_i = 0;
        }
        dy = plane_Vertices[next_i].y - plane_Vertices[i].y;
        dz = plane_Vertices[next_i].z - plane_Vertices[i].z;

        if ((dy < 0.1f && dy > -0.1f) && (dz < 0.1f && dz > -0.1f))
            // ���� ��� ���������� ����� 0, �� �������� �� ��������� ����� �����, �������������� �� ����� �� ���������
            // � ��� ������������ ������ 0
        {
            P_YZ[i].plane_a = 0.0f;
            P_YZ[i].plane_t = 0.0f;
            P_YZ[i].plane_0_coefficient = 0.0f;
            P_YZ[i].plane_top_max = P_YZ[i].plane_0_coefficient;
            P_YZ[i].plane_top_min = P_YZ[i].plane_0_coefficient;
            P_YZ[i].plane_right_max = P_YZ[i].plane_0_coefficient;
            P_YZ[i].plane_right_min = P_YZ[i].plane_0_coefficient;
        }
        else if (dy < 0.1f && dy > -0.1f)
            // ��������, ���� �� ���������� �� �, ���� ��� ���(�.�. dy = 0 ��� ����� 0), ��
            //������� �������� ���������� ��� �, ������ �������, ��� � �������� ��������� a*y - t*x = y0 �� � �� ���������
            // � ��� ����� ������ ���������, ���� ��� ���� ������������ �0 ��������� ����� �������� ���� (��� �������� ������ ������)
        {
            P_YZ[i].plane_a = 1.0f;
            P_YZ[i].plane_t = 0.0f;
            P_YZ[i].plane_0_coefficient = plane_Vertices[i].y;
            P_YZ[i].plane_top_max = P_YZ[i].plane_0_coefficient;
            P_YZ[i].plane_top_min = P_YZ[i].plane_0_coefficient;
            P_YZ[i].plane_right_max = findMaxBorder(plane_Vertices[next_i].z, plane_Vertices[i].z);
            P_YZ[i].plane_right_min = findMinBorder(plane_Vertices[next_i].z, plane_Vertices[i].z);
        }
        else if (dz < 0.1f && dz > -0.1f)
            // ��������, ���� �� ���������� �� x, ���� ��� ���(�.�. dx = 0 ��� ����� 0), ��
            //������� �������� ���������� ��� �, ������ �������, ��� � �������� ��������� a*y - t*x = y0 �� � �� ���������
            // � ��� ����� ������ ���������, ������ ��� ����� ������������ �0 = � ��������� ����� �������� ���� (��� �������� ������ ������)
        {
            P_YZ[i].plane_a = 0.0f; // � = 0, ��������� � ������ �������������� ��� � �� � �� ���������
            P_YZ[i].plane_t = -1.0f;// t = -1, ����� ������ ����� �����  (- t*x)
            P_YZ[i].plane_0_coefficient = plane_Vertices[i].z;// � ������ ������ �0 = �, ����� ����� � ���������  - t*x = y0 
            // �� ����� �������� � ����� ���� � � ��������� � ��������, ������ �� ��� ������ � ���������(������ ��� �����) 
            P_YZ[i].plane_top_max = findMaxBorder(plane_Vertices[next_i].y, plane_Vertices[i].y);
            P_YZ[i].plane_top_min = findMinBorder(plane_Vertices[next_i].y, plane_Vertices[i].y);
            P_YZ[i].plane_right_max = P_YZ[i].plane_0_coefficient;
            P_YZ[i].plane_right_min = P_YZ[i].plane_0_coefficient;

        }
        else // ���� �� ���� �� ������� ���� �� ���� ��������� (������� �� ����������� ���� ��� �� ���������������� � �����)
            // �� ����� �� ������������ ������� ��� ������
        {
            P_YZ[i].plane_a = 1.0f;
            P_YZ[i].plane_t = dy / dz;
            P_YZ[i].plane_0_coefficient = plane_Vertices[i].y - P_YZ[i].plane_t * plane_Vertices[i].z;
               
            P_YZ[i].plane_top_max =   findMaxBorder(plane_Vertices[next_i].y, plane_Vertices[i].y);
            P_YZ[i].plane_top_min =   findMinBorder(plane_Vertices[next_i].y, plane_Vertices[i].y);
            P_YZ[i].plane_right_max = findMaxBorder(plane_Vertices[next_i].z, plane_Vertices[i].z);
            P_YZ[i].plane_right_min = findMinBorder(plane_Vertices[next_i].z, plane_Vertices[i].z);
        }

        std::cout << "P_YZ[i].plane_t: " << P_YZ[i].plane_t << "\t P_YX[i].plane_0_coefficient: " << P_YZ[i].plane_0_coefficient << std::endl;
        std::cout << "P_YZ[i].plane_top_max: " <<   P_YZ[i].plane_top_max << std::endl;
        std::cout << "P_YZ[i].plane_top_min: " <<   P_YZ[i].plane_top_min << std::endl;
        std::cout << "P_YZ[i].plane_right_max: " << P_YZ[i].plane_right_max << std::endl;
        std::cout << "P_YZ[i].plane_right_min: " << P_YZ[i].plane_right_min << std::endl;
    }

    std::cout << std::endl;
     // ��������� �������� X(Z)
    // ������������ t �������������� ��� ���������� �� ���� �������� (� ������ ��������� �������� X(Z) t = (x2-x1)/(z2-z1), ���
    // x2, z2 - ���������� ��������� ����� �������  (������ ������ ����� � �������), 
    // x1, z1 - ���������� ��������� ������ ������� (������ ����� ����� � �������),
    // �� ��������� ����� �������� ���������� ������, ��� ��� �������)

    // y0 ��������������, ������ �� ��������� x = x0 + t*z, ������ �������, ��� x0 = x - t*z
    // ������ � �������� x � z - ���������� ������ ������� (����� ����� � �������)
    // ��� ��������� XZ
    for (int i = 0; i < 4; i++)
    {
        next_i = i + 1;
        if (next_i == 4)
        {
            next_i = 0;
        }
        dx = plane_Vertices[next_i].x - plane_Vertices[i].x;
        dz = plane_Vertices[next_i].z - plane_Vertices[i].z;

        if ((dx < 0.1f && dx > -0.1f) && (dz < 0.1f && dz > -0.1f))
            // ���� ��� ���������� ����� 0, �� �������� �� ��������� ����� �����, �������������� �� ����� �� ���������
            // � ��� ������������ ������ 0
        {
            P_XZ[i].plane_a = 0.0f;
            P_XZ[i].plane_t = 0.0f;
            P_XZ[i].plane_0_coefficient = 0.0f;
            P_XZ[i].plane_top_max =   P_XZ[i].plane_0_coefficient;
            P_XZ[i].plane_top_min =   P_XZ[i].plane_0_coefficient;
            P_XZ[i].plane_right_max = P_XZ[i].plane_0_coefficient;
            P_XZ[i].plane_right_min = P_XZ[i].plane_0_coefficient;
        }
        else if (dx < 0.1f && dx > -0.1f)
            // ��������, ���� �� ���������� �� �, ���� ��� ���(�.�. dy = 0 ��� ����� 0), ��
            //������� �������� ���������� ��� �, ������ �������, ��� � �������� ��������� a*y - t*x = y0 �� � �� ���������
            // � ��� ����� ������ ���������, ���� ��� ���� ������������ �0 ��������� ����� �������� ���� (��� �������� ������ ������)
        {
            P_XZ[i].plane_a = 1.0f;
            P_XZ[i].plane_t = 0.0f;
            P_XZ[i].plane_0_coefficient = plane_Vertices[i].x;
            P_XZ[i].plane_top_max = P_XZ[i].plane_0_coefficient;
            P_XZ[i].plane_top_min = P_XZ[i].plane_0_coefficient;
            P_XZ[i].plane_right_max = findMaxBorder(plane_Vertices[next_i].z, plane_Vertices[i].z);
            P_XZ[i].plane_right_min = findMinBorder(plane_Vertices[next_i].z, plane_Vertices[i].z);
        }
        else if (dz < 0.1f && dz > -0.1f)
            // ��������, ���� �� ���������� �� x, ���� ��� ���(�.�. dx = 0 ��� ����� 0), ��
            //������� �������� ���������� ��� �, ������ �������, ��� � �������� ��������� a*y - t*x = y0 �� � �� ���������
            // � ��� ����� ������ ���������, ������ ��� ����� ������������ �0 = � ��������� ����� �������� ���� (��� �������� ������ ������)
        {
            P_XZ[i].plane_a = 0.0f; // � = 0, ��������� � ������ �������������� ��� � �� � �� ���������
            P_XZ[i].plane_t = -1.0f;// t = -1, ����� ������ ����� �����  (- t*x)
            P_XZ[i].plane_0_coefficient = plane_Vertices[i].z;// � ������ ������ �0 = �, ����� ����� � ���������  - t*x = y0 
            // �� ����� �������� � ����� ���� � � ��������� � ��������, ������ �� ��� ������ � ���������(������ ��� �����) 
            P_XZ[i].plane_top_max = findMaxBorder(plane_Vertices[next_i].x, plane_Vertices[i].x);
            P_XZ[i].plane_top_min = findMinBorder(plane_Vertices[next_i].x, plane_Vertices[i].x);
            P_XZ[i].plane_right_max = P_XZ[i].plane_0_coefficient;
            P_XZ[i].plane_right_min = P_XZ[i].plane_0_coefficient;

        }
        else // ���� �� ���� �� ������� ���� �� ���� ��������� (������� �� ����������� ���� ��� �� ���������������� � �����)
            // �� ����� �� ������������ ������� ��� ������
        {
            P_XZ[i].plane_a = 1.0f;
            P_XZ[i].plane_t = dx / dz;
            P_XZ[i].plane_0_coefficient = plane_Vertices[i].x - P_XZ[i].plane_t * plane_Vertices[i].z;
              
            P_XZ[i].plane_top_max =   findMaxBorder(plane_Vertices[next_i].x, plane_Vertices[i].x);
            P_XZ[i].plane_top_min =   findMinBorder(plane_Vertices[next_i].x, plane_Vertices[i].x);
            P_XZ[i].plane_right_max = findMaxBorder(plane_Vertices[next_i].z, plane_Vertices[i].z);
            P_XZ[i].plane_right_min = findMinBorder(plane_Vertices[next_i].z, plane_Vertices[i].z);
        }

        std::cout << "P_XZ[i].plane_t: " << P_XZ[i].plane_t << "\t P_YX[i].plane_0_coefficient: " << P_XZ[i].plane_0_coefficient << std::endl;
        std::cout << "P_XZ[i].plane_top_max: " <<   P_XZ[i].plane_top_max << std::endl;
        std::cout << "P_XZ[i].plane_top_min: " <<   P_XZ[i].plane_top_min << std::endl;
        std::cout << "P_XZ[i].plane_right_max: " << P_XZ[i].plane_right_max << std::endl;
        std::cout << "P_XZ[i].plane_right_min: " << P_XZ[i].plane_right_min << std::endl;
    }
    std::cout << std::endl;
    */

     //����������� ���������, ��������� � ������� ������������� A,B,C � ��������� ������

     //YX
     for (int i = 0; i < 4; i++)
     {
         next_i = i + 1;
         if (next_i == 4)
         {
             next_i = 0;
         }

         // �������� ������ ����������, ������ �� 2 ����� ���������, �������������� ������� 
         // ����� ��������� (� - �1)/(�2 - �1) = (� - �1)/(�2 - �1), ������ 
         // (� - �1)(�2 - �1) = (� - �1)(�2 - �1)
         // �(�2 - �1) - �1(�2 - �1) - �(�2 - �1) + �1(�2 - �1) = 0
         // �(�2 - �1) + �(�1 - �2) + �1(�2 - �1) - �1(�2 - �1) = 0
         // ����� ������� A = (�2 - �1), B = (�1 - �2), C = -(x1 * A + y1 * B)
         Pl_YX[i].plane_A = plane_Vertices[next_i].y - plane_Vertices[i].y;
         Pl_YX[i].plane_B = plane_Vertices[i].x - plane_Vertices[next_i].x;
         Pl_YX[i].plane_C = -(plane_Vertices[i].x * Pl_YX[i].plane_A + plane_Vertices[i].y * Pl_YX[i].plane_B);
     
         Pl_YX[i].plane_top_max = findMaxPoint(plane_Vertices[next_i].y, plane_Vertices[i].y);
         Pl_YX[i].plane_top_min = findMinPoint(plane_Vertices[next_i].y, plane_Vertices[i].y);
         Pl_YX[i].plane_right_max = findMaxPoint(plane_Vertices[next_i].x, plane_Vertices[i].x);
         Pl_YX[i].plane_right_min = findMinPoint(plane_Vertices[next_i].x, plane_Vertices[i].x);

         std::cout << "i: " << i << std::endl;
         std::cout << "Pl_YX[i].plane_A: " << Pl_YX[i].plane_A << std::endl;
         std::cout << "Pl_YX[i].plane_B: " << Pl_YX[i].plane_B << std::endl;
         std::cout << "Pl_YX[i].plane_C: " << Pl_YX[i].plane_C << std::endl;

         std::cout << "Pl_YX[i].plane_top_max:   " << Pl_YX[i].plane_top_max << std::endl;
         std::cout << "Pl_YX[i].plane_top_min:   " << Pl_YX[i].plane_top_min << std::endl;
         std::cout << "Pl_YX[i].plane_right_max: " << Pl_YX[i].plane_right_max << std::endl;
         std::cout << "Pl_YX[i].plane_right_min: " << Pl_YX[i].plane_A << std::endl;

     }

     //YZ
     for (int i = 0; i < 4; i++)
     {
         next_i = i + 1;
         if (next_i == 4)
         {
             next_i = 0;
         }
         
         // ����� ������� A = (�2 - �1), B = (z1 - z2), C = -(z1 * A + y1 * B)
         Pl_YZ[i].plane_A = plane_Vertices[next_i].y - plane_Vertices[i].y;
         Pl_YZ[i].plane_B = plane_Vertices[i].z - plane_Vertices[next_i].z;
         Pl_YZ[i].plane_C = -(plane_Vertices[i].z * Pl_YZ[i].plane_A + plane_Vertices[i].y * Pl_YZ[i].plane_B);
             
         Pl_YZ[i].plane_top_max =   findMaxPoint(plane_Vertices[next_i].y, plane_Vertices[i].y);
         Pl_YZ[i].plane_top_min =   findMinPoint(plane_Vertices[next_i].y, plane_Vertices[i].y);
         Pl_YZ[i].plane_right_max = findMaxPoint(plane_Vertices[next_i].z, plane_Vertices[i].z);
         Pl_YZ[i].plane_right_min = findMinPoint(plane_Vertices[next_i].z, plane_Vertices[i].z);

         std::cout << "i: " << i << std::endl;
         std::cout << "Pl_YZ[i].plane_A: " <<         Pl_YZ[i].plane_A << std::endl;
         std::cout << "Pl_YZ[i].plane_B: " <<         Pl_YZ[i].plane_B << std::endl;
         std::cout << "Pl_YZ[i].plane_C: " <<         Pl_YZ[i].plane_C << std::endl;
                                                          
         std::cout << "Pl_YZ[i].plane_top_max:   " << Pl_YZ[i].plane_top_max << std::endl;
         std::cout << "Pl_YZ[i].plane_top_min:   " << Pl_YZ[i].plane_top_min << std::endl;
         std::cout << "Pl_YZ[i].plane_right_max: " << Pl_YZ[i].plane_right_max << std::endl;
         std::cout << "Pl_YZ[i].plane_right_min: " << Pl_YZ[i].plane_A << std::endl;
     }

     //XZ
     for (int i = 0; i < 4; i++)
     {
         next_i = i + 1;
         if (next_i == 4)
         {
             next_i = 0;
         }

         // ����� ������� A = (x2 - x1), B = (z1 - z2), C = -(z1 * A + x1 * B)
         Pl_XZ[i].plane_A = plane_Vertices[next_i].x - plane_Vertices[i].x;
         Pl_XZ[i].plane_B = plane_Vertices[i].z - plane_Vertices[next_i].z;
         Pl_XZ[i].plane_C = -(plane_Vertices[i].z * Pl_XZ[i].plane_A + plane_Vertices[i].x * Pl_XZ[i].plane_B);
            
         Pl_XZ[i].plane_top_max = findMaxPoint(plane_Vertices[next_i].x, plane_Vertices[i].x);
         Pl_XZ[i].plane_top_min = findMinPoint(plane_Vertices[next_i].x, plane_Vertices[i].x);
         Pl_XZ[i].plane_right_max = findMaxPoint(plane_Vertices[next_i].z, plane_Vertices[i].z);
         Pl_XZ[i].plane_right_min = findMinPoint(plane_Vertices[next_i].z, plane_Vertices[i].z);

         std::cout << "i: " << i << std::endl;
         std::cout << "Pl_XZ[i].plane_A: " <<         Pl_XZ[i].plane_A << std::endl;
         std::cout << "Pl_XZ[i].plane_B: " <<         Pl_XZ[i].plane_B << std::endl;
         std::cout << "Pl_XZ[i].plane_C: " <<         Pl_XZ[i].plane_C << std::endl;
                                                         
         std::cout << "Pl_XZ[i].plane_top_max:   " << Pl_XZ[i].plane_top_max << std::endl;
         std::cout << "Pl_XZ[i].plane_top_min:   " << Pl_XZ[i].plane_top_min << std::endl;
         std::cout << "Pl_XZ[i].plane_right_max: " << Pl_XZ[i].plane_right_max << std::endl;
         std::cout << "Pl_XZ[i].plane_right_min: " << Pl_XZ[i].plane_A << std::endl;
     }

   // // ������ ��� �������, ������������� ������� 0 � 1
   // dy = plane_Vertices[1].y - plane_Vertices[0].y;
   // dx = plane_Vertices[1].x - plane_Vertices[0].x;
   // plane_t_YX_01 = dy / dx;

   // plane_y0_YX_01 = plane_Vertices[0].y - plane_t_YX_01 * plane_Vertices[0].x;

   // // ������ ��� �������, ������������� ������� 1 � 2
   // dy = plane_Vertices[2].y - plane_Vertices[1].y;
   // dx = plane_Vertices[2].x - plane_Vertices[1].x;
   // plane_t_YX_12 = dy / dx;

   // plane_y0_YX_12 = plane_Vertices[1].y - plane_t_YX_12 * plane_Vertices[1].x;

   // // ������ ��� �������, ������������� ������� 2 � 3
   // dy = plane_Vertices[3].y - plane_Vertices[2].y;
   // dx = plane_Vertices[3].x - plane_Vertices[2].x;
   // plane_t_YX_23 = dy / dx;

   // plane_y0_YX_23 = plane_Vertices[2].y - plane_t_YX_23 * plane_Vertices[2].x;
   // 
   // // ������ ��� �������, ������������� ������� 3 � 0
   // dy = plane_Vertices[0].y - plane_Vertices[3].y;
   // dx = plane_Vertices[0].x - plane_Vertices[3].x;
   // plane_t_YX_30 = dy / dx;

   // plane_y0_YX_30 = plane_Vertices[3].y - plane_t_YX_30 * plane_Vertices[3].x;

   // // ��������� �������� Y(Z)
   // // ������������ t �������������� ��� ���������� �� ���� �������� (� ������ ��������� �������� Y(Z) t = (y2-y1)/(z2-z1), ���
   // // y2, z2 - ���������� ��������� ����� �������  (������ ������ ����� � �������), 
   // // y1, z1 - ���������� ��������� ������ ������� (������ ����� ����� � �������),
   // // �� ��������� ����� �������� ���������� ������, ��� ��� �������)

   // // y0 ��������������, ������ �� ��������� y = y0 + t*z, ������ �������, ��� y0 = y - t*z
   // // ������ � �������� y � z - ���������� ������ ������� (����� ����� � �������)
   // 
   //// ������ ��� �������, ������������� ������� 0 � 1
   // dy = plane_Vertices[1].y - plane_Vertices[0].y;
   // dz = plane_Vertices[1].z - plane_Vertices[0].z;
   // plane_t_YZ_01 = dy / dz;

   // plane_y0_YZ_01 = plane_Vertices[0].y - plane_t_YZ_01 * plane_Vertices[0].z;

   // // ������ ��� �������, ������������� ������� 1 � 2
   // dy = plane_Vertices[2].y - plane_Vertices[1].y;
   // dz = plane_Vertices[2].z - plane_Vertices[1].z;
   // plane_t_YZ_12 = dy / dz;

   // plane_y0_YZ_12 = plane_Vertices[1].y - plane_t_YZ_12 * plane_Vertices[1].z;

   // // ������ ��� �������, ������������� ������� 2 � 3
   // dy = plane_Vertices[3].y - plane_Vertices[2].y;
   // dz = plane_Vertices[3].z - plane_Vertices[2].z;
   // plane_t_YZ_23 = dy / dz;

   // plane_y0_YZ_23 = plane_Vertices[2].y - plane_t_YZ_23 * plane_Vertices[2].z;

   // // ������ ��� �������, ������������� ������� 3 � 0
   // dy = plane_Vertices[0].y - plane_Vertices[3].y;
   // dz = plane_Vertices[0].z - plane_Vertices[3].z;
   // plane_t_YZ_30 = dy / dz;

   // plane_y0_YZ_30 = plane_Vertices[3].y - plane_t_YZ_30 * plane_Vertices[3].z;

   // // ��������� �������� X(Z)
   // // ������������ t �������������� ��� ���������� �� ���� �������� (� ������ ��������� �������� X(Z) t = (x2-x1)/(z2-z1), ���
   // // x2, z2 - ���������� ��������� ����� �������  (������ ������ ����� � �������), 
   // // x1, z1 - ���������� ��������� ������ ������� (������ ����� ����� � �������),
   // // �� ��������� ����� �������� ���������� ������, ��� ��� �������)

   // // y0 ��������������, ������ �� ��������� x = x0 + t*z, ������ �������, ��� x0 = x - t*z
   // // ������ � �������� x � z - ���������� ������ ������� (����� ����� � �������)

   //// ������ ��� �������, ������������� ������� 0 � 1
   // dx = plane_Vertices[1].x - plane_Vertices[0].x;
   // dz = plane_Vertices[1].z - plane_Vertices[0].z;
   // plane_t_XZ_01 = dx / dz;

   // plane_x0_XZ_01 = plane_Vertices[0].x - plane_t_XZ_01 * plane_Vertices[0].z;

   // // ������ ��� �������, ������������� ������� 1 � 2
   // dx = plane_Vertices[2].x - plane_Vertices[1].x;
   // dz = plane_Vertices[2].z - plane_Vertices[1].z;
   // plane_t_XZ_12 = dx / dz;

   // plane_x0_XZ_12 = plane_Vertices[1].x - plane_t_XZ_12 * plane_Vertices[1].z;

   // // ������ ��� �������, ������������� ������� 2 � 3
   // dx = plane_Vertices[3].x - plane_Vertices[2].x;
   // dz = plane_Vertices[3].z - plane_Vertices[2].z;
   // plane_t_XZ_23 = dx / dz;

   // plane_x0_XZ_23 = plane_Vertices[2].x - plane_t_XZ_23 * plane_Vertices[2].z;

   // // ������ ��� �������, ������������� ������� 3 � 0
   // dx = plane_Vertices[0].x - plane_Vertices[3].x;
   // dz = plane_Vertices[0].z - plane_Vertices[3].z;
   // plane_t_XZ_30 = dx / dz;

   // plane_x0_XZ_30 = plane_Vertices[3].x - plane_t_XZ_30 * plane_Vertices[3].z;

}

void collisionPlane::DrawPlane(glm::mat4 &view, glm::mat4 &projection)
{

    plane_shader.use();
    // world transformation
    plane_shader.setMat4("projection", projection);
    plane_shader.setMat4("view", view);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(plane_rotation_degree), plane_rotation_axis);
    model = glm::scale( model, plane_scale);
    model = glm::translate(model, plane_position);
    plane_shader.setMat4("model", model);

    plane_shader.setVec3("objectColor", plane_color);
    // render the cube
    glBindVertexArray(plane_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

float collisionPlane::result(glm::vec4 &cube_vertex)
{
    float result = plane_A * cube_vertex.x + plane_B * cube_vertex.y + plane_C * cube_vertex.z + plane_D;
    
    return result;
}

float collisionPlane::minX()
{
    return plane_Xmin;
}

float collisionPlane::maxX()
{
    return plane_Xmax;
}

float collisionPlane::minY()
{
    return plane_Ymin;
}

float collisionPlane::maxY()
{
    return plane_Ymax;
}

float collisionPlane::minZ()
{
    return plane_Zmin;
}

float collisionPlane::maxZ()
{
    return plane_Zmax;
}


// ������ ��� ��������, ��������� � ������� ��������� ���������

/*
float collisionPlane::isOnProjectionYX(glm::vec4 vertex, int index)
{
    float result;
    result = P_YX[index].plane_proj_A* vertex.x + P_YX[index].plane_proj_B * vertex.y + P_YX[index].plane_proj_C * vertex.z + P_YX[index].plane_proj_D;
    //std::cout << "YX index: " << index << "\t result: " << result << std::endl;
    return result;
}

float collisionPlane::isOnProjectionYZ(glm::vec4 vertex, int index)
{
    float result;
    result = P_YZ[index].plane_proj_A * vertex.x + P_YZ[index].plane_proj_B * vertex.y + P_YZ[index].plane_proj_C * vertex.z + P_YZ[index].plane_proj_D;
    //std::cout << "YZ index: " << index << "\t result: " << result << std::endl;
    return result;
}

float collisionPlane::isOnProjectionXZ(glm::vec4 vertex, int index)
{
    float result;
    result = P_XZ[index].plane_proj_A * vertex.x + P_XZ[index].plane_proj_B * vertex.y + P_XZ[index].plane_proj_C * vertex.z + P_XZ[index].plane_proj_D;
    //std::cout << "XZ index: " << index << "\t result: " << result << std::endl;
    return result;
}*/



// ������ ��� �������� � ��������� � �������������� t y(0)x(0)


/*
bool collisionPlane::ProjectionYX(glm::vec4 vertex)
{
    bool YX_isFirstLimit = true;
    float YX_first_limit = 0.0f, YX_second_limit = 0.0f;


    // ��� X
    for (int i = 0; i < 4; i++)
    {
        int next_i = i + 1;
        if (next_i == 4)
        {
            next_i = 0;
        }

        if (
            (vertex.x >= plane_Vertices[next_i].x && vertex.x < plane_Vertices[i].x)
            ||
            (vertex.x <= plane_Vertices[next_i].x && vertex.x > plane_Vertices[i].x)
            )
        {
            float number = vertex.y - (P_YX[i].plane_0_coefficient + P_YX[i].plane_t * vertex.x);

            if (YX_isFirstLimit == true)
            {
                YX_first_limit = number;
                YX_isFirstLimit = false;
            }
            else
            {
                YX_second_limit = number;
                break;
            }
        }
    }

    if (
        (YX_first_limit > 0 && YX_second_limit < 0)
        ||
        (YX_first_limit < 0 && YX_second_limit > 0)
        )
    {
        return true;
    }

    return false;
}

bool collisionPlane::ProjectionYZ(glm::vec4 vertex)
{
    bool isFirstLimit = true;
    float first_limit = 0.0f, second_limit = 0.0f;


    // ��� Z
    for (int i = 0; i < 4; i++)
    {
        int next_i = i + 1;
        if (next_i == 4)
        {
            next_i = 0;
        }

        if (
            (vertex.z >= plane_Vertices[next_i].z && vertex.z < plane_Vertices[i].z)
            ||
            (vertex.z <= plane_Vertices[next_i].z && vertex.z > plane_Vertices[i].z)
            )
        {
            float number = vertex.y - (P_YZ[i].plane_0_coefficient + P_YZ[i].plane_t * vertex.z);

            if (isFirstLimit == true)
            {
                first_limit = number;
                isFirstLimit = false;
            }
            else
            {
                second_limit = number;
                break;
            }
        }
    }

    if (
        (first_limit > 0 && second_limit < 0)
        ||
        (first_limit < 0 && second_limit > 0)
        )
    {
        return true;
    }

    return false;
}

bool collisionPlane::ProjectionXZ(glm::vec4 vertex)
{
    bool isFirstLimit = true;
    float first_limit = 0.0f, second_limit = 0.0f;


    // ��� Z
    for (int i = 0; i < 4; i++)
    {
        int next_i = i + 1;
        if (next_i == 4)
        {
            next_i = 0;
        }

        if (
            (vertex.z >= plane_Vertices[next_i].z && vertex.z < plane_Vertices[i].z)
            ||
            (vertex.z <= plane_Vertices[next_i].z && vertex.z > plane_Vertices[i].z)
            )
        {
            float number = vertex.x - (P_XZ[i].plane_0_coefficient + P_XZ[i].plane_t * vertex.z);

            if (isFirstLimit == true)
            {
                first_limit = number;
                isFirstLimit = false;
            }
            else
            {
                second_limit = number;
                break;
            }
        }
    }

    if (
        (first_limit > 0 && second_limit < 0)
        ||
        (first_limit < 0 && second_limit > 0)
        )
    {
        return true;
    }

    return false;
}

float collisionPlane::findMaxBorder(float begin_point_coord, float end_point_coord)
{
    if (begin_point_coord >= end_point_coord)
    {
        return begin_point_coord;
    }
    else
    {
        return end_point_coord;
    }
}

float collisionPlane::findMinBorder(float begin_point_coord, float end_point_coord)
{
    if (begin_point_coord >= end_point_coord)
    {
        return end_point_coord;
    }
    else
    {
        return begin_point_coord;
    }
    
}

bool collisionPlane::isInProjectionOfPlane(glm::vec4 vertex_position)
{
    bool YX = ProjectionYX(vertex_position);
    if (YX == false)
    {
        return false;
    }

    bool YZ = ProjectionYZ(vertex_position);
    if (YZ == false)
    {
        return false;
    }

    bool XZ = ProjectionXZ(vertex_position);
    if (XZ == false)
    {
        return false;
    }

    
    
    return true;

}
*/


//int collisionPlane::PlaneProjectionYX(glm::vec4 vertex)
//{
//
//    //��������� ������������ � �������� ���� (������ �����)
//    int inPlane = 0;//� ������, ���� ����� ����� � �������� ��������� ��������
//    int upper_plane = 1;// � ������, ���� ����� ����� ���� ��������� �������� (YX_first_limit � YX_second_limit ����� ������ ����)
//    int lower_plane = 2;// � ������, ���� ����� ����� ���� ��������� �������� (YX_first_limit � YX_second_limit ����� ������ ����)
//    int not_in_limit_of_plane = 4; // � ������, ���� ����� ����� ��� ������ ��������� (�.�. ��� �������� ������������ � ����������� �������� �� ���� ����)
//
//    bool YX_isFirstLimit = true;
//    float YX_first_limit = 0.0f, YX_second_limit = 0.0f;
//
//
//    // ��� X
//    for (int i = 0; i < 4; i++)
//    {
//        
//
//
//        int next_i = i + 1;
//        if (next_i == 4)
//        {
//            next_i = 0;
//        }
//
//        if (
//            (vertex.x >= plane_Vertices[next_i].x && vertex.x < plane_Vertices[i].x)
//            ||
//            (vertex.x <= plane_Vertices[next_i].x && vertex.x > plane_Vertices[i].x)
//            )
//        {
//            float number = vertex.y - (P_YX[i].plane_0_coefficient + P_YX[i].plane_t * vertex.x);
//
//            if (YX_isFirstLimit == true)
//            {
//                YX_first_limit = number;
//                YX_isFirstLimit = false;
//            }
//            else
//            {
//                YX_second_limit = number;
//                break;
//            }
//        }
//    }
//
//    if (
//        (YX_first_limit > 0 && YX_second_limit < 0)
//        ||
//        (YX_first_limit < 0 && YX_second_limit > 0)
//        )
//    {
//        return inPlane;
//    }
//    if (YX_first_limit > 0 && YX_second_limit > 0)
//    {
//        return upper_plane;
//    }
//    if (YX_first_limit < 0 && YX_second_limit < 0)
//    {
//        return lower_plane;
//    }
//    else
//    {
//        return not_in_limit_of_plane;
//    }
//
//    
//}
//
//int collisionPlane::PlaneProjectionYZ(glm::vec4 vertex)
//{
//
//    //��������� ������������ � �������� ���� (������ �����)
//    int inPlane = 0;//� ������, ���� ����� ����� � �������� ��������� ��������
//    int upper_plane = 1;// � ������, ���� ����� ����� ���� ��������� �������� (YX_first_limit � YX_second_limit ����� ������ ����)
//    int lower_plane = 2;// � ������, ���� ����� ����� ���� ��������� �������� (YX_first_limit � YX_second_limit ����� ������ ����)
//    int not_in_limit_of_plane = 4; // � ������, ���� ����� ����� ��� ������ ��������� (�.�. ��� �������� ������������ � ����������� �������� �� ���� ����)
//
//    bool YZ_isFirstLimit = true;
//    float YZ_first_limit = 0.0f, YZ_second_limit = 0.0f;
//
//
//    // ��� Z
//    for (int i = 0; i < 4; i++)
//    {
//
//
//
//        int next_i = i + 1;
//        if (next_i == 4)
//        {
//            next_i = 0;
//        }
//
//        if (
//            (vertex.z >= plane_Vertices[next_i].z && vertex.z < plane_Vertices[i].z)
//            ||
//            (vertex.z <= plane_Vertices[next_i].z && vertex.z > plane_Vertices[i].z)
//            )
//        {
//            float number = vertex.y - (P_YZ[i].plane_0_coefficient + P_YZ[i].plane_t * vertex.z);
//
//            if (YZ_isFirstLimit == true)
//            {
//                YZ_first_limit = number;
//                YZ_isFirstLimit = false;
//            }
//            else
//            {
//                YZ_second_limit = number;
//                break;
//            }
//        }
//    }
//
//    if (
//        (YZ_first_limit > 0 && YZ_second_limit < 0)
//        ||
//        (YZ_first_limit < 0 && YZ_second_limit > 0)
//        )
//    {
//        return inPlane;
//    }
//    if (YZ_first_limit > 0 && YZ_second_limit > 0)
//    {
//        return upper_plane;
//    }
//    if (YZ_first_limit < 0 && YZ_second_limit < 0)
//    {
//        return lower_plane;
//    }
//    else
//    {
//        return not_in_limit_of_plane;
//    }
//
//
//}
//
//int collisionPlane::PlaneProjectionXZ(glm::vec4 vertex)
//{
//    std::cout << "vertex.x: " << vertex.x << "\t vertex.z: " << vertex.z << std::endl;
//    //��������� ������������ � �������� ���� (������ �����)
//    int inPlane = 0;//� ������, ���� ����� ����� � �������� ��������� ��������
//    int upper_plane = 1;// � ������, ���� ����� ����� ���� ��������� �������� (YX_first_limit � YX_second_limit ����� ������ ����)
//    int lower_plane = 2;// � ������, ���� ����� ����� ���� ��������� �������� (YX_first_limit � YX_second_limit ����� ������ ����)
//    int not_in_limit_of_plane = 3; // � ������, ���� ����� ����� ��� ������ ��������� (�.�. ��� �������� ������������ � ����������� �������� �� ���� ����)
//
//    bool XZ_isFirstLimit = true;
//    float XZ_first_limit = 0.0f, XZ_second_limit = 0.0f;
//
//
//    // ��� Z
//    for (int i = 0; i < 4; i++)
//    {
//
//
//
//        int next_i = i + 1;
//        if (next_i == 4)
//        {
//            next_i = 0;
//        }
//
//        if (
//            (vertex.z >= plane_Vertices[next_i].z && vertex.z < plane_Vertices[i].z)
//            ||
//            (vertex.z <= plane_Vertices[next_i].z && vertex.z > plane_Vertices[i].z)
//            )
//        {
//            float number = vertex.x - (P_XZ[i].plane_0_coefficient + P_XZ[i].plane_t * vertex.z);
//
//            
//            
//            if (XZ_isFirstLimit == true)
//            {
//                XZ_first_limit = number;
//                std::cout << "XZ_first_limit: " << XZ_first_limit << "\t i: " << i << "\t next i " << next_i << std::endl;
//                XZ_isFirstLimit = false;
//            }
//            else
//            {
//                XZ_second_limit = number;
//                std::cout << "XZ_second_limit: " << XZ_second_limit << "\t i: " << i << "\t next i " << next_i << std::endl;
//                std::cout << std::endl;
//                break;
//            }
//        }
//    }
//
//
//
//    if (
//        (XZ_first_limit > 0 && XZ_second_limit < 0)
//        ||
//        (XZ_first_limit < 0 && XZ_second_limit > 0)
//        )
//    {
//        return inPlane;
//    }
//    if (XZ_first_limit > 0 && XZ_second_limit > 0)
//    {
//        return upper_plane;
//    }
//    if (XZ_first_limit < 0 && XZ_second_limit < 0)
//    {
//        return lower_plane;
//    }
//    else
//    {
//        return not_in_limit_of_plane;
//    }
//

