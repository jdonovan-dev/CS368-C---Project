#include "LocationList.h"

LocationList::LocationList() {
	num_of_locations = 0;
	list_size = 4;
	// location_list = new Location*[list_size];
}

LocationList::~LocationList() {
	for (auto elem : location_list) {
		delete elem;
	}
	/*
	for (int i = 0; i < num_of_locations; i++) {
		delete GetLocation(i);
	}
	// delete [] location_list; */
}

int LocationList::GetCount() const {
	return num_of_locations;
}

Location* LocationList::GetLocation(int index) const {
	return location_list[index];
}

void LocationList::AddLocation(Location* new_loc) {
	int index;
	if (list_size == 0) {
		index = 0;
	} else {
		index = num_of_locations;
	}
	location_list.push_back(new_loc);
	num_of_locations++;
}

void LocationList::FromFile(std::string fname) {
	std::fstream file(fname);
	int size;
	file >> size;
	std::string line = "";
	for (int i = 0; i < size; i++) {
		getline(file, line, '\n');
		if (line.find("citylocation") != std::string::npos) {
			CityLocation* cityloc = new CityLocation();
			cityloc->Read(file);
			AddLocation(cityloc);
		} else {
			CampusLocation* campusloc = new CampusLocation();
			campusloc->Read(file);
			AddLocation(campusloc);
		}
	}
	file.close();
}

void LocationList::ToFile(std::string fname) {
	std::ofstream file;
	file.open(fname);
	file << num_of_locations << "\n";
	for(int i = 0; i < num_of_locations; i++) {
		location_list[i]->Write(file);
	}
	file.close();
}

LocationList::Closer::Closer(Position p) {
	 pos = Position(p.GetX(), p.GetY());
}

bool LocationList::Closer::operator()(Location* a, Location* b) {
	if ((a->get_pos() - pos) < (b->get_pos() - pos)) {
		return true;
	}
	return false;
}

void LocationList::Sort(Position p) {
	Closer closer = Closer(p);
	std::sort(location_list.begin(), location_list.end(), closer);
}

