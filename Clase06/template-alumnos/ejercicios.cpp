#include "ejercicios.h"


// Ejercicio 1: Existe Pico
bool existePico(vector<int> v){
	bool res = false;
	int i = 1;
	int length = v.size();
	while(i < length-1) {
		res = res || v[i-1] < v[i] < v[i+1];
		i++;
	}
	return res;
}

bool hayMayorACero(vector<int> v) {

}

// Ejercicio 2: MCD
int mcd(int m, int n){
	int a = 0;
	int b = 0;
	return 0;
}

// Ejercicio 3: Minimo de una Subsecuencia
int indiceMinSubsec(vector<int> v, int l, int r){
	if(l > r) {
		return 0;
	} else {
		int i = r;
		int res = r;
		while (i >= l ) {
			if ( (v[i] <= v[i+1]) && (i+1 <= r) ) {
				res = i;
			}
			i--;
		}
		return res;
	}
}
void quitarMinimo(vector<int>& v) {
	vector<int> w;
	int length = v.size();
	int minimo = indiceMinSubsec(v, 0, length-1)
	for(int i = 0; i < length; i++) {
		if (i != minimo) {
			w.push_back(v[i]);
		}
	}
	return w;
}
// Ejercicio 4: Ordenar1
void ordenar1(vector<int>& v){
	int i = 0;
	int length = v.size();
	int minimo = indiceMinSubsec(v, 0, length);
	vector<int> w;
	while (i < length) {
		w.push_back(v[minimo]);
		quitarMinimo(v);
		i++;
	}
	v = w;
	return v;
}

// Ejercicio 5: Ordenar2
void ordenar2(vector<int>& v){
	int i = 0;
	int j = 0;
	int k = 0;
	vector<int> w;
	int length = v.size();
	while(k < length) {
		if(v[minimo] == 0) {
			i++;
			j++;
		} else if(v[minimo] == 1) {
			j++;
		}
		w.push_back(v[minimo]);
		quitarMinimo(v);
		k++;
	}
	i--;
	j--;
	k--;
	w = v;
	return v;
}

// Ejercicio 6: Division
tuple<int,int> division(int n, int d){
	int r = (n % d);
	int q = n;
	int qo = 0;
	while (q > 0) {
		if(q*d + r == n) {
			qo = q
		}
	}
	return make_tuple(qo,d);
}
