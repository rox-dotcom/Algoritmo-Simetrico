#include <iostream>   
#include <fstream>   
#include <string>    
#include "confusion.h"

using namespace std;

//Función para leer archivo.txt (lo que vamos a cifar)
string leerArchivoTxt(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);  
    if (!archivo.is_open()) {  
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return "ERROR";
    }
    std::string linea, texto;
    while (std::getline(archivo, linea)) {  // Leer línea x línea
        std::cout << linea << std::endl; 
        texto = texto + linea + "\n";
    }
    archivo.close(); 
    return texto;
}

//Función que revisa que la llave sea igual o menor a 256 bits 
void verificarLlave() {
    std::string llave;
    std::cout << "Ingresa la llave (hasta 32 caracteres / 256 bits): ";
    std::getline(std::cin, llave);  

    if (llave.size() == 16 || llave.size() == 24 || llave.size() == 32) {  // Revisr que son 128, 192 o 256 bits (puse ese lim porque en la presentación menciona esos bits y en esta pag igual https://www.redeszone.net/tutoriales/seguridad/criptografia-algoritmos-clave-simetrica-asimetrica/)
        std::cout << "La llave es válida." << std::endl;
    } else {
        std::cerr << "La llave no es válida. Debe tener 16, 24 o 32 caracteres." << std::endl;
    }
}


int main() {
    std::string rutaArchivo = "test1.txt";  // aquí va el nombre del txt (test1 o test2 si quieren poner otros cambien aqui o creen otros .txt)
    leerArchivoTxt(rutaArchivo);  

    verificarLlave();  

    int desp = 3;
    string textoCon = sustitucion(leerArchivoTxt(rutaArchivo), desp);
    cout << "Cifrado: " << textoCon << endl;

    return 0;
}
