
// gọi các thư viện
#include <GL/glut.h>


// Vẽ trục tọa độ
void truc() {
    glBegin(GL_LINES);
    // vẽ trục x
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(20.0, 0.0, 0.0);

    // vẽ trục y
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 20.0, 0.0);

    // vẽ trục z
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 20.0);
    glEnd();

}

// Khởi tạo các giá trị
struct block {
    // vị trí của khối
    int pos_i, pos_j, pos_k;
    //6 mặt Rubik
    int top, bottom, left, right, front, back;
};

// kích thước
#define SIZE 3
block cube[SIZE][SIZE][SIZE];

// xoay khối Rubik
GLint rot_x = 0, rot_y = 0;

//thiết lập lại vị trí của các khối cube(nhỏ) để đổi vị trí  
void rotate90(int& x, int& y)
{
    x -= 1;
    y -= 1;
    int temp = x;
    x = -y;
    y = temp;
    x += 1;
    y += 1;
}

//thiết lập lại vị trí của các khối cube(nhỏ) để đổi vị trí 
void rotate_minus_90(int& x, int& y)
{
    x -= 1;
    y -= 1;
    int temp = x;
    x = y;
    y = -temp;
    x += 1;
    y += 1;
}

//xoay mặt trái theo chiều kim đồng hồ (nhấn phím a)
void rotate_left_clockwise()
{
    
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_i == 0) // tất cả các cube có vị tri pos_i = 0 sẽ xoay
                {
                    // thiết lập lại vị trí các khối cube
                    rotate_minus_90(t.pos_j, t.pos_k);
                    //đổi màu các mặt
                    int temp = t.top;
                    t.top = t.front;
                    t.front = t.bottom;
                    t.bottom = t.back;
                    t.back = temp;
                }

            }
}
//xoay mặt trái ngược chiều kim đồng hồ (nhấn phím s)
void rotate_left_anticlockwise()
{

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_i == 0) // tất cả các cube có vị tri pos_i = 0 sẽ xoay
                {
                    //thiết lập lại vị trí các khối cube
                    rotate90(t.pos_j, t.pos_k);
                    //đổi màu các mặt
                    int temp = t.top;
                    t.top = t.back;
                    t.back = t.bottom;
                    t.bottom = t.front;
                    t.front = temp;
                }

            }


}

//xoay mặt phải ngược chiều kim đồng hồ (nhấn phím f)
void rotate_right_anticlockwise()
{

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_i == 2) // tất cả các cube có vị tri pos_i = 2 sẽ xoay
                {
                    //thiết lập lại vị trí các khối cube
                    rotate90(t.pos_j, t.pos_k);
                    //đổi màu các mặt
                    int temp = t.top;
                    t.top = t.back;
                    t.back = t.bottom;
                    t.bottom = t.front;
                    t.front = temp;
                }

            }


}




//xoay mặt phải theo chiều kim đồng hồ (nhấn phím d)
void rotate_right_clockwise()
{

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_i == 2) // tất cả các cube có vị tri pos_i = 2 sẽ xoay
                {
                    //thiết lập lại vị trí các khối cube
                    rotate_minus_90(t.pos_j, t.pos_k);
                    //đổi màu các mặt
                    int temp = t.top;
                    t.top = t.front;
                    t.front = t.bottom;
                    t.bottom = t.back;
                    t.back = temp;
                }

            }


}



//xoay mặt trước theo chiều kim đồng hồ (nhấn phím z)
void rotate_front_clockwise()
{

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_k == 2) 
                {
   
                    rotate_minus_90(t.pos_i, t.pos_j);
                    int temp = t.top;
                    t.top = t.left;
                    t.left = t.bottom;
                    t.bottom = t.right;
                    t.right = temp;
                }

            }


}



//xoay mặt trước ngược chiều kim đồng hồ (nhấn phím x)
void rotate_front_anticlockwise()
{

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_k == 2) 
                {
                    
                    rotate90(t.pos_i, t.pos_j);
                    int temp = t.top;
                    t.top = t.right;
                    t.right = t.bottom;
                    t.bottom = t.left;
                    t.left = temp;
                }

            }


}




//xoay mặt sau theo chiều kim đồng hồ (nhấn phím c)
void rotate_back_clockwise()
{

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_k == 0) 
                {
                    
                    rotate_minus_90(t.pos_i, t.pos_j);
                    int temp = t.top;
                    t.top = t.left;
                    t.left = t.bottom;
                    t.bottom = t.right;
                    t.right = temp;
                }

            }


}




//xoay mặt sau ngược chiều kim đồng hồ (nhấn phím v)
void rotate_back_anticlockwise()
{

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_k == 0) 
                {
                    
                    rotate90(t.pos_i, t.pos_j);
                    int temp = t.top;
                    t.top = t.right;
                    t.right = t.bottom;
                    t.bottom = t.left;
                    t.left = temp;
                }

            }


}



//xoay mặt trên ngược chiều kim đồng hồ (nhấn phím w)
void rotate_top_anticlockwise()
{

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_j == 2)
                {
                   
                    rotate_minus_90(t.pos_i, t.pos_k);
                    int temp = t.back;
                    t.back = t.right;
                    t.right = t.front;
                    t.front = t.left;
                    t.left = temp;
                }

            }


}



//xoay mặt trên theo chiều kim đồng hồ (nhấn phím q)
void rotate_top_clockwise()
{

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_j == 2) 
                {
                    
                    rotate90(t.pos_i, t.pos_k);
                    int temp = t.back;
                    t.back = t.left;
                    t.left = t.front;
                    t.front = t.right;
                    t.right = temp;
                }

            }


}




//xoay mặt dưới ngược chiều kim đồng hồ (nhấn phím r)
void rotate_bottom_anticlockwise()
{

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_j == 0) 
                {
                    
                    rotate_minus_90(t.pos_i, t.pos_k);
                    int temp = t.back;
                    t.back = t.right;
                    t.right = t.front;
                    t.front = t.left;
                    t.left = temp;
                }

            }


}

//xoay mặt dưới theo chiều kim đồng hồ (nhấn phím e)
void rotate_bottom_clockwise()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                block& t = cube[i][j][k];
                if (t.pos_j == 0) 
                {
                    rotate90(t.pos_i, t.pos_k);
                    int temp = t.back;
                    t.back = t.left;
                    t.left = t.front;
                    t.front = t.right;
                    t.right = temp;
                }

            }


}
//thiết lập ma trận lưu trữ các điểm màu
float materialColor[7][3] =
{
    //màu trắng
  {1.0, 1.0, 1.0},
  //màu red
  {1.0, 0.0, 0.0},
  //màu green
  {0.0, 1.0, 0.0},
  //màu blue
  {0.0, 0.0, 1.0},
  //màu yellow
  {1.0, 1.0, 0.0},
  //màu orange
  {1.0, 0.5, 0.0},
  //màu black
  {0.0, 0.0, 0.0}
};

//thiết lập ma trận lưu trữ các điểm vẽ của khối cube(tạo điểm để vẽ)
//6 mặt, mỗi mặt 4 điểm, vị trí xyz mỗi điểm
float cube_vertexes[6][4][3] =
{
  {
    {-1.0, -1.0, -1.0},
    {-1.0, -1.0, 1.0},
    {-1.0, 1.0, 1.0},
    {-1.0, 1.0, -1.0}},

  {
    {1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0},
    {1.0, -1.0, -1.0},
    {1.0, 1.0, -1.0}},

  {
    {-1.0, -1.0, -1.0},
    {1.0, -1.0, -1.0},
    {1.0, -1.0, 1.0},
    {-1.0, -1.0, 1.0}},

  {
    {1.0, 1.0, 1.0},
    {1.0, 1.0, -1.0},
    {-1.0, 1.0, -1.0},
    {-1.0, 1.0, 1.0}},

  {
    {-1.0, -1.0, -1.0},
    {-1.0, 1.0, -1.0},
    {1.0, 1.0, -1.0},
    {1.0, -1.0, -1.0}},

  {
    {1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0},
    {-1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0}}
};

//điều chỉnh các mặt nhận được ánh sáng
float cube_normals[6][3] =
{
  {-1.0, 0.0, 0.0},
  {1.0, 0.0, 0.0},
  {0.0, -1.0, 0.0},
  {0.0, 1.0, 0.0},
  {0.0, 0.0, -1.0},
  {0.0, 0.0, 1.0}
};

//thiết lập màu cho các mặt cube
void setColor(int c)
{
    glColor3fv(&materialColor[c][0]);
}

//vẽ  khối cube
void draw_cube(int x, int y, int z)
{
    //tạo ma trận
    glPushMatrix();
    //tạo biến ma trận t (lưu vị trí)
    block t = cube[x][y][z];
    //tạo biến mảng color_array (lưu màu)
    int color_array[] = { t.front, t.left, t.right, t.bottom ,t.top, t.back };
    //tịnh tiến khối cube
    glTranslatef(  2.5 * t.pos_i, 2.5 * t.pos_j, 2.5 * t.pos_k);
    //vẽ khối
    for (int i = 0; i < 6; i++) {
        setColor(color_array[(i + 1) % 6]);
        glBegin(GL_QUADS);
        glNormal3fv(&cube_normals[i][0]);
        glVertex3fv(&cube_vertexes[i][0][0]);
        glVertex3fv(&cube_vertexes[i][1][0]);
        glVertex3fv(&cube_vertexes[i][2][0]);
        glVertex3fv(&cube_vertexes[i][3][0]);
        glEnd();
    }

    glPopMatrix();

}

// hiển thị 
void display()
{
    //vô hiệu hóa hiệu ứng chiếu sáng
    glDisable(GL_LIGHTING);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    //điểm nhìn
    gluLookAt(0, 15, 30, 0, 0, 0, 0, 1, 0);
    //vẽ trục
    truc();
    //cho phép chiếu sáng
    glEnable(GL_LIGHTING);
    //xoay quanh x
    glRotatef(rot_x, 1.0, 0.0, 0.0);
    //xoay quanh y
    glRotatef(rot_y, 0.0, 1.0, 0.0);
    //tịnh tiến khối rubik
    glTranslatef(-2.5,-2.5,-2.5);
    //vẽ các khối cude
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) {
                draw_cube(i, j, k);
            }
    //thay đổi hiển thị
    glutSwapBuffers();
}

//định dạng khối cube
void initcube() {
    //thiết lập màu đen các khối cube
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {          
                block& t = cube[i][j][k];               
                t.front = t.back = t.top = t.bottom = t.left = t.right = 6;
            }
    //thiết lập màu cho các mặt ngoài của các khối cube
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            cube[0][i][j].left = 1;
            cube[2][i][j].right = 5;
            cube[i][0][j].bottom = 4;
            cube[i][2][j].top = 0;
            cube[i][j][0].back = 2;
            cube[i][j][2].front = 3;

        }
    //thiết lập vị trí các khối
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++) {
                cube[i][j][k].pos_i = SIZE + i - 3;
                cube[i][j][k].pos_j = SIZE + j - 3;
                cube[i][j][k].pos_k = SIZE + k - 3;
            }
}

//thiết lập chiếu sáng
void InitLighting(){
    //chiếu sáng đối tượng
    GLfloat ambient_light[4] = { 0.2,0.2,0.2,1.0 };
    //màu sắc
    GLfloat diffuse_light[4] = { 0.7,0.7,0.7,1.0 };
    //độ sáng
    GLfloat specular_light[4] = { 1.0, 1.0, 1.0, 1.0 };	
    //điểm chiếu sáng
    GLfloat light_position[4] = { 0.0, 50.0, 50.0, 1.0 };


    //truyền tham số
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    //cho phép thay đổi màu sắc
    glEnable(GL_COLOR_MATERIAL);
    //Cho phép chiếu sáng
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

//Khung chương trình
void Init()
{
    
    InitLighting();

    //màu nền
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   
    //cho phép hiển thị theo độ sâu
    glEnable(GL_DEPTH_TEST);
    initcube();

}
//thiết lập góc nhìn
void reshape_func(int w, int h)
{
    glViewport(0, 0, w, h);
    float ratio = (float)w / (float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, ratio, 1.0, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// sự kiện nhấn các phím
void keyboard_func(unsigned char key, int x, int y)
{

    switch (key) {
        // thiết lập xoay đối tượng
    case 'l': // Phải
        rot_y = (rot_y - 5) % 360;
        break;

    case 'j': // Trái
        rot_y = (rot_y + 5) % 360;
        break;

    case 'i': // Xuống
        rot_x = (rot_x + 5) % 360;
        break;

    case 'k': // Lên
        rot_x = (rot_x - 5) % 360;
        break;

        //các phím điều khiển
    case 'a':rotate_left_clockwise(); break;
    case 'd':rotate_right_clockwise(); break;
    case 'q':rotate_top_clockwise(); break;
    case 'e':rotate_bottom_clockwise(); break;
    case 'z':rotate_front_clockwise(); break;
    case 'c':rotate_back_clockwise(); break;
    case 's':rotate_left_anticlockwise(); break;
    case 'f':rotate_right_anticlockwise(); break;
    case 'w':rotate_top_anticlockwise(); break;
    case 'r': rotate_bottom_anticlockwise(); break;
    case 'x':rotate_front_anticlockwise(); break;
    case 'v': rotate_back_anticlockwise(); break;
        

    default:
        break;

    }

    glutPostRedisplay();

}
//hàm main
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rubik 3D");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape_func);
    Init();
    glutKeyboardFunc(keyboard_func);
    glutMainLoop();
}
