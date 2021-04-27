#include "event.h"
#include<stdio.h>
#include <iostream>
#include <fstream>

//#include <crtdbg.h> 
//#if _DEBUG 
//#define new new(_NORMAL_BLOCK, __FILE__, __LINE__) 
//#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__) 
//#endif 
//using namespace std;
//using namespace sdds;
//
//unsigned g_sysClock;
//extern size_t times;
//int main(int argc, char* argv[])
//{
//	//_CrtSetBreakAlloc(332);
//	std::cout << "Command Line:\n";
//	//cout << argc << endl;
//	for (int i = 0; i < argc; i++) {
//		cout << i + 1 << ": " << argv[i] << endl;
//	}
//	std::cout << std::endl;
//
//	// the archive can store maximum 10 events
//	sdds::Event archive[10];
//
//	// the index of the next available position in the archive
//	size_t idxArchive = 0;
//
//	sdds::Event currentEvent;
//
//	const size_t secInDay = 60u * 60u * 24u;// day has 86400 seconds
//
//	for (auto day = 1; day < argc; ++day)
//	{
//		// each parameter for an application contains the events from one day
//		// process each one
//		std::cout << "--------------------\n";
//		std::cout << "    Day " << day << '\n';
//		std::cout << "--------------------\n";
//
//		std::ifstream in(argv[day]);
//		char opcode = '\0';
//		times = secInDay + 1;
//
//		in >> opcode >> times;
//
//		// starting at midnight, until the end of the day
//		for (::g_sysClock = 0u; ::g_sysClock < secInDay; ::g_sysClock++)
//		{
//			// what should happen this second
//			while (times == ::g_sysClock)
//			{
//				// skip the delimiter
//				in.ignore();
//				// read the next opcode
//				in >> opcode;
//
//				// end of the file
//				if (in.fail())
//					break;
//
//				switch (opcode)
//				{
//				case 'T': // a new time code, this is exit the while loop
//					in >> times;
//					//currentEvent.setTime(times);
//					break;
//				case 'S': // start a new event, the old event is automatically finished
//					char buffer[1024];
//					in.get(buffer, 1024, ',');
//					currentEvent.setDescription(buffer);
//					currentEvent.setTime(times);
//					break;
//				case 'E': // end the current event
//					currentEvent.setDescription(nullptr);
//					currentEvent.setTime(times);
//					break;
//				case 'P': // print to scren the information about the current event
//
//					currentEvent.display2();
//					break;
//				case 'A': // add a copy of the current event to the archive
//					sdds::Event copy(currentEvent);
//					archive[idxArchive++] = copy;
//					break;
//
//				}
//			}
//		}
//	}
//	// print the archive
//	std::cout << "--------------------\n";
//	std::cout << "    Archive\n";
//	std::cout << "--------------------\n";
//	for (auto i = 0u; i < idxArchive; ++i)
//
//		archive[i].display2();
//	std::cout << "--------------------\n";
//
//	//_CrtDumpMemoryLeaks(); // Memory leaking
//
//
//}

class B {
	string a = "first";
public:
	B() :a{ "second" } {}
	B(const B& src) {
		cout << "copy";
		*this = src;
	}
	string geta()const { return a; }

};
int main() {
	B b;
	B v = b;
	cout << v.geta();
}