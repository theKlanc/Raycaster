#include "vector3d.h"
#include <cmath>

vector3d::vector3d()
{
	origin = point3d(0, 0, 0);
	length = 0;
	unitaryVector = point3d(0, 0, 0);
}

vector3d::vector3d(point3d o, point3d tip) {
	origin = o;
	point3d normalizedTip = tip - o;
	length = sqrt(pow(normalizedTip.getX(), 2) + pow(normalizedTip.getY(), 2) + pow(normalizedTip.getZ(), 2));
	 unitaryVector = point3d(normalizedTip.getX() / length, normalizedTip.getY() / length, normalizedTip.getZ() / length);
}

vector3d::vector3d(point3d vec, double len)
{ 
	origin = point3d(0,0,0);
	length = sqrt(pow(vec.getX(), 2) + pow(vec.getY(), 2) + pow(vec.getZ(), 2));
	unitaryVector = point3d(vec.getX() / length, vec.getY() / length, vec.getZ() / length);
	length = len;
}

vector3d::~vector3d() {}

point3d vector3d::getTip() const
{
	return point3d(unitaryVector.getX()*length, unitaryVector.getY()*length, unitaryVector.getZ()*length)+origin;
}

point3d vector3d::getOrigin() const
{
	return origin;
}

void vector3d::setLength(double l) {
	length = l;
}

double vector3d::getLength() {
	return length;
}
