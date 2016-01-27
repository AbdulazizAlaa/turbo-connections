#include "networkwindow.h"
#include "ui_networkwindow.h"

NetworkWindow::NetworkWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NetworkWindow)
{
    filename = "../data.txt";

    ui->setupUi(this);

    //creating instance from the network
    n = new Network(filename);

    ui->openGLWidget->setNetwork(n);

    //models used to display strings in list views
    connectionsModel = new QStringListModel(this);
    personsModel = new QStringListModel(this);
    //setting list views model
    ui->connectionsLV->setModel(connectionsModel);
    ui->personsLV->setModel(personsModel);
    //displaying names of person in the personsLV
    updatePersonsLV(filename);

    //setting up the name_searchLE completer
    QStringList list;
    for(uint i=0 ; i<n->person.size() ; i++){
        list << n->person.at(i)->name.c_str() ;
    }
    QCompleter *completer = new QCompleter(list, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    //completer->setCompletionMode(QCompleter::InlineCompletion);
    ui->name_searchLE->setCompleter(completer);
}

NetworkWindow::~NetworkWindow()
{
    delete visualizeWindow;
    delete n;
    delete personsModel;
    delete connectionsModel;
    delete ui;
}

void NetworkWindow::showPersonDetails(string name)
{
    Person * p = n->find(name, true);

    if(p==NULL)
        return;

    ui->person_name_label->setText(QString::fromStdString(p->name));
    ui->person_title_label->setText(QString::fromStdString(p->title));
    ui->person_company_label->setText(QString::fromStdString(p->company));
    ui->person_address_label->setText(QString::fromStdString(p->address));

    connectionsModel->removeRows( 0, connectionsModel->rowCount() );
    connectionsList.clear();

    for(uint i=0; i<p->connection.size() ; i++){
        connectionsList << p->connection.at(i)->name.c_str();
    }

    connectionsModel->setStringList(connectionsList);
}

void NetworkWindow::updatePersonsLV(string file)
{
    n->person.clear();
    n->readFile(file);

    personsModel->removeRows( 0, personsModel->rowCount() );
    namesList.clear();

    for(uint i=0 ; i<n->person.size() ; i++){
        namesList << n->person.at(i)->name.c_str() ;
    }
    personsModel->setStringList(namesList);
}

void NetworkWindow::on_updateB_clicked()
{
    updatePersonsLV(filename);
}

void NetworkWindow::on_personsLV_clicked(const QModelIndex &index)
{
    showPersonDetails(index.data().toString().toStdString());
}

void NetworkWindow::on_name_searchB_clicked()
{
    showPersonDetails(ui->name_searchLE->text().toStdString());
}

void NetworkWindow::on_name_searchLE_returnPressed()
{
    ui->name_searchB->click();
}

void NetworkWindow::on_visualizeNetB_clicked()
{
    visualizeWindow = new VisualizingWindow();
    visualizeWindow->show();
}
