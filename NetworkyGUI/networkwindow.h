#ifndef NETWORKWINDOW_H
#define NETWORKWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QAbstractItemView>
#include <QMessageBox>
#include <QString>
#include <QCompleter>
#include "../Network.h"
#include "visualizingwindow.h"

namespace Ui {
class NetworkWindow;
}

class NetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NetworkWindow(QWidget *parent = 0);
    ~NetworkWindow();

private slots:
    void on_updateB_clicked();

    void on_personsLV_clicked(const QModelIndex &index);

    void on_name_searchB_clicked();

    void on_name_searchLE_returnPressed();

    void on_visualizeNetB_clicked();

private:
    void updatePersonsLV(string file);

    void showPersonDetails(string name);

    Ui::NetworkWindow *ui;
    QStringListModel *personsModel;
    QStringList namesList;
    QStringListModel *connectionsModel;
    QStringList connectionsList;
    VisualizingWindow *visualizeWindow;
    Network * n;
    string filename;
};

#endif // NETWORKWINDOW_H
