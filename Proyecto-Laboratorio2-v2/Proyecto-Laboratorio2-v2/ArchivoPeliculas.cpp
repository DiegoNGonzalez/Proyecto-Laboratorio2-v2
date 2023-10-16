#include "ArchivoPeliculas.h"
#include <iostream>
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

bool ArchivoPeliculas::generarBackUp() {
	FILE* p;
	FILE* pBackUp;
	Pelicula pelicula;
	bool pudoEscribir = false;
	p = fopen(_nombre, "rb");
	pBackUp = fopen("backUp/peliculaBKP.dat", "wb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al generar back up" << std::endl;
		return false;
	}
	while (fread(&pelicula, sizeof pelicula, 1, p) == 1) {
		fwrite(&pelicula, sizeof pelicula, 1, pBackUp);
	}
	fclose(p);
	fclose(pBackUp);
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

bool ArchivoPeliculas::restaurarBackUp() {
	FILE* p;
	FILE* pBackUp;
	Pelicula pelicula;
	bool pudoEscribir = false;
	p = fopen(_nombre, "wb");
	pBackUp = fopen("backUp/peliculaBKP.dat", "rb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al restaurar back up" << std::endl;
		return false;
	}
	while (fread(&pelicula, sizeof pelicula, 1, pBackUp) == 1) {
		fwrite(&pelicula, sizeof pelicula, 1, p);
	}
	fclose(p);
	fclose(pBackUp);
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