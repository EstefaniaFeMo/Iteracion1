/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG, Estefanía Fenoy Montes, Carmen Gómez Escobar
 * @version 3.5
 * @date 06-02-2024
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

/**
 * @brief Maximum size allowed for a word
 */
#define WORD_SIZE 1000

/**
 * @brief Default ID
 */
#define NO_ID -1

/**
 * @brief Declaration of the type of ID
 */
typedef long Id;

/**
 * @brief Bool
 *
 * This struct defines the two boolean values, TRUE or FALSE.
 */
typedef enum { FALSE, TRUE } Bool;

/**
 * @brief Status
 *
 * This struct defines the two status values, ERROR or OK.
 */
typedef enum { ERROR, OK } Status;

/**
 * @brief Direction
 *
 * This struct defines the four values of directions, E, N, S, or W.
 */
typedef enum { N, S, E, W } Direction;

#endif
