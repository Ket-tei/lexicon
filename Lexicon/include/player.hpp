#ifndef _PLAYER_
#define _PLAYER_

/**
 * @file player.hpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief Composant de player
*/

#include "dictionnaire.hpp"

/* Type player */
struct Player
{
	Liste main;
	unsigned int score;
};

/**
 * @brief initialiser le score des joueurs
 * @param[in] p player
 * @param[in] l liste
*/
void initialiser(Player& p, Liste& l);

#endif