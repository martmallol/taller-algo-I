#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include "definiciones.h"
///////////////////
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

///////////////////
bool auxEsTriangularSuperior(vector<vector<int> > m) {
    bool loEs = true;
    for (int i = 0; i < m.size() && loEs; ++i) {
        for (int j = i+1; loEs && j < m.size(); ++j) {
            loEs = (m[i][j] == 0);
        }
    }
    return loEs;
}

bool auxEsTriangularInferior(vector<vector<int> > m) {
    bool loEs = true;
    for (int i = 0; i < m.size() && loEs; ++i) {
        for (int j = i-1; loEs && j > -1; --j) {
            loEs = (m[i][j] == 0);
        }
    }
    return loEs;
}

bool esTriangular(vector<vector<int> > m){
	return auxEsTriangularInferior(m) || auxEsTriangularSuperior(m);
}

///////////////////
string armoSubSeqDesdeAtras(string s1, string s2) {
    string seq; //aca guardo los indices de los elementos de s1 en s2
    for (int i = s1.size()-1; i > -1; ++i) {
        if(i == s1.size()-1) {
            bool loEncontre1 = false;
            for (int j = s2.size()-1; not loEncontre1 || j > -1; --j) {
                loEncontre1 = s1[i] == s2[j];
                if(loEncontre1) {
                    seq.push_back(j);
                }
            }
        }
        bool loEncontre2 = false;
        for (int j = seq[seq.size()-1]; j > -1 || not loEncontre2 ; --j) {
            loEncontre2 = s1[i] == s2[j];
            if(loEncontre2) {
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
        res = s1[i] == s2[i];
    }
    return res;
}

bool subsecuencia(string s1, string s2) {
	string indices = armoSubSeqDesdeAtras(s1,s2);
	//bool iguales = todosIguales(s1,seq);
    bool iguales = indices.size() == s1.size();
	return iguales;
}

///////////////////
string rotar(string s, int j){
    string res = s;
    for (int i = j; i < s.size() + j; i++) {
        int k = i % s.size();
        res[k] = s[i-j];
    }
	return res;
}