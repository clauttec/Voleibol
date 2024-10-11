#include "equipo.h"

// Implementación de la clase Jugador
Jugador::Jugador(string nombre, float altura) : nombre(nombre), altura(altura), siguiente(nullptr), anterior(nullptr) {}

void Jugador::imprimir() const
{
    cout << nombre << ": " << altura << "m" << endl;
}

// Implementación de la clase ListaJugadores
ListaJugadores::ListaJugadores() : cabeza(nullptr), cola(nullptr) {}

ListaJugadores::~ListaJugadores()
{
    Jugador *actual = cabeza;
    while (actual)
    {
        Jugador *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListaJugadores::agregar_jugador(string nombre, float altura)
{
    Jugador *nuevo_jugador = new Jugador(nombre, altura);

    if (!cabeza)
    {
        cabeza = cola = nuevo_jugador;
    }
    else
    {
        cola->siguiente = nuevo_jugador;
        nuevo_jugador->anterior = cola;
        cola = nuevo_jugador;
    }
}

void ListaJugadores::imprimir_jugadores() const
{
    Jugador *actual = cabeza;
    while (actual)
    {
        actual->imprimir();
        actual = actual->siguiente;
    }
}

void ListaJugadores::eliminar_jugador(string nombre)
{
    Jugador *actual = cabeza;

    while (actual && actual->nombre != nombre)
    {
        actual = actual->siguiente;
    }

    if (actual)
    {
        if (actual->anterior)
        {
            actual->anterior->siguiente = actual->siguiente;
        }
        else
        {
            cabeza = actual->siguiente;
        }

        if (actual->siguiente)
        {
            actual->siguiente->anterior = actual->anterior;
        }
        else
        {
            cola = actual->anterior;
        }

        delete actual;
    }
}

vector<Jugador> ListaJugadores::a_vector() const
{
    vector<Jugador> jugadores;
    Jugador *actual = cabeza;
    while (actual)
    {
        jugadores.push_back(*actual);
        actual = actual->siguiente;
    }
    return jugadores;
}

// Implementación de la clase Equipo
Equipo::Equipo(string nombre, int victorias, int derrotas, int puntos)
    : nombre(nombre), victorias(victorias), derrotas(derrotas), puntos(puntos) {}

void Equipo::agregar_jugador(string nombre, float altura)
{
    jugadores.agregar_jugador(nombre, altura);
}

void Equipo::imprimir() const
{
    cout << nombre << ": " << victorias << " victorias, "
         << derrotas << " derrotas, " << puntos << " puntos" << endl;
    jugadores.imprimir_jugadores();
}

// Implementación de Quick Sort para equipos
vector<Equipo> quick_sort_equipos(vector<Equipo> equipos)
{
    if (equipos.size() <= 1)
        return equipos;

    Equipo pivote = equipos[0];
    vector<Equipo> menores, mayores;

    for (size_t i = 1; i < equipos.size(); ++i)
    {
        if (equipos[i].victorias <= pivote.victorias)
            menores.push_back(equipos[i]);
        else
            mayores.push_back(equipos[i]);
    }

    menores = quick_sort_equipos(menores);
    mayores = quick_sort_equipos(mayores);

    menores.push_back(pivote);
    menores.insert(menores.end(), mayores.begin(), mayores.end());

    return menores;
}

// Implementación de Merge Sort para jugadores
vector<Jugador> merge_sort_jugadores(vector<Jugador> jugadores)
{
    if (jugadores.size() <= 1)
        return jugadores;

    size_t medio = jugadores.size() / 2;
    vector<Jugador> izquierda(jugadores.begin(), jugadores.begin() + medio);
    vector<Jugador> derecha(jugadores.begin() + medio, jugadores.end());

    izquierda = merge_sort_jugadores(izquierda);
    derecha = merge_sort_jugadores(derecha);

    vector<Jugador> resultado;
    size_t i = 0, j = 0;

    while (i < izquierda.size() && j < derecha.size())
    {
        if (izquierda[i].altura <= derecha[j].altura)
            resultado.push_back(izquierda[i++]);
        else
            resultado.push_back(derecha[j++]);
    }

    while (i < izquierda.size())
        resultado.push_back(izquierda[i++]);
    while (j < derecha.size())
        resultado.push_back(derecha[j++]);

    return resultado;
}