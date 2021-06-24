/******************************************
| Subject        : Workshop 6             |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 11-08-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef RACECAR_HEADER
#define RACECAR_HEADER
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <type_traits>
#include <vector>
#include <list>
#include <algorithm>
#include <array>

#include "Car.h"

using namespace std;
namespace sdds {
	class Racecar : public Car {
		double m_booster;
		string m_tag;
		string m_maker;
		string m_condition;
		double m_topspeed;
		double m_rate;
		string m_remark;
	public:
		Racecar(string _tag, string _maker, string _condition, double _topspeed, double _rate) : Car(m_tag, m_maker, m_condition, m_topspeed, m_rate) {
			_tag=m_tag ;
			_maker = m_maker;
			_condition = m_condition;
			_topspeed = m_topspeed;
			_rate = m_rate;
		}
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topspeed() const;
	};
}
#endif