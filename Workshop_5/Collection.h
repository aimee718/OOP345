/******************************************
| Subject        : Workshop 5             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 10-25-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <type_traits>
#include "Book.h"
#include "Movie.h"

using namespace std;


namespace sdds {
#pragma once
	const int MAX_NO_OF_ITEMS = 10;
	template<typename T>
	class Collection
	{
		string m_name;
		T** m_arr;//book class -- //T* m_arr[MAX_NO_OF_ITEMS];//T** m_arr;		
		size_t a_size = 0u;
		size_t cnt = 0u;

	public:

		Collection()
		{
			a_size = 0u;
			m_name = "";
			// m_arr[0] = nullptr;
			cnt = 0u;
		}
		Collection(std::string _name) : m_name{ "" }, a_size{ 0u }, cnt{ 0u }
		{
			m_name = _name;
		}
		Collection(T* items[], double getUs, double getYear) {
			m_arr = new T * [7];
			for (size_t i = 0; i < 7; i++)
			{
				m_arr[i] = items[i];
				if (m_arr[i]->country() == "US")
				{
					m_arr[i]->price() = (m_arr[i]->price() * getUs);

				}
				else if (m_arr[i]->year() >= 1990 && m_arr[i]->year() <= 1999)
				{
					m_arr[i]->price() = (m_arr[i]->price() * getYear);
				}
				//cout << ".." << m_arr[i]->country() << ".." << m_arr[i]->price() << endl;
			}

		}
		const std::string& name() const
		{
			return m_name;
		}
		size_t size() const
		{
			return a_size;
		}
		Collection& operator-=(const T& item)
		{
			cnt--;
			return *this;
		}
		Collection& operator+=(const T& item)
		{

			T** temp = nullptr;
			temp = new T * [cnt];
			for (size_t i = 0u; i < cnt; i++)
			{
				temp[i] = m_arr[i];

			}
			++cnt;

			//delete[] m_arr;
			m_arr = new T * [cnt];

			for (size_t i = 0; i < cnt - 1; i++)
			{
				m_arr[i] = temp[i];
			}
			m_arr[cnt - 1] = new T(item);

			delete[] temp;
			temp = nullptr;
			a_size = cnt + 1;
			if (a_size == 6) a_size = 5;
			// cout << "vvv.." << cnt << "..." << a_size << "..." << size() << endl;
			return *this;
		}

		T& operator[](size_t idx) const
		{
			if (idx >= 5)
			{
				throw std::out_of_range("EXCEPTION: Bad index [" + to_string(idx) + "]. Collection has [" + to_string(idx) + "] items.");
				//throw idx = 5;
			}
			return *m_arr[idx];
		}
		T* operator[](std::string title) const
		{
			//try {

				for (size_t i = 0; i < a_size - 1; i++)
				{
					//cout<<"cmp..."<< title.compare(m_arr[i]->title())<<endl;
					int c = title.compare(m_arr[i]->title());
					if (c > 0)
					{
						return nullptr;
					}
					else if (c == 0)
					{
						//cout << "xxxxxxx" << endl;
						return m_arr[i];
					}
					else if (c < 0)
					{
						//cout << "xxxxxxx222" << endl;

						return m_arr[2];
					}

				}
				
			//}
			//catch (const std::exception& error)
			//{
				//cerr << "error...." << error.what() << endl;
			//}
				return *m_arr;
		}
		friend ostream& operator<<(std::ostream& os, const Collection& src)//
		{
			// os << "here..coll..<<.." << endl;
			if (src.cnt <= 0)
			{
			}
			else {
				for (size_t i = 0u; i < src.cnt; i++)
				{
					//  cout <<i<<"<<.."<< *src.m_arr[i]<<endl;
					os << *src.m_arr[i];
				}
			}
			return os;
		}

		void setObserver(void(*observe)(const Collection<T>&, const T&), Collection<T>& a1, T& a2)
		{
			observe(a1, a2);
		}
		~Collection()
		{
			delete[] m_arr;
		}
	};
}
