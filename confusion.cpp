#include <cctype>
#include "confusion.h"

using namespace std;

string sustitucion(string texto, int desp){
    string resTexto = "";
    for (int i = 0; i < texto.length(); i++) {
        char chTexto = texto[i];
        if (isalpha(chTexto)) {
            if (isupper(chTexto)) {
                resTexto = resTexto + char(int(chTexto + desp - 65) % 26 + 65);
            } else {
                resTexto = resTexto + char(int(chTexto + desp - 97) % 26 + 97);
            }
        } else {
            resTexto = resTexto + chTexto;
        } 
    }
    return resTexto;
}