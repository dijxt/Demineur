#ifndef _FIRSTCOMMAND_
#define _FIRSTCOMMAND_

#pragma once
#include <iostream>
#include <assert.h>
#include <time.h>

using namespace std;

/*Le type probl�me est d�crit par les nombres de lignes,
* de colonnes et de mines suivis par la position des mines.
*/
enum { MAX_CASES = 100 };
typedef struct {
    int nbLignes;
    int nbColonnes;
    int nbMines;
    bool posCase[MAX_CASES]; // tableau de valeurs bool�ennes 1 d�signe qu'il y a une mine
}Probleme;

/*@brief Permet de d�finir un probl�me
* @param[in] le probl�me
*/
void def_prob(Probleme& p);

#endif
