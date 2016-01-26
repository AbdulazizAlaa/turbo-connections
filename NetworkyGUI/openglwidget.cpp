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

void DrawCircle(float r)
{
    float delta_theta = 0.0001;
    glColor3f(0,0,0);
    glBegin( GL_POLYGON ); // OR GL_LINE_LOOP

        for( float angle = 0; angle < 2*M_PI; angle += delta_theta )
            glVertex3f( r*qCos(angle), r*qSin(angle), 0 );

    glEnd();
}

void DrawLine(float x, float y)
{
    glLineWidth(2.5);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(15, 0, 0);
    glEnd();
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawCircle(.2);
    DrawLine(1,2);
}


void OpenGLWidget::initializeGL()
{
    glClearColor(1,0,0,1);

}
