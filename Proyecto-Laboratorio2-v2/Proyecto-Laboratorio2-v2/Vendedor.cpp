#include "Vendedor.h"
#include <iostream>
Vendedor::Vendedor() : Persona() {

}

Vendedor::Vendedor(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Persona(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}


void Vendedor::venderEntradas(int idFuncion, int fila, int columna) {
	ArchivoDiagrama archivoDiagrama("diagrama.dat");
	ArchivoFunciones archivoFunciones("funcion.dat");
	ArchivoVenta archivoVenta("venta.dat");
	DiagramaSala diagramaAux;
	Funcion funcionAux;
	Venta ventaAux;
	int idVenta=archivoVenta.validarId();
	float importeVenta;
	int posAuxiliar = archivoFunciones.buscarPosFuncionxID(idFuncion);
	funcionAux = archivoFunciones.leerRegistro(posAuxiliar);
	diagramaAux = archivoDiagrama.leerRegistro(posAuxiliar);
	importeVenta = funcionAux.getSala().getPrecioAsiento();
	if (archivoDiagrama.reservarAsientoEnRegistro(posAuxiliar, fila, columna)) {
		ventaAux=Venta(idVenta, funcionAux, importeVenta);
		archivoVenta.grabarRegistro(ventaAux);
		//std::cout << "Venta realizada con exito" << std::endl;
	}
}