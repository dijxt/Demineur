#ifndef _THIRDCOMMAND_
#define _THIRDCOMMAND_

#pragma once
#include <iostream>
#include "Commande1.h"
#include "Commande2.h"

using namespace std;

/*@brief Permet de dire si la partie est gagnée à partir d'une grille et d'un historique de coups
* @param[in] la grille
*/
void game_won(Grille g);

#endif