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
#include "Car.h"

using namespace std;
namespace sdds {
	sdds::Car::Car()
	{
		m_tag={};
		m_maker={};
		m_condition = {};
		m_topspeed=0;
		m_rate = 0;
		m_remark = {};
	}
	Car::Car(string  _tag, string  _maker, string  _condition, double _topspeed,double _rate)
	{
		m_tag = _tag;
		m_maker = _maker;
		m_condition = _condition;
		m_topspeed = _topspeed;
		m_rate = _rate;		
	}
	Car::Car(istream &)
	{
	}
	string Car::tag() const
	{
		return m_tag;
	}
	string Car::maker() const
	{
		return m_maker;
	}
	string Car::condition() const
	{
		return m_condition;
	}
	double Car::topSpeed() const
	{
		return m_topspeed;
	}
	double Car::rate() const
	{
		return m_rate;
	}
	void Car::display(std::ostream & os) const
	{
		string s_condition = {};		
		string s_star = {};
		if (condition() == "n" || condition() == "") { s_condition = "new"; }
		else if (condition() == "u") { s_condition = "used"; }
		else if (condition() == "b") { s_condition = "broken"; };
		if (rate() == 0)
		{
			s_star = "";
		}
		else {
			s_star = "*";
		};
	
			cout << "| " << right << setw(10) << m_maker
				<< " | " << left << setw(6) << s_condition
				<< " | " << left << setw(6) << setprecision(2) << fixed << topSpeed()
				<< " |" << s_star;
	}
	string Car::trim(string & stritem)
	{
		stritem.erase(0, stritem.find_first_not_of(" "));
		stritem.erase(stritem.find_last_not_of(" ") + 1);
		return stritem;
	}
}
