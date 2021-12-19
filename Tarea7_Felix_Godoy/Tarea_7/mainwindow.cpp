#include "mainwindow.h"


//#define ICON_PATH "icono.ico"
//#define ICON_PATH "C:\\Users\\Felix\\Desktop\\PADTS\\c++\\Tarea7_Felix_Godoy\\icono.ico"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("Veterinaria");
    //this->showMaximized();
    //this->resize(800,600);
    this->setWindowIcon(QIcon(":/img/icono.ico"));
    init_central_widget();
    //this->showMinimized();
    //Formulario *form = new Formulario();
    //form->show();
}

MainWindow::~MainWindow()
{

}

void MainWindow::init_central_widget()
{
    crearWidgetPrincipales();
    crearLayouts();

    //Set layouts
    this->setCentralWidget(mainWidget);
    this->mainWidget    ->setLayout(this->mainLayout);
    this->firstWidget   ->setLayout(this->firstLayout);
    this->secondWidget  ->setLayout(this->secondLayout);

    this->listGroupBox  ->setLayout(this->listGroupLayout);
    this->infoGroupBox  ->setLayout(this->infoGroupLayout);
    this->imgWidget     ->setLayout(this->imgLayout);

    //Añadir widgets a los layout
    this->mainLayout        ->addWidget(this->firstWidget);

    this->firstLayout       ->addWidget(this->listGroupBox);
    this->listGroupLayout   ->addWidget(this->tabWidget);

    this->mainLayout        ->addWidget(this->secondWidget);

    this->secondLayout      ->addWidget(this->imgWidget);
    this->imgLayout         ->addWidget(this->imgVariable);

    this->secondLayout      ->addWidget(this->infoGroupBox);
    this->nombreLayout      ->addWidget(this->nombreLabel);
    this->nombreLayout      ->addWidget(this->nombreVariable);
    this->animalLayout      ->addWidget(this->animalLabel);
    this->animalLayout      ->addWidget(this->animalVariable);
    this->razaLayout        ->addWidget(this->razaLabel);
    this->razaLayout        ->addWidget(this->razaVariable);
    this->duenioLayout      ->addWidget(this->duenioLabel);
    this->duenioLayout      ->addWidget(this->duenioVariable);
    this->f_ingresoLayout   ->addWidget(this->f_ingresoLabel);
    this->f_ingresoLayout   ->addWidget(this->f_ingresoVariable);
    this->f_altaLayout      ->addWidget(this->f_altaLabel);
    this->f_altaLayout      ->addWidget(this->f_altaVariable);

    this->secondLayout      ->addWidget(this->actionPushBtn);




    //Grid informacion
    this->infoGroupLayout->addLayout(this->nombreLayout,0,0);
    this->infoGroupLayout->addLayout(this->animalLayout,0,1);
    this->infoGroupLayout->addLayout(this->duenioLayout,1,0);
    this->infoGroupLayout->addLayout(this->razaLayout,1,1);
    this->infoGroupLayout->addLayout(this->f_ingresoLayout,2,0,1,2);
    this->infoGroupLayout->addLayout(this->f_altaLayout,3,0,1,2);

    //listas
    this->internadosListWidget->addItem("lista");
    this->internadosListWidget->addItem("lista");
    this->colaListWidget->addItem("cola");
    this->colaListWidget->addItem("cola");
    this->altaListWidget->addItem("alta");
    this->altaListWidget->addItem("alta");


    //TabWidget
    tabWidget->addTab(internadosListWidget,"Internados");
    tabWidget->addTab(colaListWidget,"En espera");
    tabWidget->addTab(altaListWidget,"Dados de alta");

    //QObject::connect(this->actionPushBtn,SIGNAL(clicked(bool)),
                     //this,SLOT(show_error()));

    QObject::connect(this->actionPushBtn, SIGNAL(clicked(bool)),
                     this, SLOT(imgVariable->setText("hola")));
}

void MainWindow::crearWidgetPrincipales()
{
    //Principales
    this->mainWidget            = new QWidget();
    this->secondWidget          = new QWidget();
    this->firstWidget           = new QWidget();
    this->imgWidget             = new QWidget();

    //Etiquetas
    this->hello                 = new QLabel("Hola ");
    this->hello2                = new QLabel("Hola mundo");

    this->nombreLabel           = new QLabel("Nombre:");
    this->animalLabel           = new QLabel("Animal:");
    this->razaLabel             = new QLabel("Raza:");
    this->duenioLabel           = new QLabel("Dueño:");
    this->f_ingresoLabel        = new QLabel("Fecha de ingreso:");
    this->f_altaLabel           = new QLabel("Fecha de alta");
    this->nombreVariable        = new QLabel("Variable");
    this->animalVariable        = new QLabel("Variable");
    this->razaVariable          = new QLabel("Variable");
    this->duenioVariable        = new QLabel("Variable");
    this->f_ingresoVariable     = new QLabel("Variable");
    this->f_altaVariable        = new QLabel("Variable");
    this->imgVariable           = new QLabel("Imagen");

    //Botones
    this->actionPushBtn = new QPushButton();

    this->actionPushBtn->setText("Internar");

    //listas
    this->internadosListWidget  = new QListWidget();
    this->colaListWidget        = new QListWidget();
    this->altaListWidget        = new QListWidget();

    //GroupBox
    this->listGroupBox  = new QGroupBox();
    this->infoGroupBox  = new QGroupBox();

    this->infoGroupBox  ->setTitle("Información");
    this->listGroupBox  ->setTitle("Animal");

    //otros
    this->ListComboBox  = new QComboBox();
    this->tabWidget     = new QTabWidget();

}

void MainWindow::crearLayouts()
{
    this->mainLayout        = new QHBoxLayout();
    this->secondLayout      = new QVBoxLayout();
    this->firstLayout       = new QVBoxLayout();
    this->listGroupLayout   = new QVBoxLayout();
    this->infoGroupLayout   = new QGridLayout();

    this->nombreLayout      = new QHBoxLayout();
    this->animalLayout      = new QHBoxLayout();
    this->razaLayout        = new QHBoxLayout();
    this->duenioLayout      = new QHBoxLayout();
    this->f_ingresoLayout   = new QHBoxLayout();
    this->f_altaLayout      = new QHBoxLayout();
    this->imgLayout         = new QHBoxLayout();


}

void MainWindow::abrirFormulario()
{
    Formulario *form = new Formulario();
    int result = form->exec();
    if(result == QDialog::Accepted){
        try{
            Animal *animal = form->getAnimal();
            if(!animal) throw "Animal nulo";
            else{
                internados.append(animal);
                internadosListWidget->addItem(animal->getNombre());
            }
        }catch(const char *message){
            show_error(message);
        }

    }
}

void MainWindow::llenarlistas()
{

}

void MainWindow::show_error(QString err){
    QMessageBox *box = new QMessageBox();
    box->setText(err);
    box->setIcon(QMessageBox::Warning);
    box->exec();
    delete box;
}
