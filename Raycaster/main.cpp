#define light_spd 299792458 //light speed in m/s
#include "HardwareInterface.h"
#include "point3d.h"
#include "plane.h"
#include <iostream>
#include "sphere.h"
#include "item.h"
#include <vector>
#include "renderer.h"

/*Utilitzarem un sistema RHS, amb y al eix vertical, i x i z com a amplitud i profunditat respectivament
 *
 */

using namespace std;
int main() {
	HardwareInterface::systemInit();
	line3d camera(point3d(1.5,1.5,1.5),vector3d(point3d(1,0,0)));
	vector<item> items;
	sphere s= sphere(0.5, point3d(2.5, 0.5, 2.5));
	item itemp();
	//items.push_back(s);
	int hFOV=90;
	renderer r(camera, hFOV, items, HardwareInterface::getScreenHeight(), HardwareInterface::getScreenWidth());
	r.render();	
	HardwareInterface::systemFini();
}

//int main()//testing
//{
//	//POINT3D OK
//	//VECTOR3D
//	bool v1 = 12 - vector3d(point3d(1, 2, 3)).dot(vector3d(point3d(4, -5, 6))) < 0.0001; //
//	bool v2 = (vector3d(point3d(3, -3, 1))*vector3d(point3d(4, 9, 2)) - vector3d(point3d(-15, -2, 39))) < 0.0001;
//	bool v3 = vector3d(point3d(1, 5, 3)).dot(vector3d(point3d(2, 3, 6))) - 35 < 0.0001;
//	bool v = v1&&v2&&v3;
//	//PLANE
//	plane pla(vector3d(point3d(1, 1, 1)), point3d(1, 1, 1));
//	line3d test(point3d(0, 0, 0), vector3d(point3d(1, 2, 5)));
//	point3d punt = pla.getInwardLineIntersection(test);
//	bool dins = pla.isInside(point3d(0.5, 0.5, 0.5));
//	bool fora = !pla.isInside(point3d(2, 2, 2));
//	bool p = dins&&fora;
//	//SPHERE
//	sphere s(2, point3d(3, 3, 3));
//	point3d interseccio = s.getInwardLineIntersection(line3d(point3d(0, 0, 0), point3d(1, 1, 1)));
//	point3d interseccio2 = s.getOutwardLineIntersection(line3d(point3d(0, 0, 0), point3d(1, 1, 1)));
//	bool end =v&&p;
//}