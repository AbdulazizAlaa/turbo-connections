#ifndef NETWORKWINDOW_H
#define NETWORKWINDOW_H

#include <QMainWindow>

namespace Ui {
class NetworkWindow;
}

class NetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NetworkWindow(QWidget *parent = 0);
    ~NetworkWindow();

private:
    Ui::NetworkWindow *ui;
};

#endif // NETWORKWINDOW_H
