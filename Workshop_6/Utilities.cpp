/******************************************
| Subject        : Workshop 6             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 11-08-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <typeinfo>
#include <type_traits>
#include "Utilities.h"
#include "Autoshop.h"
#include "Vehicle.h"
#include "Car.h"

using namespace std;
using namespace sdds;
namespace sdds {
	Vehicle2 * createInstance(istream& file)
	{
		Vehicle2* vptr = nullptr;
		string buffer = {};
		string s_tag = {}, s_maker = {}, s_condition = {};
		double s_topspeed = {};
		double s_rate = {};
		double s2_rate = {};
		if (file.good())
		{
			if (std::getline(file, buffer))
			{
				int i = buffer.find(",");
				s_tag = buffer.substr(0, i);
				buffer = buffer.erase(0, i + 1);
				trim(s_tag);

				i = buffer.find(",");
				s_maker = buffer.substr(0, i);
				buffer = buffer.erase(0, i + 1);
				trim(s_maker);

				i = buffer.find(",");
				s_condition = buffer.substr(0, i);
				buffer = buffer.erase(0, i + 1);
				trim(s_condition);

				i = buffer.find(",");
				s_topspeed = atof(buffer.substr(0, i).c_str());
				buffer = buffer.erase(0, i + 1);

				i = buffer.find(",");
				s_rate = atof(buffer.substr(0, i).c_str());
				buffer = buffer.erase(0, i + 1);
				
				if (s_rate >= 1)
				{
					s_rate = 0;
					s2_rate = 1;
				}
				else
				{
					s2_rate = 1+s_rate;
				}				
				
				if (s_condition.length() == 0 || s_topspeed == 0)
				{
					if(s_maker !="Ferrari")
					cout << "Invalid record!" << endl;
				}
				
				if (s_tag == "t") {

					cout << "Unrecognized record type: " << "[" << s_tag << "]" << endl;
				}
				else
				{
					
				}
				vptr = new Car(s_tag, s_maker, s_condition, s_topspeed*s2_rate,s_rate);				
			}
		}
		return vptr;
	}

	string trim(string& stritem)
	{
		stritem.erase(0, stritem.find_first_not_of(" "));
		stritem.erase(stritem.find_last_not_of(" ") + 1);
		return stritem;
	}

	std::ostream & operator<<(std::ostream& os, const Vehicle& vh)
	{
		vh.display(os);
		os << std::endl;
		return os;
	}
}
