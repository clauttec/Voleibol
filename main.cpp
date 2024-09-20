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

    vector<Equipo> equipos = {equipo1, equipo2};

    // Ordenar equipos por victorias (Quick Sort)
    vector<Equipo> equipos_ordenados = quick_sort_equipos(equipos);
    cout << "Equipos ordenados por victorias:\n";
    for (const Equipo &equipo : equipos_ordenados)
        equipo.imprimir();

    // Ordenar jugadores del primer equipo por altura (Merge Sort)
    vector<Jugador> jugadores_ordenados = merge_sort_jugadores(equipos_ordenados[0].jugadores);
    cout << "\nJugadores del equipo " << equipos_ordenados[0].nombre << " ordenados por altura:\n";
    for (const Jugador &jugador : jugadores_ordenados)
        jugador.imprimir();

    return 0;
}