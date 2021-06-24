/******************************************
| Subject        : Workshop 6             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 11-08-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef Utilities_HEADER
#define Utilities_HEADER
#include <iostream>
#include <fstream>
#include <cstring>
#include <typeinfo>
#include "Autoshop.h"
#include "Vehicle.h"
#include "Car.h"

using namespace std;
namespace sdds {
	Vehicle2* createInstance(istream& in);
	string trim(string & stritem);
	std::ostream& operator<<(std::ostream& os, const Vehicle& product);
}
#endif
