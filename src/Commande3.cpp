#include "Commande3.h"

/*@brief Permet de dire si la partie est gagn�e � partir d'une grille et d'un historique de coups
* @param[in] la grille
*/

void game_won(Grille g) {
    bool cestperdu = 0;
    bool cestfinit = 0;
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

        if (g.prob.posCase[i] == 0 && g.couPrec.caseJouee[i] == 0) // nous v�rifions si la partie est termin�e
        {
            cestfinit = 1;
        }
    }


    if (cestfinit == 0 && cestperdu == 0)
    {
        cout << "game won";
    }
    else if (cestfinit == 1 || cestperdu == 1)
    {
        cout << "game not won";
    }
}