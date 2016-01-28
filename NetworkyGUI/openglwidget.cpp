#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{

}

OpenGLWidget::~OpenGLWidget()
{
}

void OpenGLWidget::setNetwork(Network * n)
{
    this->n = n;
    uint personListSize = n->person.size() ;
    uint connectionListSize = 0;
    float delta_theta = 20;
    float x,y, r = .8;
    float angle = 0;
    for(uint i=0; i<personListSize ; i++){
        QString name = n->person.at(i)->name;
        x = r * qCos(angle);
        y = r * qSin(angle);
        nodes.append(new Node(name,x,y));
        angle += delta_theta;
    }
//    for(uint i=0 ; i<personListSize ; i++){
//        connectionListSize = n->person.at(i)->connection.size();
//        for(uint j=0 ; j<connectionListSize ; j++){
//            links.append(new Link());
//        }
//    }
}

void OpenGLWidget::resizeGL(int x, int y)
{

}

void DrawCircle(float r, float x, float y)
{
    float delta_theta = 0.0001;
    glLoadIdentity();
    glColor3f(0,0,0);
//    glTranslatef(.5, .5, 0);
    glTranslatef(x, y, 0);
    glBegin( GL_POLYGON ); // OR GL_LINE_LOOP

        for( float angle = 0; angle < 2*M_PI; angle += delta_theta )
            glVertex3f( r*qCos(angle), r*qSin(angle), 0 );

    glEnd();
}

void DrawLine(float x, float y)
{
    glLineWidth(2);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(15, 0, 0);
    glEnd();
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawLine(1,2);
    for(int i=0 ; i<nodes.size() ; i++)
        DrawCircle(.1, nodes.at(i)->x, nodes.at(i)->y);
}


void OpenGLWidget::initializeGL()
{
    glClearColor(1,0,0,1);

}
