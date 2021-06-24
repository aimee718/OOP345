/******************************************
| Subject        : Workshop 9             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 11-29-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <thread>
#include <future>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
		{
			input >> text[i++];
		}			
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}
	
	void SecureData::code(char key)
	{	
		int part = nbytes / 3;
	
		auto convert_p3 = std::bind(converter, text + part * 2, key, nbytes - (part * 2), Cryptor());
		std::thread p3(convert_p3);
		
		auto convert_p2 = std::bind(converter, text + part, key, part, Cryptor());
		std::thread p2(convert_p2);
		
		converter(text, key, part, Cryptor());
		
		p2.join();
		p3.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) 
	{
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{			
			std::ofstream fout(file, std::ios::binary);

			if (!fout.good()) throw std::string("\n***Could not open file***\n");
			
			fout.write(text, nbytes);
			fout.close();
		}
	}

	void SecureData::restore(const char* file, char key) 
	{
		std::ifstream fin(file, std::ios::binary);

		if (!fin.good()) throw std::string("\n***Could not open file***\n");

		fin.seekg(0, fin.end);
		nbytes = (int)fin.tellg();
		fin.seekg(0, fin.beg);

		text = new char[nbytes];

		fin.read(text, nbytes);

		fin.close();

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;
	
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
