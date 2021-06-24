/******************************************
| Subject        : Milestone 3            |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 11-28-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef Utilities_HEADER
#define Utilities_HEADER
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

	class Utilities {
		size_t m_widthField=1;           
		static char m_delimiter;       
		size_t m_id;

	public:
		void setFieldWidth(size_t); 
		size_t getFieldWidth() const;
		std::string extractToken(const std::string&, size_t&, bool& );
		static void setDelimiter(char);
		static char getDelimiter();
	};
#endif
