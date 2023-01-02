#ifndef _FIRSTCOMMAND_
#define _FIRSTCOMMAND_

#pragma once
#include <iostream>
#include <assert.h>
#include <time.h>

using namespace std;

/*Le type problème est décrit par les nombres de lignes,
* de colonnes et de mines suivis par la position des mines.
*/
enum { MAX_CASES = 100 };
typedef struct {
    int nbLignes;
    int nbColonnes;
    int nbMines;
    bool posCase[MAX_CASES]; // tableau de valeurs booléennes 1 désigne qu'il y a une mine
}Probleme;

/*@brief Permet de définir un problème
* @param[in] le problème
*/
void def_prob(Probleme& p);

#endif
