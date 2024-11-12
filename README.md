# Voleibol

## Avance 1

En este avance del proyecto, se ha implementado un sistema para organizar equipos de voleibol en un torneo. El programa está estructurado en clases, las dos clases principales son Equipo y Jugador, donde un equipo tiene una lista de jugadores.

El programa permite organizar a los equipos según sus victorias y a los jugadores de un equipo según su altura, utilizando algoritmos de ordenamiento eficientes.

Se ha implementado el algoritmo Quick Sort para ordenar los equipos por el número de victorias y el Merge Sort para ordenar a los jugadores por su altura, seleccionando estos algoritmos por sus propiedades y rendimiento en escenarios diferentes, que se explicarán más adelante.

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