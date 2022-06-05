/**Realizar un programa en C++ que realice lo siguiente:
1) Leer nombres de personas desde teclado e insertarlos al final en una lista
doblemente enlazada.
2) Mostrar la lista leyendo desde pInicio hasta el final.
3) Mostrar la lista leyendo desde el pFinal hasta el inicio.
4) Eliminar todos los nodos previos a una instancia de un nombre leído desde teclado
sin eliminar instancias previas del nombre.
Por ejemplo, dada la lista:
Ivette, Juan, Oscar, Pedro, José, Oscar,(Juan) posterior a la eliminación la lista contendrá
únicamente Oscar, Oscar.*/

#include <iostream>

using namespace std;

struct node{
    string name;
    node *right;
    node *left;
};

class list{
    private:
        node *pStart;
        node *pEnd;
    public:
        list();
        void list_in();
        void list_in(string);
        void list_out();
        void list_out(node *);
        void list_reverse();
        void list_reverse(node *);
        void list_delete();
        void list_delete(string);
};

list::list(void){
    pStart = NULL;
    pEnd = NULL;
}

//MENU
int main(void){
    int option;
    list list;
        do{
        cout << "-----------------------------------------------" << endl;
        cout << "\tMENU"<< endl;
        cout << "\n1 - Ingresar datos de lista" << endl;
        cout << "2 - Mostrar datos de lista" << endl;
        cout << "3 - Mostrar datos de lista en reversa" << endl;
        cout << "4 - Eliminar datos de lista" << endl;
        cout << "5 - Salir" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Elija una opcion: "; cin >> option; cin.ignore();
        cout << "-----------------------------------------------" << endl;

        switch (option){
            case 1:
                list.list_in();
                break;
            case 2:
                list.list_out();
                break;
            case 3:
                list.list_reverse();
                break;
            case 4:
                list.list_delete();
                break;
            case 5:
                cout << "SALIENDO..." << endl;
                break;
            default:
                cout << "OPCION INCORRECTA" << endl;
                break;
        }
    } while (option != 5);
    return 0;
}

//INGRESO DE DATOS
void list::list_in(void){
    string name;
    cout << "Ingresa el nombre: "; getline(cin, name);
    list_in(name);
}

void list::list_in(string name){
    node *p = pStart;
    node *aux = new node;
    aux -> name = name;
    aux -> right = NULL;
    aux -> left = NULL;
    if(!pStart){
        pStart = aux;
        pEnd = aux;
    } 
    else{
        while(p -> right != NULL)
            p = p -> right;
        p -> right = aux;
        aux -> left = p;
        pEnd = aux;
    }
}

//IMPRESION DE DATOS
void list::list_out(void){
    node *p = pStart;
    cout << "\tIMPRIMIENDO DATOS" << endl;
    if(!p)
        cout << "No se han encontrado datos en lista" << endl;
    else
        list_out(p);
}

void list::list_out(node *p){
    if(p){
        cout << "Nombre: " << p -> name << endl;
        list_out(p -> right);
    }
    else
        return;
}

//IMPRESION DE DATOS EN REVERSA
void list::list_reverse(void){
    node *p = pEnd;
    cout << "\tIMPRIMIENDO DATOS \n\tDE FORMA INVERSA" << endl;
    if (!p)
        cout << "No se han encontrado datos en lista" << endl;
    else
        list_reverse(p);
}

void list::list_reverse(node *p){
    if(p){
        cout << "Nombre: " << p -> name << endl;
        list_reverse(p -> left);
    }
    else
        return;
}

//ELIMINACION DE DATOS
void list::list_delete(void){
    string find;
    bool counter = 0;

    cout << "Ingresa el nombre desde el que deseas eliminar: "; getline(cin, find);
    list_delete(find);
}

void list::list_delete(string find){
    node *aux;
    bool counter = false;

    while(pEnd){
        if(pEnd -> name == find){
            pEnd = pEnd -> left;
            counter = true;
        }
        else if(counter && pEnd -> name != find){
            aux = pEnd -> left;
            pEnd -> right -> left = aux;
            if(aux) aux -> right = pEnd -> right;
            delete(pEnd);
            pEnd = aux;
        }
        else if(!counter){
            if(pEnd -> left) pStart = pEnd;
            pEnd = pEnd -> left;
        }
    }
    pEnd = pStart;
    while(pEnd){
        if(!pEnd -> right) aux = pEnd;
        pEnd = pEnd -> right;
    }
    pEnd = aux;
    pStart = aux;
    while(pStart){
        if(!pStart->left) aux = pStart;
        pStart = pStart->left;
    }
    pStart = aux;
}