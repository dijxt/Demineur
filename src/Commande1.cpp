#include "Commande1.h"

/*@brief Permet de définir un problème
* @param[in] le problème
*
*/
void def_prob(Probleme& p) {

    // entrées nécessaires
    cin >> p.nbLignes;
    cin >> p.nbColonnes;
    cin >> p.nbMines;
    // nous vérifions si les valeurs entées permettent de jouer une partie
    assert(p.nbLignes != 0);
    assert(p.nbColonnes != 0);

    p.posCase[p.nbLignes * p.nbColonnes]; // on donne à posCase sa taille

    for (int k = 0; k < p.nbLignes * p.nbColonnes; ++k) // on vide toutes les cases
    {
        p.posCase[k] = 0;
    }

    assert(p.nbMines <= p.nbLignes * p.nbColonnes); // on s'assure que le nbr de mines est inférieur au nbr de cases

    int nbCases = ((p.nbLignes * p.nbColonnes) - 1); // les cases numérotés de 0 au nombre de cases

    srand(time(NULL));


    for (int i = 0; i < p.nbMines; ++i) // attribution au hasard des mines
    {
        int tmp = rand() % nbCases;
        while (p.posCase[tmp] != 0)
        {
            tmp = rand() % nbCases;
        }
        p.posCase[tmp] = 1;

    }

    cout << p.nbLignes << " " << p.nbColonnes << " " << p.nbMines << " "; // affichage des nombres de lignes, colonnes et mines

    for (int i = 0; i < nbCases; ++i) // affichage des positions de mines
    {
        if (p.posCase[i] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}