#include "renderer.h"

renderer::renderer(point3d camera, int hFOV, std::vector<item> elements, int vRes, int hRes): camera(camera), hFOV(hFOV), elements(elements), vRes(vRes), hRes(hRes)
{
}

renderer::~renderer() {}

void renderer::render()
{
}
