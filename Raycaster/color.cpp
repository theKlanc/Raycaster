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
color color::operator*(color c) const { return color(r / 255 * c.r, g / 255 * c.g, b / 255 * c.b); }
color color::operator+(color c) const { return color(r + c.r > 255 ? 255 : r + c.r, g + c.g > 255 ? 255 : g + c.g, b + c.b > 255 ? 255 : b + c.b); }
color color::operator-(color c) const { return color(r - c.r < 0 ? 0 : r - c.r, g - c.g < 0 ? 0 : g - c.g, b - c.b < 0 ? 0 : b - c.b); }