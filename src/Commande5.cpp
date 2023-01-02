#include "commande5.h"


/*@brief Produit un coup par rapport à une grille
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
            ++caseactuelle; // Nous passons à la case suivante lorsque '|' est trouvé
        }
        else if (caractere == '.')
        {
            if (caseactuelle > nbcolonnes)
            {
                // Nous effectuons un calcul pour rendre le résultat cohérent
                tmp = caseactuelle / nbcolonnes;
                caseactuelle = caseactuelle - tmp;
            }
            cout << 'D' << caseactuelle - 1; // affichage du résultat
            return 0; // fin du programme
        }
        
    }
    return 0; // il n'y a aucun coup à jouer
}