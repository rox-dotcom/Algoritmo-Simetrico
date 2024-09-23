#ifndef PERMUTA_H
#define PERMUTA_H

#include <vector>
#include <string>

// Genera un vector de índices basado en la longitud del texto
std::vector<int> generarIndices(int longitud);

// Permuta el texto según un vector de índices
std::string permutar(const std::string &texto, const std::vector<int> &indices);

// Deshace la permutación
std::string deshacerPermutacion(const std::string &textoPermutado, const std::vector<int> &indices);

#endif // PERMUTA_H
