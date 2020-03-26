#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/


class Rectangle{
	private:
double Longueur;
double Largeur;
    public:
void setLongueur(double l) { Longueur=l;}
void setLargeur(double L) {Largeur=L;}   
double getLongueur() const {return Longueur;}
double getLargeur() const {return Largeur;} 
double surface () const { 
	return Longueur * Largeur;
	}
};

int main()
{
  Rectangle rect;
  rect.setLongueur(1.5);
  rect.setLargeur(12.8);
  cout << "Longueur : " << rect.getLongueur() << endl;
  cout << "Largeur : " << rect.getLargeur() << endl;
  cout << "Surface =" << rect.surface() << endl;
  return 0;
}
