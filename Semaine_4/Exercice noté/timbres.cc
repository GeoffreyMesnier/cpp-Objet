#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
protected:	
	string nom;
	unsigned int annee;
	string pays;
	double valeur_faciale;

public:	
	Timbre(string Nom,unsigned int Annee,string Pays="Suisse",double Valeur_faciale=1.0)
	:nom(Nom),annee(Annee),pays(Pays),valeur_faciale(Valeur_faciale)
	{}
	//Calcule prix de vente
	double vente() const;
	//Calcule age
	unsigned int age() const;
	//affichage timbre
	ostream& afficher(ostream&) const;
	//
};

double Timbre::vente() const
{
	
	if (age() < 5)
	{
		return valeur_faciale;
	}
	else
	{
		return valeur_faciale*2.5*age(); 
	}
}

unsigned int Timbre::age() const
{ 
	return(ANNEE_COURANTE-annee);
}

ostream& Timbre::afficher(ostream& sortie) const
{
	sortie << " de nom "<< nom
				 << " datant de " << annee
				 << " (provenance " << pays 
				 << ") ayant pour valeur faciale " << valeur_faciale <<" francs";
	return sortie;			 
}				 	
			
ostream& operator<<(ostream& sortie,Timbre const& T)
{
	sortie << "Timbre ";
	return T.afficher(sortie);
}

		

class Rare : public Timbre
{
private:
	const double PRIX_BASE_TRES_RARE = 600;
	const double PRIX_BASE_RARE = 400;
	const double PRIX_BASE_PEU_RARE = 50;
protected:
	unsigned int nb_exemp;

public:
		Rare(string Nom,unsigned int Annee,string Pays="Suisse",double Valeur_faciale=1.0,unsigned int Nb_exemp=100)
		: Timbre(Nom,Annee,Pays,Valeur_faciale),
		  nb_exemp(Nb_exemp)
		 {
			}
		 
		 unsigned int nb_exemplaires() const
		 {
			 return nb_exemp;
		 }
		 
		 double vente() const;
		//affichage Rare
		ostream& affiche(ostream&) const; 
	
};

ostream& Rare::affiche(ostream& sortie) const
{
	sortie << "Timbre rare ("<< nb_exemp << " ex.)";
	Timbre::afficher(sortie);			 
				 
	return sortie;			
	
}

ostream& operator<<(ostream& sortie,Rare const& R)
{
	return R.affiche(sortie);
}

double Rare::vente() const
{
	if ( nb_exemplaires() < 100)
	{
		return PRIX_BASE_TRES_RARE * (float(age())/10);
	}
	else
	{
		if (nb_exemplaires() < 1000)
		{
			return PRIX_BASE_RARE * (age()/10);
		}
		else
		{
			return PRIX_BASE_PEU_RARE * (age() /10);
		}
	}
}

class Commemoratif : public Timbre
{
private:

protected:

public:
	Commemoratif(string Nom,unsigned int Annee,string Pays,double Valeur_faciale)
		: Timbre(Nom,Annee,Pays,Valeur_faciale)
		{}
	ostream& affiche(ostream&) const; 
	
	double vente()const;
};

ostream& Commemoratif::affiche(ostream& sortie) const
{
	sortie << "Timbre commémoratif";
	Timbre::afficher(sortie);
	return sortie;
}

ostream& operator<<(ostream& sortie,Commemoratif const& R)
{
	return R.affiche(sortie);
}


double Commemoratif::vente() const
{
	return Timbre::vente()*2;
}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl; 
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
