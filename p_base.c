#include "p_base.h"

int aleatoire_entre_a_et_b(int a_inclus, int b_exclu) {
    if (b_exclu <= a_inclus) {
        return a_inclus;
    }

    return rand() % (b_exclu - a_inclus) + a_inclus;
}
void identite_tableau(int* ceci, int nb_elements) {
    for (int i = 0; i < nb_elements; i++) {
        ceci[i] = i;
    }
}
void echanger_tableau(int* ceci, int position_1, int position_2) {
    int temp = ceci[position_1];
    ceci[position_1] = ceci[position_2];
    ceci[position_2] = temp;
}
void croiser_tableau(int* tab, int nb_elements) {
    int debut = 0;
    int fin = nb_elements - 1;
    while (debut < fin) {
        echanger_tableau(tab, debut, fin);
        debut++;
        fin--;
    }
}
void copier_tableau(int* tab, int* dans, int nb_elements) {
    for (int i = 0; i < nb_elements; i++) {
        *(dans + i) = *(tab + i);
    }
}
void copier_croisement_tableau(int* tab, int* dans, int nb_elements) {
    for (int i = 0; i < nb_elements; i++) {
        dans[i] = tab[nb_elements - 1 - i];
    }
}
int est_inferieur_strict_tableau(int* ceci, int* cela, int nb_elements) {
    int i = 0;
    while (i < nb_elements) {
        if (ceci[i] < cela[i]) {
            return 1;
        } else if (ceci[i] > cela[i]) {
            return 0;
        }
        i++;
    }
    return 0;
}
