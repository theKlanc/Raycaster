#include "point3d.h"

point3d::point3d() {
	x = y = z = 0;
}

point3d::~point3d() {}

double point3d::getX() const {
	return x;
}
double point3d::getY() const {
	return y;
}
double point3d::getZ() const {
	return z;
}

point3d point3d::operator+(point3d element) const {
	return point3d(x + element.x, y + element.y, z + element.z);
}
point3d point3d::operator-(point3d element) const {
	return point3d(x - element.x, y - element.y, z - element.z);
}
point3d point3d::operator*(point3d element) const {
	return point3d(x * element.x, y * element.y, z * element.z);
}
point3d point3d::operator/(point3d element) const {
	return point3d(x * element.x, y * element.y, z * element.z);
}