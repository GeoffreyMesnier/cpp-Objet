#include <iostream>
#include <ctime>

// pour les nombres aléatoires

#include <cstring> // strlen
#include <cmath>

using namespace std;


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

class Point3D{
	public:
	void init(double x_ini, double y_ini ,double z_ini);
	void affiche() const;
	bool compare(const Point3D& tester) const;
	
	private:
int x;
int y;
int z;
	
};

int main()
{
	Point3D point1;
	Point3D point2;
	Point3D point3;
	
	point1.init(1.0,2.0,-0.1);
	point2.init(2.6,3.5,4.1);
	point3 = point1;
	
	cout << "Le point 1 est ";
	if (point1.compare(point2)){
	cout << "identique au";
	}
	else
	{
	cout << "différent de";	
    }
    cout << "Point 2.";
    
    cout << "Le point 3 est ";
	if (point1.compare(point3)){
	cout << "identique au";
	}
	else
	{
	cout << "différent de";	
    }
    cout << "Point 3.";
	return 0;
}

void Point3D::init(double x_ini,double y_ini,double z_ini)
{
	x=x_ini;
	y=y_ini;
	z=z_ini;
}

void Point3D::affiche() const
{   
	cout << "x: " << x << " y: " << " z: " << endl;

}

bool Point3D::compare(const Point3D& Objet) const
{
	
	if ((x==Objet.x) and (y==Objet.y) and (z==Objet.z))
	{
	 return true;
	}
	else 
	{
	 return false;
	}
}



