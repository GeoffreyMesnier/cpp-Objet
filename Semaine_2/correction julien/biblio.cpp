#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
class Auteur{
  public:
    //Constructeur
    Auteur(const std::string& nom, bool prime=false)
      : nom(nom), prime(prime)
    { }

    // Delete the copy Ctor
    Auteur(Auteur const&) = delete;

    // Retourne nom de l'auteur
    std::string getNom () const {
      return nom;
    }

    bool getPrix() const {
      return prime;
    }

  private:
    std::string nom;
    bool prime;
};

class Oeuvre{
  public:
    Oeuvre(const std::string& titre, const Auteur& auteur, const std::string& langue)
      : m_titre(titre),m_auteur(auteur), m_langue(langue)
    {
    }

    Oeuvre(Oeuvre const&) = delete;

    std::string getTitre() const {
      return m_titre;
    }

    const Auteur& getAuteur() const {
      return m_auteur;
    }

    std::string getLangue() const {
      return m_langue;
    }

    void affiche() const {
      std::cout << m_titre << ", "<< m_auteur.getNom() << ", en " << m_langue;
    }

    ~Oeuvre()
    {
      std::cout << "L'oeuvre " << m_titre << ", " << m_auteur.getNom() << ", en "<< m_langue <<" n'est plus disponible" << std::endl;
    }
  private:
    std::string m_titre;
    const Auteur& m_auteur;
    std::string m_langue;
};

class Exemplaire{
  public:
    Exemplaire(const Oeuvre& oeuvre)
      : m_oeuvre(oeuvre)
    {
      // TODO: ca sera pas bon ca
      std::cout << "Nouvel exemplaire de : ";
      m_oeuvre.affiche();
      std::cout << std::endl;
    }
    /*
       Exemplaire(Exemplaire const& autre)
       : m_oeuvre(autre)
       {
       std::cout << "Copie d'un exemplaire de : ";
       m_oeuvre.affiche();
       std::cout << std::endl;
       }
       */
    ~Exemplaire()
    {
      std::cout << "Un exemplaire de ";
      m_oeuvre.affiche();
      std::cout << " a été jeté !"<< std::endl;
    }
    const Oeuvre& getOeuvre() const
    {
      return m_oeuvre;
    }

    void affiche() const
    {
      std::cout << "Exemplaire de : " ;
      m_oeuvre.affiche() ;
      std::cout << std::endl;
    }

  private:
    const Oeuvre& m_oeuvre;
};

class Bibliotheque{

  public:
    Bibliotheque(const std::string& nom)
      : m_nom(nom)
    {
      std::cout << "La bibliotheque " << nom << " est ouverte" << std::endl;
    }

    std::string getNom() const
    {
      return m_nom;
    }


    void stocker (const Oeuvre& oeuvre, int nbexemplaire=1)
    {
      for(int i=0; i< nbexemplaire ; ++i)
      {
        m_tab.push_back(new Exemplaire(oeuvre));
      }
    }

    void lister_exemplaires(std::string langue="") const
    {
      for (auto& ePtr: m_tab) {
        if (langue.empty() || (ePtr->getOeuvre().getLangue() == langue)) {
          std::cout << "Example de: " << "FINISH ME" << std::endl;
        }
      }
    }

    int compter_exemplaires(const Oeuvre& oeuvre) const {
      int result = 0;
      for (auto& ePtr: m_tab) {
        if (&ePtr->getOeuvre() == &oeuvre) {
          ++result;
        }
      }
      return result;
    }

    void afficher_auteurs() const {

    }

  private:
    std::string m_nom;
    std::vector<Exemplaire*> m_tab;


};
// Chaines de caractères à utiliser pour les affichages:
/*

   été jeté

   d'un

   n'est

   L'oeuvre

   bibliothèque

   détruit

*/

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  cout << a1.getNom()<<" " << a2.getNom() << " " << a3.getNom() << endl;


  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  cout << "Titre: "<< o1.getTitre() << endl;
  o1.affiche();

  cout << "Titre: "<< o2.getTitre() << endl;
  o2.affiche();

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
    << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const std::string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  // TODO: biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
    << o3.getTitre() << endl;

  return 0;
}
