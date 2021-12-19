#include "persona.h"

Persona::Persona()
{

}

Persona::Persona(QString nombre, QString apellidoPaterno, QString apelidoMaternom, QString genero, QDateTime registro)
{
    this->nombre = nombre;
    this->apellidoPaterno = apellidoPaterno;
    this->apellidoMaterno = apelidoMaternom;
    this->genero = genero;
    this->registro = registro;
}

Persona::Persona(const QJsonObject &object)
{
    this->nombre = object.value("nombre").toString();
    this->apellidoPaterno = object.value("apellidoP").toString();
    this->apellidoMaterno = object.value("apellidoM").toString();
    this->genero = object.value("genero").toString();
    this->registro = QDateTime::fromString(object.value("registro").toString());
}

QString Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const QString &value)
{
    nombre = value;
}

QString Persona::getApellidoPaterno() const
{
    return apellidoPaterno;
}

void Persona::setApellidoPaterno(const QString &value)
{
    apellidoPaterno = value;
}

QString Persona::getApellidoMaterno() const
{
    return apellidoMaterno;
}

void Persona::setApellidoMaterno(const QString &value)
{
    apellidoMaterno = value;
}

QString Persona::getGenero() const
{
    return genero;
}

void Persona::setGenero(const QString &value)
{
    genero = value;
}

QDateTime Persona::getRegistro() const
{
    return registro;
}

void Persona::setRegistro(const QDateTime &value)
{
    registro = value;
}

QJsonObject Persona::toJson()
{
    QJsonObject object;
    object.insert("nombre",this->nombre);
    object.insert("apellidoP",this->apellidoPaterno);
    object.insert("apellidoM",this->apellidoMaterno);
    object.insert("genero",this->genero);
    object.insert("registro",this->registro.toString());
    return object;
}
