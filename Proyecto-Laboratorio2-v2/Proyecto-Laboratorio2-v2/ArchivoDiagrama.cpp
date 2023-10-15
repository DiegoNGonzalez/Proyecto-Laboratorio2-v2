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

bool ArchivoDiagrama::grabarRegistro(DiagramaSala diagrama, int pos) {
	bool pudoEscribir;
	FILE* p = fopen(_nombre, "rb+");
	if (p == nullptr) {
		return false;
	}
	fseek(p, pos * sizeof(DiagramaSala), SEEK_SET);
	pudoEscribir = fwrite(&diagrama, sizeof(DiagramaSala), 1, p);
	fclose(p);
	return pudoEscribir;
}
void ArchivoDiagrama::mostrarRegistro(int pos)
{
	DiagramaSala diagrama;
	/*
	int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		diagrama = leerRegistro(i);
		if (diagrama.getidFuncion() == pos) {
			diagrama.mostrarSala();
		}
	*/
	diagrama = leerRegistro(pos);
	diagrama.mostrarSala();

}

bool ArchivoDiagrama::reservarAsientoEnRegistro(int pos, int fila, int columna) {
	DiagramaSala diagrama;
	diagrama = leerRegistro(pos);
	if (diagrama.reservarAsiento(fila, columna)) {

		diagrama.setSalaDeCine(fila, columna, 1);
		grabarRegistro(diagrama, pos);
		return true;
	}
	else {
		return false;
	}
	std::cout << "id funcion inexistente" << std::endl;

	/*

	diagrama = leerRegistro(idFuncion);
	if (diagrama.reservarAsiento(fila, columna)) {
		diagrama.setSalaDeCine(fila, columna, 1);
		grabarRegistro(diagrama, idFuncion);
		return true;
	}
	else {
		return false;
	}
	*/
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

	diagrama = leerRegistro(idFuncion);
	if (diagrama.cancelarReserva(fila, columna)) {
		diagrama.setSalaDeCine(fila, columna, 0);
		grabarRegistro(diagrama, idFuncion);
		return true;
	}
	else {
		return false;
	}
}

int ArchivoDiagrama::buscarPosDiagramaxID(int valorBuscado) {
	DiagramaSala diagrama;
	int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		diagrama = leerRegistro(i);
		if (diagrama.getIdFuncion() == valorBuscado) {
			return i;
		}
	}
	std::cout << "No se encontro el id." << std::endl;
	return -1;
}

bool ArchivoDiagrama::generarBackUp() {
	FILE* archivo = fopen(_nombre, "rb");
	FILE* archivoBackUp = fopen("backUp/diagramaBKP.dat", "wb");
	bool pudoEscribir = false;
	if (archivo == NULL)
	{
		std::cout << "Error al abrir el archivo, Falla BackUp" << std::endl;
		return false;
	}

	DiagramaSala diagrama;
	while (fread(&diagrama, sizeof(DiagramaSala), 1, archivo))
	{
		fwrite(&diagrama, sizeof(DiagramaSala), 1, archivoBackUp);
	}
	fclose(archivo);
	fclose(archivoBackUp);
	pudoEscribir = true;
	int porcentaje = 25;
	for (int x = 0;x < 4;x++) {

		std::cout << "Restaurando archivo de seguridad: ";
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
	return pudoEscribir;


}

bool ArchivoDiagrama::restaurarBackUp() {
	FILE* archivoBackUp = fopen("backUp/diagramaBKP.dat", "rb");
	FILE* archivo = fopen(_nombre, "wb");
	bool pudoEscribir = false;
	if (archivoBackUp == NULL)
	{
		std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
		return false;
	}

	DiagramaSala diagrama;
	while (fread(&diagrama, sizeof(DiagramaSala), 1, archivoBackUp))
	{
		fwrite(&diagrama, sizeof(DiagramaSala), 1, archivo);
	}
	fclose(archivoBackUp);
	fclose(archivo);
	pudoEscribir = true;
	int porcentaje = 25;
	for (int x = 0;x < 4;x++) {

		std::cout << "Restaurando archivo de seguridad: ";
		std::cout << porcentaje * (x + 1);
		std::cout << "%";
		Sleep(1000);
		system("cls");
		rlutil::hidecursor();
	}
	if (pudoEscribir == true) {
		std::cout << "BackUp restaurado con exito" << std::endl;
	}
	else {
		std::cout << "No se pudo restaurar el BackUp" << std::endl;
	}
	system("pause");
	return pudoEscribir;
}
