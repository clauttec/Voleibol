#ifndef EQUIPO_H
#define EQUIPO_H

#include <iostream>
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
};

#endif // EQUIPO_H