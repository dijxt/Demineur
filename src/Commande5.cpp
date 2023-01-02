#include "commande5.h"


/*@brief Produit un coup par rapport � une grille
*/

bool produire_coup() {
    int nblignes = 0;
    int nbcolonnes = 0;
    int caseactuelle = 0;
    char caractere = 'a';
    int tmp;
    
    cin >> nblignes;
    cin >> nbcolonnes;

    // Nous cherchons un '.' pour pour jouer un coup
    while (caractere != '.')
    {
        cin >> caractere;
        if (caractere == '|')
        {
            ++caseactuelle; // Nous passons � la case suivante lorsque '|' est trouv�
        }
        else if (caractere == '.')
        {
            if (caseactuelle > nbcolonnes)
            {
                // Nous effectuons un calcul pour rendre le r�sultat coh�rent
                tmp = caseactuelle / nbcolonnes;
                caseactuelle = caseactuelle - tmp;
            }
            cout << 'D' << caseactuelle - 1; // affichage du r�sultat
            return 0; // fin du programme
        }
        
    }
    return 0; // il n'y a aucun coup � jouer
}