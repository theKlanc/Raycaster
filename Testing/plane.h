#pragma once
#include "model.h"
#include "vector3d.h"

class plane :
	public model {
public:
	plane();
	plane(vector3d vec);
	~plane();
	vector3d getNormalVectorAtPoint(point3d v) override;
	point3d getPointInSurfaceInward(vector3d v) override;
	point3d getPointInSurfaceOutward(vector3d v) override;
	bool isInside(point3d p) override;
private:
	vector3d v;
	double d;
};

