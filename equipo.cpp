#include "equipo.h"
#include <fstream>
#include <iostream>
#include <sstream>

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

/*
 * Complejidad
 *
 * Mejor caso: O(1)
 * Peor caso: O(1)
 * Promedio: O(1)
 *
 * Se agrega el jugador al final de la lista sin importar el tamano de la lista
 */

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

/*
 * Complejidad
 *
 * Mejor caso: O(1)
 * Peor caso: O(n)
 * Promedio: O(n)
 *
 * La funcion recorre cada nodo de la lista para imprimirlo
 */

void ListaJugadores::imprimir_jugadores() const
{
    Jugador *actual = cabeza;
    while (actual)
    {
        actual->imprimir();
        actual = actual->siguiente;
    }
}

bool ListaJugadores::existe_jugador(string nombre) const
{
    Jugador *actual = cabeza;
    while (actual != nullptr)
    {
        if (actual->nombre == nombre)
        {
            return true; // El jugador existe
        }
        actual = actual->siguiente;
    }
    return false; // No se encontró el jugador
}
/*
 * Complejidad
 *
 * Mejor caso: O(1)
 * Peor caso: O(n)
 * Promedio: O(n/2)
 *
 * La funcion busca el jugador, este puede estar al principio, al final o en cualquier posicion
 */

void ListaJugadores::eliminar_jugador(string nombre)
{
    if (!existe_jugador(nombre))
    {
        cout << "El jugador con nombre \"" << nombre << "\" no existe en el equipo." << endl;
        return;
    }

    Jugador *actual = cabeza;
    while (actual != nullptr)
    {
        if (actual->nombre == nombre)
        {
            // Ajustar los punteros de los nodos
            if (actual->anterior)
            {
                actual->anterior->siguiente = actual->siguiente;
            }
            else
            {
                cabeza = actual->siguiente; // Si es el primero
            }
            if (actual->siguiente)
            {
                actual->siguiente->anterior = actual->anterior;
            }
            else
            {
                cola = actual->anterior; // Si es el último
            }

            delete actual; // Liberar la memoria
            cout << "El jugador \"" << nombre << "\" ha sido eliminado." << endl;
            return;
        }
        actual = actual->siguiente;
    }
}

/*
 * Complejidad
 *
 * Mejor caso: O(1)
 * Peor caso: O(n)
 * Promedio: O(n)
 *
 * La funcion recorre cada nodo para convertirlo en un elemnto del vector
 */

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

// Implementacion del constructor por default
Equipo::Equipo() : nombre(""), victorias(0), derrotas(0), puntos(0) {}

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

/*
 * Complejidad
 *
 * Mejor caso: O(1)
 * Peor caso: O(n)
 * Promedio: O(n)
 *
 * La funcion recorre cada linea del archivo
 */

void Equipo::cargar_archivo(const string &nombre_archivo, Equipo &equipo)
{
    ifstream archivo(nombre_archivo);

    if (!archivo.is_open())
    {
        cerr << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        return;
    }

    string linea;
    bool primera_linea = true;

    while (getline(archivo, linea))
    {
        stringstream ss(linea);

        if (primera_linea)
        {
            string nombre_equipo;
            int victorias, derrotas, puntos;

            ss >> nombre_equipo >> victorias >> derrotas >> puntos;
            equipo = Equipo(nombre_equipo, victorias, derrotas, puntos); // Inicializar equipo
            primera_linea = false;
        }
        else
        {
            string nombre_jugador;
            float altura;

            ss >> nombre_jugador >> altura;
            equipo.agregar_jugador(nombre_jugador, altura); // Agregar jugador al equipo
        }
    }

    archivo.close();
}

/*
 * Complejidad
 *
 * Mejor caso: O(1)
 * Peor caso: O(n)
 * Promedio: O(n)
 *
 * La complejidad depende de la cantidad de jugadores del equipo. La complejidad es lineal respecto al numero de jugadores
 */

void Equipo::escribir_en_archivo(const string &nombre_archivo) const
{
    ofstream archivo(nombre_archivo);

    if (!archivo.is_open())
    {
        cerr << "No se pudo abrir el archivo para escribir: " << nombre_archivo << endl;
        return;
    }

    // Guardar los datos del equipo
    archivo << nombre << " " << victorias << " " << derrotas << " " << puntos << endl;

    // Guardar los datos de cada jugador
    for (const auto &jugador : jugadores.a_vector())
    { // 'a_vector()' convierte la lista a un vector
        archivo << jugador.nombre << " " << jugador.altura << endl;
    }

    archivo.close();
}

/*
 * Complejidad
 *
 * Mejor caso: O(n logn)
 * Peor caso: O(n^2)
 * Promedio: O(n logn)
 *
 * Si el vector esta ordenado en orden inverso podria aumentar la complejidad, pero en la mayoria de casos el orden es aleatorio
 */

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

/*
 * Complejidad
 *
 * Mejor caso: O(n logn)
 * Peor caso: O(n logn)
 * Promedio: O(n logn)
 */

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

void mostrar_menu()
{
    cout << "\n--- Menú Principal ---" << endl;
    cout << "1. Agregar un nuevo equipo" << endl;
    cout << "2. Agregar jugador a un equipo" << endl;
    cout << "3. Eliminar jugador de un equipo" << endl;
    cout << "4. Ordenar equipos por victorias" << endl;
    cout << "5. Ordenar jugadores de un equipo por altura" << endl;
    cout << "6. Guardar equipo en archivo" << endl;
    cout << "7. Cargar datos externos" << endl;
    cout << "8. Imprimir equipos" << endl;
    cout << "9. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int menu_principal(vector<Equipo> equipos, int opcion, string nombre_equipo, string nombre_jugador, string nombre_archivo, float altura, int victorias, int derrotas, int puntos)
{
    while (true)
    {
        // Mostramos menu y pedimos que seleccione opcion
        mostrar_menu();
        cin >> opcion;

        // Switch para cada opcion del menu
        switch (opcion)
        {

        // Agregar un nuevo equipo
        case 1:
        {
            // Solicitamos el nombre del equipo
            cout << "Ingresa el nombre del equipo: ";
            cin >> nombre_equipo;

            // Solicitamos el numero de victorias del equipo y comprobamos que sea valido
            cout << "Ingresa el numero de victorias del equipo: ";
            cin >> victorias;

            while (victorias < 0)
            {
                cout << "Numero de victorias invalido, por favor intentalo de nuevo: ";
                cin >> victorias;
            }

            // Solicitamos el numero de derrotas del equipo y comprobamos que sea valido
            cout << "Ingresa el numero de derrotas del equipo: ";
            cin >> derrotas;

            while (derrotas < 0)
            {
                cout << "Numero de derrotas invalido, por favor intentalo de nuevo: ";
                cin >> derrotas;
            }

            // Solicitamos el numero de victorias del equipo y comprobamos que sea valido
            cout << "Ingresa el numero de puntos del equipo: ";
            cin >> puntos;

            while (puntos < 0)
            {
                cout << "Numero de puntos invalido, por favor intentalo de nuevo: ";
                cin >> puntos;
            }

            // Agregamos el equipo a la lista de equipos
            equipos.emplace_back(nombre_equipo, victorias, derrotas, puntos);
            cout << "Equipo agregado exitosamente.\n";

            break;
        }

        // Agregar jugador a un equipo
        case 2:
        {
            // Solicitamos el nombre del equipo al que se agregara el jugador
            cout << "Ingresa el nombre del equipo: ";
            cin >> nombre_equipo;

            bool equipo_encontrado = false;

            // Ciclo for para buscar el equipo y agregar jugador
            for (auto &equipo : equipos)
            {
                if (equipo.get_nombre() == nombre_equipo)
                {
                    cout << "Ingrese el nombre del jugador: ";
                    cin >> nombre_jugador;

                    cout << "Ingrese la altura del jugador: ";
                    cin >> altura;

                    while (altura < 0)
                    {
                        cout << "Altura invalida, intentalo de nuevo: ";
                        cin >> altura;
                    }

                    equipo.agregar_jugador(nombre_jugador, altura);
                    cout << "Jugador agregado exitosamente";

                    equipo_encontrado = true;
                    break;
                }
            }

            if (equipo_encontrado != true)
            {
                cout << "Equipo no encontrado. \n";
            }
            break;
        }

        // Eliminar jugador de un equipo
        case 3:
        {
            // Solicitamos el nombre del equipo del cual se desea eliminar el jugador
            cout << "Ingresa el nombre del equipo: ";
            cin >> nombre_equipo;

            bool equipo_encontrado = false;

            // Ciclo for para buscar el equipo y eliminar jugador
            for (auto &equipo : equipos)
            {
                if (equipo.get_nombre() == nombre_equipo)
                {
                    cout << "Ingrese el nombre del jugador a eliminar: ";
                    cin >> nombre_jugador;

                    // HACE FALTA VERIFICAR QUE EL JUGADOR ESTE EN EL EQUIPO
                    equipo.jugadores.eliminar_jugador(nombre_jugador);

                    equipo_encontrado = true;
                    break;
                }
            }

            if (equipo_encontrado != true)
            {
                cout << "Equipo no encontrado. \n";
            }
            break;
        }

        // Ordenar equipos por victorias
        case 4:
        {
            equipos = quick_sort_equipos(equipos);
            cout << "Equipos ordenados por victorias: \n";

            for (auto &equipo : equipos)
            {
                equipo.imprimir();
            }
            break;
        }

        // Ordenar jugadores de un equipo por altura
        case 5:
        {
            // Solicitamos el nombre del equipo del cual se desea ordenar jugadores
            cout << "Ingresa el nombre del equipo: ";
            cin >> nombre_equipo;

            bool equipo_encontrado = false;

            for (auto &equipo : equipos)
            {
                if (equipo.get_nombre() == nombre_equipo)
                {
                    vector<Jugador> jugadores = equipo.jugadores.a_vector();
                    jugadores = merge_sort_jugadores(jugadores);

                    cout << "Jugadores de " << nombre_equipo << " ordenados por altura: \n";

                    for (auto &jugador : jugadores)
                    {
                        jugador.imprimir();
                    }

                    equipo_encontrado = true;
                    break;
                }
            }
            if (!equipo_encontrado)
            {
                cout << "Equipo no encontrado. \n";
            }
            break;
        }

        // Guardar equipo en archivo
        case 6:
        {
            cout << "Ingresa el nombre del equipo a guardar: ";
            cin >> nombre_equipo;
            bool equipo_encontrado = false;
            for (auto &equipo : equipos)
            {
                if (equipo.get_nombre() == nombre_equipo)
                {
                    nombre_archivo = nombre_equipo;
                    nombre_archivo += ".txt";
                    equipo.escribir_en_archivo(nombre_archivo);

                    cout << "El equipo se ha guardado en el archivo: " << nombre_archivo << ".txt";

                    equipo_encontrado = true;
                }
            }
            if (!equipo_encontrado)
            {
                cout << "Equipo no encontrado. \n";
            }
            break;
        }

        // Cargar datos externos
        case 7:
        {
            Equipo equipo;

            cout << "Ingresa el nombre del archivo: ";
            cin >> nombre_archivo;

            nombre_archivo += ".txt";

            equipo.cargar_archivo(nombre_archivo, equipo);

            break;
        }

        // Imprimir equipos
        case 8:
        {
            for (auto &equipo : equipos)
            {
                equipo.imprimir();
            }
            break;
        }

        // Salir
        case 9:
        {
            cout << "Gracias por usar el programa. Hasta pronto! \n";
            return 0;
        }

        default:
            cout << "Opcion no valida, intentalo de nuevo. \n";
        }
        cout << "¿Desea realizar otra operación? (s/n): ";
        char continuar;
        cin >> continuar;
        if (continuar == 'n' || continuar == 'N')
        {
            cout << "Gracias por usar el programa. ¡Hasta pronto!\n";
            break;
        }
    }
    return 0;
}