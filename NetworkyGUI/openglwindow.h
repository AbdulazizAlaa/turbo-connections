#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QOpenGLWidget>

class OpenGLWindow : public QOpenGLWidget
{
public:
    OpenGLWindow();

    virtual void initializeGL();
    virtual void resizeGL(int x, int y);
    virtual void paintGL();
};

#endif // OPENGLWINDOW_H
