#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Punkt3D
{
public:
	float x;
	float y;
	float z;
	Punkt3D() {}
	~Punkt3D() {}
	Punkt3D(float a, float b, float c)
	{
		x = a;
		y = b;
		z = c;
	}
	Punkt3D operator+(int arg)
	{
		this->x = x + arg;
		this->y = y + arg;
		this->z = z + arg;
		return *this;
	}
};

class Wektor
{
public:
	float dx;
	float dy;
	float dz;
	Wektor() {}
	~Wektor() {}
	Wektor(float a, float b, float c)
	{
		dx = a;
		dy = b;
		dz = c;
	}
};

Punkt3D operator+(Punkt3D pkt, Wektor wek)
{
	pkt.x += wek.dx;
	pkt.y += wek.dy;
	pkt.z += wek.dz;
	return pkt;
}

Wektor operator* (Wektor wek1, Wektor wek2)
{
	Wektor mnozenie;
	mnozenie.dx = (wek1.dy * wek2.dz) - (wek1.dz * wek2.dy);
	mnozenie.dy = (wek1.dz * wek2.dx) - (wek1.dx * wek2.dz);
	mnozenie.dz = (wek1.dx * wek2.dy) - (wek1.dy * wek2.dx);
	return mnozenie;
}

ostream& operator<< (ostream& out, Punkt3D& p)
{
	out << "(" << p.x << ", " << p.y << ", " << p.z << ")" << endl;

	return out;
}

int main()
{
	Punkt3D punkt(1.0, 2.0, 3.0);
	Punkt3D punkt2(1.0, 2.0, 3.0);
	Punkt3D p;
	Wektor wektor(2.0, 1.0, 3.0);
	Wektor wektor2(2.0, 1.0, 3.0);
	Wektor w;

	p = punkt + wektor;
	w = wektor * wektor2;
	cout << "P1: " << p;
	p = punkt2 + w;
	cout << "P2: " << p;
	p = punkt2 + 3;
	cout << "P3: " << p;
	return 0;
}