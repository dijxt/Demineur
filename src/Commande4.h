#ifndef _FOURTHCOMMAND_
#define _FOURTHCOMMAND_

#pragma once
#include <iostream>
#include "Commande1.h"
#include "Commande2.h"

using namespace std;

/*@brief Permet de dire si la partie est perdue à partir d'une grille et d'un historique de coups
* @param[in] la grille
*/
void game_lost(Grille g);

#endif