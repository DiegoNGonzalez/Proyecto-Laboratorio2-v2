#include "funcionesGlobales.h"
int funcionesGlobales::validarInt(std::string textoCout, std::string textoError) {
    int nroAvalidar;

    std::cout << textoCout << std::endl;
    while (!(std::cin >> nroAvalidar)) {
        std::cout << textoError;
        std::cin.clear();
       std:: cin.ignore();
    }
    return nroAvalidar;
}
int funcionesGlobales::validarMinimo(int minimo, std::string textoCout, std::string textoError, std::string textoMinimo) {
    int nroAvalidar;

    nroAvalidar = validarInt(textoCout,textoError);
    while (nroAvalidar < minimo) {
        std::cout << textoMinimo << minimo << std::endl;
        nroAvalidar = validarInt(textoCout,textoError);
    }
    return nroAvalidar;
}
int funcionesGlobales::validarRango(int minimo, int maximo, std::string textoCout, std::string textoError, std::string textoMinimo, std::string textoMaximo) {
    int nroAvalidar;

    nroAvalidar = validarInt(textoCout,textoError);
    while (nroAvalidar<minimo || nroAvalidar>maximo) {
        std::cout << textoMinimo << textoMaximo << std::endl;
        nroAvalidar = validarInt(textoCout,textoError);
    }
    return nroAvalidar;
}

