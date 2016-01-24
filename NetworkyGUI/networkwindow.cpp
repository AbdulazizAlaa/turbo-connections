#include "networkwindow.h"
#include "ui_networkwindow.h"

NetworkWindow::NetworkWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NetworkWindow)
{
    ui->setupUi(this);
    n = new Network(filename);

    connectionsModel = new QStringListModel(this);
    personsModel = new QStringListModel(this);

    ui->connectionsLV->setModel(connectionsModel);
    ui->personsLV->setModel(personsModel);

    updatePersonsLV(filename);

    QStringList list;
    for(uint i=0 ; i<n->person.size() ; i++){
        list << n->person.at(i)->name.c_str() ;
    }
    QCompleter *completer = new QCompleter(list, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->name_searchLE->setCompleter(completer);

}

NetworkWindow::~NetworkWindow()
{
    delete ui;
}

void NetworkWindow::on_updateB_clicked()
{
    updatePersonsLV(filename);
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

void NetworkWindow::on_personsLV_clicked(const QModelIndex &index)
{

    Person * p = n->find(index.data().toString().toStdString(), true);

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

void NetworkWindow::on_name_searchB_clicked()
{
    string name = ui->name_searchLE->text().toStdString();

    vector<pair<string, int> > temp = n->QueryNameNotExactMatch(name);
    if(temp.size() == 0){
        personsModel->removeRows( 0, personsModel->rowCount() );
        namesList.clear();
    }else{

        personsModel->removeRows( 0, personsModel->rowCount() );
        namesList.clear();

        for(uint i=0 ; i<temp.size() ; i++){
            namesList << temp.at(i).first.c_str() ;
        }
        personsModel->setStringList(namesList);

        ui->personsLV->setCurrentIndex(personsModel->index(0,0));
    }
}

void NetworkWindow::on_name_searchLE_returnPressed()
{
    ui->name_searchB->click();
}

void NetworkWindow::on_name_searchLE_textChanged(const QString &text)
{

}
