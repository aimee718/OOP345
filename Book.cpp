/******************************************
| Subject        : Workshop 5             |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 10-25-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments


#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include "Book.h"

using namespace std;
using namespace sdds;
namespace sdds {

	sdds::Book::Book()
	{
		m_author = "";
		m_title = "";
		m_country = "";
		m_year = 0u;
		m_price = 0.0;
		m_description = "";
		
	}
	Book::Book(std::string& m_res)
	{

		int i = m_res.find(",");
		m_author = m_res.substr(0, i);
		m_res = m_res.erase(0, i + 1);
		trim(m_author);

		//removeSpace(m_res);
		i = m_res.find(",");
		m_title = m_res.substr(0, i);
		m_res = m_res.erase(0, i + 1);
		trim(m_title);

		i = m_res.find(",");
		m_country = m_res.substr(0, i);
		m_res = m_res.erase(0, i + 1);
		trim(m_country);
		i = m_res.find(",");
		m_price = atof(m_res.substr(0, i).c_str());
		m_res = m_res.erase(0, i + 1);

		i = m_res.find(",");
		m_year = stoi(m_res.substr(0, i));
		m_res = m_res.erase(0, i + 1);

		i = m_res.find(".");
		m_description = m_res.substr(0, i+1);
		m_res = m_res.erase(0, i + 1);
		trim(m_description);
		

	}

	const string& Book::title() const
	{
		return m_title;
	}

	const std::string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}

	const string& Book::description() const
	{
		return m_description;
	}



	string Book::trim(string& stritem)
	{
		stritem.erase(0, stritem.find_first_not_of(" "));
		stritem.erase(stritem.find_last_not_of(" ") + 1);
		return stritem;
	}

	string Book::removeSpace(string& res)
	{
		int count = 0;
		for (int i = 0; res[i]; i++)
		{
			if (res[i] != ' ')
				res[count++] = res[i];
		}
		res[count] = ' ';

		return res;

	}
	void Book::display(std::ostream& os)
	{
		//os << m_author << "....." << m_title << "....." << m_country << endl;
		os << right<<setw(20) << m_author << " | " << setw(22) << m_title << " | "
			<< setw(5) << m_country << " | "

			<< setw(4) << m_year << " | "
			<<right<< setw(6) << fixed << setprecision(2) << m_price<< " | "
			<< m_description
			<< endl;

	}
	void Book::display2(ostream& os) {
		os << setw(20) << m_author << " | " << setw(22) << m_title << " | "
			<< setw(5) << m_country << " | " << setw(4) << m_year << " | "
			//<< setw(6) << fixed << setprecision(2) << B.m_price	<< " | " 
			<< m_description << endl;
		//return os;
	}
	Book::~Book()
	{
	}
	std::ostream& operator<<(std::ostream& os, Book& res)
	{
		res.display(os);
		return os;

	}

	//ostream& operator<<(ostream& os, const Book&B) 
	//{

}
