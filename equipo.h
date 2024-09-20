#ifndef EQUIPO_H
#define EQUIPO_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Jugador
{
public:
    string nombre;
    float altura;

    Jugador(string nombre, float altura);
    void imprimir() const;
};

class Equipo
{
public:
    string nombre;
    int victorias;
    int derrotas;
    int puntos;
    vector<Jugador> jugadores;

    Equipo(string nombre, int victorias, int derrotas, int puntos);
    void agregar_jugador(Jugador jugador);
    void imprimir() const;
};

// Declaración de Quick Sort para ordenar equipos por victorias
vector<Equipo> quick_sort_equipos(vector<Equipo> equipos);

// Declaración de Merge Sort para ordenar jugadores por altura
vector<Jugador> merge_sort_jugadores(vector<Jugador> jugadores);

#endif // EQUIPO_H
