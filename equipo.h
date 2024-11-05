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
    Jugador *siguiente;
    Jugador *anterior;

    Jugador(string nombre, float altura);
    void imprimir() const;
};

class ListaJugadores
{
private:
    Jugador *cabeza;
    Jugador *cola;

public:
    ListaJugadores();
    ~ListaJugadores();
    void agregar_jugador(string nombre, float altura);
    void imprimir_jugadores() const;
    void eliminar_jugador(string nombre);
    vector<Jugador> a_vector() const; // Para convertir la lista ligada a vector
};

class Equipo
{
public:
    string nombre;
    int victorias;
    int derrotas;
    int puntos;
    ListaJugadores jugadores;

    Equipo(string nombre, int victorias, int derrotas, int puntos);
    void agregar_jugador(string nombre, float altura);
    void imprimir() const;
    static void cargar_archivo(const string &nombre_archivo, Equipo &equipo);
};

// Declaración de Quick Sort para ordenar equipos por victorias
vector<Equipo> quick_sort_equipos(vector<Equipo> equipos);

// Declaración de Merge Sort para ordenar jugadores por altura
vector<Jugador> merge_sort_jugadores(vector<Jugador> jugadores);

#endif // EQUIPO_H