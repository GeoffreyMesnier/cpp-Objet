#include <iostream>
#include <ctime>

// pour les nombres aléatoires

#include <cstring> // strlen
#include <cmath>

using namespace std;


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

class Cercle{
	private:
double Rayon;
double x;
double y;	


	public:
void setCentre (double x_in,double y_in){
	 x = x_in;
	 y = y_in;	
}	
void getCentre (double& x_out, double& y_out) const {
	 x_out = x;
	 y_out = y;
}
	
double getRayon () const { 
	return Rayon;
}
void setRayon (double r) {
	  if (r < 0)  r = 0.0;
	  Rayon = r;
}	
double surface() const{
	return M_PI * (Rayon*Rayon);
}

bool estInterieur (double x1, double y1) const{
	return (((x1-x) * (x1-x) + (y1-y) * (y1-y))
			<= Rayon * Rayon);
}



};

int main()
{
  Cercle c1;
  Cercle c2;
  c1.setCentre(1.0,2.0);
  c1.setRayon(sqrt(5.0)); //Passe par (0,0)
  c2.setCentre(-2.0,1.0);
  c2.setRayon(2.25); //2.25 < sqrt(5) > inclus le point 0,0)
  cout << "Surface 1 :" << c1.surface() << endl;
  cout << "Surface c2 : " <<c2.surface() << endl;
  cout << "position du point (0,0): ";
  if (c1.estInterieur(0.0,0.0)) cout << "dans";
  else                          cout << "hors de";
  cout << "C1 et ";
  if (c2.estInterieur(0.0,0.0)) cout <<"dans ";
  else                          cout << "hors de";
  cout << "C2." << endl;  
  return 0;
}
