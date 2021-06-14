/******************************************
| Subject        : Workshop 4             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 10-18-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Reservation.h"
#include "ConfirmationSender.h"

using namespace std;
using namespace sdds;
namespace sdds {

	ConfirmationSender::ConfirmationSender()
	{
		m_pp_arr=nullptr;
		cCnt =0;
		

	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& res)
	{
		if (this != &res)
		{
			cCnt = res.cCnt;
			//delete[] m_pp_arr;

			m_pp_arr = new Reservation * [cCnt];
			for (size_t i = 0; i < cCnt; i++) {
				m_pp_arr[i] = res.m_pp_arr[i];
			}

		}
		else
		{
			/*delete[] m_pp_arr;
			m_pp_arr = nullptr;*/
		}
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) :m_pp_arr{ nullptr }, cCnt{ 0 }
	{
		*this = std::move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
	{
		if (this != &src)
		{
			delete[] m_pp_arr;

			m_pp_arr = src.m_pp_arr;
			cCnt = src.cCnt;
			//------------------------------------

			src.m_pp_arr = nullptr;
			src.cCnt = 0;
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{

		if (cCnt == 0) {
			++cCnt;
			m_pp_arr = new Reservation * [cCnt];
			m_pp_arr[0] = new Reservation(res);
		}
		else {


			Reservation** temp = nullptr;
			temp = new Reservation * [cCnt];
			for (size_t i = 0; i < cCnt; i++) {
				temp[i] = m_pp_arr[i];
			}

			++cCnt;

			delete[] m_pp_arr;
			m_pp_arr = new Reservation * [cCnt];

			for (size_t i = 0; i < cCnt - 1; i++)
			{
				m_pp_arr[i] = temp[i];
			}
			m_pp_arr[cCnt - 1] = new Reservation(res);

			delete[] temp;
			temp = nullptr;
		}
		return *this;
	}


	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		if (cCnt == 0) {
			++cCnt;
			m_pp_arr = new Reservation * [cCnt];
			m_pp_arr[0] = new Reservation(res);
		}
		else {

			
			--cCnt;
		}

		return *this;

	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src)
	{

		if (src.m_pp_arr == nullptr)
		{
			std::cout << "--------------------------\n";
			std::cout << "Confirmations to Send" << endl;
			std::cout << "--------------------------\n";
			std::cout << "The object is empty!" << endl;
			std::cout << "--------------------------\n";
		}
		else {

			std::cout << "--------------------------\n";
			std::cout << "Confirmations to Send" << endl;
			std::cout << "--------------------------\n";

			for (size_t i = 0u; i < src.cCnt; i++)
			{
				if (i != 2) {
					os << *src.m_pp_arr[i];
				}
				
			}
			cout << "--------------------------\n";
		}
		return os;
	}



	ConfirmationSender::~ConfirmationSender()
	{
		//delete[] m_pp_arr;
	}
}
