#ifndef _GAME_
#define _GAME_

/**
 * @file game.hpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief fonctions generale du lexicon
*/

#include "player.hpp"

/**
 * @brief initialise la partie
 * @param[out] t_pile : pile modelisant le talon
 * @param[out] e_pile : pile modelisant le talon exposee
 * @param[out] players : player modelisant le joueur actuel
 * @param[in] nb_main : le nombre de joueur dont on initialise la main
*/
void game_initialiser(Pile& t_pile, Pile& e_pile, Player hands[], int& nb_main);

/**
 * @brief ecris les messages de la partie
 * @param[in] words : les mots pose sur le plateau
 * @param[in] words_index : l'index du dernier mots pose sur le plateau (ou le nombre de mots poses - 1)
 * @param[in] player_turn : numero du joueur actuel
 * @param[in] main : liste modelisant la main du joueur actuel
 * @param[in] exposee : pile modelisant le talon exposee
 * @param[in] error : variable stockant les messages d'erreurs
*/
void ecrire(const Liste* words, const unsigned int& words_index, const unsigned int& player_turn, const Liste& main, const Pile& exposee, const unsigned int& error);

/**
 * @brief ecris les message de fin de manche
 * @param[in] players : tableau contenant les joueurs
 * @param[in] NB_PLAYERS : nombre de joueur qui joue
*/
void ecrireEndGame(Player players[], int& NB_PLAYERS);

/**
 * @brief Verifie si le talon est vide, si oui le rempli avec le talon exposee
 * @param[in,out] talon : pile modelisant le talon
 * @param[in,out] exposee : pile modelisant le talon exposee
*/
void verifyDeck(Pile& talon, Pile& exposee);

/**
 * @brief Verifie si la manche est terminee, si oui met endGame a true pour arreter la manche
 * @param[in] players : tableau contenant les joueurs
 * @param[in,out] endGame : false si la manche se joue, true sinon 
 * @param[in] NB_PLAYERS : nombre de joueur qui joue
*/
void verifyEndGame(Player players[], bool& endGame, int& NB_PLAYERS);

/**
 * @brief Ajoute au score des joueurs les points des cartes de leur main
 * @param[in,out] players : tableau contenant les joueurs
 * @param[in] NB_PLAYERS : nombre de joueur qui joue
*/
void ajouterScore(Player players[], int& NB_PLAYERS);

/**
 * @brief Desallouer toutes les liste du tableau words
 * @see detruire dans liste.h
 * @param[in,out] words : le tableau de listes qui sont a desallouer
 * @param[in] initIndex : l'index du dernier mots pose sur le plateau (ou le nombre de mots poses - 1)
*/
void destruction(Liste words[], const unsigned int& initIndex);

#endif