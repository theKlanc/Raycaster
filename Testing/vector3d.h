#pragma once
#include "point3d.h"

class vector3d {
public:
	vector3d();
	vector3d(point3d origin, point3d tip);
	vector3d(point3d vec, double length);
	~vector3d();
	point3d getTip() const;
	point3d getOrigin() const;
	void setLength(double l);
	double getLength();
private:
	double length;
	point3d unitaryVector;
	point3d origin;
};
