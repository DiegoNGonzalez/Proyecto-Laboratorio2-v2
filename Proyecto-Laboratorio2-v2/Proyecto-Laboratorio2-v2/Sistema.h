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
	Administrador _admin1;
	Vendedor _vendedor1;

public:
	Administrador getAdmin() const;
	Vendedor getVendedor() const;
	void login(Administrador admin1, Vendedor vendedor1);
	void bienvenida();
	void mostrarMenuAdmin();
	void mostrarMenuVendedor();
	bool crearDirectorioBackUP();
	void creditos();

	Sistema();


};

