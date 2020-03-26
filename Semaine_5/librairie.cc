#include <iostream>
#include <cmath> // pour M_PI
#include <vector>
using namespace std;

class Livre{
	public:
	Livre(string titre,string auteur,int pages,bool bestseller)
	: titre(titre),auteur(auteur),pages(pages),bestseller(bestseller)
	{}
	
	virtual ~Livre()  
	{}
	
	virtual void afficher() const;
	
	virtual double calculer_prix() const;
	
	protected:
		string  titre;
		string auteur;
		int pages;
		bool bestseller;
		
};

	void Livre::afficher() const
	{	
		cout << "titre : " << titre << endl;
		cout << "auteur : " << auteur << endl;
		cout << "nombre de pages : " << pages << endl;
		cout << "bestseller : " << bestseller << endl;
		cout << "Prix :" << calculer_prix()<< endl;
	}

	double Livre::calculer_prix() const
	{ 
		double resultat(0);
		if (bestseller) resultat+=50;
		resultat += pages * 0.3;
		return resultat; 
	}

class Roman : public Livre{
	public:
	Roman(string titre,string auteur,int pages,bool bestseller,bool biographie)
	:Livre(titre, auteur, pages, bestseller),
	 biographie(biographie)
	 {}
	 
	 virtual ~Roman() 
	 {}
	 
	 void afficher() const;
	protected:
		bool biographie;
};

void Roman::afficher() const
{
	Livre::afficher();
	cout << "biographie : " << biographie << endl;
	
}


class BeauLivre : public Livre{
	public:
	BeauLivre(string titre,string auteur,int pages,bool bestseller)
	:Livre(titre, auteur, pages, bestseller)
	{}
	
	~BeauLivre() {}
	
	double calculer_prix() const;
	
	
	protected:
	
};

double BeauLivre::calculer_prix() const
{
	return Livre::calculer_prix()+30;
}

class Policier : public Roman{
	public:
	Policier(string titre,string auteur,int pages,bool bestseller,bool biographie)
	: Roman(titre,auteur,pages,bestseller,biographie)
	{}

	double calculer_prix() const;
};

double Policier::calculer_prix() const
{
	double resultat(Livre::calculer_prix() -10);
	if (resultat < 0) resultat=1;
	return resultat;
}

class Librairie{
	public:
	 void ajouter_livre (Livre*) ;
	 
	 void afficher() const;
	
	private:
		vector<Livre*> contenu;
};

void Librairie::ajouter_livre (Livre* livre)
{
	contenu.push_back(livre);
}

void Librairie::afficher() const
{
	for(auto element : contenu)
	{
		element->afficher();
	}
}



int main()
{
  Librairie l;
	l.ajouter_livre(new Policier("Le chien des Baskerville", "A.C.Doyle",221, false, false));
	l.ajouter_livre(new Policier("Le Parrain ", "A.Cuso", 367, true, false));
	l.ajouter_livre(new Roman("Le baron perché", "I. Calvino", 283, false, false));
	l.ajouter_livre(new Roman ("Mémoires de Géronimo", "S.M. Barrett", 173, false, true));
	l.ajouter_livre(new BeauLivre ("Fleuves d'Europe", "C. Osborne", 150, false));
	l.afficher();
//	l.vider_stock();
	return 0;
}


