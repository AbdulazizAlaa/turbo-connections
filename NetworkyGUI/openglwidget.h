#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QtMath>

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget *parent = 0);
    ~OpenGLWidget();

    virtual void resizeGL(int x, int y);
    virtual void paintGL();
    virtual void initializeGL();
};

#endif // OPENGLWIDGET_H
