/**
 * @file dictionnaire.cpp
 * Jeu du Lexicon | Projet periode B
 * @author DESMONTS Raphaël et COURNON Juliette
 * @version 1.0
 * @brief fonctions concernant le dictionnaire de lexicon
*/


#include "../include/stream.hpp"
#include <fstream>
#include "../include/dictionnaire.hpp"

/**
 * @brief definie le dictionnaire des mots autorises
 * @param[out] words : Table d'element dans lequel on ajoute les mot du dictionnaire
*/
void defineDico(Table& words)
{
  int i = 0;

  // Ouvre le fichier .txt contenant les mots autorises au lexicon
  ifstream fileIn;
  fileIn.open("../ods4.txt",ios::in);

  // Ajoute a la table tous les mots du fichier .txt
  while (i < MAX_DICO_WORDS) {
    fileIn >> words.elems[i++];
  }

  // Ferme le fichier .txt
  fileIn.close();
}

/**
 * @brief verifie si un mot est autorise
 * @param[in] words : Table d'element contenant les mots autorises
 * @param[in] word : mot que l'on verfie
 * @return tru si le mot existe, false sinon
*/
bool verifyWord(const Table& words, const Item word[])
{
  int gauche = 0;
  int droite = MAX_DICO_WORDS - 1;

  while (gauche <= droite) {
      int milieu = (gauche + droite) / 2;
      int comparaison = strcmp(words.elems[milieu], word);

      if (comparaison == 0) {
          // Le mot a été trouvé
          return true;
      } else if (comparaison < 0) {
          // Le mot est dans la moitié droite
          gauche = milieu + 1;
      } else {
          // Le mot est dans la moitié gauche
          droite = milieu - 1;
      }
  }

  // Le mot n'a pas été trouvé
  return false;
}