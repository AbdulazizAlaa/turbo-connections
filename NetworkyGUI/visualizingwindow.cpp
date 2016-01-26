#include "visualizingwindow.h"
#include "ui_visualizingwindow.h"

VisualizingWindow::VisualizingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VisualizingWindow)
{
    ui->setupUi(this);
}

VisualizingWindow::~VisualizingWindow()
{
    delete ui;
}
