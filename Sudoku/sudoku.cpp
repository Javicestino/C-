#include <string>
#include <iostream>
using namespace std;
#include <array>

// Rango de la matriz
const int M = 9;
const int N = 9;

const int N_FILAS_CAJA = 3;
const int N_COLS_CAJA = 3;

//DEfinimos el tipo fila de sudoku
typedef array <int,N> Tfila;
//Definimos el tipo tablero de sudoku
typedef array <Tfila,M> TSudoku;

//Array con la frecuencia de cada uno de los dígitos [1..9]
const int digitos = 9; 
typedef array <int, digitos> TFrecuencias;

// PRoc. para leer un tablero de Sudoku por teclado
void leeSudoku (TSudoku& sudoku) {
    cout << "Introduzca sudoku por filas (números separados por espacios)" << endl;
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            cin >> sudoku[i][j];
        }
    }
}

void escribeSudoku (const TSudoku& sudoku) {
     for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            cout << sudoku[i][j] << " ";
        }
        cout <<endl;
    }
}

// Inicializamos a 0 el array con las frec. de los dígitos [1,9]
void inicializaFrecuencias (TFrecuencias& frecuencias) {
    for (int i=0;i<frecuencias.size();i++) {
        frecuencias[i]=0;
    }
}

// Muestra el array de frecuencias
void muestraFrecuencias (TFrecuencias& frecuencias) {
    for (int i=0;i<frecuencias.size();i++) {
        cout << frecuencias[i];
    }
}

// True si la frecuencia de cada uno de los 9 digitos es 1
bool compruebaFrecuencias (const TFrecuencias& frecuencias)  {
    bool frecuenciasCorrectas =true;
    int i=0;
    while (i<frecuencias.size() && frecuenciasCorrectas) {
        if (frecuencias[i]!=1)
            frecuenciasCorrectas = false;
        i++;
    }
    return frecuenciasCorrectas;
}

//Devuelve un valor lógico indicando si la col. de sudoku es correcta (aparece una sola vez cada digito 1..9)
bool columnaCorrecta (const TSudoku& sudoku, int col) {
    bool correcta = true;
    //Para contabilizar la frecuencia de cada dígito en la column
    TFrecuencias frecuencias;
    inicializaFrecuencias(frecuencias);
    //REcorremos las filas para esa columna y contabilizamos el nº de veces que aparece cada dígito
    for (int i=0;i<M;i++) {
        int digito = sudoku[i][col];
        frecuencias[digito-1]++;
    }
    return compruebaFrecuencias(frecuencias);
}

//Devuelve un valor lógico indicando si la Fila de sudoku es correcta (aparece una sola vez cada digito 1..9)
bool filaCorrecta (const TSudoku& sudoku, int fil) {
    bool correcta = true;
    //Para contabilizar la frecuencia de cada dígito en la column
    TFrecuencias frecuencias;
    inicializaFrecuencias(frecuencias);
    //REcorremos las filas para esa columna y contabilizamos el nº de veces que aparece cada dígito
    for (int j=0;j<N;j++) {
        int digito = sudoku[fil][j];
        frecuencias[digito-1]++;
    }
    return compruebaFrecuencias(frecuencias);
}

//Devuelve un valor lógico indicando si la caja de sudoku es correcta (aparece una sola vez cada digito 1..9)
//Fil, col: fila y columna en la que inicia la caja de sudoku
bool cajaCorrecta (const TSudoku& sudoku, int fil, int col) {
    bool correcta = true;
    //Para contabilizar la frecuencia de cada dígito en la column
    TFrecuencias frecuencias;
    inicializaFrecuencias(frecuencias);
    //REcorremos las filas para esa columna y contabilizamos el nº de veces que aparece cada dígito
    for (int i=fil;i<fil+N_FILAS_CAJA;i++) {
        for (int j=col;j<col+N_COLS_CAJA;j++) {
            int digito = sudoku[i][j];
            frecuencias[digito-1]++;
        }
    }
    return compruebaFrecuencias(frecuencias);
}

bool compruebaFilas (const TSudoku& sudoku) {
    bool filasCorrectas = true;
    int i=0;
    while (i<M && filasCorrectas) {
        if (!filaCorrecta(sudoku,i)) {
            filasCorrectas = false;
        }
        i++;
    }
    return filasCorrectas;
}

// Recorremos  las columnas del sudoku para ver si tienen el relleno correcto correctas
bool compruebaColumnas (const TSudoku& sudoku) {
    bool columnasCorrectas = true;
    int j=0;
    while (j<N && columnasCorrectas) {
        if (!columnaCorrecta(sudoku,j)) {
            columnasCorrectas = false;
        }
        j++;
    }
    return columnasCorrectas;
}

// Recorremos  las columnas del sudoku para ver si tienen el relleno correcto correctas
bool compruebaCajas (const TSudoku& sudoku) {
    bool cajasCorrectas = true;
    int i=0;
    
    //Recorremos el tablero buscando cajas
     while (i<M && cajasCorrectas) {
        int j=0;
        while (j<N && cajasCorrectas ) {
            if (i%3==0 && j%3==0) { //es caja, comprobamos
                if (!cajaCorrecta(sudoku,i,j))
                    cajasCorrectas = false;
            }
            j++;
        }
        i++;
    }
    return cajasCorrectas;
}

//  El Sudoku será correcto si lo es el relleno de sus filas, columnas, y cajas
bool compruebaSudoku (const TSudoku& sudoku) {
    return (compruebaFilas(sudoku) && compruebaColumnas(sudoku) && compruebaCajas(sudoku)  );
}

//NO TOCAR

int main () {
    TSudoku sudoku;
    leeSudoku(sudoku);
    escribeSudoku(sudoku);
    if (compruebaSudoku(sudoku) )
        cout << "Relleno de Sudoku correcto" <<endl;
    else    
        cout << "Relleno de Sudoku incorrecto" <<endl;
    return 0;
}