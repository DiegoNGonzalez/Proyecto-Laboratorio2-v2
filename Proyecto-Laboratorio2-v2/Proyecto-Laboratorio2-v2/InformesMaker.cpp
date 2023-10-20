#include "InformesMaker.h"

InformesMaker::InformesMaker() {}

void InformesMaker::mostrarInfomeRecaXPelicula() {
	Administrador admin;

	int idPelicula;

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
				//uso la libreria iomanip para que se muestre como una tabla
				std::cout << " " << std::left << std::setw(36) << "____________________________________" <<""<< std::endl;
				std::cout << "|" << std::left << std::setw(15) << "TITULO" << "|" << std::setw(4) << "ID" << "|" << std::setw(15) << "RECAUDACION" << "|" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << pelicula.getTitulo() << "|" << std::setw(4) << idPelicula << "|" << std::setw(1) <<"$" << std::setw(14) << recaudacion << "|" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << "_______________" << "|" << std::setw(4) << "____" << "|" << std::setw(15) << "_______________" << "|" << std::endl;
			}

		}

	}


}