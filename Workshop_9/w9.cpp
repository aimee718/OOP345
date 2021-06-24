// Workshop 9 - Multi-Threading
// w9.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "SecureData.h"
#include "SecureData.h"

using namespace std;

//int main(int argc, char** argv)
//{
//	cout << "Command Line: " << argv[0];
//	for (int i = 1; i < argc; i++)
//		cout << " " << argv[i];
//	cout << endl << endl;
//
//	if (argc != 4)
//	{
//		cerr << endl << "***Incorrect number of arguments***" << endl;
//		return 1;
//	}
//
//	char key = argv[3][0];
//
//	try {
//		w9::SecureData sd(argv[1], key, &cout);
//		sd.backup(argv[2]);
//
//		sd.restore(argv[2], key);
//		cout << sd << std::endl;
//
//	}
//	catch (const std::string& msg) {
//		cout << msg << std::endl;
//	}
//
//	return 0;
//}

//class B {
//	string a = "Value";
//	static unsigned cnt;
//public:
//	B() :a{ "NewValue" } {}
//	B(const B& src) {
//		++cnt;
//		*this = src;
//	}
//};
//unsigned B::cnt = 0;
//void func(B t) {
//	cout << "do nothing";
//}
int main(int argc, char** argv) {

	/*int* i;
	char* j;
	i = static_cast<int*>(static_cast<void*>(j));*/
	/*int a[5]{ 0,2,4,1 };
	for (auto e : a) { e = e + 1; };
	for (auto e : a)
	{
		cout << e;
	}*/
	/*B a;
	func(a);
	func(a);
	B c(a);*/

	/*int a[5] = { 5,1,12,13 };
	vector<int> v(a, a + 4);
	v.insert(v.begin() + 1, 115);
	for (auto e : v) {
		cout << e;
	}*/
	int s[] = { 2,7,0,4,8,5 };
	int* p = &s[3];
	int* q = &s[10];
	cout << (q - p);
	return 0;
}
