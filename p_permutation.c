#include "p_permutation.h"

static int taille_permutation = 0;

t_boolean initialiser_p_permutation(int taille) {
    if (est_p_permutation_initialise()) {
        return FALSE;
    }
    taille_permutation = taille;
    return TRUE;
}

t_boolean est_p_permutation_initialise() {
    return taille_permutation != 0;
}

t_boolean donner_taille_permutation(int* taille) {
    if (!est_p_permutation_initialise()) {
        return FALSE;    
    }
    *taille = taille_permutation;
    return TRUE;
}

t_boolean initialiser_permutation(t_permutation* ceci) {
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    *ceci = malloc(taille_permutation * sizeof(int));
    identite_tableau(*ceci, taille_permutation);
    return TRUE;
}

t_boolean finaliser_permutation(t_permutation* ceci) {
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    free(*ceci);
    *ceci = NULL;
    return TRUE;
}

t_boolean identite_permutation(t_permutation ceci) {
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    identite_tableau(*ceci, taille_permutation);
    return TRUE;
}

t_boolean copier_permutation(t_permutation ceci, t_permutation cela) {
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    copier_tableau(ceci, cela, taille_permutation);
    return TRUE;
}

t_boolean debugger_permutation(t_permutation ceci) {
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    for (int i = 0; i < taille_permutation; i++) {
        printf("%d ,", ceci[i]);
    }
    return TRUE;
}

t_boolean est_indice_valide(int position) {
    if (position >= 0 && position < taille_permutation) {
        return TRUE;
    }
    return FALSE;
}

t_boolean melanger_permutation(t_permutation ceci) {
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    for (int i = taille_permutation - 1; i >= 1; i--) {
        int j = aleatoire_entre_a_et_b(1, i);
        echanger_tableau(ceci, i, j);
    }
    return TRUE;
}

t_boolean reciproque_permutation(t_permutation ceci, t_permutation cela) {
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    for (int i = 0; i < taille_permutation; i++) {
        cela[ceci[i]] = i;
    }
    return TRUE;
}

t_boolean est_permutation_valide(t_permutation ceci){
    if (est_p_permutation_initialise()) {
        return FALSE;
    }
    for(int i = 0; i < taille_permutation; i++){
        if(!est_indice_valide(ceci[i])){
            return FALSE; 
        }
    }
    for( int i = 0; i < taille_permutation - 1; i++){
        for( int j = i + 1; j < taille_permutation; j++){
            if (ceci[i] == ceci[j]){
                return FALSE;
            }
        }
    }
}

t_boolean est_inferieur_strict(t_permutation ceci, t_permutation cela);

t_boolean est_point_fixe_permutation(t_permutation ceci, int position){
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    if (est_indice_valide(position)) {
        if (ceci[position] == position) {
            return TRUE;
        }
    }
    return FALSE;
}

int nb_point_fixe(t_permutation ceci){
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    int nb_point_fixe = 0;
    for (int i = 0; i < taille_permutation; i++) {
        if (est_point_fixe_permutation(ceci, i)) {
            nb_point_fixe++;
        }
    }
    return nb_point_fixe;
}

t_boolean suivante_permutation(t_permutation ceci){
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    int i = taille_permutation - 2;
    while (i >= 0 && ceci[i] > ceci[i + 1]) {
        i--;
    }
    if (i < 0) {
        return FALSE;
    }
    int j = taille_permutation - 1;
    while (ceci[i] > ceci[j]) {
        j--;
    }
    echanger_tableau(ceci, i, j);
    int k = i + 1;
    int l = taille_permutation - 1;
    while (k < l) {
        echanger_tableau(ceci, k, l);
        k++;
        l--;
    }
    return TRUE;
}

t_boolean copier_suivante_permutation(t_permutation ceci, t_permutation cela){
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    copier_permutation(ceci, cela);
    return suivante_permutation(cela);
}

t_boolean code_point_fixe_permutation(t_permutation ceci, int point_fixe, t_permutation cela){
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    if (est_indice_valide(point_fixe)) {
        if (est_point_fixe_permutation(ceci, point_fixe)) {
            for (int i = 0; i < taille_permutation; i++) {
                cela[i] = ceci[i];
            }
            echanger_tableau(cela, point_fixe, taille_permutation - 1);
            return TRUE;
        }
    }
    return FALSE;
}

t_boolean decode_point_fixe_permutation(t_permutation ceci, t_permutation cela, int* point_fixe){
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    if (est_permutation_valide(ceci)) {
        for (int i = 0; i < taille_permutation; i++) {
            cela[i] = ceci[i];
        }
        *point_fixe = cela[taille_permutation - 1];
        echanger_tableau(cela, cela[taille_permutation - 1], taille_permutation - 1);
        return TRUE;
    }
    return FALSE;
}