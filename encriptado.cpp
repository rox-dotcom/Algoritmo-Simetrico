#include "encriptado.h"
#include "confusion.h"
#include "difusion.h"

//Función para mezclar la llave con el texto
string mezclardesmezclarConLlave(const string &texto, const string &llave) {
    string resultado = texto;
    for (size_t i = 0; i < texto.length(); i++) {
        resultado[i] = texto[i] ^ llave[i % llave.length()]; // XOR entre el texto y la llave
    }
    return resultado;
}

//Función para encriptar texto con un desplazamiento y una lista de índices de permutación y una llave
string encriptar(const string &texto, const string &llave, int desplazamiento, const vector<int> &indices) {
    // Mezclar el texto con la llave usando XOR
    string textoMezclado = mezclardesmezclarConLlave(texto, llave);

    // Aplicar la sustitución (confusión)
    string textoConfuso = sustitucion(textoMezclado, desplazamiento);
    
    // Aplicar la permutación (difusión)
    string textoPermutado = permutar(textoConfuso, indices);
    
    return textoPermutado;
}