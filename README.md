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

## Problemas 

### Enlace a perfil

https://leetcode.com/u/TSP87/ 

### Enlace a problemas y soluciones

#### Problema 1:
    
    15.3Sum
    https://leetcode.com/problems/3sum/description/

    Solucion:
    https://leetcode.com/problems/3sum/submissions/1465646063

    Post (En caso de que no tenga acceso a la submission):
    https://leetcode.com/problems/3sum/solutions/6095482/problema-1/

    Video:
    https://drive.google.com/file/d/1AuDZlaqEdJwvVQl6blBOtj495e1XIqAI/view?usp=sharing

#### Que hice?

La resolucion de este problema me parecio bastante complicado y me vi forzado en realizar varios intentos fallidos, despues de probar y fallar encontre un metodo en el que primero ordenamos la lista que se nos da a traves de un selection sort, una vez que tengamos ordenada la lista podemos evitar los tripletes duplicados verificndo que el valor al que esta apuntando nuestro apuntador head no sea igual al valor de head-1 osea que no sea igual al valor que se encontraba antes de este, en caso de que si lo sea nos saltamos este valor para asi evitar duplicados, para encontrar los valores que buscamos tenemos que declarar dos apuntadores mas, primero el apuntador de la izquierda que apunta a head+1 es decir al valor siguiente de head y el segundo apuntador seria el de la derecha que apunta al ultimo valor de la lista, lo que hice en la solucion es aprovechar que nuestra lista se encuentra ordenada para asi encontrar el triplete que al sumar su resultado sea 0 entonces, cada vez que movemos ya sea el apuntador de la izquierda o el apuntador de la derecha actualizamos nuestra variable sum con la el nuevo resultado de la suma, si sum es mayor que 0 lo que queremos hacer es mover nuestro apuntador de la derecha hacia la izquierda porque estamos buscando que el resultado de la suma sea mas pequeño y ya que nuestra lista se encuentra ordenada movernos hacia la izquierda significa tambien disminuir el resultado de la suma, con este mismo principio si sum es menor que 0 lo que queremos hacer es mover nuestro apuntador de la izquierda hacia la derecha porque lo que buscamos es un total de suma mas grande que el que tenemos, este ciclo se va a repetir siempre y cuando el apuntador de la izquierda sea menor que el apuntador de la derecha, si la suma es = 0, entonces guardamos el triplete en una lista, y la agregamos a la lista de resultado que es lo que vamos a retornar, ademas de agregar el triplete al resultado moveremos nuestro apuntador del head hacia la derecha y recolocaremos nuestros apuntadores a sus respectivas posiciones (l = head + 1 | r = longitud - 1), en caso de que no encontremos ningun triplete lo que haremos sera de igual forma mover el apuntador del head a la derecha y reacomodar los otros apuntadores, y asi es como resolvemos este problema.

#### Problema 2:  

    1721.Swapping Nodes in a Linked List  
    https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/  

    Solucion:  
    https://leetcode.com/problems/swapping-nodes-in-a-linked-list/submissions/1463157941    

    Post (En caso de que no tenga acceso a la submission):  
    https://leetcode.com/problems/populating-next-right-pointers-in-each-node/solutions/6091310/tc1031-problema-3

    Video:
    https://drive.google.com/file/d/1gW_YA3Ondi6yUrFvMgLeITWOOLYHnzD1/view?usp=sharing

#### Que hice?

La resolucion de este problema fue muy facil, nos dan una lista ligada simple y un entero "k" y nos piden intercambiar el valor del nodo en la ubicacion k empezando desde el principio con el valor del nodo en la ubicacion k empezando desde el final, para obtener un apuntador que apunte al nodo de la izquierda es muy facil, solo debemos iterar k-1 veces, sin embargo para obtener el nodo de la derecha es un poco mas dificil, ya que comente anteriormente la lista que se nos da es una lista ligada SIMPLE por lo que no podemos simplemente empezar desde el final, despues de pensarlo un poco me di cuenta que podia obtener la ubicacion del nodo de la derecha a traves de iterar longitud-k, entonces primero obtuve la longitud de la lista ligada a traves de un ciclo while para despues poder restarlo por k. Por ultimo, una vez que obtenemos los nodos los intercambiamos y retornamos la cabeza de la lista.

#### Problema 3:  

    116. Populating Next Right Pointers in Each Node  
    https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

    Submussion:  
    https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/1463024816    

    Post (En caso de que no tenga acceso a la submission):  
    https://leetcode.com/problems/swapping-nodes-in-a-linked-list/solutions/6091294/tc1031-problema-2/  

#### Que hice?

Cuando vi la imagen que venia de ejemplo en el problema automaticamente pense en BFS (Metodo de busqueda por anchura), uno de los temas que vimos en clase, entonces en vez de hacer una busqueda por profundidad, dividiremos el arbol por niveles y recorreremos cada uno de estos. Al principio puede parecer un poco dificil conectar cada nodo con el nodo que se encuentra a su derecha, sin embargo si leemos bien el contexto del problema y la definicion del arbol que se nos da nos daremos cuenta que el arbol que se nos da es un arbol binario perfecto por lo que padre tendra un hijo izquiero y uno derecho, y lo que es mas importante que cada hijo estara conectado con el otro hijo por su padre. Considerando esto podremos conectar a cada nodo con el nodo que se encuentra a la derecha siempre y cuando tengan el mismo padre, para poder conectar un nodo a un nodo con diferente padre, tendremos que aprovechar la estructura que se nos da del arbol y utilizar el apuntador next, buscaremos el hijo izquiero del next del nodo padre y haremos que el hijo derecho del padre apunte hacia este nodo. Para poder movernos entre niveles tendremos que crear un apuntador que siempre apunte hacia el hijo izquiero del nodo padre (nxt), tendremos que verificar si el next del nodo padre es nulo y en caso de que sea nulo moveremos el apuntador que apunta hacia el nodo padre hacia nxt y nxt hacia el hijo izquiero del padre.
