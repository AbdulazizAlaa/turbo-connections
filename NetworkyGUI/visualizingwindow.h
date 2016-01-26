#ifndef VISUALIZINGWINDOW_H
#define VISUALIZINGWINDOW_H

#include <QWindow>
#include <QOpenGLFunctions>

class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;

class VisualizingWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit VisualizingWindow(QWindow *parent = 0);
    ~VisualizingWindow();

    virtual void render(QPainter * painter);
    virtual void render();

    virtual void initialize();

    void setAnimating(bool animating);

private slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;

    void exposeEvent(QExposeEvent *event) Q_DECL_OVERRIDE;

private:
    bool m_update_pending;
    bool m_animating;

    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;


};

#endif // VISUALIZINGWINDOW_H
