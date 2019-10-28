#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


typedef struct HEURE
{
	int heur,minute;
}HEURE;

typedef struct Personne
{
	char CIN[50],nom[100],prenom[100];
}Personne;

typedef struct SCOOTER
{
	char model[100];
	int ni,etat;
	float kilometrage, plh;
	HEURE  HL;
	Personne locataire;
}SCOOTER;

int exist(SCOOTER PARC[],int n, int NI)
{
	int b=-1,i;
	for(i=0;i<n;i++)
	{
		if(PARC[i].ni==NI)
		{
			b=i;
			break;
		}
	}
	return b;
}
void   Ajouter(SCOOTER PARC[],int *n)
{
	int b,NI;
	printf("Les information de scooter a ajouter : \n");
	do{
		printf("Donner le numero d'identification du scooter : ");
		scanf("%d",&NI);
		b=exist(PARC,*n,NI);
		if(b!=-1 || NI<0){
			if(b!=-1)
			{
				printf("Erreur, Le scooter est deja existe!!\n ");
			}else
			{
				printf("Le numero d'identification doit etre positive!! \n");
			}
		}
	}while(b!=-1||NI<0);
	PARC[*n].ni=NI;
	printf("Donner le modele : ");
	scanf("%s", PARC[*n].model);
	do{
		printf("Donner le kilometrage(Km) : ");
		scanf("%f",&PARC[*n].kilometrage);
		if(PARC[*n].kilometrage<0){
			printf("Erreur, le kilometrage doit etre superieur a 0!!\n");
		}
	}while(PARC[*n].kilometrage<0);
	do{
		printf("Donner le prix de location par heur(Dh) : ");
		scanf("%f",&PARC[*n].plh);
		if(PARC[*n].plh<0)
		{
			printf("Erreur, le prix de location doit etre positive!!\n ");
		}
	}while(PARC[*n].plh<0);
	// on suppose que l'orsque on ajouter un nouveau scooter il est automatiquement Disponible.
	PARC[*n].etat=1; 
	PARC[*n].HL.heur = 0;
	PARC[*n].HL.minute = 0;
	PARC[*n].locataire.nom[0] = '\0';
	PARC[*n].locataire.prenom[0] = '\0';
	PARC[*n].locataire.CIN[0] = '\0';
	
	(*n)+=1;
}
void 	Suppremer( SCOOTER PARC[] , int *n)
 {
    int i,NI;
  	int s=0;
 	do
   {
 		printf("Donner le numero d\'identification a supprimer : ");
 	    scanf("%d",&NI);
 		if(NI>0)
 	    {
 		  for(i=0;i<*n;i++)
  	       {
  	 	        if(PARC[i].ni != NI)
  	 	       {
  	 		     PARC[s].ni=PARC[i].ni;
  	 		      s++;
		       }
	        }
	          if(s==*n)
	          printf("Erreur,se numero d\'identification n\'existe pas!!\n");
	          else
	          *n=s;
	          printf("\tLe scootre est supprimer.\n");
	           break;
	 }
	 else printf("Le numero d\'identification doit etre positive!!\n");
	 }while(NI<0);
 }
void      Modifier(SCOOTER PARC[],int n)
{
	int NI,b,c;
	do{
		printf("Donner le numero d'identification du scooter a modifier : ");
		scanf("%d",&NI);
		b=exist(PARC,n,NI);;
		if(b==-1 || NI<0)
		{
			if(b==-1)
			{
				printf("Se numero d\'identification n\'existe pas dans le Parc!!\n");
			}
			else
			{
				printf("Le numero d'identification  doit etre positive!!\n");
			}
		}
	}while(b==-1 || NI<0);
	do{
		printf("\n\t\t   **Mini-MENU**\n");
 		printf("\t**********************************\n");
 		printf("\n\t1--Changer le numero d\'identification\n");
 		printf("\t2--Changer le modele de du scooter\n");
 		printf("\t3--Changer le kilometrage\n");
 		printf("\t4--Changer le prix de location par heur\n");
 		printf("\t5--Changer le locataire\n");
 		printf("\t6--Changer l\'etat du scooter\n");
 		printf("\t7--Changer l\'heur de location\n");
 		printf("\t8--Quitter\n");
 	    printf("\n\t**********************************\n");
 			do 
		{
 		        printf("Choisir le donner que vous voulez modifier au scooter : ");
				scanf("%d",&c);
				if(c>8 || c<1)
					printf("Votre choix doit etre compris entre 1 et 8 . \n");
		}while(c>8 || c<1);
		switch(c)
		{
			case 1 :
			{
				do{
					
					printf("Donner le nouveau numero d'identification : ");
					scanf("%d",&NI);
					b=exist(PARC,n,NI);
		             if(b!=-1||NI<0)
					 {
			           if(b!=-1)
					   {
				        printf("Erreur, Le scooter est deja existe!!\n ");
			           }
					   else
			            {
				         printf("Le numero d'identification doit etre positive!! \n");
			            }
		             }
	              }while(b!=-1||NI<0);
	               PARC[b].ni=NI;
				   printf("Le numero d\'identification est changer.\n");
				   break;
			}
			case 2 :
			{
				printf("Donner le nouveau modele : ");
				scanf("%s", PARC[b].model);
				printf("Le modele est changer.\n");
				break;
			}
			case 3 :
			{
				do
				{
					printf("Donner le nouveau kilometrage : ");
					scanf("%f",&PARC[b].kilometrage);
					if(PARC[b].kilometrage<0)
					{
						printf("Erreur, le kilometrage doit etre positive!!");
					}
				}
				while(PARC[b].kilometrage<0);
				printf("Le kilometrage est changer.\n");
				break;
			}
			case 4  :
			{
				do
				{
					printf("Donner le prix de location par heure : ");
					scanf("%f",&PARC[b].plh);
					if(PARC[b].plh<0)
					{
						printf("Erreur, le prix doit etre positive!!\n");
					}
				}
				while(PARC[b].plh<0);
				printf("Le prix de location est changer.\n");
				break;
			}
			case 5 : 
			{
				printf("Donner le de nouveau nom locataire : ");
				scanf("%s",PARC[b].locataire.nom);
				printf("Donner le nouveau prenom locataire : ");
				scanf("%s",PARC[b].locataire.prenom);
				printf("Donner le nouvelle CIN locataire : ");
				scanf("%s",PARC[b].locataire.CIN); 
				printf("Les informations de locataire a changer.\n");
			}
			case 6 : 
			{
				int k;
				do
				{
					printf("Donner la nouvelle etat de scooter : \n");
					printf("Taper sur 1 pour -->  Etat : Disponible\n");
					printf("Taper sur 0 pour -->  Etat : En location\n");
					scanf("%d",&k);
					if(k!=1 && k!=0)
					{
						printf("Erreur, l\'etat doit etre soit 1 soit 0\n");
					}
				}while(k!=1 && k!=0);
				if(k==1)
				{
					PARC[b].etat=1;
					printf("L\'etat de scooter devient : Disponible");
					break;
				}
				else if(k=0)
				{
					PARC[b].etat=0;
					printf("L\'etat de scooter devient : En location");
					break;
					
				}
			}
			case 7 :
			{
				int d,H,M;
				do{
			        printf("Donner le temps de location sous la forme - heur:minute - (*l\'heur est compris entre 6:00 et 23:00*) : ");
			        scanf("%d:%d",&H,&M);
			         if(6>H||H>23||0>M||M>59)
			         {
				        if(H<0||M<0)
				         {
				 	        printf("Erreur!!, l'heure  doit etre positive.\n");
				         } 
				        else if(6>H||H>23)
				         {
					        printf("Desole, le temp de location doit etre compris entre 6:00 et 23:00.\n");
				         }
				         d=0;
			        }else
				   d=1;
		         }while(d==0);
		          PARC[b].HL.heur = H;
		          PARC[b].HL.minute = M;
			}	
			case 8 :
			{
				printf("\tLe(s) modification(s) sont terminer.\n");
				break;
			}
			
		}
	}while(c!=8);
}
void           Trie(SCOOTER PARC[],int n) //changer le triage
{
	SCOOTER temp;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(PARC[i].ni>PARC[j].ni)
			{
				temp=PARC[i];
				PARC[i]=PARC[j];
				PARC[j]=temp;
			}
		}
	}
}

void           Afficher(SCOOTER PARC[],  int n)
{
	Trie(PARC,n);
	int i;
	printf("Les informations de tout les scooters du Parc tries par numero d\'identification: \n ");
	for(i=0;i<n;i++)
	{
		printf("Le scooter numero %d :\n",i+1);
		printf("Le numero d\'identification : %d\n",PARC[i].ni);
		printf("Le modele : %s\n",PARC[i].model);
		printf("Le kilometrage : %fKm\n",PARC[i].kilometrage);
		printf("Le prix de location par heure : %fDh\n",PARC[i].plh);
		printf("L'heure de location  %d:%d\n",PARC[i].HL.heur,PARC[i].HL.minute);
		if(PARC[i].etat==1)
		{
			printf("L'etat du scooter : Disponible\n");
			printf("Le locataire : Aucun\n");
		}else
		{
			printf("L'etat du scooter : En location\n");
			printf("Le CIN : %s\n",PARC[i].locataire.CIN);
			printf("Le nom et le prnom de locataire : %s %s\n",PARC[i].locataire.nom,PARC[i].locataire.prenom);
		}
		
	}
}
void         Louer(SCOOTER PARC[], int n)
{
	int H,M,b,NI,d=1;
	do{
		printf("Donner le numero d'identification a louer : ");
		scanf("%d",&NI);
		b=exist(PARC,n,NI);
		if (b==-1 ||  NI<0)
		{
			if(b==-1)
			{
				printf("Erreur, Le scooter n\'existe pas!!\n ");
			}
			else
			{
				printf("Le numero d'identification  doit étre positive!!");
			}
		}
	}while(b==-1 ||  NI<0);
	if(PARC[b].etat==1)
	{
		do{
			printf("Donner l'heure de location : ");
			scanf("%d",&H);
			printf("Donner la minute de location : ");
			scanf("%d",&M);
			if(6>H||H>23||0>M||M>59)
			{
				if(H<0||M<0)
				{
					printf("Erreur!!, l'heure  doit etre positive.\n");
				}
				else if(6>H||H>23)
				{
					printf("Desole, le temps de location est compris entre 6:00 et 23:00");
					
				}
				d=0;
			}else
				d=1;
		}
		while(d==0);
		PARC[b].HL.heur = H;
		PARC[b].HL.minute = M;
		printf("Donner CIN du locataire : ");
		scanf("%s",PARC[b].locataire.CIN);
		printf("Donner le nom du locataire : ");
		scanf("%s",PARC[b].locataire.nom);
		printf("Donner le prenom du locataire : ");
		scanf("%s",PARC[b].locataire.prenom);
		PARC[b].etat=0; //Le scooter est en location
	}
	else
	{
		printf("Le scooter est deja louer.\n");
	}
}
void          Retour(SCOOTER PARC[],int n) 
{
	int b,NI,o=1,H,M;
	float kilometre;
	float prix_locatinon;
	int NBH; //nombre d'heur
	do{
		printf("Donner le numero d'identification : ");
		scanf("%d",&NI);
		b=exist(PARC,n,NI);
		if(b==-1||NI<0)
		{
			if(b==-1)
			{
				printf("Le scooter n\'existe pas.\n ");
			}
			else
			{
				printf("Le numero d'identification  doit etre positive. \n");
			}
		}
	}while(b==-1||NI<0);
	if(PARC[b].etat==0)
	{
		lingneHeure:{}
		do{
			printf("Donner l'heure de retour  : ");
			scanf("%d",&H);
			printf("Donner la minute de retour : ");
			scanf("%d",&M);
			if(6>H||H>23||0>M||M>59)
			{
				if(H<0||M<0)
				{
					printf("Erreur!!, l'heure  doit etre positive.\n");
				}
				else if(6>H||H>23)
				{
					printf("Desole, le temp de location est compris entre 6:00 et 23:00.\n");
					
				}
				o=0;
			}else
				o=1;
		}while(o==0);
		do
		{
			printf("Donner le nombre des kilometres effectue : ");
			scanf("%f",&kilometre);
			if(kilometre<0)
			{
				printf("Erreur, le kilometrage doit etre positif.\n");
			}
		}while(kilometre<0);
		PARC[b].kilometrage=PARC[b].kilometrage+kilometre;
		NBH=H-PARC[b].HL.heur;
			if(NBH<0)
			{
				printf("Erreur!!, L'heure de retour doit etre apres l'heure de location,\n");
				goto lingneHeure;
			}
			else
			{
				if(M<PARC[b].HL.heur)
				{
					NBH=NBH-1;
				}
			}
		prix_locatinon = (PARC[b].plh*NBH);
		printf("Le prix de location est : %f dh\n",prix_locatinon);
		PARC[b].HL.heur = 0;
		PARC[b].HL.minute = 0;
		PARC[b].locataire.CIN[0] = '\0';
		PARC[b].locataire.prenom[0] = '\0';
		PARC[b].locataire.nom[0] = '\0';
		PARC[b].etat=1;
	}
	else
	{
		printf("Se scooter n'est pas en location\n");
	}
}
void            Rchercher(SCOOTER PARC[] , int n)
{
	int b,NI;
	do{
		printf("Donner le numero d'identification : ");
		scanf("%d",&NI);
		b=exist(PARC,n,NI);
		if(b==-1 ||  NI<0)
		{
			if(b==-1)
			{
				printf("Le numero d\'identification n\existe pas.\n");
			}
			else
			{
				printf("Le numero d'identification  doit etre positive. \n");
			}
		}
	}while(b==-1|| NI<0);
	printf("Le numero d'identification : %d\n",PARC[b].ni);
	printf("Le modele : %s\n",PARC[b].model);
	printf("Le kilometrage : %f\n",PARC[b].kilometrage);
	printf("Le prix de location par heure : %f\n",PARC[b].plh);
	if(PARC[b].etat==1)
	{
		printf("L'etat de scooter : Disponible\n");
		printf("Locataire : Aucun locataire\n");
	}
	else
	{
		printf("L'etat de scooter : En location\n");
		printf("Le CIN : %s\n",PARC[b].locataire.CIN);
		printf("Le nom : %s\n",PARC[b].locataire.nom);
		printf("Le prenom : %s\n",PARC[b].locataire.prenom);
	}
	printf("L'heure : %d:%d\n",PARC[b].HL.heur,PARC[b].HL.minute);
}
void             Etat(SCOOTER PARC[] , int n)
{
	int nsl=0;//nombre de scooter en location.
	int i;
	float moyen=0;
	printf("\tL'etat du parc : \n");
	printf("Le nombre total des scooters : %d scooter(s)\n",n);
	for(i=0;i<n;i++)
	{
		if(PARC[i].etat==0)
			nsl=nsl+1;
	}
	printf("Le nombre des scooters en  location : %d\n",nsl);
	printf("Les numeros d'indentifications des scooter en location :");
		for(i=0;i<n;i++)
		{
			int r=0;
			if(PARC[i].etat==0)
			{
				printf("%d",PARC[i].ni);
				if(i !=  n-1) //a voire
				printf("\t");
				r=r+1;
			}
		}
		printf("\n");
	nsl=0;
	for( i=0;i<n;i++)
	{
		if(PARC[i].etat==1)
			nsl=nsl+1;
	}
	printf("Le nombre des scooters disponnibles : %d\n",nsl);
	printf("Les numeros d'indentifications des scooter disponnibles dans le Parc : ");
		for( i=0;i<n;i++)
		{
			int r=0;
			if(PARC[i].etat==1)
			{
				printf("\n%d",PARC[i].ni);
				if(i != n-1)
				printf("\t");
				    r=r+1;
			}
		}
		printf("\n");
	for(i=0;i<n;i++)
	{
		moyen+=PARC[i].kilometrage;
	}
	moyen/=n;
	printf("Le kilometrage moyen de l'ensemble des scooters : %f\n",moyen);
	float min = PARC[0].kilometrage;
	for(i=0;i<n;i++)
	{
		if(PARC[i].kilometrage<=min)
		{
			min=PARC[i].kilometrage;
		}
	}
		printf("Le(s) scooter(s) ayant le minimum kilometrage : \n");
		int v=0;
		for(i=0;i<n;i++){
			if(PARC[i].kilometrage==min)
			{
				printf("Le scooter numero %d :\n",v+1);
				printf("Le numero d'identification : %d\n",PARC[i].ni);
				printf("Le modele : %s\n",PARC[i].model);
				printf("Le kilometrage : %f\n",PARC[i].kilometrage);
				printf("Le prix de location par heure : %f\n",PARC[i].plh);
				if(PARC[i].etat==1)
				{
					printf("L'etat : Disponible\n");
				}
				else
				{
					printf("L'etat de scooter : En location\n");
				}
				v+=1;
			
			}
		}
	float max = PARC[0].kilometrage;
	for(i=0;i<n;i++)
	{
		if(PARC[i].kilometrage>=max)
		{
			max=PARC[i].kilometrage;
		}
	}
		v=0;
		printf("Le(s) scooter(s) ayant le maximum kilometrage : \n");
		for(i=0;i<n;i++)
		{
			if(PARC[i].kilometrage==max)
			{
				printf("Le scooter numero %d :\n",v+1);
				printf("Le numero d'identification : %d\n",PARC[i].ni);
				printf("Le modele : %s\n",PARC[i].model);
				printf("Le kilometrage : %fKm\n",PARC[i].kilometrage);
				printf("Le prix de location par heure : %fDh\n",PARC[i].plh);
				if(PARC[i].etat==1)
				{
					printf("L'etat du scooter : Disponible\n");
				}
				else
				{
					printf("L'etat de scooter : En location\n");
				}
				v=v+1;
			}
		}
}
void      Enregistrer(SCOOTER PARC[],int n)
{
	int i;
	FILE *pf;
		pf = fopen("PARC.txt","w");
		  for( i=0;i<n;i++)
		   {
			fprintf(pf,"%d %s %f %f %d %d %d %s %s %s\n",PARC[i].ni,PARC[i].model,PARC[i].kilometrage,PARC[i].plh,PARC[i].etat,PARC[i].HL.heur,PARC[i].HL.minute,PARC[i].locataire.prenom,PARC[i].locataire.nom,PARC[i].locataire.CIN);
			//Pour organiser les donner dans le fichier on peut utilisï¿½ se ligne : 
			//fprintf(pf,"le numero d\'identificatio: %d\n le modele: %s\n Le kilometrage: %fKm\n Le prix de location par heur : %fDh\n L\'etat : %d\n L\'heur de location  %d:%d\n Le nom et le prenom de locataire: %s %s\n Le CIN de locataire: %s\n",PARC[i].ni,PARC[i].model,PARC[i].kilometrage,PARC[i].plh,PARC[i].etat,PARC[i].Hr.heur,PARC[i].Hr.minute,PARC[i].locataire.prenom,PARC[i].locataire.nom,PARC[i].locataire.CIN);
		
		   }
		   fclose(pf);
		   printf("Les donnees sont bien enregistres\n");		
}
main(){
	SCOOTER PARC[100];
	int choix, n=0;
	/*FILE *pf;
	pf = fopen("parc","r");
	if(pf!=NULL)
	{
		while(feof(pf)==0)
		{
			fscanf(pf,"%d %s %f %f %d %d %d %s %s %s\n",PARC[i].ni,PARC[i].modele,PARC[i].kilometrage,pa[i].plh,PARC[i].etat,PARC[i].hl.heur,PARC[i].hl.minute,PARC[i].locataire.prenom,PARC[i].locataire.nom,PARC[i].locataire.CIN);
			if(PARC[i].ni!=0)
			{
				n++;
			}
		}
	}*/
	do{
		printf("\n****************MENU-LOUSCOUT****************\n");
     	printf("\n1.Ajouter un nouveau scooter au parc  \n");
     	printf("2.Supprimer un scooter du parc \n");
		printf("3.Modifier les donnees d\'un scooter  \n");
		printf("4.Afficher les scootes du parc  \n");
		printf("5.Louer un scooter  \n");
		printf("6.Retour d\'un scooter  \n");
		printf("7.Rechercher un scooter \n");
		printf("8.Etat du parc des scooters   \n");
		printf("9.Enregistrer   \n");
		printf("10.fin de programme   \n");
		printf("\n*******************************************\n");
			do 
		{
				printf("Donner votre choix : ");
				scanf("%d",&choix);
				if(choix>10 ||choix<1)
					printf("Votre choix doit etre compris entre 1 et 10 .\n");
		}while(choix>10 ||choix<1);

		switch(choix) 
		{                
			case 1 : 
			{
				Ajouter(PARC,&n);
				printf("%d",n);
			}break;
			case 2 : 
			{
					if(n==0)
				{
					printf("le Parc est vide.");
				}
				else
				{
					Suppremer( PARC,&n);
				    break;
				}		
			}break;
			case 3 : 
			{
					if(n==0)
				{
					printf("le Parc est vide.");
				}
				else
				{
					Modifier(PARC,n);
				    break;
				}	
			}break;
			case 4 : 
			{
					if(n==0)
				{
					printf("le Parc et vide.");
				}
				else
				{
						Afficher(PARC,n);
						break;
				}
			}break;
			case 5 : 
			{
				
					if(n==0)
				{
					printf("le Parc est vide.");
				}
				else
				{
				    Louer(PARC,n);
				    break;
				}
				
			}break;
			case 6 : 
			{
				if(n==0)
				{
					printf("le Parc est vide.");
				}
				else
				{
					Retour(PARC,n);
				    break;
				}	
			}break;
			case 7 : 
			{	
				if(n==0)
				{
					printf("le Parc et vide.");
				}
				else
				{
						Rchercher(PARC,n);
						break;
				}
			}break;
			case 8 : 
			{
				if(n==0)
				{
					printf("le Parc et vide.");
				}
				else
				{
						Etat(PARC,n);
						break;
				}
			}break;
			case 9 : 
			{	        
			   Enregistrer(PARC,n);
				
			}break;
			case 10 : 
			{
			  printf("\n A la prochaine.");	
			}break;
	   }
}while(choix!=10);
getch();
} //fin de programme
