#include "generador.h"
#include "vectores.h"
#include<iostream>
#include<fstream>
//EJERCICIOS DEL 8 AL 15
using namespace std;

/* Punto 8: Dado un archivo que contiene una secuencia ints (ej: 1 2 34 4 45),
leerlo y devolver un vector con los numeros en el mismo orden.*/
vector<int> leerVector(string archivo) {
    ifstream fin;
    int n;
    vector<int> v;
    fin.open(archivo);
    while(!fin.eof()){
        fin >> n;
        v.push_back(n); 
    }
    fin.close();
}

/* Punto 9: Dado un vector de ints, grabar sus elementos en un archivo cuyo nombre viene 
como parametro de entrada. 
Ej: Si el vector es <1, 2, 5, 65> el archivo contiene [1, 2, 5, 65].*/
void guardarVector(vector<int> v, string nombreArchivo) {
    ofstream fout;
    fout.open(nombreArchivo);
    for(int i=0; i < v.size(); i++) {
        fout << v[i] << ',';
    }
    fout << endl;
    fout.close();
}

/* Punto 10: Dado un vector de ints encontrar el primer elemento de izq a der tal que los 
elementos a su izq suman mas que los que estan a su der. 
Ej: <1, 2, 3, 4> el resultado es 3 porque (1+2) < 3 + 4 y (1 + 2 + 3) > 4. 
El vector de entrada debe ser: leerVector("elementoMedio.in")*/
int elementoMedio(vector<int> v) {
    ifstream fin;
    int sumatoriaV = sumatoriaVector(v);
    int sumatoriaW = 0;
    fin.open("elementoMedio.in");
    for(int i = 0; i =< v.size(); i++) {
        if(sumatoriaW > (sumatoriaV - sumatoriaW)) {
            fin >> v[i-1];
        } else {
            sumatoriaW = sumatoriaW + v[i];
        }
    }
    fin.close();
}

int sumatoriaVector(vector<int> v) {
    int i = 0;
    int sumatoria = 0;
	while (i < v.size()) {
        sumatoria = sumatoria + v[i];
        i++;
    }
    return sumatoria;
}

/* ???????????????????????????
Punto 11: Dado un archivo que contiene una lista de nros, contar la cantidad de apariciones
de cada uno y crear en un archivo en el directorio archivos/out con el mismo nombre del archivo
de entrada, de manera de tener una linea por cada nro encontrado, un espacio y su cantidad de 
apariciones.
Ej: Si el vector es <1, 2, 2, 1, 1, 4> el archivo de salida tiene que ser:
linea 1: 1 3
linea 2: 2 2
linea 3: 4 1
Utilizar los archivos 10000NumerosEntre1y50.in y cantidadApariciones.in. */
void cantApariciones(string nombreArchivo) {
    ofstream fout;
    fout.open(nombreArchivo);
    for(int i=0; i < v.size(); i++) {
        fout << v[i] << ',';
    }
    fout << endl;
    fout.close();
}

/* Punto12: Ingresar por consola una palabra a buscar y el nombre de un archivo de texto y 
devolver la cant de apariciones de la palabra en el archivo. Mostrar el resultado por 
pantalla. Para testear el ejercicio pueden usar el archivo cantidadAparicionesDePalabra.in. */
int cantidadAparicionesDePalabra(string nombreArchivo, string palabra) {
    ifstream fin;
    string palabraArchivo;
    int cantApariciones = 0;
    fin.open(nombreArchivo);
    while(!fin.eof()){
        fin >> a;
        if(palabraArchivo == palabra) {
            cantApariciones++;
        } 
    }
    fin.close();
}

/* Punto 13: Dados dos archivos en los que cada uno contiene una secuencia de enteros de la
misma longitud, guardar el promedio de cada par de nros que se encuentran en la misma posicion
en el archivo de salida. 
Ej: Si tenemos dos secuencias <1, 2, 3, 4> y <1, 25, 3, 12> el result debe ser [1, 13.5, 3, 8]. 
En archivos/ estan promedio1.in y promedio2.in. Cada archivo contiene 100 nros random entre 1 y 10. */
void promedio(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut) {
    vector<int> v = leerVector(nombreArchivoIn1);
    vector<int> w = leerVector(nombreArchivoIn2);
    vector<bool> u;
    for(int i = 0; i < v.size(); i++) {
        u.push_back( (v[i] + w[i]) / 2 );
    }
    ofstream fout;
    fout.open(nombreArchivoOut); // crea el archivo
    fout << u << endl;
    fout.close(); // guarda y cierra el archivo
}

/* Punto 14: Dados dos archivos en los que cada uno contiene una secuencia de ints ordenada, 
ordenarlos y guardar el resultado en el archivo de salida. 
Ej: Si tenemos dos secuencias <1, 4, 8, 19> y <3, 25, 31> el resultado debe ser [1, 3, 4, 8, 25, 31].
En archivos/ estan ordenarSecuencia1.in y ordenarSecuencia2.in. Cada archivo contiene 5000 nros
ordenados entre 1 y 1000. El primer archivo contiene los nros pares en el rango y el 
segundo los impares. */
void ordenarSecuencias(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut) {
    vector<int> v = leerVector(nombreArchivoIn1);
    vector<int> w = leerVector(nombreArchivoIn2);
    vector<int> u;
    for(int i = 0; i < v.size()-1; i++) {
        if(v[i] <= w[i] && w[i] <= v[i+1]) {
            u.push_back(v[i]);
            u.push_back(w[i]);
        } else if(v[i] <= w[i] && w[i] > v[i+1]) {
            u.push_back(v[i]);
            u.push_back(v[i+1]);
        } else if(v[i] > w[i] && w[i+1] > v[i]) {
            u.push_back(w[i]);
            u.push_back(v[i]);
        } else {
            u.push_back(w[i]);
            u.push_back(w[i+1]); //chequear esta funcion, se repite mucho el codigo
        }
    }
    ofstream fout;
    fout.open(nombreArchivoOut); // crea el archivo
    fout << u << endl;
    fout.close(); // guarda y cierra el archivo
}

/* Punto 15: Funcion que pide al usuario que se ingrese por teclado dos nombres de archivos que 
contengan solo ints, luego calcule la interseccion (los elementos comunes a ambos archivos), que 
debe mostrar por pantalla, ademas de devolverla como vector.*/
vector<int> interseccion() {
    cout << "Ingrese un archivo: ";
    cin >> nombreArchivoIn1; 
    cout << "Ingrese otro archivo: "; 
    cin >> nombreArchivoIn2; 
    vector<int> v = leerVector(nombreArchivoIn1);
    vector<int> w = leerVector(nombreArchivoIn2);
    vector<int> u;
    for(int i = 0; i < v.size(); i++) {
        for(int j = v.size(); j >= 0; j--) {
            if(v[i] == w[j] && !perteneceA(u,v[i])) {
                u.push_back(v[i]);
            }
        }
    }
    // ME FALTA SACARLE LOS REPETIDOS AL VECTOR (declarar la funcion perteneceA)
    cout << "La intersección de los dos archivos es: " << u; // Salida
    return 0;
}



int main() {
    // funcion para generar automaticamente los archivos numericos
    // generarDatosLaboratorio(); // descomentar para crear automaticamente los archivos necesarios en la parte de entrada-salida. Una vez creados, se puede volver a comentar
    holaModuloVectores(); // función definida en vectores.cpp
    return 0;
}
