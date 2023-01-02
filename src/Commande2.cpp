#include "Commande2.h"

using namespace std;


/*@brief Permet d'afficher une grille
* @param[in] la grille
*
*/
void afficher_grille(Grille g) {
    int numCase = 0;
    cout << g.prob.nbLignes << " " << g.prob.nbColonnes << endl;
    for (int i = 0; i < g.prob.nbLignes; i++)
    {
        for (int j = 0; j < g.prob.nbColonnes; j++)
        {
            cout << " ___";
        }
        cout << endl;
        for (int j = 0; j < g.prob.nbColonnes; j++)
        {
            cout << "| ";
            if (g.couPrec.caseJouee[numCase] == 0)
            {
                cout << ".";
            }
            else if (g.couPrec.caseJouee[numCase] == 1 && g.couPrec.marquee[numCase] == 1)
            {
                cout << "x";
            }
            else if (g.couPrec.caseJouee[numCase] == 1 && g.prob.posCase[numCase] == 0 && g.couPrec.minesAutour[numCase] > 0)
            {
                cout << g.couPrec.minesAutour[numCase];
            }
            else if (g.couPrec.caseJouee[numCase] == 1 && g.prob.posCase[numCase] == 1)
            {
                cout << "m";
            }
            else if (g.couPrec.caseJouee[numCase] == 1 && g.prob.posCase[numCase] == 0 && g.couPrec.minesAutour[numCase] == 0)
            {
                cout << " ";
            }
            cout << " ";
            ++numCase;
        }
        cout << "|";
        cout << endl;
    }
    for (int j = 0; j < g.prob.nbColonnes; j++)
    {
        cout << " ___";
    }
}

/*@brief Permet d'initialiser une grille
* @param[in] la grille
*
*/
void init_grille(Grille& g) {
    cin >> g.prob.nbLignes;
    cin >> g.prob.nbColonnes;
    cin >> g.prob.nbMines;
    for (int i = 0; i < g.prob.nbColonnes * g.prob.nbLignes; i++) // Initialise les variables à 0
    {
        g.couPrec.caseJouee[i] = 0;
        g.couPrec.marquee[i] = 0;
        g.prob.posCase[i] = 0;
    }
    for (int j = 0; j < g.prob.nbMines; j++) // Demande une entrée des positions de mines
    {
        int tmp;
        cin >> tmp;
        g.prob.posCase[tmp] = 1;
    }
    for (int i = 0; i < g.prob.nbColonnes * g.prob.nbLignes; i++) // on initialise le nombre de mines autour de chaque cases
    {
        g.couPrec.minesAutour[i] = 0;
        if (i - g.prob.nbColonnes - 1 >= 0 && g.prob.posCase[i - g.prob.nbColonnes - 1] == 1 && i % g.prob.nbColonnes != 0)
        {
            ++g.couPrec.minesAutour[i];
        }
        if (i - g.prob.nbColonnes >= 0 && g.prob.posCase[i - g.prob.nbColonnes] == 1)
        {
            ++g.couPrec.minesAutour[i];
        }
        if (i - g.prob.nbColonnes + 1 >= 0 && g.prob.posCase[i - g.prob.nbColonnes + 1] == 1 && (i + 1) % g.prob.nbColonnes != 0)
        {
            ++g.couPrec.minesAutour[i];
        }
        if (i - 1 >= 0 && g.prob.posCase[i - 1] == 1 && (i) % g.prob.nbColonnes != 0)
        {
            ++g.couPrec.minesAutour[i];
        }
        if (i + 1 <= g.prob.nbColonnes * g.prob.nbLignes && g.prob.posCase[i + 1] == 1 && (i + 1) % g.prob.nbColonnes != 0)
        {
            ++g.couPrec.minesAutour[i];
        }
        if (i + g.prob.nbColonnes - 1 <= g.prob.nbColonnes * g.prob.nbLignes && g.prob.posCase[i + g.prob.nbColonnes - 1] == 1 && i % g.prob.nbColonnes != 0)
        {
            ++g.couPrec.minesAutour[i];
        }
        if (i + g.prob.nbColonnes <= g.prob.nbColonnes * g.prob.nbLignes && g.prob.posCase[i + g.prob.nbColonnes] == 1)
        {
            ++g.couPrec.minesAutour[i];
        }
        if (i + g.prob.nbColonnes + 1 <= g.prob.nbColonnes * g.prob.nbLignes && g.prob.posCase[i + g.prob.nbColonnes + 1] == 1 && (i + 1) % g.prob.nbColonnes != 0)
        {
            ++g.couPrec.minesAutour[i];
        }
    }
}

/*@brief Permet de marquer une case de la grille
* @param[in] la grille
* @param[in] l'indice de la case
*/
void marquer(Grille& g, int indiceCase)
{
    g.couPrec.marquee[indiceCase] = 1;   // On marque la case
}


/*@brief Permet de déminer une case de la grille
* @param[in] la grille
* @param[in] l'indice de la case
*
*/

void deminer(Grille& g, int indiceCase) {

    if (g.couPrec.minesAutour[indiceCase] > 0 || g.prob.posCase[indiceCase] == 1) {} // on ne démine pas si nous avons une mine ou alors des mines à proximité
    else if (g.couPrec.minesAutour[indiceCase] == 0) // nous déminons récursivement toutes les cases autour
    {
        if (indiceCase - g.prob.nbColonnes - 1 >= 0 && g.couPrec.caseJouee[indiceCase - g.prob.nbColonnes - 1] == 0 && indiceCase % g.prob.nbColonnes != 0)
        {
            g.couPrec.caseJouee[indiceCase - g.prob.nbColonnes - 1] = 1;
            deminer(g, indiceCase - g.prob.nbColonnes - 1);
        }
        if (indiceCase + g.prob.nbColonnes >= 0 && g.couPrec.caseJouee[indiceCase - g.prob.nbColonnes] == 0)
        {
            g.couPrec.caseJouee[indiceCase - g.prob.nbColonnes] = 1;
            deminer(g, indiceCase - g.prob.nbColonnes);
        }
        if (indiceCase - g.prob.nbColonnes + 1 >= 0 && g.couPrec.caseJouee[indiceCase - g.prob.nbColonnes + 1] == 0 && (indiceCase + 1) % g.prob.nbColonnes != 0)
        {
            g.couPrec.caseJouee[indiceCase - g.prob.nbColonnes + 1] = 1;
            deminer(g, indiceCase - g.prob.nbColonnes + 1);
        }
        if (indiceCase - 1 >= 0 && g.couPrec.caseJouee[indiceCase - 1] == 0 && (indiceCase) % g.prob.nbColonnes != 0)
        {
            g.couPrec.caseJouee[indiceCase - 1] = 1;
            deminer(g, indiceCase - 1);
        }
        if (indiceCase + 1 < g.prob.nbColonnes * g.prob.nbLignes && g.couPrec.caseJouee[indiceCase + 1] == 0 && (indiceCase + 1) % g.prob.nbColonnes != 0)
        {
            g.couPrec.caseJouee[indiceCase + 1] = 1;
            deminer(g, indiceCase + 1);
        }
        if (indiceCase + g.prob.nbColonnes - 1 < g.prob.nbColonnes * g.prob.nbLignes && g.couPrec.caseJouee[indiceCase + g.prob.nbColonnes - 1] == 0 && (indiceCase) % g.prob.nbColonnes != 0)
        {
            g.couPrec.caseJouee[indiceCase + g.prob.nbColonnes - 1] = 1;
            deminer(g, indiceCase + g.prob.nbColonnes - 1);
        }
        if (indiceCase + g.prob.nbColonnes < g.prob.nbColonnes * g.prob.nbLignes && g.couPrec.caseJouee[indiceCase + g.prob.nbColonnes] == 0)
        {
            g.couPrec.caseJouee[indiceCase + g.prob.nbColonnes] = 1;
            deminer(g, indiceCase + g.prob.nbColonnes);
        }
        if (indiceCase + g.prob.nbColonnes + 1 < g.prob.nbColonnes * g.prob.nbLignes && g.couPrec.caseJouee[indiceCase + g.prob.nbColonnes + 1] == 0 && (indiceCase + 1) % g.prob.nbColonnes != 0)
        {
            g.couPrec.caseJouee[indiceCase + g.prob.nbColonnes + 1] = 1;
            deminer(g, indiceCase + g.prob.nbColonnes + 1);
        }
    }
}


/*@brief Permet de jouer des coups sur une grille
* @param[in] la grille
*/
void jouer_des_coups(Grille& g) {

    cin >> g.couPrec.nbCoups; // demande au joueur combien de coups il va jouer
    for (int i = 0; i < g.couPrec.nbCoups; i++)
    {
        char mot[MOT];
        cin >> mot; // demande d'entrer un coup
        g.couPrec.lesCoups[i].leCoup = mot[0]; // désigne le typr de coup M ou D
        g.couPrec.lesCoups[i].caseDuCoup = atoi(mot + 1); // récupère la case du coup en chaine de caractères et la transforme en entier
    }
    for (int i = 0; i < g.couPrec.nbCoups; i++)
    {
        if (g.couPrec.lesCoups[i].leCoup == 'D')
        {
            g.couPrec.caseJouee[g.couPrec.lesCoups[i].caseDuCoup] = 1;
            deminer(g, g.couPrec.lesCoups[i].caseDuCoup);
        }
        else if (g.couPrec.lesCoups[i].leCoup == 'M')
        {
            g.couPrec.caseJouee[g.couPrec.lesCoups[i].caseDuCoup] = 1;
            marquer(g, g.couPrec.lesCoups[i].caseDuCoup);
        }
    }
    bool cestperdu = 0;
    for (int i = 0; i < g.prob.nbColonnes * g.prob.nbLignes; ++i)
    {
        if (g.prob.posCase[i] == 1 && g.couPrec.caseJouee[i] == 1 && g.couPrec.marquee[i] == 0) // nous vérifions si une mine a été déminée
        {
            cestperdu = 1;
        }
    }

    for (int i = 0; i < g.prob.nbColonnes * g.prob.nbLignes; ++i)
    {
        if (g.prob.posCase[i] == 0 && g.couPrec.caseJouee[i] == 1 && g.couPrec.marquee[i] == 1) // nous vérifions si une mauvaise case a été marquée
        {
            cestperdu = 1;
        }
    }

    // si la partie est perdue nous dévoilons toutes les mines
    if (cestperdu == 1)
    {
        for (int i = 0; i < g.prob.nbColonnes * g.prob.nbLignes; ++i)
        {
            if (g.prob.posCase[i] == 1)
            {
                g.couPrec.caseJouee[i] = 1;
                g.couPrec.marquee[i] = 0;
            }
        }
    }
}