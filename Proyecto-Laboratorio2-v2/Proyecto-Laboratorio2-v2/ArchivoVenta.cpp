#include "ArchivoVenta.h"

Venta ArchivoVenta::leerRegistro(int posicion) {
	Venta venta;
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al tratar de leer" << std::endl;
		return venta;
	}
	fseek(p, posicion * sizeof(Venta), SEEK_SET);
	fread(&venta, sizeof(Venta), 1, p);
	fclose(p);
	return venta;
}
int ArchivoVenta::contarRegistros() {
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al contar" << std::endl;
		return -1;
	};
	fseek(p, 0, 2);
	int tam = ftell(p);
	fclose(p);
	return tam / sizeof(Venta);
};
bool ArchivoVenta::grabarRegistro(Venta venta) {
	FILE* p;
	p = fopen(_nombre, "ab");
	if (p == NULL) {
		std::cout << "Error al grabar registro" << std::endl;
		return false;
	};
	int escribio = fwrite(&venta, sizeof Venta, 1, p);
	fclose(p);
	return escribio;
};

bool ArchivoVenta::grabarRegistro(Venta venta, int posicion) {
	bool pudoEscribir;
	FILE* p = fopen(_nombre, "rb+");
	if (p == nullptr) {
		return false;
	}
	fseek(p, posicion * sizeof(Venta), SEEK_SET);
	pudoEscribir = fwrite(&venta, sizeof(Venta), 1, p);
	fclose(p);
	return pudoEscribir;
}
bool ArchivoVenta::generarBackUp() {
	FILE* p;
	FILE* pBackUp;
	Venta venta;
	bool pudoEscribir = false;
	p = fopen(_nombre, "rb");
	pBackUp = fopen("backUp/VentaBKP.dat", "wb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al generar back up" << std::endl;
		return false;
	}
	while (fread(&venta, sizeof Venta, 1, p) == 1) {
		fwrite(&venta, sizeof Venta, 1, pBackUp);
	}
	fclose(p);
	fclose(pBackUp);
	pudoEscribir = true;
	int porcentaje = 25;
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
	}
	system("pause");
	return pudoEscribir;
}

bool ArchivoVenta::restaurarBackUp() {
	FILE* p;
	FILE* pBackUp;
	Venta venta;
	bool pudoEscribir = false;
	p = fopen(_nombre, "wb");
	pBackUp = fopen("backUp/VentaBKP.dat", "rb");
	if (p == NULL || pBackUp == NULL) {
		std::cout << "Error al restaurar back up" << std::endl;
		return false;
	}
	while (fread(&venta, sizeof Venta, 1, pBackUp) == 1) {
		fwrite(&venta, sizeof Venta, 1, p);
	}
	fclose(p);
	fclose(pBackUp);
	pudoEscribir = true;
	int porcentaje = 25;
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
	system("pause");
	return pudoEscribir;
}

int ArchivoVenta::validarId() {
	FILE* p;
	int idMax = 0, contarReg;

	p = fopen(_nombre, "rb");
	if (p == NULL) {
		return 1;
	}
	contarReg = contarRegistros();
	for (int i = 0; i < contarReg; i++) {
		Venta venta = leerRegistro(i);
		if (venta.getIdVenta() > idMax) {
			idMax = venta.getIdVenta();
		}
	}
	fclose(p);
	return idMax + 1;

}

int ArchivoVenta::buscarPosVentaxID(int valorBuscado) {
	Venta venta;
	int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		venta = leerRegistro(i);
		if (venta.getIdVenta() == valorBuscado) {
			return i;
		}
	}
	std::cout << "No se encontro el id." << std::endl;
	return -1;
}

Venta ArchivoVenta::buscarVentaxID(int valorBuscado) {
	Venta venta;
	int pos = buscarPosVentaxID(valorBuscado);
	if (pos >= 0) {
		venta = leerRegistro(pos);
		return venta;
	}
	else {
		std::cout << "No se encontro el id." << std::endl;
		return venta;
	}
}

int ArchivoVenta::buscarPosVentaxAsientoVendido(int idFuncion, int fila, int columna)
{
	Venta venta;
	int cantidadRegistros = contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		venta = leerRegistro(i);
		if (venta.getFuncion().getIdFuncion() == idFuncion && venta.getFilaAsiento() == fila && venta.getColumnaAsiento() == columna) {
			return i;
		}
	}
	std::cout << "No se encontro el id." << std::endl;
	return -1;
}

Venta ArchivoVenta::buscarVentaxAsientoVendido(int idFuncion, int fila, int columna)
{
	Venta venta;
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

void ArchivoVenta::verVentasCargadas()
{
	Venta venta;
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
