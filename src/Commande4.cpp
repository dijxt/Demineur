#include "Commande4.h"



/*@brief Permet de dire si la partie est perdue � partir d'une grille et d'un historique de coups
* @param[in] la grille
*/

void game_lost(Grille g) {
    bool cestperdu = 0;
    for (int i = 0; i < g.prob.nbColonnes * g.prob.nbLignes; ++i)
    {
        if (g.prob.posCase[i] == 1 && g.couPrec.caseJouee[i] == 1 && g.couPrec.marquee[i] == 0) // nous v�rifions si une mine a �t� d�min�e
        {
            cestperdu = 1;
        }

        if (g.prob.posCase[i] == 0 && g.couPrec.caseJouee[i] == 1 && g.couPrec.marquee[i] == 1) // nous v�rifions si une mauvaise case a �t� marqu�e
        {
            cestperdu = 1;
        }

    }


    if (cestperdu == 0)
    {
        cout << "game not lost";
    }
    else if (cestperdu == 1)
    {
        cout << "game lost";
    }
}