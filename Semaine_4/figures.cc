#include <iostream>
#include <ctime>
#include <cmath>

// pour les nombres aléatoires


using namespace std;


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

class Figure{
	public:
		Figure(double x=0.0,double y=0.0)
		:x(x),y(y)
		{
		}
	
	void getPoint (double& abscisse, double& ordonnee) const
	{
		abscisse = x;
		ordonnee = y;
	}
	
	void setPoint (double abscisse, double ordonnee) 
	{
		x = abscisse;
		y = ordonnee;
	}
	void affiche(ostream& sortie)
	{
		sortie << "Centre= (" << x << ", " << y << ")"; 
	}
	
	
	protected:
		double x; //Abcisse du point de reference
		double y; //Ordonne point de reference
};





class Rectangle : public Figure{
	public:
	Rectangle(double h,double l,double x,double y)
	:hauteur(h),largeur(l),Figure(x,y)
	{
	}
	
	void affiche(ostream&);
	double surface() const
	{
		return(hauteur*largeur);
	}
	double getHauteur() const
	{
		return hauteur;
	}
	double getLargeur() const
	{
		return largeur;
	}
	void setHauteur(double h)
	{
		hauteur=h;
	}
	void setLargeur(double l)
	{
		largeur=l;
	}
	protected:
	double hauteur;
	double largeur;
};

	void Rectangle::affiche(ostream& sortie)
	{
		Figure::affiche(sortie);
		sortie <<"Rectangle Hauteur: "<< hauteur <<"Largeur :" << largeur ; 
	}

class RectangleColore : public Rectangle{
	public:
	RectangleColore(double Haut,double Larg,unsigned int c)
	: Rectangle(Haut,Larg),couleur(c)
	{
	}
	protected:
	unsigned int couleur;
};


class Cercle : public Figure{
	public:
	Cercle(double r,double x=0.0 ,double y=0.0)
	:rayon(r),Figure(x,y)
	{
	}
	void affiche(ostream&);
	double surface() const
	{
		return (M_PI*rayon*rayon);
	}
	double getRayon() const
	{
		return rayon;
	}
	void setRayon(double r)
	{
		if (r < 0.0) r = 0.0;
		rayon=r;
	}

	private:
	double rayon;
};

void Cercle::affiche(ostream& sortie)
{
	Figure::affiche(sortie);
	cout << "Rayon ;" <<rayon ;
}



int main()
{
	RectangleColore r(4.3, 12.5, 4);
	cout << r.getLargeur() << endl;
	r.affiche(cout);
	cout << endl;
	Cercle c(12.2, 2.3, 4.5);
	c.affiche(cout);
	cout << endl;
	Rectangle r2(1.2, 3.4, 12.3, 43.2);
	r2.affiche(cout);
	cout << endl;
	return 0;
}
