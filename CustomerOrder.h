/******************************************
| Subject        : Milestone 3            |
| Name           : Eun Kyung (Aimee) Lee  |
| Student number : 056342132              |
| Date           : 11-28-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef CUSTOMERORDER_HEADER
#define CUSTOMERORDER_HEADER
#include <iostream>
#include <fstream>
#include <string>

#include "Utilities.h"
#include "Station.h"

using namespace std;

	struct Item
	{
		string m_itemName;
		unsigned int m_serialNumber = 0;
		bool m_isFilled = false;

		Item(string src) : m_itemName(src) {};
	};

	class CustomerOrder {
		string m_name;			
		string m_product;		
		unsigned int m_cntItem;		
		Item** m_lstItem;		
		static size_t m_widthField;	
	public:
		CustomerOrder();											
		CustomerOrder(string&);								
		CustomerOrder(const CustomerOrder&);						
		CustomerOrder& operator=(const CustomerOrder&) = delete;	
		CustomerOrder(CustomerOrder&&) noexcept;					
		CustomerOrder& operator=(CustomerOrder&&);					
		~CustomerOrder();											
		bool isItemFilled(string) const;					
		bool isOrderFilled() const;								
		void fillItem(Station& item, std::ostream& os) ;				
		void display(ostream&) const;							
	};

#endif
