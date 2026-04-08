#include<ncurses.h>
#include "Fonction_Jeu_2_serpent.h"
#include "Fonction_Jeu_1_serpent.h"
#include "Serpent.h"
#include<string.h>
#include<stdlib.h>
#include"Grille.h"



struct grille *lab(struct grille*G_copie){

 struct grille* G=Grille_allouer(G_copie->n,G_copie->m);

	for (int i = 0; i < G->n; i++) {
        	for (int j = 0; j < G->m; j++) {
           		 G->tab[i][j] = "\33[44m  ";
       	 	}
    	}
    	G->tab[0][1]="\33[40m  ";
    	G->tab[1][1]="\33[40m  ";
    	
    	for(int i=1; i< G->n-1; i++ ){
    		if(i<=G->n/4){
    			if (rand() % 2 == 0) {
    			  	G->tab[i][i] = "\33[40m  ";
    			 	G->tab[i+1][i] = "\33[40m  ";
    			}
    			else{
    				G->tab[i][i] = "\33[40m  ";
    				G->tab[i][i+1] = "\33[40m  ";
    		
    			}
    		}
    		if(i>=G->n/4 && i<=G->n/2){
    			if (rand() % 2 == 0) {
    			  	G->tab[i][i] = "\33[40m  ";
    			 	G->tab[i][i-1] = "\33[40m  ";
    			}
    			else{
    				G->tab[i][i] = "\33[40m  ";
    				G->tab[i+1][i] = "\33[40m  ";
    		
    			}
    		}
    		if(i>=G->n/2 && i<=3*(G->n)/4){
    			if (rand() % 2 == 0) {
    			  	G->tab[i][i] = "\33[40m  ";
    			 	G->tab[i][i+1] = "\33[40m  ";
    			}
    			else{
    				G->tab[i][i] = "\33[40m  ";
    				G->tab[i-1][i] = "\33[40m  ";
    		
    			}
    		}
    		if(i>=3*(G->n)/4){
    			if (rand() % 2 == 0) {
    			  	G->tab[i][i] = "\33[40m  ";
    			 	G->tab[i][i+1] = "\33[40m  ";
    			}
    			else{
    				G->tab[i][i] = "\33[40m  ";
    				G->tab[i+1][i] = "\33[40m  ";
    		
    			}
    		}
    	
    	}
    	for(int j=1;j<G->n-2;j++){
    		for(int k=1;k<G->n-2;k++){
    			if(rand()%15==0){
    			      G->tab[j][k]="\33[40m  ";
    			      G->tab[j+1][k]="\33[40m  ";
    			      G->tab[j+1][k+1]="\33[40m  ";
    			}
    			if(rand()%15==1){
    			      G->tab[j][k]="\33[40m  ";
    			      G->tab[j][k+1]="\33[40m  ";
    			      G->tab[j+1][k+1]="\33[40m  ";
    			}
    			if(rand()%15==2){
    			      G->tab[j][k]="\33[40m  ";
    			      G->tab[j][k+1]="\33[40m  ";
    			      G->tab[j+1][k]="\33[40m  ";
    			}
    			if(rand()%15==3){
    			      G->tab[j+1][k]="\33[40m  ";
    			      G->tab[j][k+1]="\33[40m  ";
    			      G->tab[j+1][k+1]="\33[40m  ";
    			}
    		}
    	}
    	for (int i = 0; i < G->n; i++) {
        	for (int j = 0; j < G->m; j++) {
           			G_copie->tab[i][j]= G->tab[i][j];
       	 	}
    	}
    	return G_copie;
}


void manger_fruit2(struct serpent* S){
		struct section* Sec=creer_section(1,generer_couleur());
		ajouter_section_queue(S->corps,Sec);
}

int gameover2(struct grille* G, struct serpent* S){
	if (S->tete.x < 0 || S->tete.y <0 || S->tete.x == G->n  || S->tete.y == G->m || strcmp(G->tab[S->tete.x][S->tete.y],"\33[44m  ")==0){
		if(strcmp(S->corps->premier->couleur,"\33[40m  ")==0){
			G->tab[S->mvt->premier->suivant->coord.x][S->mvt->premier->suivant->coord.y] = "\33[42m:D";
			return -1;
		}
			G->tab[S->mvt->premier->suivant->coord.x][S->mvt->premier->suivant->coord.y] = "\33[42mX)";
			return -1;
		
	}
	else{
		return 0;
	}
}


int jeu2(struct grille* G, struct serpent* S,int vitesse){

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  int car;
  int der_car;
  ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,3));
  ajouter_section_debut(S->corps,creer_section (1,generer_couleur()));
  G=lab(G);
  printf("\33[2J"); 
  printf("\33[H"); 
  Grille_remplir_serpent(G,S);
  Grille_redessiner(G);
  halfdelay(vitesse);

do{
    car = getch();    

   if (car==-1){ 
   	car=der_car;
   }

    else{
      	car=car; /* on sauvegarde la dernière touche utilisee pour avoir le direction*/     
    }
   
   
    switch(car) {  
    
        case KEY_UP:
           S->tete.x--;
           ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,1));
           der_car=KEY_UP;	
           break;
           
        case KEY_DOWN: 
            S->tete.x++;
            ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,3));
            der_car=KEY_DOWN;
           break;
           
        case KEY_LEFT: 
           S->tete.y--;
           ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,4));
           der_car=KEY_LEFT;
           break;

        case KEY_RIGHT:
          S->tete.y++;   
          ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,2));
          der_car=KEY_RIGHT;  
          break;
        default:
          break;
      }
      
   fflush(stdout);  
   printf("\33[2J"); 
   printf("\33[H");
   Grille_remplir_serpent(G,S);
   Grille_redessiner(G);
  } while (gameover2(G,S)!= -1);
  endwin();
  //Grille_desallouer(G);
  printf("\33[2J"); 
  printf("\33[H");
  
  return 1;


}


