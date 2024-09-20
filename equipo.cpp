#include "equipo.h"

// Implementación de la clase Jugador
Jugador::Jugador(string nombre, float altura) : nombre(nombre), altura(altura) {}

void Jugador::imprimir() const
{
    cout << nombre << ": " << altura << "m" << endl;
}
