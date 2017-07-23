#pragma once
#include "model.h"
class sphere :
	public model {
public:
	sphere();
	sphere(double radius, point3d p):radius(radius),pos(p){};
	~sphere();
private:
	double radius;
	point3d pos;
};

