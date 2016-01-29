#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QtMath>
#include <QVector>
#include <QDebug>
#include "node.h"
#include "link.h"
#include "network.h"

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget *parent = 0);
    ~OpenGLWidget();

    virtual void resizeGL(int x, int y);
    virtual void paintGL();
    virtual void initializeGL();

    void setNetwork(Network * n);
    void DrawCircle(int i);

private:
    Network * n;
    QVector<Node *> nodes;
    QVector<Link *> links;
};

#endif // OPENGLWIDGET_H
