#pragma once
#include <GL/glew.h>
#include "utilities.h"

class Window
{
public:
	Window(GLsizei w, GLsizei h)
	{
		this->width = w;
		this->height = h;
		this->window_handle = BAD_GL_VALUE;
		this->period = 1000 / 60;
		this->x2 = this->y2 = this->x = this->y = 0;
	}

	virtual void DisplayFunc() = 0;
	virtual void KeyboardFunc(unsigned char c, int x, int y) = 0;
	virtual void SpecialFunc(int c, int x, int y) = 0;
	virtual void TimerFunc(int value) = 0;
	virtual bool PostGLInitialize(void * data) = 0;
	virtual void TakeDown() = 0;

	void Axes()
	{
		GLboolean lighting_is_enabled = glIsEnabled(GL_LIGHTING);
		glDisable(GL_LIGHTING);
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 1.0f);
		glEnd();
		if (lighting_is_enabled)
			glEnable(GL_LIGHTING);
	}

	void ClearWindow(int width, int height)
	{
		glViewport(0, 0, width, height);
		glClearColor(0.7f, 0.9f, 0.9f, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void DisplayWindowName(char * s,int width, int height)
	{
		glColor3d(1, 1, 1);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_TEXTURE_2D);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0, width, 0, height, 1, 10);
		glViewport(0, 0, width, height);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
			glTranslated(10, 10, -5.5);
			glScaled(0.7, 0.7, 1.0);
			glutStrokeString(GLUT_STROKE_MONO_ROMAN, (const unsigned char *) s);
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

	}

	GLsizei width;
	GLsizei height;
	GLuint window_handle;
	GLint period;
	GLsizei x;
	GLsizei y;
	GLsizei x2;
	GLsizei y2;
};
