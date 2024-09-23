#include <iostream>
#include <fstream>
#include <string>
#include "confusion.h"
#include "difusion.h"
#include "encriptado.h"

using namespace std;

// Función para leer archivo.txt (lo que vamos a cifar)
string leerArchivoTxt(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return "ERROR";
    }
    string linea, texto;
    while (getline(archivo, linea))
    { // Leer línea x línea
        cout << linea << endl;
        texto = texto + linea + "\n";
    }
    archivo.close();
    return texto;
}

// Función que revisa que la llave sea igual o menor a 256 bits
void verificarLlave()
{
    string llave;
    cout << "Ingresa la llave (hasta 32 caracteres / 256 bits): ";
    getline(cin, llave);

    if (llave.size() == 16 || llave.size() == 24 || llave.size() == 32)
    { // Revisr que son 128, 192 o 256 bits (puse ese lim porque en la presentación menciona esos bits y en esta pag igual https://www.redeszone.net/tutoriales/seguridad/criptografia-algoritmos-clave-simetrica-asimetrica/)
        cout << "La llave es válida." << endl;
    }
    else
    {
        cerr << "La llave no es válida. Debe tener 16, 24 o 32 caracteres." << endl;
    }
}

int main()
{
    string rutaArchivo = "test1.txt"; // aquí va el nombre del txt (test1 o test2 si quieren poner otros cambien aqui o creen otros .txt)
    string data = leerArchivoTxt(rutaArchivo);

    verificarLlave();

    int desp = 3;
    string textoCon = sustitucion(leerArchivoTxt(rutaArchivo), desp);
    cout<<endl << "Sustitucion: " << textoCon << endl;

    vector<int> indices = generarIndices(data.length()); // Generar índices basados en la longitud del texto

    // Permutar el texto
    string textoPermutado = permutar(data, indices);
    cout << "Texto permutado: "<<endl << textoPermutado << endl;

    // Deshacer la permutación
    string textoDeshecho = deshacerPermutacion(textoPermutado, indices);
    cout << "Texto original: " << textoDeshecho << endl;

    // Encriptar el texto
    string textoEncriptado = encriptar(data, desp, indices);
    cout << "Texto encriptado: "<<endl << textoEncriptado << endl;

    // Desencriptar el texto

    return 0;
}
