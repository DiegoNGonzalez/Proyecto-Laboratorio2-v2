#pragma once
#include <iostream>
#include "FechaHorario.h"

namespace funcionesGlobales{
	int validarInt(std::string textoCout, std::string textoError);
	int validarMinimo(int minimo, std::string textoCout, std::string textoError, std::string textoMinimo);
	int validarRango(int minimo, int maximo, std::string textoCout, std::string textoError, std::string textoMinimo, std::string textoMaximo);
	void showItem(const char* text, int posx, int posy, bool selected);
	float validarFloat(std::string textoCout, std::string textoError);
	float validarMinimoFloat(float minimo, std::string textoCout, std::string textoError, std::string textoMinimo);
	float validarRangoFloat(float minimo, float maximo, std::string textoCout, std::string textoError, std::string textoMinimo, std::string textoMaximo);
	/*
@brief compararFechas recibe dos objetos Fecha y devuelve true si son la misma fecha.
@param fecha1, fecha2
@return bool, true or false segun corresponda.
*/
	bool compararFechas(Fecha fecha1, Fecha fecha2);
	void mostrarPorcentaje(bool pudoEscribir);
	void cargarCadena(char* pal, int tam);
	bool confirmarAccion(std::string textoCout);

}
