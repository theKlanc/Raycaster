#pragma once
#include "point3d.h"
#include "vector3d.h"

class model {
public:
	model();
	virtual ~model()=0;
	virtual bool isInside(point3d p)=0;
	virtual vector3d getNormalVectorAtPoint(point3d v)=0;
	virtual point3d getPointInSurfaceInward(vector3d v)=0;
	virtual point3d getPointInSurfaceOutward(vector3d v)=0;
};

