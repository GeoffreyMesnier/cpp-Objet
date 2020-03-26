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
};

class Cercle :public Forme{
	public:
	void description() const
	{
		std::cout<<"Ceci est un cercle."<< std::endl;
	}
};

void affichageDesc(Forme& f)
{
	f.description();
}

int main() {
	Forme f;
	Cercle c;
	affichageDesc(f);
	affichageDesc(c);
	return 0;
}
