#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QDialog>
#include "animal.h"
#include <QString>
#include <QLabel>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QButtonGroup>
#include <QDialogButtonBox>
#include <QDateTimeEdit>
#include <QObject>

class Formulario : public QDialog
{
    Q_OBJECT
public:
    Formulario();
    Animal *getAnimal() const;
    void btn(bool flag);

private:
    Animal *animal;

    QPushButton *fotoPushButton;
    QPushButton *internarPushButton;
    QPushButton *esperaPushButton;
    QPushButton *liberarPushButton;

    QRadioButton *perroRButton;
    QRadioButton *gatoRButton;

    QLabel *imgVariable;
    QLabel * nombreLabel;
    QLabel * duenioLabel;

    QGroupBox *tipoGroup;

    QLineEdit *nombreLine;
    QLineEdit *duenioLine;

    //QWidget *mainWidget;
    QWidget *primerWidget;
    QWidget *segundoWidget;
    QWidget *tercerWidget;
    QWidget *imgWidget;

    QButtonGroup *grupoBotones;
    //QGroupBox *animalGroupBox;

    QVBoxLayout *mainLayout;
    QHBoxLayout *primerLayout;
    QFormLayout *segundoFormLayaout;
    QHBoxLayout *tercerLayout;
    QVBoxLayout *grouplayaout;
    QVBoxLayout *imgLayout;
    //QFormLayout *segundoFormLayaout;




};

#endif // FORMULARIO_H
