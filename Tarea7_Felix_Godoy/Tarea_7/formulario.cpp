#include "formulario.h"

Formulario::Formulario()
{
    this->setWindowTitle("Registro");
    this->setWindowIcon(QIcon(":/img/icono.ico"));
    fotoPushButton = new QPushButton();
    internarPushButton = new QPushButton();
    esperaPushButton = new QPushButton();
    liberarPushButton = new QPushButton();
    fotoPushButton->setText("Cargar foto");
    internarPushButton->setText("Internar");
    esperaPushButton->setText("En espera");
    liberarPushButton->setText("Liberar");

    perroRButton = new QRadioButton("Perro");
    gatoRButton = new QRadioButton("Gato");


    imgVariable = new QLabel("Imagen");
    nombreLabel = new QLabel("Nombre:");
    duenioLabel = new QLabel("Dueño:");

    tipoGroup = new QGroupBox("Tipo");

    nombreLine = new QLineEdit();
    duenioLine = new QLineEdit();

    //mainWidget = new QWidget();
    primerWidget = new QWidget();
    segundoWidget = new QWidget();
    tercerWidget = new QWidget();
    imgWidget = new QWidget();

    //animalGroupBox = new QGroupBox("Animal");
    grupoBotones = new QButtonGroup();
    grupoBotones->addButton(perroRButton);
    grupoBotones->addButton(gatoRButton);

    mainLayout = new QVBoxLayout();
    primerLayout  = new QHBoxLayout();
    tercerLayout  = new QHBoxLayout();
    imgLayout  = new QVBoxLayout();
    segundoFormLayaout  = new QFormLayout();
    grouplayaout = new QVBoxLayout();

    //Seteo de widgets
    this->setLayout(mainLayout);
    primerWidget->setLayout(primerLayout);
    segundoWidget->setLayout(segundoFormLayaout);
    tercerWidget->setLayout(tercerLayout);
    imgWidget->setLayout(imgLayout);
    tipoGroup->setLayout(grouplayaout);

    //Etablecer acomodo
    mainLayout->addWidget(primerWidget);
    mainLayout->addWidget(segundoWidget);
    mainLayout->addWidget(tercerWidget);

    primerLayout->addWidget(tipoGroup);
    grouplayaout->addWidget(perroRButton);
    grouplayaout->addWidget(gatoRButton);

    primerLayout->addWidget(imgWidget);
    imgLayout->addWidget(imgVariable);
    imgLayout->addWidget(fotoPushButton);

    segundoFormLayaout->addRow(nombreLabel,nombreLine);
    segundoFormLayaout->addRow(duenioLabel,duenioLine);

    tercerLayout->addWidget(liberarPushButton);
    tercerLayout->addWidget(esperaPushButton);
    tercerLayout->addWidget(internarPushButton);

    //grupoBotones->buttonPressed(perroRButton);
    //QObject::connect(this->perroRButton,SIGNAL(togle()),this,SLOT(btn()));
    //QObject::connect(this->perroRButton, SIGNAL(toggled(bool)),this,SLOT(btn(bool)));
    QObject::connect(this->fotoPushButton, SIGNAL(clicked(bool)),
                     this, SLOT(btn(bool)));
}

void Formulario::btn(bool flag){
    if(flag){
        this->imgVariable->hide();
    }
}

Animal *Formulario::getAnimal() const
{
    return animal;
}
