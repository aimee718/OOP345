#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include <string>
#include <iomanip> 
#include "event.h"
#include "event.h"// this is on purpose

using namespace std;
using namespace sdds;

extern unsigned g_sysClock;
int COUNT;
size_t times;
namespace sdds {
	
	Event::Event()
	{

		description = nullptr;
		COUNT = 1;
		time_9 = 0u;
		cnt = 0u;
		
	}
	Event::Event(const Event& other)
	{

		if (other.description != nullptr) {

			*this = other;
		}
		else {
			//delete[] description;
			description = nullptr;
		}

	}
	Event& Event::operator=(const Event& other)
	{
		if (this != &other) {
			delete[] description;// deallocate current resource
			description = nullptr;
			// allocate new dynamic memory, if needed
			if (other.description != nullptr) {
				description = new char[strlen(other.description) + 1];
				// copy the resource data
				for (unsigned i = 0u; i < strlen(other.description) + 1; i++)
				{
					description[i] = other.description[i];
				}
				time_9 = other.time_9;
			}
			else
			{
				delete[] description;
				description = nullptr;
			}
		}
		return *this;
	}
	void Event::display(void)
	{

		if (description) {
			int  h, m, s;
			/*h = (times / 3600);
			m = (times - (3600 * h)) / 60;
			s = (times - (3600 * h) - (m * 60));*/
			h = times / 3600;
			m = (times % 3600) / 60;
			s = (times % 3600) % 60;
			cout <<setfill(' ')<<setw(3)<<right<< COUNT << ". " << std::setfill('0') << std::setw(2) << h << ":" << std::setw(2) << m << ":" << std::setw(2) << s << " -> " << description << endl;
		}
		else {
			cout << setfill(' ') << setw(3) << right<<COUNT << ". " << "[No Event]" << endl;
		}
		COUNT = COUNT + 1;

	}

	void Event::display2(void)
	{
		if (description) {
			int  h, m, s;
			h = (time_9 / 3600);
			m = (time_9 - (3600 * h)) / 60;
			s = (time_9 - (3600 * h) - (m * 60));
			/*h = times / 3600;
			m = (times % 3600) / 60;
			s = (times % 3600) % 60;*/
			cout << setfill(' ') << setw(3) << right << COUNT << ". " << std::setfill('0') << std::setw(2) << h << ":" << std::setw(2) << m << ":" << std::setw(2) << s << " -> " << description << endl;
		}
		else {
			cout << setfill(' ') << setw(3) << right << COUNT << ". " << "[ No Event ]" << endl;
		}
		COUNT = COUNT + 1;

	}

	void Event::setDescription(char* desp)
	{
		if (desp != nullptr) {
			delete[] description;

			description = new char[strlen(desp) + 1];
			for (unsigned i = 0u; i < strlen(desp) + 1; i++)
				description[i] = desp[i];
		}
		else {
			delete[] description;
			description = nullptr;
		}
	}

	void Event::setTime(size_t t_time)
	{

		time_9 = t_time;
	}

	Event::~Event()
	{
		//cout << "de...con.." <<COUNT<< endl;

		delete[] description;
		description = nullptr;
		time_9 = 0u;

	}

}
