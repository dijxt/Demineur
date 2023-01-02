#include <iostream>
// inclusion de toutes les commandes
#include "Commande1.h"
#include "Commande2.h"
#include "Commande3.h"
#include "Commande4.h"
#include "Commande5.h"

using namespace std;

int main() {

    int commande;// contiendra la commande voulue

    cin >> commande;

    if (commande == 1)
    {
        Probleme p;
        def_prob(p);
    }
    else if (commande == 2)
    {
        Grille g;
        init_grille(g);
        jouer_des_coups(g);
        afficher_grille(g);
    }
    else if (commande == 3)
    {
        Grille g;
        init_grille(g);
        jouer_des_coups(g);
        game_won(g);
    }
    else if (commande == 4)
    {
        Grille g;
        init_grille(g);
        jouer_des_coups(g);
        game_lost(g);
    }
    else if (commande == 5)
    {
        produire_coup();
    }

}