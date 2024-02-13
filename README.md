# PROYECTO ITERACION1 PPROG Stable Version
## 06-02-2024
- **E** He documentado las funciones de game.h

## 09-02-2024
- **E** He documentado las funciones de game.c y type.h
- **E** Modificado Game
- **E** Terminado Game_Reader

- **E** He documentado las funciones de game_loop.c, command.h y command.c

## 10-02-2024
- **E** Creados object.c y object.h, con las fucniones create, destroy, get, set y print (Documentados)

- **E** He documentado las funciones de game_actions.c, game_actions.h
- **E** He creado el makefile

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
- **E** Añadido que se escriba PLAYER POSITION en el juego
- **E** Añadido funcion para sacar la posicion de un espacio dando su id
- **E** Corregido error que hacia que no funcionara el comando BACK
- **E** Creados take y drop