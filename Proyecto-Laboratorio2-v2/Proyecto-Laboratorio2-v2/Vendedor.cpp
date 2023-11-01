#include "Vendedor.h"
#include <iostream>
#include "funcionesGlobales.h"
Vendedor::Vendedor() : Empleado() {

}

Vendedor::Vendedor(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Empleado(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}


void Vendedor::venderEntradas(int idFuncion) {
	ArchivoDiagrama archivoDiagrama("diagrama.dat");
	ArchivoFunciones archivoFunciones("funcion.dat");
	ArchivoEntrada archivoEntrada("venta.dat");
	ArchivoSalas archivoSalas("sala.dat");

	DiagramaSala diagramaAux;
	Funcion funcionAux;
	Entrada ventaAux;
	Sala salaAux;

	int idEntrada = archivoEntrada.validarId();
	float importeVenta;
	int posAuxiliar = archivoFunciones.buscarPosFuncionxID(idFuncion);
	int fila, columna, idsala, posSala;

	fila = funcionesGlobales::validarRango(1, 10, "FILA DEL ASIENTO A VENDER: ", "INGRESO NO VALIDO, REINGRESE FILA: ", "EL NRO DE FILA DEBE SER MAYOR O IGUAL A 1 ", "Y MENOR O IGUAL A 10.");

	funcionAux = archivoFunciones.leerRegistro(posAuxiliar);
	diagramaAux = archivoDiagrama.leerRegistro(posAuxiliar);

	diagramaAux.mostrarAsientosPorFilaDisponible(fila);

	importeVenta = funcionAux.getSala().getPrecioAsiento();

	salaAux = funcionAux.getSala();
	salaAux.setAsientosDisponibles(salaAux.getAsientosDisponibles() - 1);
	funcionAux.setSala(salaAux);

	columna = funcionesGlobales::validarRango(1, 10, "NRO DE ASIENTO A VENDER: ", "INGRESO NO VALIDO, REINGRESE ASIENTO: ", "EL NRO DE ASIENTO DEBE SER MAYOR O IGUAL A 1 ", "Y MENOR O IGUAL A 10.");

	if (archivoDiagrama.reservarAsientoEnRegistro(posAuxiliar, fila, columna)) {
		ventaAux = Entrada(idEntrada, funcionAux, importeVenta, fila, columna);
		archivoEntrada.grabarRegistro(ventaAux);
		archivoFunciones.grabarRegistro(funcionAux, posAuxiliar);
	}
}

void Vendedor::cancelarVenta(int idEntrada) {
	ArchivoDiagrama archivoDiagrama("diagrama.dat");
	ArchivoFunciones archivoFunciones("funcion.dat");
	ArchivoEntrada archivoVenta("venta.dat");
	ArchivoSalas archivoSalas("sala.dat");

	DiagramaSala diagramaAux;
	Funcion funcionAux;
	Entrada ventaAux;
	Sala salaAux;

	int posVenta = archivoVenta.buscarPosEntradaxID(idEntrada);
	int posAuxiliar = archivoFunciones.buscarPosFuncionxID(ventaAux.getFuncion().getIdFuncion());
	int fila = ventaAux.getFilaAsiento();
	int columna = ventaAux.getColumnaAsiento();

	ventaAux = archivoVenta.buscarEntradaxID(idEntrada);
	funcionAux = archivoFunciones.leerRegistro(posAuxiliar);
	diagramaAux = archivoDiagrama.leerRegistro(posAuxiliar);
	salaAux = funcionAux.getSala();	

	salaAux.setAsientosDisponibles(salaAux.getAsientosDisponibles() + 1);
	funcionAux.setSala(salaAux);

	if (funcionesGlobales::confirmarAccion("DESEA CANCELAR LA VENTA? (S/N): ") ){

		if (archivoDiagrama.cancelarReservaEnRegistro(posAuxiliar, fila, columna)) {
			ventaAux.setEstado(false);
			archivoVenta.grabarRegistro(ventaAux, posVenta);
			archivoFunciones.grabarRegistro(funcionAux, posAuxiliar);
		}
	}
}
