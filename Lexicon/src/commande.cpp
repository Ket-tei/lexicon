/**
 * @file commande.cpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief commande du lexicon
*/


#include "../include/stream.hpp"
#include "../include/commande.hpp"

/**
 * @brief commande pour tirer une carte dans le talon et depose une carte de son jeu dans le talon exposee
 * @param[in,out] main : liste modelisant la main du joueur actuel
 * @param[in] letter : lettre a deplace dans le talon exposee
 * @param[in,out] talon : pile modelisant le talon
 * @param[in,out] exposee : pile modelisant le talon exposee
 * @param[in,out] error : variable stockant les messages d'erreurs
*/
void command_T(Liste& main, Item& letter, Pile& talon, Pile& exposee, unsigned int& error)
{
  // Si la lettre a depose sur le talon exposee est dans la main du joueur actuel
  // on depose la carte sur le talon exposee
  // et on recupere la carte dans le talon pour l'inserer dans la main
  if (verifier(main, letter)) {
    empiler(exposee, letter);
    supprimer(main, letter);

    inserer(main, sommet(talon), 0);
    depiler(talon);
    error = 0;
  }
  else error = 1;
}

/**
 * @brief commande pour tirer une carte dans le talon exposee et depose une carte de son jeu dans le talon exposee
 * @param[in,out] main : liste modelisant la main du joueur actuel
 * @param[in] letter : lettre a deplace dans le talon exposee
 * @param[in,out] exposee : pile modelisant le talon exposee
 * @param[in,out] error : variable stockant les messages d'erreurs
*/
void command_E(Liste& main, Item& letter, Pile& exposee, unsigned int& error)
{
  // Si la lettre a depose sur le talon exposee est dans la main du joueur actuel
  // on enleve la carte de la main et on insere la carte du talon exposee
  // et on depose la carte sur le talon exposee
  if (verifier(main, letter)) {
    supprimer(main, letter);
    inserer(main, sommet(exposee), 0);
    depiler(exposee);

    empiler(exposee, letter);
    error = 0;
  }
  else error = 1;
}

/**
 * @brief commande pour poser un mot sur le plateau de jeu (si il est autorise)
 * @see verifyWord dans dictionnaire.hpp
 * @param[in,out] main : liste modelisant la main du joueur actuel
 * @param[in,out] score : score joueur actuel
 * @param[in] words_table : dictionnaire des mots autorises
 * @param[in] word : mot que le joueur actuel pose
 * @param[in,out] words : les mots pose sur le plateau
 * @param[in,out] words_index : l'index du dernier mot pose sur le plateau (ou le nombre de mots poses - 1)
 * @param[in,out] error : variable stockant les messages d'erreurs
*/
void command_P(Liste& main, unsigned int& score, Table& words_table, Item word[], Liste words[], unsigned int& words_index, unsigned int& error)
{
  unsigned int j = 0;

  // On verfie que le mot est autorise, sinon on penalise le joueur actuel de 
  // 3 points
  if (!verifyWord(words_table, word)) {
    cout << "Mot invalide, vous passez votre tour" << endl;
    score += 3;
    error = 2;
    return;
  }

  // On verifie que les lettres du mot a poser existe dans la main du joueur
  for (unsigned int j = 0; j < strlen(word) ; ++j) {
    if (!verifier(main, word[j])) {
      error = 1;
      break;
    }
  }

  // Si il n'y a aucune erreur on pose le mot et on enleve les lettre de la main
  if (!error) {
    initialiser(words[words_index], MAX_WORD_CHAR);

    for (unsigned int j = 0; j < strlen(word); ++j) {
      inserer(words[words_index], word[j], j);
      supprimer(main, word[j]);
    }
    error = 0;
    // On incremente l'index du dernier mot pose sur le plateau (ou le nombre 
    // de mots poses - 1)
    ++words_index;
  }
  else error = 1;
}


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
void command_R(Liste& main, unsigned int& score, Table& words_table, Item word[], Liste words[], unsigned int& word_place, unsigned int& error)
{
  unsigned int min_replace = 0;

  // On verfie que le mot est autorise, sinon on penalise le joueur actuel 
  // de 3 points
  if (!verifyWord(words_table, word)) {
    score += 3;
    cout << "Mot invalide, vous passez votre tour" << endl;
    error = 2;
    return;
  }

  // On verifie qu'il n'y a pas de lettre ajoute, que les deux mots font la 
  // meme longueur
  if (strlen(word) != words[word_place].taille) {
    error = 1;
  }

  // On verifie qu'il y a eu au moins une lettre de remplacer (sinon le joueur 
  // pourrait passer son tour)
  for (unsigned int j = 0; j < strlen(word); ++j) {
    if (words[word_place].elems[j] != word[j]) {
      ++min_replace;
      // On verifie que les lettre a remplacer sont bien dans la main
      if (!verifier(main,word[j])) {
        error = 1;
        break;
      }
    }
  }

  // Si il n'y a aucune erreur et qu'il y'a au moins une lettre de remplacer 
  // on pose le mot remplacer en enlevant l'ancien et on enleve les lettre de 
  // la main
  if (!error && min_replace) {
    for (unsigned int j = 0; j < strlen(word); ++j) {
      if (words[word_place].elems[j] != word[j]) {
        supprimer(main, word[j]);
        inserer(main,words[word_place].elems[j], 0);
        supprimer(words[word_place], words[word_place].elems[j]);
        inserer(words[word_place], word[j], j);
      }
    }
  }
  else error = 1;
}

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
void command_C(Liste& main, unsigned int& score, Table& words_table, Item word[], Liste words[], unsigned int& word_place, unsigned int& error)
{
  unsigned int order = 0;
  
  // On verfie que le mot est autorise, sinon on penalise le joueur actuel 
  // de 3 points
  if (!verifyWord(words_table, word)) {
    score += 3;
    cout << "Mot invalide, vous passez votre tour" << endl;
    error = 2;
    return;
  }

  // Verifie que le mot a ete complete et qu'il y'a donc au moins une lettre en plus
  // if (strlen(word) <= strlen(words[word_place])) error = 1;

  // On verifie que les lettres qui completent le mot reste dans leur ordre 
  // originel
  for (unsigned int j = 0; j < strlen(word); ++j) {
    // On verifie que les que les lettres qui completent sont dans la main
    if (words[word_place].elems[order] != word[j]) {
      if (!verifier(main,word[j])) {
        error = 1;
      }
    }
    else ++order;
  }

  // Si il n'y a aucune erreur et que l'ordre est respecte on pose le mot 
  // completer en enlevant l'ancien et on enleve les lettre de la main
  if (!error && (order == words[word_place].taille)) {

    detruire(words[word_place]);
    initialiser(words[word_place], MAX_WORD_CHAR);

    for (unsigned int j = 0; j < strlen(word); ++j) {
      supprimer(main, word[j]);
      inserer(words[word_place],word[(strlen(word)-j)-1],0);
    }
  }
  else error = 1;
}