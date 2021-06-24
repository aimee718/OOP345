/******************************************
| Subject        : Milestone 3            |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 11-28-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <deque>
#include <string>
#include <vector>

#include "Workstation.h"
#include "CustomerOrder.h"

class LineManager {

	std::vector<Workstation*> AssemblyLine;		
	std::deque<CustomerOrder> ToBeFilled;	
	std::deque<CustomerOrder> Completed;	
	unsigned int m_cntCustomerOrder;		
	unsigned int aLineStart;				
	unsigned int aLineEnd;					
	unsigned int CustomerOrder_Count=0;			
public:

	LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);	
	bool run(std::ostream&);															
	void displayCompletedOrders(std::ostream&) const;
	void displayStations() const;
	void displayStationsSorted() ;
	 static bool ascNext(const Workstation*,const Workstation*);
	
};
#endif
