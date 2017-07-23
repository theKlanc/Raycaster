#include "plane.h"

plane::plane()
{
	v = vector3d();
	d = 0;
}

plane::plane(vector3d vec) {
	v = vec;
	d = (((vec.getTip() - vec.getOrigin()).getX()*vec.getOrigin().getX()) +
		((vec.getTip() - vec.getOrigin()).getY()*vec.getOrigin().getY()) +
		((vec.getTip() - vec.getOrigin()).getZ()*vec.getOrigin().getZ()));
}

/*equacio del pla = ax+by+cz=d on [a,b,c] es el vector normal del pla i trobem d substituint xyz per un punt del pla
 *
 *equacio del vector = (x-x1)/l=(y-y1)/m=(z-z1)/n [l,m,n] es el vector direccio i x1y1z1 es un punt de la recta
*/
plane::~plane() {}

vector3d plane::getNormalVectorAtPoint(point3d p) {
	return vector3d(p, v.getTip() - v.getOrigin() + p);
}

point3d plane::getPointInSurfaceInward(vector3d v) {//n0 es l origen del vector i n1 es la punta
//x=x0 + t(x1-x0);
//y=y0 + t(y1-y0);
//z=z0 + t(z1-z0);
//(a*(x0 + t(x1-x0)))+(b*(y0 + t(y1-y0)))+(c*(z0 + t(z1-z0)))=d
//double t=(d-(a*x0+b*y0+c*z0))/((a*(x1-x0))+(b*(y1-y0))+(c*(z1-z0)))
	double t = (d - (v.getOrigin().getX() + v.getOrigin().getY() + v.getOrigin().getZ())) / (((v.getTip().getX() - v.getOrigin().getX())) + ((v.getTip().getY() - v.getOrigin().getY())) + ((v.getTip().getZ() - v.getOrigin().getZ())));
	return point3d(v.getOrigin().getX() + (t*(v.getTip().getX() - v.getOrigin().getX())), v.getOrigin().getY() + (t*(v.getTip().getY() - v.getOrigin().getY())), v.getOrigin().getZ() + (t*(v.getTip().getZ() - v.getOrigin().getZ())));
}

point3d plane::getPointInSurfaceOutward(vector3d v) {
	return getPointInSurfaceOutward(v);
}

bool plane::isInside(point3d p)
{
	return (((p.getX()*v.getOrigin().getX()) +(p.getY()*v.getOrigin().getY())+ (p.getZ()*v.getOrigin().getZ()) + d) > 0);
}
