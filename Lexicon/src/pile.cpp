/**
 * @file pile.cpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief Composant de pile
*/


#include "../include/stream.hpp"
#include <time.h>

#include "../include/pile.hpp"


/**
 * @brief Initialiser une pile vide
 * la pile est allouee en memoire dynamique
 * @see detruire, pour une desallocation en fin d'utilisation
 * @param[out] p : la pile a initialiser
 * @param[in] cap : capacite initiale de la pile
 * @pre capa > 0
*/
void initialiser(Pile& p, int cap)
{
  assert(cap > 0);
	p.elems = new Item[cap];
	p.sommet = -1;
	p.capa = cap;
}

/**
 * @brief Test de pile vide
 * @param[in] p : la pile testee
 * @return true si p est vide, false sinon
*/
bool estVide(const Pile& p)
{
	return p.sommet == -1;
}

/**
 * @brief Test de pile pleine
 * @param[in] p : la pile testee
 * @return true si p est pleine, false sinon
*/
bool estPleine(const Pile& p)
{
	return p.sommet == p.capa - 1;
}

/**
 * @brief Empiler un item sur une pile
 * @param[in,out] p : la pile
 * @param[in] v : l'item a empiler
 * @pre la pile n'est pas pleine
*/
void empiler(Pile& p, Item v)
{
	assert(!estPleine(p));
	p.elems[++p.sommet] = v;
}

/**
 * @brief Depiler l'item au sommet de pile
 * @param[in,out] p : la pile
 * @return la valeur de l'item qui vient d'etre depiler
 * @pre la pile n'est pas vide
*/
Item depiler(Pile& p)
{
	assert(!estVide(p)); 
	return p.elems[p.sommet--];
}

/**
 * @brief Lire l'item au sommet de pile
 * @param[in] p : la pile
 * @return la valeur de l'item au sommet de pile
 * @pre la pile n'est pas vide
*/
Item sommet(const Pile& p)
{
	assert(!estVide(p));
	return p.elems[p.sommet];
}

/**
 * @brief Melange la pile de façon pseudo-aleatoire
 * @param[in,out] p : la pile
 * @pre la pile n'est pas vide
*/
void melanger(Pile& p)
{
  assert(!estVide(p));
  srand(time(0));

  Item list[p.capa];
  unsigned int j= 0;

  // On depile la pile dans une liste
  while (!estVide(p)) {
    list[j++] = sommet(p);
    depiler(p);
  }

  // On melange la liste
  for (unsigned int i = p.capa; i!=2; --i) {
    int j = rand()%(i-1);
    Item tmp = list[i-1];
    list[i-1] = list[j];
    list[j] = tmp;
  }

  // On empile les items melanges de la liste
  for (unsigned int i = 0; i < p.capa; ++i) empiler(p, list[i]);
}

/**
 * @brief Desallouer une pile
 * @see initialiser, la pile a deja ete initialisee
 * @param[out] p : la pile a desallouer
*/
void detruire(Pile& p)
{
	delete [] p.elems;
}