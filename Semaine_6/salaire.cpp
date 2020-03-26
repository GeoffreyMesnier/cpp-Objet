#include<iostream>
#include<string>
#include<vector>

using namespace std;



class Employe{
  public:
    Employe(string nom,string prenom,unsigned int age, string date)
    :nom(nom),prenom(prenom),age(age),date(date)
    {}

  virtual~Employe()
    {}

  virtual double calculer_salaire () const =0;

  virtual string get_nom() const;

  protected:
    string nom;
    string prenom;
    unsigned int age;
    string date;
};

string Employe::get_nom() const
{
  return "l'Employe "+nom+ ' '+prenom;
}


class Vendeur : public Employe{
  public:
  Vendeur(string nom,string prenom,unsigned int age,string date,double chiffre)
  :Employe(nom,prenom,age,date),
  chiffreAffaire(chiffre)
  {}
  ~Vendeur()
  {}
  protected:
   double chiffreAffaire;

};


class Vente : public Vendeur{
  public:
    Vente(string nom,string prenom,unsigned int age,string date,double chiffre)
    :Vendeur(nom,prenom,age,date,chiffre)
    {}
    ~Vente()
    {}
    double calculer_salaire()const;
    string get_nom() const;

};

string Vente::get_nom()const
 {
  return "Le Vente "+nom+' '+prenom;
}


double Vente::calculer_salaire() const
 {
  return 0.2*chiffreAffaire+ 400;
}

class Representation : public Vendeur{
  public:
    Representation(string nom,string prenom,unsigned int age,string date,double chiffre)
    :Vendeur(nom,prenom,age,date,chiffre)
    {}
    ~Representation()
    {}
   double calculer_salaire() const;
   string get_nom() const;
};

string Representation::get_nom()const
{
  return "Le Representation "+nom+" "+prenom;
}

double Representation::calculer_salaire() const
 {
  return 0.2*chiffreAffaire+800;
}


 class Production : public Employe{
  public:
    Production(string nom,string prenom,unsigned int age,string date,unsigned int nb_unite)
    :Employe(nom,prenom,age,date),
     unite(nb_unite)
    {}
    ~Production()
    {}
    double calculer_salaire() const;
    string get_nom() const;


  protected:
    unsigned int unite;

};

string Production::get_nom()const
 {
  return "Le Production "+nom+" "+prenom;
}

double Production::calculer_salaire()const
{
  return unite*5;
}


class Manutention : public Employe{
  public:
   Manutention(string nom,string prenom,unsigned int age,string date,unsigned int nb_heures)
  :Employe(nom,prenom,age,date),
  heures(nb_heures)
    {}
   ~Manutention()
   {}
    double calculer_salaire() const;
    string get_nom() const;
  protected:
    unsigned int heures;

};

string Manutention::get_nom()const
 {
  return "Le Production "+nom+" "+prenom;
}

double Manutention::calculer_salaire()const
{
  return heures*65;
}


class Personnel{
  public:
    void ajouter_employe(Employe*);
    void calculer_salaires() const;
    double salaire_moyen() const;
    void licencie();

  protected:
  vector<Employe*> contenu;
};

void Personnel::ajouter_employe(Employe* employe)
{
  contenu.push_back(employe);
}

void Personnel::calculer_salaires() const
{
  for( auto element : contenu)
  {
   cout << element->get_nom()<< element->calculer_salaire()<< endl;
  }
}


void Personnel::licencie()
{
  for (auto element : contenu)
  {
    delete element;
  }
  contenu.clear();
}

double Personnel::salaire_moyen() const
{
  double somme (0);
  for (auto element: contenu)
  {
    somme+= element->calculer_salaire();
  }
  return somme/contenu.size();
}


int main () {
Personnel p;
p.ajouter_employe(new Vente("Pierre", "Business", 45, "1995", 30000));
p.ajouter_employe(new Representation("Léon", "Vendtout", 25, "2001", 20000));
p.ajouter_employe(new Production("Yves", "Bosseur", 28, "1998", 1000));
p.ajouter_employe(new Manutention("Jeanne", "Stocketout", 32, "1998", 45));

p.calculer_salaires();
cout << "Le salaire moyen dans l'entreprise est de "
<< p.salaire_moyen() << " francs." << endl;
}











