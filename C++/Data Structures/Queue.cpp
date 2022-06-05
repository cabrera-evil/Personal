//Insert and print queue's data

#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class queue{
    private:
        node *pQueue;
        node *pTop;
    public:
        queue(void);
        void in(int);
        void out(void);
        void out(node *);
        void del(void);
};

queue::queue(void){
    pQueue = NULL;
    pTop = NULL;
}

int main(void){
    int option = 0, data;
    bool exit = false;
    queue queue;

    do{
        cout << "-----------------------------------------------" << endl;
        cout << "\tQUEUE MENU"<< endl;
        cout << "1 - Ingresar" << endl;
        cout << "2 - Imprimir" << endl;
        cout << "3 - Eliminar" << endl;
        cout << "4 - Salir" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Elija una opcion: "; cin >> option;
        switch(option){
            case 1:
                cout << "-----------------------------------------------" << endl;
                cout << "\tINGRESO DE DATOS" << endl;
                cout << "Dato a insertar: "; cin >> data;
                queue.in(data);
                break;
            case 2:
                queue.out();
                break;
            case 3:
                queue.del();
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
        }
    } while(!exit);
    return 0;
}

//DATA INSERT
void queue::in(int data){
    node *aux = NULL;
    aux = new node;
    aux -> data = data;
    if(pTop==NULL){
		pTop = aux;
		pTop->next = NULL;
		pQueue = pTop;
	}else{
		pQueue->next = aux;
		aux->next = NULL;
		pQueue = aux;
	}
}

//DATA PRINT
void queue::out(void){
    node *jumper;
    jumper = pTop;
    cout << "-----------------------------------------------" << endl;
    cout << "\tIMPRESION DE DATOS" << endl;
    if(jumper)
        out(jumper);
    else
        return;
}

void queue::out(node *jumper){
    if(jumper){
        cout << jumper -> data << endl;
        out(jumper -> next);
    }
    else
        return;
}

//DATA DELETE
void queue::del(void){
    int data = 0;
    node *jumper;
    jumper = pQueue;
    if(pQueue){
        pQueue = pQueue -> next;
        delete jumper;
    }
}