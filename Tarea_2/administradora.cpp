#include "administradora.h"
#include "persona.h"
#include "fechahora.h"

Administradora::Administradora()
{


}

void Administradora::imprimirMenu()
{
    cout<<"1 - Agregar datos"<<endl;
    cout<<"2 - Mostrar datos"<<endl;
    cout<<"3 - Salir"<<endl;
    cout<<endl;
    cout<<"opcion: ";
}

void Administradora::administrarMenu()
{
    Persona *persona = new Persona();
    bool loop=true;
    int opc;
    while(loop){
        imprimirMenu();
        cin>>opc;

        switch (opc) {
        case 1:
            cout<<endl;
            obtenerDatos();
            persona->setDatos(nombre,aPaterno,aMaterno,dia,mes,anio,hora,minuto,segundo,fechaFormato,HoraFormato);
            break;
        case 2:
            cout<<persona->getDatos()<<endl;
            cout<<endl;
            break;
        case 3:
            loop=false;
            break;
        default:
            cout<<"opcion invalida"<<endl;
            break;
        }

    }

}

void Administradora::obtenerDatos()
{
    FechaHora *fechaHoraO = new FechaHora();
    cout<<endl;
    cout<<"Nombre: ";
    cin>>this->nombre;
    cout<<"Apellido Paterno: ";
    cin>>this->aPaterno;
    cout<<"Apellido Materno: ";
    cin>>this->aMaterno;
    while(!fechaHoraO->validarFechaHora()){
        cout<<"Dia: ";
        cin>>this->dia;
        cout<<"Mes: ";
        cin>>this->mes;
        cout<<"Anio: ";
        cin>>this->anio;
        cout<<"Hora: ";
        cin>>this->hora;
        cout<<"Minuto: ";
        cin>>this->minuto;
        cout<<"Segundo: ";
        cin>>this->segundo;
        fechaHoraO->setFechaHora(dia,mes,anio,hora,minuto,segundo);
        cout<<endl;
    }
    this->fechaFormato=fechaHoraO->getFecha();
    this->HoraFormato=fechaHoraO->getFechaHora();

}
