#include "LocationList.h"
#include <vector>
class User {
private:
	std::string first_name;
	std::string last_name;
	std::string user_filename;
	std::string default_reservations;
	int age;
	double height;
	double weight;
	int unit;
	LocationList reservations = LocationList();


	std::vector<Position> pos_vec;
	std::string position_filename = "default_positions.txt";
public:
	User();
	User(std::string filename);
	User(std::string init_first_name, std::string init_last_name, int init_age,
			double init_height, double init_weight, int init_unit);
	void MakeReservation(Location* new_reservation);
	std::string to_string();
	void PrintData() const;
	void PrintReservations();
	void Read(bool& is_imperial, std::string fname = "");
	void Write(const bool is_imperial);
	int CheckExposures();
	Position AveragePosition();
	// void operator()(Position next);

	std::string getName(int fol);
	int getAge();
	double getHeight();
	double getWeight();
	int getUnit();
	std::string getUserFilename();
	LocationList getReservations();
	void changeName(int fol);
	void changeAge();
	void changeUnits();
	void changeHeight();
	void changeWeight();
};
