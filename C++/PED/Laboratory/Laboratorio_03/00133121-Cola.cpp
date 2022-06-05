/*Realizar dos .cpp, en el primero deberá codificar las funciones vistas en el
laboratorio 3 para una pila (push y pop), en un segundo archivo deberá codificar las
funciones para una cola (enqueue y dequeue)*/

#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class queue{
    private:
        node *pQueue;
    public:
        queue();
        void queue_in(void);
        void queue_in(int);
        void queue_out(void);
        void queue_out(node *);
        void dequeue(void);
};

queue::queue(void){
    pQueue = NULL;
}

//MENU
int main(void){
    int option;
    queue queue;

    do{
        cout << "-----------------------------------------------" << endl;
        cout << "\tMENU"<< endl;
        cout << "\n1 - Ingresar datos de cola" << endl;
        cout << "2 - Mostrar datos de cola" << endl;
        cout << "3 - Eliminar un dato de cola" << endl;
        cout << "4 - Salir" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Elija una opcion: "; cin >> option;
        cout << "-----------------------------------------------" << endl;

        switch (option){
            case 1: 
                queue.queue_in();
                break;
            case 2:
                queue.queue_out();
                break;
            case 3:
                queue.dequeue();
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
void queue::queue_in(void){
    int data;

    cout << "\tINGRESO DE DATOS" << endl;
    cout << "Digita el valor a almacenar en pila: "; cin >> data;
    queue_in(data);
}

//INGRESO DE DATOS DENTRO DE COLA
void queue::queue_in(int data){
    node *aux;

    aux = new node;
    aux -> data = data;
    aux -> next = pQueue;
    pQueue = aux;
}

//IMPRESION DE DATOS SIN PARAMETROS
void queue::queue_out(void){
    cout << "\tDATOS ALMACENADOS" << endl;
    queue_out(pQueue);
}

//IMPRESION DE DATOS RECURSIVA
void queue::queue_out(node *jumper){
    if(jumper){
        queue_out(jumper -> next);
        cout << jumper -> data << endl;
    }
}

//ELIMINAR ELEMENTO DE COLA
void queue::dequeue(void){
    node *aux = NULL;
    
    if(pQueue){
        aux = pQueue;
        pQueue = pQueue -> next;
    }
}