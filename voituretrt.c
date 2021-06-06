#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"structures.h"
#include"prototypes.h"


liste RechercheVoiture(liste l,char rech[3])
{
	liste tmp;


	tmp=(cellule *)malloc(sizeof cellule);

	tmp=l;

	if(tmp==NULL)		
		return NULL;

	if(strcmp(tmp->voit.identit,rech)==0) 
		return tmp;
	else
		return RechercheVoiture(tmp->suivant,rech);

}

liste SaisieVoiture(liste l)
{


	cellule *voit_final;
	voiture voit;

	EnTete();

	voit_final=(cellule *)malloc(sizeof cellule);

	printf("\n\n\tSaisie d'un type de voiture......\n");

	printf("\n\tMarque        :  ");
	scanf("%s",&voit.marque);

	printf("\tNom           :  ");
	scanf("%s",&voit.nom);

	printf("\n\tCouleur       :  ");
	scanf("%s",&voit.couleur);

	printf("\n\tNb de place :  ");
	scanf("%d",&voit.nbplace);

	printf("\n\tTarif par jour (millime):  ");
	scanf("%d",&voit.prixJour);

	do
	{
		printf("\n\tIdentificateur    :  ");
		scanf("%s",&voit.identit);
	}while(RechercheVoiture(l,voit.identit)!=NULL);


	voit_final->voit=voit;
	voit_final->suivant=NULL;


	return voit_final;

}

liste ModifierVoiture(liste l)
{
	liste modif;
	cellule *v_modif;
	char rech[3];

	printf("\n\tDonnee identifiant du type   :  ");
	scanf("%s",&rech);

	modif=RechercheVoiture(l,rech);

	if(ListeVide(modif)==1)
	{
		printf("\n\n\n\t\tRe-saisie de la voiture....");
		v_modif=SaisieVoiture(l);
		modif->voit=v_modif->voit;
	}
	else
	MessageUrgence("Voiture non trouvee");

	return l;
}

liste SupprimerVoiture(liste l)
{
	liste supp;
	char rech[3];

	if(ListeVide(l)==0)
		MessageUrgence("impossible de supprimer la voiture!");
	else
	{
		printf("Donner identifiant type :  ");
		scanf("%s",&rech);

		supp=RechercheTypeVoiture(l,rech);

		if(supp==NULL)	
			MessageUrgence("Voiture non trouver");
		else
		{
			if(l==supp)
			{
				l=l->suivant;
				free(supp);
			}
			else
				l=SupprimerPosition(l,supp);
			MessageUrgence("Voiture supprimer");
		}
	}

	return l;
}




void AfficheType(voiture voit)
{
	EnTete();

	printf("\tIdentifiant   :  %s",voit.identit);
	printf("\n\n\t\tMarque          :  %s",voit.marque);
	printf("\n\t\tNom             :  %s",voit.nom);
	printf("\n\t\tNb place        :  %d",voit.nbplace);
	printf("\n\t\tCouleur         :  %s",voit.couleur);
	printf("\n\t\tTarif par jour  :  %d",voit.prixJour);
	printf("\n\n");
	system("pause");

}

void AfficheVoiture(matriculVoiture mt)
{
	EnTete();

	printf("\n\n\t\tType            :  %s",mt.type);
	printf("\n\n\t\tMatricul        :  %d TUN %d",mt.matricule/10000,mt.matricule%10000);

	if(mt.stats=='l')
		printf("\n\n\t\tStatut          :  Louee");
	if(mt.stats=='n')
		printf("\n\n\t\tStatut          :  Non-louee");

	printf("\n\n");
	system("pause");

}
