/**
 * @file player.cpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief Composant de player
*/


#include "../include/stream.hpp"
#include "../include/player.hpp"

/**
 * @brief initialiser un joueur
 * @param[in] p : player qui est initialiser
 * @param[in] l : liste composant la main du joueur
*/
void initialiser(Player& p, Liste& l)
{
	p.main = l;
	p.score = 0;
}