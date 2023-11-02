#include "ArchivoDiagrama.h"
#include <iostream>
#include "funcionesGlobales.h"
#include <filesystem>

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
	diagrama = leerRegistro(pos);
	if (diagrama.getEstado()) {
		diagrama.mostrarSala();
	}
	else {
		std::cout << "LA FUNCION FUE DADA DE BAJA." << std::endl;
		system("pause");
	}

}

bool ArchivoDiagrama::reservarAsientoEnRegistro(int pos, int fila, int columna) {
	DiagramaSala diagrama;
	diagrama = leerRegistro(pos);
	if (diagrama.getEstado()) {
		if (diagrama.reservarAsiento(fila, columna)) {

			diagrama.setSalaDeCine(fila, columna, 1);
			grabarRegistro(diagrama, pos);
			return true;
		}
		else {
			return false;
		}
		std::cout << "LA FUNCION #" << diagrama.getIdFuncion() << " NO EXISTE." << std::endl;
	}
	else {
		std::cout << "LA FUNCION #" << diagrama.getIdFuncion() << " FUE DADA DE BAJA." << std::endl;
	}

}

bool ArchivoDiagrama::cancelarReservaEnRegistro(int pos, int fila, int columna) {
	DiagramaSala diagrama;
	diagrama = leerRegistro(pos);
	if (diagrama.getEstado()) {
		if (diagrama.cancelarReserva(fila, columna)) {
			diagrama.setSalaDeCine(fila, columna, 0);
			grabarRegistro(diagrama, pos);
			return true;
		}
		else {
			return false;
		}
	}
	else {
		std::cout << "LA FUNCION #" << diagrama.getIdFuncion() << " FUE DADA DE BAJA." << std::endl;
	}
}

int ArchivoDiagrama::buscarPosDiagramaxID(int valorBuscado) {
	DiagramaSala diagrama;
	int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		diagrama = leerRegistro(i);
		if (diagrama.getIdFuncion() == valorBuscado && diagrama.getEstado()) {
			return i;
		}
	}
	std::cout << std::endl << "NRO DE FUNCION INEXISTENTE." << std::endl;
	return -1;
}

bool ArchivoDiagrama::generarBackUp() {
	FILE* archivo = fopen(_nombre, "rb");
	std::string ruta = "backUp/diagramaBKP.dat";

	if (archivo == NULL) {
		std::cout << "Error al abrir el archivo. Falla BackUp" << std::endl;
		system("pause");
		return false;
	}

	if (std::filesystem::exists(ruta)) {
		std::cout << "Ya existe un BackUp de diagrama." << std::endl;
		if (funcionesGlobales::confirmarAccion("Desea sobreescribirlo? (S/N): ")) {
			FILE* archivoBackUp = fopen("backUp/diagramaBKP.dat", "wb");
			if (archivoBackUp == NULL) {
				std::cout << "Error al abrir el archivo de respaldo. Falla BackUp" << std::endl;
				fclose(archivo);
				return false;
			}

			DiagramaSala diagrama;
			while (fread(&diagrama, sizeof(DiagramaSala), 1, archivo) == 1) {
				fwrite(&diagrama, sizeof(DiagramaSala), 1, archivoBackUp);
			}

			fclose(archivo);
			fclose(archivoBackUp);
			funcionesGlobales::mostrarPorcentaje(true, "Generando Backup ... ");
			std::cout << "Copia de seguridad generada con éxito." << std::endl;
			return true;
		}
		else {
			fclose(archivo);
			return false;
		}
	}
	else {
		FILE* archivoBackUp = fopen("backUp/diagramaBKP.dat", "wb");
		if (archivoBackUp == NULL) {
			std::cout << "Error al abrir el archivo de respaldo. Falla BackUp" << std::endl;
			fclose(archivo);
			return false;
		}

		DiagramaSala diagrama;
		while (fread(&diagrama, sizeof(DiagramaSala), 1, archivo) == 1) {
			fwrite(&diagrama, sizeof(DiagramaSala), 1, archivoBackUp);
		}

		fclose(archivo);
		fclose(archivoBackUp);
		funcionesGlobales::mostrarPorcentaje(true, "Generando Backup ... ");
		std::cout << "Copia de seguridad generada con éxito." << std::endl;
		return true;
	}
	fclose(archivo);
	return false;
}



bool ArchivoDiagrama::restaurarBackUp() {
	FILE* archivoBackUp = fopen("backUp/diagramaBKP.dat", "rb");
	std::string ruta = "diagrama.dat";

	if (archivoBackUp == NULL)
	{
		std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
		system ("pause");
		return false;
	}
	if (std::filesystem::exists(ruta)) {
		std::cout << "Ya existe un archivo de diagrama." << std::endl;
		if (funcionesGlobales::confirmarAccion("Desea sobreescribirlo? (S/N): ")) {
			FILE* archivo = fopen("diagrama.dat", "wb");
			if (archivo == NULL)
			{
				std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
				fclose(archivoBackUp);
				return false;
			}
			DiagramaSala diagrama;
			while (fread(&diagrama, sizeof(DiagramaSala), 1, archivoBackUp))
			{
				fwrite(&diagrama, sizeof(DiagramaSala), 1, archivo);
			}
			fclose(archivoBackUp);
			fclose(archivo);
			funcionesGlobales::mostrarPorcentaje(true, "Restaurando Backup ... ");
			std::cout << "Copia de seguridad restaurada con éxito." << std::endl;
			return true;
		}
		else {
			fclose(archivoBackUp);
			return false;
		}
	}
	else {
		FILE* archivo = fopen("diagrama.dat", "wb");
		if (archivo == NULL)
		{
			std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
			fclose(archivoBackUp);
			return false;
		}
		DiagramaSala diagrama;
		while (fread(&diagrama, sizeof(DiagramaSala), 1, archivoBackUp))
		{
			fwrite(&diagrama, sizeof(DiagramaSala), 1, archivo);
		}
		fclose(archivoBackUp);
		fclose(archivo);
		funcionesGlobales::mostrarPorcentaje(true, "Restaurando Backup ... ");
		std::cout << "Copia de seguridad restaurada con éxito." << std::endl;
		return true;
	}
}