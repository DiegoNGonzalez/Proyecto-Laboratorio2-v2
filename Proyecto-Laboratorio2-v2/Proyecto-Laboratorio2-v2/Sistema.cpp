#include "Sistema.h"
#include <iostream>
#include <filesystem>
#include <string>
#include "Windows.h"
#include "rlutil.h"
#include <conio.h>


Sistema::Sistema()
{
	_admin1 = Administrador(01, "DT", "Carlos", "Tevez", "Admin", "qwerty");
	_vendedor1 = Vendedor(02, "Vendedor", "Lionel", "Messi", "Vendedor", "1234");
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
	rlutil::setConsoleTitle("LOGIN- SISTEMA DE CINE");
	do {
		system("cls");
		rlutil::setColor(rlutil::COLOR::LIGHTBLUE);
		rlutil::locate(50, 10);
		std::cout << "Ingrese su usuario: ";
		std::cin >> usuario;
		rlutil::locate(50, 11);
		std::cout << "Ingrese su contrasenia: ";
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
			std::cout << "Usuario o contrasenia incorrectos" << std::endl;
			intentos++;
			Sleep(1000);
			rlutil::locate(50, 14);
			system("pause");
			system("cls");
		}
	} while (intentos < 3 && login == false);
	rlutil::setColor(rlutil::COLOR::WHITE);
}

// Funcion para mostrar las opciones del menu
void showItem(const char* text, int posx, int posy, bool selected) {

	if (selected) {
		rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
		rlutil::locate(posx - 3, posy); // posiciona el cursor en la fila y columna que le pasamos por parametro (en este caso, -2 porque colocamos una flechita en la opcion seleccionada)
		std::cout << ">>" << "  " << text << "  " << "<<" << std::endl; // imprime una flechita a cada lado con el codigo ASCII, y el texto que le pasamos por parametro
	}
	else {
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
		rlutil::locate(posx - 3, posy);
		std::cout << "   " << text << "   " << "  " << std::endl; // si no esta seleccionado, imprime el texto sin las flechitas
	}
	rlutil::setBackgroundColor(rlutil::COLOR::BLACK); // cuando llega a la ultima opcion, cambia el color del cursor al color normal
}



void Sistema::mostrarMenuAdmin() {

	int op = 1, y = 0;
	Funcion f1;
	ArchivoFunciones archiFunciones("funcion.dat");

	do {
		rlutil::setConsoleTitle("MENU ADMIN CINE"); // establece el titulo de la consola
		rlutil::hidecursor(); // oculta el cursor
		//rlutil::cls(); // limpia la pantalla

		showItem(" Menu Peliculas ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem(" Menu Salas ", 50, 11, y == 1);
		showItem(" Menu Funciones ", 50, 12, y == 2);
		showItem(" Menu BackUp ", 50, 13, y == 3);
		showItem(" Menu Informes", 50, 14, y == 4); // ---- NUEVO MENU INFORMES
		showItem(" Cerrar sesion ", 50, 15, y == 5); // Pase cerrar sesion para abajo, cambia y == 4 a y ==5
		showItem("  SALIR   ", 50, 16, y == 6); // mismo comentario linea anterior

		int key = rlutil::getkey(); // Lee una pulsación de tecla y devuelve un código ASCII de tecla.



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
			if (y > 6) y = 6; // -- agregue otra opcion, por eso cambie el 5 a 6
			break;
		case 1: // ENTER
			switch (y)
			{
			case 0: {
				system("cls");
				_admin1.menuPeliculas();
				system("cls");
				break;
			}
			case 1:
				system("cls");
				_admin1.menuSalas();
				system("cls");
				break;
			case 2:
				system("cls");
				_admin1.menuFunciones();
				system("cls");
				break;
			case 3:
				system("cls");
				_admin1.menuBackUp();
				system("cls");
				break;
			 case 4: // ---- NUEVO MENU INFORMES
				 system("cls");
				 mostrarMenuInformes();
				 system("cls");
				 break;
			case 5: // Pase cerrar sesion para abajo, cambia case de 4 a 5
				login(_admin1, _vendedor1);
				op = 0;
				break;
			case 6: // Si el cursor esta en la opcion SALIR		// -- tambien cambie el case de 5 a 6
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
		rlutil::setConsoleTitle("MENU VENDEDOR CINE"); // establece el titulo de la consola
		rlutil::hidecursor(); // oculta el cursor
		//rlutil::cls(); // limpia la pantalla

		showItem(" FUNCIONES CARGADAS ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem(" MOSTRAR SALA, SE NECESITA ID DE FUNCION. ", 50, 11, y == 1);
		showItem(" VENTA DE ASIENTOS ", 50, 12, y == 2);
		showItem(" CANCELAR VENTA DE ASIENTOS ", 50, 13, y == 3);
		showItem(" VER VENTAS ", 50, 14, y == 4);
		showItem(" CERRAR SESION ", 50, 15, y == 5);
		showItem("  SALIR   ", 50, 16, y == 6);

		int key = rlutil::getkey(); // Lee una pulsación de tecla y devuelve un código ASCII de tecla.



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
			if (y > 6) y = 6;
			break;
		case 1: // ENTER
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
				std::cout << "Ingrese el id de la funcion a mostrar sala:";
				std::cin >> idFuncion;
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
				std::cout << "Ingrese el id de la funcion para la cual quiere vender un asiento: ";
				std::cin >> idFuncion;
				int pos = archiDiagrama.buscarPosDiagramaxID(idFuncion);
				if (pos != -1) {
					_vendedor1.venderEntradas(idFuncion);
					std::cout << std::endl;
				}
				else {
					system("pause");
				}
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				archiVenta.verVentasCargadas();
				std::cout << "Ingrese el id de la venta a cancelar: ";
				std::cin >> idEntrada;
				int pos = archiVenta.buscarPosEntradaxID(idEntrada);
				if (pos != -1) {
					_vendedor1.cancelarVenta(idEntrada);
				}
				else {
					system("pause");
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
			case 6: // Si el cursor esta en la opcion SALIR
				op = 0; // sale del programa
				break;
			}
		}
	} while (op != 0);
}

void Sistema::mostrarMenuInformes() { // NUEVO MENU INFORMES
	Pelicula pelicula;
	ArchivoPeliculas archiPeliculas("peliculas.dat");
	char nombrePelicula[30];

	int op = 1, y = 0;
	do {
		rlutil::setConsoleTitle("MENU INFORMES"); // establece el titulo de la consola
		rlutil::hidecursor();

		showItem(" 1- Total Recaudado por pelicula", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem(" 2- Total recaudado por dia ", 50, 11, y == 1);
		showItem(" 3- Total recaudado por mes ", 50, 12, y == 2);
		showItem(" 4- Total recaudado anual", 50, 13, y == 3);
		showItem(" Volver", 50, 14, y == 4);

		int key = rlutil::getkey();

		switch (key)
		{
		case 14: // flecha ARRIBA
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl; // imprime un espacio para borrar la flecha cuando cambie de posicion
			y--;
			if (y < 0) y = 0; // validacion para que no se salga de las opciones
			break;
		case 15: // flecha ABAJO													    
			rlutil::locate(28, 11 + y);
			std::cout << " " << std::endl;
			y++;
			if (y > 5) y = 5;
			break;
		case 1: // ENTER
			switch (y)
			{
			case 0: { // TOTAL RECAUDADO POR PELICULA
				system("cls");
				int cantidadPelis = archiPeliculas.contarRegistros();

				std::cout << "Total recaudado por pelicula" << std::endl;
				for (int i = 0; i < cantidadPelis; i++) {
					pelicula = archiPeliculas.leerRegistro(i);
					std::cout << "TITULO " << i << std::endl;
				}

				std::cout << "Ingrese el id de la pelicula" << std::endl;

				system("pause");
				system("cls");
				break;
			}
			case 1: {
				system("cls");
				std::cout << "Total recaudado por dia" << std::endl;
				std::cout << "Ingrese el dia que desea saber la recaudacion" << std::endl;
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				system("cls");
				std::cout << "Total recaudado por mes" << std::endl;
				std::cout << "Ingrese el mes " << std::endl;
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				std::cout << "Total recaudado anual" << std::endl;
				std::cout << "Ingrese el anio" << std::endl;
				system("pause");
				system("cls");
				break;
			}
			case 4: 
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
	std::cout << "Bombieri Rodrigo. " << std::endl;
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
	std::cout << "Linkedin: " << "https://www.linkedin.com/in/tomas-caceres-1106b6274/" << std::endl;
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
