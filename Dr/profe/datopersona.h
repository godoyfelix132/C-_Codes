#ifndef DATOPERSONA_H
#define DATOPERSONA_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QGroupBox>
#include <QRadioButton>
#include <QDialogButtonBox>
#include "persona.h"

#define DATE_FORMAT "hh:mm:ss.dd-MM-yyyy"
//#define DATE_FORMAT "dd.MM.yyyy"

class DatoPersona : public QDialog
{
    Q_OBJECT
public:
    DatoPersona();

    Persona *getPersona() const;
    void setPersona(Persona *value);
    void accept();

private:
    QVBoxLayout *mainLayout;
    QFormLayout *namesLayout;
    QHBoxLayout *dataLayout;
    QVBoxLayout *genLayout;
    QLineEdit *nameLineEdit;
    QLineEdit *lastPnameLineEdit;
    QLineEdit *lastMnameLineEdit;
    QGroupBox *genGBox;
    QRadioButton *hombreRButton;
    QRadioButton *mujerRButton;
    QRadioButton *otroRButton;
    QDateTimeEdit *dateTimeEdit;
    QDialogButtonBox *buttonBox;

    void datosInterfaz();

    Persona *persona;
};

#endif // DATOPERSONA_H
