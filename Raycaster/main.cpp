#define light_spd 299792458 //light speed in m/s
#include <vector>
#include "HardwareInterface.h"
#include "point3d.h"
#include "renderer.h"
#include "plane.h"
#include <iostream>

/*Utilitzarem un sistema RHS, amb y al eix vertical, i x i z com a amplitud i profunditat respectivament
 *
 */

using namespace std;
//int main() {
//	HardwareInterface::systemInit();
//	point3d camera;
//	vector<item> items;
//	int hFOV=90;
//	renderer r(camera, hFOV, items, HardwareInterface::getScreenHeight(), HardwareInterface::getScreenWidth());
//	r.render();	
//	HardwareInterface::systemFini();
//}
class test2 {
public: test2() { cout << 1; }
		~test2() {cout << 2;}
};
int main()//testing
{
	//POINT3D OK
	//VECTOR3D
	bool v1 = 12 - vector3d(point3d(1, 2, 3)).dot(vector3d(point3d(4, -5, 6))) < 0.0001; //
	bool v2 = (vector3d(point3d(3, -3, 1))*vector3d(point3d(4, 9, 2)) - vector3d(point3d(-15, -2, 39))) < 0.0001;
	bool v3 = vector3d(point3d(1, 5, 3)).dot(vector3d(point3d(2, 3, 6))) - 35 < 0.0001;
	bool v = v1&&v2&&v3;
	//PLANE
	plane pla(vector3d(point3d(1, 1, 1)), point3d(1, 1, 1));
	line3d test(point3d(0, 0, 0), vector3d(point3d(1, 2, 5)));
	point3d punt = pla.getLineIntersection(test);
	bool dins = pla.isInside(point3d(0.5, 0.5, 0.5));
	bool fora = !pla.isInside(point3d(2, 2, 2));
	bool p = dins&&fora;
	bool end = true;
}