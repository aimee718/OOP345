/******************************************
| Subject        : Milestone 3            |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 11-28-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

#include "Workstation.h"

Workstation::Workstation()
{
	
}

Workstation::Workstation(const std::string & record) : Station(record)
{
	m_pNextStation = { nullptr };
}

void Workstation::runProcess(std::ostream & os)
{
	if (!this->m_orders.empty() && (!this->m_orders.back().isOrderFilled())) 
	{
		this->m_orders.back().fillItem(*this,os);
	}
}
bool Workstation::moveOrder()
{
	bool queueStatus = false;

	if (!this->m_orders.empty()) 
	{
		if (this->m_orders.back().isItemFilled(this->getItemName()) && m_pNextStation) 
		{
			*this->m_pNextStation += std::move(this->m_orders.back());
			this->m_orders.pop_back();
		}
		queueStatus = true;
	}
	return queueStatus;
}

void Workstation::setNextStation(Workstation & work)
{
	this->m_pNextStation = &work;
}

const Workstation* Workstation::getNextStation() const
{
	return this->m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder & order)
{
	bool queueStatus = false;
	if (!this->m_orders.empty()) 
	{
		if (this->m_orders.back().isItemFilled(this->getItemName())) 
		{
			order =  std::move(this->m_orders.back());
			this->m_orders.pop_back();
		}
		queueStatus = true;
	}
	return queueStatus;
}

void Workstation::display(std::ostream & os)
{
	os << this->getItemName();
	os << " --> ";

	this->m_pNextStation != nullptr ? os << this->m_pNextStation->getItemName() : os << "END OF LINE";
	os << std::endl;
}

Workstation & Workstation::operator+=(CustomerOrder && customerorder)
{
	this->m_orders.push_front(std::move(customerorder));
	return *this;
}

