#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  Brique(Forme forme_,Couleur couleur_)
  : forme(forme_),couleur(couleur_)
  {}
  
  //Fonction affichage
  ostream& afficher(ostream& sortie) const;
  
};

	ostream& Brique::afficher(ostream& sortie) const
	{
		if (couleur!= "")
		{ 
			sortie << "(" << forme << ", " << couleur << ")" ;
		}
		else
		{
			sortie << forme;
		}
		return sortie;
}

 //Opérateur surcharge <<
 ostream& operator<<(ostream&,Brique const&);
  
 ostream& operator<<(ostream& sortie,Brique const& b)
  {
		return b.afficher(sortie);
	}

class Construction
{
  friend class Grader;
  public:
  //Construteur tableau (1,1,1)
	Construction(Brique const& b)
	{	
		vector<Brique> tmp1d (1,b);
		vector<vector<Brique> > tmd2d (1, tmp1d);
		contenu.push_back (tmd2d);
  }	
	ostream& afficher(ostream& sortie) const;
		
	//Ajout construction c au dessus de la construction en cours	
	Construction& operator^=(const Construction& c)
	{
		for (const auto& iLevel: c.contenu){
			contenu.push_back(iLevel);
		}
		return *this;
	}
	
	Construction& operator-=(const Construction& c)
	{
		unsigned thisHauteur = contenu.size();
		unsigned otherHauteur= c.contenu.size();
		if (otherHauteur >= thisHauteur)
		{
			for(size_t i = 0; i < contenu.size(); ++i)
			{
				for(const auto& p : contenu[i]){
					contenu[i].push_back(p);
				} 
			}
		}
		return *this;
	}
	
	Construction& operator +=(const Construction& c)
	{
		unsigned thisHauteur =contenu.size();
		unsigned otherHauteur =c.contenu.size();
		if (otherHauteur >= thisHauteur)
		{
			for(size_t i = 0; i < contenu.size_t();++i)
			{
				if (c.contenu[i].size() >= contenu[i].size())
				{
					foi
				}
			}
		}
	}
	
	private:
	vector<vector<vector<Brique> > > contenu ;
};

	Construction operator^(Construction& lhs,const Construction& rhs)	
	{
		lhs^=rhs;
		return lhs;
	}
	
	Construction operator-(Construction& lhs,const Construction& rhs)
	{
		lhs-=rhs;
		return lhs;
	}
	ostream& Construction::afficher(ostream& sortie) const
	{
		for(int i=contenu.size()-1; i>=0; --i){
			sortie << "Couche "<<  i <<" :" << endl;	
			for (const auto& j : contenu[i]) {
				for (const Brique& b : j){
						sortie << b;
				}
					sortie << endl;								
			}			
		}	
	return sortie;
}
	
ostream& operator<<(ostream& sortie,Construction const& C) 
{
	return C.afficher(sortie);
}

/*
const Construction operator*(unsigned int n, Construction const& a)
{
}

const Construction operator/(unsigned int n, Construction const& a)
{
}

const Construction operator%(unsigned int n, Construction const& a)
{
}
*/
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");
  
  cout << toitD << vide << toitG << toitM << mur;
  

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;
  
  return 0;

}
