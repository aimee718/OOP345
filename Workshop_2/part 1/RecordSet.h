/******************************************
| Subject        : Workshop 2             |
| Name           : Aimee Lee              |
| Date           : 10-04-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H
#include <complex>
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "TimedEvents.h"

using namespace std;
using namespace std::chrono;
using namespace std;

namespace sdds {

#pragma once
	class RecordSet : public TimedEvents {
		string* m_content;
		size_t sizeNumber;
		
	public:
		RecordSet();
		RecordSet(char*);
		void getFile(string);

		RecordSet(const RecordSet&);
		RecordSet& operator=(const RecordSet&);

		RecordSet(RecordSet&&);
		RecordSet& operator=(RecordSet&&);

		string getRecord(size_t);
		void getCount(string);
		size_t size();
		~RecordSet();
	};

}

#endif
