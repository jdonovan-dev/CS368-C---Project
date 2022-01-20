#include "CampusLocation.h"

CampusLocation::CampusLocation() {
	name = "name";
	address = "address";
	hours = "hours";
	reservations = 0;
}

CampusLocation::CampusLocation(std::string init_name, std::string init_address, std::string hours) {
	reservations = 0;
}

void CampusLocation::Print() const {
	std::cout << std::left << "On-Campus\n";
	std::cout << std::left << std::setw(40) << "Location:" << name << "\n";
	std::cout << std::left << std::setw(40) << "Address:" << address << "\n";
	std::cout << std::left << std::setw(40) << "Hours:" << hours << "\n";
	std::cout << std::left << std::setw(40) << "Reservation: " << "None\n";
}

void CampusLocation::Read(std::istream& s) {
	std::getline(s, name, ',');
	if (name.find("campuslocation") != std::string::npos) {
		name = name.substr(16, name.length());
	}
	std::getline(s, address, ',');
	std::getline(s, hours, ',');

	std::string temp = "";
	std::getline(s, temp, ',');
	float x = std::stof(temp);

	std::getline(s, temp, '\n');
	float y = std::stof(temp);

	pos = Position(x, y);

	format_read_data("");
}

void CampusLocation::Write(std::ostream& s) const {
	s << "campuslocation\n" << name << ", " << address << ", " << hours << ", " << pos.GetX() << ", " << pos.GetY() << ",\n";
}
