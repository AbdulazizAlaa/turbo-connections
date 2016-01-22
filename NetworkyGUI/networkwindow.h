#ifndef NETWORKWINDOW_H
#define NETWORKWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QAbstractItemView>
#include <QMessageBox>
#include <QString>
#include "../Network.h"

namespace Ui {
class NetworkWindow;
}

class NetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NetworkWindow(QWidget *parent = 0);
    ~NetworkWindow();

    Network * n;
    string filename = "../data.txt";

private slots:
    void on_updateB_clicked();

    void on_personsLV_clicked(const QModelIndex &index);

private:
    void updatePersonsLV(string file);

    Ui::NetworkWindow *ui;
    QStringListModel *personsModel;
    QStringList namesList;
    QStringListModel *connectionsModel;
    QStringList connectionsList;
};

#endif // NETWORKWINDOW_H
