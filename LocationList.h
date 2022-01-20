#include "CampusLocation.h"
#include "CityLocation.h"
#include <vector>
#include <algorithm>
class LocationList {
private:
	int list_size;
	//Location** location_list;
	std::vector<Location*> location_list;
	int num_of_locations;
	void Grow();
public:
	LocationList();
	~LocationList();
	int GetCount() const;
	Location* GetLocation(int index) const;
	void AddLocation(Location* new_loc);
	void FromFile(std::string fname);
	void ToFile(std::string fname);

	class Closer {
	private:
		Position pos;
	public:
		Closer(Position p);
		bool operator()(Location* a, Location* b);
	};

	void Sort(Position p);
};
