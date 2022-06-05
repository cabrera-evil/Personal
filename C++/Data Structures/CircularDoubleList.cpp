//Insert and print circular list's data

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
        void out(int type);
        void del(void);
};

list::list(void){
    pStart = NULL;
    pEnd = NULL;
}

int main(void){
    int option = 0, data = 0, type = 0;
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
                cout << "data a insertar: "; cin >> data;
                list.in(data);
                break;
            case 2:
                cout << "-----------------------------------------------" << endl;
                    cout << "Seleccionar impresion\n1 - Normal\n2 - Reversa\nTu opcion: "; cin >> type;
                    if (type == 1 || type == 2)
                    list.out(type);
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
    node* aux = new node();
	aux->data = data;
	if(!pStart){
		pStart = aux;
		pEnd =aux;
		pStart->right = pStart;
		pStart->left = pEnd;
	}else{
		pEnd->right =aux;
		aux->left = pEnd;
		aux->right = pStart;
		pEnd = aux;
		pStart->left = pEnd;
	}
	cout << "\n node Ingresado\n\n";
}

//DATA PRINT
void list::out(int type){
    node *current = NULL;
    cout << "-----------------------------------------------" << endl;
    cout << "\tIMPRESION DE dataS" << endl;
    //NORMAL PRINT
    if(type == 1){
        current = pStart;
        do{
            cout << current -> data << endl;
            current = current -> right;
        }while(current != pStart);
    }
    //REVERSE PRINT
    else{
        current = pEnd;
        do{
            cout << current -> data << endl;
            current = current -> left;
        }while(current != pEnd);
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
	cout << "Dato a eliminar: "; cin >> find;
	if(pStart){
		do{
			if(current->data == find){
				if(current == pStart){
					pStart = pStart->right;
					pStart->left = pEnd;
					pEnd->right = pStart;
				}
                else if(current == pEnd){
					pEnd = previous;
					pEnd->right = pStart;
					pStart->left = pEnd;
				}
                else{
					previous->right = current->right;
					current->right->left = previous;
				}
				cout << "\nDato Eliminado" << endl;
				found = true;				
			}
			previous = current;
			current = current->right;
		}while(current != pStart && found != true);
		if(!found){
			cout << "\nDato no encontrado" << endl;
		}
	}
    else
		cout << "\n La lista se Encuentra Vacia" << endl;
}