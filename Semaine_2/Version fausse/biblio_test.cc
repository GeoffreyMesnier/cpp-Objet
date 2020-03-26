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
     
     Auteur(Auteur const&) = delete;
    
    //Retourne nom de l'auteur
    
	string getNom () const
	{
		return nom;
    }
    
    bool getPrix() const
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
	
	Oeuvre(Oeuvre const&) = delete;
	
	string getTitre() const
	{
		return titre;
	}
	Auteur const& getAuteur() const
	{
		return auteur_;
    }
    string getLAngue() const
    {
		return langue;
	}
	 void affiche() const
	{
		cout << titre << ", "<< auteur_.getNom() << ", en " << langue;
	}
	~Oeuvre()
	{
		cout << "L'oeuvre " << titre << ", " << auteur_.getNom() << ", en "<< langue <<" n'est plus disponible" <<endl;
	}
private:
	string titre;
	const Auteur& auteur_;	
	string langue;
};

class Exemplaire{
public:
	Exemplaire(Oeuvre& oeuvre)
	: oeuvre_(oeuvre)
	{
		cout << "Nouvelle exemplaire de : ";
		oeuvre_.affiche();
		cout << endl;
	}
/*	
	Exemplaire(Exemplaire const& autre)
	: oeuvre_(autre)
	{
		cout << "Copie d'un exemplaire de : ";
		oeuvre_.affiche(); 
		cout << endl;
	}
*/	
	~Exemplaire()
	{
		cout << "Un exemplaire de "; 
		oeuvre_.affiche(); 
		cout << " a été jeté !"<< endl;
	}
	Oeuvre const& getOeuvre()
	{
		return oeuvre_;
    }
    
    void affiche()
    {
		cout << "Exemplaire de : " ;
		oeuvre_.affiche() ;
		cout << endl;
	}
    
private:
	Oeuvre& oeuvre_;
};	

class Bibliotheque{

public:
	Bibliotheque(string nom)
	:nom(nom)
	{
		cout << "La bibliotheque " << nom << " est ouverte" << endl;
	}

	string getNom()
	{
		return nom;
	}
	
	void stocker (Oeuvre const& oeuvre,int nbexemplaire=1)
	{
		for(int i=0; i<nbexemplaire ;++i)
		{
			Exemplaire * examplairePtr = new Exemplaire(oeuvre);
		}
			
		
	}
	
	void lister_exemplaires(string langue="")
	{
		
	}
	
private:
	string nom;
	vector<Exemplaire*> tab;
	

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
         
  cout << a1.getNom()<<" " << a2.getNom() << " " << a3.getNom() << endl;
        

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );
         
   cout << "Titre: "<< o1.getTitre() << endl; 
   o1.affiche(); 
            
   cout << "Titre: "<< o2.getTitre() << endl; 
   o2.affiche(); 

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);
/*
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
*/
  return 0;
}
