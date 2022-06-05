/*Realizar un programa en C++ para un árbol binario de búsqueda que en sus nodos
almacene la información de un estudiante: ID, nombre y apellido (deberá tomar como
criterio de ordenamiento el ID del estudiante). Su programa debe ser capaz de:
1) Agregar estudiante
2) Imprimir preOrder
3) imprimir inOrder
4) Imprimir postOrder*/
#include <iostream>
using namespace std;

struct data{
    int id = 0;
    string name = "";
    string lastname = "";
};

struct node{
    data data;
    node *left = NULL;
    node *right = NULL;
};

class ABB{
    private:
        node *pABB;
    public:
        ABB();
        void menu();
        node *create(data data);
        void insert(data data);
        void insert(node **tree, data data);
        void preOrder();
        void preOrder(node *);
        void inOrder();
        void inOrder(node *);
        void postOrder();
        void postOrder(node *);
};

ABB::ABB(){
    pABB = NULL;
};

//CREACION DE NODOS
node *ABB::create(data data){
    node *aux = new node;
    aux->data.id = data.id;
    aux->data.name = data.name;
    aux->data.lastname = data.lastname;
    aux->right = NULL;
    aux->left = NULL;

    return aux;
}

//INSERTAR NODOS EN ARBOL
void ABB::insert (data data){
    node **tree = &pABB; 
    insert(&pABB, data);
}
void ABB::insert(node **tree, data data){
    if(!(*tree)){//si el arbol esta vacio
        *tree = new node();
        (*tree)->data = data;
        (*tree)->left = (*tree)->right = NULL;
    }
    else{//si el arbol ya contiene nodos
        if((*tree)->data.id > data.id)//si es menor, insertar a la izquierda
            insert(&(*tree)->left, data);
        else//si es mayor, insertar a la derecha
            insert(&(*tree)->right, data);
    }
}

//IMPRESION EN PREORDEN
//ROOT LEFT RIGHT
void ABB::preOrder(void){
    node *tree = pABB;
    preOrder(tree);
}
void ABB::preOrder(node *tree){
    if(!tree)
        return;
    else{
        cout << "Id: " << tree->data.id;
        cout << "\nNombre: " << tree->data.name;
        cout << "\nApellido: " << tree->data.lastname;
        cout << "\n---------------------------------------" << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

//IMPRESION INORDER
//LEFT ROOT RIGHT
void ABB::inOrder(){
    node *tree = pABB;
    inOrder(tree);
}
void ABB::inOrder(node *tree){
    if(!tree)
        return;
    else{
        inOrder(tree->left);
        cout << "Id: " << tree->data.id;
        cout << "\nNombre: " << tree->data.name;
        cout << "\nApellido: " << tree->data.lastname;
        cout << "\n---------------------------------------" << endl;
        inOrder(tree->right);
    }
}

//IMPRESION POSTORDER
//LEFT RIGHT ROOT
void ABB::postOrder(void){
    node *tree = pABB;
    postOrder(tree);
}
void ABB::postOrder(node *tree){
    if(!tree)
        return;
    else{
        postOrder(tree->left);
        postOrder(tree->right);
        cout << "Id: " << tree->data.id;
        cout << "\nNombre: " << tree->data.name;
        cout << "\nApellido: " << tree->data.lastname;
        cout << "\n---------------------------------------" << endl;
    }
}

void ABB::menu(void){
    node **tree = &pABB;
    data data;
    int id = 0, option = 0;
    string name = "", lastname = "";
    bool cont = true;

    do{
        cout << "---------------------------------------" << endl;
        cout << "\tMENU:" << endl;
        cout << "\t1) Agregar" << endl;
        cout << "\t2) Imprimir preOrder" << endl;
        cout << "\t3) Imprimir inOrder" << endl;
        cout << "\t4) Imprimir postOrder" << endl;
        cout << "\t5) Salir" << endl;
        cout << "---------------------------------------" << endl;
        cout << "\tTu opcion: ";
        cin >> option;
        switch(option){
            case 1:
                cout << "---------------------------------------" << endl;
                cout << "Id: ";cin >> data.id; cin.ignore();
                cout << "Nombre: "; getline(cin, data.name);
                cout << "Apellido: "; getline(cin, data.lastname);
                insert(&pABB, data);
                break;
            case 2: 
                cout << "---------------------------------------" << endl;
                cout << "\tPreOrder: ";
                cout << "\n---------------------------------------" << endl;
                preOrder();
                break;
            case 3: 
                cout << "---------------------------------------" << endl;
                cout << "\tInOrder: ";
                cout << "\n---------------------------------------" << endl;
                inOrder();
                break;
            case 4:
                cout << "---------------------------------------" << endl;
                cout << "\tPostOrder: "; 
                cout << "\n---------------------------------------";
                postOrder();
                break;
            case 5:
                cout << "---------------------------------------" << endl;
                cout << "\tSaliendo";
                cout << "\n---------------------------------------" << endl;
                cont = false;
                break;
            default: 
                cout << "Opcion invalida!" << endl;
                break;
        }
    }while(cont);
}

int main(){
    ABB objTree;
    objTree.menu();
    return 0;
}