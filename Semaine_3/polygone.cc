#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

typedef size_t Degre;

class Polygone{
	public:
		//Constructeur par defaut
		Polygone(double = 0.0)
		{}
		Polygone(double x)
		: p(1,x)
		{}
		Polygone(double coef =0.0, Degre degre=0);
		: p(deg+1, 0.0)
		{
			p[deg] =coef;
		}
		
		const vector<double> getVector()const 
		{
			return p;
		}
		//Prototype de la méthode facilitant l'affichage
		void affiche_coef(ostream& out,Degre puissance,bool signe = true)
		
		Degre degre() const{
			return { m_tab.size()-1};
		}
		
	private:
		vector<double> p;
};

//Prototype de la methode facilitant l'affichage
ostream& operator<<(ostream&,Polygone const&);

const ostream& operator<<(ostream& sortie,Polygone const z)
{
	sortie << z.getVector():
	return sortie;
} 

int main()
{
	return 0;
}



