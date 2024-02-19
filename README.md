# Lexicon



# R1.01 – Initiation au développement  
## S1.02 Comparaison d’approches algorithmiques 

##### Raphaël DESMONTS
##### Juliette COURNON

GROUPE - 107 | 108

*raphael.desmonts@etu.u-paris.fr*

*juliette.cournon@etu.u-paris.fr*

### BUT Informatique – Semestre 1

#

## Table des matières


### Introduction au projet……………………………… p.3

### Graphe de dépendance…………………………………… p.4

### Tests unitaires………………………………………………… – 

### Bilan du projet………………………………………………… p.5

### Annexe………………………………………………………………………… p.7

#

## Introduction au projet

Le projet a pour objectif de créer un jeu de Lexicon (Jeu du Lexicon). On doit créer 4 commande (T | E | P | R | C). Ces fonctions permettent respectivement de tirer une carte dans le Talon (en posant obligatoirement une carte dans la défausse), de tirer la carte en haut de la défausse (visible par tout le monde, en posant obligatoirement une carte dans la défausse), de poser un mot (si on a les lettres nécessaires et que le mot existe dans le dictionnaire du Lexicon), de remplacer une ou plusieurs lettres d’un mot déjà posé (sans changer l’ordre et en ayant ces lettres dans notre main), de compléter un mot, c’est à dire d’ajouter des lettres à un mot déjà posé (sans changer l’ordre des lettres, en utilisant toutes les lettres du mot précédent et en ayant ces lettres dans notre main). 
Notre programme ne doit en AUCUN cas s'arrêter brutalement. Les erreurs de saisie doivent être prises en compte. De plus le programme peut se jouer à 2, 3 ou 4 joueurs (argument qui doit être précisé à l'exécution du programme -> Ex: ./lexicon.exe 2). Chaque joueur à un score et en fonction de celui-ci il peut être éliminé (éliminé si le score excède 100 points). Ce score est augmenté à chaque fin de manche (lorsqu'un joueur n’a plus de cartes) et le reste des joueurs se voient leur score augmenter en fonction des cartes qu’il leur reste et des points associé à chaque carte. 

Et ce programme s’arrête lorsqu’il a 1 ou moins de 1 joueur.

#

## Graph de dépendance



Graph de dépendance du Lexicon

#


## Bilan du projet

**Difficultés:**
Durant ce projet nous avons été confrontés à de nombreuses difficultés. Tout d’abord nous avons eu du mal à gérer la séparation du projet en plusieurs parties afin de le rendre cohérent mais tout en continuant à fonctionner.						Dans le fichier dictionnaire.cpp et dictionnaire.hpp, pour la commande qui sert à vérifier si le mot testé est dans la liste des mots du dictionnaire fournis, nous avons commencé en utilisant une simple boucle for, mais afin d’optimiser nous avons voulu faire en sorte que la recherche se fasse par dichotomie. La difficulté a été de savoir comment comparer par ordre alphabétique le mot cherché et les mots du dictionnaire. Nous avons résolu le problème en utilisant avec un strcmp.		 							     En débutant le projet, lorsque le programme devait trouver un mot, il ouvrait le fichier dictionnaire à chaque fois. Nous avons donc utilisé defineDico qui permet de ne pas avoir à ouvrir le fichier à chaque fois pour le lire. Le fichier est ouvert une fois au début du programme et est chargé dans un tableau à deux dimensions. Ainsi, au lieu d’avoir un léger ralentissement à chaque fois que le fichier doit être ouvert, il y en a un unique au moment du lancement du programme, le temps que tous les mots du ods4.txt soient copiés dans le tableau.											    Nous avons eu du mal à savoir s’il fallait utiliser des commandes plus basiques telles que if/else ou des switch, comme par exemple dans le main.cpp, où nous avons mis un switch case pour tester la commande pour TEPRC.						    


**Optimisations:**
Afin d’optimiser le code, nous avons réalisé plusieurs modifications, dont certaines citées plus tôt, car nous avons eu des difficultés à les réaliser. Premièrement la dichotomie afin de rendre la recherche plus rapide. Ensuite, la création du tableau à deux dimensions pour n’avoir à ouvrir le fichier dictionnaire qu’une fois, aussi dans le but d'accélérer l'exécution, tout comme l’utilisation de switch case.			    De plus, nous avons utilisé en grande majorité des références, des unsigned int et const dès que l’on pouvait, afin d’occuper moins d’espaces mémoire.		     Afin de rendre le tout plus modulable, nous avons fait en sorte que liste, pile et table n’utilise pas de char mais des structures d’item, qui sont des char, mais plus modulable, pour qu’ils puissent être importé dans n’importe quel programme. 	      Toujours pour gagner de l’espace, nous avons utilisé des tableaux dynamiques, en faisant en sorte d’être détruits à la fin.							Pour continuer, tous les commentaires de fonctions suivent une syntaxe normée qui permet, par exemple, avec Doxygen, de créer un graphe de dépendance et des documentations à partir de ces fichiers.							  Au début nous utilisions plusieurs cin à la suite pour récupérer ce que l’utilisateur écrit, mais cela pouvait poser problème, notamment l'exécutable qui pouvait crasher si il y avait une erreur de saisie, et donc avoir des comportement incompréhensible, et dont on pouvait difficilement gérer les erreurs. Nous avons donc décidé d’utiliser getline pour récupérer toute la ligne. Par la suite, nous avons défini un istringstream où nous lui donnons la ligne récupérée et il est donc plus facile de rediriger la lettre ou le mot vers la commande. C’est géré plus facilement et il n’y a plus de crash du programme.											Pour finir, étant donné que nous compilons sur VSCode avec GCC comme compilateur, nous avons mis des système(“pause”) juste avec le return 0 du main.cpp, afin que le programme ne se ferme pas dès que la partie est finie.

#


## Annexe

En annexe vous trouverez le programme principale qui est nommé lexicon.exe et se trouve dans le dossier programme, les fichiers .cpp sont dans le dossier src, et les .hpp sont dans le dossier include.


Raphaël DESMONTS, Juliette Cournon
























