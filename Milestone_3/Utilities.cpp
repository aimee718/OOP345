/******************************************
| Subject        : Milestone 3            |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 11-28-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <typeinfo>
#include <type_traits>
#include "Utilities.h"

using namespace std;
	
	char Utilities::m_delimiter;

	void Utilities::setFieldWidth(size_t newWidth)
	{
		this->m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return this->m_widthField;
	}

	std::string Utilities::extractToken(const std::string & str, size_t & next_pos, bool & more)
	{
		std::string line;
		
		if (str.length() > next_pos) {	
			
			more = true;
			size_t delimPos = str.substr(next_pos).find(this->getDelimiter());
			line = str.substr(next_pos, delimPos);
			if (line.length() == 0) {
				throw "No token found between two delimiters.";
			}
			
			if (line.length() > this->getFieldWidth() && delimPos != std::string::npos) {
				
				this->setFieldWidth(line.length());			
			}		
		}		
		else {
			more = false;
		}		
		
		return line;
	}

	void Utilities::setDelimiter(char newDelimiter){
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter(){
		return m_delimiter;
	}
	
