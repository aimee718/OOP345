/******************************************
| Subject        : Workshop 4             |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 10-18-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include "Reservation.h"
using namespace std;
using namespace sdds;
namespace sdds {
	Reservation::Reservation()
	{
		id = "";
		name = "";
		email = "";
		seats = 0;
		day = 0;
		hour = 0;

		resID = "";
		ppl = 0;
		cnt = 0;
	}

	Reservation::Reservation(std::string& m_res)
	{
		removeSpace(m_res);

		int i = m_res.find(":");
		id = m_res.substr(0, i);
		m_res = m_res.erase(0, i + 1);

		i = m_res.find(",");
		name = m_res.substr(0, i);
		m_res = m_res.erase(0, i + 1);

		i = m_res.find(",");
		email = m_res.substr(0, i);
		m_res = m_res.erase(0, i + 1);

		i = m_res.find(",");
		seats = stoi(m_res.substr(0, i));
		m_res = m_res.erase(0, i + 1);

		i = m_res.find(",");
		day = stoi(m_res.substr(0, i));
		m_res = m_res.erase(0, i + 1);

		i = m_res.find(",");
		hour = stoi(m_res.substr(0, i));	
	}

	int Reservation::getCnt()
	{
		return cnt;
	}

	void Reservation::setID(string _id)
	{
		s_id = _id;
	}

	string Reservation::getID()
	{
		return s_id;
	}

	void sdds::Reservation::display(std::ostream& os) const
	{
		string menu_type;
		string head("<");
		string tail(">");

		if (hour >= 6 && hour <= 9) {
			menu_type = "Breakfast";
		}
		else if (hour >= 11 && hour <= 15)
		{
			menu_type = "Lunch";
		}
		else if (hour >= 17 && hour <= 21)
		{
			menu_type = "Dinner";
		}
		else
		{
			menu_type = "Drinks";
		}

		os << "Reservation "
			<< id << ": "
			<< right << setw(10) << name << "  " << setw(24) << left << head.append(email).append(tail)
			<< left << menu_type << " on day "
			<< day << " @" << " "
			<< hour << ":00 for" << " "
			<< seats << " people."
			<< '\n';

	}

	void Reservation::removeSpace(string& res)
	{
		int count = 0;
		for (int i = 0; res[i]; i++)
		{
			if (res[i] != ' ')
				res[count++] = res[i];
		}
		res[count] = ' ';
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		res.display(os);

		return os;
	}
}
