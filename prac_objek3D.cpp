#include <GL/glut.h>
#include <math.h>
#include "Source.h"

typedef struct {
	int NumberofVertices;
	short int pnt[32];
} face_t;

typedef struct {
	float x, y;
} point2D_t;

typedef struct {
	float x, y, z;
} point3D_t;

typedef struct {
	float v[4];
} vector3D_t;

typedef struct {
	int NumberofVertices;
	point3D_t pnt[100];
	int NumberofFaces;
	face_t fc[32];
} object3D_t;

void userdraw(void) {
	object3D_t prisma = { 5,

	{{0,100,0},{100,0,0},{0,0,100},
	{-100,0,0},{0,0,-100}},5,
	{{3,{0,1,2}},{3,{0,2,3}},
	{3,{0,3,4}},{3,{0,4,1}},
	{4,{1,4,3,2}}} };
}

point2D_t Vector2Point2D(vector3D_t vec) {
	point2D_t pnt;
	pnt.x = vec.v[0];
	pnt.y = vec.v[1];
	return pnt;
}

vector3D_t Point2Vector(point3D_t pnt) {
	vector3D_t vec;
	vec.v[0] = pnt.x;
	vec.v[1] = pnt.y;
	vec.v[2] = pnt.z;
	vec.v[3] = 1.;
	return vec;
}

void display(void) {
	//menampilkan gambar
	glClear(GL_COLOR_BUFFER_BIT);
	userdraw();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Test");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(-320., 320., -240.0, 240.0);
	glutIdleFunc(display);
	glutDisplayFunc(display);
	glutMainLoop();
}