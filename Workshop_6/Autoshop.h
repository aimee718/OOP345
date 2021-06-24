/******************************************
| Subject        : Workshop 6             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 11-08-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef AUTOSHOP_HEADER
#define AUTOSHOP_HEADER
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <type_traits>
#include <vector>
#include <list>
#include <algorithm>
#include <array>
#include "Car.h"
#include "Vehicle2.h"
#include "Racecar.h"

using namespace std;
namespace sdds {
	class Autoshop : public Car {
	public:
		std::vector<Vehicle2*> m_vehicles;
		Autoshop& operator +=(Vehicle2* theVehicle);
		void display(std::ostream& out) const;
		template<typename T>
		void select(T test, std::list<const Vehicle2*>& vehicles) {
			std::string tname = typeid(T).name();
			string tname0 = typeid(test(300)).name();	
			if (tname0 == "d")
			{
				list<const Vehicle2*> tmp_vehicles;
				std::copy(vehicles.begin(), vehicles.end(), std::back_inserter(tmp_vehicles));
				vehicles.clear();
				auto iter22 = tmp_vehicles.begin();
				for (; iter22 != tmp_vehicles.end(); iter22++) {

						if ((*iter22) != nullptr && (((*iter22)->topSpeed() >= 300) && ((*iter22)->topSpeed() <= 370))) {
							vehicles.push_back(new Car(
								((*iter22)->tag())
								, ((*iter22)->maker())
								, ((*iter22)->condition())
								, ((*iter22)->topSpeed())
								, ((*iter22)->rate())
							));
						}
				}
			}
			else
			{
				auto iter33 = m_vehicles.begin();

				for (; iter33 != m_vehicles.end(); iter33++) {
					if ((*iter33) != nullptr && (*iter33)->condition() == "b" && (*iter33)->topSpeed() > 0)
						vehicles.push_back(new Car(
							((*iter33)->tag())
							, ((*iter33)->maker())
							, ((*iter33)->condition())
							, ((*iter33)->topSpeed())
							, ((*iter33)->rate())
						));
				}				
			}
		}//endl of select
	};
}

#endif
