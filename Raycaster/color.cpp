#include "color.h"
#include "HardwareInterface.h"

color::~color() {}

unsigned int color::getRComponent() const {
	return r;
}

unsigned int color::getGComponent() const {
	return g;
}

unsigned int color::getBComponent() const {
	return b;
}

unsigned int color::getAComponent() const {
	return a;
}

unsigned int color::getInt() const { return RGBA8(r, g, b, a); }
