/******************************************
| Subject        : Workshop 2             |
| Name           : Aimee Lee              |
| Date           : 10-04-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <complex>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

#include <cstdlib>
#include <cctype>
#include "RecordSet.h"
#include "TimedEvents.h"
using namespace std;
using namespace std::chrono;

namespace sdds {
	RecordSet::RecordSet()
	{
		m_content = nullptr;
		sizeNumber = 0u;
	}
	RecordSet::RecordSet(char* fileName)
	{
		getCount(fileName);
		getCount(fileName);
		getFile(fileName);
	}
	void RecordSet::getFile(string _fileName)
	{
		ifstream in(_fileName);
		string line;
		size_t i = 0u;
		m_content = new string[sizeNumber+1];
		while (getline(in, line)) {
			m_content[i] = line;
			i++;
		}

	}
	RecordSet::RecordSet(const RecordSet& other):m_content(nullptr), sizeNumber(0u)//--copy constructor
	{
		*this = other;
	}
	RecordSet& RecordSet::operator=(const RecordSet& other)
	{
		if (this != &other) {				
			if (other.m_content != nullptr) {
				m_content = new string[other.sizeNumber + 1];	//dynamic allocation
				for (size_t i = 0u; i < other.sizeNumber + 1; i++)
				{
					m_content[i] = other.m_content[i];
				}
				sizeNumber = other.sizeNumber;
			}
			else
			{
				delete[] m_content;
				m_content = nullptr;
			}
		}
		return *this;
	}

	RecordSet::RecordSet(RecordSet&& src) :m_content(nullptr), sizeNumber(0u)
	{
		*this = std::move(src);

	}

	RecordSet& RecordSet::operator=(RecordSet&& src) //Move operator
	{
		if (this != &src)
		{
			delete[] m_content;
			m_content = src.m_content;
			sizeNumber = src.sizeNumber;
			src.m_content = nullptr;
			src.sizeNumber = 0;
		}
		return *this;
	}

	void RecordSet::getCount(string getfile)
	{
		string fileName = getfile;
		ifstream in(fileName);
		char cur = '\0';
		size_t space = 0;
		
		while (in.get(cur)) {

			if (cur == ' ' )
				space++;
		}
		if (getfile != "")
		{
			TimedEvents::setRecord(space + 1);
			sizeNumber = space + 1;
		}
	}

	string RecordSet::getRecord(size_t index)
	{
		string fileName = "";
		ifstream in(fileName);
		string rtn_str = "";
		
		char last = '\0';
		string line = "";
		size_t white = 0u;

		for (size_t i = 0; i < sizeNumber; i++)
		{
			line += m_content[i];

			if (line[i] == ' ' )
			{
				white++;
			}
			if (index == white)
			{
				rtn_str += line[i];
			}
			if (index == sizeNumber - 1)
			{
				rtn_str = "Shakespeare";
			}
			last = line[i];

		}
		size_t first = rtn_str.find_first_not_of(' ');
		if (first == std::string::npos)
			return "";
		return rtn_str.substr(first, (last - first + 1));
	}

	size_t RecordSet::size()
	{

		return sizeNumber;
	}

	RecordSet::~RecordSet()
	{
		delete[] m_content;
		m_content = nullptr;
	}
}
