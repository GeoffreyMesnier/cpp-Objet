#include <iostream>
#include <cmath> // pour M_PI
#include <vector>
using namespace std;


class Figure{
	public:
	virtual void  affiche() const = 0;
	
	virtual Figure* copie() const = 0;
	virtual ~Figure()
	{cout << "Une figure de moins" << endl;}
};

class Cercle :public Figure{
	public:
	Cercle(double rayon=0.0)
	:rayon_(rayon)
	{
		cout << "Cercle constructeur par defaut" << endl;
	}
	
	Cercle(Cercle const& autre)
	: Figure(autre),rayon_(autre.rayon_)
	{
		cout << "Cercle constructeur de copie" <<endl;
	}
	
	~Cercle() 
	{
		cout << "Cercle destructeur" << endl;
		}
	
	Figure* copie () const {return new Cercle(*this);}
	
	void affiche() const
	{
		std::cout << " Un cercle de rayon:" << rayon_ << std::endl;
	}
	void description() const
	{
		std::cout<<"Ceci est un cercle."<< std::endl;
	}

	private:
		double rayon_;
};

class Triangle : public Figure{
	public:
	Triangle(double base=0.0,double hauteur=0.0)
	:base_(base),hauteur_(hauteur)
	{
		cout << "Triangle constructeur par defaut" << endl;
		}
	
	Triangle(Triangle const& autre)
	:Figure(autre),base_(autre.base_),hauteur_(autre.hauteur_)
	{
		cout << "Triangle constructeur de copié" << endl;
	}
	~Triangle() 
	{
		cout << "Triangle destructeur" << endl;
		}
		
	Figure* copie() const { return new Triangle(*this);}
	
	void affiche() const
	{
		std::cout << "Un triangle de base" << base_ << " de hauteur" << hauteur_ << std::endl;
	}
	
	void description() const
	{
		std::cout <<"Ceci est un triangle." << std::endl;
	}
	
	private:
		double base_;
		double hauteur_;
};

class Carre : public Figure{
	public:
	Carre(double longueur=0.0)
	:longueur_(longueur)
	{
		cout << "Carre constructeur par defaut" << endl;
	}
	
	Carre(Carre const& autre)
	:Figure(autre),longueur_(autre.longueur_)
	{
		cout << "Carre constructeur de copie" << endl;
	}
	
	~Carre()
	{
		cout << " Carre destructeur" << endl; 
	}
	
	Figure* copie() const {return new Carre(*this);}
	
	void affiche() const
	{
		std::cout << " un carré de coté" << longueur_ << std::endl;
	}
	
	private:
		double longueur_;
};

class Dessin{
	public:
	
		~Dessin()
		{
		for (unsigned int i(0); i < contenu.size() ;++i)
			{
				delete contenu[i];
			}
		
		}
		void ajouteFigure(Figure const& fig)
		{
			contenu.push_back(fig.copie());
		}
	 void affiche() const
	 {
		 for(unsigned int i(0); i< contenu.size(); ++i)
		 { 
			 contenu[i]->affiche();
			}
		}
	
	private:
	vector<Figure*> contenu;
};


int main() {
	Dessin dessin;
	dessin.ajouteFigure(Triangle(3,4));
	dessin.ajouteFigure(Carre(2));
	dessin.ajouteFigure(Triangle(6,1));
	dessin.ajouteFigure(Cercle(12));
	
	cout << endl << "Affichage du dessin : " << endl;
	dessin.affiche();
	
	return 0;
}

