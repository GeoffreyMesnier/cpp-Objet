#include <iostream>
#include <cmath> // pour M_PI
#include <vector>
using namespace std;



class Animal{
public:
  Animal(string espece,string lieu)
  :nom(espece),continent(lieu)
  {
    cout << " Nouvel animal protégé"<< endl;
  }
  ~Animal()
  {
    cout << "je ne suis plus protégé" << endl;
  }
  void affiche () const;
protected:
  string nom;
  string continent;

};

void Animal::affiche() const
{
  cout << "Je suis un " << nom << " et je vis en " << continent << endl;
}

class EnDanger{
public:
  EnDanger(int reste)
  :nombre(reste)
  {
    cout << " Nouvel animal en danger" << endl;
  }

  ~EnDanger()
  {
    cout << " Ouf je ne suis plus en danger" << endl;
  }

  void affiche() const;
protected:
  int nombre;

};

void EnDanger::affiche() const
{
  cout << " Il ne reste que " << nombre << " individus de mon espece sur Terre ! " << endl;
}

class Gadget{
public:
  Gadget(string name,double tarif)
  : nom(name),prix(tarif)
  {
    cout << "Nouveau gadjet" << endl;
  }

  ~Gadget()
  {
    cout << "Je ne suis plus un gadjet" << endl;
  }
  void affiche() const;
  void affiche_prix() const;
protected:
  string nom;
  double prix;

};

void Gadget::affiche() const
{
  cout << "Mon nom est "<< nom << endl;
}

void Gadget::affiche_prix() const
{
  cout << "Achetez-moi pour " << prix << " francs et vous contribuerez à me sauer !" << endl;
}

class Peluche : public Animal, public EnDanger ,public Gadget {
  public:
  Peluche(string espece,string nom,string continent,int nombre,double prix)
  :Animal(espece,continent),
   EnDanger(nombre),
   Gadget(nom,prix)
  {
    cout << "Nouvelle etiquette" << endl;
  }

  ~Peluche()
  {
    cout << "Peluche détruite"<< endl;
  }
  void etiquette () const;

  protected:

};

void Peluche::etiquette () const
{
  cout<< "Hello," <<endl;
  Gadget::affiche();
  Animal::affiche();
  EnDanger::affiche();
  Gadget::affiche_prix();
}

int main()
{
  Peluche panda("Panda","Ming","Asie",200,20.0);
  Peluche serpent("Cobra","Ssss","Asie",500,10.0);
  Peluche toucan("Toucan","Bello","Amerique",1000,15.0);

  panda.etiquette();
  serpent.etiquette();
  toucan.etiquette();

  return 0;

}

