#include "User.h"
#define heightConversion(units, height) (units == 0 ? height / 3.28 : height * 3.28); // conversion for height between ft and m
#define weightConversion(units, weight) (units == 0 ? weight / 2.20 : weight * 2.20); // conversion for weight between lbs and kg
#include <bits/stdc++.h>
int num_reservations = 0;
const std::string units[] = { "imperial", "metric" };

User::User(std::string filename) {
	bool is_imperial;
	Read(is_imperial, filename);
	user_filename = last_name + ".txt";
	default_reservations = last_name + "_reservations.txt";
	position_filename = last_name + "_reservations.txt";
}

User::User() {
	first_name = "first";
	last_name = "last";
	age = 0;
	height = 0.0;
	weight = 0.0;
	unit = 0;
}

User::User(std::string init_first_name, std::string init_last_name,
		int init_age, double init_height, double init_weight, int init_unit) {
	first_name = init_first_name;
	last_name = init_last_name;
	age = init_age;
	height = init_height;
	weight = init_weight;
	unit = init_unit;
	user_filename = last_name + ".txt";
	default_reservations = last_name + "_reservations.txt";
	position_filename = last_name + "_reservations.txt";
}

void User::MakeReservation(Location* snew_reservation) {
	num_reservations++;
	reservations.AddLocation(snew_reservation);
}

std::string User::to_string() {
	return first_name + " " + last_name;
}

void User::PrintData() const {
	std::string unitH[] = { "ft", "m" };
	std::string unitW[] = { "lbs", "kg" };
	std::cout << "Name:\t" << first_name << " " << last_name << "\n";
	std::cout << "Age:\t" << age << "\n";
	std::cout << "Height:\t" << height << " " << unitH[unit] << "\n";
	std::cout << "Weight:\t" << weight << " " << unitW[unit] << "\n";
}

void User::PrintReservations() {
	if (num_reservations == 0) {
		std::cout << "\n----------------------------------------\n";
		std::cout << "\nNo current reservations.\n";
		return;
	}
	std::cout << "\n----------------------------------------\n\n";
	for (int i = 0; i < reservations.GetCount(); i++) {
		std::cout << "[" << (i + 1) << "] "
				<< reservations.GetLocation(i)->to_string() << "\n";
		}
}

void User::Read(bool& is_imperial, std::string fname) {
	std::fstream file;
	if (fname == "") {
		 file.open(user_filename);
	} else {
		file.open(fname);
	}


	file >> first_name;
	file >> last_name;
	std::string temp = "";
	file >> temp;
	age = std::stoi(temp);
	file >> temp;
	height = std::stod(temp);
	file >> temp;
	weight = std::stod(temp);
	file >> temp;
	unit = std::stoi(temp);
	file.close();

	std::fstream pos_file;
	pos_file.open(position_filename);
	for (int i = 0; i < 24; i++) {
		Position this_pos = Position(0,0);
		this_pos.Read(pos_file);
		pos_vec.push_back(this_pos);
	}
	pos_file.close();
}

void User::Write(const bool is_imperial) {
	std::ofstream file;
	file.open(default_reservations);
	file << first_name << " " << last_name << " " << age << " " << std::setprecision(1) << std::fixed <<  height << " " << std::setprecision(1) << std::fixed <<  weight << unit << "\n";
	reservations.ToFile(default_reservations);
	file.close();
}

int User::CheckExposures() {
	AveragePosition();
	std::string hold = "";
	std::vector<Position> temp;
	std::fstream database_file;
	database_file.open("databases.txt");
	for (int i = 0; i < 24; i++) {
		Position this_pos = Position(0,0);
		this_pos.Read(database_file);
		temp.push_back(this_pos);
		database_file >> hold;
	}

	int expos = 0;
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 24; j++) {
			float dist = pos_vec.at(i) - temp.at(j);
			if (dist < 6) {
				expos++;
			}
		}
	}
	return expos;
}


auto sum = [](Position total, const Position& pos) {
	return Position(total.GetX() + pos.GetX(), total.GetY() + pos.GetY());
};

Position User::AveragePosition() {
	Position total = Position(0, 0);
	total = std::accumulate(pos_vec.begin(), pos_vec.end(), total, sum);
	return total / 24;
}

std::string User::getName(int fol) {
	if (fol == 0) {
		return first_name;
	} else {
		return last_name;
	}
}

int User::getAge() {
	return age;
}

double User::getHeight() {
	return height;
}

double User::getWeight() {
	return weight;
}

int User::getUnit() {
	return unit;
}

std::string User::getUserFilename() {
	return user_filename;
}

LocationList User::getReservations() {
	return reservations;
}

void User::changeName(int fol) {
	std::string new_name;
	const std::string firstOrLast[] = { "first", "last" };
	std::cout << "\n----------------------------------------\n";
	if (fol == 0) {
		std::cout << "\nPlease enter your first name:";
	} else {
		std::cout << "\nPlease enter your last name:";
	}
	std::cin >> new_name;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	if (fol == 0) {
		first_name = new_name;
	} else {
		last_name = new_name;
		user_filename = last_name + ".txt";
			default_reservations = last_name + "_reservations.txt";
			position_filename = last_name + "_reservations.txt";
	}
}

void User::changeAge() {
	int new_age;
	std::string input;
	while (1) {
		std::cout << "\n----------------------------------------\n";
		std::cout << "\nPlease enter your age: ";
		std::cin >> new_age;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		if (!std::cin.fail() || new_age > 122) {
			age = new_age;
			return;
		} else {
			continue;
		}
	}
}

void User::changeUnits() {
	int otherUnit;
	double conversion;
	std::cout << "\n----------------------------------------\n";
	if (unit == 0) {
		otherUnit = 1;
	} else {
		otherUnit = 0;
	}
	while (1) {
		if (unit == 0) {
			conversion = heightConversion(unit, height)
			;
			height = conversion;
			conversion = weightConversion(unit, weight)
			;
			unit = 1;
		} else {
			conversion = heightConversion(unit, height)
			;
			height = conversion;
			conversion = weightConversion(unit, weight)
			;
			weight = conversion;
			unit = 0;
		}
		std::cout << "\nNew units: " << units[unit] << "\n";
		return;
	}
}

void User::changeHeight() {
	double new_height;
	const std::string currHUnit[] = { "ft", "m" };

	while (1) {
		std::cout << "\n----------------------------------------\n";
		std::cout << "\nPlease enter your height in ft or m (form #.#): ";
		std::cin >> new_height;
		if (unit == 0 && (std::cin.fail() || (new_height > 9.0))) {
			std::cout << "\n----------------------------------------\n";
			std::cout
					<< "\nEntered height is invalid.\nPlease enter a height in the form #.# that is under 9.0 ft\n";
			continue;
		} else if (std::cin.fail() || (new_height > 2.75)) {
			std::cout << "\n----------------------------------------\n";
			std::cout
					<< "\nEntered height is invalid.\nPlease enter a height in the form #.# that is under 2.75 m\n";
			continue;
		}
		if (!std::cin.fail()) {
			height = new_height;
			return;
		} else {
			continue;
		}
	}
}

void User::changeWeight() {
	double new_weight;
	char ans;
	const std::string currWUnit[] = { "lbs", "kg" };
	while (1) {
		std::cout << "\n----------------------------------------\n";
		std::cout << "\nPlease enter your weight in lbs or kg (form #.#): ";
		std::cin >> new_weight;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		if (unit == 0 && (std::cin.fail() || new_weight > 975)) {
			std::cout << "\n----------------------------------------\n";
			std::cout
					<< "\nEntered weight is invalid.\nPlease enter a weight in the form #.# that is under 975 lbs";
			continue;
		} else if (std::cin.fail() || new_weight > 445) {
			std::cout << "\n----------------------------------------\n";
			std::cout
					<< "\nEntered weight is invalid.\nPlease enter a weight in the form #.# that is under 445 kg.\n";
			continue;
		}
		if (!std::cin.fail()) {
			weight = new_weight;
			return;
		} else {
			continue;
		}
	}
}
