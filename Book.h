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
	class Book {

		string m_author;
		string m_title;
		string m_country;
		size_t m_year;
		double m_price;
		string m_description;

	public:
		Book();
		Book(std::string& strBook);
		const string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		const string& description() const;

		string trim(string& strBook);
		string removeSpace(string& res);
		friend std::ostream& operator<<(std::ostream& os, Book& res);
		void display(std::ostream& os);
		void display2(ostream& os);

		template<typename T>
		void fixSpelling(T spellChecker) {
			try {
				if (m_description.length() == 0 || m_description == "")
				{
					throw std::out_of_range("EXCEPTION111: Bad value-space in there");
				}
				else {
					spellChecker(m_description);
				}
			}
			catch (const std::exception& error)
			{
				cerr << error.what() << endl;
				m_description = "x;";
			}

		}

		~Book();
	};

	//std::ostream& operator<<(std::ostream& os, const Book& obj);


	//template<typename T>
	//inline void Book::fixSpelling(T spellChecker)
	//{
	//	
	//	(spellChecker);
	//	
	//}

}