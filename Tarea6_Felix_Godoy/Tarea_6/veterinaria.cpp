#include "veterinaria.h"
#include <perro.h>
#include <gato.h>
#include <lista.h>
#include <fechahora.h>
#include <animal.h>
#include <nodo.h>
#include <cctype>


Veterinaria::Veterinaria()
{
    try
      {
        perro1 = new Perro("alistaPerro1");
        perro2 = new Perro("blistaPerro2");
        perro3 = new Perro("clistaPerro3");
        gato1 = new Gato("dlistaGato1");
        gato2 = new Gato("elistaGato2");
        gato3 = new Gato("flistaGato3");
        cperro1 = new Perro("gcolaPerro1");
        cperro2 = new Perro("hcolaPerro2");
        cperro3 = new Perro("icolaPerro3");
        cgato1 = new Gato("jcolaGato1");
        cgato2 = new Gato("kcolaGato2");
        cgato3 = new Gato("lcolaGato3");
        listaInternados = new Estructuras::Lista<Animal*>();
        listaOrdenada = new Estructuras::Lista<Animal*>();
        listaRecuperados = new Estructuras::Lista<Animal*>();
        cola = new Estructuras::Cola<Animal*>();
        vect = new vector<Animal*>();
        vect = new vector<Animal*>();
      }
      catch (std::exception)
      {
         std::cerr << "Error al crear objeto "<<endl;
      }
    perro1->setFechaIngreso(10,1,19,5,5,24);
    perro2->setFechaIngreso(18,2,19,6,11,35);
    perro3->setFechaIngreso(22,3,19,8,8,47);
    cperro1->setFechaIngreso(12,1,20,13,11,36);
    cperro2->setFechaIngreso(15,2,20,15,9,24);
    cperro3->setFechaIngreso(19,3,20,16,10,15);
    gato1->setFechaIngreso(12,1,19,8,7,52);
    gato2->setFechaIngreso(20,2,19,13,8,50);
    gato3->setFechaIngreso(25,3,19,16,7,47);
    cgato1->setFechaIngreso(13,1,20,18,4,26);
    cgato2->setFechaIngreso(18,2,20,23,6,24);
    cgato3->setFechaIngreso(23,3,20,14,40,25);
    cola->insertar(cperro1);
    cola->insertar(cgato1);
    cola->insertar(cperro2);
    cola->insertar(cgato2);
    cola->insertar(cperro3);
    cola->insertar(cgato3);

    vect->push_back(perro1);
    mapaInternados[perro1->getNombre()] = perro1;
    vect->push_back(gato1);
    mapaInternados[gato1->getNombre()] = gato1;
    vect->push_back(perro2);
    mapaInternados[perro2->getNombre()] = perro2;
    vect->push_back(gato2);
    mapaInternados[gato2->getNombre()] = gato2;
    vect->push_back(perro3);
    mapaInternados[perro3->getNombre()] = perro3;
    vect->push_back(gato3);
    mapaInternados[gato3->getNombre()] = gato3;

}

void Veterinaria::imprimirMenu()
{
    cout<<endl;
    cout<<"1 - Encolar animal"<<endl;
    cout<<"2 - Cola de animales"<<endl;
    cout<<"3 - Lista de animales internados"<<endl;
    cout<<"4 - Detalles de animal"<<endl;
    cout<<"5 - Lista ordenada de internados"<<endl;
    cout<<"6 - Atender siguiente"<<endl;
    cout<<"7 - Lista de animales dados de alta"<<endl;
    cout<<"8 - Dar de alta animal internado"<<endl;
    cout<<"9 - Buscar Internados"<<endl;
    cout<<"10 - Buscar dados de Alta"<<endl;
    cout<<"11 - salir"<<endl;
}

void Veterinaria::submenuAtender()
{
    cout<<"1 - Internar"<<endl;
    cout<<"2 - Liberar"<<endl;
}

int Veterinaria::obtenerOpcion(){
    int opc;
    cout<<endl<<"opc:";
    cin>>opc;
    return opc;
}

void Veterinaria::ejecutar(int opc){
    int opcx;//opciones internas
    int size;
    switch (opc) {
    case 1:
        cout<<"1 - Perro"<<endl;
        cout<<"2 - Gato"<<endl;
        cin>>opcx;
        cout<<"Nombre: ";
        cin>>this->nombre;
        if (opcx==1){
            try
            {
                perro = new Perro(nombre);
                this->cola->insertar(perro);
            }
            catch (std::exception)
            {
                 std::cerr << "Error al crear objeto "<<endl;
            }
        }else{
            try
            {
                gato = new Gato(nombre);
                this->cola->insertar(gato);
            }
            catch (std::exception)
            {
                 std::cerr << "Error al crear objeto "<<endl;
            }
        }

        break;
    case 2:
        imprimirLista(cola);
        break;
    case 3:
        //imprimirLista(listaInternados);
        size = vect->size();
        for(int i=0; i<size;i++){
           cout<<i<<" - "<<*vect->at(i)<<endl;
        }
        break;
    case 4:
        size = vect->size();
        for(int i=0; i<size;i++){
           cout<<i<<" - "<<*vect->at(i)<<endl;
        }
        cout<<"Ver: ";
        cin>>index;
        cout<<endl<<"ANIMAL"<<"\t\t"<<"INGRESO"<<endl;
        mostrarAnimal(index);
        cout<<endl;
        break;
    case 5:
        ordenarLista();
        break;
    case 6:
        atenderSiguiente();
        break;
    case 7:
        cout<<endl<<"ANIMAL"<<"\t\t"<<"INGRESO"<<"\t\t\t"<<"EGRESO"<<"\t"<<endl;
        imprimirListaAltas(listaRecuperados);
        break;
    case 8:
        size = vect->size();
        for(int i=0; i<size;i++){
           cout<<i<<" - "<<*vect->at(i)<<endl;
        }
        cout<<"Dar de alta a: ";
        cin>>opcx;
        darDeAlta(opcx);
        break;
    case 9:
        try {
            cout<<"Nombre: ";
            cin>>nombreMap;
            buscarAnimalInternado(nombreMap);
            throw;
        } catch (...) {
            cout<<"Nombre no encontrado"<<endl;
        }
        break;
    case 10:
        cout<<"Nombre: ";
        cin>>nombreMap;
        try {
            buscarAnimalAlta(nombreMap);
        } catch (...) {
            cout<<"Nombre no encontrado";
        }
    default:
        break;
    }
}

void Veterinaria::internarAnimal(Animal *animal)
{
    bool flag=false;
    while(flag==false){
        cout<<"Fecha de ingreso:"<<endl;
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
        FechaHora fechaHora;
        flag = fechaHora.validarFechaHora(dia,mes,anio,hora,minuto,segundo);
        if (flag==false){
            cout<<endl<<"Fecha incorrecta"<<endl<<endl;
        }
    }
    animal->setFechaIngreso(dia,mes,anio,hora,minuto,segundo);
    animal->internar();
    vect->push_back(animal);
    mapaInternados[animal->getNombre()] = animal;
}

Animal Veterinaria::siguienteAnimal()
{
    aux = cola->cima();
    cola->descolar();
    return *aux;
}

void Veterinaria::mostrarAnimal(int index)
{
    aux = vect->at(index);
    cout>>*aux<<endl;
}

void Veterinaria::atenderSiguiente()
{
    *aux = siguienteAnimal();
    cout<<"Atendiendo a : "<<*aux;

    cout<<endl<<"1 - Internar"<<endl;
    cout<<"2 - Liberar"<<endl;
    int opc;
    cin>>opc;
    if(!isdigit(opc)) throw;
    if(opc==1){
        internarAnimal(aux);
    }else if(opc==2){
        delete(aux);
    }
}

void Veterinaria::darDeAlta(int index)
{
    aux = vect->at(index);
    cout<<"Dar de alta a: "<<*aux<<endl;
    bool flag=false;
    while(flag==false){
        cout<<"Fecha de alta:"<<endl;
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
        FechaHora fechaHora;
        flag = fechaHora.validarFechaHora(dia,mes,anio,hora,minuto,segundo);
        if (flag==false){
            cout<<endl<<"Fecha incorrecta"<<endl<<endl;
        }
    }
    aux->setFechaEgreso(dia,mes,anio,hora,minuto,segundo);
    aux->darDeAlta();
    this->listaRecuperados->insertar(aux);
    mapaAlta[aux->getNombre()] = aux;
    mapaInternados.erase(vect->at(index)->getNombre());
    vect->erase(vect->begin()+index);

}

void Veterinaria::imprimirLista(Estructuras::Lista<Animal *> *_lista)
{
    for(int i=0;i<_lista->tamano();i++){
        aux = _lista->tomar(i);
        cout<<i<<" - "<<*aux<<endl;
    }
    cout<<endl;
}

void Veterinaria::imprimirListaAltas(Estructuras::Lista<Animal *> *_lista)
{
    for(int i=0;i<_lista->tamano();i++){
        aux = _lista->tomar(i);
        cout&&*aux;
        cout<<endl;
    }
    cout<<endl;
}

void Veterinaria::inprimirListaOrdenada(Estructuras::Lista<Animal *> *_lista)
{
    for(int i=0;i<_lista->tamano();i++){
        aux = _lista->tomar(i);
        cout<<*aux<<"\t"<<aux->tipoAnimal()<<endl;
    }
    cout<<endl;
}

void Veterinaria::ordenarLista()
{
    Animal *temp1;
    Animal *temp2;
    Animal *temp;
    int size = vect->size();
    for(int i=0;i<size;i++){
        listaOrdenada->insertar(vect->at(i));
    }
    for(int i=1;i<listaOrdenada->tamano();i++){
        for(int j=0;j<listaOrdenada->tamano()-1;j++){
            temp1=listaOrdenada->tomar(j);
            temp2=listaOrdenada->tomar(j+1);
            if(*temp1 > *temp2){
                temp = temp1;
                listaOrdenada->eliminar(j);
                listaOrdenada->insertar_en(temp2,j);
                listaOrdenada->eliminar(j+1);
                listaOrdenada->insertar_en(temp,j+1);
            }
        }
    }
    this->inprimirListaOrdenada(listaOrdenada);
    delete(listaOrdenada);
}

void Veterinaria::buscarAnimalInternado(string clave)
{
    try {
        cout>>*mapaInternados[clave]<<endl;
    } catch (...) {
        return throw ;
    }

}

void Veterinaria::buscarAnimalAlta(string clave)
{
    cout && *mapaAlta[clave];
    cout<<endl;
}

