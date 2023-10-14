#include "ArchivoSalas.h"
#include <iostream>
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
		return -1; };
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
		return false; };
	int escribio = fwrite(&sala, sizeof sala, 1, p);
	fclose(p);
	return escribio;
};

void ArchivoSalas::generarBackUp() {
	FILE* p;
	FILE* pBackUp;
	Sala sala;
	p = fopen(_nombre, "rb");
	pBackUp = fopen("backUp/salaBKP.dat", "wb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al generar back up" << std::endl;
		return;
	}
	while (fread(&sala, sizeof sala, 1, p) == 1) {
		fwrite(&sala, sizeof sala, 1, pBackUp);
	}
	fclose(p);
	fclose(pBackUp);
}

void ArchivoSalas::restaurarBackUp() {
	FILE* p;
	FILE* pBackUp;
	Sala sala;
	p = fopen(_nombre, "wb");
	pBackUp = fopen("backUp/salaBKP.dat", "rb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al restaurar back up" << std::endl;
		return;
	}
	while (fread(&sala, sizeof sala, 1, pBackUp) == 1) {
		fwrite(&sala, sizeof sala, 1, p);
	}
	fclose(p);
	fclose(pBackUp);
}