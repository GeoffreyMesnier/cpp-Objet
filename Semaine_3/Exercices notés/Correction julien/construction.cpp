#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
  private:
    Forme   forme   ;
    Couleur couleur ;

  public:
    /*****************************************************
      Compléter le code à partir d'ici
     *******************************************************/

    Brique(const Forme& forme, const Couleur& couleur)
      : forme(forme), couleur(couleur) {};

    std::ostream& afficher(std::ostream& sortie) const {
      if (couleur.empty()) {
        sortie << forme;
      } else {
        sortie << "(" << forme << ", " << couleur << ")";
      }
      return sortie;
    }
}; // Brique

std::ostream& operator << (std::ostream& os, const Brique& b){
  return b.afficher(os);
}


class Construction
{
  friend class Grader;

  public:
    Construction(const Brique& b) {
      std::vector<Brique> tmp1d(1, b);
      std::vector<std::vector<Brique> > tmd2d(1, tmp1d);
      contenu.push_back(tmd2d);
    }

    std::ostream& afficher(std::ostream& os) const {
      for (int i = contenu.size() - 1; i >= 0; --i) {
        os << "Couche " << i << " :" << std::endl;
        for (const auto& j: contenu[i]) {
          for (const Brique& b: j) {
            os << b;
          }
          os << std::endl;
        }
        // os << std::endl;
      }
      return os;
    }

    Construction& operator^=(const Construction& c) {
      for (const auto& iLevel: c.contenu) {
        contenu.push_back(iLevel);
      }
      return *this;
    }

    Construction& operator-=(const Construction& c) {
      unsigned thisHauteur = contenu.size();
      unsigned otherHauteur = c.contenu.size();
      // Si la hauteur de l'autre est plus petite que la notre, on fait rien
      if (otherHauteur >= thisHauteur) {
        // On ne va que jusqu'à la hauteur de nous, on oublie le reste
        for(std::size_t i = 0; i < contenu.size(); ++i) {
          for (const auto& p: c.contenu[i]) {
            contenu[i].push_back(p);
          }
        }
      }
      return *this;
    }

    Construction& operator+=(const Construction& c) {
      unsigned thisHauteur = contenu.size();
      unsigned otherHauteur = c.contenu.size();

      // Si la hauteur de l'autre est plus petite que la notre, on fait rien
      if (otherHauteur < thisHauteur) {
        return *this;
      }

      // On ne va que jusqu'à la hauteur de nous, on oublie le reste
      for(std::size_t i = 0; i < contenu.size(); ++i) {
        // Et on verifie les profondeurs
        if (c.contenu[i].size() < contenu[i].size()) {
          return *this;
        }
      }

      for (unsigned int i=0; i < contenu.size(); ++i) {
        for (unsigned int j=0; j < contenu[i].size(); ++j) {
          for (unsigned int k=0; k < c.contenu[i][j].size(); ++k) {
            contenu[i][j].push_back(c.contenu[i][j][k]);
          }
        }
      }

      return *this;
    }


    // i = hauteur
    // j = profondeur
    // k = largeur
    std::vector<std::vector<std::vector<Brique> > > contenu;
};

std::ostream& operator<<(std::ostream& os, const Construction& c) {
  return c.afficher(os);
}

Construction& operator^(Construction& lhs, const Construction& rhs) {
  lhs ^= rhs;
  return lhs;
}

Construction& operator+(Construction& lhs, const Construction& rhs) {
  lhs += rhs;
  return lhs;
}

Construction& operator-(Construction& lhs, const Construction& rhs) {
  lhs -= rhs;
  return lhs;
}

const Construction operator*(unsigned int n, Construction const& a)
{
  Construction b = a;
  for (unsigned int i = 1; i < n; i++){
    b += a;
  }
  return b;
}

const Construction operator/(unsigned int n, Construction const& a)
{
  Construction b = a;
  for (unsigned int i = 1; i < n; i++){
    b ^= a;
  }
  return b;
}

const Construction operator%(unsigned int n, Construction const& a)
{
  Construction b = a;
  for (unsigned int i = 1; i < n; i++){
    b -= a;
  }
  return b;
}


const Construction operator*(unsigned int n, Brique const& a)
{
  Construction b(a);
  return n*b;
}

const Construction operator/(unsigned int n, Brique const& a)
{
  Construction b(a);
  return n/b;
}

const Construction operator%(unsigned int n, Brique const& a)
{
  Construction b(a);
  return n%b;
}

const Construction operator^(const Brique& a, const Brique& b){
  Construction c(b);
  Construction ca(a);
  ca ^= b;
  return ca;
}

const Construction operator-(const Brique& a, const Brique & b){
  Construction c(b);
  Construction ca(a);
  ca -= b;
  return ca;
}

const Construction operator+(const Brique& a, const Brique& b){
  Construction c(b);
  Construction ca(a);
  ca += b;
  return ca;
}


const Construction operator+(const Brique& a, const Construction& b){
  Construction ca(a);
  ca += b;
  return ca;
}

// a est une copie ici
const Construction operator+(Construction a, const Brique& b){
  Construction cb(b);
  a += cb;
  return a;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;

  return 0;
}
