#include "renderer.h"

renderer::renderer(line3d camera, int hFOV, std::vector<item> elements, int vRes, int hRes) : camera(camera), hFOV(hFOV/360*2*PI), vRes(vRes), hRes(hRes), elements(elements) {}

renderer::~renderer() {}

void renderer::render() const {
	HardwareInterface::HIImage imatge = new HI::uint32[vRes*hRes];
	for(int j = 0;j<vRes;++j) {
		for(int i = 0;i<hRes;++i) {
			/*vector3d v(point3d(
				((camera.getTip().getX()*cos(-(hFOV/2) + ((i*hFOV) / hFOV))) - (camera.getTip().getZ()*sin(hFOV / 2 + ((i*hFOV) / hFOV)))),
				1,
				((camera.getTip().getX()*sin(-(hFOV/2) + ((i*hFOV) / hFOV))) + (camera.getTip().getZ()*cos(hFOV / 2 + ((i*hFOV) / hFOV))))
			));
			rayCast(v);*/
		}
	}
	HI::drawImage(imatge, hRes, vRes, 0, 0);
	delete[] imatge;
}

HI::HIColor renderer::rayCast(vector3d ray) {
	return (HI::HIColor)RGBA8(255, 255, 255, 255);
}
