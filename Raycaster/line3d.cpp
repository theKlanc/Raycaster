#include "line3d.h"



line3d::line3d() {}

line3d::line3d(point3d origin, point3d tip)
{
	this->origin = origin;
	vec = vector3d(origin, tip);
}

point3d line3d::getTip() const {
	return origin + vec.getTip();
}

point3d line3d::getOrigin() const {
	return origin;
}

vector3d line3d::getVector() const {
	return vec;
}


line3d::~line3d() {}
