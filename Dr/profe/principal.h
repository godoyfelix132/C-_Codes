#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QtWidgets>
#include "persona.h"

class Principal : public QMainWindow
{
    Q_OBJECT
public:
    explicit Principal(QWidget *parent = nullptr);

private:
    QMenu *menuArchivo;
    QMenu *menuAcerca;

    QVBoxLayout *mainLayout;
    QHBoxLayout *dataLayout;
    QHBoxLayout *menuButtonsLayout;
    QVBoxLayout *selectedDataLayout;
    QGroupBox *selectedDataGBox;
    QListWidget *dataListWidget;
    QPushButton *addDataButton;
    QWidget *mainWidget;
    void init_central_widget();
    void init_toolbar();
    void init_menu_bar();
    void show_error(QString err);
    QLabel * open_img(QString imgPath);
    QJsonObject obtener_personas_json();
    QList<Persona*> personas;

    /* Etiquetas para ver */
    QLabel *nombre;
    QLabel *apellidoP;
    QLabel *apellidoM;
    QLabel *genero;
    QLabel *registro;

    void manejaDir();
    /* Armando widget */
    /* ... */
signals:
    void senalaza(QString prueba);
public slots:
    void open_persona_window();
    void test();
    void muestra_detalles(int row);
    void guarda_archivo();
    void carga_archivo();
    void abrir_acerca_de();
};

#endif // PRINCIPAL_H
