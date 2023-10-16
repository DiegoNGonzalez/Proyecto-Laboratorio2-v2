#include "Vendedor.h"
#include <iostream>
Vendedor::Vendedor() : Persona() {

}

Vendedor::Vendedor(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Persona(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}


void Vendedor::venderEntradas(int contadorEntradas, int idFuncion, int contadorGeneralEntradas) {
	//FILE* f;
	//f = fopen("funcion.dat", "rb");
	//if (f == NULL) {
	//	std::cout << "ERROR AL QUERER ABRIR EL ARCHIVO DE LAS FUNCIONES" << std::endl;
	//}
	//else {
	//	// Mueve la posición del puntero en el archivo al registro correcto
	//	fseek(f, (idFuncion - 1) * sizeof(Funcion), SEEK_SET);

	//	// Lee la información de la función desde el archivo
	//	if (fread(&vecFunciones[idFuncion - 1], sizeof(Funcion), 1, f) == 1) {
	//		std::cout << "Cantidad de entradas vendidas: " << contadorEntradas << std::endl;
	//		std::cout << "El total a abonar es: $" << vecFunciones[idFuncion - 1].getPrecioEntrada() * contadorEntradas << std::endl;
	//		std::cout << "¡Entrada vendida con éxito!\n";
	//	}
	//	else {
	//		std::cout << "No se pudo leer la información de la función desde el archivo." << std::endl;
	//	}

	//	contadorGeneralEntradas += contadorEntradas;
	//	std::cout << "Cantidad de entradas vendidas en total: " << contadorGeneralEntradas << std::endl;
	//	fclose(f);
	//}
	std::cout << "Cantidad de entradas vendidas: " << contadorEntradas << std::endl;
}