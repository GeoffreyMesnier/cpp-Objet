#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
class Patient{
public:
	//Initialise poids et taille
	void init (double m_patient,double h_patient)
{
	if((m_patient > 0 ) and (h_patient > 0))
	{
		masse = m_patient;
		hauteur = h_patient;
	}
	else
	{
		masse=0;
		hauteur=0;
	}
}	
	//Affiche le poids et la taille
	void afficher () const{

	cout << "Patient : " << masse << " kg pour " << hauteur <<" m" << endl;

}
	//Lecture poids
	double poids () const{
	return masse;
}
	//Lecture taille
	double taille () const{
	return hauteur;
}
	//Calcul imc
	double imc () const{
	double imc(0);
	if (hauteur==0)
	{
		return imc;
	}	
	else
	{
		imc=masse/(hauteur*hauteur);
		return imc;
	}	
}

private:
	double masse;
	double hauteur;	
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
