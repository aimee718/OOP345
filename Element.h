#ifndef W8_ELEMENT_H
#define W8_ELEMENT_H

#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

using namespace std;

namespace sdds {
	
	struct ValidationException : public exception
	{
		std::string message;
		ValidationException(string msg) : message(msg) {}
		~ValidationException() throw() {}
		const char *what() const throw() { return message.c_str(); }
	};

	struct Description
	{
		unsigned code;
		string desc;
		
		bool load(ifstream &src)
		{
			src >> code >> desc;
			return src.good();
		}

		void display(std::ostream &os) const
		{
			os << std::setw(FWC) << code
				<< std::setw(FWD) << desc
				<< std::endl;
		}
	};

	struct Price
	{
		unsigned code;
		double price;
		bool load(std::ifstream &f)
		{
			f >> code >> price;
			return f.good();
		}

		void display(std::ostream &os) const
		{
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
	};

	struct Product
	{
		std::string m_desc;
		double m_price;
		int m_id;
		static size_t idGenerator;
		// this variable is used to print trace messages from
		//     constructors/destructor
		static bool Trace;

		Product()
		{
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" << std::endl;
		}
		Product(const std::string& str, double p)
		{
			this->m_desc = str;
			this->m_price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" << std::endl;
		}
		Product(const Product& other)
		{
			this->m_desc = other.m_desc;
			this->m_price = other.m_price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
				<< "] from [" << other.m_id << "]"
				<< std::endl;
		}

		~Product()
		{
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" << std::endl;
		}

		// TODO: add a function here to validate the price

		inline void validate()
		{
			std::string msg = "*** Negative prices are invalid ***";
			if (this->m_price < 0)
				throw msg;
		}

		void display(std::ostream &os) const
		{
			os << std::setw(FWD) << m_desc
				<< std::setw(FWP) << m_price
				<< std::endl;
		}
	};
}
#endif
