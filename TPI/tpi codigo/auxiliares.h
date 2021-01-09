//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"


using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);

//Punto 1:
bool esRectangulo(vector<vector<bool>> const &t);

bool esToroide(vector<vector<bool>> const &t);

//Punto 2:


//Punto 3:
float cantidadVivas(toroide const &t);

float superficieTotal(toroide const &t);

//Punto 4:
int mod(int d, int q);

int vecinosVivos(toroide const &t, int f, int c);

bool debeVivir(toroide const &t, int f, int c);

//Punto 7:
bool estaMuerto(toroide const t);

//Punto 8:
int kDeEvolucionHasta(toroide t, toroide u);

//Punto 9:
void esteToroideMuerto(toroide &t);
int cuantoTardaEnMorir(toroide t);
void sobreviveATodos(vector <toroide> ts, int &k);

//Punto 10:
vector<posicion> interseccionVivas(toroide const &t, toroide const &u);

//Punto 11:
toroide trasladar(toroide t, int x, int y);
vector <toroide> todasLasTraslaciones(toroide t);

//Punto 12:
vector <toroide> sacoColumnasOFilasVacias(vector <toroide> ts);

#endif //REUNIONESREMOTAS_AUXILIARES_H
