#include <algorithm>
#include "ejercicios.h"
typedef pair<int, int> posicion;
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}
//Punto 1:
/*Dados dos vectores, calcular la matriz que resulta de hacer el producto vectorial entre ambos.
Si no son vectores con tres elementos, devuelvo una matriz vacia.*/
vector<vector<int> > productoVectorial(vector<int> u, vector<int> v){
    vector<vector<int> > res;
    if(u.size() != v.size() || u.size() != 3) {
	    return res;
	}

    vector<int> w;
	int primero = u[1]*v[2] - u[2]*v[1];
	w.push_back(primero);
    int segundo = u[2]*v[0] - u[0]*v[2];
    w.push_back(segundo);
    int tercero = u[0]*v[1] - u[1]*v[0];
    w.push_back(tercero);
    res.push_back(w);
    return res;
}

//Punto 2:
/*Dada una matriz cuadrada, modificarla para obtener su traspuesta.*/
/*hackerrank*/
void trasponer(vector<vector<int> > &m) {
    vector<vector<int> > mo;
    for (int j = 0; j < m[0].size(); ++j) {
        vector<int> columna;
        for (int i = 0; i < m.size(); ++i) {
            columna.push_back(m[i][j]);
        }
        mo.push_back(columna);
    }
    m = mo;
}

//Punto 3;
/*Multiplicar matrices.*/
int auxProductoVectores(vector<int> v, vector<int> u) {
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
        res += v[i]*u[i];
    }
    return res;
}

vector<int> auxColumna(vector<vector<int>> m, int col) {
    vector<int> columna;
    for (int i = 0; i < m[0].size(); ++i) {
        columna.push_back(m[col][i]);
    }
    return columna;
}

vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2){
    vector<vector<int> > res;
    for (int i = 0; i < m1.size(); ++i) {
        vector<int> filaNueva;
        for (int j = 0; j < m2[0].size(); ++j) {
            int prod = auxProductoVectores(m1[i], auxColumna(m2,j));
            filaNueva.push_back(prod);
        }
        res.push_back(filaNueva);
    }
    return res;
}

//Punto 4:
/*Dada una matriz, devolver otra matriz reemplazando cada casillero por el promedio de la region compuesta
por sus vecinos mas el valor del centro.*/
int mod(int d, int q) {
    if (d % q < 0) {
        return ((d % q) + abs(q));
    } else {
        return d % q;
    }
}

int auxPromedioVecinos(vector<vector<int>> m, int f, int c) {
    int suma = 0;
    int filas = m.size();
    int columnas = m[0].size();
    for (int i = f-1; i < f+2; ++i) {
        for (int j = c-1; j < c+2; ++j) {
            suma += m[mod(i,filas)][mod(j, columnas)];
        }
    }
    return suma/9;
}

vector<vector<int> > promediar(vector<vector<int>> m){
	vector<vector<int> > res = m;
    if(m.size() >= 3 && m[0].size() >= 3) {
        for (int i = 0; i < m.size(); ++i) {
            for (int j = 0; j < m[0].size(); ++j) {
                res[i][j] = auxPromedioVecinos(m,i,j);
            }
        }
    }
    //AGREGAR CASOS SI LA MATRIZ TIENE MENOS DE 3 COLUMNAS Y FILAS
	return res;
}

//Punto 5:
/*Contar cuantos picos tiene una matriz, donde un pico es un elemento que es mayor que todos sus vecinos.*/
vector<int> auxQuienesSonSusVecis(vector<vector<int>> m, int f, int c) {
    vector<int> res;
    int filas = m.size();
    int columnas = m[0].size();
    for (int i = f-1; i < f+2; ++i) {
        for (int j = c-1; j < c+2; ++j) {
            if(i != f || j != c) {
                res.push_back(m[mod(i,filas)][mod(j, columnas)]);
            }
        }
    }
    return res;
}

bool auxEsMayorQueTodos(int n, vector<int> v) {
    int i = 0;
    bool loEs = true;
    while (i < v.size() && loEs) {
        loEs = n > v[i];
    }
    return loEs;
}

int contarPicos(vector<vector<int> > m){
    int cuantos = 0;
    if(m.size() >= 3 && m[0].size() >= 3) {
        for (int i = 0; i < m.size(); ++i) {
            for (int j = 0; j < m[0].size(); ++j) {
                if( auxEsMayorQueTodos(m[i][j], auxQuienesSonSusVecis(m,i,j)) ) {
                    cuantos++;
                }
            }
        }
    }
    //AGREGAR CASOS SI LA MATRIZ TIENE MENOS DE 3 COLUMNAS Y FILAS
	return cuantos;
}

//Punto 6:
/*Dada una matriz cuadrada, decidir si es triangular (inferior o superior).*/
/*hackerrank*/
bool auxEsTriangularSuperior(vector<vector<int> > m) {
    bool loEs = true;
    for (int i = 0; i < m.size() && loEs; ++i) {
        for (int j = i+1; loEs && j < m.size(); ++j) {
            loEs = (m[i][j] == 0);
        }
    }
    return loEs && (m.size() == m[0].size());
}

bool auxEsTriangularInferior(vector<vector<int> > m) {
    bool loEs = true;
    for (int i = 0; i < m.size() && loEs; ++i) {
        for (int j = i-1; loEs && j > -1; --j) {
            loEs = (m[i][j] == 0);
        }
    }
    return loEs && (m.size() == m[0].size());
}

bool esTriangular(vector<vector<int> > m){
    return auxEsTriangularInferior(m) || auxEsTriangularSuperior(m);
}

//Punto 7:
/*Decidir si, dado un tablero (no necesariamente de 8 x 8) con reinas de ajedrez, existen dos reinas
que se amenazan entre si.*/
vector<posicion> auxDondeEstanLasReinas(vector<vector<int>> m) {
    vector<posicion> reinas;
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            if (m[i][j] == 1) {
                reinas.push_back(mp(i,j));
            }
        }
    }
    return reinas;
}

bool hayAmenaza(vector<vector<int> > m){
    vector<posicion> reinas = auxDondeEstanLasReinas(m);
    bool laHay = false;
    for (int i = 0; i < reinas.size() && not laHay; ++i) {
        for (int j = 0; j < reinas.size() && not laHay; ++j) {
            if((reinas[i].first != reinas[j].first) || (reinas[i].second != reinas[j].second)) {

                if ( (reinas[i].first == reinas[j].first) || (reinas[i].second == reinas[j].second) ||
                (abs(reinas[i].first - reinas[j].first) == abs(reinas[i].second - reinas[j].second)) ) {
                    laHay = true;
                }

            }
        }
    }
    return laHay;
}

//Punto 8:
/*Dada una matriz cuadrada de n x n, devolver la diferencia absoluta entre la suma de sus dos diagonales.
Una diagonal es la que empieza en la posicion (0,0) y termina en (n-1,n-1), y la otra que va entre las
posiciones (0,n-1) y (n-1,0).*/
int diferenciaDiagonales(vector<vector<int> > m) {
    int sumaPrimerDiago = 0;
    for (int i = 0; i < m.size(); ++i) {
        sumaPrimerDiago += m[i][i];
    }
    int sumaSegundaDiago = 0;
    for (int k = 0; k < m.size() ; k++) {
        for (int j = m.size()-1; j > -1 ; j--) {
            sumaPrimerDiago += m[k][j];
        }
    }
    int diferencia = sumaPrimerDiago - sumaSegundaDiago;
    if (diferencia < 0) {
        return diferencia*(-1);
    } else {
        return diferencia;
    }
}

bool sonIguales(vector<vector<int> > m1, vector<vector<int> > m2) {
    bool loSon = true;
    for (int i = 0; i < m1.size() && loSon; ++i) {
        for (int j = 0; j < m1[0].size() && loSon; ++j) {
            loSon = (m1[i][j] == m2[i][j]);
        }
    }
    return loSon;
}