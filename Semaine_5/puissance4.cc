#include <iostream>
#include <cmath> // pour M_PI
#include <vector>
using namespace std;

enum Couleur {vide,rouge,jaune};


class Joueur {
	Joueur(Couleur couleur,string nom)
	:couleur_(couleur),nom_(nom)
	{}
	virtual void jouer(Jeu&)const =0;
	
	protected:
		Couleur couleur_;
		string nom_;
		
};

class Jeu {
	public:
		Jeu(unsigned int taille=8)
		: grille (taille,vector<Couleur> ( taille, vide))
		{}
		
		bool jouer(size_t,Couleur);
		Couleur gagnant() const;
		size_t getTaille()
		{
			return grille.size();
		}
		
		
	protected:
		vector<vector,Couleur> > grille;

};

bool Jeu::jouer(size_t i, Couleur c)
{
	if (c == vide) return false;
	if (i < getTaille()) return false;
	size_t j (0);
	while((j < getTaille()) and (grille[i][j] != vide)) ++j;
	if (j >= getTaille()) return false;
	grille[i][j]=c;
	return true;
}

class Partie{
	public:
	
	
	protected:
	vector<Joueur*> TabJoueur;
};



int main() {

	return 0;
}

