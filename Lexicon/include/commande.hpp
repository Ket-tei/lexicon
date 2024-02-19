#ifndef _COMMAND_
#define _COMMAND_

/**
 * @file commande.hpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief commande du lexicon
*/

#include "game.hpp"

/**
 * @brief commande pour tirer une carte dans le talon et depose une carte de son jeu dans le talon exposee
 * @param[in,out] main : liste modelisant la main du joueur actuel
 * @param[in] letter : lettre a deplace dans le talon exposee
 * @param[in,out] talon : pile modelisant le talon
 * @param[in,out] exposee : pile modelisant le talon exposee
 * @param[in,out] error : variable stockant les messages d'erreurs
*/
void command_T(Liste& main, Item& letter, Pile& talon, Pile& exposee, unsigned int& error);

/**
 * @brief commande pour tirer une carte dans le talon exposee et depose une carte de son jeu dans le talon exposee
 * @param[in,out] main : liste modelisant la main du joueur actuel
 * @param[in] letter : lettre a deplace dans le talon exposee
 * @param[in,out] exposee : pile modelisant le talon exposee
 * @param[in,out] error : variable stockant les messages d'erreurs
*/
void command_E(Liste& main, Item& letter, Pile& exposee, unsigned int& error);

/**
 * @brief commande pour poser un mot sur le plateau de jeu (si il est autorise)
 * @see verifyWord dans dictionnaire.hpp
 * @param[in,out] main : liste modelisant la main du joueur actuel
 * @param[in,out] score : score joueur actuel
 * @param[in] words_table : dictionnaire des mots autorises
 * @param[in] word : mot que le joueur actuel pose
 * @param[in,out] words : les mots pose sur le plateau
 * @param[in,out] words_index : l'index du dernier mots pose sur le plateau (ou le nombre de mots poses - 1)
 * @param[in,out] error : variable stockant les messages d'erreurs
*/
void command_P(Liste& main, unsigned int& score, Table& words_table, Item word[], Liste words[], unsigned int& words_index, unsigned int& error);

/**
 * @brief commande pour remplacer une carte d'un mot sur le plateau de jeu (si il est autorise)
 * @see verifyWord dans dictionnaire.hpp
 * @param[in,out] main : liste modelisant la main du joueur actuel
 * @param[in,out] score : score joueur actuel
 * @param[in] words_table : dictionnaire des mots autorises
 * @param[in] word : mot que le joueur actuel pose
 * @param[in,out] words : les mots pose sur le plateau
 * @param[in,out] words_place : l'index du mot indique par le joueur
 * @param[in,out] error : variable stockant les messages d'erreurs
*/
void command_R(Liste& main, unsigned int& score, Table& words_table, Item word[], Liste words[], unsigned int& word_place, unsigned int& error);

/**
 * @brief commande pour completer un mot sur le plateau de jeu (si il est autorise)
 * @see verifyWord dans dictionnaire.hpp
 * @param[in,out] main : liste modelisant la main du joueur actuel
 * @param[in,out] score : score joueur actuel
 * @param[in] words_table : dictionnaire des mots autorises
 * @param[in] word : mot que le joueur actuel pose
 * @param[in,out] words : les mots pose sur le plateau
 * @param[in,out] words_place : l'index du mot indique par le joueur
 * @param[in,out] error : variable stockant les messages d'erreurs
*/
void command_C(Liste& main, unsigned int& score, Table& words_table, Item word[], Liste words[], unsigned int& word_place, unsigned int& error);

#endif