﻿#include "Sistema.h"
#include <iostream>
#include <filesystem>
#include <string>
#include "Windows.h"
#include <conio.h>
#include "InformesMaker.h"
#include "funcionesGlobales.h"


Sistema::Sistema()
{
	_admin1 = Administrador(01, "DT", "Juan Roman", "Riquelme", "Admin", "qwerty");
	_vendedor1 = Vendedor(02, "Vendedor", "Lionel", "Messi", "Vendedor", "1234");
	_fechaHorario = FechaHorario();
}

Administrador Sistema::getAdmin() const {
	return _admin1;
}

Vendedor Sistema::getVendedor() const {
	return _vendedor1;
}

//funcion login

void Sistema::login(Administrador admin1, Vendedor vendedor1) {

	std::string usuario;
	std::string contrasenia;
	int intentos = 0;
	bool login = false;
	rlutil::setConsoleTitle("LOGIN - SISTEMA DE CINE");
	do {
		system("cls");
		rlutil::setColor(rlutil::COLOR::LIGHTBLUE);
		rlutil::locate(50, 10);
		std::cout << "Usuario: ";
		std::cin >> usuario;
		rlutil::locate(50, 11);
		std::cout << "Contraseña: ";
		//cin >> contrasenia;
		contrasenia = "";
		char caracter;
		while (true) {
			caracter = _getch(); // Capturamos un carácter sin mostrarlo en pantalla

			if (caracter == 13) // 13 es el código ASCII de la tecla Enter, terminamos cuando se presiona Enter
				break;
			else if (caracter == 8) { // 8 es el código ASCII de la tecla Retroceso, para borrar un carácter
				if (contrasenia.length() > 0) {
					std::cout << "\b \b"; // Borramos el carácter en pantalla y retrocedemos el cursor
					contrasenia.pop_back(); // Eliminamos el último carácter de la contraseña
				}
			}
			else {
				contrasenia += caracter; // Agregamos el carácter a la contraseña
				std::cout << "*"; // Mostramos un asterisco en lugar del carácter
			}
		}
		if (usuario == admin1.getUsuario() && contrasenia == admin1.getContrasenia()) {
			std::cout << std::endl;
			rlutil::locate(50, 12);
			std::cout << "Validando credenciales..." << std::endl;
			Sleep(1500);
			rlutil::locate(50, 13);
			std::cout << "Bienvenido " << admin1.getNombre() << " " << admin1.getApellido() << std::endl;
			login = true;
			Sleep(1000);
			rlutil::locate(50, 14);
			system("pause");
			system("cls");
			mostrarMenuAdmin();
		}
		else if (usuario == vendedor1.getUsuario() && contrasenia == vendedor1.getContrasenia()) {
			std::cout << std::endl;
			rlutil::locate(50, 12);
			std::cout << "Validando credenciales..." << std::endl;
			Sleep(1500);
			rlutil::locate(50, 13);
			std::cout << "Bienvenido " << vendedor1.getNombre() << " " << vendedor1.getApellido() << std::endl;
			login = true;
			Sleep(1000);
			rlutil::locate(50, 14);
			system("pause");
			system("cls");
			mostrarMenuVendedor();
		}
		else {
			std::cout << std::endl;
			rlutil::locate(50, 12);
			std::cout << "Validando credenciales..." << std::endl;
			Sleep(1500);
			rlutil::locate(50, 13);
			std::cout << "Usuario o contraseña incorrectos" << std::endl;
			intentos++;
			Sleep(1000);
			rlutil::locate(50, 14);
			system("pause");
			system("cls");
		}
	} while (intentos < 3 && login == false);
	rlutil::setColor(rlutil::COLOR::WHITE);
}


void Sistema::mostrarMenuAdmin() {

	int op = 1, y = 0;
	Funcion f1;
	ArchivoFunciones archiFunciones("funcion.dat");
	do {
		rlutil::setConsoleTitle("MENU ADMINISTRACIÓN CINE"); // establece el titulo de la consola
		rlutil::hidecursor(); // oculta el cursor

		funcionesGlobales::showItem(" PELICULAS ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada
		funcionesGlobales::showItem(" SALAS ", 50, 11, y == 1);
		funcionesGlobales::showItem(" FUNCIONES ", 50, 12, y == 2);
		funcionesGlobales::showItem(" BACKUP ", 50, 13, y == 3);
		funcionesGlobales::showItem(" INFORMES ", 50, 14, y == 4); // ---- NUEVO MENU INFORMES
		funcionesGlobales::showItem(" LISTADOS", 50, 15, y == 5); // ---- NUEVO MENU LISTADOS
		funcionesGlobales::showItem(" Cerrar sesion ", 50, 16, y == 6); // Pase cerrar sesion para abajo, cambia y == 4 a y ==5
		funcionesGlobales::showItem("  SALIR   ", 50, 17, y == 7); // mismo comentario linea anterior

		int key = rlutil::getkey(); // devuelve un código ASCII de tecla.



		switch (key) // evalua el codigo de tecla
		{
		case 14: // flecha ARRIBA
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl; // imprime un espacio para borrar la flecha cuando cambie de posicion
			y--;
			if (y < 0) y = 0; // validacion para que no se salga de las opciones
			break;
		case 15: // flecha ABAJO
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y++;
			if (y > 7) y = 7; // -- OPCIONES DISPONIBLES
			break;
		case 1: // ENTER
			switch (y)
			{
			case 0: {
				system("cls");
				menuPeliculas();
				system("cls");
				break;
			}
			case 1:
				system("cls");
				menuSalas();
				system("cls");
				break;
			case 2:
				system("cls");
				menuFunciones();
				system("cls");
				break;
			case 3:
				system("cls");
				menuBackUp();
				system("cls");
				break;
			case 4: // ---- NUEVO MENU INFORMES
				system("cls");
				mostrarMenuInformes();
				system("cls");
				break;
			case 5:	// --- NUEVO MENU LISTADOS
				system("cls");
				mostrarMenuListados();
				system("cls");
				break;
			case 6:
				login(_admin1, _vendedor1);
				op = 0;
				break;
			case 7: // Si el cursor esta en la opcion SALIR		// -- tambien cambie el case de 5 a 6
				system("cls");
				rlutil::locate(50, 16);
				std::cout << "SALIENDO DEL PROGRAMA . . ." << std::endl;
				Sleep(1000);
				op = 0; // sale del programa
				break;
			}
		}
	} while (op != 0);



}

void Sistema::mostrarMenuVendedor() {
	DiagramaSala diagramaSala;
	ArchivoDiagrama archiDiagrama("diagrama.dat");
	ArchivoFunciones archiFunciones("funcion.dat");
	ArchivoEntrada archiVenta("venta.dat");
	int op = 1, y = 0;
	Funcion funcionAuxiliar;
	int idFuncion, idEntrada;
	do {
		rlutil::setConsoleTitle("MENU VENDEDOR CINE");
		rlutil::hidecursor();

		funcionesGlobales::showItem(" FUNCIONES CARGADAS ", 50, 10, y == 0);
		funcionesGlobales::showItem(" MOSTRAR SALA DE CINE ", 50, 11, y == 1);
		funcionesGlobales::showItem(" VENTA DE ASIENTO ", 50, 12, y == 2);
		funcionesGlobales::showItem(" CANCELAR VENTA DE ASIENTO ", 50, 13, y == 3);
		funcionesGlobales::showItem(" VER VENTAS ", 50, 14, y == 4);
		funcionesGlobales::showItem(" CERRAR SESION ", 50, 15, y == 5);
		funcionesGlobales::showItem("  SALIR   ", 50, 16, y == 6);

		int key = rlutil::getkey(); 



		switch (key) 
		{
		case 14:
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y--;
			if (y < 0) y = 0;
			break;
		case 15:
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y++;
			if (y > 6) y = 6;
			break;
		case 1:
			switch (y)
			{
			case 0: {
				system("cls");
				_admin1.verFuncionesCargadas();
				system("pause");
				system("cls");
				break;
			}
			case 1: {
				system("cls");
				idFuncion = funcionesGlobales::validarMinimo(1, "INGRESE EL NRO DE LA FUNCION: ", "INGRESO NO VALIDO, REINGRESE UN NRO DE FUNCION: ", "EL NRO DE FUNCION DEBE SER MAYOR O IGUAL A 1: ");
				int pos = archiDiagrama.buscarPosDiagramaxID(idFuncion);
				if (pos != -1) {
					archiDiagrama.mostrarRegistro(pos);
				}
				else {
					system("pause");
				}
				system("cls");

				break;
			}
			case 2: {
				system("cls");
				idFuncion = funcionesGlobales::validarMinimo(1, "INGRESE EL NRO DE LA FUNCION A VENDER UN ASIENTO: ", "INGRESO NO VALIDO, REINGRESE UN NRO DE FUNCION: ", "EL NRO DE FUNCION DEBE SER MAYOR O IGUAL A 1: ");
				int pos = archiDiagrama.buscarPosDiagramaxID(idFuncion);
				if (pos != -1) {
					_vendedor1.venderEntradas(idFuncion);
					std::cout << std::endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				archiVenta.verVentasCargadas();
				idEntrada = funcionesGlobales::validarMinimo(1, "NRO DE LA VENTA A CANCELAR: ", "INGRESO NO VALIDO, REINGRESE UN NRO DE FUNCION: ", "EL NRO DE FUNCION DEBE SER MAYOR O IGUAL A 1: ");
				int pos = archiVenta.buscarPosEntradaxID(idEntrada);
				if (pos != -1) {
					_vendedor1.cancelarVenta(idEntrada);
				}
				system("pause");
				system("cls");

				break;
			}
			case 4: {
				system("cls");
				archiVenta.verVentasCargadas();
				system("pause");
				system("cls");
				break;
			}
			case 5:
				login(_admin1, _vendedor1);
				op = 0;
				break;
			case 6:
				op = 0;
				break;
			}
		}
	} while (op != 0);
}

void Sistema::mostrarMenuInformes() { // NUEVO MENU INFORMES
	Pelicula pelicula;
	ArchivoPeliculas archiPeliculas("peliculas.dat");
	char nombrePelicula[30];

	InformesMaker informesMaker;

	int op = 1, y = 0;
	do {
		rlutil::setConsoleTitle("MENU INFORMES");
		rlutil::hidecursor();

		funcionesGlobales::showItem(" 1- Total Recaudado por pelicula", 50, 10, y == 0);
		funcionesGlobales::showItem(" 2- Total recaudado por dia ", 50, 11, y == 1);
		funcionesGlobales::showItem(" 3- Total recaudado por mes ", 50, 12, y == 2);
		funcionesGlobales::showItem(" 4- Total recaudado anual", 50, 13, y == 3);
		funcionesGlobales::showItem(" 5- Total recaudado por franja horaria", 50, 14, y == 4);
		funcionesGlobales::showItem(" Volver", 50, 15, y == 5);

		int key = rlutil::getkey();

		switch (key)
		{
		case 14:
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y--;
			if (y < 0) y = 0;
			break;
		case 15:												    
			rlutil::locate(28, 11 + y);
			std::cout << " " << std::endl;
			y++;
			if (y > 5) y = 5;
			break;
		case 1:
			switch (y)
			{
			case 0: {
				system("cls");
				informesMaker.mostrarInfomeRecaXPelicula();
				system("pause");
				system("cls");
				break;
			}
			case 1: {
				system("cls");
				informesMaker.mostrarInformeRecaXDia();
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				system("cls");
				informesMaker.mostrarInformeRecaXMes();
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				informesMaker.mostrarInformeRecaXAnio();
				system("pause");
				system("cls");
				break;
			}
			case 4: {
				system("cls");
				informesMaker.mostrarInformeFranjasHorarias();
				system("pause");
				system("cls");
				break;
			}
			case 5:
				op = 0;
				break;
			}

		}
	} while (op != 0);
}
void Sistema::mostrarMenuListados() {

	ArchivoEntrada archiventa("venta.dat");


	int op = 1, y = 0;
	do {
		rlutil::setConsoleTitle("MENU LISTADOS");
		rlutil::hidecursor();

		funcionesGlobales::showItem("LISTADO PELICULAS", 50, 10, y == 0);
		funcionesGlobales::showItem("LISTADO FUNCIONES", 50, 11, y == 1);
		funcionesGlobales::showItem("LISTADO SALAS", 50, 12, y == 2);
		funcionesGlobales::showItem("LISTADO VENTAS", 50, 13, y == 3);
		funcionesGlobales::showItem("LISTADO EMPLEADOS", 50, 14, y == 4);
		funcionesGlobales::showItem(" Volver", 50, 15, y == 5);

		int key = rlutil::getkey();

		switch (key)
		{
		case 14:
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y--;
			if (y < 0) y = 0;
			break;
		case 15:												    
			rlutil::locate(28, 11 + y);
			std::cout << " " << std::endl;
			y++;
			if (y > 5) y = 5;
			break;
		case 1:
			switch (y)
			{
			case 0: {
				system("cls");
				std::cout << "LISTADO PELICULAS " << std::endl;
				_admin1.verPeliculasCargadas();

				system("pause");
				system("cls");
				break;
			}
			case 1: {
				system("cls");
				std::cout << "LISTADO FUNCIONES" << std::endl;
				_admin1.verFuncionesCargadas();

				system("pause");
				system("cls");
				break;
			}
			case 2: {
				system("cls");
				std::cout << "LISTADO SALAS" << std::endl;
				_admin1.verSalasCargadas();
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				std::cout << "LISTADO VENTAS" << std::endl;;

				archiventa.verVentasCargadas();

				system("pause");
				system("cls");
				break;
			}
			case 4: {
				system("cls");
				std::cout << "LISTADO EMPLEADOS" << std::endl;
				mostrarListadoEmpleados();
				system("pause");
				system("cls");
				break;
			}
			case 5:
				op = 0;
				break;
			}

		}
	} while (op != 0);
}
void Sistema::menuPeliculas() {
	int op = 1, y = 0;
	ArchivoPeliculas archiPeliculas("pelicula.dat");

	do {
		rlutil::setConsoleTitle("MENU PELICULAS");
		rlutil::hidecursor();

		funcionesGlobales::showItem(" INGRESAR NUEVA PELICULA A CARTELERA ", 50, 10, y == 0);
		funcionesGlobales::showItem(" VER PELICULAS EN CARTELERA ", 50, 11, y == 1);
		funcionesGlobales::showItem(" BUSCAR PELICULA", 50, 12, y == 2);
		funcionesGlobales::showItem(" ELIMINAR PELICULA DE LA CARTELERA ", 50, 13, y == 3);
		funcionesGlobales::showItem(" Volver ", 50, 14, y == 4);

		int key = rlutil::getkey();



		switch (key)
		{
		case 14:
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y--;
			if (y < 0) y = 0;
			break;
		case 15:
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y++;
			if (y > 4) y = 4;
			break;
		case 1:
			switch (y)
			{
			case 0: {
				system("cls");
				_admin1.cargarPeliculas();
				system("cls");
				break;
			}
			case 1:
				system("cls");
				_admin1.verPeliculasCargadas();
				system("pause");
				system("cls");
				break;

			case 2: {
				system("cls");
				int id, pos;
				id = funcionesGlobales::validarMinimo(1, "NRO DE PELICULA A BUSCAR: ", "Lo ingresado no es un numero, reingrese un numero: ", "El numero tiene que ser mayor o igual a 1, reingrese: ");
				pos = archiPeliculas.buscarPosPeliculaxID(id);
				if (pos >= 0) {
					system("cls");
					_admin1.buscarPeliculaxID(id).mostrarDetalles();
				}

				system("pause");
				system("cls");
				break;
			}
			case 3:
				system("cls");
				_admin1.darDeBajaPelicula();
				system("pause");
				system("cls");
				break;
			case 4:
				op = 0;
				break;
			}
		}
	} while (op != 0);
}
void Sistema::menuSalas() {
	int op = 1, y = 0;
	ArchivoSalas archiSalas("sala.dat");
	do {
		rlutil::setConsoleTitle("MENU SALAS");
		rlutil::hidecursor();

		funcionesGlobales::showItem(" INGRESAR SALA ", 50, 10, y == 0);
		funcionesGlobales::showItem(" VER SALAS DISPONIBLES", 50, 11, y == 1);
		funcionesGlobales::showItem(" MODIFICAR PRECIO DE SALA ", 50, 12, y == 2);
		funcionesGlobales::showItem(" ELIMINAR SALA ", 50, 13, y == 3);
		funcionesGlobales::showItem(" Volver ", 50, 14, y == 4);

		int key = rlutil::getkey();

		switch (key)
		{
		case 14: 
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y--;
			if (y < 0) y = 0; 
			break;
		case 15: 
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y++;
			if (y > 4)y = 4;
			break;
		case 1: 
			switch (y)
			{
			case 0: {
				system("cls");
				_admin1.cargarSalas();
				system("cls");
				break;
			}
			case 1:
				system("cls");
				_admin1.verSalasCargadas();
				system("pause");
				system("cls");
				break;
			case 2: {
				system("cls");
				int nroSala, posSala;
				_admin1.verSalasCargadas();
				nroSala = funcionesGlobales::validarMinimo(1, "NRO DE SALA A CAMBIAR PRECIO: ", "INGRESO NO VALIDO, REINGRESE UN NRO DE SALA: ", "EL NRO DE SALA DEBE SER MAYOR O IGUAL A 1: ");
				system("cls");
				posSala = archiSalas.buscarPosSalaxID(nroSala);
				if (posSala != -1) {
					_admin1.modificarSalaEnRegistro(nroSala);
				}
				system("pause");
				system("cls");
				break;
			}
			case 3:
				system("cls");
				_admin1.verSalasCargadas();
				_admin1.darDeBajaSala();
				system("pause");
				system("cls");
				break;
			case 4:
				op = 0; 
				break;
			}
		}
	} while (op != 0);
}
void Sistema::menuFunciones() {
	ArchivoFunciones archiFunciones("funcion.dat");
	int op = 1, y = 0;

	do {
		rlutil::setConsoleTitle("MENU FUNCIONES"); 
		rlutil::hidecursor(); 

		funcionesGlobales::showItem(" INGRESAR FUNCION ", 50, 10, y == 0);
		funcionesGlobales::showItem(" VER FUNCIONES DISPONIBLES ", 50, 11, y == 1);
		funcionesGlobales::showItem(" BUSCAR FUNCION ", 50, 12, y == 2);
		funcionesGlobales::showItem(" MODIFICAR FUNCION ", 50, 13, y == 3);
		funcionesGlobales::showItem(" ELIMINAR FUNCION ", 50, 14, y == 4);
		funcionesGlobales::showItem(" Volver ", 50, 15, y == 5);

		int key = rlutil::getkey(); 
		switch (key) 
		{
		case 14: 
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl; 
			y--;
			if (y < 0) y = 0; 
			break;
		case 15: 
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y++;
			if (y > 5) y = 5;
			break;
		case 1: 
			switch (y)
			{
			case 0: {
				system("cls");
				_admin1.cargarFunciones();
				system("cls");
				break;
			}
			case 1:
				system("cls");
				_admin1.verFuncionesCargadas();
				system("pause");
				system("cls");
				break;
			case 2: {
				system("cls");
				int id;
				id = funcionesGlobales::validarMinimo(1, "NRO DE FUNCION A BUSCAR: ", "INGRESO NO VALIDO, REINGRESE NRO DE FUNCION A BUSCAR: ", "EL NRO DE FUNCION TIENE QUE SER MAYOR A 0, REINGRESE NRO DE FUNCION A BUSCAR: ");
				if (archiFunciones.buscarFuncionxID(id).getEstado()) {
					system("cls");
					archiFunciones.buscarFuncionxID(id).mostrarDetalles();
				}
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				int id;
				id = funcionesGlobales::validarMinimo(1, "NRO DE FUNCION A MODIFICAR: ", "INGRESO NO VALIDO, REINGRESE NRO DE FUNCION A MODIFICAR: ", "EL NRO DE FUNCION TIENE QUE SER MAYOR A 0, REINGRESE NRO DE FUNCION A MODIFICAR: ");
				_admin1.modificarFuncionEnRegistro(id);
				system("cls");
				break;
			}
			case 4: {
				system("cls");
				_admin1.verFuncionesCargadas();
				_admin1.darDeBajaFuncion();
				system("pause");
				system("cls");
				break;
			}
			case 5: 
				op = 0; 
				break;
			}
		}
	} while (op != 0);



}
void Sistema::menuBackUp() {
	int op = 1, y = 0;
	ArchivoDiagrama archiDiagrama("diagrama.dat");
	ArchivoPeliculas archiPeliculas("pelicula.dat");
	ArchivoSalas archiSalas("sala.dat");
	ArchivoFunciones archiFunciones("funcion.dat");
	ArchivoEntrada archiEntrada("venta.dat");
	do {
		rlutil::setConsoleTitle("MENU BACKUP"); 
		rlutil::hidecursor(); 

		funcionesGlobales::showItem(" GENERAR BACKUP PELICULAS ", 50, 10, y == 0);
		funcionesGlobales::showItem(" RECUPERAR BACKUP PELICULAS ", 50, 11, y == 1);
		funcionesGlobales::showItem(" GENERAR BACKUP SALAS ", 50, 12, y == 2);
		funcionesGlobales::showItem(" RECUPERAR BACKUP SALAS ", 50, 13, y == 3);
		funcionesGlobales::showItem(" GENERAR BACKUP FUNCIONES ", 50, 14, y == 4);
		funcionesGlobales::showItem(" RECUPERAR BACKUP FUNCIONES ", 50, 15, y == 5);
		funcionesGlobales::showItem(" GENERAR BACKUP GRAFICOS SALA ", 50, 16, y == 6);
		funcionesGlobales::showItem(" RECUPERAR BACKUP GRAFICOS SALA ", 50, 17, y == 7);
		funcionesGlobales::showItem(" GENERAR BACKUP VENTAS ", 50, 18, y == 8);
		funcionesGlobales::showItem(" RECUPERAR BACKUP VENTAS ", 50, 19, y == 9);
		funcionesGlobales::showItem(" Volver ", 50, 20, y == 10);

		int key = rlutil::getkey(); 
		switch (key) 
		{
		case 14: 
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl; 
			y--;
			if (y < 0) y = 0; 
			break;
		case 15: 
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y++;
			if (y > 10) y = 10;
			break;
		case 1: 
			switch (y)
			{
			case 0: {
				system("cls");
				archiPeliculas.generarBackUp();
				system("cls");
				break;
			}
			case 1:
				system("cls");
				archiPeliculas.restaurarBackUp();
				system("cls");
				break;
			case 2:
				system("cls");
				archiSalas.generarBackUp();
				system("cls");
				break;
			case 3:
				system("cls");
				archiSalas.restaurarBackUp();
				system("cls");
				break;
			case 4:
				system("cls");
				archiFunciones.generarBackUp();
				system("cls");
				break;
			case 5:
				system("cls");
				archiFunciones.restaurarBackUp();
				system("cls");
				break;
			case 6:
				system("cls");
				archiDiagrama.generarBackUp();
				system("cls");
				break;
			case 7:
				system("cls");
				archiDiagrama.restaurarBackUp();
				system("cls");
				break;
			case 8:
				system("cls");
				archiEntrada.generarBackUp();
				system("cls");
				break;
			case 9:
				system("cls");
				archiEntrada.restaurarBackUp();
				system("cls");
				break;
			case 10: 
				op = 0; 
				break;
			}

		}
	} while (op != 0);
}
void Sistema::bienvenida() {
	rlutil::setConsoleTitle("SISTEMA DE CINE");
	rlutil::setColor(rlutil::COLOR::LIGHTBLUE);
	rlutil::hidecursor();
	rlutil::locate(50, 10);
	std::cout << "BIENVENIDO AL SISTEMA DE CINE" << std::endl;
	Sleep(1000);
	rlutil::locate(50, 11);
	std::cout << "Cargando archivos." << std::endl;
	Sleep(1000);
	rlutil::locate(50, 12);
	std::cout << "Cargando archivos.." << std::endl;
	Sleep(1000);
	rlutil::locate(50, 13);
	std::cout << "Cargando archivos..." << std::endl;
	Sleep(1000);
	if (crearDirectorioBackUP()) {
		rlutil::locate(50, 14);
		std::cout << "Directorio de BackUp creado correctamente" << std::endl;
	}
	else {
		rlutil::locate(50, 14);
		std::cout << "Directorio de BackUp ya existente" << std::endl;
	}
	Sleep(1000);
	rlutil::locate(50, 15);
	system("pause");
	rlutil::setColor(rlutil::COLOR::WHITE);
	system("cls");
}




bool Sistema::crearDirectorioBackUP() {
	bool creado = false;
	std::string ruta = "backUp/";
	if (std::filesystem::is_directory(ruta)) {
		return false;
	}
	else {
		creado = std::filesystem::create_directory(ruta);
	}
	return creado;
}

void Sistema::creditos()
{
	system("cls");
	rlutil::setConsoleTitle("CREDITOS");
	rlutil::setColor(rlutil::COLOR::WHITE);
	rlutil::locate(40, 7);
	std::cout << "DISEÑADO Y DESARROLLADO POR: " << std::endl;
	rlutil::locate(40, 9);
	std::cout << "-----------------------------------------" << std::endl;
	rlutil::locate(40, 10);
	std::cout << "Bombieri Rodrigo Sebastián. " << std::endl;
	rlutil::locate(40, 11);
	std::cout << "Github: " << "https://github.com/RodrigoBombieri" << std::endl;
	rlutil::locate(40, 12);
	std::cout << "Linkedin: " << "https://www.linkedin.com/in/rodrigobombieri-dev/" << std::endl;
	rlutil::locate(40, 13);
	std::cout << "Email: " << "rodrigo.bombieri@alumnos.frgp.utn.edu.ar" << std::endl;
	rlutil::locate(40, 14);
	std::cout << "-----------------------------------------" << std::endl;
	rlutil::locate(40, 15);
	std::cout << "Caceres Tomas. " << std::endl;
	rlutil::locate(40, 16);
	std::cout << "Github: " << "https://github.com/tomyok" << std::endl;
	rlutil::locate(40, 17);
	std::cout << "Linkedin: " << "https://www.linkedin.com/in/cacerestomas/" << std::endl;
	rlutil::locate(40, 18);
	std::cout << "Email: " << "tomas.caceres2@alumnos.frgp.utn.edu.ar" << std::endl;
	rlutil::locate(40, 19);
	std::cout << "-----------------------------------------" << std::endl;
	rlutil::locate(40, 20);
	std::cout << "Damonte Agustin. " << std::endl;
	rlutil::locate(40, 21);
	std::cout << "Github: " << "https://github.com/agudamonte" << std::endl;
	rlutil::locate(40, 22);
	std::cout << "Linkedin: " << "https://www.linkedin.com/in/agustindamonte/" << std::endl;
	rlutil::locate(40, 23);
	std::cout << "Email: " << "agustin.damonte@frgp.utn.edu.ar" << std::endl;
	rlutil::locate(40, 24);
	std::cout << "-----------------------------------------" << std::endl;
	rlutil::locate(40, 25);
	std::cout << "Gonzalez Valenzuela Diego. " << std::endl;
	rlutil::locate(40, 26);
	std::cout << "Github: " << "https://github.com/DiegoNGonzalez" << std::endl;
	rlutil::locate(40, 27);
	std::cout << "Linkedin: " << "https://www.linkedin.com/in/diegongonzalez/" << std::endl;
	rlutil::locate(40, 28);
	std::cout << "Email: " << "diego.gonzalez2@frgp.utn.edu.ar" << std::endl;
	rlutil::locate(40, 29);
	std::cout << "-----------------------------------------" << std::endl;
	rlutil::locate(40, 30);
	std::cout << "GRACIAS POR UTILIZAR NUESTRO SISTEMA" << std::endl;
	Sleep(2000);
	rlutil::setColor(rlutil::COLOR::WHITE);
}

void Sistema::verificarFechaYHoraFunciones()
{

	ArchivoFunciones archiFunciones("funcion.dat");
	Funcion funcionAuxiliar;
	int cantidaReg = archiFunciones.contarRegistros();
	for (int i = 0; i < cantidaReg; i++) {
		funcionAuxiliar = archiFunciones.leerRegistro(i);
		if (funcionAuxiliar.getEstado() && funcionAuxiliar.getFechaHoraFuncion() < _fechaHorario) {
			funcionAuxiliar.setEstado(false);
			archiFunciones.grabarRegistro(funcionAuxiliar, i);
		}
	}

}

void Sistema::mostrarListadoEmpleados() {

	std::cout << std::left << "." << std::setw(10) << "_________" << "." << std::setw(20) << "___________________" << "." << std::setw(20) << "___________________" << "." << std::setw(20) << "___________________" << "." << std::endl;
	std::cout << "|" << std::left << std::setw(10) << "LEGAJO" << "|" << std::setw(20) << "NOMBRE" << "|" << std::setw(20) << "APELLIDO" << "|" << std::setw(20) << "CARGO" << "|" << std::endl;
	std::cout << std::left << "|" << std::setw(10) << _admin1.getLegajo() << "|" << std::setw(20) << _admin1.getNombre() << "|" << std::setw(20) << _admin1.getApellido() << "|" << std::setw(20) << _admin1.getUsuario() << "|" << std::endl;

	std::cout << std::left << "|" << std::setw(10) << _vendedor1.getLegajo() << "|" << std::setw(20) << _vendedor1.getNombre() << "|" << std::setw(20) << _vendedor1.getApellido() << "|" << std::setw(20) << _vendedor1.getUsuario() << "|" << std::endl;
	std::cout << std::left << "|" << std::setw(10) << "_________" << "|" << std::setw(20) << "___________________" << "|" << std::setw(20) << "___________________" << "|" << std::setw(20) << "___________________" << "|" << std::endl;
	std::cout << std::endl;
}

