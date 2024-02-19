#ifndef _VALUE_
#define _VALUE_

#include "stream.hpp"

/* Type Item */
typedef char Item;

#define MAX_WORD_CHAR 16
#define DECK_SIZE 51
#define MAX_LETTER 26
#define HAND_SIZE 10
#define MAX_WORD 26 // division entiere des lettres disponibles(51) par le plus petit mot de la liste(AA -> 2), plus le reste(1)
#define MAX_DICO_WORDS 369085
#define TAB_POINTS 65
#define MAX_POINTS 100
// Plus longue commande 
// -> la commande (R | C), 
// un numero (max 25 donc 2 caractères | expliquee a la ligne 13 du meme fichier),
// MAX_WORD_CHAR,
// et 2 espaces
#define MAX_LENGTH_LINE 21

#endif