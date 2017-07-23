#pragma once
#include "model.h"
class sphere :
	public model {
public:
	sphere();
	sphere(double radius, point3d p) :radius(radius), pos(p) {};
	vector3d getNormalVectorAtPoint(point3d v) override;
	point3d getInwardLineIntersection(line3d v) override;
	point3d getOutwardLineIntersection(line3d v) override;
	bool isInside(point3d p) override;
	~sphere();
private:
	double radius;
	point3d pos;
};

