#include <iostream>
#include <string>
#include "Windows.h"
#include "rlutil.h"

using namespace std;
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Sistema.h"
#include "Empleado.h"
#include "Administrador.h"
#include <locale.h>

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