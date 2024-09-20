#include "equipo.h"

int main()
{
    // Crear equipos
    Equipo equipo1("Tigres", 5, 1, 15);
    equipo1.agregar_jugador(Jugador("Carlos", 1.85));
    equipo1.agregar_jugador(Jugador("Luis", 1.90));
    equipo1.agregar_jugador(Jugador("Mario", 1.78));

    Equipo equipo2("Águilas", 4, 2, 12);
    equipo2.agregar_jugador(Jugador("Pedro", 1.88));
    equipo2.agregar_jugador(Jugador("Juan", 1.75));

    return 0;
}