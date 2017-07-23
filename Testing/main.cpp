#define light_spd 299792458 //light speed in m/s
#include <vector>
#include "HardwareInterface.h"
#include "point3d.h"
#include "renderer.h"

/*Utilitzarem un sistema RHS, amb y al eix vertical, i x i z com a amplitud i profunditat respectivament
 *
 */

using namespace std;
int main() {
	HardwareInterface::systemInit();
	point3d camera;
	vector<item> items;
	int hFOV=90;
	renderer r(camera, hFOV, items, HardwareInterface::getScreenHeight(), HardwareInterface::getScreenWidth());
	r.render();	
	HardwareInterface::systemFini();
}