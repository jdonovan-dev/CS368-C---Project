#include "Position.h"

Position::Position(float init_x, float init_y) {
	x = init_x;
	y = init_y;
}

float Position::operator-(const Position other) {
	float xs = pow((x - other.x), 2);
	float ys = pow((y - other.y), 2);
	return sqrt(xs + ys);
}

Position Position::operator+(Position that) {
	return Position(x + that.x, y + that.y);
}

Position Position::operator/(float denominator) {
	return Position(x/denominator, y/denominator);
}

void Position::Read(std::istream& s) {
	std::string x_s = "";
	std::string y_s = "";
	std::getline(s, x_s, ' ');
	std::getline(s, y_s, '\n');

	x = std::stof(x_s);
	y = std::stof(y_s);
}
