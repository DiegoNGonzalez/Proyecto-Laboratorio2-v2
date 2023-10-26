#include <iostream>
#include <string>
#include "Windows.h"
#include "rlutil.h"
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Sistema.h"
#include "Empleado.h"
#include "Administrador.h"
#include <locale.h>


using namespace std;


int main() {

	setlocale(LC_ALL, "spanish");

	Sistema sistema;
	sistema = Sistema();
	sistema.verificarFechaYHoraFunciones();
	sistema.bienvenida();
	sistema.login(sistema.getAdmin(), sistema.getVendedor());
	sistema.creditos();

	return 0;
}