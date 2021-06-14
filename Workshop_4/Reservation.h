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

using namespace std;
namespace sdds {
#pragma once
	class Reservation {
		string id;
		string s_id;
		string name;
		string email;
		int seats;
		int day;
		int hour;

		string resID;
		int ppl;

		int cnt;
	public:
		Reservation();
		Reservation(std::string& m_res);
		//Reservation(const Reservation&);
		int getCnt();
		void setID(string _id);
		string getID();
		void display(std::ostream& os) const;
		void removeSpace(string&);
	};
	std::ostream& operator<<(std::ostream& os, const Reservation& obj);
}
