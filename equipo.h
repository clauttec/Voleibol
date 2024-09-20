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

#endif // EQUIPO_H
