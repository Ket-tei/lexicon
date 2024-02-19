/**
 * @file table.cpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief Composant de table
*/


#include "../include/stream.hpp"
#include "../include/table.hpp"
  
/**
 * @brief initialiser une table
 * @see detruire, pour une desallocation en fin d'utilisation
 * @param[in] t : table qui est initialiser
 * @param[in] cap : capacite de la table
 * @param[in] size : taille d'un element de la table
*/
void initialiser(Table& t, int cap, int size)
{
	t.elems = new Item*[cap];
  for (unsigned int i = 0; i < cap; ++i) {
    t.elems[i] = new Item[size];
  }
	t.capa = cap;
	t.taille = 0;
}

/**
 * @brief Desallouer une table
 * @see initialiser, la table a deja ete initialisee
 * @param[out] t : la table a desallouer
*/
void detruire(Table& t)
{
	for (unsigned int i = 0; i < t.taille; ++i) {
		delete [] t.elems[i];
	}
	delete [] t.elems;
}