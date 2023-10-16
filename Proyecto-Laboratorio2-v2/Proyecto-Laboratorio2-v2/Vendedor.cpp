#include "Vendedor.h"
#include <iostream>
Vendedor::Vendedor() : Persona() {

}

Vendedor::Vendedor(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Persona(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}


void Vendedor::venderEntradas() {
	ArchivoDiagrama archivoDiagrama("diagrama.dat");
	ArchivoFunciones archivoFunciones("funcion.dat");
	ArchivoVenta archivoVenta("venta.dat");
	DiagramaSala diagramaAux;
	Funcion funcionAux;
	Venta ventaAux;
	int idFuncion, entradas, idVenta=archivoVenta.validarId();
	float valorSalaAuxiliar, importeVenta;
	std::cout << "Ingrese el ID de la funcion: ";
	std::cin >> idFuncion;
	int posAuxiliar = archivoFunciones.buscarPosFuncionxID(idFuncion);
	funcionAux = archivoFunciones.leerRegistro(posAuxiliar);
	diagramaAux = archivoDiagrama.leerRegistro(posAuxiliar);

	valorSalaAuxiliar = funcionAux.getSala().getPrecioAsiento();
	entradas = funcionAux.getContadorEntrada();
	importeVenta = valorSalaAuxiliar * entradas;
	ventaAux=Venta(idVenta, entradas, funcionAux, importeVenta);
	archivoVenta.grabarRegistro(ventaAux);
	funcionAux.setContadorEntrada(0);
	archivoFunciones.grabarRegistro(funcionAux, posAuxiliar);

	std::cout << "Venta realizada con exito" << std::endl;
}