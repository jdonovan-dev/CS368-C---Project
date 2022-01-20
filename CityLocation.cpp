#include "CityLocation.h"

CityLocation::CityLocation() {
	name = "name";
	address = "address";
	hours = "hours";
	reservations = 0;
}

CityLocation::CityLocation(std::string init_name, std::string init_address, std::string init_hours, int init_reservations) {
	name = init_name;
	address = init_address;
	hours = init_hours;
	reservations = init_reservations;
}

bool CityLocation::Reserve() {
	if (reservations > 0) {
		reservations--;
		return true;
	}
	return false;
}

void CityLocation::Cancel() {
	reservations++;
}
void CityLocation::Print() const {
	std::cout << std::left << "Off-Campus\n";
	std::cout << std::left << std::setw(40) << "Location: " << name << "\n";
	std::cout << std::left << std::setw(40) << "Address:" << address << "\n";
	std::cout << std::left << std::setw(40) << "Hours:" << hours << "\n";
	std::cout << std::left << std::setw(40) << "Reservations: " << reservations << "\n";
}

void CityLocation::Read(std::istream& s) {
	std::getline(s, name, ',');
	if (name.find("citylocation") != std::string::npos) {
			name = name.substr(14, name.length());
		}
	std::getline(s, address, ',');
	std::getline(s, hours, ',');

	std::string reserve_string = "";
	std::getline(s, reserve_string, ',');
	reserve_string = format_read_data(reserve_string);
	reservations = std::stoi(reserve_string);

	std::string temp = "";
	std::getline(s, temp, ',');
	float x = std::stof(temp);

	std::getline(s, temp, '\n');
	float y = std::stof(temp);

	pos = Position(x, y);
}

void CityLocation::Write(std::ostream& s) const {
	s << "citylocation\n" << name << ", " << address << ", " << hours << ", " << pos.GetX() << ", " << pos.GetY() << ", " << reservations << ",\n";
}
