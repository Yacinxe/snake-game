#include"Grille.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>


//Définition des fonctions déclarées dans Grille.h


struct grille *Grille_allouer(int n,int m){
	int i;
	int j;
	struct grille* G=malloc(sizeof(struct grille));
	G->n=n;
	G->m=m;
	if(G==NULL){
		fprintf(stderr,"Impossible d'allouer de l'espace mémoire\n");
		return NULL;
	}
	G->tab=malloc(sizeof(char**)*(G->n));
	for(i=0;i<G->n;i++){
		*(G->tab+i)=malloc(sizeof(char*)*(G->m));
		for(j=0;j<G->m;j++){
			*(*(G->tab+i)+j)=malloc(sizeof(char) * 9);
		}
	}
	return G;
}

void Grille_vider(struct grille*G){
	int i;
	int j;
	for(i=0;i<G->n;i++){
		for(j=0;j<G->m;j++){
			G->tab[i][j]="\33[40m  ";
		}
	}
}

void Grille_tirage_fruit(struct grille*G){
	G->fruit.x=rand()%(G->n);
	G->fruit.y=rand()%(G->m);
}

void Grille_tirage_fruit_lab(struct grille*G){
	G->fruit.x=1;
	G->fruit.y=1;
}

void Grille_remplir(struct grille*G){
	
	if(strcmp(G->tab[G->fruit.x][G->fruit.y],"\33[102m  ")!=0 && strcmp(G->tab[G->fruit.x][G->fruit.y],"\33[103m  ")!=0 && strcmp(G->tab[G->fruit.x][G->fruit.y],"\33[104m  ")!=0 && strcmp(G->tab[G->fruit.x][G->fruit.y],"\33[105m  ")!=0 && strcmp(G->tab[G->fruit.x][G->fruit.y],"\33[106m  ")!=0 && strcmp(G->tab[G->fruit.x][G->fruit.y],"\33[107m  ")!=0){
		G->tab[G->fruit.x][G->fruit.y]="\33[41m  ";
	}
	
}

void Grille_desallouer(struct grille*G){
	int i;
	int j;
	for(i=0;i<G->n;i++){
		for(j=0;j<G->m;j++){
			free(G->tab[i][j]);
		}
		free(G->tab[i]);
	}
	free(G->tab);
	free(G);
}

void Grille_redessiner(struct grille*G){
    int i,j,k;
    
    for(k=0;k<G->m+2; k++)
    	if(k%2 == 0)
 	   	printf("\33[47m  ");
 	else printf("\33[40m  ");
    printf("\33[00m  ");
    printf("\n\r");
        for(i=0;i<G->n; i++){
            if(i%2 == 1)
 	   	printf("\33[47m  ");
 	else printf("\33[40m  ");
            for(j=0;j<G->m;j++){
                printf("%s",G->tab[i][j]);
            }
            if(i%2 == 1)
 	   	printf("\33[47m  ");
 	else printf("\33[40m  ");
            printf("\33[00m  ");
            printf("\n\r");
        }
    for(k=0;k<G->m+2; k++)
            if(k%2 == 0)
 	   	printf("\33[47m  ");
 	else printf("\33[40m  ");
    printf("\33[00m  ");
    printf("\n");
}


	































	
	
