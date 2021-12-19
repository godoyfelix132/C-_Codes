#include "animal.h"

Animal::Animal()
{

}

QString Animal::getNombre() const
{
    return nombre;
}

void Animal::setNombre(const QString &value)
{
    nombre = value;
}

QString Animal::getAnimal() const
{
    return animal;
}

void Animal::setAnimal(const QString &value)
{
    animal = value;
}

QString Animal::getDuenio() const
{
    return duenio;
}

void Animal::setDuenio(const QString &value)
{
    duenio = value;
}

QDateTime Animal::getF_ingreso() const
{
    return f_ingreso;
}

void Animal::setF_ingreso(const QDateTime &value)
{
    f_ingreso = value;
}

QDateTime Animal::getF_alta() const
{
    return f_alta;
}

void Animal::setF_alta(const QDateTime &value)
{
    f_alta = value;
}
