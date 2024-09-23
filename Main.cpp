#include <iostream>
#include <fstream>
#include <string>
#include "confusion.h"
#include "difusion.h"
#include "encriptado.h"
#include "desencriptado.h"

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
bool verificarLlave(const string &llave)
{
    if (llave.size() <= 16 && llave.size() > 0)
    {
        // Revisr que son 128 bits (16 caracteres) o menos
        cout << "La llave es válida." << endl;
        return true;
    }
    else
    {
        cerr << "La llave no es válida." << endl;
        return false;
    }
}

int main()
{
    string rutaArchivo = "test2.txt"; // Aquí va el nombre del txt (test1 o test2). Si desean usar otros, cambien aquí o creen otros .txt
    string data = leerArchivoTxt(rutaArchivo);
    string llave;
    int desp = 3;
    char opcion;
    string textoEncriptado = "";

    vector<int> indices = generarIndices(data.length()); // Generar índices basados en la longitud del texto

    do
    {
        cout << "\n\t 1. Sustituir Texto\n";
        cout << "\t 2. Permutar Texto\n";
        cout << "\t 3. Encriptar Texto\n";
        cout << "\t 4. Desencriptar Texto\n";
        cout << "\t 5. Salir\n";
        cout << "Escriba el numero de la opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer antes de usar getline

        switch (opcion)
        {
        case '1':
        {
            cout << "Has seleccionado: Sustituir Texto\n";
            string textoCon = sustitucion(data, desp);
            cout << "\nSustitucion:\n"
                 << textoCon << endl;
            break;
        }
        case '2':
        {
            cout << "Has seleccionado: Permutar Texto\n";
            string textoPermutado = permutar(data, indices);
            cout << "Texto permutado:\n"
                 << textoPermutado << endl;
            break;
        }
        case '3':
        {
            cout << "Has seleccionado: Encriptar Texto\n";
            textoEncriptado = "";
            cout << "Ingresa la llave (hasta 16 caracteres / 128 bits): ";
            getline(cin, llave);
            if (!verificarLlave(llave))
            {
                break;
            }
            else
            {
                cout << "La llave es válida. Encriptando...\n";
                textoEncriptado = encriptar(data, llave, desp, indices);
                cout << "\nTexto encriptado:\n"
                     << textoEncriptado << endl;
                break;
            }
        }
        case '4':
        {
            if (textoEncriptado == "")
            {
                cerr << "No puedes desencriptar un texto que no ha sido encriptado." << endl;
                break;
            }
            else
            {
                cout << "Has seleccionado: Desencriptar Texto\n";
                cout << "Ingrese la llave para desencriptar: ";
                string accesollave;
                getline(cin, accesollave);
                if (accesollave != llave)
                {
                    cerr << "La llave no es válida. No puedes desencriptar el texto." << endl;
                    break;
                }
                else
                {
                    cout << "La llave es válida. Desencriptando...\n";
                    string textoDesencriptado = desencriptar(textoEncriptado, llave, desp, indices);
                    cout << "\nTexto desencriptado:\n"
                         << textoDesencriptado << endl;
                    textoEncriptado = "";
                    break;
                }
            }
        }
        case '5':
        {
            cout << "Saliendo del programa. ¡Hasta luego!\n";
            break;
        }
        default:
        {
            cout << "Debe elegir una opcion entre 1 y 5\n";
        }
        }
    } while (opcion != '5');

    return 0;
}