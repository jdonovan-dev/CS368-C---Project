#include "User.h"
void printMainMenu();
void printTestingLocations(const LocationList &locations);
void printSymptomsMenu(std::string symptoms[], int symptoms_size, bool selected_symptoms[]);
void printUserDataMenu(const User &user);
void printAdjustUserDataMenu(User &user);
void printSettingsMenu(const bool is_metric);
void printReservationLocations(const LocationList &locations);

