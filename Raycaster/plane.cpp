#include "plane.h"
//Usem forma cartesiana on Ax+By+Cz=d, sent [x,y,z] un punt del pla, si volem D haurem d fer -1*d=D
plane::plane()
{
	A = B = C = d = 0;
}

plane::plane(vector3d vec, point3d p)
{
	A = vec.getTip().getX();
	B = vec.getTip().getY();
	C = vec.getTip().getZ();
	d = vector3d(p).dot(vec);
}

/*equacio del pla = ax+by+cz=p_d on [a,b,c] es el vector normal del pla i trobem p_d substituint xyz per un punt del pla
 *
 *equacio del vector = (x-x1)/l=(y-y1)/m=(z-z1)/n [l,m,n] es el vector direccio i x1y1z1 es un punt de la recta
*/
plane::~plane() {}

vector3d plane::getNormalVectorAtPoint(point3d p) {
	return getNormalVec();
}

point3d plane::getLineIntersection(line3d v) {
	double  t = (((A*v.getOrigin().getX())+(B*v.getOrigin().getY())+(C*v.getOrigin().getZ())+d)) / ((A*(v.getTip()-v.getOrigin()).getX())+ (B*(v.getTip() - v.getOrigin()).getY()) + (C*(v.getTip() - v.getOrigin()).getZ()));
	vector3d t2 = v.getVector();
	t2.setLength(t2.getLength()*t);
	vector3d t3 = t2.getTip() + v.getOrigin();
	point3d t4 = t3.getTip();
	return t4;
}

bool plane::isInside(point3d p)
{
	return ((A*p.getX() + B*p.getY() + C*p.getZ() - d) < 0);
}

vector3d plane::getNormalVec() const
{
	return vector3d(point3d(A, B, C));
}
