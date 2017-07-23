#include "sphere.h"
#include <cmath>


sphere::sphere() {
	radius = 0;
	pos = point3d(0, 0, 0);
}

vector3d sphere::getNormalVectorAtPoint(point3d v) {
	vector3d r(pos, v);
	r.setLength(1);
	return r;
}

point3d sphere::getInwardLineIntersection(line3d v) {//(x − h)2 + (y − k)2 + (z − l)2 = r2, h,k,l és el centre, r és el radi
	double a = pow(v.getTip().getX() - v.getOrigin().getX(), 2) + pow(v.getTip().getY() - v.getOrigin().getY(), 2) + pow(v.getTip().getZ() - v.getOrigin().getZ(), 2);
	double b = 2 * (//3 és punt de la esfera, 2és punta de la linia, 1 és origen de la linia
		((v.getTip().getX() - v.getOrigin().getX())*(v.getOrigin().getX() - pos.getX())) +
		((v.getTip().getY() - v.getOrigin().getY())*(v.getOrigin().getY() - pos.getY())) +
		((v.getTip().getZ() - v.getOrigin().getZ())*(v.getOrigin().getZ() - pos.getZ())));
	double c = pow(pos.getX(), 2) + pow(pos.getY(), 2) + pow(pos.getZ(), 2) + pow(v.getOrigin().getX(), 2) + pow(v.getOrigin().getY(), 2) + pow(v.getOrigin().getZ(), 2) -
		2 * (pos.getX()*v.getOrigin().getX() + pos.getY()*v.getOrigin().getY() + pos.getZ()*v.getOrigin().getZ()) - pow(radius, 2);
	double t1 = (-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
	double t2 = (-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
	vector3d t3 = v.getVector();
	t3.setLength(t3.getLength()*(abs(t1) < abs(t2) ? t1 : t2));
	vector3d t4 = t3.getTip() + v.getOrigin();
	point3d t5 = t4.getTip();
	return t5;
}

point3d sphere::getOutwardLineIntersection(line3d v) {
	double a = pow(v.getTip().getX() - v.getOrigin().getX(), 2) + pow(v.getTip().getY() - v.getOrigin().getY(), 2) + pow(v.getTip().getZ() - v.getOrigin().getZ(), 2);
	double b = 2 * (//3 és punt de la esfera, 2és punta de la linia, 1 és origen de la linia
		((v.getTip().getX() - v.getOrigin().getX())*(v.getOrigin().getX() - pos.getX())) +
		((v.getTip().getY() - v.getOrigin().getY())*(v.getOrigin().getY() - pos.getY())) +
		((v.getTip().getZ() - v.getOrigin().getZ())*(v.getOrigin().getZ() - pos.getZ())));
	double c = pow(pos.getX(), 2) + pow(pos.getY(), 2) + pow(pos.getZ(), 2) + pow(v.getOrigin().getX(), 2) + pow(v.getOrigin().getY(), 2) + pow(v.getOrigin().getZ(), 2) -
		2 * (pos.getX()*v.getOrigin().getX() + pos.getY()*v.getOrigin().getY() + pos.getZ()*v.getOrigin().getZ()) - pow(radius, 2);
	double t1 = (-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
	double t2 = (-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
	vector3d t3 = v.getVector();
	t3.setLength(t3.getLength()*(abs(t1) < abs(t2) ? t2 : t1));
	vector3d t4 = t3.getTip() + v.getOrigin();
	point3d t5 = t4.getTip();
	return t5;
}

bool sphere::isInside(point3d p) {
	vector3d dist(pos, p);
	return radius >= dist.getLength();
}

sphere::~sphere() {}