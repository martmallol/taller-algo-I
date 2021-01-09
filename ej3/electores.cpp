#include "electores.h"

int validarVotante(int a, int m, int d) {
	//LISTA DE ERRORES
    if(a % 4 && m == 2 && d > 29 ) { //Bisiesto
	    return ERROR;
	} else if(((m % 2 == 1 && m <= 7) || (m % 2 == 0 && m >= 12)) && d > 31) { //Mayor a 31
	    return ERROR;
	} else if((((m % 2 == 0 && m <= 7) || (m % 2 == 1 && m >= 12)) && d > 30)) { //Mayor a 30
	    return ERROR;
	} else if (m < 1 || m > 12 || d < 1 || a > 2020) { //Errores de fecha
	    return ERROR;
	}

    //LISTA DE NO_VOTAS
    if(a > 2004 || (a == 2004 && ((d>22 && m == 10) || m > 10)) ) { //Menor de la edad requerida
        return NO_VOTA;
    }

    //LISTA DE OPCIONAL_MENOR
    if(a <= 2004 && ( (a > 2002) || (m > 10 && a >= 2002) || (d > 22 && m == 10 && a == 2002) ) ) {
        return OPCIONAL_MENOR;
    } //Menor de edad (chequear)

    //LISTA DE OPCIONAL_MAYOR
    if(a > 1950 || (a == 1950 || (m < 10) || (d <= 22 && m == 10)) ) { //Mayores de edad
        return OPCIONAL_MAYOR;
    }

    //AL FIN VOTA
    return OBLIGATORIO;

}
