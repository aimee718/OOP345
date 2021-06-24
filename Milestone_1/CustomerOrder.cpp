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
#include <iomanip>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

#include "CustomerOrder.h"
#include "Station.h"

using namespace std;

	size_t CustomerOrder::m_widthField;

	CustomerOrder::CustomerOrder() : m_name{ "" }, m_product{ "" }, m_cntItem{ 0 }, m_lstItem{ nullptr } {}

	CustomerOrder::CustomerOrder(std::string& record) {
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
				this->m_product = tempVec[1];

				this->m_cntItem = int(tempVec.size() - 3);

				this->m_lstItem = new Item*[this->m_cntItem];

				for (size_t item = 0; item < this->m_cntItem; ++item) {
					this->m_lstItem[item] = new Item(tempVec[item + 2]);
				}
				CustomerOrder::m_widthField = std::max(CustomerOrder::m_widthField, util.getFieldWidth());
		}
		catch (...) {
			std::cout << "One argument constructor error" << std::endl;
		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& src) {
		throw "Copy operations not allowed";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept : CustomerOrder() {
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& res) {
		if (this != &res)
		{
			delete[] this->m_lstItem;

			this->m_name = res.m_name;
			this->m_product = res.m_product;
			this->m_cntItem = res.m_cntItem;
			this->m_lstItem = res.m_lstItem;

			res.m_name = "";
			res.m_product = "";
			res.m_cntItem = 0;
			res.m_lstItem = nullptr;
		}

		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		delete[] this->m_lstItem;
	}

	bool CustomerOrder::isItemFilled(string itemName) const {
		bool filled = true;

		for (size_t i = 0; i < this->m_cntItem; i++)
		{
			if (itemName == this->m_lstItem[i]->m_itemName)
			{
				filled = this->m_lstItem[i]->m_isFilled;

				if (!filled) {
					break;
				}
			}
		}
		return filled;
	}

	bool CustomerOrder::isOrderFilled() const {
		bool b_filled = true;

		for (size_t i = 0; i < this->m_cntItem; i++)
		{
			if (!this->m_lstItem[i]->m_isFilled)
			{
				b_filled = false;
			}
		}

		return b_filled;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) { 
		for (size_t i = 0; i < this->m_cntItem; i++) { 

			if (station.getItemName() == this->m_lstItem[i]->m_itemName ) {
				if (station.getQuantity() > 0) {
					station.updateQuantity();
					this->m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					this->m_lstItem[i]->m_isFilled = true;
					os << "    Filled ";
				}
				else {
					os << "Unable to fill ";
				}
				os << this->m_name << ", " << this->m_product << " [" << this->m_lstItem[i]->m_itemName << "]" << std::endl;
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << this->m_name << " - " << this->m_product << std::endl;

		for (size_t item = 0; item < this->m_cntItem; ++item)
		{
			os << std::setfill('0') << "[" << std::right << std::setw(6) << this->m_lstItem[item]->m_serialNumber << "] ";
			os << std::setfill(' ') << std::left << std::setw(this->m_widthField);
			os << this->m_lstItem[item]->m_itemName << " - ";

			this->m_lstItem[item]->m_isFilled ? os << "FILLED" : os << "MISSING";

			os << std::endl;
		}
	}


