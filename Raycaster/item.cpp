#include "item.h"

item::~item() {}
point3d item::getInwardLineIntersection(line3d v) const {
	return mod->getInwardLineIntersection(v);
}
point3d item::getOutwardLineIntersection(line3d v) const {
	return mod->getOutwardLineIntersection(v);
}

bool item::isInside(point3d p) const {
	return mod->isInside(p);
}

double item::getRefractiveIndex() const {
	return tex.getRefractiveIndex();
}

HI::HIColor item::getColor() const {
	return tex.getColor().getInt();
}

vector3d item::getNormalVectorAtPoint(point3d v) const {
	return mod->getNormalVectorAtPoint(v);
}