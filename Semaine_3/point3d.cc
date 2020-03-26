#include <iostream>
using namespace std;
class Point3D
{
public:
bool compare(const Point3D& autre) const;
void affiche() const;

ostream& affiche(ostream& sortie) const;

void init(double x0, double y0, double z0) {
x = x0; y = y0; z = z0;
}
private:
double x, y, z;
};

bool Point3D::compare(const Point3D& autre) const
{
return (autre.x == x) and (autre.y == y) and (autre.z == z);
}

void Point3D::affiche() const
{
cout << '(' << x << ", " << y << ", " << z << ')' << endl;
}


ostream& Point3D::affiche(ostream& sortie) const
{
	sortie << '(' << x << ", " << y << ", " << z << ')' << endl;
	return sortie;
}

ostream& operator<<(ostream& sortie, Point3D const& p)
{	
	return p.affiche(sortie);
}



int main() {
Point3D point1;
Point3D point2;
Point3D point3;
point1.init(1.0, 2.0, -0.1);
point2.init(2.6, 3.5, 4.1);
point3 = point1;
cout << "Point 1 :";
point1.affiche();
cout << "Point 2 :";
point2.affiche();
cout << "Le point 1 est ";
if (point1.compare(point2)) {
cout << "identique au";
} else {
cout << "différent du";
}
cout << " point 2." << endl;
cout << "Le point 1 est ";
if (point1.compare(point3)) {
cout << "identique au";
} else {
cout << "différent du";
}
cout << " point 3." << endl;

return 0;

}
