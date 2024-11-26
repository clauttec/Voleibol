# Voleibol

## Sobre el programa...
El progrma se estructura alrededor de un menú principal que ofrece exactamente 9 opciones, cada una diseñada para realizar una función específica.
A través del uso de estructuras de datos y algoritmos eficientes, el programa permite ordenar tanto equipos como jugadores de manera rápida y sencilla. Además, ofrece la posibilidad de crear nuevos equipos y jugadores, lo que facilita la gestión de la información y la adaptación a cambios en la composición de los equipos.
El objetivo principal del programa es ser intuitivo y eficaz, proporcionando una experiencia de usuario fluida y fácil de usar. En resumen, el programa es un gestionador de equipos de voleibol que busca simplificar la tarea de organizar y analizar datos, permitiendo a los entrenadores y aficionados tomar decisiones informadas y mejorar su comprensión del juego.

### A quien le ofrece valor?
El objetivo principal del programa es ser intuitivo y eficaz, proporcionando una experiencia de usuario fluida y fácil de usar. En resumen, el programa es un gestionador de equipos de voleibol que busca simplificar la tarea de organizar y analizar datos, permitiendo a los entrenadores y aficionados tomar decisiones informadas y mejorar su comprensión del juego.
El programa ofrece un valor significativo para los entrenadores de equipos de voleibol, al proporcionarles una herramienta eficaz para el análisis y la toma de decisiones.
Una de las principales ventajas del programa es su capacidad para crear archivos de texto que contienen datos valiosos sobre los equipos, como el número de victorias, derrotas y puntos totales. Esto permite a los entrenadores tener una visión clara y detallada del rendimiento de sus equipos.
Además, el programa ofrece la posibilidad de visualizar a todos los jugadores de un equipo, lo que facilita la identificación de patrones y tendencias en el juego. La capacidad de ordenar rápidamente tanto a los jugadores de un equipo como a los equipos en sí, es otra característica valiosa del programa.
Un aspecto destacado del programa es su capacidad para importar archivos de texto existentes que contengan información sobre los equipos. Esto permite a los entrenadores aprovechar la información que ya han recopilado y ordenarla de manera eficaz. Además, el programa genera un nuevo archivo de texto que contiene la información ordenada, lo que permite a los entrenadores almacenarla de manera segura y acceder a ella en el futuro.

### Consideraciones
1. Al momento de ingresar el nombre de un archivo, ya sea para crear o cargar, no es necesario agregar la extension de este mismo(.txt), el programa lo hace automaticamente.

2. Para cargar un archivo es necesario que este se encuentre dentro de la misma carpeta en donde se encuentra el programa.

3. Solo se puede cargar un equipo por archivo.

4. El formato que debera seguir el archivo para que se cargue es el siguiente:

    Nombre del equipo | Victorias | Derrotas | Puntos
    Nombre de jugador | Altura    |

    Ejemplo:
    
    Tigres            |    20     |    0     |    40
    Claudio           |   1.81    |
    Mauricio          |   1.84    |


### Para compilar y ejecutar

Para macOS/Linux
```
g++ -std=c++17 -g main.cpp equipo.cpp -o main 
./main
```

Para windows
```
g++ -std=c++17 -g main.cpp equipo.cpp -o main.exe
main.exe
```

### Comprobar subcompetencias

#### SICT0301 Evalua los componentes

Seleccione el metodo de quick sort para ordenar los equipos debido a su eficiencia en la mayoria de casos con una complejidad promedio de O(nlogn). Aunque su complejidad en el peor de los casos es de O(n^2) debemos de entender el contexto en el que se usa, ya que el quick sort tiene un rendimiento en la practica muy bueno, y destaca especialmente en listas desordenadas, lo que es tipico en un torneo de voleibol. Dado que el numero de equipos en el torneo es relativamente pequeño (menos de 10), Quick Sort es una opción adecuada debido a su baja constante de tiempo y rapidez en conjuntos de datos medianos.

La estrctura seleccionada (lista doblemente ligada) nos permite un acceso secuencial eficiente en ambas direcciones, teniendo una complejidad de solo O(1) al momento de insertar o eliminar y una complejidad de O(n) al momento de recorrer por completo la lista.

Cada funcion cuenta con su respectivo comentario indicando el nivel de complejidad de este mismo en su mejor, peor y promedio de caso. Puedo concluir que la complejidad del programa depende de dos principales funciones, el quick sort y el merge sort. Esto debido a que son las funciones de mayor nivel de complejidad, una vez aclarado esto, puedo decir que la complejidad del programa en su mejor caso es de O(n log(n)), su promedio es de O(n log(n)) y su peor caso de es de O(n^2) esto ultimo debido a la funcion de quick sort que tiene esta misma complejidad en su peor caso.

#### SICT0302 Toma decisiones

Para ordenar a los jugadores utilice el metodo merge sort debido a su complejidad consistente O(nlogn) en todos los casos. Merge Sort es ideal porque mantiene el orden original entre jugadores que tienen la misma altura, si los hubiera. Aunque utiliza más memoria, esto no es un problema dado que hay pocos jugadores en cada equipo, y su buen rendimiento y consistencia lo hacen adecuado en este caso.

Se selecciono la lista doblemente ligada debido a que permite la facil manipulacion de los jugadores con la posibilidad de recorrer la lista tanto hacia adelante como hacia atras, lo que se ajusta a las necesidades de agregar, eliminar y consultar jugadores.

#### SICT303 Implementa acciones cientificas

He desarrollado funciones para imprimir y listar los jugadores, convirtiendo la lista doblemente ligada en un vector para poder aplicar el algoritmo de ordenamiento. Este mecanismo permite organizar la lista de jugadores por altura y presentarla de forma clara.

Utilizando la libreria ifstream he desarrollado una nueva funcion para leer los datos de un archivo de texto, distribuyendo cada dato del archivo de texto en los atributos adecuados del objeto Equipo y su lista de jugadores. De igual forma, utilizando la libreria ifstream realice una funcion que permite escribir datos en un archivo, esta funcion guarda el estado del objeto Equipo y su lista de jugadores en un archivo de texto.