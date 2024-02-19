/**
 * @file game.cpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief fonctions generale du lexicon
*/


#include "../include/stream.hpp"
#include "../include/game.hpp"

/**
 * @brief initialise la partie
 * @param[out] t_pile : pile modelisant le talon
 * @param[out] e_pile : pile modelisant le talon exposee
 * @param[out] players : player modelisant le joueur actuel
 * @param[in] nb_main : le nombre de joueur dont on initialise la main
*/
void game_initialiser(Pile& t_pile, Pile& e_pile, Player players[], int& nb_main)
{
  Item tab_letter[MAX_LETTER];
  // Le nombre de carte par lettre (ex: 2 pour le A en indice 0)
  unsigned int tab_letter_nb[] = {2,2,2,2,5,1,2,2,4,1,1,2,1,3,2,1,1,3,3,3,3,1,1,1,1,1};
  
  for (unsigned int i = 0; i < (MAX_LETTER); ++i) tab_letter[i] = TAB_POINTS+i;
  tab_letter[MAX_LETTER] = '\0';

  // Initialisation des deux piles (talon et talon exposee)
  initialiser(t_pile, DECK_SIZE);
  initialiser(e_pile, DECK_SIZE);
  
  // Remplie le talon de cartes avec les cartes a jouer
  for (unsigned int i = 0; i < MAX_LETTER; ++i) {
    for (unsigned int j = 0; j < tab_letter_nb[i]; ++j) {
      empiler(t_pile, tab_letter[i]);
    }
  }

  // Melange le talon de cartes
  melanger(t_pile);

  // Distribue cartes aux joueurs
  for (unsigned int i = 0; i < nb_main; ++i) {
    for (unsigned int j = 0; j < HAND_SIZE; ++j) {
      inserer(players[i].main, sommet(t_pile), 0);
      depiler(t_pile);
    }
  }

  // Met la premiere carte du talon sur le tas exposee
  empiler(e_pile, sommet(t_pile));
  depiler(t_pile);

}

/**
 * @brief ecris les messages de la partie
 * @param[in] words : les mots pose sur le plateau
 * @param[in] words_index : l'index du dernier mots pose sur le plateau (ou le nombre de mots poses - 1)
 * @param[in] player_turn : numero du joueur actuel
 * @param[in] main : liste modelisant la main du joueur actuel
 * @param[in] exposee : pile modelisant le talon exposee
 * @param[in] error : variable stockant les messages d'erreurs
*/
void ecrire(const Liste* words, const unsigned int& words_index, const unsigned int& player_turn, const Liste& main, const Pile& exposee, const unsigned int& error)
{
  // Ecris si il y a une erreur de syntaxe ou si le la carte n'est pas dans le jeu
  if (error == 1) cout << "Coup invalide, recommencez" << endl;

  // Ecris le numero du joueur actuel, le sommet du talon exposee
  cout << endl << "* Joueur " << player_turn+1 << " (" << sommet(exposee) << ") ";
  // Ecris les cartes du joueur actuel
  for (unsigned int i = 0; i < main.taille; ++i) cout << carte(main, i);
  // Ecris les mots du plateau
  for (unsigned int i = 0; i < words_index; ++i) {
    cout << endl << i+1 << " - ";
    for (unsigned int j = 0; j < words[i].taille; ++j) cout << words[i].elems[j];
  }
  cout << endl << "> ";
}

/**
 * @brief ecris les message de fin de manche
 * @param[in] players : tableau contenant les joueurs
 * @param[in] NB_PLAYERS : nombre de joueur qui joue
*/
void ecrireEndGame(Player players[], int& NB_PLAYERS)
{
  cout << endl << "Le tour est fini" << endl << "* Scores" << endl;
  for (unsigned int i = 0; i < NB_PLAYERS; ++i)
      cout << "Joueur " << i+1 << " : " << players[i].score << " points" << endl;
}

/**
 * @brief Verifie si le talon est vide, si oui le rempli avec le talon exposee
 * @param[in,out] talon : pile modelisant le talon
 * @param[in,out] exposee : pile modelisant le talon exposee
*/
void verifyDeck(Pile& talon, Pile& exposee)
{
  if (estVide(talon)) {
  // Si le talon est vide on vide le talon exposee et on remplit le talon
    for (unsigned int i = 0; i < DECK_SIZE; ++i) {
      empiler(talon, sommet(exposee));
      depiler(exposee);
    }
    // On melange le talon et on retourne une carte dans le talon exposee
    melanger(talon);
    empiler(exposee, sommet(talon));
    depiler(talon);
  }
}

/**
 * @brief Verifie si la manche est terminee, si oui met endGame a true pour arreter la manche
 * @param[in] players : tableau contenant les joueurs
 * @param[in,out] endGame : false si la manche se joue, true sinon 
 * @param[in] NB_PLAYERS : nombre de joueur qui joue
*/
void verifyEndGame(Player players[], bool& endGame, int& NB_PLAYERS)
{
  endGame = false;
  for (unsigned int j = 0; j < NB_PLAYERS; ++j) {
    if (estVide(players[j].main)) endGame = true;
  } 
}

/**
 * @brief Ajoute au score des joueurs les points des cartes de leur main
 * @param[in,out] players : tableau contenant les joueurs
 * @param[in] NB_PLAYERS : nombre de joueur qui joue
*/
void ajouterScore(Player players[], int& NB_PLAYERS)
{
  // Tableau des points en fonction de la lettre (Ex: A -> premiere lettre alphabet -> points correspondant a la lettre au premier indice (0))
  unsigned int points[] = {2,2,2,2,5,1,2,2,4,1,1,2,1,3,2,1,1,3,3,3,3,1,1,1,1,1};
  // Ajoute pour chaque joueur les points des cartes qu'il lui reste en main a son score
  for (unsigned int i = 0; i < NB_PLAYERS; ++i) {
    for (unsigned int j = 0; j < players[i].main.taille; ++j) {
      // Ajoute a score le point qui a pour indice le code ASCII de la carte - le code ASCII de la premiere lettre
      players[i].score += points[int(players[i].main.elems[j])-(TAB_POINTS)];
    }
  }
}

/**
 * @brief Desallouer toutes les liste du tableau words
 * @see detruire dans liste.h
 * @param[in,out] words : le tableau de listes qui sont a desallouer
 * @param[in] initIndex : l'index du dernier mots pose sur le plateau (ou le nombre de mots poses - 1)
*/
void destruction(Liste words[], const unsigned int& initIndex)
{
  for (unsigned int i = 0; i < initIndex; ++i) detruire(words[i]);
}