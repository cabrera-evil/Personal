/*Realizar dos .cpp, en el primero deberá codificar las funciones vistas en el
laboratorio 3 para una pila (push y pop), en un segundo archivo deberá codificar las
funciones para una cola (enqueue y dequeue)*/

#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class pile{
    private:
        node *pTop;
    public:
        pile();
        void push(void);
        void push(int);
        void pile_out(void);
        void pop(void);
};

pile::pile(void){
    pTop = NULL;
};

//MENU
int main(void){
    int option;
    pile pile;

    do{
        cout << "-----------------------------------------------" << endl;
        cout << "\tMENU"<< endl;
        cout << "\n1 - Ingresar datos de pila" << endl;
        cout << "2 - Mostrar datos de pila" << endl;
        cout << "3 - Eliminar un dato de pila" << endl;
        cout << "4 - Salir" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Elija una opcion: ";
        cin >> option;
        cout << "-----------------------------------------------" << endl;

        switch (option){
            case 1: 
                pile.push();
                break;
            case 2:
                pile.pile_out();
                break;
            case 3:
                pile.pop();
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
void pile::push(void){
    int data;

    cout << "\tINGRESO DE DATOS" << endl;
    cout << "Digita el valor a almacenar en pila: "; cin >> data;
    push(data);
}

//INGRESO DE DATOS DENTRO DE PILA
void pile::push(int data){
    node *aux;

    aux = new node;
    aux -> data = data;
    aux -> next = pTop;
    pTop = aux;
}

//IMPRESION DE DATOS
void pile::pile_out(void){
    node *jumper;
    jumper = pTop;
    
    cout << "\tDATOS ALMACENADOS" << endl;
    while(jumper){
        cout << jumper -> data << endl;
        jumper = jumper -> next;
    }
}

//ELIMINAR UN DATO DE PILA
void pile::pop(void){
    node *aux;

    if(pTop){
        aux = pTop;
        pTop = pTop -> next;
        cout << aux -> data << endl;
        delete aux;
    }
}