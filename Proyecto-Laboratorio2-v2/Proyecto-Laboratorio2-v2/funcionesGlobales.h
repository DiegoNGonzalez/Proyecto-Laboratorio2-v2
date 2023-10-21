#pragma once
#include <iostream>

namespace funcionesGlobales{
	int validarInt(std::string textoCout, std::string textoError);
	int validarMinimo(int minimo, std::string textoCout, std::string textoError, std::string textoMinimo);
	int validarRango(int minimo, int maximo, std::string textoCout, std::string textoError, std::string textoMinimo, std::string textoMaximo);
}
