#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//HACKERRANK
void insertionSort(vector< int > &arr){
	//Rellenar insertion

}

void selectionSort(vector< int > &arr){
	//Rellenar selection
}

vector<int> almacenValores(vector<int> &s) { //Cuanto se repite cada uno
    vector<int> almacen(150,0);
    for (int i = 0; i < s.size(); i++) {
        almacen[s[i]]++;
    }
    return almacen;
}

void reHago(vector<int> s, vector<int> almacen) {
    int indiceAlmacen = 0;
    for (int i = s.size(); i >= 0; i--) {
        while (almacen[indiceAlmacen] == 0) {
            indiceAlmacen++;
        }
        s[i] = indiceAlmacen;
        almacen[indiceAlmacen]--;
    }
}

void ordenar(vector<int> &items){
    vector<int> almacen = almacenValores(items);
    reHago(items, almacen);
}


int bestFit(int W, vector<int> &items){
	multiset<int> restos;
	for(int i=0; i<(int)items.size(); ++i){
		restos.insert(W);
	}
	int res = 0;
	for(int i=0; i<(int)items.size(); ++i){
		multiset<int>::iterator it = restos.lower_bound(items[i]);
		int restoAct = *it;
		if(restoAct==W){
			res++;
		}
		restoAct -= items[i];
		restos.erase(it);
		restos.insert(restoAct);
	}
	return res;
}

int main(){
	int N, W, aux;

	//Se levantan los items y la capacidad del contenedor
	cout << "Se levantan los items y la capacidad del contenedor";
	ifstream bpp("BPP.in");
	bpp >> N >> W;
	vector<int> items;
	for(int i=0; i<N; ++i){
		bpp >> aux;
		items.push_back(aux);
	}
	bpp.close();
	//Se corre best-fit
	int cant1 = bestFit(W, items);
	cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;

	//Se ordenan los items
	ordenar(items);
	//Se corre best-fit-decreasing
	int cant2 = bestFit(W, items);
	cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;

	return 0;
}




