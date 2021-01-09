// Tercer tarea para Laboratorio C++ de Algoritmos I.
// Hecho por Martin Mallol
#include <iostream>
#include <math.h>
using namespace std;
// Punto 1: Repeticion controlada por un contador
void sumaCalificaciones(int &x, int i){
    x = x + i;
}
float promedioClase(int x, int y){
    float res = 0;
    res = x/y;
    return res;
}
void cantAlumnos(int &j) {
    j = j + 1;
}

/* ES LARGO PERO FUNCIONA
int main() {
    int a = 0
    int b = 0;
    std :: cout << "Ingrese primer nota: " << std :: endl;
    std :: cin >> pri;
    sumaCalificaciones(a, pri);
    cantAlumnos(b);
    std :: cout << "Ingrese segunda nota: " << std :: endl;
    std :: cin >> seg;
    sumaCalificaciones(a, seg);
    cantAlumnos(b);
    std :: cout << "Ingrese tercer nota: " << std :: endl;
    std :: cin >> ter;
    sumaCalificaciones(a, ter);
    cantAlumnos(b);
    std :: cout << "Ingrese cuarta nota: " << std :: endl;
    std :: cin >> cua;
    sumaCalificaciones(a, cua);
    cantAlumnos(b);
    std :: cout << "Ingrese quinta nota: " << std :: endl;
    std :: cin >> qui;
    sumaCalificaciones(a, qui);
    cantAlumnos(b);
    std :: cout << "La suma total de notas es: " << a << std :: endl;
    std :: cout << "El promedio total de la clase es: " << promedioClase(a, b) << std :: endl;
    return 0;
}*/

// Punto 2
// Punto 3

/* Punto 4: Escriba un programa que reciba un entero de tipo binario, 
conteniendo solo 0s y 1s, para imprimir luego el equivalente decimal.*/
main() {
    int binario = 0;
    int enDecimal = 0;
    int digito = 0;
    int exponente = 0;
    cout << "Ingrese su numero de tipo binario" << endl;
    cin >> binario;
    while(binario > 0) {
        digito = binario % 2;
        if (digito == 1) {
            enDecimal += pow(2, exponente);
        } else {}
        exponente ++;
        binario /= 10;
    }
    cout << "El numero en base decimal es:" << enDecimal << endl;
    return 0;
}

/* Punto 5: Use una f que reciba el radio de un circulo (como valor float),
calcule e imprima el diametro, la circunferencia y el area.*/

main() {
    float circunferencia = 0;
    float pi = 3.14159;
    float diametro = 0;
    float area = 0;
    float radio = 0;
    cout << "Ingrese radio" << endl;
    cin >> radio;
    diametro = 2 * radio;
    circunferencia = radio * pi;
    area = circunferencia * radio;
    cout << "El diametro es:" << diametro << endl;
    cout << "La circunferencia es:" << circunferencia << endl;
    cout << "El area es:" << area << endl;
    return 0;
}
/* Punto 6: Escribir un programa con las siguientes funciones:
- triplicarPorValor, que pasa una copia de cuenta por valor, triplica la copia
y devuelve el nuevo valor,
- triplicarPorReferencia, que pasa cuenta por referencia a traves de un 
parametro por referencia y triplica el valor original de cuenta a traves de su 
alias (es decir, el parametro por referencia)*/
void triplicarPorValor(int x) {
    x = 3 * x;
}

void triplicarPorReferencia(int &x) {
    x = 3 * x;
}

main() {
    int y = 8;
    triplicarPorValor(y);
    cout << y << endl;
    return 0;
}

main() {
    int y = 8;
    triplicarPorReferencia(y);
    cout << y << endl;
    return 0;
}

/* Punto 7: Implementar la f swap tal que:
proc swap (inout a:Z, inout b:Z) {}
Pre { a = a0 ^ b = b0 }
Post { a = b0 ^ b = a0 }
}
*/
void swap(int &a, int &b) {
    int ao = a;
    int bo = b;
    a = bo;
    b = ao;
}

main() {
    int x = 0;
    int y = 0;
    cout << "Ingrese su x" << endl;
    cin >> x;
    cout << "Ingrese su y" << endl;
    cin >> y;
    swap(x, y);
    cout << "X swapeada:" << x << endl;
    cout << "Y swapeada:" << y << endl;
    return 0;
}


// Punto 8
//SE CUELGA NO SE POR QUE
void collatz(int n, int& cantPasos) {
    int no = n;
    vector<int> serie;
    while (no > 1) {
        if(no % 2 == 0) {
            serie.push_back(no);
            no /= 2;
        } else {
            serie.push_back(no);
            no = 3*n + 1;
        }
        cantPasos ++;
    }
    mostrarVector(serie);
}

main() {
    int n = 0;
    int pasos = 0;
    vector<int> serie;
    cout << "Ingrese su numero" << endl;
    cin >> n;
    collatz(n, pasos);
    cout << "Cantidad de pasos totales:" << pasos << endl;
    return 0;
}


/* Punto 9
Implementar la f siguiente:
proc division (in dividendo Z, in divisor Z, out cociente:Z, out resto:Z) {
    Pre {dividendo >= 0 ^ divisor > 0}
    Post {dividendo = divisor * cociente + resto ^ 0 <= resto < divisor}
}
*/
int cocienteDiv(int dividendo, int divisor) {
    int c = 1;
    int k = 0;
    while((c * divisor) <= dividendo) {
        c++;
        k++;
    }
    return k;
}

void division(int dividendo, int divisor, int& cociente, int& resto) {
    if (dividendo >= 0 && divisor > 0) {
        resto = dividendo % divisor;
        cociente = cocienteDiv(dividendo, divisor);
    } else {}
}

main() {
    int dividendo = 0;
    int divisor = 0;
    int cociente = 0;
    int resto = 0;
    cout << "Ingrese dividendo" << endl;
    cin >> dividendo;
    cout << "Ingrese divisor" << endl;
    cin >> divisor;
    division(dividendo, divisor, cociente, resto);
    cout << "El cociente es:" << cociente << endl;
    cout << "El resto es:" << resto << endl;
    return 0;
}