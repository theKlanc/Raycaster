#pragma once
#include "point3d.h"
#include "item.h"
#include <vector>
#include "HardwareInterface.h"

class renderer {
public:
	renderer(line3d camera, int hFOV, std::vector<item> elements, int vRes, int hRes);;
	~renderer();
	void render() const;
private:
	static HI::HIColor rayCast(vector3d ray);
	line3d camera;
	int hFOV, vRes,hRes;
	std::vector<item> elements;

};

