/******************************************
| Subject        : Milestone 3            |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 11-28-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef STATION_HEADER
#define STATION_HEADER
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

	class Station {
		string m_name;
		string m_description;
		unsigned int m_serialNumber;
		int m_quantity;
		static size_t m_widthField;
		static size_t id_generator;
		static size_t m_widthSerial;

		public:

			Station();
			Station(const std::string);	
			const std::string& getItemName() const;
			const std::string& getDescription() const;
			const unsigned int getNextSerialNumber();
			const unsigned int getQuantity();
			void updateQuantity();
			void display(std::ostream&, bool) const;
					
			~Station();
	};
#endif
