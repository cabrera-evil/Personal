/*EJERCICIO:
Realizar un programa en C++ para una lista circular circular simplemente enlazada que en sus
nodes guarde la información de un estudiante: ID, Nombre y Carrera. Su programa deberá
ser capaz de:
1) Agregar un estudiante (en cola, es decir, al final de la lista circular).
2) Imprimir todos los estudiantes (en dicha función debe notarse con una impresión que
el nextuiente del final es el primero, esto para demostrar que es una lista circular circular
simplemente enlazada).
3) Eliminar un estudiante dado su ID.

Ejemplo:
ID: 1 Nombre: Oscar Carrera: Informática
ID: 2 Nombre: Ivette Carrera: Informática
ID: 3 Nombre: Pedro Carrera: Civil
ID: 4 Nombre: Juan Carrera: Industrial

Al imprimir la lista circular:
ID: 1 Nombre: Oscar Carrera: Informática
ID: 2 Nombre: Ivette Carrera: Informática
ID: 3 Nombre: Pedro Carrera: Civil
ID: 4 Nombre: Juan Carrera: Industrial
El nextuiente de Juan es Oscar

Al eliminar el estudiante con el ID 3:
ID: 1 Nombre: Oscar Carrera: Informática
ID: 2 Nombre: Ivette Carrera: Informática
ID: 4 Nombre: Juan Carrera: Industrial
El nextuiente de Juan es Oscar

Al eliminar el estudiante con el ID 1:
ID: 2 Nombre: Ivette Carrera: Informática
ID: 4 Nombre: Juan Carrera: Industrial
El nextuiente de Juan es Ivette*/

#include <iostream>

using namespace std;

struct node{
    string name;
    int id;
    string career;
    node *next;
};

class circular_list{
    private:
        node *pQueue;
        node *pFirst;
    public:
        circular_list();
        void Insert(void);
        void Insert(string, int, string);
        void Print(void);
        void Delete(void);
        void Delete(int);
};

circular_list::circular_list(void){
    pQueue = NULL;
}

//MENU
int main(void){
    int option;
    circular_list list;
        do{
        cout << "-----------------------------------------------" << endl;
        cout << "\tMENU"<< endl;
        cout << "\n1 - Ingresar datos de estudiante" << endl;
        cout << "2 - Mostrar datos de estudiantes" << endl;
        cout << "3 - Eliminar datos datos de estudiante" << endl;
        cout << "4 - Salir" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Elija una opcion: "; cin >> option; cin.ignore();
        cout << "-----------------------------------------------" << endl;

        switch (option){
            case 1:
                list.Insert();
                break;
            case 2:
                list.Print();
                break;
            case 3:
                list.Delete();
                break;
            case 4:
                cout << "SALIENDO..." << endl;
                break;
            default:
                cout << "OPCION INCORRECTA" << endl;
                break;
        }
    } while (option != 4);
    return 0;
}

//INGRESO DE DATOS
void circular_list::Insert(void){
    string name, career;
    int id = 0;
    cout << "\tDATOS DE ESTUDIANTE" << endl;
    cout << "Nombre: "; getline(cin, name);
    cout << "Id: "; cin >> id; cin.ignore();
    cout << "Carrera: "; getline(cin, career);
    Insert(name, id, career);
}

void circular_list::Insert(string name, int id, string career){
    node *aux, *jumper;
    aux = new node;
    aux -> name = name;
    aux -> id = id;
    aux -> career = career;
    if(!pQueue){
        pQueue = aux;
        pQueue->next = pQueue;
    }
    else{
        aux->next = pQueue;
        jumper = pQueue;
        while(jumper->next != pQueue)
            jumper = jumper->next;
        jumper->next = aux;
    }
}

//IMPRESION DE DATOS
void circular_list::Print(void){
    node *p = pQueue;
    if(pQueue){
        cout << "\tIMPRIMIENDO DATOS" << endl;
        do{
            cout << "-----------------------------------------------" << endl;
            cout << "Nombre: " << p -> name << endl;
            cout << "Id: " << p -> id << endl;
            cout << "Carrera: " << p -> career << endl;
            p = p -> next;
        }while(p != pQueue);
        if(p == pQueue){
            cout << "-----------------------------------------------" << endl;
            cout << "Nombre: " << p -> name << endl;
            cout << "Id: " << p -> id << endl;
            cout << "Carrera: " << p -> career << endl;
        }
    }
    else
        cout << "NO HAY DATOS QUE IMPRIMIR" << endl;
}

//ELIMINAR DATOS DE ESTUDIANTE
void circular_list::Delete(void){
    int id = 0;
    cout << "Ingrese el id del estudiante a eliminar: "; cin >> id;
    Delete(id);
}

void circular_list::Delete(int id){
    node *aux = pQueue, *aux2 = pQueue;
    cout << "-----------------------------------------------" << endl;
    if(pQueue)
        do{
            pQueue= pQueue->next;
        } while(pQueue && pQueue != aux2 && pQueue->next->id != id);
            if(pQueue && pQueue->next->id == id){
                aux = pQueue->next->next;
                if(pQueue->next == aux2) 
                    aux2 = aux;
                delete(pQueue->next);
                pQueue->next = aux;
                while(pQueue != aux2) 
                    pQueue = pQueue->next;
                cout << "DATOS DE ESTUDIANTE ELIMINADOS CON EXITO" << endl;
            }
    else
        cout << "NO SE HA ENCONTRADO EL DATO QUE DESEAS ELIMINAR" << endl;
}