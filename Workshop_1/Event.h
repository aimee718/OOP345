#pragma once
#include <iostream>

using namespace std;

namespace sdds {
	static unsigned g_sysClock;
	static int COUNT;
#pragma once

	class Event {

		char* description;
		size_t time_9;
		unsigned cnt;


	public:

		Event();
		Event(const Event&);
		Event& operator=(const Event&);
		void display(void);
		void setDescription(char*);
		void setTime(size_t);



		~Event();

	};

}
