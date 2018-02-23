#include "stdafx.h"
#include "testOpengl.h"
#include "opengl_freeglut_glew/glew.h"
#include "opengl_freeglut_glew/freeglut.h"

GLuint VBO;
void CreateVertexBuffer() {
	struct Point{
		double x;
		double y;
		double z;
		Point(const double x, const double y, const double z) { this->x = x; this->y = y; this->z = z; }
	} pts[1] = { Point(0.0, 0.0, 0.0) };

	// create buffer
	glGenBuffers(1, &VBO);
	// bind buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// buffer data
	glBufferData(GL_ARRAY_BUFFER, sizeof(pts), pts, GL_STATIC_DRAW);
}

void RenderScenceCB() { //callback function
	// clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// how to interpret buffer data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableVertexAttribArray(0);

	// swap front and back buffer
	glutSwapBuffers();
}

void TEST_OPENGL::testOpengl(int argc, char* argv[]) {
	// init GLUT
	glutInit(&argc, argv);

	// display mode: double buffer¡¢RGBA
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// window setting 
	glutInitWindowSize(480, 320);      // window size
	glutInitWindowPosition(100, 100);  // window position
	glutCreateWindow("testOpengl");   // window title

	// render
	glutDisplayFunc(RenderScenceCB);

	// after clear color buffer
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// init glew
	if (GLEW_OK != glewInit()) return;

	// point data
	CreateVertexBuffer();

	// GLUT message loop
	glutMainLoop();
}
