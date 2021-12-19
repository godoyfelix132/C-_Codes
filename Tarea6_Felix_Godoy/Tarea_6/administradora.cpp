#include <iostream>
#include "administradora.h"


using namespace std;

template <class T>
Administradora<T>::Administradora()
{
    string c1 = "Amor";
    string c2 = "Soledad";
    string c3 = "Intriga";
    string c4 = "Dado";
    string c5 = "Escalera";
    string c6 = "Puerta";
    string c7 = "Luna";
    string c8 = "Sol";
    string c9 = "Mesa";
    string c10 = "Casa";
    lista.insertar(c1);
    lista.insertar(c2);
    lista.insertar(c3);
    lista.insertar(c4);
    lista.insertar(c5);
    lista.insertar(c6);
    lista.insertar(c7);
    lista.insertar(c8);
    lista.insertar(c9);
    lista.insertar(c10);
}

template <class T>
void Administradora<T>::imprimirMenu()
{
    cout<<endl;
    cout<<"1: Insertar"<<endl;
    cout<<"2: Insertar en"<<endl;
    cout<<"3: Tomar"<<endl;
    cout<<"4: Buscar"<<endl;
    cout<<"5: Eliminar"<<endl;
    cout<<"6: Mostrar todo"<<endl;
    cout<<"7: Modificar"<<endl;
    cout<<"8: Vacio"<<endl;
    cout<<"9: Purga"<<endl;
    cout<<"10: Tamanio"<<endl;
    cout<<"11: Tomar primero"<<endl;
    cout<<"12: Salir"<<endl;
    cout<<endl;

}

template <class T>
int Administradora<T>::obtenerOpcion()
{
    cout<<"Opcion: ";
    cin>>this->option;
    return option;
}

template <class T>
void Administradora<T>::ejecutar(int opc)
{
    switch (opc) {
        case 1:
            cout<<"cancion a insertar: ";
            cin>>this->dato;
            lista.insertar(dato);
            break;
        case 2:
            cout<<"cancion a insertar: ";
            cin>>this->cancion;
            cout<<"posicion: ";
            cin>>this->posicion;
            lista.insertar_en(dato,posicion);
            break;
        case 3:
            cout<<"Numero de dato a tomar: ";
            cin>>index;
            cout<<"El dato numero "<<index<<" es "<<lista.tomar(index)<<endl;
            break;
        case 4:
            cout<<"cancion a buscar: ";
            cin>>this->cancion;
            cout<<"Cancion numero: "<<lista.buscar(dato)<<endl;
            break;
        case 5:
            cout<<"Dato a eliminar: ";
            cin>>index;
            cout<<lista.eliminar(index);
            break;
        case 6:
            lista.mostrarTodo();
            break;
        case 7:
            cout<<"Numero a modificar: ";
            cin>>index;
            cout<<"Cancion nueva: ";
            cin>>dato;
            lista.modificar(index,dato);
            break;
        case 8:
            cout<<lista.vacio()<<endl;
            break;
        case 9:
            lista.purga();
            break;
        case 10:
            cout<<"El tamanio es de "<<lista.tamano()<<endl;
            break;
        case 11:
            cout<<lista.tomarPrimero()<<endl;
            break;
        default:
            break;
    }
}
