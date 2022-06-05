/*Desarrollar el ejercicio #8 de la guía de hoja de cálculo electrónica, 
el cual consiste en realizar la suma de los valores de una col determinada. */
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node{
    int nRow, nCol;
    node *nextCol, *nextRow;
    int dato;
};

class spreadsheet{
    private:
        int totRow; // Total de rows de la hoja electrónica.
        int totCol; // Total de cols de la hoja electrónica.
        node *pHE; // Puntero base de la hoja electrónica.

    public:
        spreadsheet(int, int);
        void insnode(void);
        void deletenode(int, int);
        void print(void);
        void sum(int sumCol);
};

spreadsheet::spreadsheet(int totRow, int totCol)
{
    node *aux, *s;
    int i;
    pHE = new node;
    this->totRow = totRow;
    this->totCol = totCol;
    pHE->nRow = 0;
    pHE->nCol = 0;
    pHE->nextCol = pHE;
    pHE->nextRow = pHE;
    pHE->dato = 0;
    s = pHE;

    for(i = 1; i <= totCol; i++){
        aux = new node;
        s->nextCol = aux;
        aux->dato = 0;
        aux->nCol = i;
        aux->nRow = 0;
        aux->nextRow = aux;
        s = s->nextCol;
    };
    aux->nextCol = pHE;
    s = pHE;

    for(i = 1; i <= totRow; i++){
        aux = new node;
        s->nextRow = aux;
        aux->dato = 0;
        aux->nRow = i;
        aux->nCol = 0;
        aux->nextCol = aux;
        s = s->nextRow;
    }
    aux->nextRow = pHE;
}

int main(void){
    node *s;
    int option = 0, totRow, totCol, fil, col, i, sumCol;
    cout << "-----------------------------------------------" << endl;
    cout << "\tDATOS INICIALES DE HOJA ELECTRONICA" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Total de filas: "; cin >> totRow;
    cout << "Total de columnas: "; cin >> totCol;
    spreadsheet spreadsheet(totRow, totCol);
        do{
        cout << "-----------------------------------------------" << endl;
        cout << "\tMENU"<< endl;
        cout << "\n1 - Insertar nodo" << endl; 
        cout << "2 - Imprimir hoja electronica" << endl; 
        cout << "3 - Eliminar nodo" << endl;
        cout << "4 - Sumar columnas" << endl;        
        cout << "5 - Salir" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Elija una opcion: "; cin >> option; cin.ignore();
        cout << "-----------------------------------------------" << endl;

        switch (option){
            case 1:
                spreadsheet.insnode();
                break;
            case 2:
                spreadsheet.print();
                break;
            case 3:
                cout << "Digite el número de fila y el número de columna" << endl;
                cout << "del nodo que deseas eliminar:" << endl;
                cout << "Fila: "; cin >> fil;
                cout << "Columna: "; cin >> col;
                spreadsheet.deletenode(fil, col);
                break;
            case 4:
                cout << "Digita la columna que quieres sumar: "; cin >> sumCol;
                spreadsheet.sum(sumCol);
                break;
            case 5:
                cout << "SALIENDO..." << endl;
                break;
            default:
                cout << "OPCION INCORRECTA" << endl;
                break;
        }
    } while (option != 5);
    return 0;
}

void spreadsheet::insnode(void){
    int row, col;

    cout << "Inserción de nodos en la hoja electrónica." << endl;
    cout << "Introduce ceros para finalizar:" << endl;
    do{
        cout << "-----------------------------------------------" << endl;
        cout << "Fila: "; cin >> row;
        cout << "Columna: "; cin >> col;
        if(row >= 1 && row <= totRow && col >= 1 && col <= totCol){
            node *aux = new node;
            cout << "Entero a almacenar: ";
            cin >> aux->dato;
            aux->nRow = row;
            aux->nCol = col;
            node *pFil = pHE;
            node *pCol = pHE;
            int i;
            
            for(i = 1; i <= row; i++)
                pFil = pFil->nextRow;
            while((pFil->nextCol->nCol < col) && (pFil->nextCol->nCol != 0))
                pFil = pFil->nextCol;
            for(i = 1; i <= col; i++)
                pCol = pCol->nextCol;
            while((pCol->nextRow->nRow < row) && (pCol->nextRow->nRow != 0))
                pCol = pCol->nextRow;
            aux->nextCol = pFil->nextCol;
            pFil->nextCol = aux;
            aux->nextRow = pCol->nextRow;
            pCol->nextRow = aux;
            cout << "El nodo se ha insertado" << endl;
        }
        else
            cout << "Ubicación no válida para aux dato" << endl;
    }while(row  != 0 || col != 0);
}

void spreadsheet::deletenode(int fil, int col){
    node *pFil = pHE;
    node *pCol = pHE;
    node *pDelete = NULL;
    int i;

    for(i = 1; i <= fil; i++)
        pFil = pFil->nextRow;
    while((pFil->nextCol->nCol < col) && (pFil->nextCol->nCol != 0))
        pFil = pFil->nextCol;
    for(i = 1; i <= col; i++)
        pCol = pCol->nextCol;
    while((pCol->nextRow->nRow < fil) && (pCol->nextRow->nRow != 0))
        pCol = pCol->nextRow;
    pDelete = pFil->nextCol;
    pFil->nextCol = pFil->nextCol->nextCol;
    pCol->nextRow = pCol->nextRow->nextRow;
    delete pDelete;
    cout << "El nodo ha sido borrado" << endl;
}

void spreadsheet::print(void){
    cout << "Para cada nodo se muestra: fila, columna, dato." << endl;
    cout << "La hoja electrónica es:" << endl;
    node *s = pHE;
    int i;

    do{
        do{
            cout << s->nRow <<',' << s->nCol << ',' << s->dato << '\t';
            s = s->nextCol;
        }while(s->nCol != 0);
        cout << endl;
        s = s->nextRow;
    }while(s->nRow != 0);
}

void spreadsheet::sum(int sumCol){
    node *s = pHE;
    int total = 0;

    do{
        s = s->nextCol;
    }while(s->nCol != sumCol);

    do{
        total += s->dato;
        s = s->nextRow;
    }while(s->nRow != 0);
    cout << "La suma de la columna " << sumCol << " es: " << total << endl;
}