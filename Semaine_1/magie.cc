#include <iostream>
#include <ctime>

// pour les nombres aléatoires

#include <cstring> // strlen
#include <cmath>

using namespace std;


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

class Papier{
public:
	void ecrire (int un_age,int de_l_argent );
	int lire_age() const { return Age;}
	int lire_somme() const {return Argent;}
	
private:
	int Age;
	int Argent;	
};


class Spectateur{
	public:
   void initialise();
   void ecrire();
   Papier montre();
	private:
int age;
int argent;
Papier paquets_cigarettes;

};

class Assistant{
	public:
	void lire(const Papier& billet);
	void calcul();
	int annoncer();
		

	private:
int age_lu;
int argent_lu;
int resultat;
};	

class Magicien{

public:
	void tourdemagie (Assistant& asst, Spectateur& spect);
	   
private:
	 void calcul_age_somme(int resultat_recu);
	 void annoncer();
	 
 
 int age_devine;
 int argent_devine;	
};


int main()
{
   //L'histoire générale:
   Spectateur geoffrey;
   geoffrey.initialise();
   
   Magicien Gandalf;
   Assistant Bilbo;
   Gandalf.tourdemagie(Bilbo,geoffrey);
   
   	

  return 0;
}

//Papier

void Papier::ecrire (int un_age,int de_l_argent ){
	Age = un_age;
	Argent=de_l_argent;
}

//Assistant
void Assistant::lire(const Papier& billet)
{
	cout << "Je lis le papiers "<< endl;
	age_lu=billet.lire_age();
	argent_lu=billet.lire_somme();
}

void Assistant::calcul(){
	
		cout << "Je calcul Mentalement" << endl;
		resultat=age_lu* 2;
		resultat += 5;
		resultat *= 50;
		resultat += argent_lu;
		resultat -=365;
}

int Assistant::annoncer(){
	cout << "Le resultat est " << resultat << endl;
	return resultat;
}


//Spectateur
void Spectateur::initialise(){
	cout << "[Spectateur]" << "J entre en scene" <<endl;
	cout << "quel age ai-je " ;
	cin >> age;
	do {
		cout << "Combien d'argent ai-je en poche" ;
		cin >> argent;	
	}while(argent<1 or argent >99);
	cout << "[Spectateur] je suis la" << endl;
}

void Spectateur::ecrire(){
	cout << "[Spectateur] J'écrit le papier" << endl;
	paquets_cigarettes.ecrire(age,argent);
}

Papier Spectateur::montre(){
	cout << "[Spectateur] je montre le papier" << endl;
	return paquets_cigarettes;
}

//Magicien
void Magicien::tourdemagie(Assistant& fidele,Spectateur& quidam)
{
// Le magicien donne ses instruction
quidam.ecrire();
fidele.lire(quidam.montre());
fidele.calcul();
calcul_age_somme(fidele.annoncer());
annoncer();	
}
void Magicien::calcul_age_somme(int resultat_recu)
{
	resultat_recu += 115;
	age_devine= resultat_recu /100;
	argent_devine =resultat_recu %100;
}

void Magicien::annoncer()
{
	cout << " [Magicien]" << endl;
	cout <<" Hum je vois que vous etes agé de " << age_devine << " ans " << endl;
	cout << "  et que vous avez" << argent_devine << " francs en poche!" << endl;
}
