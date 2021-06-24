/******************************************
| Subject        : Workshop 6             |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 11-08-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <iomanip> 
#include "Racecar.h"

using namespace std;
namespace sdds {
	Racecar::Racecar(std::istream& in)
	{
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
	}
	double Racecar::topspeed() const
	{
		return m_topspeed;
	}
}