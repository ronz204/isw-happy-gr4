Objetivo. 
La UTN sede San Carlos necesita un sistema para ayudar a sus estudiantes, 
docentes, administrativos y personal externos orientarse dentro del campus, por lo 
cual el sistema debe de modelar una red a través de grafos. 
Red de caminos del campus, la cual será un grafo no dirigido con pesos, porque los 
caminos internos del campus se pueden recorrer en ambas direcciones y el peso 
representa la distancia en metros entre puntos del campus. 
Para lo anterior, se debe investigar y modelar el campus real en donde los nodos, 
conexiones y pesos deben ser lo más cercanos posible a la realidad. Si algún dato 
exacto no está disponible, se estima con criterio justificado.
Módulos del sistema.  
Lo que el sistema debe hacer sobre la red de caminos del campus: 
1. Mostrar todos los puntos del campus y sus conexiones con distancias. 
2. Dado un punto de inicio, realizar un recorrido DFS y mostrar el orden de visita 
con las distancias acumuladas. 
3. Dado un punto de inicio, realizar un recorrido BFS y mostrar el orden de visita 
con las distancias acumuladas. 
4. Determinar si el campus es completamente conexo, es decir, si desde 
cualquier punto se puede llegar a cualquier otro. 
5. Dado un punto de inicio y un punto destino, indicar si existe algún camino 
entre ellos y mostrar todos los nodos que se recorren en ese camino usando 
DFS. 
El sistema debe considerar en la red de caminos los siguientes escenarios: 
1. Movilidad reducida: los pesos de ciertas aristas cambian si el usuario usa 
silla de ruedas, muletas o tiene dificultad con pendientes. Algunas rutas 
simplemente no están disponibles (gradas sin rampa). Se debe modelar para 
todos los casos. 
2. Estudiante nuevo vs estudiante regular: el sistema sugiere rutas distintas: 
el nuevo prioriza pasar por puntos de referencia conocidos (biblioteca, soda), 
el veterano prioriza la ruta más corta. 
En el sistema debe haber una sección de Análisis de Complejidad donde comparen: 
1. BFS vs. DFS: ¿Cuál de los dos recorridos visitó más nodos antes de 
encontrar el destino? 
2. Tiempo de Respuesta: Mostrar cuánto tiempo (en milisegundos o 
microsegundos) tardó el algoritmo en encontrar la ruta. 
El sistema debe tener una sección de Resiliencia: "Puntos de Fallo y Bloqueos" (por 
mantenimiento, eventos o lluvia intensa). 
1. Simulación de Obstrucción: Agregar una opción donde el usuario pueda 
"marcar un nodo o una conexión como bloqueada". Deben definir cuál será 
ese punto de fallo o bloqueo. 
2. Recálculo en Tiempo Real: Si el camino principal está bloqueado, el sistema 
debe determinar automáticamente si aún es posible llegar al destino por una 
ruta alterna. 
De acuerdo con lo anterior, el menú o pestañas que debe tener el sistema son las 
siguientes: 
1. Ver mapa del campus. 
2. Recorrido DFS desde un punto. 
3. Recorrido BFS desde un punto. 
4. Verificar si el campus es conexo. 
5. Buscar camino entre dos puntos. 
6. Simulación de escenarios. 
7. Análisis de complejidad. 
8. Puntos de fallos y bloqueos.