#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

GLfloat escala = 1.0f; // controla o zoom
GLfloat dx = 0.0f; // controla o deslocamento horizontal
GLfloat dy = 0.0f; // controla o deslocamento vertical
GLfloat angulo = 0.0f; // controla a rotação

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 900);  // define a área de desenho
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLineWidth(5);


    glPushMatrix();


        glTranslatef(dx, dy, 0);
        glTranslatef(330, 600, 0);
        glRotatef(angulo, 0.0f, 0.0f, 1.0f);
        glScalef(escala, escala, 1.0f);
        glTranslatef(-330, -600, 0);

    // Letra J
    glBegin(GL_LINE_STRIP); // primeiro valor horizontal e segundo valor vertical
        glVertex2d(30, 700); //reta de cima do J  30 = 0
        glVertex2d(130, 700); //reta de cima do J
        glVertex2d(80, 700);  //reta vertical do J
        glVertex2d(80, 500); //reta vertical do J
        glVertex2d(30, 500); //reta horizontal da parte de baixo
        glVertex2d(30, 550); //reta da subdinha do J
    glEnd();

    // Letra o
    glBegin(GL_LINE_LOOP);
        glVertex2d(150, 700); // distância entra as letras é 20
        glVertex2d(150, 500); //tamanho horizontal das letras é 80
        glVertex2d(220, 500); //tamanho vertical das letras é 200
        glVertex2d(220, 700); //a metadade da letra é 600
    glEnd();

   // Letra s
    glBegin(GL_LINE_STRIP);
        glVertex2d(310, 700);
        glVertex2d(240, 700);
        glVertex2d(240, 600);
        glVertex2d(310, 600);
        glVertex2d(310, 500);
        glVertex2d(240, 500);
    glEnd();

     // Letra i
    glBegin(GL_LINES);
        glVertex2d(330, 700);
        glVertex2d(330, 500);
    glEnd();

     // Letra a
     glBegin(GL_LINE_LOOP);
        glVertex2d(350, 700);
        glVertex2d(350, 500);
        glVertex2d(350, 600);
        glVertex2d(430, 600);
        glVertex2d(430, 500);
        glVertex2d(430, 700);
    glEnd();

    // Letra n
    glBegin(GL_LINES);
        glVertex2d(450, 700);
        glVertex2d(450, 500);
        glVertex2d(450, 700);
        glVertex2d(530, 500);
        glVertex2d(530, 700);
        glVertex2d(530, 500);
    glEnd();

      // Letra e
    glBegin(GL_LINES);
        glVertex2d(550, 700);
        glVertex2d(550, 500);
        glVertex2d(550, 700);
        glVertex2d(630, 700);
        glVertex2d(550, 600);
        glVertex2d(630, 600);
        glVertex2d(630, 500);
        glVertex2d(550, 500);

    glEnd();

    glPopMatrix();  // desfaz transformações

    glFlush();
}

void escutaTeclado(unsigned char tecla, GLint x, GLint y) {
    switch(tecla) {
        case '+': escala *= 1.1f; break;
        case '-': if(escala > 0.2f) escala *= 0.9f; break;
        case 'a': dx -= 10.0f; break;
        case 'd': dx += 10.0f; break;
        case 'w': dy += 10.0f; break;
        case 's': dy -= 10.0f; break;
        case 'q': angulo += 5.0f; break;
        case 'e': angulo -= 5.0f; break;
        case 27: exit(0); // tecla ESC para sair
    }

    glutPostRedisplay();  // avisa o glut que precisa redesenhar
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("PROJETO-DO-NOME");

    glClearColor(0, 0, 0, 1); // fundo preto

    glutKeyboardFunc(escutaTeclado);
    glutDisplayFunc(desenha);

    glutMainLoop();
    return 0;
}
