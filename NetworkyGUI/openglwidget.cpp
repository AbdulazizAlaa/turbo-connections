#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
}

OpenGLWidget::~OpenGLWidget()
{
}

void OpenGLWidget::resizeGL(int x, int y)
{

}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLWidget::initializeGL()
{
    glClearColor(1,0,0,1);
}
