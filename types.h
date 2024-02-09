/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Estefanía Fenoy Montes
 * @version 3.5
 * @date 04-02-2024
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
 * @brief Boolean types
 */
typedef enum { FALSE, TRUE } Bool;

/**
 * @brief Status values for functions
 */
typedef enum { ERROR, OK } Status;

/**
 * @brief Cardinal directions (N,S,E,W)
 */
typedef enum { N, S, E, W } Direction;

#endif