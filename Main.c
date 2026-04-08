#include<stdio.h>
#include<string.h>
#include<time.h>
#include<ncurses.h>
#include<stdlib.h>
#include"Grille.h"
#include"Serpent.h"
#include"Fonction_Jeu_1_serpent.h"
#include"Fonction_Jeu_2_serpent.h"
#include"Fonction_Jeu_3_serpent.h"

int main(){
	srand(time(NULL));
	int n;
	int m;
	int vitesse;
	int jeux;


	menu();
	
	scanf("%d", &jeux);
	switch(jeux){
		case 1:
			printf("Choisissez la longueur de la grille:\n");
			scanf(" %d", &n );
			printf("Choisissez la largeur de la grille:\n");
			scanf(" %d", &m );
			printf("Choisissez la vitesse à laquelle vous voulez jouer de 1(hardcore) à 10(très facile):\n");
			scanf(" %d", &vitesse);
			
			struct grille *G=Grille_allouer(n,m);
			Grille_vider(G);
			Grille_tirage_fruit(G);
			struct serpent *Snake=creer_serpent((G->n)/2,(G->m)/2);
			if(jeu(G,Snake,vitesse)==1){
				Grille_redessiner(G);
				printf("\n");
				printf("\33[31mGameover\n");
			}
			break;
		case 2:
		        printf("Choisissez la longueur de la grille:\n");
			scanf(" %d", &n );
			printf("Choisissez la largeur de la grille:\n");
			scanf(" %d", &m );
			printf("Choisissez la vitesse à laquelle vous voulez jouer de 1(hardcore) à 10(très facile):\n");
			scanf(" %d", &vitesse);
			struct grille *G_lab=Grille_allouer(n,m);
			struct serpent *Snake_lab=creer_serpent(1,0);
			lab(G_lab);
			Grille_redessiner(G_lab);
			if(jeu2(G_lab,Snake_lab,vitesse)==1){
				Grille_redessiner(G_lab);
				printf("\n");
				printf("\33[31mGameover\n");
			}
			break;
		
		case 3:
			printf("Choisissez la longueur de la grille:\n");
			scanf(" %d", &n );
			printf("Choisissez la largeur de la grille:\n");
			scanf(" %d", &m );
			printf("Choisissez la vitesse à laquelle vous voulez jouer de 1(hardcore) à 10(très facile):\n");
			scanf(" %d", &vitesse);
			
			struct grille *G_diago=Grille_allouer(n,m);
			Grille_vider(G_diago);
			Grille_tirage_fruit(G_diago);
			struct serpent *Snake_diago=creer_serpent((G_diago->n)/2,(G_diago->m)/2);
			if(jeu3(G_diago,Snake_diago,vitesse)==1){
				Grille_redessiner(G_diago);
				printf("\n");
				printf("\33[31mGameover\n");
			}
			break;
			
		
		case 4:
			printf("Jeu en cours de developpement...\n");
		default:
			break;
	}
}	
	
