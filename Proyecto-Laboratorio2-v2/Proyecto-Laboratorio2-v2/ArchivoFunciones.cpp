#include "ArchivoFunciones.h"
#include "funcionesGlobales.h"
//#include <iostream>
#include <filesystem>

Funcion ArchivoFunciones::leerRegistro(int posicion) {
	Funcion funcion;
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al tratar de leer" << std::endl;
		return funcion;
	}
	fseek(p, posicion * sizeof(Funcion), SEEK_SET);
	fread(&funcion, sizeof(Funcion), 1, p);
	fclose(p);
	return funcion;
}
int ArchivoFunciones::contarRegistros() {
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al contar" << std::endl;
		return -1;
	};
	fseek(p, 0, 2);
	int tam = ftell(p);
	fclose(p);
	return tam / sizeof(Funcion);
};
bool ArchivoFunciones::grabarRegistro(Funcion funcion) {
	FILE* p;
	p = fopen(_nombre, "ab");
	if (p == NULL) {
		std::cout << "Error al grabar registro" << std::endl;
		return false;
	};
	int escribio = fwrite(&funcion, sizeof funcion, 1, p);
	fclose(p);
	return escribio;
};

bool ArchivoFunciones::grabarRegistro(Funcion funcion, int posicion) {
	bool pudoEscribir;
	FILE* p = fopen(_nombre, "rb+");
	if (p == nullptr) {
		return false;
	}
	fseek(p, posicion * sizeof(Funcion), SEEK_SET);
	pudoEscribir = fwrite(&funcion, sizeof(Funcion), 1, p);
	fclose(p);
	return pudoEscribir;
}
bool ArchivoFunciones::generarBackUp() {
	FILE* archivo = fopen(_nombre, "rb");
	std::string ruta = "backUp/funcionBKP.dat";

	if (archivo == NULL) {
		std::cout << "Error al abrir el archivo. Falla BackUp" << std::endl;
		return false;
	}

	if (std::filesystem::exists(ruta)) {
		std::cout << "Ya existe un BackUp de Funciones." << std::endl;
		if (funcionesGlobales::confirmarAccion("Desea sobreescribirlo? (S/N): ")) {
			FILE* archivoBackUp = fopen("backUp/funcionBKP.dat", "wb");
			if (archivoBackUp == NULL) {
				std::cout << "Error al abrir el archivo de respaldo. Falla BackUp" << std::endl;
				fclose(archivo);
				return false;
			}

			Funcion funcion;
			while (fread(&funcion, sizeof(Funcion), 1, archivo) == 1) {
				fwrite(&funcion, sizeof(Funcion), 1, archivoBackUp);
			}

			fclose(archivo);
			fclose(archivoBackUp);
			funcionesGlobales::mostrarPorcentaje(true);
			std::cout << "Copia de seguridad generada con éxito." << std::endl;
			return true;
		}
		else {
			fclose(archivo);
			return false;
		}
	}
	else {
		FILE* archivoBackUp = fopen("backUp/funcionBKP.dat", "wb");
		if (archivoBackUp == NULL) {
			std::cout << "Error al abrir el archivo de respaldo. Falla BackUp" << std::endl;
			fclose(archivo);
			return false;
		}

		Funcion funcion;
		while (fread(&funcion, sizeof(Funcion), 1, archivo) == 1) {
			fwrite(&funcion, sizeof(Funcion), 1, archivoBackUp);
		}

		fclose(archivo);
		fclose(archivoBackUp);
		funcionesGlobales::mostrarPorcentaje(true);
		std::cout << "Copia de seguridad generada con éxito." << std::endl;
		return true;
	}
	fclose(archivo);
	return false;
}



bool ArchivoFunciones::restaurarBackUp() {
	FILE* archivoBackUp = fopen("backUp/funcionBKP.dat", "rb");
	std::string ruta = "funcion.dat";

	if (archivoBackUp == NULL)
	{
		std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
		return false;
	}
	if (std::filesystem::exists(ruta)) {
		std::cout << "Ya existe un archivo de Funciones." << std::endl;
		if (funcionesGlobales::confirmarAccion("Desea sobreescribirlo? (S/N): ")) {
			FILE* archivo = fopen("funcion.dat", "wb");
			if (archivo == NULL)
			{
				std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
				fclose(archivoBackUp);
				return false;
			}
			Funcion funcion;
			while (fread(&funcion, sizeof(Funcion), 1, archivoBackUp))
			{
				fwrite(&funcion, sizeof(Funcion), 1, archivo);
			}
			fclose(archivoBackUp);
			fclose(archivo);
			funcionesGlobales::mostrarPorcentaje(true);
			std::cout << "Copia de seguridad restaurada con éxito." << std::endl;
			return true;
		}
		else {
			fclose(archivoBackUp);
			return false;
		}
	}
	else {
		FILE* archivo = fopen("funcion.dat", "wb");
		if (archivo == NULL)
		{
			std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
			fclose(archivoBackUp);
			return false;
		}
		Funcion funcion;
		while (fread(&funcion, sizeof(Funcion), 1, archivoBackUp))
		{
			fwrite(&funcion, sizeof(Funcion), 1, archivo);
		}
		fclose(archivoBackUp);
		fclose(archivo);
		funcionesGlobales::mostrarPorcentaje(true);
		std::cout << "Copia de seguridad restaurada con éxito." << std::endl;
		return true;
	}
}

int ArchivoFunciones::validarId() {
	FILE* p;
	int idMax = 0, contarReg;

	p = fopen(_nombre, "rb");
	if (p == NULL) {
		return 1;
	}
	contarReg = contarRegistros();
	for (int i = 0; i < contarReg; i++) {
		Funcion funcion = leerRegistro(i);
		if (funcion.getIdFuncion() > idMax) {
			idMax = funcion.getIdFuncion();
		}
	}
	fclose(p);
	return idMax + 1;

}

int ArchivoFunciones::buscarPosFuncionxID(int valorBuscado) {
	Funcion funcion;
	int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		funcion = leerRegistro(i);
		if (funcion.getIdFuncion() == valorBuscado) {
			return i;
		}
	}
	std::cout << "NRO DE FUNCION INEXISTENTE." << std::endl;
	return -1;
}

Funcion ArchivoFunciones::buscarFuncionxID(int valorBuscado) {
	Funcion funcion;
	int pos = buscarPosFuncionxID(valorBuscado);
	if (pos >= 0) {
	funcion = leerRegistro(pos);
	return funcion;
	}
	return Funcion::Funcion();
}

