#include "ArchivoPeliculas.h"
#include "funcionesGlobales.h"
//#include <iostream>
#include <filesystem>
Pelicula ArchivoPeliculas::leerRegistro(int posicion) {
	Pelicula pelicula;
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al tratar de leer" << std::endl;
		return pelicula;
	}
	fseek(p, posicion * sizeof(Pelicula), SEEK_SET);
	fread(&pelicula, sizeof(Pelicula), 1, p);
	fclose(p);
	return pelicula;
}
int ArchivoPeliculas::contarRegistros() {
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al contar" << std::endl;
		return -1;
	};
	fseek(p, 0, 2);
	int tam = ftell(p);
	fclose(p);
	return tam / sizeof(Pelicula);
};
bool ArchivoPeliculas::grabarRegistro(Pelicula pelicula) {
	FILE* p;
	p = fopen(_nombre, "ab");
	if (p == NULL) {
		std::cout << "Error al grabar registro" << std::endl;
		return false;
	};
	int escribio = fwrite(&pelicula, sizeof pelicula, 1, p);
	fclose(p);
	return escribio;
};

bool ArchivoPeliculas::grabarRegistro(Pelicula diagrama, int posicion) {
	bool pudoEscribir;
	FILE* p = fopen(_nombre, "rb+");
	if (p == nullptr) {
		return false;
	}
	fseek(p, posicion * sizeof(Pelicula), SEEK_SET);
	pudoEscribir = fwrite(&diagrama, sizeof(Pelicula), 1, p);
	fclose(p);
	return pudoEscribir;
}
bool ArchivoPeliculas::generarBackUp() {
	FILE* archivo = fopen(_nombre, "rb");
	std::string ruta = "backUp/peliculaBKP.dat";

	if (archivo == NULL) {
		std::cout << "Error al abrir el archivo. Falla BackUp" << std::endl;
		system("pause");
		return false;
	}

	if (std::filesystem::exists(ruta)) {
		std::cout << "Ya existe un BackUp de Peliculas." << std::endl;
		if (funcionesGlobales::confirmarAccion("Desea sobreescribirlo? (S/N): ")) {
			FILE* archivoBackUp = fopen("backUp/peliculaBKP.dat", "wb");
			if (archivoBackUp == NULL) {
				std::cout << "Error al abrir el archivo de respaldo. Falla BackUp" << std::endl;
				fclose(archivo);
				return false;
			}

			Pelicula pelicula;
			while (fread(&pelicula, sizeof(Pelicula), 1, archivo) == 1) {
				fwrite(&pelicula, sizeof(Pelicula), 1, archivoBackUp);
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
		FILE* archivoBackUp = fopen("backUp/peliculaBKP.dat", "wb");
		if (archivoBackUp == NULL) {
			std::cout << "Error al abrir el archivo de respaldo. Falla BackUp" << std::endl;
			fclose(archivo);
			return false;
		}

		Pelicula pelicula;
		while (fread(&pelicula, sizeof(Pelicula), 1, archivo) == 1) {
			fwrite(&pelicula, sizeof(Pelicula), 1, archivoBackUp);
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



bool ArchivoPeliculas::restaurarBackUp() {
	FILE* archivoBackUp = fopen("backUp/peliculaBKP.dat", "rb");
	std::string ruta = "pelicula.dat";

	if (archivoBackUp == NULL)
	{
		std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
		return false;
	}
	if (std::filesystem::exists(ruta)) {
		std::cout << "Ya existe un archivo de Peliculas." << std::endl;
		if (funcionesGlobales::confirmarAccion("Desea sobreescribirlo? (S/N): ")) {
			FILE* archivo = fopen("venta.dat", "wb");
			if (archivo == NULL)
			{
				std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
				fclose(archivoBackUp);
				return false;
			}
			Pelicula pelicula;
			while (fread(&pelicula, sizeof(Pelicula), 1, archivoBackUp))
			{
				fwrite(&pelicula, sizeof(Pelicula), 1, archivo);
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
		FILE* archivo = fopen("pelicula.dat", "wb");
		if (archivo == NULL)
		{
			std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
			fclose(archivoBackUp);
			return false;
		}
		Pelicula pelicula;
		while (fread(&pelicula, sizeof(Pelicula), 1, archivoBackUp))
		{
			fwrite(&pelicula, sizeof(Pelicula), 1, archivo);
		}
		fclose(archivoBackUp);
		fclose(archivo);
		funcionesGlobales::mostrarPorcentaje(true);
		std::cout << "Copia de seguridad restaurada con éxito." << std::endl;
		return true;
	}
}
int ArchivoPeliculas::validarId() {
	FILE* p;
	int idMax = 0, contarReg;

	p = fopen(_nombre, "rb");
	if (p == NULL) {
		return 1;
	}
	contarReg = contarRegistros();
	for (int i = 0; i < contarReg; i++) {
		Pelicula pelicula = leerRegistro(i);
		if (pelicula.getId() > idMax) {
			idMax = pelicula.getId();
		}
	}
	fclose(p);
	return idMax + 1;


}

int ArchivoPeliculas::buscarPosPeliculaxID(int valorBuscado) {
	
	Pelicula pelicula;
	int cantidadRegistros=contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		pelicula = leerRegistro(i);
		if (pelicula.getId() == valorBuscado && pelicula.getEstado() == true) {
			return i;
		}
	}
	std::cout << "ID DE PELICULA INEXISTENTE." << std::endl;
	return -1;
	
}

