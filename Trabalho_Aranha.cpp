/*
 * Trabalho 1 de CG - Aranha
 *
 *  Created on: out de 2020
 *      Author:
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

//Contrala o movimento das patas
GLint tipo_movimento = 0; // 0=parado p1=1 e p2=2
GLfloat move_pata1   = 0.0;
GLfloat move_pata2   = 0.0;
GLfloat tam_pata     = 0.20;
GLfloat larg_pata    = 0.020;

void move_Aranha(int passo);
void reinicia_Patas();
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
   	   corpoAranha(angulo_alvo_graus-90, 0, 0, 0.15, 0.15);

	   //Empilha a cabeça da aranha
	   glPushMatrix();
	   	   //RGB [%]: 100–7.8–7.8 - VERMELHO
		   glColor3f(1.0, 0.0, 0.0);
		   //Desenha a Cabeça da Aranha
		   corpoAranha(0, 0, 0.30, 0.10, 0.10);
		   //Desempilha a cabeça da aranha
	   glPopMatrix();


	   //***************************************************
	   //****      Desenhando as patas ***
	   //***************************************************

		//Empilha a pata 1D
		glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(35+move_pata2, 0.08, 0.20, tam_pata, larg_pata);

		   //RGB [%]: 35.7–16.5–45.9 - ROXO
		   //glColor3f(0.35f, 0.16f, 0.45f);
		   desenhapata(-45, tam_pata, 0, tam_pata, larg_pata);
		glPopMatrix();

		//Empilha a pata 2D
		glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(20+move_pata1, 0.12, 0.15, tam_pata, larg_pata);

		   //RGB [%]: 92.5–30.2–64.3 - ROSA
		   //glColor3f(0.92f, 0.30f, 0.64f);
		   desenhapata(-30, tam_pata, 0, tam_pata, larg_pata);
		glPopMatrix();

		//Empilha a pata 3D
		glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(0+move_pata2, 0.15, 0.10, tam_pata, larg_pata);

		   //RGB [%]: 24.7–61.2–61.2 - VERDE AZULADO
		   //glColor3f(0.24f, 0.61f, 0.61f);
		   desenhapata(-30, tam_pata, 0, tam_pata, larg_pata);
		glPopMatrix();

		//Empilha a pata 4D
	   glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(-30+move_pata1, 0.20, 0, tam_pata, larg_pata);

		   //RGB [%]: 15.3–45.9–32.5 - VERDE
		   //glColor3f(0.15f, 0.45f, 0.32f);
		   desenhapata(-30, tam_pata, 0, tam_pata, larg_pata);
		glPopMatrix();

		//Empilha a pata 1E
		glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(145+move_pata2, -0.08, 0.20, tam_pata, larg_pata);

		   //RGB [%]: 35.7–16.5–45.9 - ROXO
		   //glColor3f(0.35f, 0.16f, 0.45f);
		   desenhapata(45, tam_pata, 0, tam_pata, larg_pata);
		glPopMatrix();

		//Empilha a pata 2E
		glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(160+move_pata1, -0.12, 0.15, tam_pata, larg_pata);

		   //RGB [%]: 92.5–30.2–64.3 - ROSA
		   //glColor3f(0.92f, 0.30f, 0.64f);
		   desenhapata(30, tam_pata, 0, tam_pata, larg_pata);
		glPopMatrix();

		//Empilha a pata 3E
		glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(180+move_pata2, -0.15, 0.10, tam_pata, larg_pata);

		   //RGB [%]: 24.7–61.2–61.2 - VERDE AZULADO
		   //glColor3f(0.24f, 0.61f, 0.61f);
		   desenhapata(30, tam_pata, 0, tam_pata, larg_pata);
		glPopMatrix();

		//Empilha a pata 4E
	   glPushMatrix();
		   glColor3f(1.0, 1.0, 0.0);
		   //void desenhapata(GLfloat angulo, GLfloat translacao_x, GLfloat translacao_y, GLfloat size_x, GLfloat size_y)
		   desenhapata(210+move_pata1, -0.20, 0, tam_pata, larg_pata);

		   //RGB [%]: 15.3–45.9–32.5 - VERDE
		   //glColor3f(0.15f, 0.45f, 0.32f);
		   desenhapata(30, tam_pata, 0, tam_pata, larg_pata);
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
    	//Seta o tipo de movimento para começar a mexer as patas
    	tipo_movimento = 1;

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

void move_Aranha(int passo)
	{

	GLfloat velocidade = .03;
	GLfloat velocidade_pata = 2.0;

	//atualiza posicao
	if(posatual_x != posfinal_x)
		{
			posatual_x = posatual_x + (cos(angulo_alvo) * velocidade);

			if(tipo_movimento == 1)
				{
					//Movimento das patas
					move_pata1 +=  velocidade_pata;
					move_pata2 += -velocidade_pata;

					if(move_pata1 == 10)
						tipo_movimento = 2;
				}
			else if(tipo_movimento == 2)
				{
					//Movimento das patas
					move_pata1 += -velocidade_pata;
					move_pata2 +=  velocidade_pata;

					if(move_pata1 == -10)
						tipo_movimento = 1;
				}
		}

	if(posatual_y != posfinal_y)
		posatual_y = posatual_y + (sin(angulo_alvo) * velocidade);

	if(cos(angulo_alvo) < 0 && posatual_x < posfinal_x)
		{
			posatual_x = posfinal_x;
			reinicia_Patas();
		}
	else if(cos(angulo_alvo) > 0 && posatual_x > posfinal_x)
		{
			posatual_x = posfinal_x;
			reinicia_Patas();
		}
	if(sin(angulo_alvo) < 0 && posatual_y < posfinal_y)
		posatual_y = posfinal_y;
	else if(sin(angulo_alvo) > 0 && posatual_y > posfinal_y)
		posatual_y = posfinal_y;


	glutPostRedisplay();
	glutTimerFunc(50,move_Aranha, 1);

	}

void reinicia_Patas()
	{
		//Quando a aranha parar as patas sempre retornarão pra posição inicial
		move_pata1 = 0.0;
		move_pata2 = 0.0;
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
  glutTimerFunc(50,move_Aranha,1);

  // movimento SEM botão pressionado
  //glutPassiveMotionFunc(MouseAndandoNaoPressionado);

  // Indica que sempre que uma tecla for pressionada no teclado, GLUT deverá chama a função keyboard() para tratar eventos de teclado (keyboard callback).
  // A função de teclado deve possuir o seguinte protótipo:
  glutKeyboardFunc(keyboard);


  glutMouseFunc(mouseclick);

  //Inicia o loop de processamento de desenhos com GLUT.
  // Esta rotina deve ser chamada pelo menos uma vez em um programa que utilize a biblioteca GLUT.
  glutMainLoop();

  return 0;

}

