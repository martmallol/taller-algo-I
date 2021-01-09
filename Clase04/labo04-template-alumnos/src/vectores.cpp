#include "vectores.h"
//EJERCICIOS DEL 1 AL 7
// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
}

//FUNCIONES PREEXISTENTES:
vector<int> crearVector(int n) {
    vector<int> res;
    for (int i=1; i<=n;i=i+1) {
        res.push_back(i);
    }
    return res;
}

void modificarVector(vector<int>& a) {
    a[0]=35;
}

void mostrarVector(vector<int> v) {
    cout << "[";
    for (int i =0; i <v.size()-1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size()-1] << "]";
}
//FIN DE LAS FUNCIONES

/* Punto 1: Dados un vector v y un entero a, decide si a divide a todos
los elementos de v.*/
bool divide(vector<int> v, int a){
	bool res = true;
	for(int i = 0; i < v.size(); i++) {
        if(v[i] % a != 0) {
			res = false;
		}
    }
	return res;
}

main() {
   	vector<int> v = crearVector(5);
   	int k = 0;
    cout << "Ingrese su entero" << endl;
    cin >> k;
    cout << divide(v, k) << endl;
    return 0;
}

/* Punto 2: Dado un vector v, devuelve el valor maximo encontrado.*/
int mayor(vector<int> v){
	int res = 0;
	for(int i = 0; i < v.size(); i++) {
        if(v[i] > res) {
			res = v[i];
		}
    }
	return res;
}

main() {
   	vector<int> v = crearVector(5);
    cout << mayor(v) << endl;
    mostrarVector(v);
    return 0;
}

/* Punto 3: Dado un vector v, devuelve el vector reverso.*/
vector<int> reverso(vector<int> v){
	vector<int> w;
	int i = (v.size() - 1);
	while (i >= 0) {
        w.push_back(v[i]);
        i--;
    }
    return w;
}

main() {
   	vector<int> v = crearVector(5);
   	mostrarVector(reverso(v));
    mostrarVector(v);
    return 0;
}

/* Punto 4: Dado un vector v y un entero k, rotar k posiciones los 
elementos de v.*/
vector<int> rotar(vector<int> v, int k) {
    vector<int> w;
    for (int i = k; i < v.size() + k; i++) { 
        int j = i % v.size(); 
        w.push_back(v[j]);
    }
    return w;
}

main() {
   	vector<int> v = crearVector(5);
   	int k = 0;
    cout << "Ingrese su entero" << endl;
    cin >> k;
    mostrarVector(rotar(v, k));
    return 0;
}

/* Punto 5: Dado un vector v de ints no repetidos, devuelve verdadero si 
el mismo esta ordenado (ya sea creciente o decrecientemente).*/
bool estaOrdenado(vector<int> v){
	int creciente = 0;
	int decreciente = 0;
	for(int i = 0; i < v.size()-1; i++) {
        if(v[i] <= v[i+1]) {
			creciente++;
		}
	}
	for(int i = 0; i < v.size()-1; i++) {
        if(v[i] >= v[i+1]) {
			decreciente++;
		}
	}
	if(creciente == v.size()-1 || decreciente == v.size()-1) {
		return true;
	}
}

main() {
   	vector<int> v = crearVector(5);
   	//modificarVector(v);
   	//vector<int> v = crearVector(2);
   	// v[0] = 3;
   	int k = 0;
   	bool res;
    res = estaOrdenado(v);
    cout << "Esta ordenado? " << res << endl;
    mostrarVector(v);
    return 0;
}

/* Punto 6: Dado un int devuelve un vector con los factores primos del mismo.*/
bool esPrimo(int n){
     int contadorDivisores = 0;
     int i = n - 1;
     while(i > 1) {
         if (n % i == 0) {
             contadorDivisores = contadorDivisores + 1;
         }
         i = i - 1;
     }
     if (contadorDivisores == 0) {
         return true;
     } else {
         return false;
     }
}

vector<int> factoresPrimos(int n){
	vector<int> v = {1};
	int i = 2;
	while (i < n) {
        if(esPrimo(i) && (n % i == 0)) {
			v.push_back(i);
		}
        i++;
    }
	return v;
}

main() {
   	int k = 0;
    cout << "Ingrese su entero" << endl;
    cin >> k;
    mostrarVector(factoresPrimos(k));
    return 0;
}

/* Punto 7: Dado un vector de enteros v muestra por pantalla su contenido. 
Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar por pantalla [1, 2, 5, 65].*/
void mostrarVector(vector<int> v) {
    cout << "[";
    for (int i =0; i <v.size()-1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size()-1] << "]";
}











