#ifndef _LISTE_
#define _LISTE_

/**
 * @file liste.hpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief Composant de liste
*/

#include "pile.hpp"

/* Type liste */
struct Liste
{
	Item* elems;
	int capa;
	int taille;
};

/**
 * @brief Initialiser une liste vide
 * la liste est allouee en memoire dynamique
 * @see detruire, pour une desallocation en fin d'utilisation
 * @param[out] l : la liste a initialiser
 * @param[in] cap : capacite initiale de la liste
 * @pre capa > 0
*/
void initialiser(Liste& l, int cap);

/**
 * @brief Test de liste vide
 * @param[in] l : la liste testee
 * @return true si l est vide, false sinon
*/
bool estVide(const Liste& l);

/**
 * @brief Test de liste pleine
 * @param[in] l : la liste testee
 * @return true si l est pleine, false sinon
*/
bool estPleine(const Liste& l);

/**
 * @brief Lire l'item a la position indiquee
 * @param[in,out] l : la liste
 * @param[in] pos : position de l'item a lire
 * @return la position de l'item de la liste a la position pos
 * @pre la liste n'est pas vide
*/
Item carte(const Liste& l, const int& pos);

/**
 * @brief retourner vrai si l'Item est au moins une fois dans la liste
 * @param [in] l : liste dans laquel ont va verifier
 * @param [in] v : l'item que l'on verifie
 * @return true si l'item est dans la liste, sinon false
*/
bool verifier(const Liste& l, const Item v);

/**
 * @brief permet d'inserer un item dans un une liste a la position indiquee
 * @param[in] l : liste dans laquel on insere l'item
 * @param[in] v : l'item à insérer
 * @param[in] pos : position a laquel l'item v est insere
 * @pre la liste n'est pas pleine
*/
void inserer(Liste& l, Item v, const int& pos);

/**
 * @brief supprime un item v de la liste
 * @param[in] l : liste dans laquel l'item va etre supprime
 * @param[in] v : l'item a supprimer
 * @pre la liste n'est pas vide
*/
void supprimer(Liste& l, Item v);

/**
 * @brief Desallouer une liste
 * @see initialiser, la liste a deja ete initialisee
 * @param[out] l : la liste a desallouer
*/
void detruire(Liste& l);

#endif