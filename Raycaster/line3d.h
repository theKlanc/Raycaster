#pragma once
#include "point3d.h"
#include "vector3d.h"

class line3d {
public:
	line3d();
	line3d(point3d origin, vector3d vec) : origin(origin), vec(vec) {};
	line3d(point3d origin, point3d tip);
	point3d getTip() const;
	point3d getOrigin() const;
	vector3d getVector() const;
	~line3d();
private:
	point3d origin;
	vector3d vec;
};

