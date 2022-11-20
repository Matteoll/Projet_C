#include "base_aleatoire.h"



int getNbElementAdverbe(p_letter_adverbe temp){
    int count = 0;
    int i = 0;
    while(i<MAX_ALPHABET){
        if (temp->suite[i] != NULL){
            count++;
        }
        i++;
    }
    return count;
}

//Renvoie une base aléatoire d'un adverbe
char* adverbeBase(t_adverbe_tree *mytree_adverbe, long k_max){
    int element, random;

    char* base = getEmptyTab1(k_max);
    int k = 0;

    random = rand() % (MAX_ALPHABET - 4);

    p_letter_adverbe temp = mytree_adverbe->root_letter[random];

    base[k] = temp->value;
    k++;

    int compteur_verification, count;

    while (1){

        compteur_verification = 0;
        count = 0;

        if (temp->fleche != NULL){
            random = rand() % 4 + 1;
            if (random == 2){
                break;
            }
        }

        element = getNbElementAdverbe(temp);

        if (element == 0){
            break;
        }

        random = rand() % element + 1;

        while (1){
            if (temp->suite[count] != NULL){
                compteur_verification++;
                if (compteur_verification == random){
                    break;
                }
            }
            count++;
        }

        temp = temp->suite[count];
        base[k] = temp->value;
        k++;
    }

    base[k] = '.';

    return base;
}


int getNbElementNA(p_letter_NA temp){
    int count = 0;
    int i = 0;
    while(i<MAX_ALPHABET){
        if (temp->suite[i] != NULL){
            count++;
        }
        i++;
    }
    return count;
}

//Renvoie une base aléatoire d'un nom ou d'un adjectif
char* NABase(t_NA_tree *mytree_NA, long k_max){
    int element, random;

    char* base = getEmptyTab1(k_max);
    int k = 0;

    random = rand() % (MAX_ALPHABET - 4);

    p_letter_NA temp = mytree_NA->root_letter[random];

    base[k] = temp->value;
    k++;

    int compteur_verification, count;

    while (1){

        compteur_verification = 0;
        count = 0;

        if (temp->fleche != NULL){
            random = rand() % 5 + 1;
            if (random == 2){
                break;
            }
        }

        element = getNbElementNA(temp);

        if (element == 0){
            break;
        }

        random = rand() % element + 1;

        while (1){
            if (temp->suite[count] != NULL){
                compteur_verification++;
                if (compteur_verification == random){
                    break;
                }
            }
            count++;
        }

        temp = temp->suite[count];
        base[k] = temp->value;
        k++;
    }

    base[k] = '.';

    return base;
}




int getNbElementVerbe(p_letter_verb temp){
    int count = 0;
    int i = 0;
    while(i<MAX_ALPHABET){
        if (temp->suite[i] != NULL){
            count++;
        }
        i++;
    }
    return count;
}

//Renvoie une base aléatoire d'un verbe
char* verbeBase(t_verb_tree *mytree_verbe, long k_max){
    int element, random;

    char* base = getEmptyTab1(k_max);
    int k = 0;

    random = rand() % (MAX_ALPHABET - 4);

    p_letter_verb temp = mytree_verbe->root_letter[random];

    base[k] = temp->value;
    k++;

    int compteur_verification, count;

    while (1){

        compteur_verification = 0;
        count = 0;

        if (temp->fleche != NULL){
            random = rand() % 2 + 1;
            if (random == 2){
                break;
            }
        }

        element = getNbElementVerbe(temp);

        if (element == 0){
            break;
        }

        random = rand() % element + 1;

        while (1){
            if (temp->suite[count] != NULL){
                compteur_verification++;
                if (compteur_verification == random){
                    break;
                }
            }
            count++;
        }

        temp = temp->suite[count];
        base[k] = temp->value;
        k++;
    }

    base[k] = '.';

    return base;
}






//Fonction pour afficher une base
void dispalyBase(char* base){
    int i = 0;
    while (base[i] != '.'){
        printf("%c", base[i]);
        i++;
    }
}



//Fonction qui gère la partie sur la génération de mot
void genererPhrase(t_verb_tree* mytree_verbe, t_NA_tree* mytree_nom, t_NA_tree* mytree_adjectif, t_adverbe_tree* mytree_adverbe, char *alphabet, long k_max){

    printf("\nChoisissez un modele de ph&rase :\n  1) nom-adjectif-verbe-nom\n  2) nom-'qui'-verbe-verbe-nom-adjectif\n  3) verbe-adverbe-nom\n");

    char Choix;
    do {
        printf("\n{-} Entrer le numero du model choisit :");
        scanf(" %c", &Choix);
        printf("\n");
    } while (Choix != '1' && Choix != '2' && Choix != '3');

    if (Choix == '1'){
        char* base_nom1 = NABase(mytree_nom, k_max);
        char * base_verbe = verbeBase(mytree_verbe, k_max);
        char* base_adjectif = NABase(mytree_adjectif, k_max);
        char* base_nom2 = NABase(mytree_nom, k_max);

        p_letter_NA temp_nom1 = searchLetterNA(mytree_nom, base_nom1, alphabet);
        p_letter_NA temp_nom2 = searchLetterNA(mytree_nom, base_nom2, alphabet);
        p_letter_NA temp_adjectif = searchLetterNA(mytree_adjectif, base_adjectif, alphabet);
        p_letter_verb temp_verb = searchLetter(mytree_verbe, base_verbe, alphabet);

        /*
        int random = rand() % 6 + 1;
        char* article1 = getEmptyTab1(k_max);

        if (random == 1){
            article1[0] = 'l';
            article1[1] = 'e';
            article1[2] = '.';
        }
        else if (random == 2){
            article1[0] = 'l';
            article1[1] = 'a';
            article1[2] = '.';
        }
        else if (random == 3){
            article1[0] = 'u';
            article1[1] = 'n';
            article1[2] = '.';
        }
        else if (random == 4){
            article1[0] = 'u';
            article1[1] = 'n';
            article1[2] = 'e';
            article1[4] = '.';
        }
        else if (random == 5){
            article1[0] = 'd';
            article1[1] = 'e';
            article1[2] = 's';
            article1[4] = '.';
        }
        else if (random == 6){
            article1[0] = 'l';
            article1[1] = 'e';
            article1[2] = 's';
            article1[4] = '.';
        }

        random = rand() % 6 + 1;
        char* article2 = getEmptyTab1(k_max);

        if (random == 1){
            article2[0] = 'l';
            article2[1] = 'e';
            article2[2] = '.';
        }
        else if (random == 2){
            article2[0] = 'l';
            article2[1] = 'a';
            article2[2] = '.';
        }
        else if (random == 3){
            article2[0] = 'u';
            article2[1] = 'n';
            article2[2] = '.';
        }
        else if (random == 4){
            article2[0] = 'u';
            article2[1] = 'n';
            article2[2] = 'e';
            article2[4] = '.';
        }
        else if (random == 5){
            article2[0] = 'd';
            article2[1] = 'e';
            article2[2] = 's';
            article2[4] = '.';
        }
        else if (random == 6){
            article2[0] = 'l';
            article2[1] = 'e';
            article2[2] = 's';
            article2[4] = '.';
        }
        */


        printf("\n----> Forme de base : ");
        dispalyBase(base_nom1); printf(" ");
        dispalyBase(base_adjectif); printf(" ");
        dispalyBase(base_verbe); printf(" ");
        dispalyBase(base_nom2);

        printf("\n\n----> Forme flechie : ");

    }


    else if (Choix == '2'){
        char* base_nom1 = NABase(mytree_nom, k_max);
        char * base_verbe1 = verbeBase(mytree_verbe, k_max);
        char * base_verbe2 = verbeBase(mytree_verbe, k_max);
        char* base_adjectif = NABase(mytree_adjectif, k_max);
        char* base_nom2 = NABase(mytree_nom, k_max);

        p_letter_NA temp_nom1 = searchLetterNA(mytree_nom, base_nom1, alphabet);
        p_letter_NA temp_nom2 = searchLetterNA(mytree_nom, base_nom2, alphabet);
        p_letter_NA temp_adjectif = searchLetterNA(mytree_adjectif, base_adjectif, alphabet);
        p_letter_verb temp_verb1 = searchLetter(mytree_verbe, base_verbe1, alphabet);
        p_letter_verb temp_verb2 = searchLetter(mytree_verbe, base_verbe2, alphabet);

        printf("\n----> Forme de base : ");
        dispalyBase(base_nom1); printf(" qui ");
        dispalyBase(base_verbe1); printf(" ");
        dispalyBase(base_verbe2); printf(" ");
        dispalyBase(base_nom2); printf(" ");
        dispalyBase(base_adjectif);

        printf("\n\n----> Forme flechie : ");

    }


    else if (Choix == '3'){
        char* base_verbe = verbeBase(mytree_verbe, k_max);
        char* base_adverbe = adverbeBase(mytree_adverbe, k_max);
        char* base_nom = NABase(mytree_nom, k_max);

        p_letter_verb temp_verbe = searchLetter(mytree_verbe, base_verbe, alphabet);
        p_letter_adverbe temp_adverbe = searchLetterAdverbe(mytree_adverbe, base_adverbe, alphabet);
        p_letter_NA temp_nom = searchLetterNA(mytree_nom, base_nom, alphabet);

        printf("\n----> Forme de base : ");
        dispalyBase(base_verbe); printf(" ");
        dispalyBase(base_adverbe); printf(" ");
        dispalyBase(base_nom);

        printf("\n\n----> Forme flechie : ");
    }


    printf("\n\n\n-----[menu-principal]-----\n\n");
    printf("Que voulez-vous faire ?\n  1- Generer une phrase\n  2- Rechercher un mot\n  3- Quitter le generateur\n");
}
