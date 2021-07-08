#include<windows.h>
#include<GL/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void ukuran(int, int);

int is_depth;
int h, j, g, k, l, m;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 3.0;
        break;
    case 'd':
    case 'D':
        xmov += 3.0;
        break;
    case 's':
    case 'S':
        zmov -= 3.0;
        break;
    case 'a':
    case 'A':
        xmov -= 3.0;
        break;
    case '7':
        ymov += 3.0;
        break;
    case '9':
        ymov -= 3.0;
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, lebar / tinggi, 5.0, 750.0);
    glTranslatef(0.0, -10.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

void building()
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(3.0);
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();

    glBegin(GL_QUADS);// ALAS DEPAN
    glColor3ub(145, 143, 140);
    glVertex3f(150.0, -23.0, 30.0); //PANJANG,Y,X
    glVertex3f(-10.0, -23.0, 30.0);
    glVertex3f(-10.0, -23.0, -80.0);
    glVertex3f(150.0, -23.0, -80.0);
    glEnd();

glBegin(GL_QUADS);// TUTUP ATAS LOBBY
    glColor3ub(99, 82, 52);
    glVertex3f(155.0, 50.0, 30.0);//atas1
    glVertex3f(-15.0, 50.0, 30.0);
    glVertex3f(-15.0, 50.0, -85.0);
    glVertex3f(155.0, 50.0, -85.0);

    glVertex3f(155.0, 40.0, 30.0);//atas2
    glVertex3f(-15.0, 40.0, 30.0);
    glVertex3f(-15.0, 40.0, -85.0);
    glVertex3f(155.0, 40.0, -85.0);

    glVertex3f(155.0, 30.0, 30.0);//atas 3
    glVertex3f(-15.0, 30.0, 30.0);
    glVertex3f(-15.0, 30.0, -85.0);
    glVertex3f(155.0, 30.0, -85.0);
    glEnd();

    glBegin(GL_QUADS); // TEMBOK DIKIT ATAP LOBBY
    glColor3ub(139, 163, 145);
    glVertex3f(155.0, 40.0, 30.0); //KIRI
    glVertex3f(155.0, 50.0, 30.0);
    glVertex3f(155.0, 50.0, -85.0);
    glVertex3f(155.0, 40.0, -85.0);

    glVertex3f(-15.0, 40.0, 30.0); //KANAN
    glVertex3f(-15.0, 50.0, 30.0);
    glVertex3f(-15.0, 50.0, -85.0);
    glVertex3f(-15.0, 40.0, -85.0);

    glVertex3f(155.0, 50.0, -85.0); //DEPAN
    glVertex3f(-15.0, 50.0, -85.0);
    glVertex3f(-15.0, 40.0, -85.0);
    glVertex3f(155.0, 40.0, -85.0);
    glEnd();

    glBegin(GL_TRIANGLES);//ATAP LOBBY
    glColor3ub(173, 92, 38);
     glVertex3f(150, 40, -80);//DEPAN
     glVertex3f(70.3, 80, -30.0);
     glVertex3f(-10, 40, -80);

     glVertex3f(150.0, 40, 30.0);//BELAKANG
     glVertex3f(70.3, 80, -30.0);
     glVertex3f(-10.0, 40, 30.0);

     glVertex3f(-10, 40, -80);//KANAN
     glVertex3f(70.3, 80, -30);
     glVertex3f(-10, 40, 30);

     glVertex3f(150, 40, -80);//KIRI
     glVertex3f(70.3, 80, -30);
     glVertex3f(150, 40, 30);
    glEnd();

    glBegin(GL_QUADS);// tiang kiri depan lobby
    glColor3ub(66, 45, 9);
    glVertex3f(150.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(150.0, 50.0, -70.0);
    glVertex3f(150.0, 50.0, -80.0);
    glVertex3f(150.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tiang kiri depan lobby
    glColor3ub(66, 45, 9);
    glVertex3f(145.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(145.0, 50.0, -70.0);
    glVertex3f(145.0, 50.0, -80.0);
    glVertex3f(145.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tiang kiri depan lobby
    glColor3ub(66, 45, 9);
    glVertex3f(150.0, -24.0, -80.0); //PANJANG,Y,X
    glVertex3f(150.0, 50.0, -80.0);
    glVertex3f(145.0, 50.0, -80.0);
    glVertex3f(145.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tiang kiri depan lobby
    glColor3ub(66, 45, 9);
    glVertex3f(150.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(150.0, 50.0, -70.0);
    glVertex3f(145.0, 50.0, -70.0);
    glVertex3f(145.0, -24.0, -70.0);
    glEnd();

       glBegin(GL_QUADS);// tiang kiri belakang lobby
    glColor3ub(66, 45, 9);
    glVertex3f(150.0, -24.0, 10.0); //PANJANG,Y,X
    glVertex3f(150.0, 50.0, 10.0);
    glVertex3f(150.0, 50.0, 20.0);
    glVertex3f(150.0, -24.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);// tiang kiri belakang lobby
    glColor3ub(66, 45, 9);
    glVertex3f(145.0, -24.0, 10.0); //PANJANG,Y,X
    glVertex3f(145.0, 50.0, 10.0);
    glVertex3f(145.0, 50.0, 20.0);
    glVertex3f(145.0, -24.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);// tiang kiri belakang lobby
    glColor3ub(66, 45, 9);
    glVertex3f(150.0, -24.0, 20.0); //PANJANG,Y,X
    glVertex3f(150.0, 50.0, 20.0);
    glVertex3f(145.0, 50.0, 20.0);
    glVertex3f(145.0, -24.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);// tiang kiri belakang lobby
    glColor3ub(66, 45, 9);
    glVertex3f(150.0, -24.0, 10.0); //PANJANG,Y,X
    glVertex3f(150.0, 50.0, 10.0);
    glVertex3f(145.0, 50.0, 10.0);
    glVertex3f(145.0, -24.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);// tiang kanan depan lobby
    glColor3ub(66, 45, 9);
    glVertex3f(-10.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(-10.0, 50.0, -70.0);
    glVertex3f(-10.0, 50.0, -80.0);
    glVertex3f(-10.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tiang loby depan kanan
    glColor3ub(66, 45, 9);
    glVertex3f(-5.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(-5.0, 50.0, -70.0);
    glVertex3f(-5.0, 50.0, -80.0);
    glVertex3f(-5.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tiang lobby kanan depan
    glColor3ub(66, 45, 9);
    glVertex3f(-10.0, -24.0, -80.0); //PANJANG,Y,X
    glVertex3f(-10.0, 50.0, -80.0);
    glVertex3f(-5.0, 50.0, -80.0);
    glVertex3f(-5.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tiang loby kanan depan
    glColor3ub(66, 45, 9);
    glVertex3f(-10.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(-10.0, 50.0, -70.0);
    glVertex3f(-5.0, 50.0, -70.0);
    glVertex3f(-5.0, -24.0, -70.0);
    glEnd();

    glBegin(GL_QUADS);// tiang loby belakang kanan
    glColor3ub(66, 45, 9);
    glVertex3f(-10.0, -24.0, 10.0); //PANJANG,Y,X
    glVertex3f(-10.0, 50.0, 10.0);
    glVertex3f(-10.0, 50.0, 20.0);
    glVertex3f(-10.0, -24.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);// tiang lobby belakang kanan
    glColor3ub(66, 45, 9);
    glVertex3f(-5.0, -24.0, 10.0); //PANJANG,Y,X
    glVertex3f(-5.0, 50.0, 10.0);
    glVertex3f(-5.0, 50.0, 20.0);
    glVertex3f(-5.0, -24.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);// tiang lobby kanan belakang
    glColor3ub(66, 45, 9);
    glVertex3f(-10.0, -24.0, 20.0); //PANJANG,Y,X
    glVertex3f(-10.0, 50.0, 20.0);
    glVertex3f(-5.0, 50.0, 20.0);
    glVertex3f(-5.0, -24.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);// tiang loby belakang kanan
    glColor3ub(66, 45, 9);
    glVertex3f(-10.0, -24.0, 10.0); //PANJANG,Y,X
    glVertex3f(-10.0, 50.0, 10.0);
    glVertex3f(-5.0, 50.0, 10.0);
    glVertex3f(-5.0, -24.0, 10.0);
    glEnd();

     glBegin(GL_QUADS);// atap lantai 1
    glColor3ub(168, 164, 158);
    glVertex3f(305.0, 50.0, 25.0); //PANJANG,Y,X
    glVertex3f(-155.0, 50.0, 25.0);
    glVertex3f(-155.0,50.0, 305.0);
    glVertex3f(305.0, 50.0, 305.0);

    // DASARAN lantai 1
    glColor3ub(99, 91, 86);
    glVertex3f(300.0, -23.0, 30.0); //PANJANG,Y,X
    glVertex3f(-150.0, -23.0, 30.0);
    glVertex3f(-150.0,-23.0, 300.0);
    glVertex3f(300.0, -23.0, 300.0);
    glEnd();

   glBegin(GL_QUADS); //tembok kanan lt 1
    glColor3ub(59, 37, 4);
    glVertex3f(-150.0, 50.0, 30.0); //PANJANG,Y,X
    glVertex3f(-150.0, -24.0, 30.0);
    glVertex3f(-150.0,-24.0, 300.0);
    glVertex3f(-150.0, 50.0, 300.0);
    glEnd();


    glBegin(GL_QUADS); //tembok kiri lt 1
    glColor3ub(59, 37, 4);
    glVertex3f(300.0, 50.0, 30.0); //PANJANG,Y,X
    glVertex3f(300.0, -24.0, 30.0);
    glVertex3f(300.0,-24.0, 300.0);
    glVertex3f(300.0, 50.0, 300.0);
    glEnd();

     glBegin(GL_QUADS);//ALAS TANAH
    glColor3ub(23, 66, 9);
    glVertex3f(400.0, -24.0, -150.0);
    glVertex3f(-200.0, -24.0, -150.0);
    glVertex3f(-200.0, -24.0, 400.0);
    glVertex3f(400.0, -24.0, 400.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK DEPAN 1
    glColor3ub(59, 37, 4);
    glVertex3f(300.0, -24.0, 30.0);
    glVertex3f(-150.0, -24.0, 30.0);
    glVertex3f(-150.0, 50.0,30.0);
    glVertex3f(300.0, 50.0, 30.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK BELAKANG 1
    glColor3ub(59, 37, 4);
    glVertex3f(300.0, -24.0, 300.0);
    glVertex3f(-150.0, -24.0, 300.0);
    glVertex3f(-150.0, 50.0, 300.0);
    glVertex3f(300.0, 50.0, 300.0);
    glEnd();

    //Batas lantai 1-2
    glBegin(GL_QUADS);//
    glColor3ub(194, 38, 14);
    glVertex3f(305.0, 60.0, 25.0); //TUTUP ATAS
    glVertex3f(-155.0, 60.0, 25.0);
    glVertex3f(-155.0,60.0, 305.0);
    glVertex3f(305.0, 60.0, 305.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(218, 228, 232);
    glVertex3f(305.0, 50.0, 25.0); //KIRI
    glVertex3f(305.0, 60.0, 25.0);
    glVertex3f(305.0, 60.0, 305.0);
    glVertex3f(305.0, 50.0, 305.0);

    glVertex3f(-155.0, 50.0, 25.0); //KANAN
    glVertex3f(-155.0, 60.0, 25.0);
    glVertex3f(-155.0, 60.0, 305.0);
    glVertex3f(-155.0, 50.0, 305.0);

    glVertex3f(305.0, 60.0, 25.0); //DEPAN
    glVertex3f(-155.0, 60.0, 25.0);
    glVertex3f(-155.0, 50.0, 25.0);
    glVertex3f(305.0, 50.0, 25.0);

    glVertex3f(305.0, 60.0, 305.0); //DEPAN
    glVertex3f(-155.0, 60.0, 305.0);
    glVertex3f(-155.0, 50.0, 305.0);
    glVertex3f(305.0, 50.0, 305.0);
    glEnd();



    glBegin(GL_QUADS); //TEMBOK KIRI 2
    glColor3ub(59, 37, 4);
    glVertex3f(230.0, 500.0, 80.0); //PANJANG,Y,X
    glVertex3f(230.0, 60.0, 80.0);
    glVertex3f(230.0, 60.0, 270.0);
    glVertex3f(230.0, 500.0, 270.0);
    glEnd();

     glBegin(GL_QUADS); //TEMBOK KANAN 2
    glColor3ub(59, 37, 4);
    glVertex3f(-80.0, 500.0, 80.0); //PANJANG,Y,X
    glVertex3f(-80.0, 60.0, 80.0);
    glVertex3f(-80.0, 60.0, 270.0);
    glVertex3f(-80.0, 500.0, 270.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK Belakang Lantai2
    glColor3ub(59, 37, 4);
    glVertex3f(230.0, 60.0, 270.0);
    glVertex3f(-80.0, 60.0, 270.0);
    glVertex3f(-80.0, 500.0, 270.0);
    glVertex3f(230.0, 500.0, 270.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK Depan lantai2
    glColor3ub(59, 37, 4);
    glVertex3f(230.0, 60.0, 80.0);
    glVertex3f(-80.0, 60.0, 80.0);
    glVertex3f(-80.0, 500.0,80.0);
    glVertex3f(230.0, 500.0, 80.0);
    glEnd();


    //ATAP LANTAI 2
    glBegin(GL_QUADS);// PEMBATAS atap lantai 2
    glColor3ub(168, 164, 158);
    glVertex3f(235.0, 500.0, 75.0); //PANJANG,Y,X
    glVertex3f(-85.0, 500.0, 75.0);
    glVertex3f(-85.0,500.0, 275.0);
    glVertex3f(235.0, 500.0, 275.0);

    glVertex3f(235.0, 510.0, 75.0); //PANJANG,Y,X
    glVertex3f(-85.0, 510.0, 75.0);
    glVertex3f(-85.0,510.0, 275.0);
    glVertex3f(235.0, 510.0, 275.0);
    glEnd();

    glBegin(GL_QUADS); // TEMBOK DIKIT ATAP LANTAI 2
    glColor3ub(218, 228, 232);
    glVertex3f(235.0, 500.0, 75.0); //KIRI
    glVertex3f(235.0, 510.0, 75.0);
    glVertex3f(235.0, 510.0, 275.0);
    glVertex3f(235.0, 500.0, 275.0);

    glVertex3f(-85.0, 500.0, 75.0); //KANAN
    glVertex3f(-85.0, 510.0, 75.0);
    glVertex3f(-85.0, 510.0, 275.0);
    glVertex3f(-85.0, 500.0, 275.0);

    glVertex3f(235.0, 510.0, 75.0); //DEPAN
    glVertex3f(-85.0, 510.0, 75.0);
    glVertex3f(-85.0, 500.0, 75.0);
    glVertex3f(235.0, 500.0, 75.0);

    glVertex3f(235.0, 510.0, 275.0); //BELAKANG
    glVertex3f(-85.0, 510.0, 275.0);
    glVertex3f(-85.0, 500.0, 275.0);
    glVertex3f(235.0, 500.0, 275.0);
    glEnd();

    glBegin(GL_TRIANGLES);//ATAP LT 2
    glColor3ub(173, 92, 38);
     glVertex3f(230, 500, 80);//DEPAN
     glVertex3f(90, 600, 160);
     glVertex3f(-80, 500, 80);

     glVertex3f(230, 500, 275);//BELAKANG
     glVertex3f(90, 600, 160);
     glVertex3f(-80, 500, 275);

     glVertex3f(-80, 500, 80);//KAKAN
     glVertex3f(90, 600, 160);
     glVertex3f(-80, 500, 275);

     glVertex3f(230, 500, 80);//KIRI
     glVertex3f(90, 600, 160);
     glVertex3f(230, 500, 275);
    glEnd();

}

void kursi(int h, int j, int g) {
    //PERABOTAN
    glBegin(GL_QUADS);
    glColor3ub(130, 73, 9);
    glVertex3d(h, j, g);
    glVertex3d(h + 20, j, g);
    glVertex3d(h + 20, j+10, g);
    glVertex3d(h, j+10, g);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h, j, g+2);
    glVertex3d(h + 20, j, g+2);
    glVertex3d(h + 20, j+10, g+2);
    glVertex3d(h, j+10, g+2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h + 20, j, g);
    glVertex3d(h + 20, j, g + 2 );
    glVertex3d(h + 20, j + 10, g + 2);
    glVertex3d(h + 20, j + 10, g);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h, j, g);
    glVertex3d(h, j, g + 2);
    glVertex3d(h, j + 10, g + 2);
    glVertex3d(h, j + 10, g);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h, j + 10, g);
    glVertex3d(h, j + 10, g + 2);
    glVertex3d(h+20, j + 10, g + 2);
    glVertex3d(h+20, j + 10, g);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3d(h, j + 4, g + 2);
    glVertex3d(h, j + 4, g + 7);
    glVertex3d(h + 20, j + 4, g +7);
    glVertex3d(h + 20, j + 4, g +2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h, j, g + 7);
    glVertex3d(h, j + 4, g + 7);
    glVertex3d(h + 20, j + 4, g + 7);
    glVertex3d(h + 20, j, g + 7);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h +20, j, g + 2);
    glVertex3d(h +20, j + 4, g + 2);
    glVertex3d(h + 20, j + 4, g + 7);
    glVertex3d(h + 20, j, g + 7);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h, j, g + 2);
    glVertex3d(h, j + 4, g + 2);
    glVertex3d(h, j + 4, g + 7);
    glVertex3d(h, j, g + 7);

    glEnd();
}


void pintu(int o,int p,int q) {
    glBegin(GL_QUADS);
    glColor3ub(219, 20, 66);
    glVertex3d(o - 5.5, p-5, q + 0.5);
    glVertex3d(o - 5.5, p + 23, q + 0.5);
    glVertex3d(o + 6.5, p + 23, q + 0.5);
    glVertex3d(o + 6.5, p-5, q + 0.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o - 5.5, p-5, q + 0.5);
    glVertex3d(o - 5.5, p + 23, q + 0.5);
    glVertex3d(o - 5.5, p + 23, q - 0.25);
    glVertex3d(o - 5.5, p-5, q - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o - 5.5, p-5, q - 0.25);
    glVertex3d(o - 5.5, p + 23, q - 0.25);
    glVertex3d(o + 6.5, p + 23, q - 0.25);
    glVertex3d(o + 6.5, p-5, q - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o + 6.5, p-5, q + 0.5);
    glVertex3d(o + 6.5, p + 23, q + 0.5);
    glVertex3d(o + 6.5, p + 23, q - 0.25);
    glVertex3d(o + 6.5, p-5, q - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o - 5.5, p + 23, q + 0.5);
    glVertex3d(o - 5.5, p + 23, q - 0.25);
    glVertex3d(o + 6.5, p + 23, q - 0.25);
    glVertex3d(o + 6.5, p + 23, q + 0.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o - 5.5, p-5, q + 0.5);
    glVertex3d(o - 5.5, p-5, q - 0.25);
    glVertex3d(o + 6.5, p-5, q - 0.25);
    glVertex3d(o + 6.5, p-5, q + 0.5);
    glEnd();

    //gagang pintu
    glBegin(GL_QUADS);
    glColor3ub(1,1,1);
    glVertex3d(o - 5, p + 10, q + 0.7);
    glVertex3d(o - 5, p + 14, q + 0.7);
    glVertex3d(o - 4, p + 14, q + 0.7);
    glVertex3d(o - 4, p + 10, q + 0.7);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o - 5, p + 10, q - 0.27);
    glVertex3d(o - 5, p + 14, q - 0.27);
    glVertex3d(o - 4, p + 14, q - 0.27);
    glVertex3d(o - 4, p + 10, q - 0.27);
    glEnd();

}
void jendela(int k,int l,int m){
    glBegin(GL_QUADS);
    glColor3ub(240, 235, 236);
    glVertex3d(k - 5.5, l+1, m + 0.5);
    glVertex3d(k - 5.5, l + 23, m + 0.5);
    glVertex3d(k + 6.5, l + 23, m + 0.5);
    glVertex3d(k + 6.5, l+1, m + 0.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(k - 5.5, l+1, m + 0.5);
    glVertex3d(k - 5.5, l + 23, m + 0.5);
    glVertex3d(k - 5.5, l + 23, m - 0.25);
    glVertex3d(k - 5.5, l+1, m - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(k - 5.5, l+1, m - 0.25);
    glVertex3d(k - 5.5, l + 23, m - 0.25);
    glVertex3d(k + 6.5, l + 23, m - 0.25);
    glVertex3d(k + 6.5, l+1, m - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(k + 6.5,l+1, m + 0.5);
    glVertex3d(k + 6.5, l + 23, m + 0.5);
    glVertex3d(k + 6.5, l + 23, m - 0.25);
    glVertex3d(k + 6.5, l+1, m - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(k - 5.5, l + 23, m + 0.5);
    glVertex3d(k - 5.5, l + 23, m - 0.25);
    glVertex3d(k + 6.5, l + 23, m - 0.25);
    glVertex3d(k + 6.5, l + 23, m + 0.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(k - 5.5, l+1, m + 0.5);
    glVertex3d(k - 5.5, l+1, m - 0.25);
    glVertex3d(k + 6.5, l+1, m - 0.25);
    glVertex3d(k + 6.5, l+1, m + 0.5);
    glEnd();

    //kacakiri
    glBegin(GL_POLYGON);
    glColor3ub(38, 38, 38);
    glVertex3d(k - 4.5, l + 16, m + 0.55);
    glVertex3d(k - 4.5, l + 22, m + 0.55);
    glVertex3d(k - 0.5, l + 22, m + 0.55);
    glVertex3d(k - 0.5, l + 16, m + 0.55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k - 4.5, l + 9, m + 0.55);
    glVertex3d(k - 4.5, l + 15, m + 0.55);
    glVertex3d(k - 0.5, l + 15, m + 0.55);
    glVertex3d(k - 0.5, l + 9, m + 0.55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k - 4.5, l + 2, m + 0.55);
    glVertex3d(k - 4.5, l + 8, m + 0.55);
    glVertex3d(k - 0.5, l + 8, m + 0.55);
    glVertex3d(k - 0.5, l + 2, m + 0.55);
    glEnd();

    //kaca kanan
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 16, m + 0.55);
    glVertex3d(k + 1.5, l + 22, m + 0.55);
    glVertex3d(k + 5.5, l + 22, m + 0.55);
    glVertex3d(k + 5.5, l + 16, m + 0.55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 9, m + 0.55);
    glVertex3d(k + 1.5, l + 15, m + 0.55);
    glVertex3d(k + 5.5, l + 15, m + 0.55);
    glVertex3d(k + 5.5, l + 9, m + 0.55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 2, m + 0.55);
    glVertex3d(k + 1.5, l + 8, m + 0.55);
    glVertex3d(k + 5.5, l + 8, m + 0.55);
    glVertex3d(k + 5.5, l + 2, m + 0.55);
    glEnd();

    //kaca kiri belakang
    glBegin(GL_POLYGON);
    glVertex3d(k - 4.5, l + 16, m - 0.255);
    glVertex3d(k - 4.5, l + 22, m - 0.255);
    glVertex3d(k - 0.5, l + 22, m - 0.255);
    glVertex3d(k - 0.5, l + 16, m - 0.255);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k - 4.5, l + 9, m - 0.255);
    glVertex3d(k - 4.5, l + 15, m - 0.255);
    glVertex3d(k - 0.5, l + 15, m - 0.255);
    glVertex3d(k - 0.5, l + 9, m - 0.255);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k - 4.5, l + 2, m - 0.255);
    glVertex3d(k - 4.5, l + 8, m - 0.255);
    glVertex3d(k - 0.5, l + 8, m - 0.255);
    glVertex3d(k - 0.5, l + 2, m - 0.255);
    glEnd();

    //kaca kanan belakang
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 16, m - 0.255);
    glVertex3d(k + 1.5, l + 22, m - 0.255);
    glVertex3d(k + 5.5, l + 22, m - 0.255);
    glVertex3d(k + 5.5, l + 16, m - 0.255);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 9, m - 0.255);
    glVertex3d(k + 1.5, l + 15, m - 0.255);
    glVertex3d(k + 5.5, l + 15, m - 0.255);
    glVertex3d(k + 5.5, l + 9, m - 0.255);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 2, m - 0.255);
    glVertex3d(k + 1.5, l + 8, m - 0.255);
    glVertex3d(k + 5.5, l + 8, m - 0.255);
    glVertex3d(k + 5.5, l + 2, m - 0.255);
    glEnd();



}

void jendelasamping(int m, int l, int k) {

    glBegin(GL_QUADS);
    glColor3ub(240, 235, 236);
    glVertex3d(m + 0.5, l,k - 5.5);
    glVertex3d(m + 0.5, l + 23,k - 5.5 );
    glVertex3d(m + 0.5, l + 23, k + 6.5);
    glVertex3d(m + 0.5, l,k + 6.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(m + 0.5, l,k - 5.5 );
    glVertex3d(m + 0.5, l + 23, k - 5.5);
    glVertex3d(m - 0.25, l + 23, k - 5.5);
    glVertex3d( m - 0.25, l,k - 5.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(m - 0.25, l, k - 5.5);
    glVertex3d(m - 0.25, l + 23, k - 5.5);
    glVertex3d(m - 0.25, l + 23,k + 6.5);
    glVertex3d(m - 0.25, l, k + 6.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(m + 0.5, l, k + 6.5);
    glVertex3d(m + 0.5, l + 23, k + 6.5);
    glVertex3d(m - 0.25, l + 23,k + 6.5);
    glVertex3d(m - 0.25, l, k + 6.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d( m + 0.5, l + 23,k - 5.5);
    glVertex3d(m - 0.25, l + 23, k - 5.5);
    glVertex3d(m - 0.25, l + 23, k + 6.5);
    glVertex3d(m + 0.5, l + 23, k + 6.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(m + 0.5, l, k - 5.5);
    glVertex3d(m - 0.25, l, k - 5.5);
    glVertex3d(m - 0.25, l, k + 6.5);
    glVertex3d(m + 0.5, l,k + 6.5);
    glEnd();

    //kacakiri
    glBegin(GL_POLYGON);
    glColor3ub(38, 38, 38);
    glVertex3d(m + 0.55, l + 16, k - 4.5);
    glVertex3d(m + 0.55, l + 22, k - 4.5);
    glVertex3d(m + 0.5, l + 22, k - 0.55);
    glVertex3d(m + 0.55, l + 16, k - 0.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(m + 0.55, l + 9, k - 4.5);
    glVertex3d(m + 0.55, l + 15, k - 4.5);
    glVertex3d(m + 0.55, l + 15, k - 0.5);
    glVertex3d(m + 0.55, l + 9, k - 0.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(m + 0.55, l + 2, k - 4.5);
    glVertex3d(m + 0.5, l + 8, k - 4.55);
    glVertex3d(m + 0.55, l + 8, k - 0.5);
    glVertex3d(m + 0.55, l + 2, k - 0.5);
    glEnd();

    //kaca kanan
    glBegin(GL_POLYGON);
    glVertex3d(m + 0.55, l + 16, k + 1.5);
    glVertex3d(m + 0.55, l + 22, k + 1.5);
    glVertex3d(m + 0.55, l + 22, k + 5.5);
    glVertex3d(m + 0.55, l + 16, k + 5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(m + 0.55, l + 9, k + 1.5);
    glVertex3d(m + 0.55, l + 15, k + 1.5);
    glVertex3d(m + 0.55, l + 15, k + 5.5);
    glVertex3d(m + 0.55, l + 9, k + 5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(m + 0.55, l + 2, k + 1.5);
    glVertex3d(m + 0.55, l + 8, k + 1.5);
    glVertex3d(m + 0.55, l + 8, k + 5.5);
    glVertex3d(m + 0.55, l + 2, k + 5.5);
    glEnd();

    //kaca kiri belakang
    glBegin(GL_POLYGON);
    glVertex3d(m - 0.255, l + 16, k - 4.5);
    glVertex3d(m - 0.255, l + 22, k - 4.5);
    glVertex3d(m - 0.255, l + 22, k - 0.5);
    glVertex3d(m - 0.255, l + 16, k - 0.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(m - 0.255, l + 9, k - 4.5);
    glVertex3d(m - 0.255, l + 15, k - 4.5);
    glVertex3d(m - 0.255, l + 15, k - 0.5);
    glVertex3d(m - 0.255, l + 9, k - 0.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(m - 0.255, l + 2, k - 4.5);
    glVertex3d(m - 0.255, l + 8, k - 4.5);
    glVertex3d(m - 0.255, l + 8, k - 0.5);
    glVertex3d(m - 0.255, l + 2, k - 0.5);
    glEnd();

    //kaca kanan belakang
    glBegin(GL_POLYGON);
    glVertex3d(m - 0.255, l + 16, k + 1.5);
    glVertex3d(m - 0.255, l + 22, k + 1.5);
    glVertex3d(m - 0.255, l + 22, k + 5.5);
    glVertex3d(m - 0.255, l + 16, k + 5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(m - 0.255, l + 9, k + 1.5);
    glVertex3d(m - 0.255, l + 15, k + 1.5);
    glVertex3d(m - 0.255, l + 15, k + 5.5);
    glVertex3d(m - 0.255, l + 9, k + 5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(m - 0.255, l + 2, k + 1.5);
    glVertex3d(m - 0.255, l + 8, k + 1.5);
    glVertex3d(m - 0.255, l + 8, k + 5.5);
    glVertex3d(m - 0.255, l + 2, k + 5.5);
    glEnd();
}
void tampil(void)
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    building(); // memanggil point bulding
    glScalef(1.5f, 1.5f, 1.0f);
    pintu(40,-10,30);
    jendela(10, -6, 30);//lantai1
    jendela(-20, -6, 30);
    jendela(180, -6, 30);
    jendela(-50, -6, 30);
    jendela(-80, -6, 30);
    jendela(70, -6, 30);
    jendela(100, -6, 30);
    jendela(130, -6, 30);
    jendela(155, -6, 30);

    jendela(10, -6, 300);//lantai1
    jendela(-20, -6, 300);
    jendela(-50, -6, 300);
    jendela(-80, -6, 300);
    jendela(70, -6, 300);
    jendela(100, -6, 300);
    jendela(130, -6, 300);
    jendela(155, -6, 300);
    jendela(40, -6, 300);
    jendela(180, -6, 300);

    jendela(20, 45, 80);//lantai2 depan
    jendela(-10, 45, 80);
    jendela(-40, 45, 80);
    jendela(50,45,80);
    jendela(80, 45, 80);
    jendela(110, 45, 80);
    jendela(140, 45, 80);
jendela(20, 78, 80);
    jendela(-10, 78, 80);
    jendela(-40, 78, 80);
    jendela(50,78,80);
    jendela(80, 78, 80);
    jendela(110, 78, 80);
    jendela(140, 78, 80);
jendela(20, 113, 80);
    jendela(-10, 113, 80);
    jendela(-40, 113, 80);
    jendela(50,113,80);
    jendela(80, 113, 80);
    jendela(110, 113, 80);
    jendela(140, 113, 80);
jendela(20, 148, 80);
    jendela(-10, 148, 80);
    jendela(-40, 148, 80);
    jendela(50,148,80);
    jendela(80, 148, 80);
    jendela(110, 148, 80);
    jendela(140, 148, 80);
jendela(20, 183, 80);
    jendela(-10, 183, 80);
    jendela(-40, 183, 80);
    jendela(50,183,80);
    jendela(80, 183, 80);
    jendela(110, 183, 80);
    jendela(140, 183, 80);
jendela(20, 218, 80);
    jendela(-10, 218, 80);
    jendela(-40, 218, 80);
    jendela(50,218,80);
    jendela(80, 218, 80);
    jendela(110, 218, 80);
    jendela(140, 218, 80);
jendela(20, 253, 80);
    jendela(-10, 253, 80);
    jendela(-40, 253, 80);
    jendela(50,253,80);
    jendela(80, 253, 80);
    jendela(110, 253, 80);
    jendela(140, 253, 80);
jendela(20, 288, 80);
    jendela(-10, 288, 80);
    jendela(-40, 288, 80);
    jendela(50,288,80);
    jendela(80, 288, 80);
    jendela(110, 288, 80);
    jendela(140, 288, 80);

jendela(20, 45, 270);//lantai2 belakang
    jendela(-10, 45, 270);
    jendela(-40, 45, 270);
    jendela(50,45,270);
    jendela(80, 45, 270);
    jendela(110, 45, 270);
    jendela(140, 45, 270);
jendela(20, 78, 270);
    jendela(-10, 78, 270);
    jendela(-40, 78, 270);
    jendela(50,78,270);
    jendela(80, 78, 270);
    jendela(110, 78, 270);
    jendela(140, 78, 270);
jendela(20, 113, 270);
    jendela(-10, 113, 270);
    jendela(-40, 113, 270);
    jendela(50,113,270);
    jendela(80, 113, 270);
    jendela(110, 113, 270);
    jendela(140, 113, 270);
jendela(20, 148, 270);
    jendela(-10, 148, 270);
    jendela(-40, 148, 270);
    jendela(50,148,270);
    jendela(80, 148, 270);
    jendela(110, 148, 270);
    jendela(140, 148, 270);
jendela(20, 183, 270);
    jendela(-10, 183, 270);
    jendela(-40, 183, 270);
    jendela(50,183,270);
    jendela(80, 183, 270);
    jendela(110, 183, 270);
    jendela(140, 183, 270);
jendela(20, 218, 270);
    jendela(-10, 218, 270);
    jendela(-40, 218, 270);
    jendela(50,218,270);
    jendela(80, 218, 270);
    jendela(110, 218, 270);
    jendela(140, 218, 270);
jendela(20, 253, 270);
    jendela(-10, 253, 270);
    jendela(-40, 253, 270);
    jendela(50,253,270);
    jendela(80, 253, 270);
    jendela(110, 253, 270);
    jendela(140, 253, 270);
jendela(20, 288, 270);
    jendela(-10, 288, 270);
    jendela(-40, 288, 270);
    jendela(50,288,270);
    jendela(80, 288, 270);
    jendela(110, 288, 270);
    jendela(140, 288, 270);

jendelasamping(20, 288, 270); //jendela samping kiri
    jendelasamping(-54, 45, 100);
    jendelasamping(-54, 45, 130);
    jendelasamping(-54, 45, 160);
    jendelasamping(-54, 45, 190);
    jendelasamping(-54, 45, 220);
    jendelasamping(-54, 45, 250);
jendelasamping(-54, 78, 100);
    jendelasamping(-54, 78, 130);
    jendelasamping(-54, 78, 160);
    jendelasamping(-54, 78, 190);
    jendelasamping(-54, 78, 220);
    jendelasamping(-54, 78, 250);
jendelasamping(-54, 113, 100);
    jendelasamping(-54, 113, 130);
    jendelasamping(-54, 113, 160);
    jendelasamping(-54, 113, 190);
    jendelasamping(-54, 113, 220);
    jendelasamping(-54, 113, 250);
jendelasamping(-54, 148, 100);
    jendelasamping(-54, 148, 130);
    jendelasamping(-54, 148, 160);
    jendelasamping(-54, 148, 190);
    jendelasamping(-54, 148, 220);
    jendelasamping(-54, 148, 250);
jendelasamping(-54, 183, 100);
    jendelasamping(-54, 183, 130);
    jendelasamping(-54, 183, 160);
    jendelasamping(-54, 183, 190);
    jendelasamping(-54, 183, 220);
    jendelasamping(-54, 183, 250);
jendelasamping(-54, 218, 100);
    jendelasamping(-54, 218, 130);
    jendelasamping(-54, 218, 160);
    jendelasamping(-54, 218, 190);
    jendelasamping(-54, 218, 220);
    jendelasamping(-54, 218, 250);
jendelasamping(-54, 253, 100);
    jendelasamping(-54, 253, 130);
    jendelasamping(-54, 253, 160);
    jendelasamping(-54, 253, 190);
    jendelasamping(-54, 253, 220);
    jendelasamping(-54, 253, 250);
jendelasamping(-54, 288, 100);
    jendelasamping(-54, 288, 130);
    jendelasamping(-54, 288, 160);
    jendelasamping(-54, 288, 190);
    jendelasamping(-54, 288, 220);
    jendelasamping(-54, 288, 250);
jendelasamping(20, 288, 270); //jendela samping kanan
    jendelasamping(155, 45, 100);
    jendelasamping(155, 45, 130);
    jendelasamping(155, 45, 160);
    jendelasamping(155, 45, 190);
    jendelasamping(155, 45, 220);
    jendelasamping(155, 45, 250);
jendelasamping(155, 78, 100);
    jendelasamping(155, 78, 130);
    jendelasamping(155, 78, 160);
    jendelasamping(155, 78, 190);
    jendelasamping(155, 78, 220);
    jendelasamping(155, 78, 250);
jendelasamping(155, 113, 100);
    jendelasamping(155, 113, 130);
    jendelasamping(155, 113, 160);
    jendelasamping(155, 113, 190);
    jendelasamping(155, 113, 220);
    jendelasamping(155, 113, 250);
jendelasamping(155, 148, 100);
    jendelasamping(155, 148, 130);
    jendelasamping(155, 148, 160);
    jendelasamping(155, 148, 190);
    jendelasamping(155, 148, 220);
    jendelasamping(155, 148, 250);
jendelasamping(155, 183, 100);
    jendelasamping(155, 183, 130);
    jendelasamping(155, 183, 160);
    jendelasamping(155, 183, 190);
    jendelasamping(155, 183, 220);
    jendelasamping(155, 183, 250);
jendelasamping(155, 218, 100);
    jendelasamping(155, 218, 130);
    jendelasamping(155, 218, 160);
    jendelasamping(155, 218, 190);
    jendelasamping(155, 218, 220);
    jendelasamping(155, 218, 250);
jendelasamping(155, 253, 100);
    jendelasamping(155, 253, 130);
    jendelasamping(155, 253, 160);
    jendelasamping(155, 253, 190);
    jendelasamping(155, 253, 220);
    jendelasamping(155, 253, 250);
jendelasamping(155, 288, 100);
    jendelasamping(155, 288, 130);
    jendelasamping(155, 288, 160);
    jendelasamping(155, 288, 190);
    jendelasamping(155, 288, 220);
    jendelasamping(155, 288, 250);
//lantai1 samping kanan
jendelasamping(-100, -6, 50);
    jendelasamping(-100, -6, 75);
    jendelasamping(-100, -6, 100);
    jendelasamping(-100, -6, 130);
    jendelasamping(-100, -6, 160);
    jendelasamping(-100, -6, 190);
    jendelasamping(-100, -6, 220);
    jendelasamping(-100, -6, 250);
    jendelasamping(-100, -6, 280);
    //lantai1 samping kiri
jendelasamping(200, -6, 50);
    jendelasamping(200, -6, 75);
    jendelasamping(200, -6, 100);
    jendelasamping(200, -6, 130);
    jendelasamping(200, -6, 160);
    jendelasamping(200, -6, 190);
    jendelasamping(200, -6, 220);
    jendelasamping(200, -6, 250);
    jendelasamping(200, -6, 280);








    kursi(-100,-16,35);//lantai1baris1
    kursi(-60,-16,35);
    kursi(0,-16,35);
    kursi(50,-16,35);
    kursi(100,-16,35);
    kursi(150,-16,35);

    kursi(-100,-16,70);//lantai1baris2
    kursi(-60,-16,70);
    kursi(0,-16,70);
    kursi(50,-16,70);
    kursi(100,-16,70);
    kursi(150,-16,70);

    kursi(-100,-16,105);//lantai1baris3
    kursi(-60,-16,105);
    kursi(0,-16,105);
    kursi(50,-16,105);
    kursi(100,-16,105);
    kursi(150,-16,105);

    kursi(-100,-16,140);//lantai1baris4
    kursi(-60,-16,140);
    kursi(0,-16,140);
    kursi(50,-16,140);
    kursi(100,-16,140);
    kursi(150,-16,140);


    glPopMatrix();
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 250);
    glutCreateWindow("Tr Asdos - Brawijaya");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
