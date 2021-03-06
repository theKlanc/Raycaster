#pragma once
#include "color.h"

class material {
public:
	material(double refractiveIndex, color c):m_refractiveIndex(refractiveIndex),m_color(c){};
	~material();
	color getColor() const;
	double getRefractiveIndex() const;
private:
	double m_refractiveIndex;
	color m_color;
};

