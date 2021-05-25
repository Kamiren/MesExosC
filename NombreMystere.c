#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    bool game = true;
    bool again = true;
    int nbPropose = 0;
    int nbCoup = 0;
    int choix = 0;
    int nbRand;

    while (again) {
        game = true;
        nbCoup = 0;

        printf("Selectionnez la difficultees : \n 1 : Facile entre 0 et 10 \n 2 : Moyen entre 0 et 100 \n 3 : Difficile entre 0 et 1000 \n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                nbRand = rand() % 11;
                break;
            case 2:
                nbRand = rand() % 101;
                break;
            case 3:
                nbRand = rand() % 1001;
                break;
            default:
                nbRand = rand() % 101;
        }
        do {
            switch (choix) {
                case 1:
                    printf("Mettez un nombre entre 0 et 10 : ");
                    break;
                case 2:
                    printf("Mettez un nombre entre 0 et 100 : ");
                    break;
                case 3:
                    printf("Mettez un nombre entre 0 et 1000 : ");
                    break;
                default:
                    nbRand = rand() % 101;
            }
            scanf("%d", &nbPropose);
            nbCoup = nbCoup + 1;
            if (nbPropose == nbRand) {
                printf("Vous avez devine le bon numero !");
                game = false;
            } else if (nbPropose > nbRand) {
                printf("Le nombre a deviner est plus petit !\n");
            } else if (nbPropose < nbRand) {
                printf("Le nombre a deviner est plus grand !\n");
            } else {
                printf("Le nombre a entre n est pas valide !\n");
            }
        } while (game == true);
        printf("Vous avez trouve le nombre en : %d coups", nbCoup);
        printf("\nVoulez vous recommencer ? 0 = non ; 1 = oui");
        scanf("%d", &choix);
        if(choix != 1){
            again = false;
        }
    }
    return 0;
}
