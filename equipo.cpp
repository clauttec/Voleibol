#include "equipo.h"

// Implementación de la clase Jugador
Jugador::Jugador(string nombre, float altura) : nombre(nombre), altura(altura) {}

void Jugador::imprimir() const
{
    cout << nombre << ": " << altura << "m" << endl;
}

// Implementación de la clase Equipo
Equipo::Equipo(string nombre, int victorias, int derrotas, int puntos)
    : nombre(nombre), victorias(victorias), derrotas(derrotas), puntos(puntos) {}

void Equipo::agregar_jugador(Jugador jugador)
{
    jugadores.push_back(jugador);
}

void Equipo::imprimir() const
{
    cout << nombre << ": " << victorias << " victorias, "
         << derrotas << " derrotas, " << puntos << " puntos" << endl;
}