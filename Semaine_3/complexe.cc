#include <iostream>
#include <ctime>

// pour les nombres aléatoires

#include <cstring> // strlen
#include <cmath>

using namespace std;

class Complexe{
	public:
		double reel() const
		{ return m_re;}
		double imag() const
		{ return m_im;}
		
		
		Complexe (const double re = 0.0 ,const double im = 0.0)
		: m_re(re),m_im(im)
		{
	  }
		
		bool operator==(const Complexe&) const;
	
		Complexe& operator+=(const Complexe&);
		Complexe& operator-=(const Complexe&);
		Complexe& operator*=(const Complexe&);
		Complexe& operator/=(const Complexe&);
		
		Complexe operator+(const Complexe&) const;
		Complexe operator-(const Complexe&) const;
		Complexe operator*(const Complexe&) const;
		Complexe operator/(const Complexe&) const;
		
		
	private:
		double m_re;
		double m_im;
		
	  void set_reel(double x)
	  { m_re=x;}
	  void set_imag (double y)
	  { m_im = y;}
	 
};

Complexe operator+(const double, const Complexe&);
Complexe operator-(const double, const Complexe&);
Complexe operator*(const double, const Complexe&);
Complexe operator/(const double, const Complexe&);



bool Complexe::operator==(const Complexe& c) const
{
	if ((reel()==c.reel()) and (imag()== c.imag()))
	{
		return true;
	}
	else
	{
		return false;
	}	
}

Complexe& Complexe::operator+=(const Complexe& x)
{
	set_reel( reel() + x.reel());
	set_imag ( imag() + x.imag());
	return *this;
} 

Complexe& Complexe::operator-=(const Complexe& x)
{
	set_reel ( reel() - x.reel());
	set_imag ( imag() - x.imag());
	return *this;
}

Complexe& Complexe::operator*=(const Complexe& x)
{
	const double anc_reel( reel() );
	
	set_reel ( reel() * x.reel()  - imag() * x.imag() );
	set_imag ( anc_reel * x.imag() +  x.reel() * imag() );
	return *this;
}

Complexe& Complexe::operator/=(const Complexe& x)
{
	const double anc_reel( reel() );
	const double r = ( x.reel()*x.reel() + x.imag()*x.imag());
	set_reel ( ( reel() * x.reel() - imag() * x.imag()) / r);
	set_imag ( ( anc_reel * x.imag() + x.reel() * imag() ) / r); 
	return *this;
}

//Affichage
ostream& operator<<(ostream&,const Complexe&);

//Affichage définition
ostream& operator<<(ostream& sortie,const Complexe& c)
{
	sortie << '(' << c.reel() <<" , " << c.imag() << ")";
	return sortie;
}

Complexe Complexe::operator+(const Complexe& x) const
{
	return Complexe (*this) += x;
}

Complexe Complexe::operator-(const Complexe& x) const
{
	return Complexe (*this) -= x;
}

Complexe Complexe::operator*(const Complexe& x) const 
{ 
	return Complexe (*this) *= x;
}

Complexe Complexe::operator/(const Complexe& x) const
{
	return Complexe (*this) /= x;
}

Complexe operator+(const double y,const Complexe& x)
{
	return (Complexe(y) + x);
}

Complexe operator-(const double y,const Complexe& x)
{
	return (Complexe(y) - x);
}

Complexe operator*(const double y, const Complexe& x)
{
	return (Complexe(y) * x);
}

Complexe operator/(const double y, const Complexe& x)
{
	return (Complexe(y) / x);
}

int main ()
{
	 Complexe defaut;
	 Complexe zero(0.0,0.0);
	 Complexe un(1.0,0.0);
	 Complexe i(0.0,1.0);
	 Complexe j;
	 
	 cout << zero << " ==? " << defaut;
	 if (zero == defaut) cout << " oui" << endl;
	 else cout << " non" << endl;
	 
	 cout << zero << " ==? " << i;
	 if (zero == i) cout << " oui" << endl;
	 else cout << " non" << endl;
	 
	 j = un + i;
	 cout << un << " + " << i << " = " << j << endl;
	 
	 Complexe trois(un);
	 trois += un;
	 trois += 1.0;
	 cout << un << " + " << un << " + 1.0 = " << trois << endl;
	 
	 Complexe deux(trois);
	 deux -= un;
	 cout << trois << " - " << un << " = " << deux << endl;
	 
	 trois = 1.0 + deux;
	 cout << "1.0 + " << deux << " = " << trois << endl;
	 
	 Complexe z (i*i);
	 cout << i << " * " << i << " = " << z << endl;
	 cout << z << " / " << i << " = " << z/i << " = ";
	 cout << (z/=i) << endl;
	 
	 Complexe k(2.0,-3.0);
	 z = k;
	 z *= 2.0;
	 z *= i;
	 cout << k << " * 2.0 " << i <<" = " << z << endl;
	 z = 2.0 * k *i  /1.0;
	 cout << " 2.0 * " << k << " * " << i << " / 1 = " << z << endl;  
	 
	 
	 return 0;

}
