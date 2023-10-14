#pragma once
#include <vector>
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Administrador.h"
#include "Vendedor.h"

class Sistema
{
private:
	Pelicula vecPeliculas[5];
	Sala vecSalas[5];
	Funcion vecFunciones[25];
	Administrador _admin1;
	Vendedor _vendedor1;
	int matrizSalasxFuncion[25][10][10] = { 0 };

public:
	Administrador getAdmin() const;
	Vendedor getVendedor() const;
	void login(Administrador admin1, Vendedor vendedor1);
	void bienvenida();
	void mostrarMenuAdmin();
	void mostrarMenuVendedor();
	bool crearDirectorioBackUP();

	Sistema();


};

