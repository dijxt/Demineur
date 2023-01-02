#ifndef _SECONDCOMMAND_
#define _SECONDCOMMAND_

#pragma once
#include <iostream>
#include "Commande1.h"

using namespace std;

enum { MAX_COUPS = 100 };
enum { MOT = 4 };


/*Un coup est d�fini par son type : D�masquer ou Marquer
* Et par l'indice de la case sur laquelle on souhaite jouer le coup
*/
typedef struct {
    char leCoup;
    int caseDuCoup;
}Coup;

/*Un historique de coup est d�fini par son nombres de coups,
* le nombre de mines autour de chaque cases
* si la case est marqu�e
* des coups jou�s
* si la case est jou�e
*/
typedef struct {
    int nbCoups;
    int minesAutour[MAX_CASES];
    bool marquee[MAX_CASES];
    Coup lesCoups[MAX_COUPS];
    bool caseJouee[MAX_CASES];
}HistCoups;


/*Une grille est compos�e d'un probl�me et d'un historique de coups
*/
typedef struct {
    Probleme prob;
    HistCoups couPrec;
}Grille;

/*@brief Permet d'afficher une grille
* @param[in] la grille
*
*/
void afficher_grille(Grille g);

/*@brief Permet d'initialiser une grille
* @param[in] la grille
*
*/
void init_grille(Grille& g);

/*@brief Permet de marquer une case de la grille
* @param[in] la grille
* @param[in] l'indice de la case
*/
void marquer(Grille& g, int indiceCase);

/*@brief Permet de d�miner une case de la grille
* @param[in] la grille
* @param[in] l'indice de la case
*
*/
void deminer(Grille& g, int indiceCase);

/*@brief Permet de jouer des coups sur une grille
* @param[in] la grille
*/
void jouer_des_coups(Grille& g);

#endif
