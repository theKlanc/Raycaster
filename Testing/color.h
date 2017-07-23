#pragma once
class color {
public:
	color(int r, int g, int b) : r(r), g(g), b(b) {};
	~color();
	int getRComponent() const;
	int getGComponent() const;
	int getBComponent() const;
private:
	int r, g, b;
};