// #ifndef CITYLOCATION_H
// #define CITYLOCATION_H
#include "Location.h"

class CityLocation: public Location {
public:
	CityLocation();
	CityLocation(std::string init_name, std::string init_address,
			std::string init_hours, int init_reservations);
	bool Reserve();
	void Cancel();
	void Print() const;
	void Read(std::istream &s);
	void Write(std::ostream &s) const;
};
// #endif // CITYLOCATION_H
