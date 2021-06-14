/******************************************
| Subject        : Workshop 4             |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 10-18-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <type_traits>
#include "Reservation.h"
#include "Restaurant.h"

using namespace std;
using namespace sdds;
using namespace sdds;
namespace sdds {
#pragma once
	class ConfirmationSender {
		Reservation** m_pp_arr;
		size_t cCnt;
		int flag;

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender& operator=(ConfirmationSender&&);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		int getFlag() { return flag; };

		~ConfirmationSender();

		friend ostream& operator<<(std::ostream& os, const ConfirmationSender&);
	};
}