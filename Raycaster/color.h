#pragma once
class color {
public:
	color(unsigned int r, unsigned int g, unsigned int b, unsigned int a = 255) : r(r), g(g), b(b), a(a){};
	~color();
	unsigned int getRComponent() const;
	unsigned int getGComponent() const;
	unsigned int getBComponent() const;
	unsigned int getAComponent() const;
	unsigned int getInt() const;

private:
	unsigned int r, g, b,a;
};