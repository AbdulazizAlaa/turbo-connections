#ifndef VISUALIZINGWINDOW_H
#define VISUALIZINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class VisualizingWindow;
}

class VisualizingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VisualizingWindow(QWidget *parent = 0);
    ~VisualizingWindow();

private:
    Ui::VisualizingWindow *ui;
};

#endif // VISUALIZINGWINDOW_H
