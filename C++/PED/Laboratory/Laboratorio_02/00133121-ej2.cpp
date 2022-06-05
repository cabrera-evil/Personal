/*Realizar una lista que permita almacenar los datos de los clientes frecuentes de un
negocio de comida rápida. Debe considerar que cada cliente tiene: nombre, apellido,
Documento Único de Identidad (DUI), ID de tarjeta de cliente frecuente, y sellos en
tarjeta (se recomienda tratar la tarjeta de cliente frecuente como una estructura
anidada). El programa deberá;
a. Buscar un cliente por su DUI
b. Mostrar en pantalla cantidad de sellos
c. Calcular cuántos productos puede canjear con su cantidad de sellos (10
sellos equivale a un producto gratis), si aún tiene puntos sobrantes deberá
eliminarse el excedente de su cuenta. Ejemplo:
Nombre; Ivette
DUI 060815136
Total de sellos; 32
Productos gratis: 3
Nuevo total de sellos: 2*/

#include <iostream>

using namespace std;

struct frecuent_card{
    int ID;
    int stamps;
};

struct node{
    int DUI;
    struct frecuent_card customer_card;
    string first_name = "";
    string last_name = "";
    node *next;
};

class frecuent_clients{
    private:
        node *pStarter;
    public:
        frecuent_clients(void);
        void filldata(void);
        void filldata(string, string, int, int, int);
        void find_client(void);
        void find_client(node *p, int find);
        void show_client_data(node *p);
        void stamps_products(node *p);
};

//Menu
int main(void){
    int option;
    frecuent_clients clients;

    do{
        cout << "-----------------------------------------------" << endl;
        cout << "\n\tMENU"<< endl;
        cout << "\n1 - Ingresar datos de cliente" << endl;
        cout << "2 - Buscar un cliente por su DUI" << endl;
        cout << "3 - Salir" << endl << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Elija una opcion: ";
        cin >> option;
        cout << "-----------------------------------------------" << endl;

        switch (option){
            case 1: 
                cin.ignore();
                cout << "\n\tINGRESAR DATOS DE CLIENTE" << endl;
                clients.filldata(); 
                break;
            case 2:
                cin.ignore();
                cout << "\n\tBUSCAR CLIENTE POR DUI" << endl;
                clients.find_client();
                break;
            case 3:
                cin.ignore();
                cout << "\nSaliendo..." << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
    } while (option != 3);
    return 0;
}

frecuent_clients::frecuent_clients(void){
    pStarter = NULL;
}

//Ingreso de Datos
void frecuent_clients::filldata(void){
    node data;
    
    cout << "\nNombre: "; getline(cin, data.first_name);
    cout << "Apellido: "; getline(cin, data.last_name);
    cout << "DUI: "; cin >> data.DUI;
    cout << "ID de Tarjeta de cliente frecuente: "; cin >> data.customer_card.ID;
    cout << "Total de sellos: "; cin >> data.customer_card.stamps; cin.ignore();
    filldata(data.first_name, data.last_name, data.DUI, data.customer_card.ID, data.customer_card.stamps);
}

//Ingreso de datos en el nodo
void frecuent_clients::filldata(string first_name, string last_name, int DUI, int ID, int stamps){
    node *aux = new node;
    aux = new node;
    aux -> first_name = first_name;
    aux -> last_name = last_name;
    aux -> DUI = DUI;
    aux -> customer_card.ID = ID;
    aux -> customer_card.stamps = stamps;
    aux -> next = pStarter;
    pStarter = aux;
}

//Buscar a cliente sin parametros
void frecuent_clients::find_client(void){
    node *p = pStarter;
    int find;

    cout << "\nDUI a buscar: ";cin >> find; cin.ignore();
    cout << "-----------------------------------------------" << endl;
    if (!p)
        cout << "El DUI ingresado no existe" <<endl;
	else{
        if(p -> DUI == find)
            show_client_data(p);
        else
            find_client(p -> next, find);
	}
}

//Buscar cliente con parametros recursivos
void frecuent_clients::find_client(node *p, int find){
    if (!p)
        cout << "El DUI ingresado no existe" <<endl;
	else{
        if (p -> DUI == find)
            show_client_data(p);
        else
            find_client(p -> next, find);
	}
}

//Impresion de datos
void frecuent_clients::show_client_data(node *p){
    cout << "\n\tDATOS DE CLIENTE ENCONTRADOS" << endl;
    cout << "\nNombre: " << p -> first_name << endl;
    cout << "Apellido: " << p -> last_name << endl;
    cout << "DUI: " << p -> DUI << endl;
    cout << "ID de Tarjeta de cliente frecuente: " << p -> customer_card.ID << endl;
    cout << "Total de sellos: " << p -> customer_card.stamps << endl;
    stamps_products(p);
}

//Mostrar cuantos productos puede canjear
void frecuent_clients::stamps_products(node *p){
    int products = 0, stamps = 0;

    products = p -> customer_card.stamps / 10;
    stamps = p -> customer_card.stamps % 10;
    cout << "Productos gratis: " << products << endl;
    cout << "Nuevo total de sellos: " << stamps << endl;
}