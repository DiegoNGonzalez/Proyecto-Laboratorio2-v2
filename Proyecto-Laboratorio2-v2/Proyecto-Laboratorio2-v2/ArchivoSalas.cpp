#include "ArchivoSalas.h"
#include "funcionesGlobales.h"
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
	FILE* p;
	FILE* pBackUp;
	Sala sala;
	bool pudoEscribir = false;
	p = fopen(_nombre, "rb");
	//system("mkdir backUp");
	pBackUp = fopen("backUp/salaBKP.dat", "wb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al generar back up" << std::endl;
		return false;
	}
	while (fread(&sala, sizeof sala, 1, p) == 1) {
		fwrite(&sala, sizeof sala, 1, pBackUp);
	}
	fclose(p);
	fclose(pBackUp);
	pudoEscribir = true;
	funcionesGlobales::mostrarPorcentaje(pudoEscribir);
	/*int porcentaje = 25;
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
	system("pause");*/
	return pudoEscribir;
}

bool ArchivoSalas::restaurarBackUp() {
	FILE* p;
	FILE* pBackUp;
	Sala sala;
	bool pudoEscribir = false;
	p = fopen(_nombre, "wb");
	pBackUp = fopen("backUp/salaBKP.dat", "rb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al restaurar back up" << std::endl;
		return false;
	}
	while (fread(&sala, sizeof sala, 1, pBackUp) == 1) {
		fwrite(&sala, sizeof sala, 1, p);
	}
	fclose(p);
	fclose(pBackUp);
	pudoEscribir = true;
	funcionesGlobales::mostrarPorcentaje(pudoEscribir);
	/*int porcentaje = 25;
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
	system("pause");*/
	return pudoEscribir;
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
	std::cout << "No se encontro el id." << std::endl;
	return -1;

}