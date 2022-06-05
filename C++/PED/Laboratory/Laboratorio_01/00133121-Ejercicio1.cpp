/*Realizar la multiplicación de dos enteros en forma de suma recursiva. 
Por ejemplo:
4 × 3 = 4 + 4 + 4*/
#include <iostream>

using namespace std;

int sum(int a, int b);

int main(void){
    float a = 0, b = 0;

    cout << "\n\tMULTIPLICACION RECURSIVA DE ENTEROS" << endl;
    cout << "Primer termino: "; cin >> a;
    cout << "Segundo termino: "; cin >> b;
    cout << "-----------------------------------------------" << endl;
    cout << "El resultado es: " << sum(a,b);
    return 0;
}

int sum(int a, int b){
    if (b == 1)
        return a;
    else if (b > 0)
        return a + sum(a, b - 1);
    else 
        return -a + sum(a, b + 1);
}