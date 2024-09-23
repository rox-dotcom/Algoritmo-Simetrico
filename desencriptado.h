#ifndef DESENCRIPTADO_H
#define DESENCRIPTADO_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Función para desencriptar texto con un desplazamiento y una lista de índices de permutación
string desencriptar(const string &texto, const string &llave,int desplazamiento, const vector<int> &indices);

#endif