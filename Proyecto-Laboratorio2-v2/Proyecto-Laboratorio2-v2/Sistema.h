#pragma once
#include <vector>  // chequear si corresponde incluirlo aca
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
	FechaHorario _fechaHorario;

public:
	Administrador getAdmin() const;
	Vendedor getVendedor() const;
	void login(Administrador admin1, Vendedor vendedor1);
	void bienvenida();
	void mostrarMenuAdmin();
	void mostrarMenuVendedor();
	void mostrarMenuInformes();
	void mostrarMenuListados();
	bool crearDirectorioBackUP();
	void creditos();
	void verificarFechaYHoraFunciones();

	Sistema();


};

