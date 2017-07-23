#pragma once
#include "material.h"
#include "model.h"
#include "point3d.h"
#include "vector3d.h"

class item {
public:
	item(model* mod, material tex):tex(tex),mod(mod){};
	~item();
	point3d getPointInSurfaceInward(vector3d v);
	point3d getPointInSurfaceOutward(vector3d v);
	bool isInside(point3d);
	vector3d getNormalVectorAtPoint(point3d v);
	double getRefractiveIndex();
private:
	material tex;
	model* mod;
};
