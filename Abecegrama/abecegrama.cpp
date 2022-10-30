#include <string>
#include <iostream>
using namespace std;
#include <array>

// HAY QUE IMPLEMENTARLO
const int MAX_PALABRAS = 30;

typedef array <string,MAX_PALABRAS> TPalabras;

struct TListaPalabras  {
    int numeroPalabras;
    TPalabras palabras;
};
//

void leeTexto (TListaPalabras& listaPalabras) {
    int numPalabra = 0;
    cout <<"Escriba el texto a analizar si es abecegrama:" <<endl;
    string palabra;
    cin >> palabra;
    //Metemos en el array del registro cada palabra leída por teclado
    while (palabra!="FIN" && numPalabra<listaPalabras.palabras.size()) {
        listaPalabras.palabras[numPalabra] = palabra;
        listaPalabras.numeroPalabras++; //Incrementamos el nº de palabras que forman parte del texto
        cin >> palabra;
        numPalabra++;
    }
}

void muestraTexto (const TListaPalabras& listaPalabras) {
    for (int i=0;i<listaPalabras.numeroPalabras;i++) {
        cout << listaPalabras.palabras[i] << " ";
    }
    cout <<endl;
}


void leeLetraInicio (char& letraInicio) {
    cout <<" Introduzca la letra de inicio" <<endl;
    cin >> letraInicio;
}

bool compruebaAbecegrama (const TListaPalabras& listaPalabras, char letraInicio) {
    bool isAbecegrama = true;
    //Recorremos las palabras
    char letraAChequear = letraInicio;
    int i=0;
    // Mientras no hayamos recorrido todas las palabras y sea abecegrama
    while (i<listaPalabras.numeroPalabras && isAbecegrama ) {
        string palabra = listaPalabras.palabras[i]; //Leemos la palabra
        if (palabra[0]!=letraAChequear) //si la primera letra de la palabra que leemos es diferente a la letra correspondiente, NO
            isAbecegrama = false;
        else
            letraAChequear++; //Incrementamos la letra del abecedario
        i++;
    }

    return isAbecegrama;
}

// NO TOCAR

int main () {
    //Implementar TListaPalabras
    TListaPalabras listaPalabras;
    listaPalabras.numeroPalabras = 0;
    char letraInicio;
    leeTexto(listaPalabras);
    muestraTexto(listaPalabras);
    leeLetraInicio (letraInicio);
    if (compruebaAbecegrama (listaPalabras,letraInicio)) {
        cout << "El texto es un abecegrama" <<endl;
    }
    else 
        cout << "El texto no es un abecegrama" <<endl;
    return 0;
}