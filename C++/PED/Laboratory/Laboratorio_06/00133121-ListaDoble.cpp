/*Realizar un programa en C++ que lea números enteros desde teclado y los inserte en una
lista doblemente enlazada, su programa debe ser capaz de:
1) Insertar al inicio o al final (elegir solamente una de las dos opciones)
2) Insertar después de
3) Eliminar
4) Imprimir desde pFinal hasta pStart
Ejemplo: Si inicialmente se ingresan los números enteros:
1,2,3,10,4:
Si quiero eliminar el 10, la lista quedaría:
1,2,3,4
Por último, imprimiendola desde pFinal hasta pStart:
4,3,2,1*/

#include <iostream>

using namespace std;

struct node{
    int num;
    node *right;
    node *left;
};

class DoubleList{
    private:
        node *pStart;
        node *pEnd;
    public:
        DoubleList();
        void FirstInsert(void);
        void FirstInsert(int);
        void LastInsert(void);
        void LastInsert(int);
        void InsertAfter(void);
        void InsertAfter(int);
        void Delete(void);
        void Print(void);
        void Print(node *);
};

DoubleList::DoubleList(void){
    pStart = NULL;
    pEnd = NULL;
}

int main(void){
    int option;
    DoubleList list;
    int First_Last;
        do{
        cout << "-----------------------------------------------" << endl;
        cout << "\tMENU"<< endl;
        cout << "\n1 - Ingresar datos al inicio o al final" << endl;
        cout << "2 - Insertar despues de" << endl;
        cout << "3 - Eliminar un dato de lista" << endl;
        cout << "4 - Imprimir datos de lista" << endl;
        cout << "5 - Salir" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Elija una opcion: "; cin >> option; cin.ignore();
        cout << "-----------------------------------------------" << endl;

        switch (option){
            case 1:
                cout << "Deseas insertar al inicio o al final?: " << "\n1 - Inicio \n2 - Final" << endl;
                cout << "Tu opcion: "; cin >> First_Last;
                if(First_Last == 1)
                        list.FirstInsert();
                if(First_Last == 2)
                        list.LastInsert();
                break;
            case 2:
                list.InsertAfter();
                break;
            case 3:
                list.Delete();
                break;
            case 4:
                list.Print();
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

void DoubleList::FirstInsert(void){
    int num = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Ingresa el numero que deseas almacenar: "; cin >> num;
    FirstInsert(num);
}

void DoubleList::FirstInsert(int num){
    node *aux = new node;
    aux -> num = num;
    aux -> right = NULL;
    aux -> left = NULL;
    if(!pStart){
        pStart = aux;
        pEnd = aux;
    }
    else{
        aux -> right = pStart;
        pStart -> left = aux;
        pStart = aux;
    }
}

void DoubleList::LastInsert(void){
    int num = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Ingresa el numero que deseas almacenar: "; cin >> num;
    LastInsert(num);
}

void DoubleList::LastInsert(int num){
    node *aux = new node;
    aux -> num = num;
    aux -> right = NULL;
    aux -> left = NULL;
    if(!pStart){
        pStart = aux;
        pEnd = aux;
    }
    else{
        pEnd -> right = aux;
        aux -> left = pEnd;
        pEnd = aux;
    }
}

void DoubleList::InsertAfter(void){
    int num = 0, next = 0;
    node *aux = pStart;
    cout << "-----------------------------------------------" << endl;
    cout << "Ingresar numero despues de: "; cin >> next;
    cout << "Ingresa el numero que deseas almacenar: "; cin >> num;

    while(pStart && pStart -> num != next) 
        pStart = pStart -> right;
    if(pStart){
        if(pStart -> right){
            aux = new node;
            aux -> left = pStart;
            aux -> right = pStart->right;
            aux -> num = num;
            pStart -> right->left = aux;
            pStart -> right = aux;
            while(pStart -> left) 
                pStart = pStart -> left;
        }
        else if(!pStart -> right){
            aux = new node;
            aux -> left = pStart;
            aux -> right = NULL;
            aux -> num = num;
            pStart -> right = aux;
            pEnd = aux;
            while(pStart -> left) pStart = pStart -> left;
        }
    }
    else{
        pStart = aux;
        while(pStart -> right) 
            pStart = pStart -> right;
        aux = new node;
        aux -> left = pStart;
        aux -> right = NULL;
        aux -> num = num;
        pStart -> right = aux;
        pEnd = aux;
        while(pStart -> left) 
            pStart = pStart -> left;
    }
}

void DoubleList::Delete(void){
    int num = 0;
    bool check = false;
    node *aux = pStart;
    cout << "-----------------------------------------------" << endl;
    cout << "Ingresa el numero que deseas eliminar: "; cin >> num;

    while(pStart){
        if(pStart -> num == num){
            check = true;
            if(pStart -> left && pStart -> right){
                aux = pStart -> right;
                pStart -> left -> right = aux;
                aux -> left = pStart -> left;
                delete(pStart);
                pStart = aux;
            }
            else if(pStart -> left && !pStart -> right){
                aux = pStart -> left;
                aux -> right = NULL;
                delete(pStart);
                pStart = aux;
                pEnd = aux;
            }
            else if(!pStart -> left && pStart -> right){
                aux = pStart -> right;
                aux -> left = NULL;
                delete(pStart);
                pStart = aux;
            }
            else if(!pStart -> left && !pStart -> right){
                delete(pStart);
                pStart = NULL;
                pEnd = NULL;
                aux = NULL;
            }
        }
        else
            pStart = pStart -> right;
    }
    if(aux){
        pStart = aux;
        while(pStart -> left) pStart = pStart -> left;
    }
    if(!check)
        cout << "El valor no existe en la lista" << endl;
}
void DoubleList::Print(void){
    node *p = pEnd;
    cout << "\tIMPRIMIENDO DATOS" << endl;
    if(!p)
        cout << "No se han encontrado datos en lista" << endl;
    else
        Print(p);
}

void DoubleList::Print(node *jumper){
    if(jumper){
        cout << jumper -> num << endl;
        Print(jumper -> left);
    }
    else
        return;
}