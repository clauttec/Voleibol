#include "equipo.h"
#include <vector>
#include <iostream>
#include <string>

int main()
{
    vector<Equipo> equipos;
    int opcion;
    string nombre_equipo, nombre_jugador, nombre_archivo;
    float altura;
    int victorias, derrotas, puntos;
    Equipo equipoVacio;

    menu_principal(equipos, opcion, nombre_equipo, nombre_jugador, nombre_archivo, altura, victorias, derrotas, puntos, equipoVacio);

    return 0;
}