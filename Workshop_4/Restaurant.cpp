/******************************************
| Subject        : Workshop 4             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 10-18-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Restaurant.h"    

using namespace std;
using namespace sdds;
namespace sdds {             
	Restaurant::Restaurant()
	{
		for (int i = 0; i < MAX_ITEMS; i++) {
			m_arr[i] = nullptr;
		}	
		_counter = 0;
		m_arr = nullptr;
	}

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		m_arr = new Reservation * [cnt];
		for (size_t i = 0; i < cnt; i++) {
			m_arr[i] = reservations[i];
		}
		_counter = cnt;
	}

	Restaurant::Restaurant(const Restaurant& src) : m_arr{ nullptr }, _counter{ 0 }
	{
		*this = src;
	}

	Restaurant& Restaurant::operator=(const Restaurant& res)
	{
		if (this != &res)
		{
			_counter = res._counter;
			delete[] m_arr;

			m_arr = new Reservation * [_counter];
			for (size_t i = 0; i < _counter; i++) {
				m_arr[i] = res.m_arr[i];
			}
		}
		else
		{
			delete[] m_arr;
			m_arr = nullptr;
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src)
	{
		m_arr = src.m_arr;
		_counter = src._counter;

		// Release the data pointer from the source object so that
		// the destructor does not free the memory multiple times.
		src.m_arr = nullptr;
		src._counter = 0;
	}

	Restaurant& Restaurant::operator=(Restaurant&& src)
	{
		if (this != &src) {
			delete[] m_arr;
			_counter = src._counter;
			m_arr = src.m_arr;

			m_arr = nullptr;
			_counter = 0;
		}
		else
		{
			m_arr = nullptr;
			_counter = 0;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& src)
	{
		if (src.m_arr == nullptr)
		{
			std::cout << "--------------------------\n";
			std::cout << "Fancy Restaurant" << endl;
			std::cout << "--------------------------\n";
			std::cout << "The object is empty!" << endl;
			std::cout << "--------------------------\n";
		}
		else {

			std::cout << "--------------------------\n";
			std::cout << "Fancy Restaurant" << endl;
			std::cout << "--------------------------\n";

			for (size_t i = 0u; i < src._counter; i++)
			{
				os << *src.m_arr[i];
			}
			std::cout << "--------------------------\n";
		}
		return os;
	}

	size_t Restaurant::size() const
	{
		return _counter;
	}

	Restaurant::~Restaurant()
	{
	}
}
