#ifndef _Fonction_JEU_2_SERPENT_H
#define _Fonction_JEU_2_SERPENT_H
#include"Grille.h"
#include "Serpent.h"
#include "Fonction_Jeu_1_serpent.h"

struct grille* lab(struct grille*);

int jeu2(struct grille* G, struct serpent* S,int vitesse);

void manger_fruit2(struct serpent* S);

void Grille_vider_lab(struct grille*G);

int gameover2(struct grille* G, struct serpent* S);









#endif
