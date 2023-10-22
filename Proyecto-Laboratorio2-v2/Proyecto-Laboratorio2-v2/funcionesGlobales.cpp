#include "funcionesGlobales.h"
#include "rlutil.h"
#include <cstdio>
#include <stdio.h>
int funcionesGlobales::validarInt(std::string textoCout, std::string textoError) {
    int nroAvalidar;

    std::cout << textoCout;
    //<< std::endl; // le saque el salto de linea para que la fecha se ingrese en el mismo renglon
    while (!(std::cin >> nroAvalidar)) {
        std::cout << textoError;
        std::cin.clear();
       std:: cin.ignore();
    }
    return nroAvalidar;
}
int funcionesGlobales::validarMinimo(int minimo, std::string textoCout, std::string textoError, std::string textoMinimo) {
    int nroAvalidar;

    nroAvalidar = validarInt(textoCout,textoError);
    while (nroAvalidar < minimo) {
        std::cout << textoMinimo << std::endl;
        nroAvalidar = validarInt(textoCout,textoError);
    }
    return nroAvalidar;
}
int funcionesGlobales::validarRango(int minimo, int maximo, std::string textoCout, std::string textoError, std::string textoMinimo, std::string textoMaximo) {
    int nroAvalidar;

    nroAvalidar = validarInt(textoCout,textoError);
    while (nroAvalidar<minimo || nroAvalidar>maximo) {
        std::cout << textoMinimo << textoMaximo << std::endl;
        nroAvalidar = validarInt(textoCout,textoError);
    }
    return nroAvalidar;
}
// Funcion para mostrar las opciones del menu
void funcionesGlobales::showItem(const char* text, int posx, int posy, bool selected) {

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

float funcionesGlobales::validarFloat(std::string textoCout, std::string textoError)
{
    float nroAvalidar;

    std::cout << textoCout << std::endl;
    while (!(std::cin >> nroAvalidar)) {
        std::cout << textoError;
        std::cin.clear();
        std::cin.ignore();
    }
    return nroAvalidar;
}

float funcionesGlobales::validarMinimoFloat(float minimo, std::string textoCout, std::string textoError, std::string textoMinimo)
{
    float nroAvalidar;

    nroAvalidar = validarInt(textoCout, textoError);
    while (nroAvalidar < minimo) {
        std::cout << textoMinimo << minimo << std::endl;
        nroAvalidar = validarInt(textoCout, textoError);
    }
    return nroAvalidar;
}

float funcionesGlobales::validarRangoFloat(float minimo, float maximo, std::string textoCout, std::string textoError, std::string textoMinimo, std::string textoMaximo)
{
   float nroAvalidar;

    nroAvalidar = validarInt(textoCout, textoError);
    while (nroAvalidar<minimo || nroAvalidar>maximo) {
		std::cout << textoMinimo << textoMaximo << std::endl;
        nroAvalidar = validarInt(textoCout, textoError);
    }
    return nroAvalidar;
}

bool funcionesGlobales::compararFechas(Fecha fecha1, Fecha fecha2) {
    if (fecha1.getDia() == fecha2.getDia() && fecha1.getMes() == fecha2.getMes() && fecha1.getAnio() == fecha2.getAnio()) {
        return true;
    }
    else {
        return false;
    }
}

void funcionesGlobales::mostrarPorcentaje(bool pudoEscribir)
{
    int porcentaje = 25;
    for (int x = 0; x < 4; x++) {

        std::cout << "Restaurando archivo de seguridad: ";
        std::cout << porcentaje * (x + 1);
        std::cout << "%";
        Sleep(1000);
        system("cls");
        rlutil::hidecursor();
    }
    if (pudoEscribir == true) {
        std::cout << "BackUp generado con exito" << std::endl;
    }
    else {
        std::cout << "No se pudo generar el BackUp" << std::endl;
    }
    system("pause");
}

void funcionesGlobales::cargarCadena(char* pal, int tam)
{
        int i;
        fflush(stdin);
        for (i = 0; i < tam; i++)
        {
            pal[i] = std::cin.get();
            if (pal[i] == '\n') break;
        }
        pal[i] = '\0';
        fflush(stdin);
    

}

// Agregue para mostrar el mes en letras, lo uso en informes
std::string funcionesGlobales::escribirMes(int mes) {
    std::string vMeses[12] = {
        "Enero",
        "Febrero",
        "Marzo",
        "Abril",
        "Mayo",
        "Junio",
        "Julio ",
        "Agosto",
        "Septiembre",
        "Octubre",
        "Noviembre",
        "Diciembre"
    };
    return vMeses[mes - 1];
}
