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
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

#include "LineManager.h"
#include "Workstation.h"

LineManager::LineManager(const std::string& record, std::vector<Workstation*>& tasks, std::vector<CustomerOrder>& customerOrders)
{
	try {
		
		Utilities util;
		size_t pos = 0;
		std::vector<std::string> tempVec;
		bool notDone = true;
		std::ifstream file(record);
		if (!file)
			throw std::string("Unable to open [") + record + "] file.";

		std::string collection;
		while (!file.eof())
		{
			std::getline(file, collection);
			while (notDone) {
				tempVec.push_back(util.extractToken(collection, pos, notDone));
				pos += tempVec[tempVec.size() - 1].length() + 1;
			}
			tempVec.pop_back();
			pos = 0;
			notDone = true;
		}

		file.close();

		auto firstItem = std::find_if(tasks.begin(), tasks.end()
			, [=](Workstation* it) {return it->getItemName() == tempVec[0]; });

		this->aLineStart = (unsigned int)std::distance(tasks.begin(), firstItem);

		auto lastItem = std::find_if(tasks.begin(), tasks.end()
			, [=](Workstation* it) {return it->getItemName() == tempVec[tempVec.size() - 1]; });

		this->aLineEnd = (unsigned int)std::distance(tasks.begin(), lastItem);
		for (Workstation* iter : tasks) {

			auto result = std::find_if(tempVec.rbegin(), tempVec.rend(),
				[=](std::string itemName) { return itemName == iter->getItemName(); });
			size_t index = std::distance(result, tempVec.rend());

			if (index != tempVec.size()) {
				auto nextTask = std::find_if(tasks.begin(), tasks.end(),
					[=](Workstation* targetTask) { return targetTask->getItemName() == tempVec[index + 1]; });

				iter->setNextStation(**nextTask);
			}
		}

		this->m_cntCustomerOrder = (unsigned int)customerOrders.size();
		for (size_t num = 0; num < customerOrders.size(); ++num) {
			this->ToBeFilled.push_front(std::move(customerOrders[num]));
		}

		customerOrders.erase(customerOrders.begin(), customerOrders.end());

		this->AssemblyLine = tasks;
	}
	catch (...) {
		std::cout << "An error has occured in the LineManager three-argument constructor." << std::endl;
	}
}

bool LineManager::run(std::ostream& os)
{
	
	bool filled = true;

	if (!this->ToBeFilled.empty()) 
	{
		*this->AssemblyLine[this->aLineStart] += std::move(this->ToBeFilled.back());
		this->ToBeFilled.pop_back();
	}
	cout <<"Line Manager Iteration: "<< CustomerOrder_Count+1 << endl;
	for (Workstation* task : this->AssemblyLine) {
		task->runProcess(std::cout);
	}

	CustomerOrder transferOrder;
	if (this->AssemblyLine[this->aLineEnd]->getIfCompleted(transferOrder)) {
		this->Completed.push_back(std::move(transferOrder));
	}
	for (Workstation* station : this->AssemblyLine) 
	{
		if (station->moveOrder()) {
			filled = false;
		}
	}
	
	CustomerOrder_Count++;
	return filled;
}

void LineManager::displayCompletedOrders(std::ostream& os) const
{
	for (size_t num = 0; num < this->Completed.size(); ++num) {
		this->Completed[num].display(std::cout);
	}
}

void LineManager::displayStations() const
{
	for (size_t num = 0; num < this->AssemblyLine.size(); ++num) {
		this->AssemblyLine[num]->display(std::cout);
	}
}

void LineManager::displayStationsSorted() 
{	
	std::vector<Workstation*> Temp_AssemblyLine;
	std::copy(AssemblyLine.begin(), AssemblyLine.end(), std::back_inserter(Temp_AssemblyLine));
	std::sort(Temp_AssemblyLine.begin(), Temp_AssemblyLine.end() - 1, LineManager::ascNext);

	auto iter = Temp_AssemblyLine.begin();
	for (; iter != Temp_AssemblyLine.end(); iter++) 
	{
		if ((*iter) != nullptr && (*iter)->getItemName() != "WiFi")
		{		
			cout << left << (*iter)->getItemName();
			cout << " --> ";
			if ((*iter)->getNextStation() != nullptr )
			{
				cout<<(*iter)->getNextStation()->getItemName();
			}
			else
			{
				cout<< "END OF LINE";
			}	        
			cout << endl;
		}		
	}
	
			cout << "WiFi" << " --> " << "END OF LINE";
			cout << endl;	
}

bool LineManager::ascNext(const Workstation* a, const Workstation* b)
{
	if (b->getNextStation() != nullptr && a->getNextStation() != nullptr)   
	{
		return (a->getNextStation()->getItemName() < b->getNextStation()->getItemName());
	}
	else {
		return false;
	}

}
