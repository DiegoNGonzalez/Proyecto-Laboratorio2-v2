#include "ArchivoEntrada.h"
#include "funcionesGlobales.h"

Entrada ArchivoEntrada::leerRegistro(int posicion) {
	Entrada entrada;
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al tratar de leer" << std::endl;
		return entrada;
	}
	fseek(p, posicion * sizeof(Entrada), SEEK_SET);
	fread(&entrada, sizeof(Entrada), 1, p);
	fclose(p);
	return entrada;
}
int ArchivoEntrada::contarRegistros() {
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al contar" << std::endl;
		return -1;
	};
	fseek(p, 0, 2);
	int tam = ftell(p);
	fclose(p);
	return tam / sizeof(Entrada);
};
bool ArchivoEntrada::grabarRegistro(Entrada entrada) {
	FILE* p;
	p = fopen(_nombre, "ab");
	if (p == NULL) {
		std::cout << "Error al grabar registro" << std::endl;
		return false;
	};
	int escribio = fwrite(&entrada, sizeof Entrada, 1, p);
	fclose(p);
	return escribio;
};

bool ArchivoEntrada::grabarRegistro(Entrada entrada, int posicion) {
	bool pudoEscribir;
	FILE* p = fopen(_nombre, "rb+");
	if (p == nullptr) {
		return false;
	}
	fseek(p, posicion * sizeof(Entrada), SEEK_SET);
	pudoEscribir = fwrite(&entrada, sizeof(Entrada), 1, p);
	fclose(p);
	return pudoEscribir;
}
bool ArchivoEntrada::generarBackUp() {
	FILE* p;
	FILE* pBackUp;
	Entrada entrada;
	bool pudoEscribir = false;
	p = fopen(_nombre, "rb");
	pBackUp = fopen("backUp/VentaBKP.dat", "wb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al generar back up" << std::endl;
		return false;
	}
	while (fread(&entrada, sizeof Entrada, 1, p) == 1) {
		fwrite(&entrada, sizeof Entrada, 1, pBackUp);
	}
	fclose(p);
	fclose(pBackUp);
	pudoEscribir = true;
	funcionesGlobales::mostrarPorcentaje(pudoEscribir);
	/*int porcentaje = 25;
	for (int x = 0; x < 4; x++) {

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
	}*/
	system("pause");
	return pudoEscribir;
}

bool ArchivoEntrada::restaurarBackUp() {
	FILE* p;
	FILE* pBackUp;
	Entrada entrada;
	bool pudoEscribir = false;
	p = fopen(_nombre, "wb");
	pBackUp = fopen("backUp/VentaBKP.dat", "rb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al restaurar back up" << std::endl;
		return false;
	}
	while (fread(&entrada, sizeof Entrada, 1, pBackUp) == 1) {
		fwrite(&entrada, sizeof Entrada, 1, p);
	}
	fclose(p);
	fclose(pBackUp);
	pudoEscribir = true;
	funcionesGlobales::mostrarPorcentaje(pudoEscribir);
	/*int porcentaje = 25;
	for (int x = 0; x < 4; x++) {

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

int ArchivoEntrada::validarId() {
	FILE* p;
	int idMax = 0, contarReg;

	p = fopen(_nombre, "rb");
	if (p == NULL) {
		return 1;
	}
	contarReg = contarRegistros();
	for (int i = 0; i < contarReg; i++) {
		Entrada venta = leerRegistro(i);
		if (venta.getidEntrada() > idMax) {
			idMax = venta.getidEntrada();
		}
	}
	fclose(p);
	return idMax + 1;

}

int ArchivoEntrada::buscarPosEntradaxID(int valorBuscado) {
	Entrada venta;
	int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		venta = leerRegistro(i);
		if (venta.getidEntrada() == valorBuscado) {
			return i;
		}
	}
	std::cout << "No se encontro el id." << std::endl;
	return -1;
}

Entrada ArchivoEntrada::buscarEntradaxID(int valorBuscado) {
	Entrada venta;
	int pos = buscarPosEntradaxID(valorBuscado);
	if (pos >= 0) {
		venta = leerRegistro(pos);
		return venta;
	}
	else {
		std::cout << "No se encontro el id." << std::endl;
		return venta;
	}
}

int ArchivoEntrada::buscarPosVentaxAsientoVendido(int idFuncion, int fila, int columna)
{
	Entrada entrada;
	int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		entrada = leerRegistro(i);
		if (entrada.getFuncion().getIdFuncion() == idFuncion && entrada.getFilaAsiento() == fila && entrada.getColumnaAsiento() == columna) {
			return i;
		}
	}
	std::cout << "No se encontro el id." << std::endl;
	return -1;
}

Entrada ArchivoEntrada::buscarVentaxAsientoVendido(int idFuncion, int fila, int columna)
{
	Entrada venta;
	int pos = buscarPosVentaxAsientoVendido(idFuncion, fila, columna);
	if (pos >= 0) {
		venta = leerRegistro(pos);
		return venta;
	}
	else {
		std::cout << "No se encontro el id." << std::endl;
		return venta;
	}
}

void ArchivoEntrada::verVentasCargadas()
{
	Entrada venta;
	int contador = 0;
	int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		venta = leerRegistro(i);
		if (venta.getEstado()) {
			venta.mostrarVenta();
			contador++;
		}
	}
	if (contador == 0) {
		std::cout << "No hay ventas cargadas" << std::endl;
	}
}
