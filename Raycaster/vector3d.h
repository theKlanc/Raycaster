#pragma once
// Aixo realment no es un vector, sinò un bipunt/linia, pero pot usar-se per representar vectors. SEPARANT
#include "point3d.h"

class vector3d {
public:
	vector3d();
	vector3d(point3d desti);
	vector3d(point3d origin, point3d tip);
	vector3d(point3d vec, double length);
	~vector3d();
	point3d getTip() const;
	void setLength(double l);
	double getLength() const;
	vector3d operator*(double d) const;
	vector3d operator*(vector3d v) const;
	vector3d operator+(vector3d v)const;
	vector3d operator-(vector3d v)const;
	bool operator<(double d) const;
	double dot(vector3d v) const;
private:
	double length;
	point3d unitaryVector;
};
