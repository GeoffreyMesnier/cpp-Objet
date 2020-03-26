#include <iostream>
#include <cmath> // pour M_PI
#include <vector>
using namespace std;



class Vivipare{
public:
    Vivipare(unsigned int jours=128)
    :gestation(jours)
    {}

    void naissance () const;
protected:
    unsigned int gestation;
};

void Vivipare::naissance() const
{
    std::cout << "Apres " << gestation << " jours de gestation , je viens de mettre au monde un nouveau bébé" << std::endl;
}

class Ovipare{
public:
    Ovipare(unsigned int nombre=12)
    :oeufs(nombre)
    {}

    void naissance() const;
protected:
    unsigned int oeufs;
};

void Ovipare::naissance() const
{
    std::cout << "Je viens de pondres environ " << oeufs << " oeuf(s) " << endl;
}

class Ovovivipare: public Vivipare, public Ovipare
{
public:
    Ovovivipare(unsigned int jours,unsigned int nombre,bool rare=false)
    :Vivipare(jours),
     Ovipare(nombre),
     espece_rare(rare)
    {}

protected:
    bool espece_rare;
};


int main()
{

    return 0;
}

