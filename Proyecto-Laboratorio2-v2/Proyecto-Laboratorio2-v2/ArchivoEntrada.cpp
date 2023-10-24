#include "ArchivoEntrada.h"
#include "funcionesGlobales.h"
#include <filesystem>

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
	FILE* archivo = fopen(_nombre, "rb");
	std::string ruta = "backUp/ventaBKP.dat";

	if (archivo == NULL) {
		std::cout << "Error al abrir el archivo. Falla BackUp" << std::endl;
		return false;
	}

	if (std::filesystem::exists(ruta)) {
		std::cout << "Ya existe un BackUp de Entradas." << std::endl;
		if (funcionesGlobales::confirmarAccion("Desea sobreescribirlo? (S/N): ")) {
			FILE* archivoBackUp = fopen("backUp/ventaBKP.dat", "wb");
			if (archivoBackUp == NULL) {
				std::cout << "Error al abrir el archivo de respaldo. Falla BackUp" << std::endl;
				fclose(archivo);
				return false;
			}

			Entrada entrada;
			while (fread(&entrada, sizeof(Entrada), 1, archivo) == 1) {
				fwrite(&entrada, sizeof(Entrada), 1, archivoBackUp);
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
		FILE* archivoBackUp = fopen("backUp/ventaBKP.dat", "wb");
		if (archivoBackUp == NULL) {
			std::cout << "Error al abrir el archivo de respaldo. Falla BackUp" << std::endl;
			fclose(archivo);
			return false;
		}

		Entrada entrada;
		while (fread(&entrada, sizeof(Entrada), 1, archivo) == 1) {
			fwrite(&entrada, sizeof(Entrada), 1, archivoBackUp);
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



bool ArchivoEntrada::restaurarBackUp() {
	FILE* archivoBackUp = fopen("backUp/ventaBKP.dat", "rb");
	std::string ruta = "venta.dat";

	if (archivoBackUp == NULL)
	{
		std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
		return false;
	}
	if (std::filesystem::exists(ruta)) {
		std::cout << "Ya existe un archivo de Entradas." << std::endl;
		if (funcionesGlobales::confirmarAccion("Desea sobreescribirlo? (S/N): ")) {
			FILE* archivo = fopen("venta.dat", "wb");
			if (archivo == NULL)
			{
				std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
				fclose(archivoBackUp);
				return false;
			}
			Entrada entrada;
			while (fread(&entrada, sizeof(Entrada), 1, archivoBackUp))
			{
				fwrite(&entrada, sizeof(Entrada), 1, archivo);
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
		FILE* archivo = fopen("venta.dat", "wb");
		if (archivo == NULL)
		{
			std::cout << "Error al abrir el archivo, Fallo BackUp" << std::endl;
			fclose(archivoBackUp);
			return false;
		}
		Entrada entrada;
		while (fread(&entrada, sizeof(Entrada), 1, archivoBackUp))
		{
			fwrite(&entrada, sizeof(Entrada), 1, archivo);
		}
		fclose(archivoBackUp);
		fclose(archivo);
		funcionesGlobales::mostrarPorcentaje(true);
		std::cout << "Copia de seguridad restaurada con éxito." << std::endl;
		return true;
	}
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
