#include "Vendedor.h"
#include <iostream>
Vendedor::Vendedor() : Empleado() {

}

Vendedor::Vendedor(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Empleado(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}


void Vendedor::venderEntradas(int idFuncion) {
	ArchivoDiagrama archivoDiagrama("diagrama.dat");
	ArchivoFunciones archivoFunciones("funcion.dat");
	ArchivoEntrada archivoEntrada("venta.dat");
	DiagramaSala diagramaAux;
	Funcion funcionAux;
	Entrada ventaAux;
	int idEntrada=archivoEntrada.validarId();
	float importeVenta;
	int posAuxiliar = archivoFunciones.buscarPosFuncionxID(idFuncion);
	int fila, columna;
	std::cout << "FILA DEL ASIENTO A VENDER: ";
	std::cin >> fila;
	funcionAux = archivoFunciones.leerRegistro(posAuxiliar);
	diagramaAux = archivoDiagrama.leerRegistro(posAuxiliar);
	diagramaAux.mostrarAsientosPorFilaDisponible(fila);
	importeVenta = funcionAux.getSala().getPrecioAsiento();
	std::cout << "NRO DE ASIENTO A VENDER: ";
	std::cin >> columna;
	if (archivoDiagrama.reservarAsientoEnRegistro(posAuxiliar, fila, columna)) {
		ventaAux=Entrada(idEntrada, funcionAux, importeVenta, fila, columna);
		archivoEntrada.grabarRegistro(ventaAux);
		//std::cout << "Venta realizada con exito" << std::endl;
	}
}

void Vendedor::cancelarVenta(int idEntrada)
{
	ArchivoDiagrama archivoDiagrama("diagrama.dat");
	ArchivoFunciones archivoFunciones("funcion.dat");
	ArchivoEntrada archivoVenta("venta.dat");
	DiagramaSala diagramaAux;
	Funcion funcionAux;
	Entrada ventaAux;
	//int idEntrada = archivoVenta.validarId();
	//float importeVenta;
	int posVenta= archivoVenta.buscarPosEntradaxID(idEntrada);
	ventaAux = archivoVenta.buscarEntradaxID(idEntrada);
	int posAuxiliar = archivoFunciones.buscarPosFuncionxID(ventaAux.getFuncion().getIdFuncion());
	int fila= ventaAux.getFilaAsiento(), columna= ventaAux.getColumnaAsiento();
	/*std::cout << "Ingrese la fila del asiento: ";
	std::cin >> fila;
	std::cout << "Ingrese la columna del asiento: ";
	std::cin >> columna;*/
	funcionAux = archivoFunciones.leerRegistro(posAuxiliar);
	diagramaAux = archivoDiagrama.leerRegistro(posAuxiliar);
	//importeVenta = funcionAux.getSala().getPrecioAsiento();
	if (archivoDiagrama.cancelarReservaEnRegistro(posAuxiliar, fila, columna)) {
		//ventaAux = Venta(idEntrada, funcionAux, importeVenta);
		ventaAux.setEstado(false);
		archivoVenta.grabarRegistro(ventaAux, posVenta);
		//std::cout << "Venta realizada con exito" << std::endl;
	}
}
