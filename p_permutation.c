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
    printf("[ ");
    for (int i = 0; i < taille_permutation; i++) {
        printf("%d ", ceci[i]);
    }
    printf("]\n");
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
        int j = rand() % (i + 1);
        int temp = ceci[i];
        ceci[i] = ceci[j];
        ceci[j] = temp;
    }
    return TRUE;
}

t_boolean construire_reciproque_permutation(t_permutation ceci, t_permutation cela) {
    if (!est_p_permutation_initialise()) {
        return FALSE;
    }
    for (int i = 0; i < taille_permutation; i++) {
        cela[ceci[i]] = i;
    }
    return TRUE;
}