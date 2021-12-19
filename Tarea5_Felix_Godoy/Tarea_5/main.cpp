#include "veterinaria.h"
#include <fstream>
#include "animal.h"
#include <iostream>
#include <string.h>
#include "lista.h"
using namespace std;

void readFile(string fileName);
void writeFile(string fileName);
//lo que hay en b, se copia en a
//void copiar(Animal &a, Animal &b)
//{
//    a.setNombre(b.getNombre());
//    a.setFechaIngreso(b.getFechaIngreso());
//    a.setFechaEgreso(b.getFechaEgreso());
//}
int main()
{
//    char a[20] = "loo3";
//    char a2[20] = "f";

//    Estructuras::Lista<Animal*> *lista= new Estructuras::Lista<Animal*>();

//    fstream file;

//    Animal p("perro");
//    lista->insertar(&p);
//    cout<<*lista->tomar(0);



//    file.open("i.txt", ios::binary | ios::out);
//    if(!file){
//          cout<<"Error in creating file...\n";
//    }
//    file.seekp(0*sizeof (p),ios::end);
//    file.write((char*)lista->tomar(0),sizeof(p));
//    file.close();
//    cout<<"Date saved into file the file.\n";





//    file.open("i.txt",ios::in|ios::binary );
//    if(!file){
//           cout<<"Error in creating file...\n";
//    }

//    Perro t("");
//    if(file.read((char*)&t,sizeof(t))){
//            cout<<endl<<endl;
//            cout<<"Data extracted from file..\n";
//            //print the object
//            //t.getNombre();
//            cout>>t;
//            cout<<endl;
//    }
//    else{
//        cout<<"Error in reading data from file...\n";
//    }
//    file.close();



//    cout<<"ctr"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
//    //llenarListaInternadosInicial();

//    //fstream internadosIn("internados.txt", ios::binary | ios::in);
//    //readInternadosTxt(&internadosIn);
//     Perro *perro1 = new Perro("alPerro1");
//     Perro *perro2 = new Perro("blPerro2");
//     Gato *gato1 = new Gato("dlGato1");
//     Gato *gato2 = new Gato("elGato2");
//     perro1->setFechaIngreso(10,1,19,5,5,24);
//     perro2->setFechaIngreso(18,2,19,6,11,35);
//     gato1->setFechaIngreso(12,1,19,8,7,52);
//     gato2->setFechaIngreso(20,2,19,13,8,50);
//     int t = sizeof (Animal);
//     fstream f("fecha.txt", ios::binary | ios::in | ios::out);
//     //f.close();
//     //f.open("fecha.txt");
//     if(f.is_open()){
//         f.seekp(0,ios::beg);
//         cout<<"ctr"<<t<<endl;
//         f.write((char*) gato2, t );
//         //f.write((char*) perro1, t);
//         //f.write((char*) perro2, t);
//         //perro1->getNombre();
//     }else{
//         cerr<<"Error al abrir el archivo"<<endl;
//     }
//     //f.close();
//     Animal temp("");
//     f.open("fecha.txt");
//     if(f.is_open()){
//         f.seekg(0,ios::beg);
//         cout<<"ctr"<<t<<endl;
//         f.read((char*) temp, t );
//         cout<<"objeto"<<temp.getNombre()<<endl;
//         //f.write((char*) perro1, t);
//         //f.write((char*) perro2, t);
//         //perro1->getNombre();
//     }else{
//         cerr<<"Error al abrir el archivo"<<endl;
//     }
//     f.close();

//    writeFile("texto.txt");
//    readFile("texto.txt");
    Veterinaria *veterinaria = new Veterinaria();
    int opc=0;
    while(opc!=15){
        veterinaria->imprimirMenu();
        opc = veterinaria->obtenerOpcion();
        veterinaria->ejecutar(opc);
    }
    cout <<endl;
    return 0;
}

void readFile(string fileName){
    ifstream f(fileName);
    string s;
    if(f.is_open()){
        getline(f,s);
        while(!f.eof()){
            cout<<s<<endl;
            getline(f,s);
        }
    }else {
         cout<<"Error a al abrir archivo";
    }
    f.close();
}

void writeFile(string fileName){
    ofstream f(fileName);
    if(f.is_open()){
        f<<"Hola mundo!"<<endl;
        f<<"Hola mundo 2!"<<endl;
        f<<"3ra linea"<<endl;
    }else{
        cout<<"Error al abrir el archivo"<<endl;
    }
    f.close();
}
