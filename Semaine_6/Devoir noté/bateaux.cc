#include <iostream>
#include <cmath>
using namespace std;

enum Pavillon { JollyRogers, CompagnieDuSenegal, CompagnieDOstende };

enum Etat { Intact, Endommage, Coule };

int sq(int x)
{
  return x*x;
}

class Coordonnees
{
public:
  Coordonnees(int un_x, int un_y) : x_(un_x), y_(un_y) {}
  int x() const {
    return x_;
  }
  int y() const {
    return y_;
  }
  void operator+=(Coordonnees const& autre); // à définir plus bas
private:
  int x_;
  int y_;
};

class Navire
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
	public:
	 Navire(int x,int y,Pavillon pavillon,Etat etat=Intact)
	:position_(x,y),pavillon_(pavillon),etat_(etat)
	{}
	
	
	const Coordonnees& position() const;
	
	void avancer (int de_x,int de_y);
	
	void renflouer();
	
	virtual void attaque (Navire&) =0;	
  virtual void replique (Navire&) =0;
 	virtual void est_touche () =0;
	
	void rencontrer (Navire&);
	
	virtual ostream& afficher(ostream& sortie) const;
	
	protected:
	Coordonnees position_;	
	Pavillon pavillon_;
	Etat etat_;
	static const int rayon_rencontre=10;
};

//Fonction spécifique affichage et calcul.
void Coordonnees::operator+=(Coordonnees const& autre)
{
  x_+=autre.x_;
  y_+=autre.y_;

}

double distance (const Coordonnees& cord1,const Coordonnees& cord2)
{
	double z(0);
	double u(0);

	z=pow((cord1.x()-cord2.x()),2);
	u=pow((cord1.y()-cord2.y()),2);
	
	
	return sqrt(z+u); 
}

double distance (const Navire& navire1,const Navire& navire2)
{
	Coordonnees x(navire1.position());
	Coordonnees y(navire2.position());
	double resultat= distance(x,y);
	return resultat;
}
ostream& operator<<(ostream& sortie,const Coordonnees& cord)
{
	sortie << '(' << cord.x() << ", " << cord.y() << ')';
	return sortie;
}

ostream& operator<<(ostream& sortie,Pavillon pav)
{
	
	if (pav == 0)
	{
		sortie << "pirate";
		return sortie; 
	}
	
	if (pav == 1)
	{
		sortie << "francais";
		return sortie;
	}
	if (pav == 2)
	{
		sortie << "autrichien";
		return sortie;
	}
	sortie << "pavillon inconnu";
	return sortie;
}

ostream& operator<<(ostream& sortie,Etat eta)
{
	if (eta == 0)
	{
		sortie << "intact";
		return sortie; 
	}
	
	if (eta == 1)
	{
		sortie << "ayant subi des dommages";
		return sortie;
	}
	if (eta == 2)
	{
		sortie << "coulé";
		return sortie;
	}
	sortie << "etat inconnu";
	return sortie;
}


void Navire::rencontrer(Navire& nav) 
{
	if ((this->etat_ != Coule) and (nav.etat_ != Coule))
	{
		if (this->pavillon_ != nav.pavillon_)
		{
				if ( distance(this->position_,nav.position_) < rayon_rencontre)
				
				{
					this->attaque(nav);
					if (nav.etat_ != Coule)
					{
						nav.replique(*this);
					}
				}
		}
	}
}

class Pirate : virtual public Navire{
	public:
	Pirate(int x,int y,Pavillon pavillon,Etat etat=Intact)
	:Navire(x,y,pavillon,etat)
	{}
	void virtual attaque(Navire&);
	void replique (Navire&);
	void virtual est_touche();
	ostream& afficher(ostream& sortie) const;

};

void Pirate::attaque(Navire& ennemi)
{
	cout << "A l'abordage !" << endl;
	ennemi.est_touche();

}

void Pirate::replique (Navire& ennemi)
{
	if (this->etat_ != 0)
	{
		cout << "Non mais, ils nous attaquent ! On riposte!!" << endl;
		this->attaque(ennemi);
	}
}

void Pirate::est_touche() 
{
	
	if(this->etat_== Intact)
	{
		this->etat_ = Endommage;
	}
	else
	{
		if(this->etat_== Endommage) this->etat_ = Coule;
	}
}


class Marchand : virtual public Navire{
	public:
	Marchand(int x,int y,Pavillon pavillon,Etat etat=Intact)
	:Navire(x,y,pavillon,etat)
	{}
	void virtual attaque(Navire&);
  void replique (Navire&);
 	void est_touche ();
 	ostream& afficher(ostream& sortie) const;

};



void Marchand::attaque(Navire& ennemi) 
{
	cout << "On vous aura ! (insultes)" << endl;

	
}

void Marchand::replique (Navire& ennemi)
{
	if (this->etat_ == Coule)
	{
		cout << "SOS Je coule" << endl;
	}
	else
	{
		cout<< "Même pas peur !" << endl;
	}
}

void Marchand::est_touche()
{
	this->etat_= Coule;
}


class Felon :public Marchand, public Pirate{
	public:
	Felon(int x,int y,Pavillon pavillon,Etat etat=Intact)
	: Navire(x,y,pavillon,etat),
		Marchand(x,y,pavillon,etat),
		Pirate(x,y,pavillon,etat)
	{}
	
	void attaque(Navire&);
	void replique(Navire&);
	void est_touche();
	ostream& afficher(ostream& sortie) const;
	
	protected:
	
	
};

void Felon::attaque(Navire& nav)
{
	Pirate::attaque(nav);
}

void Felon::replique(Navire& nav)
{
	Marchand::replique(nav);
}

void Felon::est_touche()
{
	Pirate::est_touche();
}


void Navire::avancer (int de_x,int de_y)
{
	Coordonnees temp(de_x,de_y);
	position_+=(temp);
}

const Coordonnees& Navire::position() const
{
	return position_;
}

void Navire::renflouer()
{
	etat_=Intact;
}


ostream& Navire::afficher(ostream& sortie) const
{
	sortie<< "navire " << pavillon_ << " en "<< position_ << " battant pavillon " << pavillon_ << ", " << etat_;
	return sortie;
}

ostream& Pirate::afficher(ostream& sortie) const
{
	sortie<< "bateau pirate en "<< position_ << " battant pavillon " << pavillon_ << ", " << etat_;
	return sortie;
}

ostream& operator<<(ostream& sortie,const Navire& nav)
{
	return nav.afficher(sortie);	
}

ostream& Marchand::afficher(ostream& sortie) const
{
	sortie<< "navire marchand en "<< position_ << " battant pavillon " << pavillon_ << ", " << etat_;
	return sortie;
}

ostream& Felon::afficher(ostream& sortie) const
{
	sortie<< "navire félon en "<< position_ << " battant pavillon " << pavillon_ << ", " << etat_;
	return sortie;
}


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void rencontre(Navire& ship1, Navire& ship2)
{
  cout << "Avant la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
  cout << "Distance : " << distance(ship1, ship2) << endl;
  ship1.rencontrer(ship2);
  cout << "Apres la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
}

int main()
{
  // Test de la partie 1
  cout << "===== Test de la partie 1 =====" << endl << endl;

  // Un bateau pirate 0,0
  Pirate ship1(0, 0, JollyRogers);
  cout << ship1 << endl;

  // Un bateau marchand en 25,0
  Marchand ship2(25, 0, CompagnieDuSenegal);
  cout << ship2 << endl;

  cout << "Distance : " << distance(ship1, ship2) << endl;

  cout << "Quelques déplacements..." << endl;
  cout << "  en haut à droite :" << endl;
  // Se déplace de 75 unités à droite et 10 en haut
  ship1.avancer(75, 10);
  cout << ship1 << endl;

  cout << "  vers le bas :" << endl;
  ship1.avancer(0, -5);
  cout << ship1 << endl;

  cout << endl << "===== Test de la partie 2 =====" << endl << endl;

  cout << "Bateau pirate et marchand ennemis (trop loins) :" << endl;
  rencontre(ship1, ship2);

  cout << endl << "Bateau pirate et marchand ennemis (proches) :" << endl;
  ship1.avancer(-40, -2);
  ship2.avancer(10, 2);
  rencontre(ship1, ship2);

  cout << endl << "Deux bateaux pirates ennemis intacts (proches) :" << endl;
  Pirate ship3(33, 8, CompagnieDOstende);
  rencontre(ship1, ship3);

  cout << endl << "Bateaux pirates avec dommages, ennemis :" << endl;
  rencontre(ship1, ship3);

  cout << endl << "Bateaux marchands ennemis :" << endl;
  Marchand ship4(21, 7, CompagnieDuSenegal);
  Marchand ship5(27, 2, CompagnieDOstende);
  rencontre(ship4, ship5);

  cout << endl << "Pirate vs Felon :" << endl;
  ship3.renflouer();
  Felon ship6(32, 10, CompagnieDuSenegal);
  rencontre(ship3, ship6);

  cout << endl << "Felon vs Pirate :" << endl;
  rencontre(ship6, ship3);

  return 0;
}
