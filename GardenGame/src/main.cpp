
#include "Renderer.h"
#include "Model.h"
#include "ModelsGenerator.h"
#include "Texture.h"
#include <math.h>
#include <windows.h>
#include <map>
#include "Randomize.h"


std::vector<std::string> modelGroups
{
	"Character",
	"Grass",
	"Table",
	"Pergola",
	"Swing",
	"Goal",
	"Park Bench",
	"Ground",
	"Fence",
	"Swimming Pool"
};


struct vec3
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

vec3 cameraPos;
vec3 cameraFront;

bool won = false;

int WIDTH = 1100;
int HEIGHT = 950;

float radius = 1.5f;
float angle = -45.11f;
float elapsedTime = 0.0f;

float gameOverTime = 10.0f;

static float lightColor[]{ 1.0f, 1.0f, 1.0f };
static float lightPos[]{ 5.6f, 10.0f, 7.5f };


void print(int x, int y, char* string)
{
	int len, i;

	glRasterPos2f(x, y);

	len = (int)strlen(string);

	for (i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
}


void SetupCamera()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-0.5, 0.5, -0.5, 0.5, -1, 1);
	gluPerspective(60, 16 / 9, 0.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	cameraPos.x = std::sin(angle * 3.14f / 180.0f) * radius;
	cameraPos.z = std::cos(angle * 3.14f / 180.0f) * radius;

	gluLookAt(cameraPos.x + 1.0, cameraPos.y + 3.0, cameraPos.z + 2.8, cameraFront.x, cameraFront.y, cameraFront.z, 0.0f, 1.0f, 0.0f);
}

std::vector<Model> models;
std::vector<bool> anim(5, false);

static float randX = Randomize(-1.0f, 1.0f);
static float randY = Randomize(-1.0f, 1.0f);

void RenderAnimate()
{

	static std::vector<float> angle(5, 0);
	for (auto& model : models)
		if (model.group == -1)
			model.Render();
		else
		{
			glPushMatrix();

			if (modelGroups.at(model.group) == "Pergola" && anim[0])
			{
				glTranslatef(0.48, 1.458, -0.034);
				glRotatef(angle[0], 0.0f, 1.0f, 0.0f);
				glTranslatef(-0.48, -1.458, 0.034);
				angle[0] += 0.1f;
			}

			if (modelGroups.at(model.group) == "Swing" && anim[1])
			{
				glTranslatef(-0.2, -0.158, -1.056);
				glRotatef(angle[1], 0.0f, 1.0f, 0.0f);
				glTranslatef(0.2, 0.158, 1.056);
				angle[1] += 0.1f;
			}

			if (modelGroups.at(model.group) == "Park Bench" && anim[2])
			{
				glTranslatef(-0.24, -0.4, 1.62);
				glRotatef(angle[2], 0.0f, 1.0f, 0.0f);
				glTranslatef(0.24, 0.4, -1.62);
				angle[2] += 0.1f;
			}

			if (modelGroups.at(model.group) == "Swimming Pool" && anim[3])
			{
				glTranslatef(1, -0.32, 1.1);
				glRotatef(angle[3], 0.0f, 1.0f, 0.0f);
				glTranslatef(-1, 0.32, -1.1);
				angle[3] += 0.1f;
			}

			if (modelGroups.at(model.group) == "Goal" && anim[4])
			{
				glTranslatef(randX - 0.765, 0, randY + 0.74);
				glRotatef(angle[4], 0.0f, 1.0f, 0.0f);
				glTranslatef(-(randX - 0.765), 0, -(randY + 0.74));
				angle[4] += 0.1f;
			}

			if (modelGroups.at(model.group) == "Goal")
				glTranslatef(randX, 0, randY);

			model.Render();
			glPopMatrix();
		}

}


void SetupLights()
{

	GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
	GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { lightColor[0], lightColor[1], lightColor[2], 1.0f };
	GLfloat lightPosition[] = { lightPos[0], lightPos[1], lightPos[2], 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void RenderScene(void)
{
	SetupCamera();
	SetupLights();


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.2f, 0.5f, 0.8f, 1.0f);

	RenderAnimate();

	char* p0s[20];

	if (gameOverTime < 1)
	{
		sprintf((char*)p0s, "You Lost the Game :(");
		if (!won)
			PlaySound(TEXT("lose.wav"), NULL, SND_ASYNC);
		won = true;
	}
	else if (won)
	{
		glColor3f(0, 1, 0);
		sprintf((char*)p0s, "You won The Game :D");
	}
	else
		sprintf((char*)p0s, "Time Remaining: %f", gameOverTime);

	print(0.1, 2.7, (char*)p0s);


}

bool ModelsIntresect(Model& model1, Model& model2, float x, float z)
{
	if (std::abs((model1.position.at(0) + x) - model2.position.at(0)) < model1.scale.at(0) / 4 + model2.scale.at(0) / 4)
		if (std::abs(model1.position.at(1) - model2.position.at(1)) < model1.scale.at(1) / 4 + model2.scale.at(1) / 4)
			if (std::abs((model1.position.at(2) + z) - model2.position.at(2)) < model1.scale.at(2) / 4 + model2.scale.at(2) / 4)
				return true;
	return false;
}

bool CheckCollision(float x, float z)
{
	for (auto& model : models)
		if (model.collider)
			for (auto& modelCollision : models)
				if (modelCollision.collider && &modelCollision != &model && model.group != -1)
					if (ModelsIntresect(model, modelCollision, x, z) && modelGroups.at(model.group) == "Character")
						return true;
	return false;
}

void key(unsigned char key, int x, int y)
{
	if (key == 'a')
	{
		angle = -45.11f;
		radius = 1.5f;
	}

	if (key == 's')
	{
		angle = -120.11f;
		radius = 5.5f;
	}

	if (key == 'd')
	{
		angle = 7.11f;
		radius = -7.5f;
	}

	switch (key)
	{
	case 'q': anim[0] = !anim[0]; PlaySound(TEXT("wood.wav"), NULL, SND_ASYNC); break;
	case 'w': anim[1] = !anim[1]; PlaySound(TEXT("wind.wav"), NULL, SND_ASYNC); break;
	case 'e': anim[2] = !anim[2]; PlaySound(TEXT("bench.wav"), NULL, SND_ASYNC); break;
	case 'r': anim[3] = !anim[3]; PlaySound(TEXT("water.wav"), NULL, SND_ASYNC); break;
	case 't': anim[4] = !anim[4]; PlaySound(TEXT("ice.wav"), NULL, SND_ASYNC); break;
	}

}


void key(int key, int x, int y)
{
	bool pass = false;
	const float limit = 0.2f;
	const float speed = 0.1f;

	if (won)
		return;

	static float goalX = randX - 0.765;
	static float goalY = randY + 0.74;
	static float charX = 0.0f;
	static float charY = 0.0f;


	for (auto& model : models)
		if (model.group != -1)
			if (modelGroups.at(model.group) == "Character")
			{
				charX = model.position.at(0);
				charY = model.position.at(2);
				break;
			}

	if (std::abs(goalX - charX) < 0.5f && std::abs(goalY - charY) < 0.5f)
	{
		won = true;
		PlaySound(TEXT("coin.wav"), NULL, SND_ASYNC);
	}

	std::cout << "(x: " << std::abs(goalX - charX) << ", y:" << std::abs(goalY - charY) << ")" << std::endl;

	for (auto& model : models)
		if (model.group != -1)
			if (modelGroups.at(model.group) == "Character")
			{

				if ((key == GLUT_KEY_DOWN && !CheckCollision(0.0f, limit)) || (key == GLUT_KEY_UP && !CheckCollision(0.0f, -limit)) || (key == GLUT_KEY_LEFT && !CheckCollision(-limit, 0.0f)) || (key == GLUT_KEY_RIGHT && !CheckCollision(limit, 0.0f)))
					pass = true;

				if (pass)
					if (key == GLUT_KEY_DOWN)
						model.TranslateAccum(0.0f, 0.0f, speed);
					else if (key == GLUT_KEY_UP)
						model.TranslateAccum(0.0f, 0.0f, -speed);
					else if (key == GLUT_KEY_LEFT)
						model.TranslateAccum(-speed, 0.0f, 0.0f);
					else if (key == GLUT_KEY_RIGHT)
						model.TranslateAccum(speed, 0.0f, 0.0f);
			}
}

void glut_display_func()
{
	RenderScene();
	glutSwapBuffers();
	glutPostRedisplay();
}

void Generate(int value)
{
	GenerateModels(models);
}

void timer(int value)
{
	if (gameOverTime >= 1)
		gameOverTime -= 1;
	glutTimerFunc(1000, timer, 1000);
}


void timerFence(int value)
{
	static float timeSpent;
	timeSpent += value;
	for (auto& model : models)
		if (model.group != -1)
			if (modelGroups.at(model.group) == "Fence")
				model.SetColor(std::abs(sin(timeSpent)), std::abs(cos(timeSpent)), std::abs(cos(timeSpent)));

	glutTimerFunc(100, timerFence, 100);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);


	glutCreateWindow("Garden Game");

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);


	gluOrtho2D(0, WIDTH, 0, HEIGHT);

	glutDisplayFunc(glut_display_func);

	glutTimerFunc(1000, timer, 1000);
	glutTimerFunc(100, timerFence, 100);

	//glutReshapeFunc(ReshapeCallback);

	Generate(100);

	glutKeyboardFunc(key);
	glutSpecialFunc(key);

	glutMainLoop();


	return 1;
}
