// TP1Cplus.cpp : 

#include <iostream>
#include <conio.h>
#include <stdio.h>

	int calculerPgcd(int numerateur, int denominateur) {
		//cette fonction calcule le PGCD de deux valeurs.
		int temp;
		if (numerateur > denominateur){
			temp = numerateur;
			numerateur = denominateur;
			denominateur = temp;
		}
    	while (numerateur != 0){
			temp = denominateur % numerateur;
			denominateur = numerateur;
			numerateur = temp;
		}
		//std::cout << "Le PGCD est " << denominateur << std::endl;
        return denominateur;
	}

	int calculerPgcdBinaire(int numerateur, int denominateur)
	{
		//cette fonction calcule le PGCD binaires de deux valeurs, cetteimplimentation 
		//calculerPgcdBinaire(numerateur, denominateur)=calculerPgcdBinaire(denominateur,numerateur) 
		//le premier parametre doit etre plus grand que le deusiéme dans l'appelle de fonction
		
		if (numerateur == 0)
			return denominateur;	
		else if (((numerateur % 2)!=0) & ((denominateur % 2) != 0)) // les deux impairs
			return calculerPgcdBinaire(((numerateur - denominateur) / 2), denominateur);
		else if (((numerateur % 2) == 0) & ((denominateur % 2) == 0)) // les deux pairs
			return 2*calculerPgcdBinaire(numerateur/2, denominateur/2);
		else if (((numerateur % 2) != 0) & ((denominateur % 2) == 0)) // le premier param est impair et le deusiéme est pair
            return calculerPgcdBinaire(numerateur, denominateur/2);
		else if (((numerateur % 2) == 0) & ((denominateur % 2) != 0)) //le premier param est pair et le deusiéme est impair
			return calculerPgcdBinaire(numerateur/2, denominateur);
	}
	

	int* simplifierFraction(int diviseur, int fraction[]) {
		//vette fonction simplifie une fraction grâce à un diviseur donné.
        for(int i = 0; i < 2; ++i) {
			fraction[i] = fraction[i]/diviseur;
	    }
		return fraction;
	}

	int* saisirFractions(int* nbrFractions) {
		//vette fonction demande aux personnes utilisatrices la quantité de fractions à analyser afind de les saisir
		int numerateur, denominateur, k = 1;
		std::cout << "=============================================\t" << std::endl;
		std::cout << "   Entrez le nombre de fraction a analyser:\t" << std::endl;
		std::cout << "=============================================\t" << std::endl;
		std::cin >> *nbrFractions;
		int *ptrFractions = new int[*nbrFractions * 2];
		for (int i = 0; i < *nbrFractions * 2; i = i + 2) {
			do {
				std::cout << "Entrez le numerateur de la fraction numero " << k << ":\t" << std::endl;
				std::cin >> numerateur;
			} while (numerateur <= 0);
			do {
				std::cout << "Entrez le denominateur de la fraction numero " << k << ":\t" << std::endl;
				std::cin >> denominateur;
			} while (denominateur <= 0);

			*(ptrFractions + i) = numerateur;
			*(ptrFractions + i + 1) = denominateur;
			k = k + 1;
		}
		return ptrFractions;
	}



	void afficherFractionsEtSimplifications(int *ptrFractions, int nbrFractions) {
		//vette fonction  affiche les fractions ainsi que leur simplifications finales.
		int pgcd; int fraction[2]; int *p;
		std::cout << "Affichage des fractions ainsi que de leur simplifications finales :" << std::endl;
		for (int i = 0; i < nbrFractions * 2; i = i + 2) {
			pgcd = calculerPgcd(*(ptrFractions + i), *(ptrFractions + i + 1));
			fraction[0] = *(ptrFractions + i);
			fraction[1] = *(ptrFractions + i + 1);
			p = simplifierFraction(10, fraction);
			std::cout << *(ptrFractions + i) << "/" << *(ptrFractions + i + 1) << "  <<<  "
				<< *(p + 0) << "/" << *(p + 1) << std::endl;
		}
	}

	void main()
	{
		// fonction main qui permet la saisie des fraction et l'affichages des résultats de leurs simplifications
	int *p; int nbrFractions = 0;
    p = saisirFractions(&nbrFractions);
    afficherFractionsEtSimplifications(p, nbrFractions);

	//calculerPgcdBinaire(a, b)=calculerPgcdBinaire(b, a), le premier param est le plus grand dans cette implimentation
	//int pc = calculerPgcdBinaire(30, 20);
	//std::cout << "Le PGCD est " << pc << std::endl;
	//getch();
}