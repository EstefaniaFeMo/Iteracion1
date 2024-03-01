# PROYECTO ITERACION1 PPROG Stable Version
## 06-02-2024
- **E** He documentado las funciones de game.h

## 09-02-2024
- **E** He documentado las funciones de game.c y type.h
- **E** Modificado Game
- **E** Terminado Game_Reader

- **C** He documentado las funciones de game_loop.c, command.h y command.c

## 10-02-2024
- **E** Creados object.c y object.h, con las fucniones create, destroy, get, set y print (Documentados)

- **C** He documentado las funciones de game_actions.c, game_actions.h
- **C** He creado el makefile

## 11-02-2024
- **E** modificado makefile
- **E** modificado space el object e intento en game pero fallo al poner en el struct un puntero a Object 
e intentar acceder a él.

- **C** Creados player.c y player.h, con las fucniones create, destroy, get, set, localization y print (Documentados)

## 12-02-2024
- **E** Modificado game_reader como corresponde, añadido a la estructura de game, puntero a player, añadidos comandos take y drop.
- **E** Hay q modificar sabiendo q no se puede acceder en la estructura de game a las estructuras de object y player, solo se puede acceder con primitivas.
- **E** Modificado la funciones relacionadas con object en el módulo Game y Space.
- **E** He modificado ya las funciones de print la localización del player y el object en el módulo Game.

- **C** He modificado game.c para implamentar las funciones del módulo player.
- **C** He documentado las funciones necesarias para implementar los comandos drop y take en game_actions.c (las funciones no están hechas, sólo escritas).

- **E** Creada función drop

## 13-02-2024
- **B** Hemos dolucionado los problemas en la implementación de Player y Object a Game.
  
- **E** Añadido que se escriba PLAYER POSITION en el juego
- **E** Añadido funcion para sacar la posicion de un espacio dando su id
- **E** Corregido error que hacia que no funcionara el comando BACK
- **E** Creados take y drop

- **C** Creado los nuevos caminos de 6 y 4 en un fichero llamado anthill_camino.dat

## 14-02-2024

- **C** He revisado la documentación de todos los ficheros .c y .h, y modificado algunas documentaciones y detalles

## 20-02-2024
- **C** He empezado a implementar el módulo character que incluye character.c y character.h

## 21-02-2024
- **C** Terminado el módulo character y todas sus funciones
- **C** Modificado el módulo player para que contenga sus puntos de vida
- **E** Terminado módulo set 

## 22-02-2024
- **E** Modificaciones (aunque aun no terminadas) en el modulo space con el modulo set y nuevas funciones para set. (preguntar al profesor si hay que comprobar que las ids del array son unicas o darlo por supuesto)
- **C** Creado la función game_reader_load_objects, y empezado a implemenatar los nuevos comandos.
- **C** Modificado el fichero para que contenga 4 objetos
## 01-03-2024
- **E** Comprobado space test que funcione space, falta documentar correctamente las funciones de space, 
modificando game con las funciones de space, la parte de objetos falta documentar y comprobar y falta las funciones de los characters
