#include "ejercicios.h"
#include "time.h"
#include <ctime>
#include "stdlib.h"
#include <string>
#include<iostream>

using namespace std;

int busquedaBinaria(vector<int> v, int x){
	return -1;
}

int busquedaJumpSearch(vector<int> v, int x){
	return -1;
}

int buscar(vector<int> v, int x){
    return busquedaBinaria(v, x);
    //return busquedaJumpSearch(v, x);
}


double ejemplo_como_calcular_tiempos() {
    clock_t begin = clock();

    for(int i=0 ; i < 100000; i++){
        // nada
    }

    clock_t end = clock();
    double elapsed_msecs = double(end - begin) / CLOCKS_PER_SEC  * 1000; // mide el tiempo en milisegundos
    return elapsed_msecs;
}

vector<int> construir_vector(int size, string mode){
    vector<int> res {};
    time_t t;
    srand((unsigned) time(&t));
    int base = rand() % 100;
    int step;
    for(int i = 0; i < size; i++){
        step = rand() % 100;
        if(mode == "asc") {
            res.push_back(base+step);
            base += step;
        }
        if(mode == "desc"){
            res.push_back(base-step);
            base -= step;
        }
        if(mode == "azar"){
            res.push_back(step);
        }
        if(mode == "iguales"){
            res.push_back(base);
        }
    }
    return res;
}



int indicePico(vector<int> v){
	return -1;
}

//HACKERRANK
/*Dado un arreglo ordenado ascendentemente y sin repetidos, encontrar una posicion i tal que v[i] = i. Si hay
mas de una posicion, devolver la menor. Devolver -1 en caso de que tal indice no exista.*/

int puntoFijo(vector<int> v){
	int res = -1;
	bool yaEsta = false;
    for (int i = 0; i < v.size() && not yaEsta; ++i) {
        yaEsta = (i == v[i]);
        if(yaEsta) {
            res = i;
        }
    }
    return res;
}




///////////////////
int encontrarRotado(vector<int> v, int x){
	return -1;
}

//HACKERRANK
/*Dado un arreglo ordenado en orden creciente y sin repetidos, encontrar el indice del menor elemento
que sea mayor al pasado por parametro. Devolver -1 si tal elemento no existe.*/

/*Utilizo una busqueda binaria para encontrar un i tal que s[i] == x. Luego elijo al siguiente indice.*/
int menorMasGrande(vector<int> v, int x){
    int res = -1;
    if (v.size()==0 || (v.size()==1 && v[0] < x)) { //Aca contemplo casos borde
        return res;
    } else if (x > v[v.size()-1]) {
        return res;
    } else if (x<v[0] || x == v[0]) {
        return 0;
    } else if (x = v[v.size()-1]) {
        return v.size()-1;
    } else { //Aca empieza la busqueda del elemento por toda la secuencia
        int low = 0;
        int high = v.size() - 1;
        while( low+1 < high ) {
            int mid = (low+high) / 2;
            if( v[mid] <= x ) {
                low = mid;
            } else {
                high = mid;
            }
        }
        /*if (v[low] < x) { //Si tengo un indice tq v[i] == x , elijo al siguiente
            while(v[low] < x) {
                low++;
            }
            res = low;
        } else if(low > x) {
            while(v[low] > x) {
                low--;
            }
            res = low+1;
        }*/
        if(v[low] < x) {
            res = high;
        } else {
            res = low;
        }
    }
    return res;
}

vector<int> masCercanoK(vector<int> v, int k,  int x){
	return {};
}
