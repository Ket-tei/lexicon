/**
 * @file  main.cpp
 * Jeu du Lexicon
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0 12/12/2023
*/

#include "../include/commande.hpp"

int main(int argc, char** argv)
{
  // commandes supportees
  cout << "(Commandes valides : TEPRC)" << endl;

  // creation d'un tableau pour transpose les mots du dictionnaire de mots valides
  Table words_table;
  initialiser(words_table, MAX_DICO_WORDS, MAX_WORD_CHAR);

  // remplissage du tableau par les mots du fichier ods.txt
  defineDico(words_table);

  // recuperation et convertissement du nombre de joueurs en parametre
  int NB_PLAYERS = atoi(argv[1]);
  unsigned int actual_nb_players;

  // Verifie que le nombre de joueurs est d'au moins 2 personnes et n'excede pas 4 
  if (NB_PLAYERS < 2 || NB_PLAYERS > 4) {
    cout << "Le nombre minimum de joueurs est de 2 et est maximum de 4" << endl;
    system("pause");
    return 0;
  }
  
  Liste ply1, ply2, ply3, ply4; // Creation des mains de jeu des 4 joueurs
  Liste main[] = {ply1, ply2, ply3, ply4};
  Player p1, p2, p3, p4;
  Player players[] = {p1, p2, p3, p4};
  for (unsigned int i=0;i<NB_PLAYERS;++i) initialiser(main[i], HAND_SIZE); // Initialise les mains des joueurs
  
  bool endGame;
  unsigned int nb_tour = 0;


  do {
    actual_nb_players = NB_PLAYERS;
    unsigned int words_index = 0; // initialisation de l'index du dernier mot pose sur le plateau (ou le nombre de mots poses)

    Pile talon; // Creation du Tas de cartes du talon
    Pile exposee; // Creation du Tas de cartes du exposee
    Liste mot1, mot2, mot3, mot4, mot5, mot6, mot7, mot8, mot9, mot10, mot11, mot12, mot13, mot14, mot15, mot16, mot17, mot18, mot19, mot20, mot21, mot22, mot23, mot24, mot25, mot26; 
    Liste words[MAX_WORD] = {mot1, mot2, mot3, mot4, mot5, mot6, mot7, mot8, mot9, mot10, mot11, mot12, mot13, mot14, mot15, mot16, mot17, mot18, mot19, mot20, mot21, mot22, mot23, mot24, mot25, mot26};

    for (unsigned int i = 0; i < NB_PLAYERS; ++i) {
      unsigned int temp;
      // Si le nombre de manche > 0 on garde en memoire le score puis on initialise le joueur puis on le redonne son score (sinon on initialise juste le joueur)
      if (nb_tour > 0) temp = players[i].score; // Variable temporaire pour garder en memoire le score des joueurs avant reinitialisation des joueurs 
      initialiser(players[i], main[i]); // Initialisation des joueurs
      if (nb_tour > 0) players[i].score = temp; // Reaffecte l'ancien score
    }
    

    
    // Initialise partie
    game_initialiser(talon, exposee, players, NB_PLAYERS);

    // Chaque tour de boucle correspond a une manche
    do {

      // Variable stockant le message d'erreur
      unsigned int error = 0;

      // Variable stockant la lettre de la commande (T | E | P | R | C)
      char command;
      // Variable stockant la lettre a deposer dans le talon exposee (T | E)
      Item letter;
      // Variable stockant le mot a poser (P | R | C)
      Item word[MAX_WORD_CHAR];
      // Variable stockant le mot a modifie (R | C)
      unsigned int word_place;
      char line[MAX_LENGTH_LINE];

      // Chaque tour correspond a un tour de joueurs
      for (unsigned int i = 0; i < NB_PLAYERS; ++i) {
        // Ne fais jouer que les joueurs non eliminés
        if (players[i].score <= 100)

          do {
            ecrire(words, words_index, i, players[i].main, exposee, error);

            cin.getline(line,MAX_LENGTH_LINE);
            istringstream is(line);
            is >> command;

            switch(command)
            {
              case 'T':
                is >> letter;

                command_T(players[i].main, letter, talon, exposee, error);
                break;

              case 'E':
                is >> letter;
                command_E(players[i].main, letter, exposee, error);
                break;

              case 'P':
                error = 0;
                is >> word;
                command_P(players[i].main, players[i].score, words_table, word, words, words_index, error);
                break;

              case 'R':
                error = 0;
                is >> word_place;
                --word_place;
                is >> word;
                command_R(players[i].main, players[i].score, words_table, word, words, word_place, error);
                break;

              case 'C':
                error = 0;
                is >> word_place;
                --word_place;
                is >> word;
                command_C(players[i].main, players[i].score, words_table, word, words, word_place, error);
                break;

              default:
                error = 1;
                break;
            }

          } while(error == 1);

        // Verifie si le talon est vide, si oui il le rempli avec le talon exposee
        verifyDeck(talon, exposee);
        // Verifie que c'est pas la fin de la manche
        verifyEndGame(players, endGame, NB_PLAYERS);

        if (endGame) break;
      }
    } while(!endGame);

    // Detruit tous les talons ainsi que les mots du plateau
    detruire(talon); detruire(exposee);
    destruction(words, words_index);

    // Ajoute au score des joueurs les points des cartes de leur main
    ajouterScore(players, NB_PLAYERS);
    
    ecrireEndGame(players, NB_PLAYERS);

    // Compte le nombre de joueur non elimine (joueur avec un score > 100)
    for (unsigned int i = 0; i < NB_PLAYERS; ++i) 
      if (players[i].score >= 100)
        --actual_nb_players;

    // Incremente le nombre de tour fais a chaque tour
    ++nb_tour;

  } while (actual_nb_players > 1); // Arrete le programme si il n'y a plus qu'un joueur qui peut jouer (score <= 100)
  
  // Detruit la Table des mots autorises
  detruire(words_table);

  cout << endl << "La partie est finie" << endl << endl;

  //
  system("pause"); 
  // 

  return 0;
}
