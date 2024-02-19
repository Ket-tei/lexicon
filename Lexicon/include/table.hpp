#ifndef _TABLE_
#define _TABLE_

/**
 * @file table.hpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief Composant de table
*/

#include "liste.hpp"

/* Type de table */
struct Table
{
	Item** elems;
	int capa;
	int taille;
};
  
/**
 * @brief initialiser une table
 * @see detruire, pour une desallocation en fin d'utilisation
 * @param[in] t : table qui est initialiser
 * @param[in] cap : capacite de la table
 * @param[in] size : taille d'un element de la table
*/
void initialiser(Table& t, int cap, int size);

/**
 * @brief Desallouer une table
 * @see initialiser, la table a deja ete initialisee
 * @param[out] t : la table a desallouer
*/
void detruire(Table& t);

#endif