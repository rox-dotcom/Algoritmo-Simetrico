#include "difusion.h"
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

vector<int> generarIndices(int longitud)
{
    vector<int> indices(longitud);
    iota(indices.begin(), indices.end(), 0); // Llenar el vector con 0, 1, 2, ..., longitud-1

    // Mezclar los índices para crear una permutación aleatoria
    random_device rd; // Semilla para el generador
    default_random_engine eng(rd());
    shuffle(indices.begin(), indices.end(), eng);

    return indices;
}

string permutar(const string &texto, const vector<int> &indices)
{
    string textoPermutado(texto.length(), ' ');

    for (int i = 0; i < texto.length(); i++)
    {
        textoPermutado[indices[i]] = texto[i];
    }

    return textoPermutado;
}

string deshacerPermutacion(const string &textoPermutado, const vector<int> &indices)
{
    string textoOriginal(textoPermutado.length(), ' ');

    vector<int> indicesInversos(textoPermutado.length());
    for (int i = 0; i < indices.size(); i++)
    {
        indicesInversos[indices[i]] = i;
    }

    for (int i = 0; i < textoPermutado.length(); i++)
    {
        textoOriginal[indicesInversos[i]] = textoPermutado[i];
    }

    return textoOriginal;
}
