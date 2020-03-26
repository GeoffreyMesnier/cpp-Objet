#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
 class Auteur{
public:
	 //Constructeur
	 Auteur(string nom,bool prime=false)
	 : nom(nom),prime(prime)
	 {
     }
     Auteur(Auteur const&)=delete;

    //Retourne nom de l'auteur
	string getNom()
	{
		return nom;
    }
    
    bool getPrix()
    {
		return prime;
	}
	 
private:
	string nom;
	bool prime;
};

class Oeuvre{
public:
	Oeuvre(string titre,Auteur const& auteur,string langue)
	: titre(titre),auteur_(auteur),langue(langue)
	{
	}
	
	Oeuvre(Oeuvre const&)=delete;
	
	string getTitre()
	{
		return titre;
	}
	Auteur const& getAuteur()
	{
		return auteur_;
    }
    string getLAngue()
    {
		return langue;
	}
	void affiche()
	{
		cout <<"l'oeuvre "<< titre << ","<< auteur_.getNom() << ", en " << langue << "n'est plus disponible" << endl;
		
	}
private:
	string titre;
	string langue;
	Auteur Const& auteur_;		
};

class Exemplaire{
public:
	Exemplaire(Oeuvre const& oeuvre)
	: oeuvre_(oeuvre);
	{
		cout <<	"Nouvel exemplaire  de :" << oeuvre_.getTitre() <<", "<<oeuvre_.getAuteur() <<", en " << oeuvre_.getLangue <<endl; 
	}
	Exemplaire(Exemplaire const& nouvel_oeuvre)
	: oeuvre_(nouvel_oeuvre)
	{
		cout << "Copie d'un exemplaire de : " << oeuvre_.getTitre() <<", "<<oeuvre_.getAuteur() <<", en " << oeuvre_.getLangue <<endl;
	}
	~Exemplaire()
	{
		cout << "Un exemplaire de " << oeuvre_.getTitre() << ", " << oeuvre_.getAuteur() << ", en " << oeuvre_.getLAngue() << " a été jeté !"<< endl;
	}
	Oeuvre const& getOeuvre()
	{
		return oeuvre_;
    }
    
    void affiche()
    {
		cout << "Exemplaire de : " << oeuvre_.getTitre() << ", " << oeuvre_.getAuteur() << ", en " << oeuvre_.getLAngue();
	}
    
	

private:
	Oeuvre Const& oeuvre_;
};	

 
 
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
