//Insert and print pile's data

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
        pile(void);
        void in(int);
        void out(void);
        void outrec(void);
        void outrec(node *);
        void del(void);
};

pile::pile(void){
    pTop = NULL;
}

int main(void){
    int option = 0, data = 0;
    bool exit = false;
    pile pile;

    do{
        cout << "-----------------------------------------------" << endl;
        cout << "\tPILE MENU"<< endl;
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
                pile.in(data);
                break;
            case 2:
                pile.out();
                break;
            case 3:
                pile.del();
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
void pile::in(int data){
    node *aux = NULL;
    aux = new node;
    aux -> data = data;
    aux -> next = pTop;
    pTop = aux;
}

//DATA PRINT
//ITERATIVE
void pile::out(void){
    node *jumper;
    jumper = pTop;
    cout << "-----------------------------------------------" << endl;
    cout << "\tIMPRESION DE DATOS" << endl;
    if(jumper){
        while(jumper){
        cout << jumper -> data << endl;
        jumper = jumper -> next;
        }
    }
    else
        return;
}
//RECURSIVE
void pile::outrec(void){
    node *jumper;
    jumper = pTop;
    cout << "-----------------------------------------------" << endl;
    cout << "\tIMPRESION DE DATOS" << endl;
    outrec(jumper);
}
void pile::outrec(node *jumper){
    if(jumper != NULL){
        outrec(jumper -> next);
        cout << "Dato: " << jumper -> data;
    }
    else
        cout << "No hay datos" << endl;
}

//DATA DELETE
void pile::del(void){
    node *jumper;
    jumper = pTop;
    if(pTop){
        pTop = pTop -> next;
        delete jumper;
    }
    else
        return;
}