#include "Position.h"

int main() {
	Position pos1 = Position(2, 4);
	Position pos2 = Position(7, 3);

	std::cout << pos1.getX() << "\n";
	std::cout << pos2.getY() << "\n";

	float f = pos1 - pos2;

	std:: cout << f << "\n";

	return 0;
}

/*

   g++ main.cpp menus.cpp menus.h Location.h Location.cpp CityLocation.h CityLocation.cpp CampusLocation.h CampusLocation.cpp LocationList.h LocationList.cpp User.h User.cpp

 */
