/******************************************
| Subject        : Workshop 5             |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 10-25-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <type_traits>
#include "SpellChecker.h"

using namespace std;

namespace sdds {
#pragma once
	class Movie
	{
		string m_title;
		size_t m_r_year;
		string m_description;
		size_t cnt;
		string r_title;
	public:
		Movie();
		Movie(std::string&);
		//Movie(const Movie&);
		//Movie& operator=(const Movie&);
		const string& title() const;
		const size_t& year() const;
		const string& description() const;
		size_t get_Mv_Cnt() const;

		void removeSpace(string& res);
		friend std::ostream& operator<<(std::ostream& os, const Movie res);
		//friend std::ostream & operator<<(std::ostream & os, Movie);
		void display(std::ostream& os);
		string trim(string&);
		string Ltrim(string&);

		template<typename T>
		void fixSpelling(T spellChecker)
		{
			try {
				if (m_description.length() == 0 || m_description == "")
				{
					throw std::out_of_range("EXCEPTION99999999: Bad value-space in there");
				}

			}
			catch (const std::exception& error)
			{
				cerr << error.what() << endl;
				m_description = "???";
			}
			spellChecker(m_description);
			spellChecker(m_title);
		}

		~Movie();

	};



}
