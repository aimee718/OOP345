/******************************************
| Subject        : Workshop 6             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 11-08-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <iomanip> 
#include "Autoshop.h"

using namespace std;
namespace sdds {
	Autoshop & sdds::Autoshop::operator+=(Vehicle2 * theVehicle)
	{
		return *this;
	}
	void Autoshop::display(std::ostream & out) const
	{
		std::cout << "--------------------------------\n";
		std::cout << "| Cars in the autoshop!        |\n";
		std::cout << "--------------------------------\n";
		
		auto iter = m_vehicles.begin();
		string s_condition = "";
		
		string s_star = {};
		for (; iter != m_vehicles.end()-1; iter++) {
			if ((*iter) != nullptr)
			{
				if ((*iter)->condition() == "n" || (*iter)->condition() =="") { s_condition = "new"; }
				else if ((*iter)->condition() == "u") { s_condition = "used"; }
				else if ((*iter)->condition() == "b") { s_condition = "broken"; };

				if (((*iter)->rate()) == 0) 
				{ 
				    s_star = "";
				}else {
					s_star = "*";
				}

				if ((*iter)->topSpeed() > 0 && (*iter)->tag()!= "t" && (*iter)->condition() != "s") {

					cout << "| " << right << setw(10) << (*iter)->maker()
						<< " | " << left << setw(6) << s_condition
						<< " | " << left << setw(6) << setprecision(2) << fixed << (*iter)->topSpeed()
						<< " |" << s_star
						<< endl;
				}
			}
		}
		std::cout << "--------------------------------\n";
	}
}
