#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  #define BONUS
  
	Flacon(const string nom_,const double volume_,const double pH_)
	: nom(nom_),volume(volume_),pH(pH_)
	{
	}
	//Lecture nom
	const string get_Nom() const
	 {return nom;} 
	//Lecture volume
	const double get_Volume() const
	{return volume;}
	//Lecture ph 
	const double get_PH() const 
	{return pH;}
	

	//Prototype Gestion de l'affichage
	 ostream& etiquette(ostream&) const;
	 
	//Protype addition
	 void operator+=(Flacon const& f2);
	 

};

	//Prototype surcharge opérateur affichage
	ostream& operator<<(ostream&,Flacon const&);
	
	//Prototype addition
	 const Flacon operator+(Flacon,Flacon const&);

	//Fonction affichage
	ostream& Flacon::etiquette(ostream &sortie)const
	{
		sortie << get_Nom() << " : " << get_Volume() << " ml, pH " << get_PH()  ;
		return sortie;
	}
	
	//Surcharge opérateur definition
	ostream& operator<<(ostream& sortie,Flacon const& f)
	{
		return f.etiquette(sortie);
	}
	
	//Addition ajout
	void Flacon::operator+=(Flacon const& f2)
	{
		double anc_volume=volume;
		nom+=" + "+f2.get_Nom();
		volume+= f2.get_Volume();
		pH=-log10((anc_volume*pow(10.0,-pH)+f2.get_Volume()*pow(10.0,(-f2.get_PH())))/float(anc_volume+f2.get_Volume()));
	}
 
 //Addition
 const Flacon operator+(Flacon f1,Flacon const& f2)
 {
	 f1+=f2;
	 return f1;
 }
 


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
