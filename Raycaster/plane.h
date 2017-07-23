#pragma once
#include "model.h"
#include "vector3d.h"
#include "line3d.h"

class plane :
	public model {
public:
	plane();
	plane(vector3d vec, point3d p);
	plane(double A, double B, double C, double d) :A(A), B(B), C(C), d(d) {};
	~plane();
	vector3d getNormalVectorAtPoint(point3d v) override;
	point3d getLineIntersection(line3d v) override;
	bool isInside(point3d p) override;
private:
	vector3d getNormalVec() const;
	double A, B, C, d;
};