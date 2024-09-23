#include "desencriptado.h"
#include "confusion.h"
#include "difusion.h"
#include "encriptado.h"

//Función para desmezclar con la llave
//Función dezmezclar con la llave
string desencriptar(const string &texto, const string &llave, int desplazamiento, const vector<int> &indices) {
    // Deshacer la permutación (difusión)
    string textoDespermutado = deshacerPermutacion(texto, indices);
    
    // Deshacer la sustitución (confusión)
    string textoDesconfuso = sustitucion(textoDespermutado, 26 - desplazamiento);
    
    // Desmezclar el texto con la llave usando XOR
    string textoDesmezclado = mezclardesmezclarConLlave(textoDesconfuso, llave);
    
    return textoDesmezclado;
}