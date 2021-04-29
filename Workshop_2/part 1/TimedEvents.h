/******************************************
| Subject        : Workshop 2             |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 10-04-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef SDDS_TIMEEVENT_H
#define SDDS_TIMEEVENT_H
#include <complex>
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

namespace sdds {
#pragma once
	class TimedEvents {
		size_t m_record;
		steady_clock::time_point m_start;
		steady_clock::time_point m_end;
		size_t cnt;

		struct
		{
			char* m_eventName;
			char* m_timeUnit;
			steady_clock::duration m_due;
		} event[7];
	public:
		TimedEvents();

		void startClock();
		void stopClock();
		void recordEvent(const char*);

		void setRecord(const size_t);
		size_t GetRecord();

		void setEventName(int, const char*);
		void setTimeUnit(int, const char*);
		void setDue(int, const std::chrono::steady_clock::duration);

		friend std::ostream& operator<<(std::ostream& os, const TimedEvents&);

		~TimedEvents();

	};
}
#endif
