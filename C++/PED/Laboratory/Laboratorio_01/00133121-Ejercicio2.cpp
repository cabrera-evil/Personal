/*Realizar una lista simplemente enlaza con la forma que gusten, ya sea insertando al inicio o al
final (pila o cola), la lista representará una colección de libros donde deberá guardarse el id y
nombre de cada libro, para este ejercicio se deberán insertar libros e imprimirlos de forma
recursiva.*/

#include <iostream>

using namespace std;

struct node{
    int ID;
    string name = "";
    node *next;
};

class book_data{
    private:
        node *pStarter;
    public:
        book_data(void);
        void filldata(void);
        void filldata_recursive(string name, int ID);
        void jumper(void);
        void showdata(node *jumper);
};

int main(void){
    book_data data;

    cout << "\n\tCOLECCION DE LIBROS" << endl;
    data.filldata();
    cout << "\nDATOS ALMACENADOS" << endl;
    data.jumper();
    return 0;
}

book_data::book_data(void){
    pStarter = NULL;
}

void book_data::filldata(void){
    node data;
    
    cout << "-----------------------------------------------";
    cout << "\nDATOS DEL LIBRO" << endl;
    cout << "Nombre: "; getline(cin, data.name);
    cout << "ID: "; cin >> data.ID; cin.ignore();
    filldata_recursive(data.name, data.ID);
}

void book_data::filldata_recursive(string name, int ID){
    node data;
    
    node *new_node = new node;
    new_node = new node;
    new_node -> name = name;
    new_node -> ID = ID;
    new_node-> next = pStarter;
    pStarter = new_node;

    cout << "-----------------------------------------------";
    cout << "\nDATOS DEL LIBRO" << endl;
    cout << "Nombre: ";
    if(getline(cin, data.name)){
        cout << "ID: "; cin >> data.ID; cin.ignore();
        filldata_recursive(data.name, data.ID);
    }
}

void book_data::jumper(void){
    cout << "-----------------------------------------------";
    cout << "\nNombre: " << pStarter -> name << endl;
    cout << "ID: " << pStarter -> ID << endl;
    cout << "-----------------------------------------------";
    showdata(pStarter -> next);
}

void book_data::showdata(node *jumper){
    if(jumper != NULL){
        cout << "\nNombre: " << jumper -> name << endl;
        cout << "ID: " << jumper -> ID << endl;
        cout << "-----------------------------------------------";
        jumper = jumper -> next;
        showdata(jumper);
    }
}