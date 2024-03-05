/**
 * @brief It defines the game interface for the characters control, decribing its location, name, identification and their health. It also
 * determinates if the character is friendly, and if he has any message.
 *
 * @file character.c
 * @author Carmen Gómez Escobar
 * @version 3.5
 * @date 14-02-2024
 * @copyright GNU Public License
 */

#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Character
 *
 * This struct stores all the information of a character.
 */
struct _Character
{
    Id id;                       /*!< Id number of the character, it must be unique */
    char name[WORD_SIZE + 1];    /*!< Name of the character */
    int health;                  /*!< Id of the object that character has */
    Bool friendly;               /*!< Boolean of whether the caracther is a friend or an enemy */
    char message[WORD_SIZE + 1]; /*!< String with the message of that character */
};

/** character_create creates a new character, reserving dynamic memory and initializing its variables */
Character *character_create(Id id)
{
    Character *newCharacter = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;

    newCharacter = (Character *)malloc(sizeof(Character));
    if (newCharacter == NULL)
    {
        return NULL;
    }

    /* Initialization of an empty character*/
    newCharacter->id = id;
    newCharacter->name[0] = '\0';
    newCharacter->health = CHARACTER_HEALTH;
    newCharacter->friendly = FALSE;
    newCharacter->message[0] = '\0';

    return newCharacter;
}

/** character_destroy, destroys a character and releases the reserved memory */
Status character_destroy(Character *character)
{
    /* Error Control */
    if (!character)
    {
        return ERROR;
    }

    free(character);
    character = NULL;

    return OK;
}

/** character_get_id, gets the id of the character */
Id character_get_id(Character *character)
{
    /* Error Control */
    if (!character)
    {
        return NO_ID;
    }
    return character->id;
}

/** character_set_name, sets the name of the character */
Status character_set_name(Character *character, char *name)
{
    /* Error Control */
    if (!character || !name)
    {
        return ERROR;
    }

    if (!strcpy(character->name, name))
    {
        return ERROR;
    }
    return OK;
}

/** character_get_name, gets the name of the character */
const char *character_get_name(Character *character)
{
    /* Error Control */
    if (!character)
    {
        return NULL;
    }

    return character->name;
}

/** character_set_health, sets the health of the character */
Status character_set_health(Character *character, int health)
{
    /* Error Control */
    if (!character || health<=0)
    {
        return ERROR;
    }

    character->health = health;

    return OK;
}

/** character_get_health, gets the health of the character */
int character_get_health(Character *character)
{
    /* Error Control */
    if (!character)
    {
        return -1;
    }

    return character->health;
}

/** character_set_friendly, sets whether the character is friendly or not */
Status character_set_friendly(Character *character, Bool friendly)
{
    /* Error Control */
    if (!character )
    {
        return ERROR;
    }

    character->friendly = friendly;

    return OK;
}

/** character_get_friendly, gets whether the character is friendly or not*/
Bool character_get_friendly(Character *character)
{
    /* Error Control */
    if (!character)
    {
        return FALSE;
    }

    return character->friendly;
}

/** character_set_message, sets the message of the character */
Status character_set_message(Character *character, char *message)
{
    /* Error Control */
    if (!character || !message)
    {
        return ERROR;
    }

    if (!strcpy(character->message, message))
    {
        return ERROR;
    }
    return OK;
}

/** character_get_message, gets the message of the character */
const char *character_get_message(Character *character)
{
    /* Error Control */
    if (!character)
    {
        return NULL;
    }

    return character->message;
}

/** character_print_message, prints the message of the character */
Status character_print_message(Character *character)
{
    /* Error Control */
    if (!character)
    {
        return ERROR;
    }

    /* Print the message of the character */
    fprintf(stdout, "--> Message: %s\n", character->message);

    return OK;
}

/** character_print, prints the id and health of the character */
Status character_print(Character *character)
{
    /* Error Control */
    if (!character)
    {
        return ERROR;
    }

    fprintf(stdout, "--> Characters:\n");

    /* Print the character, its location and points of life */

    if (character_get_friendly(character) == FALSE)
    {
        fprintf(stdout, "-->  /\\oo/\\ : %ld, (%d)\n", character->id, character->health);
    }
    else if (character_get_friendly(character) == TRUE)
    {
        fprintf(stdout, "--> ^0m : %ld, (%d)\n", character->id, character->health);
    }

    /*Indication that the function has worked correctly*/
    return OK;
}
