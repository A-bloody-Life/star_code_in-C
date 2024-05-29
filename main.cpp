#include <GL/glut.h>
#include <GL/glui.h>

int angle = 0;
int shapeType = 0; // 0 - Cube, 1 - Parallelepiped

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1.5, 0.0, -6.0);
    glRotatef(angle, 1.0, 1.0, 1.0);

    if (shapeType == 0) {
        // Рисуем куб
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glEnd();
    } else {
        // Рисуем параллелепипед
        glBegin(GL_QUADS);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.0, -1.0, 1.0);
        glVertex3f(1.0, -1.0, 1.0);
        glEnd();
    }

    glutSwapBuffers();
}

void timer(int value) {
    angle += 2;
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void controlCallback(int control) {
    shapeType = control;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Shape");

    glutDisplayFunc(display);
    glutTimerFunc(10, timer, 0);

    GLUI *glui = GLUI_Master.create_glui("Controls");
    glui->add_button("Cube", 0, controlCallback);
    glui->add_button("Parallelepiped", 1, controlCallback);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}
