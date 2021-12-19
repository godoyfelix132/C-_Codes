#include "widget.h"

#include <QLabel>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Pruebas");
    this->resize(600,400);
    mainLayout = new QHBoxLayout(this);
    //testGBox = new QGroupBox("Lista");
    listWidget = new QListWidget;
    mainLayout->addWidget(listWidget);
    //boxLayout = new QVBoxLayout(testGBox);
    //boxLayout->addWidget(listWidget);
    //testGBox->setGeometry(QRect(50,50,100,120));
    //testGBox->setParent(this);

    QDir dir(QDir::currentPath()+"/imgs");
    dir.setFilter(QDir::Files);
    QStringList files = dir.entryList();
    this->listWidget->addItems(files);
}

Widget::~Widget()
{

}
