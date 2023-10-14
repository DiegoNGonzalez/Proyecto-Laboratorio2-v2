#include <iostream>
#include <string>
#include "Windows.h"
#include "rlutil.h"
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Sistema.h"
#include "Persona.h"
#include "Administrador.h"


using namespace std;



int main() {



	Sistema sistema;
	sistema = Sistema();
	sistema.bienvenida();
	sistema.login(sistema.getAdmin(), sistema.getVendedor());

	return 0;
}