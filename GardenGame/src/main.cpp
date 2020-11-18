#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl2.h>
#include <imgui/imgui_impl_glut.h>
#include <stdio.h>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "Renderer.h"
#include "Model.h"
#include "ModelsGenerator.h"
#include "Randomize.h"
#include "Texture.h"

struct vec3
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

vec3 cameraPos;
vec3 cameraFront;


int WIDTH = 1100;
int HEIGHT = 950;

float radius = 1.5;
float angle = 0.0f;

static float lightColor[]{ 1.0f, 1.0f, 1.0f };
static float lightPos[]{ 5.6f, 10.0f, 7.5f };

void WriteHeader(std::string);

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

	gluLookAt(cameraPos.x + 1.0, cameraPos.y + 1.0, cameraPos.z, cameraFront.x, cameraFront.y, cameraFront.z, 0.0f, 1.0f, 0.0f);
}

std::vector<Model> models;

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


void RenderIMGUI()
{
	static bool showCode = false;
	ImGui::Begin("3D Editor");

	ImGui::Checkbox("Show Code", &showCode);

	if (ImGui::CollapsingHeader("Camera Settings"))
	{
		if (ImGui::Button("Reset Camera Position"))
		{
			cameraPos.x = cameraPos.y = cameraPos.z = 0;
			cameraFront.x = cameraFront.y = cameraFront.z = 0;
			angle = 0.0f;
			radius = 1.5f;
		}

		ImGui::SliderFloat3("Camera Eye", &cameraPos.x, -radius, radius);
		ImGui::SliderFloat3("Camera Center", &cameraFront.x, -5.0, 5.0);
	}

	if (ImGui::CollapsingHeader("Light Settings"))
	{
		if (ImGui::Button("Reset Light Setup"))
		{
			lightColor[0] = lightColor[1] = lightColor[2] = 1.0f;

			lightPos[0] = 5.6f;
			lightPos[1] = 10.0f;
			lightPos[2] = 7.5f;
		};

		ImGui::ColorEdit3("Light Color", &lightColor[0]);
		ImGui::SliderFloat3("Light Position", &lightPos[0], -10.0, 10.0);
	}

	ImGui::Spacing();
	ImGui::Spacing();
	ImGui::Spacing();


	if (ImGui::Button("Cube"))
	{
		Model* cube = new Model();
		cube->CreateCube();
		models.push_back(*cube);
	}
	ImGui::SameLine();
	if (ImGui::Button("Sphere"))
	{
		Model* sphere = new Model();
		sphere->CreateSphere();
		models.push_back(*sphere);
	}
	ImGui::SameLine();
	if (ImGui::Button("Torus"))
	{
		Model* torus = new Model();
		torus->CreateTours();
		models.push_back(*torus);
	}
	if (ImGui::Button("Cylinder"))
	{
		Model* cylinder = new Model();
		cylinder->CreateCylinder();
		models.push_back(*cylinder);
	}
	ImGui::SameLine();
	if (ImGui::Button("Cone"))
	{
		Model* cone = new Model();
		cone->CreateCone();
		models.push_back(*cone);
	}
	ImGui::SameLine();
	if (ImGui::Button("Teapot"))
	{
		Model* teapot = new Model();
		teapot->CreateTeapot(0.5f);
		models.push_back(*teapot);
	}


	for (int i = models.size(); i-- > 0; )
	{
		Model& model = models.at(i);

		std::string name;

		ImGui::Spacing();

		name = model.GetPrimitveString() + " " + std::to_string(i);

		if (ImGui::CollapsingHeader(name.c_str()))
		{

			ImGui::Checkbox(std::string("Uniform Scale " + std::to_string(i)).c_str(), &model.uniformScale);
			ImGui::ColorEdit3(std::string("Color " + std::to_string(i)).c_str(), &model.color.R);
			ImGui::SliderFloat3(std::string("Position " + std::to_string(i)).c_str(), &model.position.at(0), -1.0f, 1.0f);
			if (model.uniformScale)
			{
				ImGui::SliderFloat(std::string("Scale " + std::to_string(i)).c_str(), &model.scale.at(0), 0.01f, 3.0f);
				model.scale.at(2) = model.scale.at(1) = model.scale.at(0);
			}
			else
				ImGui::SliderFloat3(std::string("Scale " + std::to_string(i)).c_str(), &model.scale.at(0), 0.01f, 3.0f);
			ImGui::SliderFloat3(std::string("Rotate " + std::to_string(i)).c_str(), &model.rotate.at(0), 0.0f, 360.0f);


			if (model.GetPrimitive() == Primitive::Tours)
			{
				ImGui::SliderFloat(std::string("Inner Radius " + std::to_string(i)).c_str(), &model.size, 0.0f, 2.0f);
				ImGui::SliderFloat(std::string("Outer Radius " + std::to_string(i)).c_str(), &model.modelHeight, 0.0f, 2.0f);
			}

			if (model.GetPrimitive() == Primitive::Cone)
			{
				ImGui::SliderFloat(std::string("Base " + std::to_string(i)).c_str(), &model.size, 0.0f, 2.0f);
				ImGui::SliderFloat(std::string("Height " + std::to_string(i)).c_str(), &model.modelHeight, 0.0f, 2.0f);
			}

			if (model.GetPrimitive() == Primitive::Sphere)
			{
				ImGui::SliderFloat(std::string("Radius " + std::to_string(i)).c_str(), &model.size, 0.0f, 2.0f);
			}

			if (model.GetPrimitive() == Primitive::Cylinder)
			{
				ImGui::SliderFloat(std::string("Base Radius " + std::to_string(i)).c_str(), &model.size, 0.0f, 2.0f);
				ImGui::SliderFloat(std::string("Top Radius " + std::to_string(i)).c_str(), &model.radius, 0.0f, 2.0f);
				ImGui::SliderFloat(std::string("Height " + std::to_string(i)).c_str(), &model.modelHeight, 0.0f, 2.0f);
			}

			if (model.GetPrimitive() != Primitive::Cube && model.GetPrimitive() != Primitive::Teapot)
			{
				ImGui::SliderInt(std::string("Slices " + std::to_string(i)).c_str(), &model.slices, 1, 50);
				ImGui::SliderInt(std::string("Stacks " + std::to_string(i)).c_str(), &model.stacks, 1, 50);
			}

			if (ImGui::Button(std::string("Delete: " + name).c_str()))
				models.erase(models.begin() + i);

		}
	}

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();

	static bool isGlutCode = false;
	std::string codeString;


	std::stringstream code;
	std::stringstream glutCode;


	if (isGlutCode)
	{

		glutCode << std::setprecision(4) << std::noshowbase;

		if (models.empty())
			glutCode << " \n \n";

		for (size_t i = 0; i < models.size(); i++)
		{
			Model& model = models.at(i);
			std::string name = model.GetPrimitveString() + " " + std::to_string(i) + "\n";

			glutCode << " // " + name;
			glutCode << "glPushMatrix();\n";
			glutCode << " glTranslatef(" << (model.position.at(0)) << ", " << (model.position.at(1)) << ", " << (model.position.at(2)) << ");\n";

			glutCode << " glRotatef(" << model.rotate.at(0) << ", 1, 0, 0);\n";
			glutCode << " glRotatef(" << model.rotate.at(1) << ", 1, 0, 0);\n";
			glutCode << " glRotatef(" << model.rotate.at(2) << ", 1, 0, 0);\n";

			glutCode << " glColor3f(" << (model.color.R) << ", " << (model.color.G) << ", " << (model.color.B) << ");\n";

			if (model.GetPrimitive() == Primitive::Cube)
				glutCode << " glutSolidCube(0.5f);\n";

			if (model.GetPrimitive() == Primitive::Teapot)
				glutCode << " glutSolidTeapot(0.5f);\n";

			if (model.GetPrimitive() == Primitive::Tours)
				glutCode << " glutSolidTorus(" << (model.size) << ", " << (model.modelHeight) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";

			if (model.GetPrimitive() == Primitive::Cone)
				glutCode << " glutSolidCone(" << (model.size) << ", " << (model.modelHeight) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";

			if (model.GetPrimitive() == Primitive::Sphere)
				glutCode << " glutSolidSphere(" << (model.size) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";

			if (model.GetPrimitive() == Primitive::Cylinder)
			{
				glutCode << " GLUquadricObj* qobj" << std::to_string(i) << ";\n" ;
				glutCode << " qobj" << std::to_string(i) << " = gluNewQuadric()"  << ";\n";
				glutCode << " gluQuadricDrawStyle(qobj" << std::to_string(i) << ", GLU_FILL);\n";
				glutCode << " gluCylinder( qobj" << std::to_string(i) << ", " << (model.size)  << ", " << (model.modelHeight) << ", " << (model.modelHeight) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";
			}
			glutCode << " glColor3f(" << 1 << ", " << 1 << ", " << 1 << ");\n";
			glutCode << "glPopMatrix();\n \n";
		}

	}

	code << std::setprecision(4) << std::noshowbase;

	if (models.empty())
		code << " \n \n";

	for (size_t i = 0; i < models.size(); i++)
	{
		Model& model = models.at(i);
		std::string name = model.GetPrimitveString() + std::to_string(i);

		code << " // " + name + "\n";
		code << "Model " << name << ";\n";


		if (model.GetPrimitive() == Primitive::Cube)
			code << name << ".CreateCube(" << model.size << ");\n";

		if (model.GetPrimitive() == Primitive::Teapot)
			code << name << ".CreateTeapot(" << model.size << ");\n";

		if (model.GetPrimitive() == Primitive::Tours)
			code << name << " .CreateTours(" << (model.size) << ", " << (model.modelHeight) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";

		if (model.GetPrimitive() == Primitive::Cone)
			code << name << " .CreateCone(" << (model.size) << ", " << (model.modelHeight) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";

		if (model.GetPrimitive() == Primitive::Sphere)
			code << name << " .CreateSphere(" << (model.size) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";

		if (model.GetPrimitive() == Primitive::Cylinder)
			code << name << " .CreateCylinder(" << (model.size) << ", " << (model.radius) << ", " << (model.modelHeight) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";

		code << name << ".Translate(" << model.position.at(0) << ", " << model.position.at(1) << ", " << model.position.at(2) << ");\n";
		code << name << ".Scale(" << model.scale.at(0) << ", " << model.scale.at(1) << ", " << model.scale.at(2) << ");\n";
		code << name << ".Rotate(" << model.rotate.at(0) << ", " << model.rotate.at(1) << ", " << model.rotate.at(2) << ");\n";
		code << name << ".SetColor(" << model.color.R << ", " << model.color.G << ", " << model.color.B << ");\n";

		code << "models.emplace_back(" << name << ");\n \n";


	}
	if (showCode)
	{
		ImGui::Begin("Code:");
		ImGui::Checkbox("GLUT Code", &isGlutCode);
		if (isGlutCode)
			codeString = glutCode.str();
		else
			codeString = code.str();
		char* c = const_cast<char*>(codeString.c_str());
		if (ImGui::Button("Copy Code"))
			ImGui::SetClipboardText(c);
		if (!isGlutCode)
			ImGui::InputTextMultiline("Code: ", c, codeString.length());
		else
			ImGui::InputTextMultiline("Code: ", c, codeString.length());
		ImGui::Text("W, A, S, D Buttons to change Camera's Eye");
		ImGui::Text("UP, LEFT, DOWN, RIGHT Arrows to change Camera's Center");
		ImGui::End();
	}
	WriteHeader(code.str());

	WIDTH = glutGet(GLUT_WINDOW_WIDTH);
	HEIGHT = glutGet(GLUT_WINDOW_HEIGHT);
	glViewport(0, 0, WIDTH, HEIGHT);

}
void RenderScene(void)
{
	SetupCamera();
	SetupLights();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.2f, 0.5f, 0.8f, 1.0f);

	for (size_t i = 0; i < models.size(); i++)
	{
		models.at(i).Render();
	}

	RenderIMGUI();
}

void key(unsigned char key, int x, int y)
{
	if (key == 'w')
		radius -= 0.5f;
	if (key == 's')
		radius += 0.5f;

	if (key == 'a')
		angle -= 5.0f;
	if (key == 'd')
		angle += 5.0f;

}

void key(int key, int x, int y)
{
	if (key == GLUT_KEY_DOWN)
		cameraFront.z += 0.1f;
	if (key == GLUT_KEY_UP)
		cameraFront.z -= 0.1f;
	if (key == GLUT_KEY_LEFT)
		cameraFront.x -= 0.1f;
	if (key == GLUT_KEY_RIGHT)
		cameraFront.x += 0.1f;
}



void glut_display_func()
{
	// Start the Dear ImGui frame
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGLUT_NewFrame();

	RenderScene();

	// Rendering
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());




	glutSwapBuffers();
	glutPostRedisplay();

}

void Generate(int value)
{
	GenerateModels(models);
}

void WriteHeader(std::string code)
{
	std::ofstream myfile("src/ModelsGenerator.h");
	if (myfile.is_open())
	{
		myfile << "#pragma once\n#include \"Model.h\"\nvoid GenerateModels(std::vector<Model>& models)\n {\n\n";
		myfile << code;
		myfile << "}\n";
	}
	else std::cout << "Unable to open file";
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


	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGLUT_Init();
	ImGui_ImplGLUT_InstallFuncs();
	ImGui_ImplOpenGL2_Init();

	gluOrtho2D(0, WIDTH, 0, HEIGHT);

	glutDisplayFunc(glut_display_func);

	//glutReshapeFunc(ReshapeCallback);


	glutKeyboardFunc(key);
	glutSpecialFunc(key);
	glutTimerFunc(100, Generate, 100);
	glutMainLoop();


	// Cleanup
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGLUT_Shutdown();
	ImGui::DestroyContext();



	return 1;
}
