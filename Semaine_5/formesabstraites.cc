#include <iostream>
#include <cmath> // pour M_PI
#include <vector>
using namespace std;


class Forme{
	public:
	virtual void description() const
	{
		std::cout<<"Ceci est une forme!"<<std::endl;
	}
	virtual double aire() const = 0;
};

class Cercle :public Forme{
	public:
	Cercle(double rayon=0.0)
	:rayon_(rayon)
	{}
	
	void description() const
	{
		std::cout<<"Ceci est un cercle."<< std::endl;
	}
	
	double aire() const 
	{return M_PI * rayon_ * rayon_ ;}
		
	private:
		double rayon_;
};

class Triangle : public Forme{
	public:
	Triangle(double base,double hauteur)
	:base_(base),hauteur_(hauteur)
	{}
	
	void description() const
	{
		std::cout <<"Ceci est un triangle." << std::endl;
	}
	
	double aire() const { return base_*hauteur_*0.5;}
	private:
		double base_;
		double hauteur_;
};


void affichageDesc(const Forme& f)
{
	f.description();
	cout << "Aire :" << f.aire()<< endl;}

int main() {
	Cercle c(5);
	Triangle t(10, 2);
	
	affichageDesc(c);
	affichageDesc(t);
	
	return 0;
}

