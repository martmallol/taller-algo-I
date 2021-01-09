#include "ejercicios.h"

/* Para compilar */ 

using namespace std;

//Punto 1:
/*Separar el string segun el delimitador pasado por parametro.*/
vector<string> split(string s, char delim){
	vector<string> v;
	strin w;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != delim) {
            v.push_back(w);
            w.clear();
        } else {
            w.push_back(s[i]);
        }
    }
	return v;
}

//Punto 2:
/*Dado un string solo conformado por letras y espacios, devolver otro que
resulte de dar vuelta el orden de las palabras.*/
vector<int> dondeEstanLosEspacios(string s) {
    vector<int> v;
    for (int i = s.size(); i > -1; --i) {
        if(s[i] == ' ') {
            v.push_back(i);
        }
    }
    return v;
}

string darVueltaPalabra(string s){
	string res;
	vector<int> v = dondeEstanLosEspacios(s);
    for (int i = 0; i < v.size(); ++i) {
        int j = i+1;
        while (j < s.size() || (s[j-1] == ' ' && j != i+1)) {
            if(i == v.size()-1 && s[j] == ' ') {
                j++;
            } else {
                res.push_back(s[j]);
                j++;
            }
        }
    }
	return res;
}

//Punto 3:
// Decidir si s1 es substring o subsecuencia de s2
/*hackerrank*/
/*aca guardo en un vector donde se encuentra en orden cada elemento de s1 en s2.
 * si su largo es igual al de s1, entonces s1 es subseq de s2*/
vector <int> armoSubSeqDesdeAtras(string s1, string s2) {
    string seq; //aca guardo los indices de los elementos de s1 en s2
    for (int i = s1.size()-1; i > -1; ++i) {
        if(i == s1.size()-1) {
            bool loEncontre1 = false;
            for (int j = s2.size()-1; not loEncontre1 || j > -1; --j) {
                loEncontre = s1[i] == s2[j];
                if(loEncontre1) {
                    seq.push_back(j);
                }
            }
        }
        bool loEncontre2 = false;
        for (int j = seq[seq.size()-1]; j > -1 || not loEncontre2 ; --j) {
            loEncontre = s1[i] == s2[j];
            if(loEncontre1) {
                seq.push_back(j);
            }
        }
    }
    return seq;
}

bool todosIguales(vector<int> s1, vector<int> s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    bool res = true;
    for (int i = 0; i < s1.size() && res; ++i) {
        res = s1[i] == s2[i]
    }
    return res;
}

bool subsecuencia(string s1, string s2) {
	string indices = armoSubSeqDesdeAtras(s1,s2);
	//bool iguales = todosIguales(s1,seq);
    bool iguales = indices.size() == s1.size();
	return iguales;
}

//Punto 4:
// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<int> contadorDeLetras(string s) {
    vector<int> contador(27);
    for (int i = 0; i < s.size(); ++i) {
        int letra = s[i];
        contador[letra]++;
    }
    return contador;
}

bool laMismaPalabra(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    bool res = true;
    for (int i = 0; i < s1.size() && res; ++i) {
        res = s1[i] == s2[i]
    }
    return res;
}

bool noEstaEn(vector<vector<string> > r, string s) {
    bool noEsta = true;
    for (int i = 0; i < r.size() && noEsta; ++i) {
        for (int j = 0; j < r[i].size() && noEsta; ++j) {
            noEsta = not laMismaPalabra(r[i][j], s);
        }
    }
    return noEsta;
}

vector<vector<string> > agruparAnagramas(vector<string> v){
	vector<vector<string> > res;
    vector<string> anagramas;
    for (int i = 0; i < v.size(); ++i) {
        if(noEstaEn(res, v[i])) {
            anagramas.push_back(v[i]);
        }
        for (int j = i+1; j < v.size(); ++j) {
            if( todosIguales(contadorDeLetras(v[i]), contadorDeLetras(v[i])) ) {
                anagramas.push_back(v[j])
            }
        }
        res.push_back(anagramas);
        anagramas.clear();
    }
	return res;
}

//Punto 5:
/*Decidir si un string es palindromo, es decir, si se escribe igual en ambas direcciones.*/
string palabraInversa(string s) {
    string inversa;
    for (int i = s.size()-1; i > -1; ++i) {
        inversa.push_back(s[i]);
    }
    return inversa;
}

bool esPalindromo(string s){
	return laMismaPalabra(s, palabraInversa(s));
}

//Punto 6:
/*Decidir si un string tiene algun caracter repetido.*/
bool algunoMayorAUno(vector<int> v) {
    hayAlMenos = false;
    for (int i = 0; i < v.size(); ++i) {
        hayAlMenos = v[i] > 1;
    }
    return hayAlMenos;
}

bool tieneRepetidos(string s){
	return algunoMayorAUno(contadorDeLetras(s));
}

//Punto 7:
/*Devolver un string que este rotado j veces hacia la derecha.
Por ejemplo rotar("hola", 7) debe devolver "olah".*/
/*hackerrank*/
string rotar(string s, int j){
    string res = s;
    for (int i = j; i < s.size() + j; i++) {
        int k = i % s.size();
        res[k] = s[i-j];
    }
	return res;
}

//Punto 8:
/*Dado un string s, dar vuelta cada k caracteres el substring de longitud k. Si la cantidad de caracteres de
la entrada no es multiplo de k, el ultimo substring (de longitud menor a k) tambien debe darse vuelta.*/
// no se puede usar substring
string darVueltaK(string s, int k){
	string res(s);
	return res;
}

//Punto 10.1:
string abueloLaino(string s){
    string res;
    return res;
}

//Punto 10.2:
int cantidadDeFelicitaciones(vector<string> v){
    int res;
    return res;
}

//Punto 10.3:
int middleOut(string s, string t){

    return 0;
}
