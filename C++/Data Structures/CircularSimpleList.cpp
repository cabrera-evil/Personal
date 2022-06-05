//Insert and print circular list's data

#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class list{
    private:
        node *pStart;
        node *pEnd;
    public:
        list(void);
        void in(int);
        void out(void);
        void del(void);
};

list::list(void){
    pStart = NULL;
    pEnd = NULL;
}

int main(void){
    int option = 0, data = 0;
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
                    list.out();
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
		pStart->next = pStart;
		pEnd = pStart;
	}else{
		pEnd->next = aux;
		aux->next = pStart;
		pEnd = aux;
	}
}

//DATA PRINT
void list::out(void){
    node *jumper = NULL;
    jumper = pStart;
    cout << "-----------------------------------------------" << endl;
    cout << "\tIMPRESION DE DATOS" << endl;
        if(pStart){
            do{
                cout << jumper->data << endl;
                jumper = jumper->next;
            }while(jumper!=pStart);
        }
        else
            return;
}

//DATA DELETE
void list::del(void){
	node* current = new node();
	current = pStart;
	node* previous = new node();
	previous = NULL;
	bool found = false;
	int find = 0;
	cout << "\nDato a eliminar: "; cin >> find;
	if(pStart){
		do{
			if(current->data == find){
				if(current == pStart){
					pStart = pStart->next;
					pEnd->next = pStart;
				}
                else if(current == pEnd){
					previous->next = pStart;
					pEnd = previous;
				}
                else
					previous->next = current->next;
				cout << "\nDato Eliminado" << endl;
				found = true;
			}
			previous = current;
			current = current->next;
		}while(current!=pStart && found != true);
		if(!found)
			cout << "\nDato no encontrado" << endl;
	}
    else
		cout << "\nLa lista se encuentra vacia" << endl;
}