#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*****************************************************
  * Compléter le code à partir d'ici
 *****************************************************/

class Produit{
public:
  Produit(string nom,string unite="")
  :nomProd_(nom),unite_(unite)
  {}

  string getNom() const { return nomProd_;}

  string getUnite() const { return unite_;}
  string toString() const { return nomProd_;}
protected:
  string nomProd_;
  string unite_;
};


class Ingredient{
public:
  Ingredient(const Produit& prod,double quantite)
  : produit_(prod),quantite_(quantite)
  {}
	
  iostream& descriptionAdaptee(iostream&) const;

  const Produit& getProduit() const { return produit_; }
  double getQuantite() const { return quantite_;}

  void descriptionAdaptee() const;
protected:
  const Produit& produit_;
  double quantite_;
};


iostream& Ingredient::descriptionAdaptee(iostream& sortie) const
{
  sortie << quantite_<< ' ' << produit_.getUnite() <<  " de " << produit_.toString();
   return sortie;
}



class Recette{
public:
  Recette(string nom,double fois=1)
  :nomRecette_(nom),nbFois_(fois)
  {}

  void ajouter(const Produit&,double);
  
  iostream& toString(iostream&);

 // Recette adapter (double n);

protected:
  string nomRecette_;
  double nbFois_;
  vector<Ingredient> contenu;
};

void Recette::ajouter(const Produit& p,double quantite)
{
	cout << "test" << endl;
	//double quant(quantite*nbFois_);
	contenu.push_back(Ingredient(p,quantite));
}

/*
iostream& Recette::toString(iostream& sortie)
{	
		for (auto& element:contenu)
		{
			element.descriptionAdaptee(sortie);
		}
}
*/

class ProduitCuisine : public Produit {
public:
  ProduitCuisine(string nom,string unite="Portions")
	:Produit(nom,unite),recette_(nom)
  {}

  void ajouterARecette(const Produit& produit,double quantite);

  //const ProduitCuisine* adapter(double n)

  string toString() const;

protected:
  Recette recette_;
};

void ProduitCuisine::ajouterARecette(const Produit& produit,double quantite)
{
	recette_.ajouter(produit,quantite);
}

string ProduitCuisine::toString() const
{
	 string resultat;
	 resultat+=this->toString();
	// resultat+=recette_.toString();
		
	 return resultat;
}


 /*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
/* 
void afficherQuantiteTotale(const Recette& recette, const Produit& produit)
{
  string nom = produit.getNom();
  cout << "Cette recette contient " << recette.quantiteTotale(nom)
       << " " << produit.getUnite() << " de " << nom << endl;
}
*/
int main()
 {
  // quelques produits de base
  Produit oeufs("oeufs");
  Produit farine("farine", "grammes");
  Produit beurre("beurre", "grammes");
  Produit sucreGlace("sucre glace", "grammes");
  Produit chocolatNoir("chocolat noir", "grammes");
  Produit amandesMoulues("amandes moulues", "grammes");
  Produit extraitAmandes("extrait d'amandes", "gouttes");
  
  Ingredient test(farine,200);
  cout << test.descriptionAdaptee()<< endl;
  
  //Impression des ingrédients pour test
  cout << oeufs.toString() << endl;  
  cout << farine.toString() << endl;
/*
  ProduitCuisine glacage("glaçage au chocolat");
  // recette pour une portion de glaçage:
  glacage.ajouterARecette(chocolatNoir, 200);
  glacage.ajouterARecette(beurre, 25);
  glacage.ajouterARecette(sucreGlace, 100);
  cout << glacage.toString() << endl;

  ProduitCuisine glacageParfume("glaçage au chocolat parfumé");
  // besoin de 1 portions de glaçage au chocolat et de 2 gouttes
  // d'extrait d'amandes pour 1 portion de glaçage parfumé

  glacageParfume.ajouterARecette(extraitAmandes, 2);
  glacageParfume.ajouterARecette(glacage, 1);
  cout << glacageParfume.toString() << endl;

  Recette recette("tourte glacée au chocolat");
  recette.ajouter(oeufs, 5);
  recette.ajouter(farine, 150);
  recette.ajouter(beurre, 100);
  recette.ajouter(amandesMoulues, 50);
  recette.ajouter(glacageParfume, 2);

  cout << "===  Recette finale  =====" << endl;
  cout << recette.toString() << endl;
  afficherQuantiteTotale(recette, beurre);
  cout << endl;

  // double recette
  Recette doubleRecette = recette.adapter(2);
  cout << "===  Recette finale x 2 ===" << endl;
  cout << doubleRecette.toString() << endl;

  afficherQuantiteTotale(doubleRecette, beurre);
  afficherQuantiteTotale(doubleRecette, oeufs);
  afficherQuantiteTotale(doubleRecette, extraitAmandes);
  afficherQuantiteTotale(doubleRecette, glacage);
  cout << endl;

  cout << "===========================\n" << endl;
  cout << "Vérification que le glaçage n'a pas été modifié :\n";
  cout << glacage.toString() << endl; 
  */

  return 0;
}
