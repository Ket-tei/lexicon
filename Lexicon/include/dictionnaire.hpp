#ifndef _DICO_
#define _DICO_

/* @file dictionnaire.hpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief fonctions concernant le dictionnaire de lexicon
*/

#include "table.hpp"

/**
 * @brief definie le dictionnaire des mots autorises
 * @param[out] words : Table d'element dans lequel on ajoute les mot du dictionnaire
*/
void defineDico(Table& words);

/**
 * @brief verifie si un mot est autorise
 * @param[in] words : Table d'element contenant les mots autorises
 * @param[in] word : mot que l'on verfie
 * @return true si le mot existe, false sinon
*/
bool verifyWord(const Table& words, const Item word[]);

#endif