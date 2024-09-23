#include "encriptado.h"
#include "confusion.h"
#include "difusion.h"

// Función para encriptar texto con un desplazamiento y una lista de índices de permutación
string encriptar(const string &texto, int desplazamiento, const vector<int> &indices){
    //Primero se sustituye el texto con un desplazamiento
    string textoCon = sustitucion(texto, desplazamiento);
    //Luego se permuta el texto sustituido
    string textoPermutado = permutar(textoCon, indices);
    
    return textoPermutado;
}