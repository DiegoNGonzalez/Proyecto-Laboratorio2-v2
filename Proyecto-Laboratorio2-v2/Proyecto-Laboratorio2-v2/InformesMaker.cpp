#include "InformesMaker.h"
#include "funcionesGlobales.h"


InformesMaker::InformesMaker() {}

void InformesMaker::mostrarInfomeRecaXPelicula() {
	Administrador admin;

	int idPelicula;

	std::cout << "LISTADO DE PELICULAS DISPONIBLES " << std::endl << std::endl;
	admin.verPeliculasCargadas();

	idPelicula = funcionesGlobales::validarMinimo(1, "Ingrese el numero de la pelicula: ", "ERROR. Ingrese un numero valido", "El numero debe ser mayor o igual a 1 ");

	Pelicula pelicula;
	ArchivoPeliculas archivoPeliculas("pelicula.dat");

	Entrada entrada;
	ArchivoEntrada archivoEntrada("venta.dat");

	int cantidadPeliculas = archivoPeliculas.contarRegistros();
	int cantidadEntradas = archivoEntrada.contarRegistros();

	float recaudacion = 0;

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

				system("cls");
				std::cout << "." << std::left << std::setw(31) << "_______________________________" << "." << std::endl;
				std::cout << "|" << std::left << std::setw(15) << "TITULO" << "|" << std::setw(15) << "RECAUDACION" << "|" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << pelicula.getTitulo() << "|" << std::setw(1) << "$" << std::setw(14) << recaudacion << "|" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << "_______________" << "|" << std::setw(15) << "_______________" << "|" << std::endl;
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

	float recaudacion = 0;

	std::cout << "INGRESAR LA FECHA\n" << std::endl;

	dia = funcionesGlobales::validarRango(1, 31, "Ingrese el dia: ", "ERROR. Ingrese un numero valido: ", "El numero debe ser mayor o igual a 1 ", "y menor o igual a 31");
	mes = funcionesGlobales::validarRango(1, 12, "Ingrese el mes: ", "ERROR. Ingrese un numero valido: ", "El numero debe ser mayor o igual a 1 ", "y menor o igual a 12");
	anio = funcionesGlobales::validarRango(2020, 2023, "Ingrese el anio: ", "ERROR. Ingrese un numero valido: ", "El numero debe ser mayor o igual a 2020 ", "y menor o igual a 2021");

	Fecha fechaInforme(dia, mes, anio);

	for (int i = 0; i < cantEntradas; i++) {
		entrada = archiEntrada.leerRegistro(i);
		Fecha fechaEntrada = entrada.getFechaHora().getFecha();

		if (funcionesGlobales::compararFechas(fechaEntrada, fechaInforme)) {
			recaudacion += entrada.getImporte();
		}
	}

	if (recaudacion > 0) {
		system("cls");
		std::cout << "\nRECAUDACION POR DIA" << std::endl;
		std::cout << " " << std::left << std::setw(26) << "__________________________" << "" << std::endl;
		std::cout << "|" << std::left << std::setw(10) << "FECHA" << " |" << std::setw(14) << "  RECAUDACION" << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(0) << dia << "/" << mes << "/" << anio << " |" << std::setw(3) << "  $" << std::setw(11) << recaudacion << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(26) << "__________________________" << "|" << std::endl;
		std::cout << std::endl;
	}
	else {
		fechaInforme.mostrarFecha();
		std::cout << "\nNo se vendieron entradas" << std::endl;
	}

}

void InformesMaker::mostrarInformeRecaXMes() {
	float recaudacion = 0;
	int mesInforme;
	mesInforme = funcionesGlobales::validarRango(1, 12, "Ingrese el mes: ", "ERROR. Ingrese un mes valido: ", "El numero debe ser mayor o igual a 1 ", "y menor o igual a 12");

	ArchivoEntrada archiEntrada("venta.dat");
	Entrada entrada;
	int cantidadEntradas = archiEntrada.contarRegistros();

	for (int i = 0; i < cantidadEntradas; i++) {
		entrada = archiEntrada.leerRegistro(i);

		int mesEntrada = entrada.getFechaHora().getFecha().getMes();

		if (mesInforme == mesEntrada) {
			recaudacion += entrada.getImporte();
		}
	}

	if (recaudacion > 0) {
		system("cls");
		std::cout << "RECAUDACION MENSUAL " << std::endl;

		std::cout << "." << std::left << std::setw(15) << "_______________" << "_" << std::setw(15) << "_______________" << "." << std::endl;
		std::cout << "|" << std::left << std::setw(15) << "MES" << "|" << std::setw(15) << "RECAUDACION" << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(15) << funcionesGlobales::escribirMes(mesInforme) << "|" << std::setw(1) << "$" << std::setw(14) << recaudacion << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(15) << "_______________" << "|" << std::setw(15) << "_______________" << "|" << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "No se vendieron entradas en " << funcionesGlobales::escribirMes(mesInforme) << std::endl;
	}

}

void InformesMaker::mostrarInformeRecaXAnio() {
	float recaudacion = 0;
	int anioInforme = funcionesGlobales::validarRango(2020, 2023, "Ingrese el anio: ", "ERROR. Ingrese un anio valido: ", "El numero debe ser mayor o igual a 2020 ", "y menor o igual a 2023");

	ArchivoEntrada archiEntrada("venta.dat");
	Entrada entrada;
	int cantidadEntradas = archiEntrada.contarRegistros();

	for (int i = 0; i < cantidadEntradas; i++) {
		entrada = archiEntrada.leerRegistro(i);
		int anioEntrada = entrada.getFechaHora().getFecha().getAnio();

		if (anioInforme == anioEntrada) {
			recaudacion += entrada.getImporte();
		}
	}

	if (recaudacion > 0) {
		system("cls");
		std::cout << "RECAUDACION ANUAL" << std::endl;

		std::cout << "." << std::left << std::setw(15) << "_______________" << "_" << std::setw(15) << "_______________" << "." << std::endl;
		std::cout << "|" << std::left << std::setw(15) << "ANIO" << "|" << std::setw(15) << "RECAUDACION" << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(15) << anioInforme << "|" << std::setw(1) << "$" << std::setw(14) << recaudacion << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(15) << "_______________" << "|" << std::setw(15) << "_______________" << "|" << std::endl;
		std::cout << std::endl;

	}
	else {
		std::cout << "No se vendieron entradas en " << anioInforme << std::endl;
	}
}

void InformesMaker::mostrarInformeFranjasHorarias() {
	//primera franja 12 a 15hs
	//segunda franja 15 a 17hs
	//tercera franja 17 a 20hs
	//cuarta franja 20 a 23hs
	//quinta franja 23 a 1hs

	ArchivoEntrada archiEntrada("venta.dat");
	Entrada entrada;

	int cantidadEntradas = archiEntrada.contarRegistros();

	int cantEntradasFranja1 = 0;
	int cantEntradasFranja2 = 0;
	int cantEntradasFranja3 = 0;
	int cantEntradasFranja4 = 0;
	int cantEntradasFranja5 = 0;

	float recaudacionFranja1 = 0;
	float recaudacionFranja2 = 0;
	float recaudacionFranja3 = 0;
	float recaudacionFranja4 = 0;
	float recaudacionFranja5 = 0;

	int fhMax = -1;
	float recaudacionMax = -1;
	std::string mensaje = "<- Franja horaria con mayor recaudacion";

	for (int i = 0; i < cantidadEntradas; i++) {
		entrada = archiEntrada.leerRegistro(i);
		int horaEntrada = entrada.getFechaHora().getHorario().getHora();

		if (horaEntrada >= 12 && horaEntrada < 15) {
			cantEntradasFranja1++;
			recaudacionFranja1 += entrada.getImporte();
		}
		else if (horaEntrada >= 15 && horaEntrada < 17) {
			cantEntradasFranja2++;
			recaudacionFranja2 += entrada.getImporte();
		}
		else if (horaEntrada >= 17 && horaEntrada < 20) {
			cantEntradasFranja3++;
			recaudacionFranja3 += entrada.getImporte();
		}
		else if (horaEntrada >= 20 && horaEntrada < 23) {
			cantEntradasFranja4++;
			recaudacionFranja4 += entrada.getImporte();
		}
		else if (horaEntrada >= 23 && horaEntrada < 1) {
			cantEntradasFranja5++;
			recaudacionFranja5 += entrada.getImporte();
		}
	}

	float porcentajeFranja1 = (cantEntradasFranja1 * 100) / cantidadEntradas;
	float porcentajeFranja2 = (cantEntradasFranja2 * 100) / cantidadEntradas;
	float porcentajeFranja3 = (cantEntradasFranja3 * 100) / cantidadEntradas;
	float porcentajeFranja4 = (cantEntradasFranja4 * 100) / cantidadEntradas;
	float porcentajeFranja5 = (cantEntradasFranja5 * 100) / cantidadEntradas;

	if (fhMax == -1) {
		fhMax = 1;
		recaudacionMax = recaudacionFranja1;
	}
	if (recaudacionMax < recaudacionFranja2) {
		fhMax = 2;
		recaudacionMax = recaudacionFranja2;
	}
	if (recaudacionMax < recaudacionFranja3) {
		fhMax = 3;
		recaudacionMax = recaudacionFranja3;
	}
	if (recaudacionMax < recaudacionFranja4) {
		fhMax = 4;
		recaudacionMax = recaudacionFranja4;
	}
	if (recaudacionMax < recaudacionFranja5) {
		fhMax = 5;
	}


	std::cout << "INFORME DE FRANJAS HORARIAS" << std::endl;

	std::cout << "." << std::left << std::setw(16) << "________________" << "_" << std::setw(15) << "_______________" << "_" << std::setw(12) << "____________" << "_" << std::setw(8) << "________" << "." << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "FRANJA HORARIA" << "|" << std::setw(15) << "CANT ENTRADAS" << "|" << std::setw(12) << "RECAUDACION" << "|" << std::setw(8) << " % REC" << "|" << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "12hs - 15 hs" << "|" << std::setw(15) << cantEntradasFranja1 << "|" << std::setw(12) << recaudacionFranja1 << "|" << std::setw(8) << porcentajeFranja1 << "|" << (fhMax == 1 ? mensaje : "") << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "15hs - 17 hs" << "|" << std::setw(15) << cantEntradasFranja2 << "|" << std::setw(12) << recaudacionFranja2 << "|" << std::setw(8) << porcentajeFranja2 << "|" << (fhMax == 2 ? mensaje : "") << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "17hs - 20 hs" << "|" << std::setw(15) << cantEntradasFranja3 << "|" << std::setw(12) << recaudacionFranja3 << "|" << std::setw(8) << porcentajeFranja3 << "|" << (fhMax == 3 ? mensaje : "") << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "20hs - 23 hs" << "|" << std::setw(15) << cantEntradasFranja4 << "|" << std::setw(12) << recaudacionFranja4 << "|" << std::setw(8) << porcentajeFranja4 << "|" << (fhMax == 4 ? mensaje : "") << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "23hs - 01 hs" << "|" << std::setw(15) << cantEntradasFranja5 << "|" << std::setw(12) << recaudacionFranja5 << "|" << std::setw(8) << porcentajeFranja5 << "|" << (fhMax == 5 ? mensaje : "") << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "________________" << "|" << std::setw(15) << "_______________" << "|" << std::setw(12) << "____________" << "|" << std::setw(8) << "________" << "|" << std::endl;
	std::cout << std::endl;
}
