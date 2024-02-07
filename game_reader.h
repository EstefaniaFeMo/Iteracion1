/**
 * @brief It defines the game interface for the reading of spaces and other elements
 *
 * @file game_reader.h
 * @author Estefanía Fenoy Montes, Carmen Gómez Escobar
 * @version 3.5
 * @date 06-02-2024
 * @copyright GNU Public License
 */
#ifndef GAMEREADER_H
#define GAMEREADER_H

#include "command.h"
#include "space.h"
#include "types.h"
//Macro con el máximo de espacios posibles
#define MAX_SPACES 100


/**
 * @brief Game
 *
 * Esta estructura contiene toda la información relacionada con los datos del juego juego.
 */


typedef struct _Game {
  Id player_location;/*!< Id que indica el lugar/ la locación del jugador*/
  Id object_location;/*!< Id que indica el lugar/ la locación del ojeto */
  Space *spaces[MAX_SPACES];/*!< Array condiferentes espacios */
  int n_spaces; /*!< Numero de espacios*/
  Command last_cmd; /*!< Comando para modificar la locación: NO, salida, siguiente o atrás */
  Bool finished; /*!< Variable booleane que indica con valores TRUE/ FALSE la finalización del programa*/
} Game;

/**
 * @brief Si no se puede cargar, inicializando, el juego, se devuelve error. En caso de que no se puedan cargar los espacios a partir de la lectura del
 * archivo, pasado como argumento se devuelver error. Cuando se carga el juego y los espacios correctamente, se posiciona al objeto y al jugador en el espacio inicial.
 * @author Estefanía Fenoy, Carmen Gómez Escobar
 *
 * @param game un puntero a la estructura que la inicializa
 * @param filename un puntero con el nombre del fichero de texto que se leerá para cargar los espacios
 * @return status==OK, variable booleana que indica el correcto funcionamiento de la función.
 * @return status==ERROR, variable booleana que indica el erróneo funcionamiento de la función.
 */
Status game_create_from_file(Game *game, char *filename);

/**
 * @brief It downloads the spaces defined in a file
 * @author Estefanía Fenoy, Carmen Gómez Escobar
 *
 * @param game a pointer in a struct, Game and it uses it to define the space that makes the function to add it
 * @param filename a pointer to the file of text that is passed as an argument to the function
 * @return status==OK, if the function has worked correctly
 * @return status==ERROR, if a mistken has happened
 */
Status game_load_spaces(Game *game, char *filename);



#endif




