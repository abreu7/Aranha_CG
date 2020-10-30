/*
 * Tentantiva de fazer um objeto seguir o mouse
 *
 *  Created on: 27 de out de 2020
 *      Author: T3500855
 */


#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

void init(void);
void display(void);


GLint movebola = 0;
GLint direcao = 1;

GLfloat angulo_alvo = 0;
GLint angulo_alvo_graus = 90;
GLfloat angulo_teste = 0;

GLfloat posatual_x = 0;
GLfloat posatual_y = 0;
//Ponto de destino
GLfloat posfinal_x = 0;
GLfloat posfinal_y = 0;

void bola(int passo);
void corpoAranha(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y);
void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y);

void init(void)
{
	// define a cor de background da janela
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// define o sistema de visualização - tipo de projeção
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display() {

  // Limpa a janela, colocando na tela a cor definida pela função glClearColor
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  //void glutSolidSphere(GLdouble radius, GLint slices, GLint stacks
  glColor3f(.2, .21, .46);

  //Empilha o corpo inteiro da aranha
   glPushMatrix();
   	   glTranslatef(posatual_x, posatual_y, 0);
   	   glScalef(0.5, 0.5, 0);
   	   //Desenha o Corpo da Aranha
   	   //(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
   	   corpoAranha(angulo_alvo_graus-90, 0, 0, 0.20, 0.20);

	   //Empilha a cabeça da aranha
	   glPushMatrix();
		   glColor3f(255.0, 255.0, 0.0);
		   //Desenha a Cabeça da Aranha
		   corpoAranha(0, 0, 0.30, 0.10, 0.10);
		   //Desempilha a cabeça da aranha
	   glPopMatrix();


	   //***************************************************
	   //****      Desenhando as patas ***
	   //***************************************************

	   //Empilha a pata 1
	   glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(-30, 0.20, 0, 0.60, 0.010);

		   glColor3f(1.0f, 0.0f, 0.0f);
		   desenhapata(0, 0.60, 0, 0.60, 0.010);
		glPopMatrix();

		//Empilha a pata 2
		glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(35, 0.08, 0.20, 0.60, 0.010);

		   glColor3f(1.0f, 0.0f, 0.0f);
		   desenhapata(0, 0.60, 0, 0.60, 0.010);
		glPopMatrix();

		//Empilha a pata 3
		glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(angulo_teste, 0.15, 0.10, 0.60, 0.010);

		   glColor3f(1.0f, 0.0f, 0.0f);
		   desenhapata(-30, 0.60, 0, 0.60, 0.010);
		glPopMatrix();

		//Empilha a pata 4
		glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(angulo_teste, 0.08, 0.20, 0.60, 0.010);

		   glColor3f(1.0f, 0.0f, 0.0f);
		   desenhapata(-30, 0.60, 0, 0.60, 0.010);
		glPopMatrix();

   glPopMatrix();
   //Desempilha o corpo inteiro da aranha

 // Libera o buffer de comando de desenho para fazer o desenho acontecer o mais rápido possível.
 glutSwapBuffers();
}

void keyboard( unsigned char key, int x, int y )
{
	cout << "angulo_teste: " << angulo_teste << endl;
	switch( key ) {
	case 'p' : case 'P' :
		//glClearColor(0.0, 0.0, 0.0, 1.0);
		angulo_teste +=5;

	break;

	case 'b' : case 'B' :
		//glClearColor(1.0, 1.0, 1.0, 1.0);
		angulo_teste -=5;

	break;
	}
display();
}


void corpoAranha(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
	{
		//Aplica uma translação em todo o Corpo da Aranha
	   	glTranslatef(translacao_x, translacao_y, 0.0);
	   	glRotatef(angulo, 0, 0, 1);

	   	glPushMatrix();
		glScalef(size_x, size_y, 0);
		glutSolidSphere(1, 15, 15);
		glPopMatrix();
	}

void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
	{
		glTranslatef(translacao_x, translacao_y, 0);
		glRotatef(angulo, 0, 0, 1);
		glPushMatrix();
		glTranslatef(size_x/2, 0, 0);
		glScalef(size_x, size_y, 0);
		glutSolidCube(1);
		glPopMatrix();
	}

void mouseclick(int button, int action, int x, int y)
{

    if ((button == GLUT_LEFT_BUTTON) && (action == GLUT_DOWN))
    {
    	GLint altura_tela  = glutGet(GLUT_WINDOW_HEIGHT);
		GLint largura_tela = glutGet(GLUT_WINDOW_WIDTH);

		//Convertendo a posição da tela para posição da projeção
    	posfinal_x = x*(2.0/largura_tela)-1;
    	posfinal_y = 1 - y*(2.0/altura_tela);
    	cout << "posatual_x: " << x << endl;
    	cout << "posatual_y: " << y << endl;
    	cout << "posfinal_x: " << posfinal_x << endl;
    	cout << "posfinal_y: " << posfinal_y << endl;
    	cout << endl;


    	GLfloat vetor_dir_x, vetor_dir_y;

		//Realiza calculo vetor direção
		vetor_dir_x = posfinal_x - posatual_x;
		vetor_dir_y = posfinal_y - posatual_y;

		//Angulo do vetor direção
		angulo_alvo = atan2(vetor_dir_y, vetor_dir_x);
		angulo_alvo_graus = (angulo_alvo*180)/M_PI;
    }
  //display();
}

void bola(int passo)
	{

	GLfloat velocidade = .01;

	//atualiza posicao
	if(posatual_x != posfinal_x)
		posatual_x = posatual_x + (cos(angulo_alvo) * velocidade);
	if(posatual_y != posfinal_y)
		posatual_y = posatual_y + (sin(angulo_alvo) * velocidade);

	if(cos(angulo_alvo) < 0 && posatual_x < posfinal_x)
		posatual_x = posfinal_x;
	else if(cos(angulo_alvo) > 0 && posatual_x > posfinal_x)
		posatual_x = posfinal_x;
	if(sin(angulo_alvo) < 0 && posatual_y < posfinal_y)
		posatual_y = posfinal_y;
	else if(sin(angulo_alvo) > 0 && posatual_y > posfinal_y)
		posatual_y = posfinal_y;


	glutPostRedisplay();
	glutTimerFunc(10,bola, 1);

	}

// Função chamada quando o mouse anda sobre a janele
// e NÃO HÁ botão pressionado
void MouseAndandoNaoPressionado (int x, int y)
{
	//posdest_x = x;
	//posdest_y = y;
}

int main(int argc, char** argv)
{

 //Inicializa a biblioteca GLUT e negocia uma seção com o gerenciador de janelas.
 //É possível passar argumentos para a função glutInit provenientes da linha de execução, tais como informações sobre a geometria da tela
  glutInit(&argc, argv);

  //Informa à biblioteca GLUT o modo do display a ser utilizado quando a janela gráfica for criada.
  // O flag GLUT_SINGLE força o uso de uma janela com buffer simples, significando que todos os desenhos serão feitos diretamente nesta janela.
  // O flag GLUT_RGB determina que o modelo de cor utilizado será o modelo RGB.
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

  //Define o tamanho inicial da janela, 256x256 pixels, e a posição inicial do seu canto superior esquerdo na tela, (x, y)=(100, 100).
  glutInitWindowSize (600, 600);
  glutInitWindowPosition (100, 100);

  // Cria uma janela e define seu título
  glutCreateWindow ("Trabalho Aranha");

  //Nesta função é definido o estado inicial do OpenGL. Ajustes podem ser feitos para o usuário nessa função.
  init();

  // Define display() como a função de desenho (display callback) para a janela corrente.
  // Quando GLUT determina que esta janela deve ser redesenhada, a função de desenho é chamada.
  glutDisplayFunc(display);

  //Função que executa a animação
  glutTimerFunc(10,bola,1);

  // movimento SEM botão pressionado
  glutPassiveMotionFunc(MouseAndandoNaoPressionado);

  // Indica que sempre que uma tecla for pressionada no teclado, GLUT deverá chama a função keyboard() para tratar eventos de teclado (keyboard callback).
  // A função de teclado deve possuir o seguinte protótipo:
  glutKeyboardFunc(keyboard);


  glutMouseFunc(mouseclick);

  //Inicia o loop de processamento de desenhos com GLUT.
  // Esta rotina deve ser chamada pelo menos uma vez em um programa que utilize a biblioteca GLUT.
  glutMainLoop();

  return 0;

}

