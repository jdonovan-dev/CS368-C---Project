#include "menus.h"

std::string symptoms[] = { "Fever", "Cough", "Shortness of breath",
		"Loss of taste or smell", "Fatigue", "Sore Throat" };
int selected_symptoms_size = 6;
bool selected_symptoms[6];
int location_data_count = 4;
User user = User("userdata.txt");
LocationList list = LocationList();
std::string units[] = { "imperial", "metric" };

int checkForEnter() {
	char enter;
	while (1) {
		std::cin.ignore();
		std::cin.get(enter);
		if (enter != '\n') {
			std::cin.clear();
			std::cout << "\n----------------------------------------\n";
			std::cout << "\nPlease hit enter to return to the main menu.";
			continue;
		}
		return 1;
	}
}

int checkInput(int upper, int lower) {
	while (1) {
		int input;
		std::cin >> input;
		if (!std::cin || input < upper || input > lower) {
			std::cin.clear();
			std::cin.ignore(10, '\n');
			std::cout << "\n----------------------------------------\n";
			std::cout << "\nPlease enter a valid number:";
			continue;
		} else {
			return input;
		}
	}
}

void runViewTestingLocations() {
	while (1) {
		Position pos = user.AveragePosition();
		list.Sort(pos);
		printTestingLocations(list);
		std::cout << "Press enter to return to the main menu.\n";
		if (checkForEnter() == 1) {
			return;
		} else {
			continue;
		}
	}
}

void runMakeTestReservation() {
	std::cout << "\nMake a reservation\n";
	int i = 1;
	for (int j = 0; j < list.GetCount(); j++) {
		if (list.GetLocation(j)->IsReservable() == true) {
			std::cout << "[" << i << "] " << list.GetLocation(j)->to_string() << "\n";
			i++;
		}
	}
	std::cout << "Please enter a menu item:";
	int input = checkInput(1, i - 1);
	list.GetLocation(input)->Reserve();
	user.MakeReservation(list.GetLocation(input));
}

void checkSymptoms(bool selected_symptoms[]) {
	int counter = 0;
	for (int i = 0; i < selected_symptoms_size; i++) {
		if (selected_symptoms[i] == true) {
			counter++;
		}
	}
	if (counter >= 3) {
		std::cout << "\n----------------------------------------\n";
		std::cout
				<< "\nPlease go to an available testing site to be tested for Covid-19.\n";
		std::cout << "Press enter to return to main menu.";
	} else if (counter < 3 && counter > 0) {
		std::cout << "\n----------------------------------------\n";
		std::cout
				<< "\nPlease stay home and monitor your symptoms. If your symptoms persist or you develop new symptoms, please go to an available testing site to be tested for Covid-19.\n";
		std::cout << "Press enter to return to main menu.";
	} else {
		std::cout << "\n----------------------------------------\n";
		std::cout
				<< "\nYou seem to be feeling fine. Remember to test regularly for Covid-19\n";
		std::cout << "Press enter to return to main menu.";
	}
	checkForEnter();
}

void runUseSymptomChecker() {
	int input;
	while (1) {
		printSymptomsMenu(symptoms, selected_symptoms_size, selected_symptoms);
		input = checkInput(1, selected_symptoms_size + 2);
		if (input == (selected_symptoms_size + 2)) {
			return;
		} else if (input == (selected_symptoms_size + 1)) {
			checkSymptoms(selected_symptoms);
			std::fill_n(selected_symptoms, selected_symptoms_size, false);
			return;
		} else {
			if (selected_symptoms[input - 1] == true) {
				selected_symptoms[input - 1] = false;
			} else {
				selected_symptoms[input - 1] = true;
			}
			continue;
		}
	}
}

void runViewMyReservations() {
	while (1) {
		user.PrintReservations();
		std::cout << "Please press enter to return to the main menu.\n";
		if (checkForEnter() == 1) {
			return;
		} else {
			continue;
		}
	}
}

void runViewPersonalData() {
	while (1) {
		printUserDataMenu(user);
		if (checkForEnter() == 1) {
			return;
		} else {
			continue;
		}
	}
}

void runAdjustPersonalData() {
	int input;
	std::string unitH[] = { "ft", "m" };
	std::string unitW[] = { "lbs", "kg" };
	while (1) {
		printAdjustUserDataMenu(user);
		switch (checkInput(1, 6)) {
		case 1:
			user.changeName(0);
			break;
		case 2:
			user.changeName(1);
			break;
		case 3:
			user.changeAge();
			break;
		case 4:
			user.changeHeight();
			break;
		case 5:
			user.changeWeight();
			break;
		case 6:
			return;
		default:
			break;
		}
	}
}

void runChangeSettings() {
	int input;
	bool is_i = false;
	while (1) {
		printSettingsMenu(user.getUnit());
		switch (checkInput(1, 4)) {
		case 1:
			user.changeUnits();
			break;
		case 2:
			user.Read(is_i, "userdata.txt");
			break;
		case 3:
			user.Write(false);
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}

void runCheckExposures() {
	if (user.CheckExposures() == 0) {
		std::cout << "\n----------------------------------------\n";
		std::cout << "\nNo Covid-19 exposures detected!\n";
	} else {
		std::cout << "\n----------------------------------------\n";
		std::cout << "\nFound " << user.CheckExposures() << " possible Covid-19 exposures, please arrange to be tested for Covid-19.\n";
	}
}

void runMainMenu() {
	while (1) {
		printMainMenu();
		switch (checkInput(1, 9)) {
		case 1:
			runViewTestingLocations();
			break;
		case 2:
			runMakeTestReservation();
			break;
		case 3:
			runUseSymptomChecker();
			break;
		case 4:
			runCheckExposures();
			break;
		case 5:
			runViewMyReservations();
			break;
		case 6:
			runViewPersonalData();
			break;
		case 7:
			runAdjustPersonalData();
			break;
		case 8:
			runChangeSettings();
			break;
		case 9:
			return;
		default:
			break;
		}
	}
}

void loadData() {
	bool is_imperial = false;
	list.FromFile("data.txt");
}


// g++ menus.cpp menus.h User.cpp User.h Location.cpp Location.h LocationList.cpp LocationList.h main.cpp Position.cpp Position.h CampusLocation.cpp CampusLocation.h CityLocation.cpp CityLocation.h
int main() {
	loadData();
	runMainMenu();
	return 0;
}

