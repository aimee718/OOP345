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

//#include "Book.h"
//#include "Movie.h"

using namespace std;
//using namespace sdds;
namespace sdds {
#pragma once
	const int MAX_WORDS = 10;
	class SpellChecker
	{
		string* m_content;
		string m_badWords[MAX_WORDS];
		string m_goodWords[MAX_WORDS];
		int cnt;
		//char* g_filename;
		string* get_move;
		size_t sizeNumber;
	public:
		SpellChecker();
		//SpellChecker(char* filename);
		SpellChecker(const char* filename, size_t arg);
		void operator()(std::string& text);
		void getFile(string);
		void getCount(string);
		string trim(string&);
		string makeOne(string&);
		void removeSpace(string&);

		string ReplaceString(std::string subject, const std::string& search,
			const std::string& replace);


		~SpellChecker();
	};
}
