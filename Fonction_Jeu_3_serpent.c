#include<ncurses.h>
#include "Fonction_Jeu_3_serpent.h"
#include "Serpent.h"
#include<string.h>
#include<stdlib.h>
#include"Grille.h"



int jeu3(struct grille* G, struct serpent* S,int vitesse){

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  int score=0;
  int car;
  int est_fruit=1;
  int der_car;
  ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,4));
  
  printf("\33[2J"); 
  printf("\33[H");
    
  Grille_remplir_serpent(G,S);
  Grille_tirage_fruit(G);
  Grille_remplir(G);
  Grille_redessiner(G);
  halfdelay(vitesse);

do{
    est_fruit=1;
    car = getch();    

   if (car==-1){ 
   	car=der_car;
   }

    else{
      	car=car; /* on sauvegarde la dernière touche utilisee pour avoir le direction*/     
    }
   
   
    switch(car) {  
    
        case KEY_UP:
           if(der_car==KEY_DOWN && S->corps->premier!=NULL){
           	 der_car=KEY_DOWN;
           }
           else{
           	ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,1));
           	S->tete.x--;
           	der_car=KEY_UP;
           }
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	est_fruit=0;
           	manger_fruit(S);
           	score++;
           }
           break;
           
        case KEY_DOWN: 
            if(der_car==KEY_UP && S->corps->premier!=NULL){
           	der_car=KEY_UP;
           }
            else{
            	ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,3));
            	S->tete.x++;
            	der_car=KEY_DOWN;
            }
            if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
            	est_fruit=0;
           	manger_fruit(S);
           	score++;
           }
           break;
           
        case KEY_LEFT: 
           if(der_car==KEY_RIGHT && S->corps->premier!=NULL){   
           	der_car=KEY_RIGHT;
           }
           else{
           	ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,4));
           	S->tete.y--;
           	der_car=KEY_LEFT;
           }
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	est_fruit=0;
           	manger_fruit(S);
           	score++;
           }
           break;

        case KEY_RIGHT:
           if(der_car==KEY_LEFT && S->corps->premier!=NULL){
           	der_car=KEY_LEFT;
           }
           else{
          	ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,2));
           	S->tete.y++;   
          	 der_car=KEY_RIGHT;
           } 
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	est_fruit=0;
           	manger_fruit(S);
           	score++;
           }           
           break;
           

        case 'w':
           	if(der_car=='s' && S->corps->premier!=NULL){
           		der_car='s';
          	 }
           	else{
          		ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,5));
           		S->tete.y++;
           		S->tete.x--;   
          		der_car='w';
           	} 
           	if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           		est_fruit=0;
           		manger_fruit(S);
           		score++;
           	}    	       
           	break;
           
        case 'a':
           	if(der_car=='d' && S->corps->premier!=NULL){
           		der_car='d';
          	 }
           	else{
          		ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,6));
           		S->tete.y++;
           		S->tete.x++;   
          	 	der_car='a';
           	} 
           	if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           		est_fruit=0;
           		manger_fruit(S);
           		score++;
           	}           
           	break;
           
        case 's':
           	if(der_car=='w' && S->corps->premier!=NULL){
           		der_car='w';
          	 }
           	else{
          		ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,7));
           		S->tete.y--;
           		S->tete.x++;   
          		 der_car='s';
           	} 
           	if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           		est_fruit=0;
           		manger_fruit(S);
           		score++;
          	 }           
          	 break;
           
        case 'd':
           	if(der_car=='a' && S->corps->premier!=NULL){
           		der_car='a';
           	}
           	else{
          		ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,8));
           		S->tete.y--;
           		S->tete.x--;   
          		der_car='d';
           	} 
           	if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           		est_fruit=0;
           		manger_fruit(S);
           		score++;
           	}           
           	break;
        default:
          break;
      }
      
   fflush(stdout);  
   printf("\33[2J"); 
   printf("\33[H");
   Grille_vider(G);
   if(est_fruit!=1){
   	do{
   		Grille_tirage_fruit(G);
   	}while(strcmp(G->tab[G->fruit.x][G->fruit.y],"\33[42m:p")==0 || strcmp(G->tab[S->tete.x][S->tete.y],"\33[102m  ")==0 || strcmp(G->tab[S->tete.x][S->tete.y],"\33[103m  ")==0 || strcmp(G->tab[S->tete.x][S->tete.y],"\33[104m  ")==0 || strcmp(G->tab[S->tete.x][S->tete.y],"\33[105m  ")==0|| strcmp(G->tab[S->tete.x][S->tete.y],"\33[106m  ")==0 || strcmp(G->tab[S->tete.x][S->tete.y],"\33[107m  ")==0);
   }
   Grille_remplir(G);
   Grille_remplir_serpent(G,S);
   Grille_redessiner(G);
  } while ( gameover1(G,S)!= -1);
  endwin();
  //Grille_desallouer(G);
  printf("\33[2J"); 
  printf("\33[H");
  printf("\33[39mVotre score est:%d\n", score);
  if(score<=3){
		printf("Même Cristophe Tollu ferait mieux que vous frr mdr XD\n");
	}
	if(3<score && score<=8){
		printf("C'est pas la fête au village !\n");
	}
	if(8<score && score<=15){
		printf("Pas mal pour un mortel\n");
	}
	if(score>15){
		printf("GG tu as un niveau monstrueux\n");
	}
  
  return 1;


}
