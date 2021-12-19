#include "datopersona.h"
#include <QButtonGroup>

DatoPersona::DatoPersona()
{
    this->mainLayout = new QVBoxLayout(this);

    this->namesLayout = new QFormLayout();
    this->nameLineEdit = new QLineEdit();
    this->lastPnameLineEdit = new QLineEdit();
    this->lastMnameLineEdit = new QLineEdit();
    namesLayout->addRow(new QLabel("Nombre:"), this->nameLineEdit);
    namesLayout->addRow(new QLabel("Apellido Paterno:"), this->lastPnameLineEdit);
    namesLayout->addRow(new QLabel("Apellido Materno:"), this->lastMnameLineEdit);
    this->mainLayout->addLayout(this->namesLayout);

    this->dataLayout = new QHBoxLayout();
    this->genGBox = new QGroupBox("Género");
    QButtonGroup *grupoBotones = new QButtonGroup;
    this->genLayout = new QVBoxLayout(this->genGBox);
    this->hombreRButton = new QRadioButton("Hombre");
    this->mujerRButton = new QRadioButton("Mujer");
    this->otroRButton = new QRadioButton("Prefiero no decirlo");
    grupoBotones->addButton(this->hombreRButton);
    grupoBotones->addButton(this->mujerRButton);
    grupoBotones->addButton(this->otroRButton);
    this->genLayout->addWidget(this->hombreRButton);
    this->genLayout->addWidget(this->mujerRButton);
    this->genLayout->addWidget(this->otroRButton);
    this->dataLayout->addWidget(this->genGBox);
    this->dateTimeEdit = new QDateTimeEdit();
    this->dataLayout->addWidget(this->dateTimeEdit);
    this->mainLayout->addLayout(dataLayout);

    this->buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    this->mainLayout->addWidget(this->buttonBox);

    QObject::connect(this->buttonBox, SIGNAL(accepted()),
                     this, SLOT(accept()));
    QObject::connect(this->buttonBox, SIGNAL(rejected()),
                     this, SLOT(reject()));
}

Persona *DatoPersona::getPersona() const
{
    return persona;
}

void DatoPersona::setPersona(Persona *value)
{
    persona = value;
}

void DatoPersona::accept()
{
    datosInterfaz();
    QDialog::accept();
}

void DatoPersona::datosInterfaz()
{
    QString nombre = nameLineEdit->text();
    QString apellidoP = lastPnameLineEdit->text();
    QString apellidoM = lastMnameLineEdit->text();
    QString genero;
    if(hombreRButton->isChecked()){
        genero = hombreRButton->text();
    }else if(mujerRButton->isChecked()){
        genero = mujerRButton->text();
    }else if(otroRButton->isChecked()){
        genero = otroRButton->text();
    }
    QDateTime registro = dateTimeEdit->dateTime();
    persona = new Persona(nombre,apellidoP,apellidoM,genero
                          ,registro);
}
