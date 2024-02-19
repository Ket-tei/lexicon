#ifndef _PILE_
#define _PILE_

/**
 * @file pile.hpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief Composant de pile
*/

#include "valueInit.hpp"

/* Type pile */
struct Pile
{
	Item* elems;
	int sommet ;
	int capa;
};


/**
 * @brief Initialiser une pile vide
 * la pile est allouee en memoire dynamique
 * @see detruire, pour une desallocation en fin d'utilisation
 * @param[out] p : la pile a initialiser
 * @param[in] cap : capacite initiale de la pile
 * @pre capa > 0
*/
void initialiser(Pile& p, int cap);

/**
 * @brief Test de pile vide
 * @param[in] p : la pile testee
 * @return true si p est vide, false sinon
*/
bool estVide(const Pile& p);

/**
 * @brief Test de pile pleine
 * @param[in] p : la pile testee
 * @return true si p est pleine, false sinon
*/
bool estPleine(const Pile& p);

/**
 * @brief Empiler un item sur une pile
 * @param[in,out] p : la pile
 * @param[in] v : l'item a empiler
 * @pre la pile n'est pas pleine
*/
void empiler(Pile& p, Item v);

/**
 * @brief Depiler l'item au sommet de pile
 * @param[in,out] p : la pile
 * @pre la pile n'est pas vide
*/
Item depiler(Pile& p);

/**
 * @brief Lire l'item au sommet de pile
 * @param[in] p : la pile
 * @return la valeur de l'item au sommet de pile
 * @pre la pile n'est pas vide
*/
Item sommet(const Pile& p);

/**
 * @brief Melange la pile de façon pseudo-aleatoire
 * @param[in,out] p : la pile
 * @pre la pile n'est pas vide
*/
void melanger(Pile& p);

/**
 * @brief Desallouer une pile
 * @see initialiser, la pile a deja ete initialisee
 * @param[out] p : la pile a desallouer
*/
void detruire(Pile& p);

#endif