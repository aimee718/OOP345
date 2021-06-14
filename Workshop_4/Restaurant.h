/******************************************
| Subject        : Workshop 4             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 10-18-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <type_traits>
#include "Reservation.h"

#define MAX_ITEMS 20
using namespace sdds;
using namespace std;
namespace sdds {
#pragma once
	class Restaurant {
		
		Reservation** m_arr;//Reservation* m_arr[];
		size_t _counter;

	public:
		Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);

		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);

		Restaurant(Restaurant&&);
		Restaurant& operator=(Restaurant&&);

		~Restaurant();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant&);

	};
}
