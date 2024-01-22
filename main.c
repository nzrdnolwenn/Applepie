
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "methode.c"
#include "propriete.c"
#include "animation.c"
#include "liste.c"


void game() {

    int t = theme();        
    int d = level();        
    char* mot = mot_aleatoire( t, d );

    char lettre_saisi[LONGUEUR_MAX_MOT] = "";
    int choix_incorrecte = 0;

    system("clear");
    pendu(choix_incorrecte);
    while (choix_incorrecte < ESSAI_MAX) {
        mot_cachee(mot, lettre_saisi);
        char choix = choix_utilisateur();
        int result = verifie_choix(mot, choix, lettre_saisi);

        if (result == 1) {
            strncat(lettre_saisi, &choix, 1);
        }
        else if (result == -1) {
            choix_incorrecte++;
            pendu(choix_incorrecte);
        }

        if (strspn(mot, lettre_saisi) == strlen(mot)) {
            system("clear");
            pendu(choix_incorrecte);
            printf("Felicitaion! Vous avez touver le mot: %s\n", mot);
            break;
        }
    }

    if (choix_incorrecte == ESSAI_MAX) {
        system("clear");
        pendu(choix_incorrecte);
        printf("\t--> word to find: %s <---\n", mot);
    }
}




void run(){

    system("clear");
    
        logo();
        int m = menu();

        switch( m ){
            case 1:
                game();
            break;
            case 2:
                //score();
            break;
            case 3:
                infos();
            break;
            case 4:
                quit();
            break;
        }

}




int main() {
    run();
    return 0;
}
