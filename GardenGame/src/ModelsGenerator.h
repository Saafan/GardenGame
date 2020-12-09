#pragma once
#include "Model.h"
void GenerateModels(std::vector<Model>& models)
{

 // Sphere0 of Group Character
Model Sphere0;
Sphere0.CreateSphere(0.5, 14, 15);
Sphere0.Translate(0.515, -0.259, 0.95);
Sphere0.Scale(0.754, 0.754, 0.754);
Sphere0.group = 0;
models.emplace_back(Sphere0);

 // Sphere1 of Group Character
Model Sphere1;
Sphere1.CreateSphere(0.5, 22, 10);
Sphere1.Translate(0.515, 0.308, 0.95);
Sphere1.Scale(0.541, 0.541, 0.541);
Sphere1.group = 0;
models.emplace_back(Sphere1);

 // CollisionBox2 of Group Character
Model CollisionBox2;
CollisionBox2.CreateWireCube(0.5);
CollisionBox2.Translate(0.522, 0.213, 0.9);
CollisionBox2.Scale(1.356, 2.561, 1);
CollisionBox2.collider = true;
CollisionBox2.group = 0;
models.emplace_back(CollisionBox2);

 // Sphere3 of Group Character
Model Sphere3;
Sphere3.CreateSphere(0.5, 16, 15);
Sphere3.Translate(0.515, 0.697, 0.95);
Sphere3.Scale(0.302, 0.302, 0.302);
Sphere3.group = 0;
models.emplace_back(Sphere3);

 // Sphere4 of Group Character
Model Sphere4;
Sphere4.CreateSphere(0.5, 22, 10);
Sphere4.Translate(0.476, 0.76, 0.87);
Sphere4.Scale(0.09, 0.09, 0.09);
Sphere4.SetColor(1e-06, 0, 0);
Sphere4.group = 0;
models.emplace_back(Sphere4);

 // Cylinder5 of Group Character
Model Cylinder5;
Cylinder5.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder5.Translate(0.346, 0.435, 0.95);
Cylinder5.Scale(0.052, 0.052, 1);
Cylinder5.Rotate(85.42, 312.7, 0);
Cylinder5.group = 0;
models.emplace_back(Cylinder5);

 // Torus6 of Group Character
Model Torus6;
Torus6.CreateTours(0.1, 0.8, 12, 23);
Torus6.Translate(0.52, 0.697, 0.85);
Torus6.Scale(0.098, 0.098, 0.063);
Torus6.Rotate(227.4, 0, 360);
Torus6.SetColor(1e-06, 1e-06, 1e-06);
Torus6.group = 0;
models.emplace_back(Torus6);

 // Cylinder7 of Group Character
Model Cylinder7;
Cylinder7.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder7.Translate(0.714, 0.384, 0.92);
Cylinder7.Scale(0.052, 0.052, 1);
Cylinder7.Rotate(85.42, 47.29, 0);
Cylinder7.group = 0;
models.emplace_back(Cylinder7);

 // Cone8 of Group Character
Model Cone8;
Cone8.CreateCone(0.5, 0.5, 10, 10);
Cone8.Translate(0.518, 0.693, 0.91);
Cone8.Scale(0.187, 0.187, 0.302);
Cone8.Rotate(0, 180.6, 0);
Cone8.SetColor(0.9804, 0.6949, 0.009612);
Cone8.group = 0;
models.emplace_back(Cone8);

 // Sphere9 of Group Character
Model Sphere9;
Sphere9.CreateSphere(0.5, 17, 10);
Sphere9.Translate(0.567, 0.742, 0.88);
Sphere9.Scale(0.116, 0.116, 0.116);
Sphere9.SetColor(1e-06, 0, 0);
Sphere9.group = 0;
models.emplace_back(Sphere9);

 // Cone10 of Group Grass
Model Cone10;
Cone10.CreateCone(0.5, 0.5, 10, 10);
Cone10.Translate(-1.38, -0.778, -0.561);
Cone10.Scale(0.364, 0.275, 0.623);
Cone10.Rotate(89.2, 175.2, 0);
Cone10.SetColor(0.09948, 0.5637, 0);
Cone10.group = 1;
models.emplace_back(Cone10);

 // Cone11 of Group Grass
Model Cone11;
Cone11.CreateCone(0.5, 0.5, 10, 10);
Cone11.Translate(-0.088, -0.708, 0);
Cone11.Scale(0.364, 0.275, 0.623);
Cone11.Rotate(89.2, 175.2, 0);
Cone11.SetColor(0.09948, 0.5637, 0);
Cone11.group = 1;
models.emplace_back(Cone11);

 // Cone12 of Group Grass
Model Cone12;
Cone12.CreateCone(0.5, 0.5, 10, 10);
Cone12.Translate(-1.38, -0.778, 1.579);
Cone12.Scale(0.364, 0.275, 0.623);
Cone12.Rotate(89.2, 175.2, 0);
Cone12.SetColor(0.09948, 0.5637, 0);
Cone12.group = 1;
models.emplace_back(Cone12);

 // Cone13 of Group Grass
Model Cone13;
Cone13.CreateCone(0.5, 0.5, 10, 10);
Cone13.Translate(1.027, -0.778, -0.561);
Cone13.Scale(0.364, 0.275, 0.623);
Cone13.Rotate(89.2, 175.2, 0);
Cone13.SetColor(0.09948, 0.5637, 0);
Cone13.group = 1;
models.emplace_back(Cone13);

 // Cone14 of Group Grass
Model Cone14;
Cone14.CreateCone(0.5, 0.5, 10, 10);
Cone14.Translate(-1.38, -0.778, -1.193);
Cone14.Scale(0.364, 0.275, 0.623);
Cone14.Rotate(89.2, 175.2, 0);
Cone14.SetColor(0.09948, 0.5637, 0);
Cone14.group = 1;
models.emplace_back(Cone14);

 // Cone15 of Group Grass
Model Cone15;
Cone15.CreateCone(0.5, 0.5, 10, 10);
Cone15.Translate(0.284, -0.778, -1.298);
Cone15.Scale(0.364, 0.275, 0.623);
Cone15.Rotate(89.2, 175.2, 0);
Cone15.SetColor(0.09948, 0.5637, 0);
Cone15.group = 1;
models.emplace_back(Cone15);

 // Cone16 of Group Grass
Model Cone16;
Cone16.CreateCone(0.5, 0.5, 10, 10);
Cone16.Translate(-0.849, -0.743, 0.912);
Cone16.Scale(0.364, 0.275, 0.623);
Cone16.Rotate(89.2, 175.2, 0);
Cone16.SetColor(0.09948, 0.5637, 0);
Cone16.group = 1;
models.emplace_back(Cone16);

 // Cone17 of Group Grass
Model Cone17;
Cone17.CreateCone(0.5, 0.5, 10, 10);
Cone17.Translate(0, -0.743, 0.912);
Cone17.Scale(0.364, 0.275, 0.623);
Cone17.Rotate(89.2, 175.2, 0);
Cone17.SetColor(0.09948, 0.5637, 0);
Cone17.group = 1;
models.emplace_back(Cone17);

 // Cone18 of Group Grass
Model Cone18;
Cone18.CreateCone(0.5, 0.5, 10, 10);
Cone18.Translate(1.416, -0.708, 1.579);
Cone18.Scale(0.364, 0.275, 0.623);
Cone18.Rotate(89.2, 175.2, 0);
Cone18.SetColor(0.09948, 0.5637, 0);
Cone18.group = 1;
models.emplace_back(Cone18);

 // Sphere19 of Group Table
Model Sphere19;
Sphere19.CreateSphere(0.5, 10, 10);
Sphere19.Translate(-1.531, -0.007, 0.08);
Sphere19.Scale(0.447, 0.01, 0.413);
Sphere19.SetColor(0.8588, 0.4863, 0.1059);
Sphere19.group = 2;
models.emplace_back(Sphere19);

 // Cylinder20 of Group Table
Model Cylinder20;
Cylinder20.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder20.Translate(-1.525, -0.052, 0.075);
Cylinder20.Scale(0.079, 0.079, 1.455);
Cylinder20.Rotate(64.72, 0, 88.99);
Cylinder20.SetColor(0.3382, 0.3382, 0.3382);
Cylinder20.group = 2;
models.emplace_back(Cylinder20);

 // Teapot21 of Group Table
Model Teapot21;
Teapot21.CreateTeapot(0.5);
Teapot21.Translate(-1.548, 0.038, 0.075);
Teapot21.Scale(0.148, 0.148, 0.148);
Teapot21.SetColor(0.4265, 0.004181, 0.004181);
Teapot21.group = 2;
models.emplace_back(Teapot21);

 // Cylinder22 of Group Table
Model Cylinder22;
Cylinder22.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder22.Translate(-1.525, -0.08, 0.075);
Cylinder22.Scale(0.079, 0.079, 1.455);
Cylinder22.Rotate(84.94, 343.8, 88.99);
Cylinder22.SetColor(0.3382, 0.3382, 0.3382);
Cylinder22.group = 2;
models.emplace_back(Cylinder22);

 // Cylinder23 of Group Table
Model Cylinder23;
Cylinder23.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder23.Translate(-1.542, -0.007, 0.086);
Cylinder23.Scale(0.365, 0.365, 0.178);
Cylinder23.Rotate(88.99, 0, 0);
Cylinder23.group = 2;
models.emplace_back(Cylinder23);

 // Cylinder24 of Group Table
Model Cylinder24;
Cylinder24.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder24.Translate(-1.525, -0.097, 0.075);
Cylinder24.Scale(0.079, 0.079, 1.455);
Cylinder24.Rotate(101.1, 0, 117.3);
Cylinder24.SetColor(0.3382, 0.3382, 0.3382);
Cylinder24.group = 2;
models.emplace_back(Cylinder24);

 // Cylinder25 of Group Table
Model Cylinder25;
Cylinder25.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder25.Translate(-1.525, -0.058, 0.075);
Cylinder25.Scale(0.079, 0.079, 1.455);
Cylinder25.Rotate(84.94, 16.18, 88.99);
Cylinder25.SetColor(0.3333, 0.3333, 0.3333);
Cylinder25.group = 2;
models.emplace_back(Cylinder25);

 // Cube26 of Group Pergola
Model Cube26;
Cube26.CreateCube(0.5);
Cube26.Translate(0.519, 0.243, 0.348);
Cube26.Scale(0.095, 4.337, 0.094);
Cube26.group = 3;
models.emplace_back(Cube26);

 // Cube27 of Group Pergola
Model Cube27;
Cube27.CreateCube(0.5);
Cube27.Translate(2.434, 0.243, 0.348);
Cube27.Scale(0.095, 4.337, 0.094);
Cube27.group = 3;
models.emplace_back(Cube27);

 // Cube28 of Group Pergola
Model Cube28;
Cube28.CreateCube(0.5);
Cube28.Translate(2.434, 0.339, -0.449);
Cube28.Scale(0.095, 4.337, 0.094);
Cube28.group = 3;
models.emplace_back(Cube28);

 // Cube29 of Group Pergola
Model Cube29;
Cube29.CreateCube(0.5);
Cube29.Translate(1.49, 1.367, 0.191);
Cube29.Scale(4.408, 0.278, 0.416);
Cube29.SetColor(0.651, 0.4039, 0);
Cube29.group = 3;
models.emplace_back(Cube29);

 // Cube30 of Group Pergola
Model Cube30;
Cube30.CreateCube(0.5);
Cube30.Translate(0.474, 0.328, -0.449);
Cube30.Scale(0.095, 4.337, 0.094);
Cube30.group = 3;
models.emplace_back(Cube30);

 // Cube31 of Group Pergola
Model Cube31;
Cube31.CreateCube(0.5);
Cube31.Translate(1.49, 1.424, -0.247);
Cube31.Scale(4.408, 0.278, 0.416);
Cube31.SetColor(0.652, 0.4027, 0);
Cube31.group = 3;
models.emplace_back(Cube31);

 // Cube32 of Group Pergola
Model Cube32;
Cube32.CreateCube(0.5);
Cube32.Translate(1.49, 1.458, -0.034);
Cube32.Scale(4.408, 0.278, 0.416);
Cube32.SetColor(0.6392, 0.4235, 0);
Cube32.group = 3;
models.emplace_back(Cube32);

 // Cube33 of Group Pergola
Model Cube33;
Cube33.CreateCube(0.5);
Cube33.Translate(1.479, 1.446, -0.449);
Cube33.Scale(4.408, 0.278, 0.416);
Cube33.SetColor(0.6431, 0.4235, 0);
Cube33.group = 3;
models.emplace_back(Cube33);

 // Cube34 of Group Pergola
Model Cube34;
Cube34.CreateCube(0.5);
Cube34.Translate(1.49, 1.379, 0.404);
Cube34.Scale(4.408, 0.278, 0.416);
Cube34.SetColor(0.6471, 0.4235, 0);
Cube34.group = 3;
models.emplace_back(Cube34);

 // Cylinder35 of Group Swing
Model Cylinder35;
Cylinder35.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder35.Translate(-0.93, 0.737, -1.132);
Cylinder35.Scale(0.035, 0.055, 3);
Cylinder35.Rotate(74.3, 0, 0);
Cylinder35.SetColor(0.4755, 0.4242, 0.4242);
Cylinder35.group = 4;
models.emplace_back(Cylinder35);

 // Cube36 of Group Swing
Model Cube36;
Cube36.CreateCube(0.5);
Cube36.Translate(-0.202, -0.141, -1.103);
Cube36.Scale(1.034, 0.092, 0.073);
Cube36.SetColor(0.8588, 0.4863, 0.2863);
Cube36.group = 4;
models.emplace_back(Cube36);

 // Cube37 of Group Swing
Model Cube37;
Cube37.CreateCube(0.5);
Cube37.Translate(-0.202, -0.145, -1.145);
Cube37.Scale(1.034, 0.092, 0.073);
Cube37.SetColor(0.8588, 0.4863, 0.2863);
Cube37.group = 4;
models.emplace_back(Cube37);

 // Cylinder38 of Group Swing
Model Cylinder38;
Cylinder38.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder38.Translate(0.321, 0.737, -1.12);
Cylinder38.Scale(0.035, 0.055, 3);
Cylinder38.Rotate(93.33, 0, 0);
Cylinder38.SetColor(0.4275, 0.4196, 0.4196);
Cylinder38.group = 4;
models.emplace_back(Cylinder38);

 // Cube39 of Group Swing
Model Cube39;
Cube39.CreateCube(0.5);
Cube39.Translate(-0.202, -0.166, -1.019);
Cube39.Scale(1.034, 0.092, 0.073);
Cube39.SetColor(0.8588, 0.4863, 0.2863);
Cube39.group = 4;
models.emplace_back(Cube39);

 // Cube40 of Group Swing
Model Cube40;
Cube40.CreateCube(0.5);
Cube40.Translate(-0.202, -0.162, -0.972);
Cube40.Scale(1.034, 0.092, 0.073);
Cube40.SetColor(0.8588, 0.4863, 0.2863);
Cube40.group = 4;
models.emplace_back(Cube40);

 // Cube41 of Group Swing
Model Cube41;
Cube41.CreateCube(0.5);
Cube41.Translate(-0.206, -0.137, -1.056);
Cube41.Scale(1.034, 0.092, 0.073);
Cube41.SetColor(0.8588, 0.4863, 0.2863);
Cube41.group = 4;
models.emplace_back(Cube41);

 // Cube42 of Group Swing
Model Cube42;
Cube42.CreateCube(0.5);
Cube42.Translate(-0.007, 0.27, -1.094);
Cube42.Scale(0.01, 1.829, 0.01);
Cube42.SetColor(0.6765, 0.6765, 0.6765);
Cube42.group = 4;
models.emplace_back(Cube42);

 // Cube43 of Group Swing
Model Cube43;
Cube43.CreateCube(0.5);
Cube43.Translate(-0.288, 0.721, -1.073);
Cube43.Scale(2.656, 0.175, 0.392);
Cube43.SetColor(0.402, 0.1714, 0.1714);
Cube43.group = 4;
models.emplace_back(Cube43);

 // Cylinder44 of Group Swing
Model Cylinder44;
Cylinder44.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder44.Translate(0.321, 0.737, -1.132);
Cylinder44.Scale(0.035, 0.055, 3);
Cylinder44.Rotate(74.3, 0, 0);
Cylinder44.SetColor(0.4363, 0.4063, 0.4063);
Cylinder44.group = 4;
models.emplace_back(Cylinder44);

 // Cylinder45 of Group Swing
Model Cylinder45;
Cylinder45.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder45.Translate(-0.926, 0.737, -1.12);
Cylinder45.Scale(0.035, 0.055, 3);
Cylinder45.Rotate(93.33, 0, 0);
Cylinder45.SetColor(0.4657, 0.4177, 0.4177);
Cylinder45.group = 4;
models.emplace_back(Cylinder45);

 // Cube46 of Group Swing
Model Cube46;
Cube46.CreateCube(0.5);
Cube46.Translate(-0.45, 0.266, -1.051);
Cube46.Scale(0.01, 1.613, 0.01);
Cube46.SetColor(0.4853, 0.4853, 0.4853);
Cube46.group = 4;
models.emplace_back(Cube46);

 // CollisionBox47 of Group Goal
Model CollisionBox47;
CollisionBox47.CreateWireCube(0.5);
CollisionBox47.Translate(0.993, -0.029, -1.245);
CollisionBox47.Scale(1.214, 2.348, 1);
CollisionBox47.collider = true;
CollisionBox47.group = 5;
models.emplace_back(CollisionBox47);

 // Sphere48 of Group Goal
Model Sphere48;
Sphere48.CreateSphere(0.5, 10, 10);
Sphere48.Translate(1.064, 0.247, -1.245);
Sphere48.Scale(0.41, 0.41, 0.41);
Sphere48.SetColor(1, 0, 0);
Sphere48.group = 5;
models.emplace_back(Sphere48);

 // Sphere49 of Group Goal
Model Sphere49;
Sphere49.CreateSphere(0.5, 10, 10);
Sphere49.Translate(0.893, 0.247, -1.245);
Sphere49.Scale(0.41, 0.41, 0.41);
Sphere49.SetColor(0.147, 0, 1);
Sphere49.group = 5;
models.emplace_back(Sphere49);

 // Cone50 of Group Goal
Model Cone50;
Cone50.CreateCone(0.5, 0.5, 10, 10);
Cone50.Translate(0.979, 0.29, -1.245);
Cone50.Scale(0.648, 0.576, 2.295);
Cone50.Rotate(95.75, 0, 0);
Cone50.SetColor(1, 0.6786, 0);
Cone50.group = 5;
models.emplace_back(Cone50);

 // Sphere51 of Group Goal
Model Sphere51;
Sphere51.CreateSphere(0.5, 10, 10);
Sphere51.Translate(1, 0.375, -1.415);
Sphere51.Scale(0.41, 0.41, 0.41);
Sphere51.SetColor(1, 0, 0.9118);
Sphere51.group = 5;
models.emplace_back(Sphere51);

 // Cylinder52 of Group Park Bench
Model Cylinder52;
Cylinder52.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder52.Translate(0.211, -0.649, 1.976);
Cylinder52.Scale(0.091, 0.091, 0.602);
Cylinder52.Rotate(245.6, 0, 0);
Cylinder52.SetColor(0.6275, 0.6274, 0.6274);
Cylinder52.group = 6;
models.emplace_back(Cylinder52);

 // Cube53 of Group Park Bench
Model Cube53;
Cube53.CreateCube(0.5);
Cube53.Translate(-0.287, -0.526, 1.914);
Cube53.Scale(1.85, 0.088, 0.139);
Cube53.Rotate(52.5, 0, 0);
Cube53.SetColor(0.6588, 0.4588, 0.2706);
Cube53.group = 6;
models.emplace_back(Cube53);

 // Cylinder54 of Group Park Bench
Model Cylinder54;
Cylinder54.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder54.Translate(0.211, -0.42, 1.584);
Cylinder54.Scale(0.091, 0.091, 0.627);
Cylinder54.Rotate(253.1, 0, 0);
Cylinder54.SetColor(0.6275, 0.6274, 0.6274);
Cylinder54.group = 6;
models.emplace_back(Cylinder54);

 // Cube55 of Group Park Bench
Model Cube55;
Cube55.CreateCube(0.5);
Cube55.Translate(-0.248, -0.483, 1.872);
Cube55.Scale(1.938, 0.088, 0.139);
Cube55.Rotate(31.88, 0, 0);
Cube55.SetColor(0.6588, 0.4588, 0.2706);
Cube55.group = 6;
models.emplace_back(Cube55);

 // Cube56 of Group Park Bench
Model Cube56;
Cube56.CreateCube(0.5);
Cube56.Translate(-0.268, -0.42, 1.749);
Cube56.Scale(2.026, 0.088, 0.139);
Cube56.SetColor(0.6569, 0.4637, 0.2705);
Cube56.group = 6;
models.emplace_back(Cube56);

 // Cube57 of Group Park Bench
Model Cube57;
Cube57.CreateCube(0.5);
Cube57.Translate(-0.287, -0.358, 1.563);
Cube57.Scale(1.985, 0.088, 0.139);
Cube57.Rotate(71.25, 0, 0);
Cube57.SetColor(0.6588, 0.4588, 0.2706);
Cube57.group = 6;
models.emplace_back(Cube57);

 // Cube58 of Group Park Bench
Model Cube58;
Cube58.CreateCube(0.5);
Cube58.Translate(-0.287, -0.399, 1.625);
Cube58.Scale(1.857, 0.088, 0.139);
Cube58.Rotate(20.63, 0, 0);
Cube58.SetColor(0.6588, 0.4588, 0.2706);
Cube58.group = 6;
models.emplace_back(Cube58);

 // Cylinder59 of Group Park Bench
Model Cylinder59;
Cylinder59.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder59.Translate(-0.747, -0.42, 1.584);
Cylinder59.Scale(0.091, 0.091, 0.627);
Cylinder59.Rotate(253.1, 0, 0);
Cylinder59.SetColor(0.6275, 0.6274, 0.6274);
Cylinder59.group = 6;
models.emplace_back(Cylinder59);

 // Torus60 of Group Park Bench
Model Torus60;
Torus60.CreateTours(0.266, 0.553, 10, 10);
Torus60.Translate(0.224, -0.525, 1.684);
Torus60.Scale(0.183, 0.183, 0.183);
Torus60.Rotate(0, 92.39, 0);
Torus60.SetColor(0.6235, 0.6235, 0.6314);
Torus60.group = 6;
models.emplace_back(Torus60);

 // Cube61 of Group Park Bench
Model Cube61;
Cube61.CreateCube(0.5);
Cube61.Translate(-0.268, -0.441, 1.811);
Cube61.Scale(1.93, 0.088, 0.139);
Cube61.Rotate(208.1, 0, 0);
Cube61.SetColor(0.6588, 0.4588, 0.2706);
Cube61.group = 6;
models.emplace_back(Cube61);

 // Cube62 of Group Park Bench
Model Cube62;
Cube62.CreateCube(0.5);
Cube62.Translate(-0.268, -0.42, 1.687);
Cube62.Scale(1.93, 0.088, 0.139);
Cube62.SetColor(0.6588, 0.4588, 0.2706);
Cube62.group = 6;
models.emplace_back(Cube62);

 // Cube63 of Group Park Bench
Model Cube63;
Cube63.CreateCube(0.5);
Cube63.Translate(-0.287, -0.149, 1.543);
Cube63.Scale(1.933, 0.088, 0.139);
Cube63.Rotate(90, 0, 0);
Cube63.SetColor(0.6588, 0.4588, 0.2706);
Cube63.group = 6;
models.emplace_back(Cube63);

 // Cylinder64 of Group Park Bench
Model Cylinder64;
Cylinder64.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder64.Translate(0.211, -0.399, 1.872);
Cylinder64.Scale(0.091, 0.091, 0.627);
Cylinder64.Rotate(178.1, 0, 0);
Cylinder64.SetColor(0.6275, 0.6274, 0.6274);
Cylinder64.group = 6;
models.emplace_back(Cylinder64);

 // Cube65 of Group Park Bench
Model Cube65;
Cube65.CreateCube(0.5);
Cube65.Translate(-0.287, -0.274, 1.563);
Cube65.Scale(1.985, 0.088, 0.139);
Cube65.Rotate(90, 0, 0);
Cube65.SetColor(0.6588, 0.4588, 0.2706);
Cube65.group = 6;
models.emplace_back(Cube65);

 // Cylinder66 of Group Park Bench
Model Cylinder66;
Cylinder66.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder66.Translate(-0.747, -0.399, 1.872);
Cylinder66.Scale(0.091, 0.091, 0.627);
Cylinder66.Rotate(178.1, 0, 0);
Cylinder66.SetColor(0.6275, 0.6274, 0.6274);
Cylinder66.group = 6;
models.emplace_back(Cylinder66);

 // Cylinder67 of Group Park Bench
Model Cylinder67;
Cylinder67.CreateCylinder(0.5, 0.5, 0.5, 10, 10);
Cylinder67.Translate(-0.747, -0.649, 1.976);
Cylinder67.Scale(0.091, 0.091, 0.602);
Cylinder67.Rotate(245.6, 0, 0);
Cylinder67.SetColor(0.6275, 0.6274, 0.6274);
Cylinder67.group = 6;
models.emplace_back(Cylinder67);

 // Cube68 of Group Park Bench
Model Cube68;
Cube68.CreateCube(0.5);
Cube68.Translate(-0.268, -0.232, 1.543);
Cube68.Scale(1.933, 0.088, 0.139);
Cube68.Rotate(90, 0, 0);
Cube68.SetColor(0.6588, 0.4588, 0.2706);
Cube68.group = 6;
models.emplace_back(Cube68);

 // Torus69 of Group Park Bench
Model Torus69;
Torus69.CreateTours(0.266, 0.553, 10, 10);
Torus69.Translate(-0.767, -0.525, 1.684);
Torus69.Scale(0.183, 0.183, 0.183);
Torus69.Rotate(0, 92.39, 0);
Torus69.SetColor(0.6235, 0.6235, 0.6314);
Torus69.group = 6;
models.emplace_back(Torus69);

 // Cube70 of Group Ground
Model Cube70;
Cube70.CreateCube(0.5);
Cube70.Translate(0.071, -0.672, 0.351);
Cube70.Scale(10, 0.01, 10);
Cube70.SetColor(0, 0.4804, 0.1413);
Cube70.group = 7;
models.emplace_back(Cube70);

 // CollisionBox71 of Group Fence
Model CollisionBox71;
CollisionBox71.CreateWireCube(0.5);
CollisionBox71.Translate(2, -0.341, 0.182);
CollisionBox71.Scale(0.719, 1.356, 10);
CollisionBox71.collider = true;
CollisionBox71.group = 8;
models.emplace_back(CollisionBox71);

 // CollisionBox72 of Group Fence
Model CollisionBox72;
CollisionBox72.CreateWireCube(0.5);
CollisionBox72.Translate(0, 0.014, -1.972);
CollisionBox72.Scale(9.504, 1, 1);
CollisionBox72.collider = true;
CollisionBox72.group = 8;
models.emplace_back(CollisionBox72);

 // CollisionBox73 of Group Fence
Model CollisionBox73;
CollisionBox73.CreateWireCube(0.5);
CollisionBox73.Translate(-2, -0.397, 0.294);
CollisionBox73.Scale(0.719, 1.498, 10);
CollisionBox73.collider = true;
CollisionBox73.group = 8;
models.emplace_back(CollisionBox73);

 // Cube74 of Group Fence
Model Cube74;
Cube74.CreateCube(0.5);
Cube74.Translate(0.085, -0.369, -2);
Cube74.Scale(10, 1.126, 0.435);
Cube74.SetColor(0.4705, 0, 1);
Cube74.group = 8;
models.emplace_back(Cube74);

 // Torus75 of Group Fence
Model Torus75;
Torus75.CreateTours(0.217, 0.8, 10, 10);
Torus75.Translate(-2, 0.24, -1.07);
Torus75.Scale(0.41, 0.41, 0.41);
Torus75.Rotate(0, 89.65, 0);
Torus75.SetColor(0.05882, 1, 0);
Torus75.group = 8;
models.emplace_back(Torus75);

 // Torus76 of Group Fence
Model Torus76;
Torus76.CreateTours(0.217, 0.8, 10, 10);
Torus76.Translate(0, 0.227, -2);
Torus76.Scale(0.41, 0.41, 0.41);
Torus76.SetColor(0.05952, 1, 0);
Torus76.group = 8;
models.emplace_back(Torus76);

 // Torus77 of Group Fence
Model Torus77;
Torus77.CreateTours(0.217, 0.8, 10, 10);
Torus77.Translate(1.319, 0.227, -2);
Torus77.Scale(0.41, 0.41, 0.41);
Torus77.SetColor(0.05882, 1, 0);
Torus77.group = 8;
models.emplace_back(Torus77);

 // Sphere78 of Group Fence
Model Sphere78;
Sphere78.CreateSphere(0.5, 10, 10);
Sphere78.Translate(-1.121, 0.213, -2);
Sphere78.Scale(0.393, 0.393, 0.393);
Sphere78.SetColor(1, 0, 0);
Sphere78.group = 8;
models.emplace_back(Sphere78);

 // Sphere79 of Group Fence
Model Sphere79;
Sphere79.CreateSphere(0.5, 10, 10);
Sphere79.Translate(2, 0.099, -1.636);
Sphere79.Scale(0.393, 0.393, 0.393);
Sphere79.SetColor(1, 0, 0);
Sphere79.group = 8;
models.emplace_back(Sphere79);

 // Cube80 of Group Fence
Model Cube80;
Cube80.CreateCube(0.5);
Cube80.Translate(-2, -0.352, 0.171);
Cube80.Scale(10, 1.126, 0.435);
Cube80.Rotate(0, 89.65, 0);
Cube80.SetColor(0.4706, 0, 1);
Cube80.group = 8;
models.emplace_back(Cube80);

 // Sphere81 of Group Fence
Model Sphere81;
Sphere81.CreateSphere(0.5, 10, 10);
Sphere81.Translate(2, 0.131, 1.385);
Sphere81.Scale(0.393, 0.393, 0.393);
Sphere81.SetColor(1, 0, 0);
Sphere81.group = 8;
models.emplace_back(Sphere81);

 // Torus82 of Group Fence
Model Torus82;
Torus82.CreateTours(0.217, 0.8, 10, 10);
Torus82.Translate(-1.128, 0.227, -2);
Torus82.Scale(0.41, 0.41, 0.41);
Torus82.SetColor(0.05882, 1, 0);
Torus82.group = 8;
models.emplace_back(Torus82);

 // Torus83 of Group Fence
Model Torus83;
Torus83.CreateTours(0.217, 0.8, 10, 10);
Torus83.Translate(-2, 0.24, 0.341);
Torus83.Scale(0.41, 0.41, 0.41);
Torus83.Rotate(0, 89.65, 0);
Torus83.SetColor(0.05882, 1, 0);
Torus83.group = 8;
models.emplace_back(Torus83);

 // Torus84 of Group Fence
Model Torus84;
Torus84.CreateTours(0.217, 0.8, 10, 10);
Torus84.Translate(-2, 0.224, 1.628);
Torus84.Scale(0.41, 0.41, 0.41);
Torus84.Rotate(0, 89.65, 0);
Torus84.SetColor(0, 1, 0.05882);
Torus84.group = 8;
models.emplace_back(Torus84);

 // Sphere85 of Group Fence
Model Sphere85;
Sphere85.CreateSphere(0.5, 10, 10);
Sphere85.Translate(-2, 0.131, 0.965);
Sphere85.Scale(0.393, 0.393, 0.393);
Sphere85.SetColor(1, 0, 0);
Sphere85.group = 8;
models.emplace_back(Sphere85);

 // Sphere86 of Group Fence
Model Sphere86;
Sphere86.CreateSphere(0.5, 10, 10);
Sphere86.Translate(-2, 0.131, -0.419);
Sphere86.Scale(0.393, 0.393, 0.393);
Sphere86.SetColor(1, 0, 0);
Sphere86.group = 8;
models.emplace_back(Sphere86);

 // Cube87 of Group Fence
Model Cube87;
Cube87.CreateCube(0.5);
Cube87.Translate(2, -0.352, 0.171);
Cube87.Scale(10, 1.126, 0.435);
Cube87.Rotate(0, 89.65, 0);
Cube87.SetColor(0.5, 0, 1);
Cube87.group = 8;
models.emplace_back(Cube87);

 // Torus88 of Group Fence
Model Torus88;
Torus88.CreateTours(0.217, 0.8, 10, 10);
Torus88.Translate(2, 0.364, -0.822);
Torus88.Scale(0.41, 0.41, 0.41);
Torus88.Rotate(0, 89.65, 0);
Torus88.SetColor(0.05882, 1, 0);
Torus88.group = 8;
models.emplace_back(Torus88);

 // Torus89 of Group Fence
Model Torus89;
Torus89.CreateTours(0.217, 0.8, 10, 10);
Torus89.Translate(2, 0.364, 0.806);
Torus89.Scale(0.41, 0.41, 0.41);
Torus89.Rotate(0, 89.65, 0);
Torus89.SetColor(0.05882, 1, 0);
Torus89.group = 8;
models.emplace_back(Torus89);

 // Torus90 of Group Fence
Model Torus90;
Torus90.CreateTours(0.217, 0.8, 10, 10);
Torus90.Translate(2, 0.364, 2);
Torus90.Scale(0.41, 0.41, 0.41);
Torus90.Rotate(0, 89.65, 0);
Torus90.SetColor(0.05952, 1, 0);
Torus90.group = 8;
models.emplace_back(Torus90);

 // Sphere91 of Group Fence
Model Sphere91;
Sphere91.CreateSphere(0.5, 10, 10);
Sphere91.Translate(2, 0.131, -0.126);
Sphere91.Scale(0.393, 0.393, 0.393);
Sphere91.SetColor(1, 0, 0);
Sphere91.group = 8;
models.emplace_back(Sphere91);

 // Sphere92 of Group Fence
Model Sphere92;
Sphere92.CreateSphere(0.5, 10, 10);
Sphere92.Translate(0.014, 0.213, -2);
Sphere92.Scale(0.393, 0.393, 0.393);
Sphere92.SetColor(1, 0, 0);
Sphere92.group = 8;
models.emplace_back(Sphere92);

 // Sphere93 of Group Fence
Model Sphere93;
Sphere93.CreateSphere(0.5, 10, 10);
Sphere93.Translate(1.319, 0.213, -2);
Sphere93.Scale(0.393, 0.393, 0.393);
Sphere93.SetColor(1, 0, 0);
Sphere93.group = 8;
models.emplace_back(Sphere93);

}
