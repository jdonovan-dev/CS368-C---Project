#include "Location.h"

const std::string bool_val[2] = { "No", "Yes" };

Location::Location() {
	name = "name";
	address = "address";
	hours = "hours";
	reservations = 0;;
}

Location::~Location() {}

Location::Location(std::string init_name, std::string init_address,
		std::string init_hours, float x, float y, int init_reservations) {
	name = init_name;
	address = init_address;
	hours = init_hours;
	reservations = init_reservations;
	pos = Position(x, y);
}

Location::Location(const Location* copy_from) {
	name = copy_from->name;
	address = copy_from->address;
	hours = copy_from->hours;
	reservations = copy_from->reservations;
	pos = Position(copy_from->pos.GetX(), copy_from->pos.GetY());
}

float Location::operator-(const Position that) {
	return pos - that;
}

bool Location::IsReservable() const {
	if (reservations == 0) {
		return false;
	} else {
		return true;
	}
}

std::string Location::to_string() const {
	return name;
}

void Location::Print() const {
	std::cout << std::left << std::setw(40) << "Location:" << name << "\n";
	std::cout << std::left << std::setw(40) << "Address:" << address << "\n";
	std::cout << std::left << std::setw(40) << "Hours:" << hours << "\n";
	std::cout << std::left << std::setw(40) << "Allows Reservations:" << bool_val[IsReservable()] << "\n";
}

std::string Location::format_helper(std::string line) {
	if (line[0] == ' ') {
		line.erase(0, 1);
	}
	return line;
}

std::string Location::format_read_data(std::string reserves) {
	std::string temp;
	for(int i = 0; i < 4; i++) {
		switch(i){
		case 0:
			name = format_helper(name);
			break;
		case 1:
			address = format_helper(address);
			break;
		case 2:
			hours = format_helper(hours);
			break;
		case 3:
			reserves = format_helper(reserves);
			break;
		}
	}
	return reserves;
}

void Location::Cancel() {}
void Location::Read(std::istream& s) {}
void Location::Write(std::ostream& s) const {}
bool Location::Reserve() {return false;}

Position Location::get_pos() {return pos;}
