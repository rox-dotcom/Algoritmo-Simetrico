#ifndef ENCRIPTADO_H
#define ENCRIPTADO_H

#include <string>
#include <vector>

using namespace std;

// Función para encriptar texto con un desplazamiento y una lista de índices de permutación
string encriptar(const string &texto, const string &llave, int desplazamiento, const vector<int> &indices);
string mezclardesmezclarConLlave(const string &texto, const string &llave);

#endif // ENCRIPTADO_H