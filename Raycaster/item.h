#pragma once
#include "material.h"
#include "model.h"
#include "point3d.h"
#include "vector3d.h"
#include "HardwareInterface.h"

class item {
public:
	item(model* mod, material tex):tex(tex),mod(mod){};
	~item();
	point3d getInwardLineIntersection(line3d v) const;
	point3d getOutwardLineIntersection(line3d v) const;
	bool isInside(point3d) const;
	vector3d getNormalVectorAtPoint(point3d v) const;
	double getRefractiveIndex() const;
	HI::HIColor getColor() const;
private:
	material tex;
	model* mod;
};
