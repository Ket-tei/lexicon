/**
 * @file liste.cpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief Composant de liste
*/


#include "../include/stream.hpp"
#include "../include/liste.hpp"

/**
 * @brief Initialiser une liste vide
 * la liste est allouee en memoire dynamique
 * @see detruire, pour une desallocation en fin d'utilisation
 * @param[out] l : la liste a initialiser
 * @param[in] cap : capacite initiale de la liste
 * @pre capa > 0
*/
void initialiser(Liste& l, int cap)
{
  assert(cap > 0);
	l.elems = new Item[cap];
	l.capa = cap;
	l.taille = 0;
}

/**
 * @brief Test de liste vide
 * @param[in] l : la liste testee
 * @return true si l est vide, false sinon
*/
bool estVide(const Liste& l)
{
	return l.taille == 0;
}

/**
 * @brief Test de liste pleine
 * @param[in] l : la liste testee
 * @return true si l est pleine, false sinon
*/
bool estPleine(const Liste& l)
{
	return l.taille == l.capa;
}

/**
 * @brief Lire l'item a la position indiquee
 * @param[in,out] l : la liste
 * @param[in] pos : position de l'item a lire
 * @return la position de l'item de la liste a la position pos
 * @pre la liste n'est pas vide
*/
Item carte(const Liste& l, const int& pos)
{
	assert(!estVide(l));
	return l.elems[pos];
}

/**
 * @brief retourner vrai si l'Item est au moins une fois dans la liste
 * @param [in] l : liste dans laquel ont va verifier
 * @param [in] v : l'item que l'on verifie
 * @return true si l'item est dans la liste, sinon false
*/
bool verifier(const Liste& l, const Item v)
{
  for (unsigned int i = 0; i < l.taille; ++i) {
    if (l.elems[i] == v) return true;
  }
  return false;
}

/**
 * @brief permet d'inserer un item dans un une liste a la position indiquee
 * @param[in] l : liste dans laquel on insere l'item
 * @param[in] v : l'item à insérer
 * @param[in] pos : position a laquel l'item v est insere
 * @pre la liste n'est pas pleine
*/
void inserer(Liste& l, Item v, const int& pos)
{
	assert(!estPleine(l));
	Item temp[++l.taille];
  int i_p = 0;

  // recopie la liste l dans une liste temporaire (temp) en ajoutant l'item v
  for (unsigned int i = 0; i < l.taille; ++i) {
    // une fois la position pos atteinte, on ajoute a temp l'item v
    if (i == pos) {
      temp[i] = v;
    }
    // sinon on ajoute les items de l
    else {
      temp[i] = l.elems[i_p];
      ++i_p;
    }
  }

  // on recopie la liste temp dans l
  for (unsigned int i = 0; i < l.taille; ++i) {
    l.elems[i] = temp[i];
  }
}

/**
 * @brief supprime un item v de la liste
 * @param[in] l : liste dans laquel l'item va etre supprime
 * @param[in] v : l'item a supprimer
 * @pre la liste n'est pas vide
*/
void supprimer(Liste& l, Item v)
{
	assert(!estVide(l));
  Item temp[l.taille];
  int i_temp = 0;
  bool first = false;

  for (unsigned int i = 0; i < l.taille; ++i) {
    // Si l'element n'est pas l'item v on recopie l'item dans temp
    // si l'element est l'item v on ne le recopie pas et on change first a true
    // pour en supprimer un seul
    if (!first) {
      if (l.elems[i] != v) {
        temp[i_temp] = l.elems[i];
        ++i_temp;
      }
      else first = true;
    // Une fois l'element v rencontrer on recopie le reste de la liste
    } else {
      temp[i_temp] = l.elems[i];
      ++i_temp;
    }
  }

  // On efface tous les items de l (pour etre sur de ne pas avoir de caractere restant a la fin)
  for (unsigned int i = 0; i < l.taille; ++i) {
    l.elems[i] = '\0';
  }

  // On recopie temp dans l
  for (unsigned int i = 0; i < i_temp; ++i) {
    l.elems[i] = temp[i];
  }

  // On reduit la taille de la liste l de 1 car un item a ete supprime
  --l.taille;
}

/**
 * @brief Desallouer une liste
 * @see initialiser, la liste a deja ete initialisee
 * @param[out] l : la liste a desallouer
*/
void detruire(Liste& l)
{
	delete [] l.elems;
}