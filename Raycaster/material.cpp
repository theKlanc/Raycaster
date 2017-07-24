#include "material.h"

material::~material() {}

color material::getColor() const {
	return m_color;
}

double material::getRefractiveIndex() const { return m_refractiveIndex; }
