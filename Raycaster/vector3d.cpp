#include "vector3d.h"
#include <cmath>

vector3d::vector3d() { //OKK
	length = 0;
	unitaryVector = point3d(0, 0, 0);
}

vector3d::vector3d(point3d desti) {
	length = sqrt(pow(desti.getX(), 2) + pow(desti.getY(), 2) + pow(desti.getZ(), 2));
	unitaryVector = point3d(desti.getX() / length, desti.getY() / length, desti.getZ() / length);
}

vector3d::vector3d(point3d o, point3d tip) { //OKK
	point3d normalizedTip = tip - o;
	length = sqrt(pow(normalizedTip.getX(), 2) + pow(normalizedTip.getY(), 2) + pow(normalizedTip.getZ(), 2));
	unitaryVector = point3d(normalizedTip.getX() / length, normalizedTip.getY() / length, normalizedTip.getZ() / length);
}

vector3d::vector3d(point3d vec, double len) { //OKK
	double vecLength = sqrt(pow(vec.getX(), 2) + pow(vec.getY(), 2) + pow(vec.getZ(), 2));
	unitaryVector = point3d(vec.getX() / vecLength, vec.getY() / vecLength, vec.getZ() / vecLength);
	length = len;
}

vector3d::~vector3d() {}

point3d vector3d::getTip() const { //OK
	return (point3d(unitaryVector.getX()*length, unitaryVector.getY()*length, unitaryVector.getZ()*length));
}

void vector3d::setLength(double l) { //OK
	length = l;
}

double vector3d::getLength() const { //OK
	return length;
}

vector3d vector3d::operator*(double d) const { //OK
	vector3d temp(*this);
	temp.length *= d;
	return temp;
}

vector3d vector3d::operator*(vector3d v) const {//PRODUCTE VECTORIAL  OK
	// a x b = (a2b3 - a3b2),(a3b1 - a1b3),(a1b2-a2b1)
	return vector3d(point3d((getTip().getY()*v.getTip().getZ() - getTip().getZ()*v.getTip().getY()),
		(getTip().getZ()*v.getTip().getX() - getTip().getX()*v.getTip().getZ()),
		(getTip().getX()*v.getTip().getY() - getTip().getY()*v.getTip().getX())));
}

vector3d vector3d::operator+(vector3d v) const { //OK
	return vector3d(getTip() + v.getTip());
}

vector3d vector3d::operator-(vector3d v) const {  //OK
	return vector3d(getTip() - v.getTip());
}

bool vector3d::operator<(double d) const {  //OK
	return (getTip().getX() < d && getTip().getY() < d && getTip().getZ() < d);
}

double vector3d::dot(vector3d v) const { //OK
	return ((getTip().getX()*v.getTip().getX()) + (getTip().getY()*v.getTip().getY()) + (getTip().getZ()*v.getTip().getZ()));
}
