#include <iostream>
#include <lista.h>
#include "nodo.h"
#include "administradora.h"
#include "pila.h"
#include "cola.h"
#include <string>

using namespace std;

void pilasColas();
//bool evaluaSintaxis(char [],int);
//void atencionCliente();
//void sintaxis();


int main()
{
    ////////////////////////////////pilas y colas/////////////////////////////////
    pilasColas();
    //////////////////////////////////ejecicio sintaxis////////////////////////////
    //sintaxis();
    //////////////////////////////////atencion al cliente/////////////////////////
    //atencionCliente();
    ///////////////////////////////////administrador de tarea 1////////////////////////
//    int opc;
//    Administradora administradora;
//    do {
//        administradora.imprimirMenu();
//        opc = administradora.obtenerOpcion();
//        administradora.ejecutar(opc);
//    } while (opc!=12);

   cout <<endl;
   return 0;
}

bool evaluaSintaxis(char cadena[],int t){

    Pila *pila = new Pila();
    Cola *cola = new Cola();

    for(int i=0;i<t-1;i++){
      if(i<(t/2)){
          string s (1,cadena[i]);
          pila->insertar(s);
      }else{
          string s (1,cadena[i]);
          cola->insertar(s);
      }
    }
    Pila *tempPila = new Pila();
    Cola *tempCola = new Cola();
    tempPila = pila;
    tempCola = cola;
    bool flag = true;
    for(int i=0;i<(t-1)/2;i++){
        string b = tempCola->cima();
        string a = tempPila->cima();
        if((a=="[" || a=="{" || a=="(") && (b=="]" || b=="}" || b==")")){
            if((a=="[" && b=="]") || (a=="(" && b==")") || (a=="{" && b=="}")){
                flag = true;
            }else{
                return false;
            }
        }else{
            return false;
        }
        tempCola->descolar();
        tempPila->desapilar();
    }
    if(flag == true){
        return true;
    }else{
        return false;
    }
}

void atencionCliente(){
    cout<<endl<<"\t\tATENCION AL CLIENTE"<<endl;
    Cola *cola = new Cola();
    string nombre;
    int opc=0;
    while (opc!=4){
        cout<<endl;
        cout<<"1 - Nuevo"<<endl;
        cout<<"2 - Pasar"<<endl;
        cout<<"3 - Mostrar cola"<<endl;
        cout<<"4 - Salir"<<endl;
        cout<<endl<<"opcion: ";
        cin>>opc;
        switch (opc) {
        case 1:
            cout<<endl<<"Bienvenido a atencion a cliente, por favor, diga su nombre y lo pondremos en la cola de espera: "<<endl;
            cin>>nombre;
            cola->insertar(nombre);
            break;
        case 2:
            if(cola->tamano()!=0){
              cout<<endl<<cola->cima()<<" favor de pasar a ventanilla"<<endl;
              cola->descolar();
            }else{
                cout<<"No hay personas en la cola de espera"<<endl;
            }
            break;
        case 3:
            cout<<endl;
            cola->mostrarTodo();
            break;
        default:
            break;
        }
    }
}

void pilasColas(){

    cout<<endl<<"\t\tPILAS Y COLAS"<<endl;

    Pila *pila = new Pila();
    cout<<endl<<"INSERTA CANCIONES"<<endl;
    pila->insertar("Primer dato");
    pila->insertar("Segundo dato");
    pila->insertar("Tercer Dato");
    cout<<endl<<"EJECUTA MOSTRAR TODO"<<endl;
    pila->mostrarTodo();
    cout<<endl<<"EJECUTA DESAPILAR"<<endl;
    pila->desapilar();
    cout<<endl<<"EJECUTA MOSTRAR TODO"<<endl;
    pila->mostrarTodo();
    cout<<"IMPRIME LA CIMA"<<endl;
    cout<<pila->cima()<<endl;

    Cola *cola = new Cola();
    cout<<endl<<"INSERTA CANCIONES"<<endl;
    cola->insertar("Primer dato");
    cola->insertar("Segundo dato");
    cola->insertar("Tercer Dato");
    cout<<endl<<"EJECUTA MOSTRAR TODO"<<endl;
    cola->mostrarTodo();
    cout<<endl<<"EJECUTA DESCOLAR"<<endl;
    cola->descolar();
    cout<<endl<<"EJECUTA MOSTRAR TODO"<<endl;
    cola->mostrarTodo();
    cout<<"IMPRIME LA CIMA"<<endl;
    cout<<cola->cima()<<endl;
}

void sintaxis(){
    cout<<endl<<"\t\tEJERCIO DE SINTAXIS"<<endl;
    cout<<endl<<"EVALUANDO CADENA 1 CON SINTAXIS CORRECTA -{([])}-"<<endl;
    char cadena[] = "{([])}";
    int t=sizeof(cadena);
    cout<<"Evaluacion: "<<evaluaSintaxis(cadena,t)<<endl;
    cout<<endl<<"EVALUANDO CADENA 2 CON SINTAXIS INCORRECTA -{([)]}-"<<endl;
    char cadena2[] = "{([)])}";
    int t2=sizeof(cadena2);
    cout<<"Evaluacion: "<<evaluaSintaxis(cadena2,t2)<<endl;
}
