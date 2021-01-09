// Primer tarea para Laboratorio C++ de Algoritmos I.
// Hecho por Martin Mallol
#include <iostream>

// Punto 1
int f(int x){
    return x +1;
}
/*
int main () {
    std :: cout << "El resultado es: " << f (10) << std :: endl ;
    return 0;
}
*/
// El codigo me devuelve como resultado: 11

// Punto 2
int fSuma(int x, int y){
    return x + y;
}
/*
int main () {
    std :: cout << "El resultado de la nueva f es: " << fSuma (8,5) << std :: endl ;
    return 0;
}
*/
// El codigo me devuelve como resultado: 13

// Punto 3
int fSumaMayorOProducto(int x, int y){
    if(x > y) {
        return x + y;
    } else {
      return x * y;
    }
}
/*
int main () {
    std :: cout << "El resultado de la nueva f es: " << fSumaMayorOProducto (2,5) << std :: endl ;
    return 0;
}
*/

// Punto 4:
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

/*
int main () {
    std :: cout << "Es primo?: " << esPrimo(13) << std :: endl ;
    return 0;
}
*/

// Punto 5: RECURSIVO
int fibonacciRecursivo(int n) {
    if ((n == 1) || (n == 0)) {
        return n;
    } else if (n > 1) {
        return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
    } else {
        return 0;
    }
}

/*
int main () {
    std :: cout << "El resultado es: " << fibonacciRecursivo(8) << std :: endl ;
    return 0;
}
*/

// Punto 5: FOR/WHILE
int fibonacciFor(int n) {
    int res = 1;
    int nroAnterior = 0;
    int nuevoNro = 0;
    if (n == 0) {
        return 0;
    } else {
        for (int i = 1; i < n ; i++) {
        nuevoNro = nroBase + nroAnterior;
        nroAnterior = nroBase;
        nroBase = nuevoNro;
    }
        return res;
    }
}

/*
int main () {
    std :: cout << "El resultado es: " << fibonacciFor(8) << std :: endl ;
    return 0;
}
*/

// Punto 6: RECURSIVO
int sumaImparesAnteriores(int n) {
    if (n == 2) {
        return 1;
    } else if (n < 2) {
        return 0;
    } else if (n % 2 == 0) {
        return sumaImparesAnteriores(n - 2) + (n - 1);
    } else {
        return sumaImparesAnteriores(n - 1);
    }
}

/*
int main () {
    std :: cout << "El resultado es: " << sumaImparesAnteriores(10) << std :: endl ;
    return 0;
}
*/

// Punto 6: FOR/WHILE
int sumaImparesAnterioresWhile(int n) {
    int i = 1;
    int resultado = 0;
    while (i < n) {
        if (i % 2 != 0) {
            resultado = resultado + i;
        }
        i = i + 1;
    }
    return resultado;
}

/*
int main () {
    std :: cout << "El resultado es: " << sumaImparesAnterioresWhile(10) << std :: endl ;
    return 0;
}
*/

// Punto 7: RECURSIVO
int divisoresHasta(int n, int m) {
    if (m == 1) {
        return 1;
    } else if (n % m == 0) {
        return m + divisoresHasta(n, m - 1);
    } else {
        return divisoresHasta(n, m - 1);
    }
}

int sumaDivisores(int n) {
    return divisoresHasta(n, n);
}

/*
int main () {
    std :: cout << "El resultado es: " << sumaDivisores(24) << std :: endl ;
    return 0;
}
*/

// Punto 7: FOR/WHILE
int sumaDivisoresFor(int n) {
    int sumaDiv = 0;
    for(int i = 1; i <= n; i++) {
        if (n % i == 0) {
            sumaDiv = sumaDiv + i;
        }
    }
    return sumaDiv;
}

/*
int main () {
    std :: cout << "El resultado es: " << sumaDivisoresFor(24) << std :: endl ;
    return 0;
}
*/

// Punto 8: RECURSIVO
long long int combinatorio(int n, int k) {
    if ((k == 0) || (n == k)) {
        return 1;
    } else if (k > n) {
        return 0;
    } else {
        return combinatorio(n - 1, k) + combinatorio(n - 1, k - 1);
    }
}

/*
int main () {
    std :: cout << "El resultado es: " << combinatorio(8, 3) << std :: endl ;
    return 0;
}
*/

// Punto 8: FOR/WHILE
// Para esta version iterativa, utilicé un loop en la funcion auxiliar llamada "factorial".
long long int factorial(int n) {
    int resultado = 1;
    for (int i = n; i > 0; i--) {
        resultado = resultado * i;
    }
    return resultado;
}

long long int combinatorioFor(int n, int k) {
    if ((k == 0) || (n == k)) {
        return 1;
    } else if (k > n) {
        return 0;
    } else {
        return factorial(n) / (factorial(n-k) * factorial(k));
    }
}

/*
int main () {
    std :: cout << "El resultado es: " << combinatorioFor(8, 3) << std :: endl ;
    return 0;
}
*/