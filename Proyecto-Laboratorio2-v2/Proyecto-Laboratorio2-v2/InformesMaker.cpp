#include "InformesMaker.h"
/*
@brief compararFechas recibe dos objetos Fecha y devuelve true si son la misma fecha.
@param fecha1, fecha2
@return bool, true or false segun corresponda.
*/
bool compararFechas(Fecha fecha1, Fecha fecha2);

InformesMaker::InformesMaker() {}

void InformesMaker::mostrarInfomeRecaXPelicula() {
	Administrador admin;

	int idPelicula;

	std::cout << "LISTADO DE PELICULAS DISPONIBLES " << std::endl << std::endl;
	admin.verPeliculasCargadas();

	std::cout << "Por favor ingrese el ID de la pelicula: ";
	std::cin >> idPelicula;


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

	std::cout << "INGRESAR LA FECHA\n" << std::endl ;
	std::cout << "Ingrese el dia: ";
	std::cin >> dia;
	std::cout << "Ingrese el mes: ";
	std::cin >> mes;
	std::cout << "Ingrese el anio: ";
	std::cin >> anio;

	Fecha fechaInforme(dia, mes, anio);

	for (int i = 0; i < cantEntradas; i++) {
		entrada = archiEntrada.leerRegistro(i);	
		Fecha fechaEntrada = entrada.getFechaHora().getFecha();

		if (compararFechas(fechaEntrada, fechaInforme)) {
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

// Funcion comparar Fechas -- esto deberia ir en otra clase, despues lo acomodamos
bool compararFechas(Fecha fecha1, Fecha fecha2) {

	int dia1, dia2;
	int mes1, mes2;
	int anio1, anio2;

	dia1 = fecha1.getDia();
	dia2 = fecha2.getDia();

	mes1 = fecha1.getMes();
	mes2 = fecha2.getMes();

	anio1 = fecha1.getAnio();
	anio2 = fecha2.getAnio();

	if (dia1 == dia2 && mes1 == mes2 && anio1 == anio2) {
		return true;
	}
	else {
		return false;
	}
}