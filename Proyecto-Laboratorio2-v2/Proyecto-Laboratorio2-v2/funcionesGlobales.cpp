#include "funcionesGlobales.h"
#include "rlutil.h"
#include <cstdio>
#include <stdio.h>


int funcionesGlobales::validarInt(std::string textoCout, std::string textoError) {
	int nroAvalidar;

	std::cout << textoCout;
	while (!(std::cin >> nroAvalidar)) {
		std::cout << textoError;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');// El INT_MAX es el valor de entero mas grande, ignora los caracteres hasta el salto de linea.
	}
	return nroAvalidar;
}
int funcionesGlobales::validarMinimo(int minimo, std::string textoCout, std::string textoError, std::string textoMinimo) {
	int nroAvalidar;

	nroAvalidar = validarInt(textoCout, textoError);
	while (nroAvalidar < minimo) {
		std::cout << textoMinimo << std::endl;
		nroAvalidar = validarInt(textoCout, textoError);
	} 
	return nroAvalidar;
}
int funcionesGlobales::validarRango(int minimo, int maximo, std::string textoCout, std::string textoError, std::string textoMinimo, std::string textoMaximo) {
	int nroAvalidar;

	nroAvalidar = validarInt(textoCout, textoError);
	while (nroAvalidar<minimo || nroAvalidar>maximo) {
		std::cout << textoMinimo << textoMaximo << std::endl;
		nroAvalidar = validarInt(textoCout, textoError);
	}
	return nroAvalidar;
}
// Funcion para mostrar las opciones del menu
void funcionesGlobales::showItem(const char* text, int posx, int posy, bool selected) {

	if (selected) {
		rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
		rlutil::locate(posx - 3, posy); // posiciona el cursor en la fila y columna que le pasamos por parametro (en este caso, -2 porque colocamos una flechita en la opcion seleccionada)
		std::cout << ">>" << "  " << text << "  " << "<<" << std::endl; // imprime una flechita a cada lado con el codigo ASCII, y el texto que le pasamos por parametro
	}
	else {
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
		rlutil::locate(posx - 3, posy);
		std::cout << "   " << text << "   " << "  " << std::endl; // si no esta seleccionado, imprime el texto sin las flechitas
	}
	rlutil::setBackgroundColor(rlutil::COLOR::BLACK); // cuando llega a la ultima opcion, cambia el color del cursor al color normal
}

float funcionesGlobales::validarFloat(std::string textoCout, std::string textoError)
{
	float nroAvalidar;

	std::cout << textoCout;
	while (!(std::cin >> nroAvalidar)) {
		std::cout << textoError;
		std::cin.clear();
		std::cin.ignore(FLT_MAX, '\n');// El FLT_MAX es el valor de float mas grande, ignora los caracteres hasta el salto de linea.
	}
	return nroAvalidar;
}

float funcionesGlobales::validarMinimoFloat(float minimo, std::string textoCout, std::string textoError, std::string textoMinimo)
{
	float nroAvalidar;

	nroAvalidar = validarFloat(textoCout, textoError);
	while (nroAvalidar < minimo) {
		std::cout << textoMinimo << minimo << std::endl;
		nroAvalidar = validarFloat(textoCout, textoError);
	}
	return nroAvalidar;
}

float funcionesGlobales::validarRangoFloat(float minimo, float maximo, std::string textoCout, std::string textoError, std::string textoMinimo, std::string textoMaximo)
{
	float nroAvalidar;

	nroAvalidar = validarFloat(textoCout, textoError);
	while (nroAvalidar<minimo || nroAvalidar>maximo) {
		std::cout << textoMinimo << textoMaximo << std::endl;
		nroAvalidar = validarFloat(textoCout, textoError);
	}
	return nroAvalidar;
}

void funcionesGlobales::mostrarPorcentaje(bool pudoEscribir, std::string mensaje)
{
	int porcentaje = 25;
	for (int x = 0; x < 4; x++) {

		std::cout << mensaje;
		std::cout << porcentaje * (x + 1);
		std::cout << "%";
		Sleep(1000);
		system("cls");
		rlutil::hidecursor();
	}
	if (pudoEscribir == true) {
		std::cout << "BackUp generado con exito" << std::endl;
	}
	else {
		std::cout << "No se pudo generar el BackUp" << std::endl;
	}
	system("pause");
}

void funcionesGlobales::cargarCadena(char* pal, int tam)
{
	std::string input;
	std::getline(std::cin, input); 

	if (input.length() > tam) { 
		input = input.substr(0, tam);  // recorta y asigna la cadena con la cantidad l�mite
	}

	strncpy(pal, input.c_str(), tam);  // usamos strncpy para evitar desbordamientos
	pal[tam - 1] = '\0';  // colocamos caracter nulo para asegurarse de finalizar la cadena
}

bool funcionesGlobales::confirmarAccion(std::string textoCout)
{
	char siONo;
	std::cout << textoCout;
	std::cin >> siONo;
	while (siONo != 's' && siONo != 'S' && siONo != 'n' && siONo != 'N') {
		std::cout << "OPCION NO VALIDA, REINGRESE (S/N): ";
		std::cin >> siONo;
	}
	if (siONo == 's' || siONo == 'S') {
		return true;
	}
	else {
		std::cout << "ACCION CANCELADA." << std::endl;
		return false;
	}
}

// Agregue para mostrar el mes en letras, lo uso en informes
std::string funcionesGlobales::escribirMes(int mes) {
	std::string vMeses[12] = {
		"ENERO",
		"FEBRERO",
		"MARZO",
		"ABRIL",
		"MAYO",
		"JUNIO",
		"JULIO",
		"AGOSTO",
		"SEPTIEMBRE",
		"OCTUBRE",
		"NOVIEMBRE",
		"DICIEMBRE"
	};
	return vMeses[mes - 1];
}
