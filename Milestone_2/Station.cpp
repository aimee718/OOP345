/******************************************
| Subject        : Milestone 2            |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 11-21-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>

#include "Station.h"
#include "Utilities.h"

using namespace std;

	size_t Station::id_generator=1;
	size_t Station::m_widthField;
	size_t Station::m_widthSerial = 6;

	Station::Station(){
		m_name = {};
		m_description = {};
		m_serialNumber = {};
		m_quantity = {};
        m_widthField=1;
		id_generator = {1};

	}	

	Station::Station(const std::string record){		
		try {
			Utilities util;
			size_t pos = 0;
			std::vector<std::string> tempVec;
			bool notDone = true;

			while (notDone) {
				tempVec.push_back(util.extractToken(record, pos, notDone));
				pos += tempVec[tempVec.size() - 1].length() + 1;				
			}
			
			this->m_name = tempVec[0];
			this->m_serialNumber = stoi(tempVec[1]);
			this->m_quantity = stoi(tempVec[2]);
			this->m_description = tempVec[3];
					
			Station::m_widthField = std::max(Station::m_widthField, util.getFieldWidth());			
		}
		catch (std::string err) {
			std::cout << err << std::endl;
		}
		catch (...) {
			std::cout << "An unknown error has occured." << std::endl;
		}
	}

	const std::string & Station::getItemName() const{
		return m_name;
	}

	const std::string & Station::getDescription() const{
		return m_description;
	}

	const unsigned int Station::getNextSerialNumber(){
		return m_serialNumber++;
	}

	const unsigned int Station::getQuantity(){
		return m_quantity;
	}

	void Station::updateQuantity(){
		this->m_quantity = std::max(this->m_quantity - 1, 0);
	}

	void Station::display(std::ostream & os, bool full) const{
		
		if (id_generator >= 8) {
			id_generator = 1;
		}
		os <<"["<<right<<setw(3)<<setfill('0')<<id_generator<<"]"<<std::setfill(' ')<< std::left << " Item: " << std::setw(this->m_widthField) << getItemName() << " ["
			<< right << std::setw(this->m_widthSerial) << std::setfill('0') << this->m_serialNumber 
			<< std::setfill(' ')<< "]";
			if (full) {
				os << " Quantity: " << std::left << std::setw(this->m_widthField) << m_quantity << " Description: " << this->getDescription();
			}
			os << std::endl;
			
			id_generator = id_generator+1;
	}

	Station::~Station(){
		
	}

