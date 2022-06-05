//Insert and print double list's data

#include <iostream>

using namespace std;

struct node{
    int data;
    node *right;
    node *left;
};

class list{
    private:
        node *pStart;
        node *pEnd;
    public:
        list(void);
        void in(int);
        void out(int);
        void del(void);
};

list::list(void){
    pStart = NULL;
    pEnd = NULL;
}

int main(void){
    int option = 0, type = 0, data = 0;
    bool exit = false;
    list list;

    do{
        cout << "-----------------------------------------------" << endl;
        cout << "\tLIST MENU"<< endl;
        cout << "1 - Ingresar" << endl;
        cout << "2 - Imprimir" << endl;
        cout << "3 - Eliminar" << endl;
        cout << "4 - Salir" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Elija una opcion: "; cin >> option;
        switch(option){
            case 1:
                cout << "-----------------------------------------------" << endl;
                cout << "\tINGRESO DE dataS" << endl;
                cout << "Dato a insertar: "; cin >> data;
                list.in(data);
                break;
            case 2:
                cout << "-----------------------------------------------" << endl;
                cout << "Seleccionar impresion\n1 - Normal\n2 - Reversa\nTu opcion: "; cin >> type;
                if (type == 1 || type == 2)
                    list.out(type);
                else
                    cout << "Opcion invalida" << endl;
                break;
            case 3:
                list.del();
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
void list::in(int data){
    node *currentAux = pStart;
    node *previousAux = NULL;
    previousAux = new node;
    previousAux -> data = data;
    previousAux -> right = NULL;
    previousAux -> left = NULL;
    if(!pStart){
        pStart = previousAux;
        pEnd = previousAux;
    }
    else{
        while(currentAux -> right)
            currentAux = currentAux -> right;
        currentAux -> right = previousAux;
        previousAux -> left = currentAux;
        pEnd = previousAux;
    }
}

//DATA PRINT
void list::out(int type){
    node *jumper = NULL;
    cout << "-----------------------------------------------" << endl;
    cout << "\tIMPRESION DE DATOS" << endl;
    //NORMAL PRINT
    if(type == 1){
        jumper = pStart;
        while(jumper){
        cout << jumper -> data << endl;
        jumper = jumper -> right;
        }
    }
    //REVERSE PRINT
    else{
        jumper = pEnd;
        while(jumper){
        cout << jumper -> data << endl;
        jumper = jumper -> left;
        }
    }
}

//DATA DELETE
void list::del(void){
    node* current = new node();
	current = pStart;
	node* previous = new node();
	previous = NULL;
	bool found = false;
	int find = 0;
	cout << "Nodo a Eliminar: "; cin >> find;
	if(pStart){
		while(current != NULL && found != true){
			if(current->data == find){
				if(current == pStart){
					pStart = pStart->right;
					pStart->left = NULL;
				}
                else if(current == pEnd){
					previous->right = NULL;
					pEnd = previous;
				}
                else{
					previous->right = current->right;
					current->right->left = previous;
				}
				cout << "\nNodo Eliminado" << endl;
				found = true;
			}
			previous = current;
			current = current->right;
		}
		if(!found)
			cout << "\nNo se ha encontrado el nodo\n\n" << endl;
	}
    else
		cout << "\n La listas se encuentra Vacia\n\n" << endl;
}