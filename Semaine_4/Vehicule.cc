#include <iostream>
#include <cmath> // pour M_PI
#include <vector>
using namespace std;

// ----------------------------------------------------------------------
class Vehicule {
	protected:
		string m_marque;
		unsigned int m_dateAchat;
		double m_prixAchat;
		double m_prixCourant;
	public:
	Vehicule(string marque,unsigned int dateAchat,double prixAchat)
	: m_marque(marque),m_dateAchat(dateAchat),m_prixAchat(prixAchat),m_prixCourant(prixAchat)
	{}
	void affiche(ostream& affichage) const;
	
	void calculePrix();
};
//---------------------------------------------------------------------
void Vehicule::affiche(ostream& affichage) const
{
	affichage << "Marque = " << m_marque <<", " 
				    << "Date achat = " << m_dateAchat << ", "
				    << "Prix achat = " << m_prixAchat << ", " 
				    << "Prix courant = "<< m_prixCourant<< " ." 
				    << endl;
	
}

void Vehicule::calculePrix()
	 {
		 double decote((2019 - m_dateAchat)* .01);
		 m_prixCourant = max(0.0,(1.0-decote) * m_prixAchat);
	 }

// ----------------------------------------------------------------------
class Voiture : public Vehicule{
	protected:
		double m_cylindree;
		unsigned int m_nbPorte;
		double m_puissance;
		unsigned int m_kilometrage;
	
	public:
	Voiture(string marque, unsigned int dateAchat, double prixAchat,
	 double cylindree, unsigned int nbPorte, double puissance, unsigned int kilometrage)
	:Vehicule(marque,dateAchat,prixAchat),
	 m_cylindree(cylindree),m_nbPorte(nbPorte),m_puissance(puissance),m_kilometrage(kilometrage)
	 {}
	
	 //Affichage info
	 void affiche(ostream&)const;
	 
	 void calculePrix();
	 

};
// ----------------------------------------------------------------------
void Voiture::affiche(ostream& affichage) const
{
	affichage << "----Voiture----"<<endl;
	Vehicule::affiche(affichage);
	affichage << "Cylindree =" << m_cylindree<<", "
				 << "Nb porte =" << m_nbPorte << "; "
				 << "Puissance =" << m_puissance << ", "
				 << "Kilometrage=" << m_kilometrage << endl;
}

void Voiture::calculePrix()
{
	double decote ((2015 - m_dateAchat) * .02);
	decote += 0.05 * (m_kilometrage / 10000);
	if (m_marque == "Renaud" or m_marque == "Fiat")
  {
		decote += 0.10;
	}
	if (m_marque == "Ferrari" or m_marque == "Porsche")
	{
		decote += 0.20;
	}
	m_prixCourant = max(0.0,(1-decote) * m_prixAchat);
}
// ----------------------------------------------------------------------
enum Type_avion {HELICE, REACTION};

class Avion : public Vehicule{
	protected:
		Type_avion m_moteur;
		unsigned int m_nbHeureVol;
	public :
	Avion(string marque, unsigned int dateAchat, double prixAchat,
	Type_avion moteur,unsigned int nbHeureVol)
	: Vehicule(marque,dateAchat,prixAchat),
		m_moteur(moteur),m_nbHeureVol(nbHeureVol)
		{}		
		
	//Affichage info	
	void affiche(ostream&)const ;
	
	void calculePrix();
};

void Avion:: calculePrix()
{
	double decote(0.0);
	if (m_moteur == HELICE)
	{
		decote +=  m_nbHeureVol * 0.10 /1000 ;
	} 
	else
	{
		decote += m_nbHeureVol * 0.10 /100 ;
	}
	m_prixCourant = max(0.0, (1.0 - decote) * m_prixAchat);
}

// ----------------------------------------------------------------------
 void Avion::affiche(ostream& affichage) const
 {
	 affichage << "-------Avion � ";
	 if (m_moteur == HELICE) affichage << "h�lices";
	 else                    affichage << "R�action";
	 affichage <<"------"<< endl;
	 Vehicule::affiche(affichage);
	 affichage << "Type =" << m_moteur << "," 
					<< "NbHeureVol " << m_nbHeureVol;
 }


int main() {
	vector<Voiture> garage;
	vector<Avion> hangar;
	garage.push_back(Voiture("Peugeot", 1998, 147325.79, 2.5, 5, 180.0, 1200));
	garage.push_back(Voiture("Porsche", 1985, 250000.00, 6.5, 2, 280.0, 81320));
	garage.push_back(Voiture("Fiat", 2001, 7237.30, 1.6, 3, 65.0, 3000));
	hangar.push_back(Avion("Cessna", 1972, 12306373.90, HELICE, 250));
	hangar.push_back(Avion("Nain Connu", 1992, 4321098.00, REACTION, 1300));
	for(auto& voiture : garage){
		voiture.calculePrix();
		voiture.affiche(cout);
	}
	
	for(auto& avion : hangar){
		avion.calculePrix();
		avion.affiche(cout);
	} 
return 0;
}
