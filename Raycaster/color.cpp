#include "color.h"

color::~color() {}

int color::getRComponent() const {
	return r;
}

int color::getGComponent() const {
	return g;
}

int color::getBComponent() const {
	return b;
}
