#include "ArchivoDiagrama.h"
#include <iostream>

DiagramaSala ArchivoDiagrama::leerRegistro(int posicion)
{
	DiagramaSala diagrama;
	FILE* archivo = fopen(_nombre, "rb");
	if (archivo == NULL)
	{
		std::cout << "Error al abrir el archivo" << std::endl;
	}
	else
	{
		fseek(archivo, posicion * sizeof(DiagramaSala), SEEK_SET);
		fread(&diagrama, sizeof(DiagramaSala), 1, archivo);
		fclose(archivo);
	}
	return diagrama;
}

int ArchivoDiagrama::contarRegistros()
{
	FILE* archivo = fopen(_nombre, "rb");
	if (archivo == NULL)
	{
		std::cout << "Error al abrir el archivo" << std::endl;
		return -1;
	}
	else
	{
		fseek(archivo, 0, SEEK_END);
		int tam = ftell(archivo);
		fclose(archivo);
		return tam / sizeof(DiagramaSala);
	}
}

bool ArchivoDiagrama::grabarRegistro(DiagramaSala diagrama)
{
	FILE* archivo = fopen(_nombre, "ab");
	if (archivo == NULL)
	{
		std::cout << "Error al abrir el archivo" << std::endl;
		return false;
	}
	else
	{
		int escribio = fwrite(&diagrama, sizeof(DiagramaSala), 1, archivo);
		fclose(archivo);
		return escribio;
	}
}

bool ArchivoDiagrama::grabarRegistro(DiagramaSala diagrama, int idFuncion) {
	bool pudoEscribir;
	FILE* p = fopen(_nombre, "rb+");
	if (p == nullptr) {
		return false;
	}
	fseek(p, idFuncion-1 * sizeof(DiagramaSala), SEEK_SET);
	pudoEscribir = fwrite(&diagrama, sizeof(DiagramaSala), 1, p);
	fclose(p);
	return pudoEscribir;
}
void ArchivoDiagrama::mostrarRegistro(int idFuncion)
{
	DiagramaSala diagrama;
	/*int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		diagrama = leerRegistro(i);
		if (diagrama.getidFuncion() == idFuncion) {
			diagrama.mostrarSala();
			
		}
	}*/
	diagrama = leerRegistro(idFuncion-1);
	diagrama.mostrarSala();
}

bool ArchivoDiagrama::reservarAsientoEnRegistro(int idFuncion, int fila, int columna){
	DiagramaSala diagrama;
	/*int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		diagrama = leerRegistro(i);
		if (diagrama.getidFuncion() == idFuncion) {
			if (diagrama.reservarAsiento(fila, columna)) {
			
				diagrama.setSalaDeCine(fila, columna, 1);
				grabarRegistro(diagrama, idFuncion);
				return true;
			}
			else {
				return false;
			}
				std::cout <<"id funcion inexistente"<< std::endl;
		}
	}*/

	diagrama = leerRegistro(idFuncion-1);
	if (diagrama.reservarAsiento(fila, columna)) {
		diagrama.setSalaDeCine(fila, columna, 1);
		grabarRegistro(diagrama, idFuncion);
		return true;
	}
	else {
		return false;
	}
}

bool ArchivoDiagrama::cancelarReservaEnRegistro(int idFuncion, int fila, int columna) {
	DiagramaSala diagrama;
	/*int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		diagrama = leerRegistro(i);
		if (diagrama.getidFuncion() == idFuncion) {
			if (diagrama.cancelarReserva(fila, columna)) {
				diagrama.setSalaDeCine(fila, columna, 0);
				grabarRegistro(diagrama, idFuncion);
				return true;
			}
			else {
				return false;
			}
		}
	}*/

	diagrama = leerRegistro(idFuncion-1);
	if (diagrama.cancelarReserva(fila, columna)) {
		diagrama.setSalaDeCine(fila, columna, 0);
		grabarRegistro(diagrama, idFuncion);
		return true;
	}
	else {
		return false;
	}
}

