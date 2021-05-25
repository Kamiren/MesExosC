#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void afficheTableau(int tableau[], int tailleTableau);
int sommeTableau(int tableau[], int tailleTableau);
int valMax(int tableau[], int tailleTableau);
double moyenneTableau(int tableau[], int tailleTableau);
void copieDeTableau(int tableauOriginal[], int *tableauCopie, int tailleTableau);
void maximumTableau(int* tableau, int tailleTableau, int valeurMax);
void ordonnerTableau(int* tableau, int tailleTableau);

int main() {
    int tab[3] = {30, 23, 40};
    int tabDeux[3] = {3, 21, 32};
    int tabTrois[9] = {3, 21, 32, 34, 1, 2, 49, 4, 9};

    printf("La somme du tableau : ");
    printf("%d\n\n" , sommeTableau(tab, 3));
    printf("La moyenne du tableau : ");
    printf("%f\n\n", moyenneTableau(tab, 3));
    printf("Copie du tableau : ");
    copieDeTableau(tab, tabDeux, 3);
    afficheTableau(tabDeux, 3);
    printf("\n\nValeur maximale de 35 du tableau 1 : ");
    maximumTableau(tab, 3, 35);
    printf("\n\nTableau trois ordonne : ");
    ordonnerTableau(tabTrois, 9);
    afficheTableau(tabTrois, 9);

    return 0;
}

//Methode pour afficher un tableau
void afficheTableau(int tableau[], int tailleTableau){
    int i;
    for(i = 0; i < tailleTableau; i++){
        printf("\n%d", tableau[i]);
    }
}


//Fonction de la somme du tableau
int sommeTableau(int tableau[], int tailleTableau){
    int i;
    int somme = 0;
    for(i = 0; i < tailleTableau; i++){
        somme = tableau[i] + somme;
    }
    return  somme;
}


//Fonction renvoyant la plus grande valeur du tableau
int valMax(int tableau[], int tailleTableau){
    int i, valMaximum = tableau[0];
    for(i = 0; i < tailleTableau; i++){
        if(valMaximum < tableau[i]){
            valMaximum = tableau[i];
        }
    }
    return valMaximum;
}

//Fonction de la moyenne du tableau
double moyenneTableau(int tableau[], int tailleTableau){
    return sommeTableau(tableau, tailleTableau) / tailleTableau;
}

//Methode de copie de deux tableaux
void copieDeTableau(int tableauOriginal[], int* tableauCopie, int tailleTableau){
    int i;
    for(i = 0; i < tailleTableau; i++){
        tableauCopie[i] = tableauOriginal[i];
    }
}

//Methode devant mettre les valeur a 0 si celle-ci est superieur a la valeurMax
void maximumTableau(int* tableau, int tailleTableau, int valeurMax){
    int i;
    for(i = 0; i < tailleTableau; i++){
        if(tableau[i] > valeurMax){
            tableau[i] = 0;
        }
    }
    afficheTableau(tableau, tailleTableau);
}

//Methode permettant de trier un tableau
void ordonnerTableau(int* tableau, int tailleTableau){
    int valMin = tableau[0], valeurMax = valMax(tableau, tailleTableau) ,i, j, tabMem[tailleTableau], index;

    //Copie du tableau dans tabMem
    copieDeTableau(tableau, tabMem, tailleTableau);

    //Boucle permettant de remplacer les elements
    for(i = 0; i < tailleTableau; i++){

        //Boucle permettant de déterminer la valeur minimale
        for(j = 0; j < tailleTableau; j++){
            if(valMin > tabMem[j]){
                valMin = tabMem[j];
                index = j;
            }
        }
        tableau[i] = valMin;

        //Remplace le plus petit element du tableau memoire par le plus grand
        tabMem[index] = valeurMax;

        //valMin obtient le plus grand element du tableau
        valMin = valeurMax;
    }
}