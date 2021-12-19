#include "principal.h"

#include <QMessageBox>
#include "datopersona.h"
#include "widget.h"

#include <QDebug>

//#define ICON_PATH "C:\\Users\\coriz\\Pictures\\emotes\\1200px-Illuminati_triangle_eye.png"

Principal::Principal(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("Ventana principal");
    this->resize(600,400);
    this->setWindowIcon(QIcon(":/iconos/iluminati.png"));

    init_menu_bar();
    init_central_widget();

    //manejaDir();
}

void Principal::init_central_widget(){
    this->mainWidget = new QWidget();
    this->mainLayout = new QVBoxLayout(mainWidget);
    this->dataLayout = new QHBoxLayout();
    this->menuButtonsLayout = new QHBoxLayout();
    this->menuButtonsLayout->setAlignment(Qt::AlignRight);

    this->mainLayout->addLayout(dataLayout);
    this->mainLayout->addLayout(menuButtonsLayout);
    /* Bloque izquierdp del widget */
    this->dataListWidget = new QListWidget;
    this->dataListWidget->setMaximumWidth(400);
    this->selectedDataGBox = new QGroupBox("Datos");
    this->selectedDataLayout = new QVBoxLayout(this->selectedDataGBox);
    this->selectedDataLayout->setAlignment(Qt::AlignTop);
    this->dataLayout->addWidget(this->dataListWidget);
    this->dataLayout->addWidget(this->selectedDataGBox);
    /* **** */
    this->addDataButton = new QPushButton("Añadir");
    this->addDataButton->setMaximumWidth(100);
    QFont font;
    font.setPixelSize(15);
    font.setBold(true);
    font.setItalic(true);
    this->addDataButton->setFont(font);
    this->menuButtonsLayout->addWidget(this->addDataButton);

    this->setCentralWidget(this->mainWidget);

    nombre = new QLabel("");
    apellidoP = new QLabel("");
    apellidoM = new QLabel("");
    genero = new QLabel("");
    registro = new QLabel("");

    selectedDataLayout->addWidget(nombre);
    selectedDataLayout->addWidget(apellidoP);
    selectedDataLayout->addWidget(apellidoM);
    selectedDataLayout->addWidget(genero);
    selectedDataLayout->addWidget(registro);


    QObject::connect(this->addDataButton, SIGNAL(clicked(bool)),
                     this, SLOT(open_persona_window()));
    QObject::connect(this->dataListWidget, SIGNAL(currentRowChanged(int)),
                     this, SLOT(muestra_detalles(int)));

    //manejaDir();
}

void Principal::init_menu_bar()
{
    QAction *saveFileAction = new QAction("Guardar");
    saveFileAction->setStatusTip("Guarda un archivo");
    QObject::connect(saveFileAction, SIGNAL(triggered(bool)),
                     this, SLOT(guarda_archivo()));

    QAction *loadFileAction = new QAction("Cargar");
    loadFileAction->setStatusTip("Carga un archivo");
    QObject::connect(loadFileAction, SIGNAL(triggered(bool)),
                     this, SLOT(carga_archivo()));

    QAction *acercaAction = new QAction("Ver información");
    acercaAction->setStatusTip("Ver información acerca de nosotros");
    QObject::connect(acercaAction, SIGNAL(triggered(bool)),
                     this, SLOT(abrir_acerca_de()));

    this->menuArchivo = menuBar()->addMenu("Archivo");
    this->menuArchivo->addAction(saveFileAction);
    this->menuArchivo->addAction(loadFileAction);

    this->menuAcerca = menuBar()->addMenu("Acerca de..");
    this->menuAcerca->addAction(acercaAction);
}

void Principal::show_error(QString err){
    QMessageBox *box = new QMessageBox();
    box->setText(err);
    box->setIcon(QMessageBox::Warning);
    box->exec();
    delete box;
}

QLabel * Principal::open_img(QString imgPath){
    /*  para abrir una imagen */
    QLabel *imgLabel;
    imgLabel = new QLabel();                        // Label vacío
    QPixmap imgPixmap(imgPath);                     // "cargas la imagen"
    imgLabel->setPixmap(imgPixmap);                 // colocas la imagen
    imgLabel->setMask(imgLabel->pixmap()->mask());  // colocas máscara
    /* Abrir imagen termina aquí */
    return imgLabel;
}

QJsonObject Principal::obtener_personas_json()
{
    QJsonObject personasObject;
    QJsonArray listaPersonas;
    Q_FOREACH(Persona *persona, this->personas){
        QJsonObject object = persona->toJson();
        listaPersonas.push_back(object);
    }
    personasObject.insert("Personas",listaPersonas);
    return personasObject;
}

void Principal::manejaDir()
{
    //QString path = QFileDialog::getExistingDirectory();
    QDir dirActual(QDir::currentPath());
    //dirActual.setNameFilters(QStringList("*.jpg"));
    dirActual.setFilter(QDir::Files);
    QStringList archivos = dirActual.entryList();
    this->dataListWidget->addItems(archivos);
    /*Q_FOREACH(const QString &val, archivos){
        dataListWidget->addItem(val);
        qDebug() << val;
    }*/
}

void Principal::open_persona_window()
{
    DatoPersona *window;
    window = new DatoPersona();
    int result = window->exec();
    if(result == QDialog::Accepted){
        try{
            Persona *p = window->getPersona();
            if(!p) throw "Persona nulo";
            else{
                personas.append(p);
                dataListWidget->addItem(p->getNombre());
            }
        }catch(const char *message){
            show_error(message);
        }

    }
}

void Principal::test()
{
    emit senalaza("Para que vean que también puedo tener params");
}

void Principal::muestra_detalles(int row)
{
    Persona *p = personas.at(row);
    nombre->setText(QString("Nombre: " + p->getNombre()));
    apellidoP->setText(QString("Apellido Paterno: " + p->getApellidoPaterno()));
    apellidoM->setText(QString("Apellido Materno: " + p->getApellidoMaterno()));
    genero->setText(QString("Genero: " + p->getGenero()));
    registro->setText(QString("Registro: " + p->getRegistro().toString(DATE_FORMAT)));
}

void Principal::guarda_archivo()
{
    QString path = QFileDialog::getSaveFileName(this,"Guardar como",QDir::currentPath(),"JSON (*.json)");
    QFile file(path);
    QJsonObject personas = this->obtener_personas_json();
    QJsonDocument jsonDocument(personas);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!file.write(jsonDocument.toJson())){
        show_error("No se pudo guardar el archivo");
        return;
    }
    file.close();
}

void Principal::carga_archivo()
{
    QString path = QFileDialog::getOpenFileName(this,"Cargar json","","JSON (*.json)");
    QFile file(path); // ":/..." en caso de recursos
    try{
        if(!file.exists())
            throw QString("El archivo " + path + " no existe");
    }catch(QString message){
        show_error(message);
        return;
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString datos = file.readAll();
    file.close();
    QJsonObject object = QJsonDocument::fromJson(datos.toUtf8()).object();
    QJsonArray listaPersonas = object.value("Personas").toArray();
    Q_FOREACH(QJsonValue val, listaPersonas){
        Persona *p = new Persona(val.toObject());
        this->personas.push_back(p);
        this->dataListWidget->addItem(p->getNombre());
    }
}

void Principal::abrir_acerca_de()
{
    /*Widget *w = new Widget();
    w->show();*/
    /*QString path = QFileDialog::getExistingDirectory();
    QDir dirPath(path);
    dirPath.setNameFilters(QStringList("*.png"));
    dirPath.setFilter(QDir::Files);
    QStringList archivos = dirPath.entryList();
    this->dataListWidget->addItems(archivos);*/
}
