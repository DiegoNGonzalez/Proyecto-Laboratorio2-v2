#include "InformesMaker.h"
#include "funcionesGlobales.h"


InformesMaker::InformesMaker() {}

void InformesMaker::mostrarInfomeRecaXPelicula() {
	Administrador admin;

	int idPelicula;

	std::cout << "LISTADO DE PELICULAS DISPONIBLES " << std::endl << std::endl;
	admin.verPeliculasCargadas();

	/*std::cout << "Por favor ingrese el ID de la pelicula: ";
	std::cin >> idPelicula;*/
	idPelicula = funcionesGlobales::validarMinimo(1, "Por favor ingrese el ID de la pelicula: ", "ERROR. Ingrese un numero valido", "El numero debe ser mayor o igual a 1 ");


	Pelicula pelicula; // creo el obj pelicuila
	ArchivoPeliculas archivoPeliculas("pelicula.dat");

	Entrada entrada;
	ArchivoEntrada archivoEntrada("venta.dat");

	int cantidadPeliculas = archivoPeliculas.contarRegistros();
	int cantidadEntradas = archivoEntrada.contarRegistros();

	int recaudacion = 0;

	for (int i = 0; i < cantidadPeliculas; i++) {

		pelicula = archivoPeliculas.leerRegistro(i);
		int idPeliActual = pelicula.getId();

		if (idPeliActual == idPelicula) {
			for (int j = 0; j < cantidadEntradas; j++) {
				entrada = archivoEntrada.leerRegistro(j);
				int idPeliEntrada = entrada.getFuncion().getPelicula().getId();

				if (idPeliEntrada == idPelicula) {
					recaudacion += entrada.getImporte();
				}
			}
			if (recaudacion == 0) {
				std::cout << "No hay ventas para la pelicula " << pelicula.getTitulo() << std::endl;

			}
			else {
				//uso la libreria <iomanip> para que se muestre como una tabla
				std::cout << " " << std::left << std::setw(36) << "____________________________________" << "" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << "TITULO" << "|" << std::setw(4) << "ID" << "|" << std::setw(15) << "RECAUDACION" << "|" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << pelicula.getTitulo() << "|" << std::setw(4) << idPelicula << "|" << std::setw(1) << "$" << std::setw(14) << recaudacion << "|" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << "_______________" << "|" << std::setw(4) << "____" << "|" << std::setw(15) << "_______________" << "|" << std::endl;
				std::cout << std::endl;
			}

		}

	}


}

void InformesMaker::mostrarInformeRecaXDia() {

	ArchivoEntrada archiEntrada("venta.dat");
	Entrada entrada;

	int cantEntradas = archiEntrada.contarRegistros();

	int dia;
	int mes;
	int anio;

	int recaudacion = 0;

	std::cout << "INGRESAR LA FECHA\n" << std::endl;
	dia=funcionesGlobales::validarRango(1, 31, "Ingrese el dia: ", "ERROR. Ingrese un numero valido", "El numero debe ser mayor o igual a 1 ", "y menor o igual a 31");
	mes=funcionesGlobales::validarRango(1, 12, "Ingrese el mes: ", "ERROR. Ingrese un numero valido", "El numero debe ser mayor o igual a 1 ", "y menor o igual a 12");
	anio=funcionesGlobales::validarRango(2020, 2021, "Ingrese el anio: ", "ERROR. Ingrese un numero valido", "El numero debe ser mayor o igual a 2020 ", "y menor o igual a 2021");
	/*std::cout << "Ingrese el dia: ";
	std::cin >> dia;
	std::cout << "Ingrese el mes: ";
	std::cin >> mes;
	std::cout << "Ingrese el anio: ";
	std::cin >> anio;*/

	Fecha fechaInforme(dia, mes, anio);

	for (int i = 0; i < cantEntradas; i++) {
		entrada = archiEntrada.leerRegistro(i);	
		Fecha fechaEntrada = entrada.getFechaHora().getFecha();

		if (funcionesGlobales::compararFechas(fechaEntrada, fechaInforme)) {
			recaudacion += entrada.getImporte();
		}
	}

	if (recaudacion > 0) {
		fechaInforme.mostrarFecha();
		std::cout << "\nLa recaudacion del dia fue de: " << recaudacion << std::endl;
	}
	else {
		fechaInforme.mostrarFecha();
		std::cout << "\nNo se vendieron entradas" << std::endl;
	}

}

