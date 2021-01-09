#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}
//Punto 1:
bool esRectangulo(vector<vector<bool>> const &t) {
    int filas = t.size();
    int columnas = t[0].size();
    bool columnasYFilasSinVariar = true;
    for(int i = 0; i < filas; i++) {
        if(t[i].size() != columnas) {
            columnasYFilasSinVariar = false;
        }
    }
    return columnasYFilasSinVariar;
}

bool esToroide(vector<vector<bool>> const &t) {
    bool result = false;
    int filas = t.size();
    int columnas = t[0].size();
    if(esRectangulo(t) && filas >= 3 && columnas >= 3) {
        result = true;
    }
    return result;
}

//Punto 3:
float cantidadVivas(toroide const &t) {
    float result = 0;
    float filas = t.size();
    float columnas = t[0].size();
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if(t[i][j] == true) {
                result++;
            }
        }
    }
    return result;
}

float superficieTotal(toroide const &t) {
    float result;
    float filas = t.size();
    float columnas = t[0].size();
    result = filas * columnas;
    return result;
}

//Punto 4:
int mod(int d, int q) {
    if (d % q < 0) {
        return ((d % q) + abs(q));
    } else {
        return d % q;
    }
}
int vecinosVivos(toroide const &t, int f, int c) {
    int cantidad = 0;
    int filas = t.size();
    int columnas = t[0].size();
    for (int i = f-1; i < f+2; ++i) {
        for (int j = c-1; j < c+2; ++j) {
            if((t[mod(i,filas)][mod(j, columnas)]) && (i != f || j != c)) {
                cantidad++;
            }
        }
    }
    return cantidad;
}

bool debeVivir(toroide const &t, int f, int c) {
    bool result = false;
    if( ((t[f][c]) && (2 <= vecinosVivos(t,f,c) && vecinosVivos(t,f,c) <= 3)) || ((t[f][c] == false) && vecinosVivos(t,f,c) == 3) ) {
        result = true;
    }
    return result;
}

//Punto 7:
bool estaMuerto(toroide const t) {
    bool result = (cantidadVivas(t) == 0);
    return result;
}

//Punto 8:
//Recorre las evoluciones de "t" hasta que sea igual a "u" o este muerta, o vuelva a ser "t" (osea, es periodica).
// Me devuelve las k-evoluciones
int kDeEvolucionHasta(toroide t, toroide u) {
    toroide to = t;
    int k = 1;
    while ((not estaMuerto(to)) && to != u && (k > 1 && to != t)) {
        evolucionToroide(to);
        k++;
    }
    if(evolucionMultiple(t,k) == t) {
        k = 0;
    }
    return k;
}

//Punto 9:
void esteToroideMuerto(toroide &t) {
    toroide to = t;
    int filas = to.size();
    int columnas = to[0].size();
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if(to[i][j] == true) {
                t[i][j] = false;
            }
        }
    }
}

int cuantoTardaEnMorir(toroide t) {
    int k = 0;
    toroide tMuerto = t;
    esteToroideMuerto(tMuerto);
    k = kDeEvolucionHasta(t,tMuerto);
    return k;
}

void sobreviveATodos(vector <toroide> ts, int &k) {
    int i = 0;
    while (i < ts.size()) {
        if (cuantoTardaEnMorir(ts[i]) > k ) {
            k = cuantoTardaEnMorir(ts[i]);
        }
    }
}

//Punto 10:
vector<posicion> interseccionVivas(toroide const &t, toroide const &u) {
    vector<posicion> vivos;
    vector<posicion> vivasDeT = posicionesVivas(t);
    vector<posicion> vivasDeU = posicionesVivas(u);
    for (int i = 0; i < vivasDeT.size(); ++i) {
        for (int j = 0; j < vivasDeU.size(); ++j) {
            if(vivasDeT[i] == vivasDeU[j]) {
                vivos.push_back(vivasDeT[i]);
            }
        }
    }
    return vivos;
}

//Punto 11:
toroide trasladar(toroide t, int x, int y) {
    toroide to = t;
    esteToroideMuerto(to);
    int filas = to.size();
    int columnas = to[0].size();
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            to[i][j] = t[mod((i + x), filas)][mod((j + y), columnas)];
        }
    }
    return to;
}

vector <toroide> todasLasTraslaciones(toroide t) {
    vector <toroide> ts;
    toroide to = t;
    int filas = t.size();
    int columnas = t[0].size();
    for (int x = 0; x < filas; ++x) {
        for (int y = 0; y < columnas; ++y) {
            ts.push_back(trasladar(to,x,y));
        }
    }
    return ts;
}

//Punto 12:
vector <toroide> sacoColumnasOFilasVacias(vector <toroide> ts) {
    vector <toroide> tsBis;
    int largoTS = ts.size();
    int filaT = ts[0].size();
    int columnaT = ts[0][0].size();
    for (int k = 0; k < largoTS; ++k) {
        /*????????????????????????????
        ????????????????????????????*/
    }
    return tsBis;
}