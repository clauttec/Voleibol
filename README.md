# Voleibol

## Avance 1

En este avance del proyecto, se ha implementado un sistema para organizar equipos de voleibol en un torneo. El programa está estructurado en clases, las dos clases principales son Equipo y Jugador, donde un equipo tiene una lista de jugadores.

El programa permite organizar a los equipos según sus victorias y a los jugadores de un equipo según su altura, utilizando algoritmos de ordenamiento eficientes.

Se ha implementado el algoritmo Quick Sort para ordenar los equipos por el número de victorias y el Merge Sort para ordenar a los jugadores por su altura, seleccionando estos algoritmos por sus propiedades y rendimiento en escenarios diferentes, que se explicarán más adelante.

### Para compilar y ejecutar

Para macOS/Linux
```
g++ main.cpp Equipo.cpp -o torneo
./torneo
```

Para windows
```
g++ main.cpp Equipo.cpp -o torneo.exe
torneo.exe
```

### Comprobar subcompetencias

#### SICT0301

Seleccione el metodo de quick sort para ordenar los equipos debido a su eficiencia en la mayoria de casos con una complejidad promedio de O(nlogn). Aunque su complejidad en el peor de los casos es de O(n^2) debemos de entender el contexto en el que se usa, ya que el quick sort tiene un rendimiento en la practica muy bueno, y destaca especialmente en listas desordenadas, lo que es tipico en un torneo de voleibol. Dado que el numero de equipos en el torneo es relativamente pequeño (menos de 10), Quick Sort es una opción adecuada debido a su baja constante de tiempo y rapidez en conjuntos de datos medianos.

La estrctura seleccionada (lista doblemente ligada) nos permite un acceso secuencial eficiente en ambas direcciones, teniendo una complejidad de solo O(1) al momento de insertar o eliminar y una complejidad de O(n) al momento de recorrer por completo la lista.

#### SICT0302

Para ordenar a los jugadores utilice el metodo merge sort debido a su complejidad consistente O(nlogn) en todos los casos. Merge Sort es ideal porque mantiene el orden original entre jugadores que tienen la misma altura, si los hubiera. Aunque utiliza más memoria, esto no es un problema dado que hay pocos jugadores en cada equipo, y su buen rendimiento y consistencia lo hacen adecuado en este caso.

Se selecciono la lista doblemente ligada debido a que permite la facil manipulacion de los jugadores con la posibilidad de recorrer la lista tanto hacia adelante como hacia atras, lo que se ajusta a las necesidades de agregar, eliminar y consultar jugadores.

#### SICT303

He desarrollado funciones para imprimir y listar los jugadores, convirtiendo la lista doblemente ligada en un vector para poder aplicar el algoritmo de ordenamiento. Este mecanismo permite organizar la lista de jugadores por altura y presentarla de forma clara.