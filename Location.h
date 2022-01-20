#ifndef LOCATION_H
#define LOCATION_H

#include "Position.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
class Location {
protected:
	std::string name;
	std::string address;
	std::string hours;
	int reservations;
	Position pos;
public:
	Location();
	Location(std::string init_name, std::string init_address, std::string init_hours, float x, float y, int init_reservations);
	Location(const Location* copy_from);
	virtual ~Location();
	float operator-(const Position that);
	bool IsReservable() const;
	std::string to_string() const;
	virtual void Print() const = 0;
	virtual void Read(std::istream& s) = 0;
	virtual void Write(std::ostream& s) const = 0;
	virtual bool Reserve() = 0;
	virtual void Cancel() = 0;
	std::string format_helper(std::string line);
	std::string format_read_data(std::string reserves);
	Position get_pos();
};
#endif // LOCATION_H
