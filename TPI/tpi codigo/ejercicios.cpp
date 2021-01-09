#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    bool resp = false; // este valor puede ser cambiado de acuerdo a la propia implementacion
        resp = esToroide(t);
    return resp;
}

// EJERCICIO 2
vector<posicion> posicionesVivas(toroide const &t) {
	vector<posicion> vivos;
	int filas = t.size();
	int columnas = t[0].size();
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (t[i][j]) {
                vivos.push_back(mp(i,j));
            }
        }
    }
    return vivos;
}

// EJERCICIO 3
float densidadPoblacion(toroide const &t) {
	float resp = -1;
        resp = cantidadVivas(t)/superficieTotal(t);
    return resp;
}

// EJERCICIO 4
bool evolucionDePosicion(toroide const &t, posicion x) {
	bool resp = false;
        resp = debeVivir(t,x.first,x.second);
    return resp;
}

// EJERCICIO 5
void evolucionToroide(toroide &t){
    toroide to = t;
    int filasDeT = t.size();
    int columnasDeT = t[0].size();
    for (int i = 0; i < filasDeT; ++i) {
        for (int j = 0; j < columnasDeT; ++j) {
            if(debeVivir(to, i, j)) {
                t[i][j] = true;
            } else {
                t[i][j] = false;
            }
        }
    }
}

// EJERCICIO 6
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out = t;
    // Implementacion
    for (int i = 0; i < K; ++i) {
        evolucionToroide(out);
    }
    return out;
}

// EJERCICIO 7
bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    toroide to = t;
    evolucionToroide(to);
    int po = 1;
    for(po; (not estaMuerto(to)) && to != t; po++) {
        evolucionToroide(to);
    }
    if(to == t) {
        p = po;
        resp = true;
    }
    return resp;
}

// EJERCICIO 8
bool primosLejanos(toroide const &t, toroide const &u) {
	bool resp = false;
	toroide to = t;
	toroide uo = u;
    int kDeT = kDeEvolucionHasta(to, uo);
    int kDeU = kDeEvolucionHasta(uo, to);
    resp = (evolucionMultiple(t,kDeT) == u || evolucionMultiple(u, kDeU) == t);
    return resp;
}

// EJERCICIO 9
int seleccionNatural(vector <toroide> ts) {
    int resp = 0; // este valor puede ser cambiado de acuerdo a la propia implementacion
	sobreviveATodos(ts,resp);
    return resp;
}

// EJERCICIO 10
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out = t;
    esteToroideMuerto(out);
    vector<posicion> interseccion = interseccionVivas(t,u);
    int todasLasPosiciones = interseccion.size();
    for (int i = 0; i < todasLasPosiciones; ++i) {
        out[interseccion[i].first][interseccion[i].second] = true;
    }
    return out;
}

// EJERCICIO 11
bool vistaTrasladada(toroide const &t, toroide const &u){
	bool resp = false;
    vector <toroide> traslacionesDeT = todasLasTraslaciones(t);
	int cantTraslaciones = todasLasTraslaciones(t).size();
    int i = 0;
    while (!resp && i < cantTraslaciones) {
        if(u == traslacionesDeT[i]) {
            resp = true;
        }
    }
    return resp;
}

// EJERCICIO 12
int menorSuperficieViva(toroide const &t){
	int resp = -1;
    vector <toroide> traslaciones = sacoColumnasOFilasVacias(todasLasTraslaciones(t));
    int k = 0;
    int largoTraslaciones = traslaciones.size();
    while (k < largoTraslaciones) {
        if(traslaciones[k].size() * traslaciones[k][0].size() < resp || resp == -1) {
            resp = traslaciones[k].size() * traslaciones[k][0].size();
        }
        k++;
    }
	return resp;
}


