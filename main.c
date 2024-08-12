#include <GLUT/glut.h>
#include <math.h>

float angle = 0.0f;
int direction = 1;

void drawFlower() {
    glColor3f(1.0f, 0.0f, 0.0f);

    for (int i = 0; i < 6; i++) {
        glPushMatrix();
        glRotatef(i * 60.0f, 0.0f, 0.0f, 1.0f); 
        glBegin(GL_TRIANGLES);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(0.2f, 0.6f);
            glVertex2f(-0.2f, 0.6f);
        glEnd();
        glPopMatrix();
    }

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180;
            glVertex2f(0.1f * cos(theta), 0.1f * sin(theta));
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    drawFlower();

    glPopMatrix();
    glutSwapBuffers();
}

void keyPressed(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        direction = -1; // Anti-horário
    }
    else if (key == GLUT_KEY_LEFT) {
        direction = 1; // Horário
    }
}

void update(int value) {
    angle += direction * 2.0f;
    if (angle > 360) angle -= 360;
    if (angle < 0) angle += 360;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Flor de Abril Transformada em Catavento");

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(display);
    glutSpecialFunc(keyPressed);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
