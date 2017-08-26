#include "renderer.h"

renderer::renderer(line3d camera, int hFOV, std::vector<item> elements, int vRes, int hRes) : camera(camera), vRes(vRes),hRes(hRes), hFOV(hFOV/360.0f*2.0f*PI), vFOV(atan(vRes/2/ (1.0f / tan(this->hFOV / 2)))*2), elements(elements) {}

renderer::~renderer() {}

void renderer::render() const {
	HardwareInterface::HIImage imatge = new HI::uint32[vRes*hRes];
	double l = (1.0f / tan(hFOV / 2));
	for(int j = 0;j<vRes;++j) {
		for(int i = 0;i<hRes;++i) {
			vector3d v(point3d(l, j-(vRes/2), i-(hRes/2)));//Crear vector per camera amb direccio(1,0,0)
			//FALTA ROTAR CAMERA
			line3d line(camera.getOrigin(), v);
			imatge[i+(hRes*j)]=rayCast(line);
		}
	}
	HI::drawImage(imatge, hRes, vRes, 0, 0);
	delete[] imatge;
}

HI::HIColor renderer::rayCast(line3d ray) {
	return (HI::HIColor)RGBA8(255, 255, 255, 255);
}