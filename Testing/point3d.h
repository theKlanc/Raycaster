#pragma once
class point3d {
public:
	point3d(double x, double y, double z):x(x),y(y),z(z){};
	point3d();
	~point3d();
	double getX() const;
	double getY() const;
	double getZ() const;
	point3d operator+(point3d element) const;
	point3d operator-(point3d element) const;
	point3d operator*(point3d element) const;
	point3d operator/(point3d element) const;
private:
	double x, y, z;
};

