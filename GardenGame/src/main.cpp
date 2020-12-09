#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl2.h>
#include <imgui/imgui_impl_glut.h>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "Renderer.h"
#include "Model.h"
#include "ModelsGenerator.h"
#include "Texture.h"
#include <math.h>
#include <map>


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
	"Fence"

};

std::vector<bool> modelExpand(modelGroups.size(), false);
std::vector<float[3]> modelTrans(modelGroups.size());

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

float radius = 1.5f;
float angle = -45.11f;
float elapsedTime = 0.0f;

float gameOverTime = 10;

static float lightColor[]{ 1.0f, 1.0f, 1.0f };
static float lightPos[]{ 5.6f, 10.0f, 7.5f };

void WriteHeader(std::string code);

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

void Animate()
{
	float sumTime = 0.0f;

	for (auto& model : models)
	{
		if (modelGroups.at(model.group) == "Pergola")
		{
			model.TranslateAccum(cos(), cos(), 0);
		}
		
		if (modelGroups.at(model.group) == "Swing")
		{
		
		}
		
		if (modelGroups.at(model.group) == "Park Bench")
		{
		
		}
		
		if (modelGroups.at(model.group) == "Pergola")
		{
		
		}
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


void SortModels()
{
	std::sort(models.begin(),
		models.end(),
		[](const Model& lhs, const Model& rhs)
		{
			return rhs.group > lhs.group;
		});
}

void ShowModelAttributes(int i, Model& model, std::string name)
{
	ImGui::Checkbox(std::string("Uniform Scale " + model.id).c_str(), &model.uniformScale);
	ImGui::ColorEdit3(std::string("Color " + model.id).c_str(), &model.color.R);
	ImGui::SliderFloat3(std::string("Position " + model.id).c_str(), &model.position.at(0), -2.0f, 2.0f);

	if (model.uniformScale)
	{
		ImGui::SliderFloat(std::string("Scale " + model.id).c_str(), &model.scale.at(0), 0.01f, 10.0f);
		model.scale.at(2) = model.scale.at(1) = model.scale.at(0);
	}
	else
		ImGui::SliderFloat3(std::string("Scale " + model.id).c_str(), &model.scale.at(0), 0.01f, 10.0f);

	ImGui::SliderFloat3(std::string("Rotate " + model.id).c_str(), &model.rotate.at(0), 0.0f, 360.0f);


	if (model.GetPrimitive() == Primitive::Tours)
	{
		ImGui::SliderFloat(std::string("Inner Radius " + model.id).c_str(), &model.size, 0.0f, 2.0f);
		ImGui::SliderFloat(std::string("Outer Radius " + model.id).c_str(), &model.modelHeight, 0.0f, 2.0f);
	}

	if (model.GetPrimitive() == Primitive::Cone)
	{
		ImGui::SliderFloat(std::string("Base " + model.id).c_str(), &model.size, 0.0f, 2.0f);
		ImGui::SliderFloat(std::string("Height " + model.id).c_str(), &model.modelHeight, 0.0f, 2.0f);
	}

	if (model.GetPrimitive() == Primitive::Sphere)
	{
		ImGui::SliderFloat(std::string("Radius " + model.id).c_str(), &model.size, 0.0f, 2.0f);
	}

	if (model.GetPrimitive() == Primitive::Cylinder)
	{
		ImGui::SliderFloat(std::string("Base Radius " + model.id).c_str(), &model.size, 0.0f, 2.0f);
		ImGui::SliderFloat(std::string("Top Radius " + model.id).c_str(), &model.radius, 0.0f, 2.0f);
		ImGui::SliderFloat(std::string("Height " + model.id).c_str(), &model.modelHeight, 0.0f, 2.0f);
	}

	if (model.GetPrimitive() != Primitive::Cube && model.GetPrimitive() != Primitive::Teapot)
	{
		ImGui::SliderInt(std::string("Slices " + model.id).c_str(), &model.slices, 1, 50);
		ImGui::SliderInt(std::string("Stacks " + model.id).c_str(), &model.stacks, 1, 50);
	}

	if (ImGui::Button(std::string("Delete: " + name).c_str()))
	{
		for (size_t q = 0; q < models.size(); q++)
			if (&models.at(q) == &model)
				models.erase(models.begin() + q);
		return;
	}

	if (ImGui::Button(std::string("Duplicate: " + name).c_str()))
	{
		Model newModel = model;
		newModel.id = std::to_string(model.numofModels++);
		models.push_back(newModel);
		SortModels();
	}

	ImGui::Indent(20);
	if (ImGui::CollapsingHeader(std::string("Group " + name + " in ").c_str()))
		for (size_t i = 0; i < modelGroups.size(); i++)
		{
			if (ImGui::Button(std::string(modelGroups.at(i) + " " + name).c_str()))
			{
				model.group = i;
				SortModels();
			}
			if ((i % 3 != 0) || i == 0)
				ImGui::SameLine();
		}
	ImGui::Spacing();
	ImGui::Unindent(20);

	if (ImGui::Button(std::string("Delete " + model.id + " from Group").c_str()))
		model.group = -1;
	ImGui::Spacing();

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
		}

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

	if (ImGui::Button("Collision Box"))
	{
		Model* cube = new Model();
		cube->CreateWireCube();
		cube->collider = true;
		models.push_back(*cube);
	}


	int lastGroup = -1;
	SortModels();
	for (int i = models.size(); i-- > 0; )
	{
		ImGui::Spacing();

		Model& model = models.at(i);
		std::string name;
		name = model.GetPrimitveString() + " " + model.id;

		if (model.group == -1)
		{
			if (ImGui::CollapsingHeader(name.c_str()))
				ShowModelAttributes(i, model, name);
		}
		else
		{
			if (lastGroup != model.group)
				if (ImGui::CollapsingHeader(modelGroups.at(model.group).c_str()))
				{
					modelExpand.at(model.group) = true;
					ImGui::SliderFloat3(std::string(modelGroups.at(model.group)).c_str(), modelTrans.at(model.group), -2.0f, 2.0f);
				}
				else
					modelExpand.at(model.group) = false;

			if (modelExpand.at(model.group))
			{
				model.groupTrans.at(0) = modelTrans.at(model.group)[0];
				model.groupTrans.at(1) = modelTrans.at(model.group)[1];
				model.groupTrans.at(2) = modelTrans.at(model.group)[2];

				ImGui::Indent(20);
				if (ImGui::CollapsingHeader(name.c_str()))
					ShowModelAttributes(i, model, name);
				ImGui::Unindent(20);
			}

			lastGroup = model.group;
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
			std::string name = model.GetPrimitveString() + " " + model.id + "\n";

			if (model.group != -1)
				code << " // " + name + " of Group " + modelGroups.at(model.group) + "\n";
			else
				code << " // " + name + "\n";

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
				glutCode << " GLUquadricObj* qobj" << model.id << ";\n";
				glutCode << " qobj" << model.id << " = gluNewQuadric()" << ";\n";
				glutCode << " gluQuadricDrawStyle(qobj" << model.id << ", GLU_FILL);\n";
				glutCode << " gluCylinder( qobj" << model.id << ", " << (model.size) << ", " << (model.modelHeight) << ", " << (model.modelHeight) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";
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

		if (model.group != -1)
			code << " // " + name + " of Group " + modelGroups.at(model.group) + "\n";
		else
			code << " // " + name + "\n";

		code << "Model " << name << ";\n";

		if (model.GetPrimitive() == Primitive::Cube)
			code << name << ".CreateCube(" << model.size << ");\n";

		if (model.GetPrimitive() == Primitive::WireCube)
			code << name << ".CreateWireCube(" << model.size << ");\n";

		if (model.GetPrimitive() == Primitive::Teapot)
			code << name << ".CreateTeapot(" << model.size << ");\n";

		if (model.GetPrimitive() == Primitive::Tours)
			code << name << ".CreateTours(" << (model.size) << ", " << (model.modelHeight) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";

		if (model.GetPrimitive() == Primitive::Cone)
			code << name << ".CreateCone(" << (model.size) << ", " << (model.modelHeight) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";

		if (model.GetPrimitive() == Primitive::Sphere)
			code << name << ".CreateSphere(" << (model.size) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";

		if (model.GetPrimitive() == Primitive::Cylinder)
			code << name << ".CreateCylinder(" << (model.size) << ", " << (model.radius) << ", " << (model.modelHeight) << ", " << (model.slices) << ", " << (model.stacks) << ");\n";

		code << name << ".Translate(" << model.position.at(0) + model.groupTrans.at(0) << ", " << model.position.at(1) + model.groupTrans.at(1) << ", " << model.position.at(2) + model.groupTrans.at(2) << ");\n";

		if (model.scale.at(0) != 1 || model.scale.at(1) != 1 || model.scale.at(2) != 1)
			code << name << ".Scale(" << model.scale.at(0) << ", " << model.scale.at(1) << ", " << model.scale.at(2) << ");\n";

		if (model.rotate.at(0) != 0 || model.rotate.at(1) != 0 || model.rotate.at(2) != 0)
			code << name << ".Rotate(" << model.rotate.at(0) << ", " << model.rotate.at(1) << ", " << model.rotate.at(2) << ");\n";

		if (model.color.R != 1 || model.color.G != 1 || model.color.B != 1)
			code << name << ".SetColor(" << model.color.R << ", " << model.color.G << ", " << model.color.B << ");\n";

		if (model.collider)
			code << name << ".collider = " << "true;\n";

		if (model.group != -1)
			code << name << ".group = " << model.group << ";\n";

		code << "models.emplace_back(" << name << ");\n\n";
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

	for (auto& model : models)
		model.Render();

	RenderIMGUI();
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
	if (key == 'w')
		radius -= 0.5f;
	if (key == 's')
		radius += 0.5f;

	if (key == 'a')
		angle -= 5.0f;
	if (key == 'd')
		angle += 5.0f;

	if (key == 'q')
		cameraPos.y += 0.1f;
	if (key == 'e')
		cameraPos.y -= 0.1f;

	if (key == 't')
	{
		angle = -45.11f;
		radius = 1.5f;
	}

	if (key == 'y')
	{
		angle = -120.11f;
		radius = 5.5f;
	}

	if (key == 'u')
	{
		angle = 7.11f;
		radius = -7.5f;
	}

	if (key == 'z')
	{

	}
}

void key(int key, int x, int y)
{
	bool pass = false;
	const float limit = 0.2f;
	const float speed = 0.1f;
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


void timer(int value)
{

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
	std::ofstream myFile("src/ModelsGenerator.h");
	if (myFile.is_open())
	{
		myFile << "#pragma once\n#include \"Model.h\"\nvoid GenerateModels(std::vector<Model>& models)\n{\n\n";
		myFile << code;
		myFile << "}\n";
	}
}

void timer(int value)
{
	if (gameOverTime >= 1)
		gameOverTime -= 1;
	glutTimerFunc(1000, timer, 1000);
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

	glutTimerFunc(1000, timer, 1000);

	//glutReshapeFunc(ReshapeCallback);


	glutKeyboardFunc(key);
	glutSpecialFunc(key);
	Generate(100);
	glutMainLoop();


	// Cleanup
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGLUT_Shutdown();
	ImGui::DestroyContext();



	return 1;
}