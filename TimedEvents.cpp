/******************************************
| Subject        : Workshop 2             |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 10-04-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<cstring>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;
using namespace sdds;

namespace sdds {
	TimedEvents::TimedEvents() :m_record{ 0 }
	{
		event[0].m_eventName = nullptr;
		event[0].m_timeUnit = nullptr;
		cnt = 0;

	}

	void TimedEvents::startClock()
	{
		m_start = std::chrono::steady_clock::now();
	}
	void TimedEvents::stopClock()
	{
		m_end = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* attr)
	{
		setEventName(cnt, attr);
		setTimeUnit(cnt, "nanoseconds");
		std::chrono::nanoseconds time_span = m_end - m_start;
		setDue(cnt, time_span);
		cnt++;
	}

	void TimedEvents::setRecord(const size_t _record)
	{
		m_record = _record;
	}

	size_t TimedEvents::GetRecord()
	{
		return m_record;
	}

	//----------------------------------------
	void TimedEvents::setEventName(int k, const char* desp)
	{		
		event[k].m_eventName = new char[strlen(desp) + 1];
		for (size_t i = 0u; i < strlen(desp) + 1; i++)
			event[k].m_eventName[i] = desp[i];
	}

	void TimedEvents::setTimeUnit(int k, const char* _unit)
	{
		event[k].m_timeUnit = new char[strlen(_unit) + 1];
		for (size_t i = 0u; i < strlen(_unit) + 1; i++)
			event[k].m_timeUnit[i] = _unit[i];
	}

	void TimedEvents::setDue(int k, const std::chrono::steady_clock::duration _due)
	{
		event[k].m_due = _due;
	}

	TimedEvents::~TimedEvents()
	{
		
		for (size_t i = 0; i < cnt; i++)
		{
			delete[] event[i].m_eventName;
			delete[] event[i].m_timeUnit;
			event[i].m_eventName = nullptr;
			event[i].m_timeUnit = nullptr;

		}
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& src)
	{
		std::cout << "--------------------------\n";
		std::cout << "Execution Times:" << endl;
		std::cout << "--------------------------\n";

		for (size_t i = 0u; i < src.cnt; i++)
		{
			os << std::left << setw(20) << src.event[i].m_eventName
				<< std::right << std::setw(12) << src.event[i].m_due.count()
				<< std::right << std::setw(12) << src.event[i].m_timeUnit << endl;
		}
		std::cout << "--------------------------\n";
		return os;
	}

}