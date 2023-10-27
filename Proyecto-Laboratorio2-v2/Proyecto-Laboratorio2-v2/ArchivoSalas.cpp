#include "ArchivoSalas.h"
#include "funcionesGlobales.h"
#include <iostream>
#include <filesystem>

Sala ArchivoSalas::leerRegistro(int posicion) {
	Sala sala;
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al tratar de leer" << std::endl;
		return sala;
	}
	fseek(p, posicion * sizeof(Sala), SEEK_SET);
	fread(&sala, sizeof(Sala), 1, p);
	fclose(p);
	return sala;
}
int ArchivoSalas::contarRegistros() {
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al contar" << std::endl;
		return -1;
	};
	fseek(p, 0, 2);
	int tam = ftell(p);
	fclose(p);
	return tam / sizeof(Sala);
};
bool ArchivoSalas::grabarRegistro(Sala sala) {
	FILE* p;
	p = fopen(_nombre, "ab");
	if (p == NULL) {
		std::cout << "Error al grabar registro" << std::endl;
		return false;
	};
	int escribio = fwrite(&sala, sizeof sala, 1, p);
	fclose(p);
	return escribio;
};
bool ArchivoSalas::grabarRegistro(Sala sala, int posicionSala) {
	bool pudoEscribir;
	FILE* p = fopen(_nombre, "rb+");
	if (p == nullptr) {
		return false;
	}
	fseek(p, posicionSala * sizeof(Sala), SEEK_SET);
	pudoEscribir = fwrite(&sala, sizeof(Sala), 1, p);
	fclose(p);
	return pudoEscribir;
};
bool ArchivoSalas::generarBackUp() {
	FILE* archivo = fopen(_nombre, "rb");
	std::string ruta = "backUp/salaBKP.dat";

	if (archivo == NULL) {
		std::cout << "Error al abrir el archivo. Falla BackUp" << std::endl;
		system("pause");
		return false;
	}

	if (std::filesystem::exists(ruta)) {
		std::cout << "Ya existe un BackUp de Salas." << std::endl;
		if (funcionesGlobales::confirmarAccion("Desea sobreescribirlo? (S/N): ")) {
			FILE* archivoBackUp = fopen("backUp/salaBKP.dat", "wb");
			if (archivoBackUp == NULL) {
				std::cout << "Error al abrir el archivo de respaldo. Falla BackUp" << std::endl;
				fclose(archivo);
				return false;
			}

			Sala sala;
			while (fread(&sala, sizeof(Sala), 1, archivo) == 1) {
				fwrite(&sala, sizeof(Sala), 1, archivoBackUp);
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
		FILE* archivoBackUp = fopen("backUp/salaBKP.dat", "wb");
		if (archivoBackUp == NULL) {
			std::cout << "Error al abrir el archivo de respaldo. Falla BackUp" << std::endl;
			fclose(archivo);
			return false;
		}

		Sala sala;
		while (fread(&sala, sizeof(Sala), 1, archivo) == 1) {
			fwrite(&sala, sizeof(Sala), 1, archivoBackUp);
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



bool ArchivoSalas::restaurarBackUp() {
	FILE* archivoBackUp = fopen("backUp/salaBKP.dat", "rb");
	std::string ruta = "venta.dat";

	if (archivoBackUp == NULL)
	{
		std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
		system("pause");
		return false;
	}
	if (std::filesystem::exists(ruta)) {
		std::cout << "Ya existe un archivo de Salas." << std::endl;
		if (funcionesGlobales::confirmarAccion("Desea sobreescribirlo? (S/N): ")) {
			FILE* archivo = fopen("sala.dat", "wb");
			if (archivo == NULL)
			{
				std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
				fclose(archivoBackUp);
				return false;
			}
			Sala sala;
			while (fread(&sala, sizeof(Sala), 1, archivoBackUp))
			{
				fwrite(&sala, sizeof(Sala), 1, archivo);
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
		FILE* archivo = fopen("sala.dat", "wb");
		if (archivo == NULL)
		{
			std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
			fclose(archivoBackUp);
			return false;
		}
		Sala sala;
		while (fread(&sala, sizeof(Sala), 1, archivoBackUp))
		{
			fwrite(&sala, sizeof(Sala), 1, archivo);
		}
		fclose(archivoBackUp);
		fclose(archivo);
		funcionesGlobales::mostrarPorcentaje(true);
		std::cout << "Copia de seguridad restaurada con éxito." << std::endl;
		return true;
	}
}

int ArchivoSalas::validarId() {
	FILE* p;
	int idMax = 0, contarReg;

	p = fopen(_nombre, "rb");
	if (p == NULL) {
		return 1;
	}
	contarReg = contarRegistros();
	for (int i = 0; i < contarReg; i++) {
		Sala sala = leerRegistro(i);
		if (sala.getIdSala() > idMax) {
			idMax = sala.getIdSala();
		}
	}
	fclose(p);
	return idMax + 1;

}

int ArchivoSalas::buscarPosSalaxID(int valorBuscado) {
	Sala sala;
	int cantidadRegistros=contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		sala = leerRegistro(i);
		if (sala.getIdSala() == valorBuscado) {
			return i;
		}
	}
	std::cout << "ID DE SALA INEXISTENTE." << std::endl;
	return -1;

}