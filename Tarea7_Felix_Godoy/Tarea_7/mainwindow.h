#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QListWidget>
#include <QPushButton>
#include <QAbstractScrollArea>
#include <QVector>
#include <QComboBox>
#include "animal.h"
#include <QRadioButton>
#include <QTabWidget>
#include <QList>
#include <QVector>
#include <QQueue>
#include <QMessageBox>
#include <QObject>

#include "formulario.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void crearWidgetPrincipales();
    void crearLayouts();
    void abrirFormulario();
    void llenarlistas();
    void show_error(QString err);
private:
    QWidget *mainWidget;
    QWidget *firstWidget;
    QWidget *secondWidget;
    QWidget *infoWidget;
    QWidget *imgWidget;

    QHBoxLayout *mainLayout;
    QVBoxLayout *firstLayout;
    QVBoxLayout *secondLayout;
    QVBoxLayout *listGroupLayout;
    QGridLayout *infoGroupLayout;
    QHBoxLayout *nombreLayout;
    QHBoxLayout *animalLayout;
    QHBoxLayout *razaLayout;
    QHBoxLayout *duenioLayout;
    QHBoxLayout *f_ingresoLayout;
    QHBoxLayout *f_altaLayout;
    QHBoxLayout *imgLayout;

    QRadioButton * radio = new QRadioButton();
    QTabWidget *tabWidget;

    QLabel *hello;
    QLabel *hello2;
    QLabel *nombreLabel;
    QLabel *animalLabel;
    QLabel *razaLabel;
    QLabel *duenioLabel;
    QLabel *f_ingresoLabel;
    QLabel *f_altaLabel;
    QLabel *nombreVariable;
    QLabel *animalVariable;
    QLabel *razaVariable;
    QLabel *duenioVariable;
    QLabel *f_ingresoVariable;
    QLabel *f_altaVariable;
    QLabel *imgVariable;



    QGroupBox *listGroupBox;
    QGroupBox *infoGroupBox;

    QListWidget *internadosListWidget;
    QListWidget *colaListWidget;
    QListWidget *altaListWidget;
    QLabel *ImgLabel;
    QPushButton *actionPushBtn;

    QComboBox *ListComboBox;

    QList<Animal*> internados;
    QQueue<Animal*> cola;
    QVector<Animal*> altas;

    QAbstractScrollArea *listScrollArea;

    void init_central_widget();

};
#endif // MAINWINDOW_H
