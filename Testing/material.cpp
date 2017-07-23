#include "material.h"

material::~material() {}

color material::getColor() {
	return m_color;
}