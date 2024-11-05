#include "equipo.h"
#include <vector>
#include <iostream>

int main()
{
    // Crear un equipo inicial vacio
    Equipo equipo;

    equipo.cargar_archivo("equipo.txt", equipo);

    // Imprimir el equipo y sus jugadores
    equipo.imprimir();

    // Eliminar un jugador
    equipo.jugadores.eliminar_jugador("Pedro");

    // Imprimir el equipo después de eliminar a Pedro
    cout << "\nDespués de eliminar a Pedro:\n";
    equipo.imprimir();

    // Prueba de ordenamiento Merge Sort para jugadores
    vector<Jugador> jugadores = equipo.jugadores.a_vector();
    jugadores = merge_sort_jugadores(jugadores);

    cout << "\nJugadores ordenados por altura:\n";
    for (const Jugador &jugador : jugadores)
    {
        jugador.imprimir();
    }

    // Prueba de Quick Sort para equipos
    vector<Equipo> equipos = {equipo, Equipo("Leones", 8, 3, 28), Equipo("Águilas", 12, 1, 36)};
    equipos = quick_sort_equipos(equipos);

    cout << "\nEquipos ordenados por victorias:\n";
    for (const Equipo &eq : equipos)
    {
        eq.imprimir();
    }

    return 0;
}