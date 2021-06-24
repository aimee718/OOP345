/******************************************
| Subject        : Workshop 6             |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 11-08-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments



#ifndef CAR_HEADER
#define CAR_HEADER
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <type_traits>
#include "Vehicle.h"
#include "Vehicle2.h"

using namespace std;
namespace sdds {
	class Car :public Vehicle2 {
		
	public:
		string m_tag;
		string m_maker;
		string m_condition;
		double m_topspeed;
		double m_rate;
		string m_remark;
	
		Car();
		Car(string , string, string, double,double);
		Car(istream&);

		string tag() const;
		string maker() const;
		string condition() const;
		double topSpeed() const;
		double rate() const;
		void display(std::ostream&) const;
		string trim(string &);
	};
}
#endif
