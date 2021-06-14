/******************************************
| Subject        : Workshop 5             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 10-25-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>


#include "Movie.h"
using namespace std;
using namespace sdds;
namespace sdds {
	sdds::Movie::Movie()
	{
		m_title = "";
		m_r_year = 0u;
		m_description = "";
		cnt = 0u;
		r_title = "";
	}
	Movie::Movie(std::string& m_res)
	{

		int i = m_res.find(",");
		m_title = m_res.substr(0, i);
		m_res = m_res.erase(0, i + 1);
		trim(m_title);
		//removeSpace(m_res);
		i = m_res.find(",");
		m_r_year = stoi(m_res.substr(0, i));
		m_res = m_res.erase(0, i + 1);

		//removeSpace(m_res);
		i = m_res.find(".");
		m_description = m_res.substr(0, i+1);
		m_res = m_res.erase(0, i + 1);
		trim(m_description);
		//mv_cnt++;
		//trim(m_description);

		/*i = m_res.find(",");
		m_description2 = m_res.substr(0, i);
		m_res = m_res.erase(0, i + 1);
		*/
		//cout << "dis..mv.." << m_title << ".." << endl;
		cnt++;
	}

	const string& Movie::title() const
	{
		return m_title;
	}

	size_t Movie::get_Mv_Cnt() const
	{
		return cnt;
	}

	void Movie::removeSpace(string& res)
	{
		int count = 0;
		for (int i = 0; res[i]; i++)
		{
			if (res[i] != ' ')
				res[count++] = res[i];
		}
		res[count] = ' ';

	}
	void Movie::display(std::ostream& os)
	{
		if (r_title.substr(0, 5) != m_title.substr(0.5))
		{
			os << right << setw(40) << m_title << " | " << setw(4) << m_r_year << " | "
				<< left << /*setw(95) <<*/ m_description <<'\n';
		}
		r_title = m_title;

	}
	string Movie::trim(string& stritem)
	{
		stritem.erase(0, stritem.find_first_not_of(" "));
		stritem.erase(stritem.find_last_not_of(" ")+1);
		return stritem;
	}
	string Movie::Ltrim(string& stritem)
	{
		stritem.erase(0, stritem.find_first_not_of(" "));
		return stritem;
	}
	Movie::~Movie()
	{
	}
	std::ostream& operator<<(std::ostream& os, Movie res)
	{
		res.display(os);
		return os;

	}

}
