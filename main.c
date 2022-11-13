#include "demarrage.h"

int main(void) {

    start();





    return 0;
}

/*




    char** tab = NULL;

    int val1 = 10;
    int val2 = 5;

    tab = (char**) malloc(val1 * sizeof (char*));

    for (int i=0; i<val1; i++){
        tab[i] = (char*) malloc(val2 * sizeof (char));
    }

    for (int i=0; i<val1; i++){
        for (int j=0; j<val2; j++){
            tab[i][j] = '1';
        }

    }

    printf("\n\n");
    for (int i=0; i<val1; i++){
        for (int j=0; j<val2; j++){
            printf("%c ",tab[i][j]);
        }
        printf("\n");
    }

    val1++;
    tab = (char**) realloc(tab, (val1) * sizeof (char*));


    tab[val1-1] = (char*) malloc(val2 * sizeof (char));



    for (int j=0;j<val2; j++){
        tab[10][j] = '0';
    }

    printf("\n\n");
    for (int i=0; i<val1; i++){
        for (int j=0; j<val2; j++){
            printf("%c ",tab[i][j]);
        }
        printf("\n");
    }









##########################################################################################################################################
     FILE *fichier;

    fichier = fopen(chemin_mini_dico,"r");

    if (fichier == NULL){
        printf("Erreur fopen\n");
        return 1;
    }





    char tab[100][3][20];

    char c = fgetc(fichier);

    int i=0, j=0, k=0;

    while (c != EOF){

        if (c == ' '){
            j++;
            c = fgetc(fichier);
        }
        else if(c == '\n'){
            tab[i][j][k] = c;
            i++;
            j = 0;
            k = 0;

        }
        else{
            tab[i][j][k] = c;
            k++;
            c = fgetc(fichier);
        }

    }


    fclose(fichier);







    char c = fgetc(fichier);
    while (c != EOF){
        printf("%c", c);
        c = fgetc(fichier);
    }

     char ligne[MAX_LiGNE];
    while(fgets(ligne, MAX_LiGNE, fichier) != NULL){
        printf("%s",ligne);
    }










 */
