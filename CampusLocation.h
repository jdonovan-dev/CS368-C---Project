//#ifndef CAMPUSLOCATION_H
//#define CAMPUSLOCATION_H

#include "Location.h"

class CampusLocation: public Location {
public:
	CampusLocation();
	CampusLocation(std::string init_name, std::string init_address, std::string init_hours);
	bool Reserve() {return false;}
	void Cancel() {};
	void Print() const;
	void Read(std::istream& s);
	void Write(std::ostream& s) const;
};
//#endif // CAMPUSLOCATION_H
