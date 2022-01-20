#include "menus.h"

void printMainMenu() {
	std::cout << "\n----------------------------------------\n";
	std::cout << "\nWelcome (back) to Safe-ish Badgers!\n";
	std::cout << "[1] View testing locations\n";
	std::cout << "[2] Make test reservation\n";
	std::cout << "[3] Use symptom checker\n";
	std::cout << "[4] Check for Covid-19 Exposures\n";
	std::cout << "[5] View my reservations\n";
	std::cout << "[6] View my personal data\n";
	std::cout << "[7] Adjust my personal data\n";
	std::cout << "[8] Change settings\n";
	std::cout << "[9] Exit program\n";
	std::cout << "Please enter a menu item:";
}

void printTestingLocations(const LocationList &locations) {
	std::cout << "\n----------------------------------------\n";
	std::cout << "\nTesting locations:\n";
	for (int i = 0; i < locations.GetCount(); i++) {
		std::cout << "[" << (i + 1) << "] ";
		locations.GetLocation(i)->Print();
		std::cout << "\n";
	}
}

void printSymptomsMenu(std::string symptoms[], int symptoms_size,
		bool selected_symptoms[]) {
	std::cout << "\n----------------------------------------\n";
	std::cout << "\nSymptoms checker:\n";
	int i;
	for (i = 0; i < symptoms_size; i++) {
		if (selected_symptoms[i] == true) {
			std::cout << "[" << (i + 1) << "*] " << symptoms[i] << "\n";
		} else {
			std::cout << "[" << (i + 1) << "] " << symptoms[i] << "\n";
		}
	}
	std::cout << "[" << (i + 1) << "] Submit symptoms\n";
	std::cout << "[" << (i + 2) << "] Cancel and return to main menu\n";
}

void printUserDataMenu(const User &user) {
	std::cout << "\n----------------------------------------\n";
	std::cout << "\nYour personal data:\n";
	user.PrintData();
	std::cout << "Press enter to return to the main menu.";
}

void printAdjustUserDataMenu(User &user) {
	std::string unitH[] = { "ft", "m" };
	std::string unitW[] = { "lbs", "kg" };
	std::cout << "\n----------------------------------------\n";
	std::cout << "\nSet your personal data:\n";
	std::cout << "[1] First name (" << user.getName(0) << ")\n";
	std::cout << "[2] Last name (" << user.getName(1) << ")\n";
	std::cout << "[3] Age (" << user.getAge() << ")\n";
	std::cout << "[4] Height (" << user.getHeight() << unitH[user.getUnit()]
			<< ")\n";
	std::cout << "[5] Weight (" << user.getWeight() << unitW[user.getUnit()]
			<< ")\n";
	std::cout << "[6] Return to main menu\n";
	std::cout << "Please enter a menu item:";
}

void printSettingsMenu(const bool is_metric) {
	std::string units[] = { "imperial", "metric" };
	std::cout << "\n----------------------------------------\n";
	std::cout << "\nSettings:\n";
	std::cout << "[1] Switch units (" << units[is_metric] << ")\n";
	std::cout << "[2] Load Data\n";
	std::cout << "[3] Save Data\n";
	std::cout << "[4] Return to main menu\n";
	std::cout << "Please enter a menu item:";
}

void printReservationLocations(const LocationList &locations) {
	std::cout << "\n----------------------------------------\n";
	std::cout << "\nHere are the locations accepting reservations:\n";
	for (int i = 0; i < locations.GetCount(); i++) {
		if (locations.GetLocation(i)->IsReservable()) {
			std::cout << "[" << (i + 1) << "] "
					<< locations.GetLocation(i)->to_string() << "\n";
		}
	}
}
