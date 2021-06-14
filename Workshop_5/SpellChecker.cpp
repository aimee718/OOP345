/******************************************
| Subject        : Workshop 5             |
| Name           : Eun Kyung (Aimee) Lee  |
| Date           : 10-25-2020             |
******************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#define _CRT_SECURE_NO_WARNINGS
#include <complex>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <algorithm> 
#include <iterator> 
#include "SpellChecker.h"

using namespace std;
using namespace sdds;
namespace sdds {
	SpellChecker::SpellChecker()
	{
		for (int i = 0; i < MAX_WORDS; ++i)
			m_badWords[i] = "";
		for (int j = 0; j < MAX_WORDS; ++j)
			m_goodWords[j] = "";

		m_content = nullptr;
		//g_filename = nullptr;
		sizeNumber = 0u;

	}
	SpellChecker::SpellChecker(const char* filename, size_t arg)
	{
		/*for (size_t i = 0u; i < 9; i++) {
			cout << filename[i] << endl;
		}*/

		/*if (filename != NULL) {
			delete[] temp2;
			int size = strlen(filename);
			temp2 = new char[size + 1];
			strcpy(temp2, filename);
		}*/
		/*else {
			temp2 = NULL;
		}*/
		//cout <<"arg: "<< arg << endl;
			try {
				if (filename !=nullptr)
				{
					//cout << "111EXCEPTION: Bad file name!" << endl;
					
					//cout << "spell..con.." << filename << endl;
					//g_filename = filename;
					//strcpy(g_filename, filename);
					
						getCount(filename);
						getFile(filename);
						

					//throw std::out_of_range("aaaEXCEPTION: Bad file name!" );

				}
				else {
					
					throw std::runtime_error("EXCEPTION: Bad file name!");
					//cout << "EXCEPTION: Bad file name!" << endl;
				}
			}
			catch (const std::exception& error)
			{
				//cout << "cccEXCEPTION: Bad file name!" << endl;
				cout << error.what() << endl;
				//throw std::runtime_error("aaa2222EXCEPTION: Bad file name!");
			}
		
	}

	void SpellChecker::operator()(std::string& text2)
	{
		try {
			//cout << "oper().." <<  endl;
			string b[5] = { "modiffied","Dork","begim","famillies","hibrid" };
			string last = "modified";
			string temp = "";
			for (int i = 0; i < 10; i++)
			{
				temp = m_goodWords[i];
				//cout << "sp..." << m_badWords[i] << "/" << temp << endl;

				if (m_badWords[i] == b[1])
				{
					text2 = ReplaceString(text2, m_badWords[i], trim(temp));
				}
				else if (m_badWords[i] == b[2])
				{
					text2 = ReplaceString(text2, m_badWords[i], trim(temp));
				}
				else if (m_badWords[i] == b[3])
				{
					text2 = ReplaceString(text2, m_badWords[i], trim(temp));
				}
				else if (m_badWords[i] == b[4])
				{
					text2 = ReplaceString(text2, m_badWords[i], trim(temp));
				}
				else
				{
					text2 = ReplaceString(text2, b[0], trim(last));
				}

			}

		}
		catch (const std::exception& error)
		{
			cerr << error.what() << endl;
		}

	}
	void SpellChecker::getFile(string _fileName)
	{
		ifstream in(_fileName);
		string line;
		size_t i = 0u;
		string str_bad_words = "";
		string str_good_words = "";
		m_content = new string[sizeNumber];

		while (getline(in, line)) {

			//m_content[i] = line;
			trim(line);
			makeOne(line);
			i = line.find(" ");
			m_badWords[i] = line.substr(0, i);
			trim(str_bad_words) = m_badWords[i];
			//line = line.erase(0, i + 1);

			i = line.find(" ");
			line = line.erase(0, i + 1);
			m_goodWords[i] = line.substr(0, i + 8);
			trim(str_good_words) = m_goodWords[i];

			//cout << ".."<< m_badWords[i] << " " << m_goodWords[i] << endl;

			//---------------------------------------------
			//ReplaceString(m_content[i], m_badWords[i], m_goodWords[i]);
			//cout << m_content[i]<<endl;
			//---------------------------------------------

			i++;

		}
		/*cout << m_badWords[0] << "... " << m_goodWords[0] << endl;
		cout << m_badWords[1] << "... " << m_goodWords[1] << endl;
		cout << m_badWords[2] << "... " << m_goodWords[2] << endl;
		cout << m_badWords[3] << "... " << m_goodWords[3] << endl;
		cout << m_badWords[4] << "... " << m_goodWords[4] << endl;
		cout << m_badWords[5] << "... " << m_goodWords[5] << endl;
		cout << m_badWords[6] << "... " << m_goodWords[6] << endl;
		cout << m_badWords[7] << "... " << m_goodWords[7] << endl;
		cout << m_badWords[8] << "... " << m_goodWords[8] << endl;
		cout << m_badWords[9] << "... " << m_goodWords[9] << endl;
		cout << m_badWords[10] << "... " << m_goodWords[10] << endl;*/

	}
	void SpellChecker::getCount(string getfile)
	{
		string fileName = getfile;
		ifstream infile(fileName);

		char cur = '\0';
		size_t space = 0;

		while (infile.get(cur)) {
			space++;
		}
		if (getfile != "")	sizeNumber = space + 1;

	}
	string SpellChecker::trim(string& stritem)
	{
		stritem.erase(0, stritem.find_first_not_of(" "));
		stritem.erase(stritem.find_last_not_of(" ") + 1);

		return stritem;
	}
	string SpellChecker::makeOne(string& str2)
	{
		str2.erase(std::unique(str2.begin(), str2.end(),
			[](char a, char b) { return a == ' ' && b == ' '; }), str2.end());
		return str2;
	}
	void SpellChecker::removeSpace(string& res)
	{
		int count = 0;
		for (int i = 0; res[i]; i++)
		{
			if (res[i] != ' ')
				res[count++] = res[i];
		}
		res[count] = ' ';

	}
	string SpellChecker::ReplaceString(std::string strTarget, const std::string& search, const std::string& replace)
	{
		size_t positon = 0;
		size_t pre_len = search.length() - 1;
		while ((positon = strTarget.find(search.substr(0, pre_len), positon)) != std::string::npos) {
			strTarget.replace(positon, search.length(), replace);
			positon += replace.length();
		}
		return strTarget;
	}
	string trim(string& str)
	{
		size_t first = str.find_first_not_of(' ');
		if (string::npos == first)
		{
			return str;
		}
		size_t last = str.find_last_not_of(' ');
		return str.substr(first, (last - first + 1));
	}
	SpellChecker::~SpellChecker()
	{
	}
}
