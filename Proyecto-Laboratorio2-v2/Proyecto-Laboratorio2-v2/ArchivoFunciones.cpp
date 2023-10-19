#include "ArchivoFunciones.h"
//#include <iostream>

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
	FILE* p;
	FILE* pBackUp;
	Funcion funcion;
	bool pudoEscribir = false;
	p = fopen(_nombre, "rb");
	pBackUp = fopen("backUp/funcionBKP.dat", "wb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al generar back up" << std::endl;
		return false;
	}
	while (fread(&funcion, sizeof funcion, 1, p) == 1) {
		fwrite(&funcion, sizeof funcion, 1, pBackUp);
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

bool ArchivoFunciones::restaurarBackUp() {
	FILE* p;
	FILE* pBackUp;
	Funcion funcion;
	bool pudoEscribir = false;
	p = fopen(_nombre, "wb");
	pBackUp = fopen("backUp/funcionBKP.dat", "rb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al restaurar back up" << std::endl;
		return false;
	}
	while (fread(&funcion, sizeof funcion, 1, pBackUp) == 1) {
		fwrite(&funcion, sizeof funcion, 1, p);
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
	std::cout << "No se encontro el id." << std::endl;
	return -1;
}

Funcion ArchivoFunciones::buscarFuncionxID(int valorBuscado) {
	Funcion funcion;
	int pos = buscarPosFuncionxID(valorBuscado);
	if (pos >= 0) {
	funcion = leerRegistro(pos);
	return funcion;
	}
	else {
		std::cout << "No se encontro el id." << std::endl;
		return funcion;
	}
}

