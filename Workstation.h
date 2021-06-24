/******************************************
| Subject        : Milestone 3            |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 11-28-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef Workstation_HEADER
#define Workstation_HEADER

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <deque>
#include <string>

#include "Station.h"
#include "CustomerOrder.h"

using namespace std;

	class Workstation :public Station {
		deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation;

	public:

		Workstation();
		Workstation(const std::string&);				
		Workstation(const Workstation&) = delete;				
		Workstation& operator=(const Workstation&) = delete;	
		Workstation(Workstation&&) = delete;					
		Workstation& operator=(Workstation&&) = delete;

		void runProcess(std::ostream&);
		bool moveOrder();
		void setNextStation(Workstation& station);
		const Workstation* getNextStation() const;

		bool getIfCompleted(CustomerOrder& order);

		void display(std::ostream&);

		Workstation& operator+=(CustomerOrder&&);		
	};

#endif

