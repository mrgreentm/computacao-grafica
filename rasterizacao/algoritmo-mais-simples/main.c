#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <math.h>

int gridSize = 10;
float lineX1 = 0.0, lineY1 = 0.0; 
float lineX2 = 10.0, lineY2 = 15.0;

void drawSquare(int x, int y) {
    glColor3f(1.0, 0.0, 0.0); 
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd();
}

void drawLine() {
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(lineX1, lineY1); 
    glVertex2f(lineX2, lineY2); 
    glEnd();
}

void drawGrid() {
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_LINES);

    for (int i = -gridSize; i <= gridSize; i++) {
        glVertex2f(i, -gridSize);
        glVertex2f(i, gridSize);
    }

    for (int i = -gridSize; i <= gridSize; i++) {
        glVertex2f(-gridSize, i);
        glVertex2f(gridSize, i);
    }

    glEnd();
}

void paintSquaresOnLine() {
    float dx = lineX2 - lineX1;
    float dy = lineY2 - lineY1;
    int steps = fmax(fabs(dx), fabs(dy));

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = lineX1;
    float y = lineY1;

    for (int i = 0; i <= steps; i++) {
        int gridX = (int)floor(x);
        int gridY = (int)floor(y);
        drawSquare(gridX, gridY);
        x += xIncrement;
        y += yIncrement;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawGrid();
    drawLine();

    paintSquaresOnLine();


    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-gridSize, gridSize, -gridSize, gridSize);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Malha Quadriculada com Linha e Quadrados Pintados");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
