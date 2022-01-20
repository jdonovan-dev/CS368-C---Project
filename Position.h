#include <math.h>
#include <iostream>

class Position {
private:
	float x;
	float y;
public:
	Position(float init_x, float init_y);
	Position() {x = 0; y = 0;};
	float operator-(const Position other);
	Position operator+(Position that);
	Position operator/(float denominator);
	float GetX() const {return x;};
	float GetY() const {return y;};
	void Read(std::istream& s);
	float getX() {return x;};
	float getY() {return y;};
};
