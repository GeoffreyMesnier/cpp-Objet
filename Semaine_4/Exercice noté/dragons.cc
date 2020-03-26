#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int distance(int x, int y)
{
  return abs(x - y);
}

class Creature
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
private:
	
protected:
	string const nom_;
	int niveau_;
	int points_de_vie_;
	int force_;
	int position_;
	
public:
	Creature(string const nom,int niveau,int points_de_vie,int force,int position=0)
	:nom_(nom),niveau_(niveau),points_de_vie_(points_de_vie),force_(force),position_(position)
	{}
	
	bool vivant() const;
	
	int position() const
	{
		return position_;
	}
	
	int points_attaque() const;
	
	void deplacer(int mouv);
	
	void adieu() const;
	
	void faiblir(int points);
	
	void afficher();
	
};
/******************************************************************************/

bool Creature::vivant() const
{
	if (points_de_vie_>0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Creature::points_attaque() const
{
	if (vivant())
	{
		return niveau_ * force_;
	}
	else
	{
		return 0;
	}
}

void Creature::deplacer(int mouv)
{
	if (vivant())
	{
		position_+= mouv;
	}
}

void Creature::adieu() const
{
	std::cout << nom_ << " n'est plus !" << endl;
}

void Creature::faiblir (int points)
{
	if (vivant())
	{
		points_de_vie_ -= points;
	}
	
	if (not vivant())
	{
		points_de_vie_=0;
		adieu();
	}
	
}

void Creature::afficher()
{
	std::cout << nom_ << ", niveau: "
						<< niveau_ << ", points de vie: "
						<< points_de_vie_ << ", force: "
						<< force_	<< ", points d'attaque: "
						<< points_attaque() << ", position: "
						<< position_ << endl;
}

/******************************************************************************/
class Dragon : public Creature
{
	private:
	protected:
		int portee_flamme_;
	public:
		Dragon (string const nom,int niveau,int points_de_vie,int force,int portee_flamme,int position=0)
		: Creature(nom, niveau, points_de_vie, force, position),
			portee_flamme_(portee_flamme)
		{}
		
	void voler(int pos);
	
	void souffle_sur(Creature& bete);
};

	void Dragon::voler(int pos)
	{
		if (vivant())
		{
			position_=pos;
		}	
	}	
	
	void Dragon::souffle_sur(Creature& bete)
	{
		int d (0);
		d=distance( position_, bete.position());
		if (vivant() and bete.vivant())
		{
			if ( d <= portee_flamme_)
			{
				bete.faiblir(points_attaque());
				faiblir(d);
			}
				if (vivant()==true and  bete.vivant()==false)
			{
				++niveau_;
			}
		}
	
	}
	
/****************************************************************************************/
class Hydre : public Creature
{
	private:
	protected:
		int longueur_cou_;
		int dose_poison_;
	public:
		Hydre (string const nom,int niveau,int points_de_vie,int force, int longueur_cou, int dose_poison, int position=0)
		: Creature(nom, niveau, points_de_vie, force, position),
			longueur_cou_(longueur_cou),dose_poison_(dose_poison)
		{}
		
		void empoisonne( Creature& bete);
		
};	
	
void Hydre::empoisonne( Creature& bete)
{
	int d(0);
	d=distance(position_,bete.position());
	
	if (vivant() and bete.vivant())
	{ if (d <= longueur_cou_)
		{
			bete.faiblir(dose_poison_+ points_attaque());
		}
		if (bete.vivant()==false)
		{
			++niveau_;
		}
	
	}
	
	

	void combat(Dragon&  drag,Hydre& hydr);
}	

void combat(Dragon& drag,Hydre& hydr)
{
	hydr.empoisonne(drag);
	drag.souffle_sur(hydr);
}
	
	
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  Dragon dragon("Dragon rouge"   , 2, 10, 3, 20         );
  Hydre  hydre ("Hydre maléfique", 2, 10, 1, 10, 1,  42 );

  dragon.afficher();
  cout << "se prépare au combat avec :" << endl;
  hydre.afficher();

  cout << endl;
  cout << "1er combat :" << endl;
  cout << "    les créatures ne sont pas à portée, donc ne peuvent pas s'attaquer."
       << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon vole à proximité de l'hydre :" << endl;
  dragon.voler(hydre.position() - 1);
  dragon.afficher();

  cout << endl;
  cout << "L'hydre recule d'un pas :" << endl;
  hydre.deplacer(1);
  hydre.afficher();

  cout << endl;
  cout << "2e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 2 points de vie supplémentaires\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 41 = 2 ].\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon avance d'un pas :" << endl;
  dragon.deplacer(1);
  dragon.afficher();

  cout << endl;
  cout << "3e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 1 point de vie supplémentaire\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 42 = 1 ] ;\n\
  + l'hydre est vaincue et le dragon monte au niveau 3.\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "4e Combat :" << endl;
  cout << "    quand une créature est vaincue, rien ne se passe." << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  return 0;
}
