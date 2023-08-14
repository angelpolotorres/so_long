## En el main de so_long.
- [x] La funcion main recibe por argumentos argc y argv
- [x] Crea una variable llamada game basandose en la estructura t_complete.
- [x] Lanzar error si no recibe solo 1 parametro, ni más ni menos.
- [x] Rellena la variable game con 0 usando una funcion memset.
- [x] Lee el mapa con ft_read_map de argv y lo guarda en la memoria.
- [x] Chequea si hay errores en el mapa con una funcion externa
- [x] crea la instancia mlx en game->mlx_ptr y una ventana en la instancia que acabamos de crear. Las medidas de esa ventana vienen dadas por game->map_colums y cols. Ademas hay que multiplicarlas por el numero de pixel que tiene cada bloque, en este caso elegimos 40.
- [x] carga los archivos xpm a la estructura mapa
- [x] añade graficos con una funcion externa
- [ ] ejecuta un hook de teclas
- [ ] tiene otro hook para salir
- [ ] tiene el loop basico

<!-- ## Funcion read map
- [x] funcion para leer el mapa recibe como argumentos una structura game y un doble puntero char a argv. Además devuelve un entero.
- [x] Define una variable string (puntero a char)
- [x] Abre el archivo argv[1] con open y el file descriptor que devuelve open lo almacena en game->fd
- [x] Si la lectura devuelve un fd negativo es que ha fallado y hay que devolver cero.
- [x] Entra en un bucle infinito con while (1)
  - [x] Lee con get_next_line una linea del mapa
  - [x] Usa ft_save_line_map para guardar la linea nueva
  - [x] Si el guardado devuelve un error (que suele ser por que no hay mas lineas que agrear) rompemos el bucle.
  - [x] Cerramos el archivo game->fd con close
  - [x] con la funcion widthmap averiguamos el width del mapa pasandole la primera linea de game->map. (game->map[0])
  - [x] el resultado lo guardamos en game->widthmap
  - [x] devolvemos 1 para decir que hemos leido bien el mapa -->

<!-- ## Funcion get map width
- [x] Funcion que devuelve un entero que sera el width del mapa
- [x] Recibe un puntero a una str
- [x] Dentro definimos un entero que sera el ancho de nuestro mapa
- [x] bucle recorriendo el str hasta el null incremantado width
- [x] si width - 1 es un salto de linea restamos 1 al width
- [x] devolvemos width -->

<!-- ## Función save_line_map
- [x] Función "static" que recibe como parametros una structura game y un puntero a una str. Devuelve 1 o 0 para informar si ha ido bien o mal.
- [x] Definimos un doble puntero de char llamado temporary y un incrementador
- [x] Si la line que no llega es nula devolvemos 0
- [x] inicializamos i a 0
- [x] sumamos una a heightmap que tiene la estructura game
- [x] reservamos con malloc la memoria necesaria para temporary usando como referencia heightmap + 1
- [x] Ponemos null al final del array
- [x] bucle, mientras i < heigthmap -1
- [x] dentro del bucle hacemos que temporary[i] apunte a game->map[i] e incrementamos luego i.
- [x] apuntamos temporary[i] a line para asi añadir la linea nueva
- [x] si game->map existe liberamos game->map por si tiene contenido de la iteración anterior
- [x] apuntamos game->map al nuevo temporary
- [x] retornamos (1) para decir que todo fue bien -->

<!-- ## Funcion memset
- [x] Recibe una puntero tipo void llamado dest, un entero c, y un size_t llamado length.
- [x] Debes rellenar del entero c transformado a char la memoria a la que apunta dest.  -->

<!-- ## Checkeo de Errores
- [x] Usar funcion "ft_check_map_borders" para checkear si las paredes de los bordes del mapa son válidos.
- [x] Usar funcion "ft_check_map_chars" para chekears si los caracteres que forman en mapa son validos (0, 1, C, E, P).
- [x] Checkear que al menos haya un C, E, P. -->

<!-- ## Funcion salida juego
- [x] Definimos un iterador a 0
- [x] Si tenemos un windows pointer ejecutamos la funcion para destruir la ventana "mlx_destroy_window"
- [x] Liberamos el mlx pointer
- [x] Con un bucle recorremos el array de map liberando para array
- [x] Liberamos el array general de map
- [x] Ejecutamos exit con 0 -->

## Control con teclas
- [x] La funcion recibe el comando (int) y la estructura de juego (t_game)
- [x] Si el comando es 53, salir, si el comando es 13 o 1 ejecutamos la funcion de teclas w y s
- [x] Si el comando es 0 o 2 ejcutamos la funciona de las teclas a y d.
- [x] Si estas funciones me devuelven 1 ejecuto la funcion de añadir graficos al mapa otra vez para actualizar el mapa.
- [x] Devuelvo 1 al final de la función por que realmente no ha habido ingun error.

----- Funcion w y s
- [x] Creo  2 variables enteras y copio las posiciones inciales del player de la estructura de game.
- [x] restamos 1 a la posicion y (row)
- [x] si el mapa con las nuevas posiciones x e y es igual a 1 devolvemos 0
- [x] si no, ejecutamos la funcion de movimiento correcto pasandole las cordenadas y el game
- [x] si la funcion movimiento correcto diera error devolvemos 0
- [x] el hueco del mapa donde estaba el player lo rellenamos cno un 0

----- Función movimiento correcto
- [x] Si la posicion en el mapa es 'E' evaluamos
  - [x] Si colleccionables no es mayor que 0 devolvemos 0
  - [x] Imprimirmos mensaje de "enhorabuena has ganado"
  - [x] Ejecutamos la función salida del mapa
- [x] Si la posicion en el mapa es '0'
  - [x] Rellenamos esa posición del map con el player
  - [x] Actualizamos las posicion x del player
  - [x] Atuañizamos la posicion y del player
  - [x] Sumamos 1 al contador de movimientos
- [x] Si la posicón en el mapa es 'C'
  - [x] Rellenaos esa posición del mapa con el player
  - [x] actualizamos las cordenadas x del player
  - [x] actualizamos las coodenadas y del player
  - [x] restamos 1 a collectables
  - [x] sumamos 1 al contador de movimientos
- [x] retornamos 1
