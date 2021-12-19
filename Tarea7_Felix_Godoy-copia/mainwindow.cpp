#include "mainwindow.h"

//#define ICON_PATH "icono.ico"
//#define ICON_PATH "C:\\Users\\Felix\\Desktop\\PADTS\\c++\\Tarea7_Felix_Godoy\\icono.ico"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("Veterinaria");
    //this->showMaximized();
    //this->resize(800,600);
    //this->setWindowIcon(QIcon(":/img/img/icono.ico"));
    init_central_widget();
}

MainWindow::~MainWindow()
{

}

void MainWindow::init_central_widget()
{

    this->hello = new QLabel("Hola mu01212ndo");
    this->hello2 = new QLabel("Hola mundo");

    this->mainWidget = new QWidget();
    this->mainLayout = new QHBoxLayout(this->mainWidget);

    this->dataWidget = new QWidget();
    this->dataLayout = new QVBoxLayout(this->dataWidget);


    this->listGroupBox = new QGroupBox();
    this->groupLayout = new QVBoxLayout(listGroupBox);

    this->listListWidget = new QListWidget();

    this->listGroupBox->setTitle("Lista");
    this->listListWidget->addItem("hola");
    this->listListWidget->addItem("hola");
    this->listListWidget->addItem("hola");
    this->listListWidget->addItem("hola");
    this->listListWidget->addItem("hola");
    this->listListWidget->addItem("hola");
    this->listListWidget->addItem("hola");

    this->mainLayout->addWidget(this->listGroupBox);
    this->groupLayout->addWidget(this->listListWidget);

    this->mainLayout->addWidget(dataWidget);
    this->dataLayout->addWidget(hello);
    this->dataLayout->addWidget(hello2);


    this->setCentralWidget(mainWidget);

}

