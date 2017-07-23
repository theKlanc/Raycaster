#pragma once
#include "point3d.h"
#include "item.h"
#include <vector>

class renderer {
public:
	renderer(point3d camera, int hFOV, std::vector<item> elements, int vRes, int hRes);;
	~renderer();
	void render();
private:
	point3d camera;
	int hFOV, vRes,hRes;
	std::vector<item> elements;

};

